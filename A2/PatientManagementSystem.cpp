#include "PatientManagementSystem.h"

#include <iostream>
#include <map>
#include <tuple>

#include "Patient.h"
#include "PatientDatabaseLoader.h"
#include "PatientFileLoader.h"
#include "PatientFileLoaderAdapter.h"
#include "Vitals.h"

#include "GPNotificationSystemFacade.h"
#include "HospitalAlertSystemFacade.h"

#include "AmogusSusCalculateStrategy.h"
#include "ERushCalculateStrategy.h"
#include "NocapSyndromeCalculateStrategy.h"
#include "TicctoccBrainDamageCalculateStrategy.h"
#include "CompositeHighestAlertLevel.h" 
#include "PatientObserver.h"

using namespace std;


PatientManagementSystem::PatientManagementSystem() :
    //_patientDatabaseLoader(std::make_unique<PatientDatabaseLoader>()),
    _patientFileLoaderAdapter(std::make_unique<PatientFileLoaderAdapter>()),
    _hospitalAlertSystem(std::make_unique<HospitalAlertSystemFacade>()),
    _gpNotificationSystem(std::make_unique<GPNotificationSystemFacade>())
{
//    _patientDatabaseLoader->initialiseConnection();
}

PatientManagementSystem::~PatientManagementSystem()
{
    //_patientDatabaseLoader->closeConnection();

    // clear patient memory
    for (Patient* p : _patients) {
        delete p;
    }
}

void PatientManagementSystem::init()
{
    //_patientDatabaseLoader->loadPatients(_patients);
    _patientFileLoaderAdapter->loadPatients(_patients);
    for (Patient* p : _patients) {
        _patientLookup[p->uid()] = p;
    }

    for (Patient* p : _patients) {
        // TODO: do any processing you need here
        p->addSubscribers(_hospitalAlertSystem.get());
        p->addSubscribers(_gpNotificationSystem.get());
    }
}

void PatientManagementSystem::run()
{
    printWelcomeMessage();

    bool running = true;
    while (running) {
        printMainMenu();
        int option = 0;
        cin >> option;

        // handle basic errors
        if (cin.bad()) {
            cin.clear();
            cin.ignore();
            continue;
        }

        // switch based on the selected option
        switch (option) {
        case 1:
            addVitalsRecord();
            break;
        case 2:
            printPatients();
            break;
        case 3:
            running = false;
            break;
        }
    }
}

void PatientManagementSystem::addVitalsRecord()
{
    cout << "Patients" << endl;
    printPatients();
    cout << endl;
    cout << "Enter the patient ID to declare vitals for > ";
    
    string pid { "" };
    cin >> pid;
    if (_patientLookup.count(pid)) {
        int heartRate;
        int oxygenSaturation;
        int bodyTemperature;
        int brainActivity;

        cout << "Enter hear rate: ";
        cin >> heartRate;
        cout << "Enter oxygen saturation: ";
        cin >> oxygenSaturation;
        cout << "Enter body temperature: ";
        cin >> bodyTemperature;
        cout << "Enter brain activity: ";
        cin >> brainActivity;

        //TODO looping patient's diagnoses to find all dieases
        auto compStrat = new CompositeHighestAlertLevel();
        for (const auto& disease : _patientLookup[pid]->diagnoses())
        {
            if (disease == "AmogusSus")
            {
                auto strat = new AmogusSusCalculateStrategy();
                compStrat->addStrategy(strat);
                cout << "AmogusSus" << endl;
            }
            else if (disease == "ERush")
            {
                auto strat = new ERushCalculateStrategy();
                compStrat->addStrategy(strat);
                cout << "ERush" << endl;
            }
            else if (disease == "NocapSyndrome")
            {
                auto strat = new NocapSyndromeCalculateStrategy();
                compStrat->addStrategy(strat);
                cout << "NocapSyndrome" << endl;
            }
            else if (disease == "TicctoccBrainDamage")
            {
                auto strat = new TicctoccBrainDamageCalculateStrategy();
                compStrat->addStrategy(strat);
                cout << "TicctoccBrainDamage" << endl;
            }
        }
        _patientLookup[pid]->setCompositeStrategy(compStrat);

        Vitals* v = new Vitals(heartRate, oxygenSaturation, bodyTemperature, brainActivity);
        _patientLookup[pid]->addVitals(v);

        //call observers when alert level change
        for (auto& sub : _patientLookup[pid]->_subscribers)
        {
            sub->sendAlertForPatient(_patientLookup[pid]);
            sub->sendGPNotificationForPatient(_patientLookup[pid]);
        }

    }
    else {
        cout << "Patient not found" << endl;
    }
}

void PatientManagementSystem::printWelcomeMessage() const
{
    cout << "WELCOME TO DOCTRACK 2000" << endl;
    cout << "------------------------" << endl;
}

void PatientManagementSystem::printMainMenu() const
{
    cout << endl << "Select an option:" << endl;
    cout << "1. Record new vitals" << endl;
    cout << "2. List patients" << endl;
    cout << "3. Quit" << endl;
    cout << "> ";
}

void PatientManagementSystem::printPatients() const
{
    for (Patient* p : _patients) {
        std::cout << *p << std::endl;
    }
}
