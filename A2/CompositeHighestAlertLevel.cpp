#include "CompositeHighestAlertLevel.h"

CompositeHighestAlertLevel::CompositeHighestAlertLevel()
{
}

CompositeHighestAlertLevel::~CompositeHighestAlertLevel()
{
    for (auto strat : _strategies) {
        delete strat;
    }

    _strategies.clear();
}

void CompositeHighestAlertLevel::addStrategy(CalculateAlertLevelStrategy* Strategy)
{
    _strategies.push_back(strategy);
}

void CompositeHighestAlertLevel::calculateAlertLevel(const Vitals* v, Patient* p)
{
    //TODO compare muti alert level set alert level to highest one
}
