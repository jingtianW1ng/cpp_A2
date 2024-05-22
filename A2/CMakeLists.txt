# CMakeList.txt : CMake project for A2, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (A2 "A2.cpp" "A2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET A2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
