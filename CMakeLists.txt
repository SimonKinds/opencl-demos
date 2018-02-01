cmake_minimum_required (VERSION 3.1)
project (OpenCL-demos)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCL)

if(NOT ${OpenCL_FOUND})
  message( FATAL_ERROR "OpenCL not found" )
endif()

#include_directories(${OpenCL_INCLUDE_DIRS})
add_subdirectory(list-devices)
