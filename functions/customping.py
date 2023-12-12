import socket

def send_data_to_all_ports(target_ip, data):
    """
    Sends data to the target IP address on all ports.
    """
    for port in range(1, 65536):
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
                sock.settimeout(1)
                sock.connect((target_ip, port))
                sock.sendall(data.encode())
                print(f"Data sent to {target_ip}:{port}")
        except (socket.timeout, ConnectionRefusedError):
            pass

def send_data_to_port(target_ip, port, data):
    """
    Sends data to the target IP address on a specific port.
    """
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
            sock.settimeout(1)
            sock.connect((target_ip, port))
            sock.sendall(data.encode())
            print(f"Data sent to {target_ip}:{port}")
    except (socket.timeout, ConnectionRefusedError):
        print(f"Failed to send data to {target_ip}:{port}")

# # Example usage:
# target_ip = "127.0.0.1"  # Replace with your target IP address
# data_to_send = "Hello, world!"

# # Send data to all ports
# send_data_to_all_ports(target_ip, data_to_send)

# # User specifies a port to send data
# user_selected_port = 8080  # Replace with the desired port
# send_data_to_port(target_ip, user_selected_port, data_to_send)
