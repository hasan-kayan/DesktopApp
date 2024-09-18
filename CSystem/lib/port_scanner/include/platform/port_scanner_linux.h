#ifndef PORT_SCANNER_LINUX_H
#define PORT_SCANNER_LINUX_H

#include <vector>
#include "port_scanner.h"

// Linux-specific functions to scan ports
std::vector<PortInfo> scanUSBPortsLinux();     // Scan USB ports on Linux
std::vector<PortInfo> scanUARTPortsLinux();    // Scan UART/serial ports on Linux

#endif // PORT_SCANNER_LINUX_H
