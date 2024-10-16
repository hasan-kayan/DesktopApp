#include <iostream>
#include <fcntl.h>      // File control definitions
#include <termios.h>    // POSIX terminal control definitions
#include <unistd.h>     // UNIX standard function definitions
#include <errno.h>      // Error number definitions
#include <cstring>

int openSerialPort(const char* portname) {
    // Open the serial port for reading and writing, and non-blocking
    int serialPort = open(portname, O_RDWR | O_NOCTTY | O_NDELAY);
    if (serialPort == -1) {
        std::cerr << "Error opening serial port: " << strerror(errno) << std::endl;
        return -1;
    }
    return serialPort;
}

bool configureSerialPort(int serialPort, speed_t baudrate) {
    struct termios options;
    if (tcgetattr(serialPort, &options) < 0) {
        std::cerr << "Error getting terminal attributes: " << strerror(errno) << std::endl;
        return false;
    }

    // Set the baud rate for both input and output
    cfsetispeed(&options, baudrate);
    cfsetospeed(&options, baudrate);

    // Configure the serial port settings
    options.c_cflag |= (CLOCAL | CREAD);    // Enable receiver, set local mode
    options.c_cflag &= ~PARENB;             // No parity bit
    options.c_cflag &= ~CSTOPB;             // One stop bit
    options.c_cflag &= ~CSIZE;              // Clear size bits
    options.c_cflag |= CS8;                 // 8 data bits

    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  // Raw input mode
    options.c_iflag &= ~(IXON | IXOFF | IXANY);          // Disable software flow control
    options.c_oflag &= ~OPOST;                           // Raw output mode

    // Apply the settings to the serial port
    if (tcsetattr(serialPort, TCSANOW, &options) < 0) {
        std::cerr << "Error setting terminal attributes: " << strerror(errno) << std::endl;
        return false;
    }

    return true;
}

int readFromSerialPort(int serialPort, char* buffer, size_t size) {
    int bytesRead = read(serialPort, buffer, size);
    if (bytesRead < 0) {
        std::cerr << "Error reading from serial port: " << strerror(errno) << std::endl;
        return -1;
    }
    return bytesRead;
}

void closeSerialPort(int serialPort) {
    close(serialPort);
}

int main() {
    const char* portname = "/dev/ttyUSB0";  // Change this to your USB port
    int serialPort = openSerialPort(portname);

    if (serialPort == -1) {
        return 1;  // Error opening the port
    }

    if (!configureSerialPort(serialPort, B9600)) {  // Configure with baudrate 9600
        closeSerialPort(serialPort);
        return 1;
    }

    char buffer[256];
    while (true) {
        int bytesRead = readFromSerialPort(serialPort, buffer, sizeof(buffer) - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  // Null-terminate the string
            std::cout << "Received: " << buffer << std::endl;
        }
        // Add your break condition here
        usleep(100000);  // Sleep for 100ms to avoid busy-waiting
    }

    closeSerialPort(serialPort);
    return 0;
}
