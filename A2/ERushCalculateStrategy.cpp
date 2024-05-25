#include "ERushCalculateStrategy.h"
#include "Vitals.h"
#include "Patient.h"

ERushCalculateStrategy::ERushCalculateStrategy()
{
    alertLevel = AlertLevel::Green;
}

void ERushCalculateStrategy::calculateAlertLevel(const Vitals* v, Patient* p)
{
    if (v->BT() > 38 && v->BA() > 100)
    {
        alertLevel = AlertLevel::Yellow;
        p->setAlertLevel(alertLevel);
    }
    if (v->BT() > 38 && v->BA() > 110)
    {
        alertLevel = AlertLevel::Red;
        p->setAlertLevel(alertLevel);
    }
}
