#ifndef PORT_H // Check if PORT_H is not defined
#define PORT_H // Define PORT_H

#include <iostream>
#include <sstream>
#include <string>

struct Port {
    int portNumber;           // Port number (e.g., 80, 443)
    std::string protocol;     // Protocol type (e.g., "TCP", "UDP")
    std::string status;       // Port status (e.g., "open", "closed", "listening")
    std::string description;  // A description of the port's function (optional)

    // Constructor for easy initialization
    Port(int number, const std::string& proto, const std::string& stat, const std::string& desc)
        : portNumber(number), protocol(proto), status(stat), description(desc) {}

    // Method to display port information
    /**
     * @brief Prints the port information to the standard output.
     * 
     * This function outputs the port number, protocol, status, and description
     * of the port to the console.
     */
    void printPortInfo() const {
        std::cout << "Port Number: " << portNumber << "\n"
                  << "Protocol: " << protocol << "\n"
                  << "Status: " << status << "\n"
                  << "Description: " << description << "\n";
    }

    void readData(std::istream& in) {
        in >> portNumber >> protocol >> status >> description;
    }

    void writeData(std::ostream& out) const {
        out << portNumber << " " << protocol << " " << status << " " << description;
    }

    friend std::ostream& operator<<(std::ostream& out, const Port& port) {
        port.writeData(out);
        return out;
    }

    std::string createSerialConnection(int portNumber) {
        return "Serial connection established on port " + std::to_string(portNumber);
    }
};

#endif // PORT_H
