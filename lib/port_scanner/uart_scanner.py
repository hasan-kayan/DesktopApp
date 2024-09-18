import pyudev

def list_usb_devices():
    """Return a list of connected USB devices on Linux."""
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
