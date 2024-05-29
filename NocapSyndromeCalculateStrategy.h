#ifndef NOCAP_SYNDROME_CALCULATE_STRATEGY_H
#define NOCAP_SYNDROME_CALCULATE_STRATEGY_H
#include "CalculateAlertLevelStrategy.h"

class NocapSyndromeCalculateStrategy : public CalculateAlertLevelStrategy
{
public:
	NocapSyndromeCalculateStrategy();


	virtual void calculateAlertLevel(const Vitals* v, Patient* p) override;

};

#endif