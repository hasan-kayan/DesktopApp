#include <iostream>
#include <boost/asio.hpp>

/**
 * @class SerialPortHandler
 * @brief A class to handle serial port communication using Boost.Asio.
 * 
 * This class provides functionalities to initialize, read from, write to, and close a serial port.
 * It uses Boost.Asio for asynchronous I/O operations.
 * 
 * @details
 * The SerialPortHandler class encapsulates the details of setting up and managing a serial port.
 * It allows users to specify the port name and baud rate during construction and provides methods
 * to write data to and read data from the serial port. The class also ensures proper closure of the
 * serial port when it is no longer needed.
 * 
 * Example usage:
 * @code
 * SerialPortHandler serial("/dev/ttyUSB0", 9600);
 * serial.write("Hello, World!");
 * std::string response = serial.read();
 * serial.close();
 * @endcode
 * 
 * @note This class requires the Boost.Asio library.
 * 
 * @see boost::asio::serial_port
 * 
 * @fn SerialPortHandler::SerialPortHandler(const std::string& port_name, unsigned int baud_rate)
 * @brief Constructs a new SerialPortHandler object.
 * 
 * This constructor initializes the serial port with the specified port name and baud rate.
 * It sets various serial port options including baud rate, character size, stop bits, parity, and flow control.
 * 
 * @param port_name The name of the serial port (e.g., "/dev/ttyUSB0" on Linux or "COM3" on Windows).
 * @param baud_rate The baud rate for the serial communication (e.g., 9600, 115200).
 * 
 * @fn void SerialPortHandler::write(const std::string& data)
 * @brief Writes data to the serial port.
 * 
 * This method sends the specified data to the serial port.
 * 
 * @param data The data to be written to the serial port.
 * 
 * @fn std::string SerialPortHandler::read()
 * @brief Reads data from the serial port.
 * 
 * This method reads data from the serial port and returns it as a string.
 * 
 * @return A string containing the data read from the serial port.
 * 
 * @fn void SerialPortHandler::close()
 * @brief Closes the serial port.
 * 
 * This method closes the serial port, releasing any resources associated with it.
 * 
 * @var SerialPortHandler::io
 * @brief The Boost.Asio I/O service object.
 * 
 * This object is used to perform asynchronous I/O operations.
 * 
 * @var SerialPortHandler::serial
 * @brief The Boost.Asio serial port object.
 * 
 * This object represents the serial port and is used to perform read and write operations.
 */
class SerialPortHandler {
public:
    /**
     * @brief Constructs a new SerialPortHandler object.
     * 
     * This constructor initializes the serial port with the specified port name and baud rate.
     * It sets various serial port options including baud rate, character size, stop bits, parity, and flow control.
     * 
     * @param port_name The name of the serial port (e.g., "/dev/ttyUSB0" on Linux or "COM3" on Windows).
     * @param baud_rate The baud rate for the serial communication (e.g., 9600, 115200).
     */
    SerialPortHandler(const std::string& port_name, unsigned int baud_rate)
        : io(), serial(io, port_name) {
        // Set the baud rate and other port settings
        serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
    }

    /**
     * @brief Writes data to the serial port.
     * 
     * This function sends the provided string data to the serial port using
     * Boost.Asio's write functionality.
     * 
     * @param data The string data to be written to the serial port.
     */
    void write(const std::string& data) {
        boost::asio::write(serial, boost::asio::buffer(data));
    }

    /**
     * @brief Reads data from the serial port.
     * 
     * This function reads up to 1024 bytes of data from the serial port into a buffer
     * and returns it as a std::string.
     * 
     * @return std::string The data read from the serial port.
     */
    std::string read() {
        char buf[1024];
        boost::asio::read(serial, boost::asio::buffer(buf, 1024));
        return std::string(buf);
    }

    /**
     * @brief Closes the serial port connection.
     * 
     * This function closes the serial port connection by calling the 
     * close method on the serial object. It should be called when 
     * the serial communication is no longer needed to free up resources.
     */
    void close() {
        serial.close();
    }
    /**
     * @brief Scans all possible serial ports and prints the names of the found ports.
     * 
     * This function iterates through a range of possible serial port names (from /dev/ttyUSB0 to /dev/ttyUSB255)
     * and attempts to open each one using Boost.Asio's serial_port class. If a port is successfully opened, it is
     * immediately closed and its name is printed to the standard output. If a port cannot be opened, it is assumed
     * to not exist and the function continues to the next port.
     * 
     * @note This function is specific to Unix-like systems where serial ports are named /dev/ttyUSB*.
     */
    void scanAllPorts() {
        for (int i = 0; i < 256; i++) {
            std::string port_name = "/dev/ttyUSB" + std::to_string(i);
            try {
                boost::asio::serial_port serial(io, port_name);
                serial.close();
                std::cout << "Found port: " << port_name << std::endl;
            } catch (const boost::system::system_error& e) {
                // Port not found
            }
        }
    }
    /**
     * @brief Checks the status of all possible serial ports.
     * 
     * This function iterates through all possible serial port names from /dev/ttyUSB0 to /dev/ttyUSB255.
     * For each port, it attempts to open and then immediately close the port to check if it exists.
     * If the port is found, it prints the port name to the standard output.
     * If the port is not found, it catches the exception and continues to the next port.
     * 
     * @note This function uses the Boost.Asio library for serial port operations.
     */
    void checkStatusOfAllPorts(){
        for (int i = 0; i < 256; i++) {
            std::string port_name = "/dev/ttyUSB" + std::to_string(i);
            try {
                boost::asio::serial_port serial(io, port_name);
                serial.close();
                std::cout << "Found port: " << port_name << std::endl;
            } catch (const boost::system::system_error& e) {
                // Port not found
            }
        }
    }
private:
    boost::asio::io_service io;
    boost::asio::serial_port serial;
};
