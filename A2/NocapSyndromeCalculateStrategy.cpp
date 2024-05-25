#include "NocapSyndromeCalculateStrategy.h"
#include "Vitals.h"
#include "Patient.h"
NocapSyndromeCalculateStrategy::NocapSyndromeCalculateStrategy()
{
    alertLevel = AlertLevel::Green;
}

void NocapSyndromeCalculateStrategy::calculateAlertLevel(const Vitals* v, Patient* p)
{
    if (v->SPO2() > 92 && v->SPO2() < 94)
    {
        alertLevel = AlertLevel::Yellow;
    }
    if (v->SPO2() > 90 && v->SPO2() < 92)
    {
        alertLevel = AlertLevel::Orange;
    }
    if (v->SPO2() < 90)
    {
        alertLevel = AlertLevel::Red;
    }
}
