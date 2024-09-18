#include "platform/port_scanner_win.h"
#include <windows.h>
#include <setupapi.h>

std::vector<PortInfo> scanUSBPortsWin() {
    // Windows USB scanning implementation
    std::vector<PortInfo> ports;
    // Use SetupAPI to list USB devices
    return ports;
}

std::vector<PortInfo> scanUARTPortsWin() {
    // Windows UART scanning implementation
    std::vector<PortInfo> ports;
    // Use SetupAPI to list serial ports
    return ports;
}
