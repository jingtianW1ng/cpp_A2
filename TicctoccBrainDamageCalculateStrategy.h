#ifndef TICCTICC_BRAIN_DAMAGE_CALCULATE_STRATEGY_H
#define TICCTICC_BRAIN_DAMAGE_CALCULATE_STRATEGY_H
#include "CalculateAlertLevelStrategy.h"

class TicctoccBrainDamageCalculateStrategy : public CalculateAlertLevelStrategy
{
public:
	TicctoccBrainDamageCalculateStrategy();


	virtual void calculateAlertLevel(const Vitals* v, Patient* p) override;

};

#endif