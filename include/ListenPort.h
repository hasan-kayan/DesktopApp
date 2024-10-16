#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <termios.h>  // POSIX terminal control definitions
#include <cstddef>    // For size_t

// Opens the serial port and returns the file descriptor (or -1 if an error occurs)
/**
 * @brief Opens a serial port with the specified port name.
 * 
 * This function attempts to open a serial port using the provided port name.
 * It returns a file descriptor for the opened port, or -1 if an error occurs.
 * 
 * @param portname The name of the serial port to open (e.g., "/dev/ttyS0").
 * @return int The file descriptor for the opened serial port, or -1 on error.
 */
int openSerialPort(const char* portname);

// Configures the serial port settings (e.g., baud rate, data bits, stop bits, etc.)
/**
 * @brief Configures the serial port with the specified baud rate.
 * 
 * @param serialPort The file descriptor of the serial port to configure.
 * @param baudrate The baud rate to set for the serial port.
 * @return true if the configuration is successful, false otherwise.
 */
bool configureSerialPort(int serialPort, speed_t baudrate);

// Reads data from the serial port into the buffer and returns the number of bytes read
/**
 * @brief Reads data from a serial port.
 * 
 * This function reads up to `size` bytes of data from the specified serial port
 * into the provided buffer. The function blocks until data is available or an
 * error occurs.
 * 
 * @param serialPort The file descriptor of the serial port to read from.
 * @param buffer A pointer to the buffer where the read data will be stored.
 * @param size The maximum number of bytes to read.
 * @return The number of bytes actually read, or -1 if an error occurred.
 */
int readFromSerialPort(int serialPort, char* buffer, size_t size);

// Closes the serial port
/**
 * @brief Closes the specified serial port.
 * 
 * This function closes the serial port identified by the given file descriptor.
 * It is important to close the serial port to free up system resources and 
 * avoid potential conflicts with other processes.
 * 
 * @param serialPort The file descriptor of the serial port to be closed.
 */
void closeSerialPort(int serialPort);

#endif // SERIALPORT_H
