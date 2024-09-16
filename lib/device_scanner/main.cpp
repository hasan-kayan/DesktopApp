#include "device_scanner/device_scanner.h"
#include <iostream>

int main() {
    device_scanner::DeviceScanner scanner;
    std::vector<device_scanner::DeviceInfo> devices = scanner.scanDevices();

    for (const auto& device : devices) {
        std::cout << "Port: " << device.port << "\n";
        std::cout << "Type: " << (device.type == device_scanner::DeviceType::MCU_CARD ? "MCU Card" :
                                    device.type == device_scanner::DeviceType::FLASH_DISK ? "Flash Disk" :
                                    "Other") << "\n";
        std::cout << "Description: " << device.description << "\n";
        std::cout << "--------------------------------\n";
    }

    return 0;
}
