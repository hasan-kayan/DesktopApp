import platform

# Import platform-specific libraries
if platform.system() == 'Linux':
    import pyudev
elif platform.system() == 'Windows':
    import pywinusb.hid
elif platform.system() == 'Darwin':  # macOS
    import subprocess

def list_usb_devices():
    """Return a list of connected USB devices based on the platform."""
    os_name = platform.system()

    if os_name == 'Linux':
        return list_usb_devices_linux()
    elif os_name == 'Windows':
        return list_usb_devices_windows()
    elif os_name == 'Darwin':
        return list_usb_devices_macos()
    else:
        raise NotImplementedError(f"USB scanning not supported on {os_name}.")

# USB scanning for Linux
def list_usb_devices_linux():
    context = pyudev.Context()
    usb_devices = []
    for device in context.list_devices(subsystem='usb'):
        usb_devices.append({
            'name': device.sys_name,
            'device_path': device.device_path,
            'manufacturer': device.attributes.get('manufacturer'),
            'product': device.attributes.get('product')
        })
    return usb_devices

# USB scanning for Windows
def list_usb_devices_windows():
    usb_devices = []
    all_devices = pywinusb.hid.HidDeviceFilter().get_devices()
    for device in all_devices:
        usb_devices.append({
            'vendor_id': device.vendor_id,
            'product_id': device.product_id,
            'product_name': device.product_name,
            'serial_number': device.serial_number
        })
    return usb_devices

# USB scanning for macOS
def list_usb_devices_macos():
    usb_devices = []
    try:
        result = subprocess.run(['system_profiler', 'SPUSBDataType'], stdout=subprocess.PIPE)
        output = result.stdout.decode()
        devices = output.split('\n')
        current_device = {}
        for line in devices:
            if "Product ID" in line:
                current_device['product_id'] = line.split(':')[-1].strip()
            if "Vendor ID" in line:
                current_device['vendor_id'] = line.split(':')[-1].strip()
            if "Serial Number" in line:
                current_device['serial_number'] = line.split(':')[-1].strip()
            if "Manufacturer" in line:
                current_device['manufacturer'] = line.split(':')[-1].strip()
            if current_device:
                usb_devices.append(current_device)
                current_device = {}
    except Exception as e:
        print(f"Error scanning USB devices on macOS: {e}")
    return usb_devices
