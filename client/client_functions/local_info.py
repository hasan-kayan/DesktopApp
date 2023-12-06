import socket
import platform
import wifi

def get_local_ip():
    try:
        # Get the local IP address
        local_ip = socket.gethostbyname(socket.gethostname())
        return local_ip
    except Exception as e:
        return f"Error getting local IP: {e}"

def get_wifi_info():
    try:
        # Get WiFi information
        wifi_data = wifi.Cell.all('wlan0')  # Replace 'wlan0' with your actual interface name
        return wifi_data
    except Exception as e:
        return f"Error getting WiFi information: {e}"

def get_system_info():
    try:
        # Get system information
        system_info = {
            "System": platform.system(),
            "Node": platform.node(),
            "Release": platform.release(),
            "Version": platform.version(),
            "Machine": platform.machine(),
            "Processor": platform.processor()
        }
        return system_info
    except Exception as e:
        return f"Error getting system information: {e}"

def get_all_system_info():
    # Get and print local IP
    local_ip = get_local_ip()
    print(f"Local IP: {local_ip}")

    # Get and print WiFi information
    wifi_info = get_wifi_info()
    print("WiFi Information:")
    for cell in wifi_info:
        print(f"SSID: {cell.ssid}, Signal Strength: {cell.signal}")

    # Get and print system information
    system_info = get_system_info()
    print("\nSystem Information:")
    for key, value in system_info.items():
        print(f"{key}: {value}")

# Example usage
if __name__ == "__main__":
    get_all_system_info()
