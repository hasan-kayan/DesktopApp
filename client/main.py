import socket
import platform
import wifi
import argparse

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

   

    # Get and print system information
    system_info = get_system_info()
    print("\nSystem Information:")
    for key, value in system_info.items():
        print(f"{key}: {value}")
def scan_ports(target_host, start_port, end_port):
    open_ports = []

    for port in range(start_port, end_port + 1):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(1)

        try:
            sock.connect((target_host, port))
            open_ports.append(port)
            print(f"Port {port} is open.")
        except (socket.timeout, ConnectionRefusedError):
            pass
        finally:
            sock.close()

    return open_ports

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Port Scanner")
    parser.add_argument("host", help="Target host to scan")
    parser.add_argument("start_port", type=int, help="Start port of the scan range")
    parser.add_argument("end_port", type=int, help="End port of the scan range")
    
    args = parser.parse_args()

    open_ports = scan_ports(args.host, args.start_port, args.end_port)

    if open_ports:
        print("Open ports:", open_ports)
    else:
        print("No open ports found in the specified range.")