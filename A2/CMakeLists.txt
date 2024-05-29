# CMakeList.txt : CMake project for A2, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (A2
    "AbstractPatientDatabaseLoader.h"
    "GPNotificationSystemFacade.cpp" "GPNotificationSystemFacade.h"
    "HospitalAlertSystemFacade.cpp" "HospitalAlertSystemFacade.cpp"
    "main.cpp"
    "Patient.cpp" "Patient.h"
    "PatientAlertLevels.h"
    "PatientDatabaseLoader.cpp" "PatientDatabaseLoader.h"
    "PatientFileLoader.cpp" "PatientFileLoader.h"
    "PatientManagementSystem.cpp" "PatientManagementSystem.h"
    "Person.cpp" "Person.h"
    "Vitals.cpp" "Vitals.h"
 "CalculateAlertLevelStrategy.h" "AmogusSusCalculateStrategy.h" "AmogusSusCalculateStrategy.cpp" "ERushCalculateStrategy.h" "ERushCalculateStrategy.cpp" "NocapSyndromeCalculateStrategy.h" "NocapSyndromeCalculateStrategy.cpp" "TicctoccBrainDamageCalculateStrategy.h" "TicctoccBrainDamageCalculateStrategy.cpp" "CompositeHighestAlertLevel.h" "CompositeHighestAlertLevel.cpp" "PatientFileLoaderAdapter.h" "PatientFileLoaderAdapter.cpp" "PatientObserver.h")

 configure_file(patients.txt patients.txt COPYONLY)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET A2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
