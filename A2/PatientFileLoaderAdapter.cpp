#include "PatientFileLoaderAdapter.h"


void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn)
{
    patientIn = file_loader->loadPatientFile();
}
