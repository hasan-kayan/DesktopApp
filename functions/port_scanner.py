import socket

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
