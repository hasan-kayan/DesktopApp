#include <iostream>
#include <sstream>
#include "Port.h" // Include the Port structure definition

int main() {
    // Test creating and printing a Port object
    Port httpPort(80, "TCP", "open", "HTTP port for web traffic");
    std::cout << "Testing Port Object Creation and Print:\n";
    httpPort.printPortInfo();

    // Test writing data to an output stream
    std::cout << "\nTesting Writing Port Info to Stream:\n";
    std::ostringstream oss;
    httpPort.writeData(oss);
    std::cout << "Written Data: " << oss.str() << "\n";

    // Test reading data from an input stream  
    std::cout << "\nTesting Reading Port Data from Input Stream:\n";
    std::istringstream iss("443 TCP open HTTPS port for secure web traffic");
    Port httpsPort(0, "", "", "");
    httpsPort.readData(iss);
    std::cout << "Data Read from Stream:\n";
    httpsPort.printPortInfo();

    // Test serial connection creation
    std::cout << "\nTesting Serial Connection Creation:\n";
    std::string connectionMessage = httpsPort.createSerialConnection(443);
    std::cout << connectionMessage << "\n";

    // Additional tests
    std::cout << "\nAdditional Tests:\n";
    Port ftpPort(21, "TCP", "open", "FTP port for file transfers");
    ftpPort.printPortInfo();

    std::ostringstream oss2;
    ftpPort.writeData(oss2);
    std::cout << "Written Data for FTP: " << oss2.str() << "\n";

    return 0;
}
