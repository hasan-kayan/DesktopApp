#include "../include/ListenPort.h"
#include <iostream>
#include <fcntl.h>      // File control definitions
#include <unistd.h>     // UNIX standard function definitions
#include <errno.h>      // Error number definitions
#include <cstring>      // For strerror

/**
 * @brief Opens a serial port for reading and writing in non-blocking mode.
 *
 * This function attempts to open the specified serial port with read and write
 * permissions and in non-blocking mode. If the port cannot be opened, an error
 * message is printed to the standard error stream.
 *
 * @param portname The name of the serial port to open (e.g., "/dev/ttyS0").
 * @return The file descriptor for the opened serial port, or -1 if an error occurred.
 */
int openSerialPort(const char* portname) {
    // Open the serial port for reading and writing, non-blocking mode
    int serialPort = open(portname, O_RDWR | O_NOCTTY | O_NDELAY);
    if (serialPort == -1) {
        std::cerr << "Error opening serial port: " << strerror(errno) << std::endl;
        return -1;
    }
    return serialPort;
}

/**
 * @brief Configures the serial port with the specified baud rate.
 *
 * This function sets up the serial port with the given baud rate and configures
 * various options such as disabling parity, setting 8 data bits, and enabling
 * raw input and output modes.
 *
 * @param serialPort The file descriptor of the serial port to configure.
 * @param baudrate The baud rate to set for the serial port.
 * @return true if the serial port was successfully configured, false otherwise.
 */
bool configureSerialPort(int serialPort, speed_t baudrate) {
    struct termios options;

    // Get the current serial port settings
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

/**
 * @brief Reads data from a serial port.
 *
 * This function attempts to read a specified number of bytes from a given serial port
 * into a provided buffer. If the read operation fails, an error message is printed
 * to the standard error stream.
 *
 * @param serialPort The file descriptor of the serial port to read from.
 * @param buffer A pointer to the buffer where the read data will be stored.
 * @param size The number of bytes to read from the serial port.
 * @return The number of bytes successfully read, or -1 if an error occurred.
 */
int readFromSerialPort(int serialPort, char* buffer, size_t size) {
    // Read data from the serial port
    int bytesRead = read(serialPort, buffer, size);
    if (bytesRead < 0) {
        std::cerr << "Error reading from serial port: " << strerror(errno) << std::endl;
        return -1;
    }
    return bytesRead;
}

/**
 * @brief Closes the specified serial port.
 * 
 * This function closes the serial port identified by the given file descriptor.
 * 
 * @param serialPort The file descriptor of the serial port to be closed.
 */
void closeSerialPort(int serialPort) {
    // Close the serial port
    close(serialPort);
}
