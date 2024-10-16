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

    /**
     * @brief Reads data from the given input stream and assigns it to the member variables.
     * 
     * This function extracts data from the provided input stream and assigns the values to 
     * the member variables `portNumber`, `protocol`, `status`, and `description`.
     * 
     * @param in The input stream from which data is read.
     */

    void writeData(std::ostream& out) const {
        out << portNumber << " " << protocol << " " << status << " " << description;
    }

    /**
     * @brief Overloaded stream insertion operator for the Port class.
     *
     * This friend function allows the Port object to be inserted into an output stream.
     * It calls the writeData method of the Port class to write the data to the stream.
     *
     * @param out The output stream to which the Port object will be written.
     * @param port The Port object to be written to the output stream.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Port& port) {
        port.writeData(out);
        return out;
    }

    /**
     * @brief Establishes a serial connection on the specified port.
     * 
     * @param portNumber The port number on which to establish the serial connection.
     * @return A string indicating that the serial connection has been established on the specified port.
     */
    std::string createSerialConnection(int portNumber) {
        return "Serial connection established on port " + std::to_string(portNumber);
    }
};

#endif // PORT_H
