#include "PatientFileLoaderAdapter.h"
#include <filesystem>


PatientFileLoaderAdapter::PatientFileLoaderAdapter(PatientFileLoader* file_loader) : file_loader(file_loader)
{
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
