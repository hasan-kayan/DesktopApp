import serial.tools.list_ports

def list_serial_ports():
    """Return a list of available serial ports."""
    ports = serial.tools.list_ports.comports()
    return [port.device for port in ports]

def get_serial_details():
    """Return detailed information of available serial ports."""
    ports = serial.tools.list_ports.comports()
    return [{"device": port.device, "description": port.description, "hwid": port.hwid} for port in ports]
