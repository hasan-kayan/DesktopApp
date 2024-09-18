from PyQt5.QtWidgets import QApplication, QMainWindow, QListWidget, QLabel, QVBoxLayout, QWidget, QPushButton, QHBoxLayout
import sys
from device_manager import DeviceManager

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Device Listener')
        self.setGeometry(100, 100, 600, 400)

        self.device_manager = DeviceManager()

        # Create main layout
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # Device list section
        self.device_list = QListWidget()
        self.device_list_label = QLabel('Connected Devices:')
        self.layout.addWidget(self.device_list_label)
        self.layout.addWidget(self.device_list)

        # Select and listen button
        self.listen_button = QPushButton('Start Listening')
        self.layout.addWidget(self.listen_button)

        # Data flow label (left modal)
        self.data_label = QLabel('Data Flow:')
        self.data_flow = QLabel('')
        self.layout.addWidget(self.data_label)
        self.layout.addWidget(self.data_flow)

        # Load connected devices when the program starts
        self.load_devices()

        # Connect button to the function that starts listening
        self.listen_button.clicked.connect(self.on_listen)

    def load_devices(self):
        """Load the list of connected devices."""
        devices = self.device_manager.list_devices()
        self.device_list.clear()
        for device in devices:
            self.device_list.addItem(device)

    def on_listen(self):
        """Start listening to the selected device."""
        selected_item = self.device_list.currentItem()
        if selected_item:
            selected_device = selected_item.text()
            self.device_manager.start_listening(selected_device, self.display_data)
            self.listen_button.setText(f'Listening on {selected_device}')

    def display_data(self, data):
        """Display incoming data in the UI."""
        self.data_flow.setText(f"Data: {data}")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
