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

            //start add everythong into Patient
            for (const auto& s : stringList) {
                std::cout << "name: " << s << std::endl;
            }
        }
        //close file when reach the end
        inFile.close();
    }

    return patients;
}
