import serial.tools.list_ports
import threading

class DeviceManager:
    def __init__(self):
        self.devices = []
        self.selected_device = None
        self.is_listening = False

    def list_devices(self):
        """List all connected serial devices."""
        self.devices = [port.device for port in serial.tools.list_ports.comports()]
        return self.devices

    def start_listening(self, device_port, callback):
        """Start listening to a selected device."""
        self.selected_device = device_port
        self.is_listening = True

        def read_data():
            try:
                with serial.Serial(device_port, 9600, timeout=1) as ser:
                    while self.is_listening:
                        line = ser.readline().decode('utf-8').strip()
                        if line:
                            callback(line)  # Send data to the UI via callback
            except Exception as e:
                print(f"Error: {e}")

        # Run the listening function in a separate thread
        threading.Thread(target=read_data, daemon=True).start()

    def stop_listening(self):
        """Stop listening to the current device."""
        self.is_listening = False
