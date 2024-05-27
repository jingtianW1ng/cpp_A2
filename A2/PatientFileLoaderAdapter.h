#ifndef PATIENT_FILE_LOADER_ADAPTER_H
#define PATIENT_FILE_LOADER_ADAPTER_H

#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader {
private:
    PatientFileLoader* file_loader;
public:
    PatientFileLoaderAdapter();
    ~PatientFileLoaderAdapter();
    virtual void initialiseConnection() override;
    virtual void loadPatients(std::vector<Patient*>& patientIn) override;
    virtual void closeConnection() override;
};

#endif