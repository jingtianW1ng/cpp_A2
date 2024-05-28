#ifndef PATIENT_OBSERVER_H
#define PATIENT_OBSERVER_H
#include "Patient.h"
class PatientObserver
{
public:
	PatientObserver() {}
	~PatientObserver() {}

	virtual void sendGPNotificationForPatient(Patient* p) {}
	virtual void sendAlertForPatient(Patient* p) {}
};

#endif