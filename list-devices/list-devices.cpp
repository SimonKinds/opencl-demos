#include <iostream>

#include "CL/cl2.hpp"

std::vector<cl::Platform> getPlatforms();
std::vector<cl::Device> getDevices(const cl::Platform&);
std::string getPlatformName(const cl::Platform&);
std::string getDeviceName(const cl::Device&);

int main() {
  for (const auto& p : getPlatforms()) {
    std::cout << "Platform: " << getPlatformName(p) << '\n';
    std::cout << "Devices: ";
    for (const auto& d : getDevices(p)) {
      std::cout << getDeviceName(d) << ", ";
    }
  }
  std::cout << std::endl;
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
std::string getDeviceName(const cl::Device& device) {
  return device.getInfo<CL_DEVICE_NAME>();
}
