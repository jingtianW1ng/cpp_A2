#ifndef PATIENT_OBSERVER_H
#define PATIENT_OBSERVER_H

class PatientObserver
{
public:
	PatientObserver() {}
	~PatientObserver() {}

	virtual void addVitalsRecord() {}
};

#endif