#ifndef GP_NOTIFICATION_SYSTEM_FACADE_H
#define GP_NOTIFICATION_SYSTEM_FACADE_H

#include "Patient.h"
#include "PatientObserver.h"


class GPNotificationSystemFacade : public PatientObserver {
public:
    GPNotificationSystemFacade();
    virtual ~GPNotificationSystemFacade();

    virtual void sendGPNotificationForPatient(Patient* p) override;
};

#endif
