#include "device_scanner/device_scanner.h"
#include <iostream>
#include <vector>

// Mock implementation of PortScanner, replace with actual port scanning logic
#include "../port_scanner/src/port_scanner.cpp"

namespace device_scanner {

DeviceScanner::DeviceScanner() {
    // Initialize the PortScanner object
}

DeviceScanner::~DeviceScanner() {
    // Clean up resources if needed
}

std::vector<DeviceInfo> DeviceScanner::scanDevices() {
    std::vector<DeviceInfo> devices;
    
    // Use portScanner to list connected ports
    std::vector<std::string> ports = portScanner.listPorts(); // Mocked method
    for (const auto& port : ports) {
        DeviceType type = identifyDeviceType(port);
        std::string description = "Description not available"; // Add logic to get description

        devices.push_back({port, type, description});
    }
    
    return devices;
}

DeviceType DeviceScanner::identifyDeviceType(const std::string& port) {
    // Logic to identify device type based on port
    // This is a simplified version, actual implementation may involve querying device descriptors

    if (port.find("MCU") != std::string::npos) {
        return DeviceType::MCU_CARD;
    } else if (port.find("Flash") != std::string::npos) {
        return DeviceType::FLASH_DISK;
    } else {
        return DeviceType::OTHER;
    }
}

} // namespace device_scanner
