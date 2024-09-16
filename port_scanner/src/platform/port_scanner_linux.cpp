#include "platform/port_scanner_linux.h"
#include <dirent.h>

std::vector<PortInfo> scanUSBPortsLinux()
{
    // Linux USB scanning implementation
    std::vector<PortInfo> ports;
    // Use sysfs or udev to list USB devices
    return ports;
}

std::vector<PortInfo> scanUARTPortsLinux()
{
    // Linux UART scanning implementation
    std::vector<PortInfo> ports;
    // Check /dev/ for tty devices
    return ports;
}
