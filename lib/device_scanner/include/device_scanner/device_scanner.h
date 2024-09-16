#ifndef DEVICE_SCANNER_H
#define DEVICE_SCANNER_H

#include <string>
#include <vector>
#include "port_scanner/port_scanner.h" // Update this path if necessary

namespace device_scanner {

enum class DeviceType {
    UNKNOWN,
    MCU_CARD,
    FLASH_DISK,
    OTHER
};

struct DeviceInfo {
    std::string port;
    DeviceType type;
    std::string description;
};

class DeviceScanner {
public:
    DeviceScanner();
    ~DeviceScanner();

    std::vector<DeviceInfo> scanDevices();

private:
    PortScanner portScanner;  // Now the compiler can see the full definition

    DeviceType identifyDeviceType(const std::string& port);
};

} // namespace device_scanner

#endif // DEVICE_SCANNER_H
