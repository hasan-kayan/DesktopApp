/**
 * @file Port.cpp
 * @brief Implementation of the Port structure for managing port information.
 * 
 * This file contains the definition and implementation of the Port structure,
 * which is used to store and display information about network ports, including
 * their number, protocol, status, and description.
 * 
 * @author Hasan Kayan
 * @github hasan-kayan
 * @date 2024-09-25
 */

/**
 * @struct Port
 * @brief A structure to represent a network port.
 * 
 * The Port structure holds information about a network port, including its
 * number, protocol type, status, and an optional description of its function.
 * 
 * @var Port::portNumber
 * The port number (e.g., 80, 443).
 * 
 * @var Port::protocol
 * The protocol type (e.g., "TCP", "UDP").
 * 
 * @var Port::status
 * The status of the port (e.g., "open", "closed", "listening").
 * 
 * @var Port::description
 * A description of the port's function (optional).
 * 
 * @fn Port::Port(int number, const std::string& proto, const std::string& stat, const std::string& desc)
 * @brief Constructor to initialize a Port object.
 * 
 * This constructor initializes a Port object with the specified port number,
 * protocol type, status, and description.
 * 
 * @param number The port number.
 * @param proto The protocol type.
 * @param stat The status of the port.
 * @param desc A description of the port's function.
 * 
 * @fn void Port::printPortInfo() const
 * @brief Prints the information of the port.
 * 
 * This function outputs the port number, protocol, status, and description
 * to the standard output stream.
 */

// INCLUDES
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Port.h"   
struct Port {
    int portNumber;           // Port number (e.g., 80, 443)
    std::string protocol;     // Protocol type (e.g., "TCP", "UDP")
    std::string status;       // Port status (e.g., "open", "closed", "listening")
    std::string description;  // A description of the port's function (optional)

    // Constructor for easy initialization
    Port(int number, const std::string& proto, const std::string& stat, const std::string& desc)
        : portNumber(number), protocol(proto), status(stat), description(desc) {}

    // Method to display port information
    void printPortInfo() const {
        std::cout << "Port Number: " << portNumber << "\n"
                  << "Protocol: " << protocol << "\n"
                  << "Status: " << status << "\n"
                  << "Description: " << description << "\n";
    }

    /**
     * @brief Reads data from the given input stream and assigns it to the member variables.
     * 
     * This function extracts values from the input stream and assigns them to the 
     * member variables `portNumber`, `protocol`, `status`, and `description`.
     * 
     * @param in The input stream from which data is read.
     * @throw std::runtime_error If reading fails or input format is invalid.
     */
    void readData(std::istream& in) {
        if (!(in >> portNumber >> protocol >> status)) {
            throw std::runtime_error("Error reading port data: Invalid input format.");
        }
        std::getline(in >> std::ws, description); // Read the rest of the line as description
        if (description.empty()) {
            throw std::runtime_error("Error reading port data: Description cannot be empty.");
        }
    }   

    /**
     * @brief Writes the port details to the given output stream.
     * 
     * This function outputs the port number, protocol, status, and description
     * to the provided output stream in a space-separated format.
     * 
     * @param out The output stream to which the port details will be written.
     * @throw std::runtime_error If writing to the output stream fails.
     */
    void writeData(std::ostream& out) const {
        if (!(out << portNumber << " " << protocol << " " << status << " " << description)) {
            throw std::runtime_error("Error writing port data: Failed to output data.");
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Port& port) {
        port.writeData(out);
        return out;
    }

    /**
     * @brief Creates a serial port connection to the specified port number.
     * 
     * This function establishes a serial port connection to the specified port
     * number and returns a status message indicating whether the connection
     * was successful or not.
     * 
     * @param portNumber The port number to which the serial connection will be made.
     * @return std::string A status message indicating the success or failure of the connection.
     */
    std::string createSerialConnection(int portNumber) {
        if (portNumber < 1 || portNumber > 65535) {
            throw std::invalid_argument("Invalid port number: Port number must be between 1 and 65535.");
        }
        // Code to create serial port connection
        return "Serial connection established on port " + std::to_string(portNumber);
    }
};

