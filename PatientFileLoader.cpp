#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

PatientFileLoader::PatientFileLoader(const std::string& file) :
    _file(file)
{
}

std::vector<Patient*> PatientFileLoader::loadPatientFile()
{
    std::vector<Patient*> patients;

    std::ifstream inFile(_file);
    if (inFile.is_open()) {
        // TODO: load your file here
        //using while loop looping each line
        while (!inFile.eof())
        {
            //read every line
            std::string line;
            std::getline(inFile, line);
            //make line to istringstream
            std::istringstream issLine(line);
            std::string destString;
            std::vector<std::string> stringList;

            //add every string between '/' to a list
            while (std::getline(issLine, destString, '/')) {
                stringList.push_back(destString);
            }

            //record time
            std::tm t{ };
            std::istringstream ssTime(stringList.at(1));
            ssTime >> std::get_time(&t, "%d-%m-%Y");

            //record name
            std::string fullname = stringList.at(2);
            std::istringstream ssFullName(fullname);
            std::string lastName;
            std::string firstName;
            //read firstname first before ','
            std::getline(ssFullName, firstName, ',');
            //read lastname
            std::getline(ssFullName, lastName);

            //create ptr of a new Patient
            Patient* p = new Patient(firstName, lastName, t);

            //record diease
            std::string diagnosis = stringList.at(3);
            std::istringstream ssDiagnosis(diagnosis);
            std::string destDiagnosis;
            while (std::getline(ssDiagnosis, destDiagnosis, ','))
            {
                p->addDiagnosis(destDiagnosis);
            }

            //record Vitals
            if (stringList.size() == 5)
            {
                std::string vitals = stringList.at(4);
                std::istringstream ssvitals(vitals);
                std::string destvital;
                //for each vital
                while (std::getline(ssvitals, destvital, ';'))
                {
                    // istringstream each vital
                    std::istringstream ssvital(destvital);
                    std::string HR, SPO2, BT, BA;
                    // record HR
                    std::getline(ssvital, HR, ',');
                    // record SPO2
                    std::getline(ssvital, SPO2, ',');
                    // record BT
                    std::getline(ssvital, BT, ',');
                    // record BA
                    std::getline(ssvital, BA);
                    Vitals* v = new Vitals(std::stoi(HR), std::stoi(SPO2), std::stoi(BT), std::stoi(BA));
                    p->addVitals(v);
                }
            }


            patients.push_back(p);
            //clear list when finish this line
            stringList.clear();
        }
        //close file when reach the end
        inFile.close();
    }

    return patients;
}
