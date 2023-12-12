import socket
import subprocess
import ipaddress


def port_scan(target_ip, start_port, end_port):
    open_ports = []

    for port in range(start_port, end_port + 1):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(1)

        try:
            sock.connect((target_ip, port))
            open_ports.append(port)
            print(f"Port {port} is open.")
        except (socket.timeout, ConnectionRefusedError):
            pass
        finally:
            sock.close()

    return open_ports

# Kullanım örneği:
# target_ip = "127.0.0.1"  # Hedef IP adresini değiştirin
# start_port = 1
# end_port = 1024

# open_ports = port_scan(target_ip, start_port, end_port)

# if open_ports:
#     print("Open ports:", open_ports)
# else:
#     print("No open ports found in the specified range.")



def find_devices_in_network(network):
    devices = []

    # IP adresi aralığındaki her IP'yi tara
    for ip in ipaddress.IPv4Network(network, strict=False).hosts():
        ip_str = str(ip)
        
        # ICMP ping isteği gönder
        try:
            subprocess.check_output(["ping", "-c", "1", ip_str], stderr=subprocess.STDOUT, text=True)
            devices.append(ip_str)
        except subprocess.CalledProcessError:
            pass

    return devices

# # Kullanım örneği:
# network_to_scan = "192.168.1.0/24"  # Taramak istediğiniz IP aralığını belirtin

# found_devices = find_devices_in_network(network_to_scan)

# 
print("Started")
network_to_scan = "192.168.1.0/24" 
print("Scanning devices")
found_devices = find_devices_in_network(network_to_scan)
print("scanned")
if found_devices:
    print("Found devices in the network:")
    for device in found_devices:
        print("- ", device)
else:
    print("No devices found in the network.")