#ifndef PORT_SCANNER_H
#define PORT_SCANNER_H

#include <string>
#include <vector>

// Data structure to store port information
struct PortInfo {
    std::string name;        // Name of the port (e.g., "COM3", "/dev/ttyUSB0")
    std::string description; // Description of the port (e.g., "USB Serial Device")
    std::string type;        // Type of the port (e.g., "USB", "UART")
};

// PortScanner class interface
class PortScanner {
public:
    // Static methods to scan ports
    static std::vector<PortInfo> scanAllPorts();     // Scan all ports (USB, UART, etc.)
    static std::vector<PortInfo> scanUSBPorts();     // Scan USB ports
    static std::vector<PortInfo> scanUARTPorts();    // Scan UART/serial ports
};

#endif // PORT_SCANNER_H
