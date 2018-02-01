add_executable(list-devices list-devices.cpp)
target_include_directories(list-devices PUBLIC ${OpenCL_INCLUDE_DIRS})
target_link_libraries(list-devices ${OpenCL_LIBRARIES})
