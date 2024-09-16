#include <iostream>
#include "port_scanner.h"

int main() {
    // Detect and print the operating system
    #ifdef _WIN32
        std::cout << "Operating System: Windows\n";
    #elif defined(__APPLE__)
        std::cout << "Operating System: macOS\n";
    #elif defined(__linux__)
        std::cout << "Operating System: Linux\n";
    #else
        std::cout << "Operating System: Unknown\n";
    #endif

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
