# CMakeList.txt : CMake project for OOP_Assignment2_Task3_v, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (OOP_Assignment2_Task3_v "OOP_Assignment2_Task3_v.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OOP_Assignment2_Task3_v PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
