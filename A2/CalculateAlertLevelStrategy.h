#ifndef CALCULATE_ALERT_LEVEL_STRATEGY_H
#define CALCULATE_ALERT_LEVEL_STRATEGY_H
class Vitals;

class CalculateAlertLevelStrategy
{
public:

    virtual std::string calculateAlertLevel(const Vitals* v) = 0;
};


#endif