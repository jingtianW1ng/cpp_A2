#include "CompositeHighestAlertLevel.h"
#include "Vitals.h"
#include "Patient.h"

CompositeHighestAlertLevel::CompositeHighestAlertLevel()
{
    alertLevel = AlertLevel::Green;
}

CompositeHighestAlertLevel::~CompositeHighestAlertLevel()
{
    for (auto strat : _strategies) {
        delete strat;
    }

    _strategies.clear();
}

void CompositeHighestAlertLevel::addStrategy(CalculateAlertLevelStrategy* strategy)
{
    _strategies.push_back(strategy);
}

void CompositeHighestAlertLevel::calculateAlertLevel(const Vitals* v, Patient* p)
{
    //TODO compare muti alert level set alert level to highest one
    for (const auto& strategie : _strategies)
    {
        strategie->calculateAlertLevel(v,p);
        if (strategie->alertLevel > alertLevel)
        {
            alertLevel = strategie->alertLevel;
        }
    }
    //set the highest level to Patient
    p->setAlertLevel(alertLevel);
}
