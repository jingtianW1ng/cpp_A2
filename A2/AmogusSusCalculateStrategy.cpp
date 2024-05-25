#include "AmogusSusCalculateStrategy.h"
#include "Vitals.h"
#include "Patient.h"

AmogusSusCalculateStrategy::AmogusSusCalculateStrategy()
{
    alertLevel = AlertLevel::Green;
}

void AmogusSusCalculateStrategy::calculateAlertLevel(const Vitals* v, Patient* p)
{
    if (v->HR() < 200)
    {
        alertLevel = AlertLevel::Green;
        p->setAlertLevel(alertLevel);
    }
    else if (200 < v->HR() < 210)
    {
        alertLevel = AlertLevel::Yellow;
        p->setAlertLevel(alertLevel);
    }
    else if (210 < v->HR() < 220)
    {
        alertLevel = AlertLevel::Orange;
        p->setAlertLevel(alertLevel);
    }
    else
    {
        alertLevel = AlertLevel::Red;
        p->setAlertLevel(alertLevel);
    }
}
