#ifndef E_RUSH_CALCULATE_STRATEGY_H
#define E_RUSH_CALCULATE_STRATEGY_H
#include "CalculateAlertLevelStrategy.h"

class ERushCalculateStrategy : public CalculateAlertLevelStrategy
{
public:
	ERushCalculateStrategy();


	virtual void calculateAlertLevel(const Vitals* v, Patient* p) override;

};

#endif
