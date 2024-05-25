#ifndef AMOGUS_SUS_CALCUALTE_STRATEEGY_H
#define AMOGUS_SUS_CALCUALTE_STRATEEGY_H
#include "CalcualteAlertLevelStrategy.h"

class PercentageDiscountPricingStrategy : public CalcualteAlertLevelStrategy
{
public:
	PercentageDiscountPricingStrategy();


	virtual std::string calcualteAlertLevel(const Vitals* v) override;

};

#endif
