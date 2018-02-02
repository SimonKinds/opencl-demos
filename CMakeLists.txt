cmake_minimum_required (VERSION 3.1)
project (OpenCL-demos)

set(CMAKE_CXX_STANDARD 14)
set(OpenCL_VERSION 200)

find_package(OpenCL)

if(NOT ${OpenCL_FOUND})
  message( FATAL_ERROR "OpenCL not found" )
endif()

add_definitions(-DCL_HPP_TARGET_OPENCL_VERSION=${OpenCL_VERSION})
add_definitions(-DCL_HPP_MINIMUM_OPENCL_VERSION=${OpenCL_VERSION})

include_directories(${OpenCL_INCLUDE_DIRS})
add_subdirectory(list-devices)
