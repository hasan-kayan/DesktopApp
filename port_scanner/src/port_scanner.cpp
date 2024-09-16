#include "port_scanner.h"

#ifdef _WIN32
    #include "platform/port_scanner_win.h"
#elif defined(__APPLE__)
    #include "platform/port_scanner_mac.h"
#elif defined(__linux__)
    #include "platform/port_scanner_linux.h"
#endif

std::vector<PortInfo> PortScanner::scanAllPorts() {
    std::vector<PortInfo> allPorts;
    auto usbPorts = scanUSBPorts();
    auto uartPorts = scanUARTPorts();
    allPorts.insert(allPorts.end(), usbPorts.begin(), usbPorts.end());
    allPorts.insert(allPorts.end(), uartPorts.begin(), uartPorts.end());
    return allPorts;
}

std::vector<PortInfo> PortScanner::scanUSBPorts() {
#ifdef _WIN32
    return scanUSBPortsWin();
#elif defined(__APPLE__)
    return scanUSBPortsMac();
#elif defined(__linux__)
    return scanUSBPortsLinux();
#endif
}

std::vector<PortInfo> PortScanner::scanUARTPorts() {
#ifdef _WIN32
    return scanUARTPortsWin();
#elif defined(__APPLE__)
    return scanUARTPortsMac();
#elif defined(__linux__)
    return scanUARTPortsLinux();
#endif
}
