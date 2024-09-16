#include <iostream>
#include "port_scanner.h"

int main() {
    // Scan all ports (USB and UART)
    std::vector<PortInfo> ports = PortScanner::scanAllPorts();

    // Print the detected ports
    if (ports.empty()) {
        std::cout << "No ports detected.\n";
    } else {
        for (const auto& port : ports) {
            std::cout << "Port: " << port.name << "\n";
            std::cout << "Description: " << port.description << "\n";
            std::cout << "Type: " << port.type << "\n\n";
        }
    }

    return 0;
}
