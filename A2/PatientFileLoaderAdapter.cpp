#include "PatientFileLoaderAdapter.h"
#include <filesystem>


PatientFileLoaderAdapter::PatientFileLoaderAdapter()
{
    file_loader = new PatientFileLoader("patients.txt");
}

PatientFileLoaderAdapter::~PatientFileLoaderAdapter()
{
    delete file_loader;
}

void PatientFileLoaderAdapter::initialiseConnection()
{
}

void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn)
{
    patientIn = file_loader->loadPatientFile();
}

void PatientFileLoaderAdapter::closeConnection()
{
}
