#ifndef PATIENT_MANAGEMENT_SYSTEM_H
#define PATIENT_MANAGEMENT_SYSTEM_H

#include <map>
#include <memory>
#include <string>
#include <vector>


// forward declare several classes
class AbstractPatientDatabaseLoader;
class HospitalAlertSystemFacade;
class GPNotificationSystemFacade;
class Patient;
class PatientObserver;


class PatientManagementSystem
{
public:

    PatientManagementSystem();
    ~PatientManagementSystem();

    // initialise the patient records
    void init();
    void run();

    // ask the user for a patient and vitals and add those vitals to the patient
    void addVitalsRecord();

    void printWelcomeMessage() const;
    void printMainMenu() const;
    void printPatients() const;
    void addSubscribers(PatientObserver* patientObserver);

protected:
    std::vector<PatientObserver*> _subscribers;
    std::vector<Patient*> _patients;
    std::map<std::string, Patient*> _patientLookup;

    std::unique_ptr<HospitalAlertSystemFacade> _hospitalAlertSystem;
    std::unique_ptr<GPNotificationSystemFacade> _gpNotificationSystem;

    std::unique_ptr<AbstractPatientDatabaseLoader> _patientDatabaseLoader;
    std::unique_ptr<AbstractPatientDatabaseLoader> _patientFileLoaderAdapter;
};

#endif
