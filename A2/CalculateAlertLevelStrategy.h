#ifndef CALCULATE_ALERT_LEVEL_STRATEGY_H
#define CALCULATE_ALERT_LEVEL_STRATEGY_H
#include "PatientAlertLevels.h"
class Vitals;
class Patient;

class CalculateAlertLevelStrategy
{
public:

    virtual void calculateAlertLevel(const Vitals* v, Patient* p) = 0;
    AlertLevel alertLevel;
};


#endif