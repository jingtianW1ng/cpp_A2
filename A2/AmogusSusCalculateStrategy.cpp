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
    }
    else if (v->HR() > 200 && v->HR() < 210)
    {
        alertLevel = AlertLevel::Yellow;
    }
    else if (v->HR() > 210 && v->HR() < 220)
    {
        alertLevel = AlertLevel::Orange;
    }
    else
    {
        alertLevel = AlertLevel::Red;
    }
}
