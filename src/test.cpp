#include "../include/ListenPort.h"
#include <iostream>
#include <unistd.h>  // for usleep()

int main() {
    const char* portname = "/dev/ttyUSB0";  // Change this to your serial port
    int serialPort = openSerialPort(portname);

    if (serialPort == -1) {
        std::cerr << "Failed to open the serial port" << std::endl;
        return 1;
    }

    // Configure the serial port (baudrate set to 9600 in this example)
    if (!configureSerialPort(serialPort, B9600)) {
        std::cerr << "Failed to configure the serial port" << std::endl;
        closeSerialPort(serialPort);
        return 1;
    }

    std::cout << "Serial port configured successfully. Reading data..." << std::endl;

    char buffer[256];
    int bytesRead;
    
    // Example: Read data from the serial port in a loop
    for (int i = 0; i < 5; i++) {
        bytesRead = readFromSerialPort(serialPort, buffer, sizeof(buffer) - 1);

        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  // Null-terminate the received data
            std::cout << "Received (" << bytesRead << " bytes): " << buffer << std::endl;
        } else if (bytesRead == 0) {
            std::cout << "No data available." << std::endl;
        }
        
        // You can add a delay between reads to avoid busy-waiting
        usleep(1000000);  // Sleep for 1 second
    }

    // Close the serial port
    closeSerialPort(serialPort);
    std::cout << "Serial port closed." << std::endl;

    return 0;
}
