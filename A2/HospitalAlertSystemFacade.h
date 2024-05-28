#ifndef HOSPITAL_ALERT_SYSTEM_FACADE_H
#define HOSPITAL_ALERT_SYSTEM_FACADE_H

#include "Patient.h"
#include "PatientObserver.h"


class HospitalAlertSystemFacade : public PatientObserver
{
public:
    HospitalAlertSystemFacade();
    virtual ~HospitalAlertSystemFacade();

    virtual void sendAlertForPatient(Patient* p) override;

};

#endif
