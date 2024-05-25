#ifndef CALCULATE_ALERT_LEVEL_STRATEGY_H
#define CALCULATE_ALERT_LEVEL_STRATEGY_H
class Vitals;
class Patient;

class CalculateAlertLevelStrategy
{
public:

    virtual void calculateAlertLevel(const Vitals* v, Patient* p) = 0;
};


#endif