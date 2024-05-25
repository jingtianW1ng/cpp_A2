#ifndef CALCULATE_ALERT_LEVEL_STRATEGY_H
#define CALCULATE_ALERT_LEVEL_STRATEGY_H
class Vitals;

class CalcualteAlertLevelStrategy
{
public:

    virtual std::string calcualteAlertLevel(const Vitals* v) = 0;
};


#endif