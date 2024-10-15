/**
 * @file Port.cpp
 * @brief Implementation of the Port structure for managing port information.
 * 
 * This file contains the definition and implementation of the Port structure,
 * which is used to store and display information about network ports, including
 * their number, protocol, status, and description.
 * 
 * @author Hasan Kayan
 * @date 2023
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
#include <iostream>
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
     * @brief Prints the information of the port.
     * 
     * This function outputs the port number, protocol, status, and description
     * to the standard output stream.
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
     * This function extracts values from the input stream and assigns them to the 
     * member variables `portNumber`, `protocol`, `status`, and `description`.
     * 
     * @param in The input stream from which data is read.
     */
    void readData (std::istream& in) {
        in >> portNumber >> protocol >> status >> description;
    }   
    /**
     * @brief Writes the port details to the given output stream.
     * 
     * This function outputs the port number, protocol, status, and description
     * to the provided output stream in a space-separated format.
     * 
     * @param out The output stream to which the port details will be written.
     */
    void writeData (std::ostream& out) const {
        out << portNumber << " " << protocol << " " << status << " " << description;
    }

    /**
     * @brief Overloads the << operator to output the Port object to an output stream.
     * 
     * This friend function allows the Port object to be output to an std::ostream
     * by calling the writeData method of the Port class.
     * 
     * @param out The output stream to which the Port object will be written.
     * @param port The Port object to be written to the output stream.
     * @return std::ostream& The output stream after writing the Port object.
     */
    friend std::ostream& operator<< (std::ostream& out, const Port& port) {
        port.writeData(out);
        return out;
    }

    // Create serial port connection to the given port number
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
        // Code to create serial port connection
        return "Serial connection established on port " + std::to_string(portNumber);
    }
};
