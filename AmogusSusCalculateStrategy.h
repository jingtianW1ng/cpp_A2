#ifndef AMOGUS_SUS_CALCULATE_STRATEEGY_H
#define AMOGUS_SUS_CALCULATE_STRATEEGY_H
#include "CalculateAlertLevelStrategy.h"

class AmogusSusCalculateStrategy : public CalculateAlertLevelStrategy
{
public:
	AmogusSusCalculateStrategy();


	virtual void calculateAlertLevel(const Vitals* v, Patient* p) override;

};

#endif
