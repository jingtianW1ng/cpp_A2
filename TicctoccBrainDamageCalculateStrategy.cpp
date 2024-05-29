#include "TicctoccBrainDamageCalculateStrategy.h"
#include "Vitals.h"
#include "Patient.h"
TicctoccBrainDamageCalculateStrategy::TicctoccBrainDamageCalculateStrategy()
{
    alertLevel = AlertLevel::Green;
}

void TicctoccBrainDamageCalculateStrategy::calculateAlertLevel(const Vitals* v, Patient* p)
{
    if (p->age() < 35 && v->BA() < 10)
    {
        alertLevel = AlertLevel::Red;
    }
    if (p->age() >= 35 && v->BA() < 20)
    {
        alertLevel = AlertLevel::Red;
    }
}
