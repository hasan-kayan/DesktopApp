#include <iostream>
#include <boost/asio.hpp>

class Port {
public:
    Port(const std::string& port_name, unsigned int baud_rate)
        : io(), serial(io, port_name) {
        // Set the baud rate and other port settings
        serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
    }
   
private:
    boost::asio::io_service io;
    boost::asio::serial_port serial;
};
