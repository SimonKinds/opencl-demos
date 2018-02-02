#include <iostream>
#include <sstream>

#include "CL/cl2.hpp"

std::vector<cl::Platform> getPlatforms();
std::string getPlatformName(const cl::Platform&);
std::vector<cl::Device> getDevices(const cl::Platform&);
std::string getDeviceInfo(const cl::Device&);

int main() {
  std::stringstream output;
  for (const auto& p : getPlatforms()) {
    output << "Devices for platform: " << getPlatformName(p) << "\n\n";
    for (const auto& d : getDevices(p)) {
      output << getDeviceInfo(d);
      output << "\n\n";
    }
  }
  std::cout << output.str();
}

std::vector<cl::Platform> getPlatforms() {
  std::vector<cl::Platform> platforms;
  cl::Platform::get(&platforms);
  return platforms;
}

std::vector<cl::Device> getDevices(const cl::Platform& platform) {
  std::vector<cl::Device> devices;
  platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);
  return devices;
}

std::string getPlatformName(const cl::Platform& platform) {
  return platform.getInfo<CL_PLATFORM_NAME>();
}
std::string getDeviceInfo(const cl::Device& device) {
  std::stringstream info;

  info << "GENERAL";
  info << "\nName: ";
  info << device.getInfo<CL_DEVICE_NAME>();

  info << "\nOpenCL version: ";
  info << device.getInfo<CL_DEVICE_VERSION>();

  info << "\nMax compute unit count: ";
  info << device.getInfo<CL_DEVICE_MAX_COMPUTE_UNITS>();


  info << "\n\nGLOBAL";
  info << "\nglobal memory size (bytes): ";
  info << device.getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>();

  info <<  "\nglobal memory cache size (bytes): ";
  info << device.getInfo<CL_DEVICE_GLOBAL_MEM_CACHE_SIZE>();

  info <<  "\nglobal memory cache line size (memory per fetch) (bytes): ";
  info << device.getInfo<CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE>();

  info <<  "\nglobal memory cache line size (memory per fetch) (bytes): ";
  info << device.getInfo<CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE>();

  info << "\n\nLOCAL";
  info << "\nlocal memory size (bytes): ";
  info << device.getInfo<CL_DEVICE_LOCAL_MEM_SIZE>();

  info << "\nlocal memory type: ";
  info << (device.getInfo<CL_DEVICE_LOCAL_MEM_TYPE>() == CL_LOCAL
    ? "dedicated local memory" : "shared with global memory");

  info << "\n\nWORK GROUPS";
  info << "\nMax work group size: ";
  info << device.getInfo<CL_DEVICE_MAX_WORK_GROUP_SIZE>();


  return info.str();
}
