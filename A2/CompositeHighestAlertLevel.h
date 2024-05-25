#ifndef COMPOSITE_HIGHEST_ALERT_LEVEL_H
#define COMPOSITE_HIGHEST_ALERT_LEVEL_H
#include "CalculateAlertLevelStrategy.h"
#include <vector>

class CompositeHighestAlertLevel : public CalculateAlertLevelStrategy
{
public:
	CompositeHighestAlertLevel();
	~CompositeHighestAlertLevel();

	void addStrategy(CalculateAlertLevelStrategy* strategy);


	virtual void calculateAlertLevel(const Vitals* v, Patient* p) override;

protected:

	std::vector<CalculateAlertLevelStrategy*> _strategies;
};

#endif