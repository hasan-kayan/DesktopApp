#ifndef PORT_SCANNER_WIN_H
#define PORT_SCANNER_WIN_H

#include <vector>
#include "port_scanner.h"

// Windows-specific functions to scan ports
std::vector<PortInfo> scanUSBPortsWin();     // Scan USB ports on Windows
std::vector<PortInfo> scanUARTPortsWin();    // Scan UART/serial ports on Windows

#endif // PORT_SCANNER_WIN_H
