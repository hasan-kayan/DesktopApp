#ifndef PORT_SCANNER_MAC_H
#define PORT_SCANNER_MAC_H

#include <vector>
#include "port_scanner.h"

// macOS-specific functions to scan ports
std::vector<PortInfo> scanUSBPortsMac();     // Scan USB ports on macOS
std::vector<PortInfo> scanUARTPortsMac();    // Scan UART/serial ports on macOS

#endif // PORT_SCANNER_MAC_H
