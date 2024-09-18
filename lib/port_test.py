import port_scanner

def test_serial_ports():
    print("Testing Serial Port Detection:")
    serial_ports = port_scanner.list_serial_ports()
    if serial_ports:
        print(f"Serial Ports found: {serial_ports}")
    else:
        print("No serial ports found.")
    
    serial_details = port_scanner.get_serial_details()
    if serial_details:
        print("Serial Port Details:")
        for detail in serial_details:
            print(detail)
    else:
        print("No detailed information found for serial ports.")

def test_usb_devices():
    print("\nTesting USB Device Detection:")
    usb_devices = port_scanner.list_usb_devices()
    if usb_devices:
        print(f"USB Devices found: {usb_devices}")
    else:
        print("No USB devices found.")

if __name__ == "__main__":
    test_serial_ports()
    test_usb_devices()
