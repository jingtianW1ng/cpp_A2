#include "PatientFileLoaderAdapter.h"
#include <filesystem>


PatientFileLoaderAdapter::PatientFileLoaderAdapter()
{
    file_loader = new PatientFileLoader("D:\\2024_allCourse\\C++_work\\A2\\A2\\patients.txt");
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
