import streamlit as st
from functions.scanner import * 



def service_1():
    st.title("Network Scanner")

    st.write("""
    This service allows you to perform network scanning using two functions:
    - Port Scan: Scan for open ports on a target IP within a specified range.
    - Device Discovery: Find devices in a network by pinging each IP.
    """)

    # Port Scan section
    st.header("Port Scan")

    target_ip = st.text_input("Enter the target IP address:")
    start_port = st.number_input("Enter the start port:", min_value=1, max_value=65535, value=1)
    end_port = st.number_input("Enter the end port:", min_value=1, max_value=65535, value=1024)

    if st.button("Scan Ports"):
        open_ports = port_scan(target_ip, start_port, end_port)
        if open_ports:
            st.success(f"Open ports: {open_ports}")
        else:
            st.warning("No open ports found in the specified range.")

    # Device Discovery section
    st.header("Device Discovery")

    network_to_scan = st.text_input("Enter the network to scan (e.g., 192.168.1.0/24):")

    if st.button("Scan Devices"):
        found_devices = find_devices_in_network(network_to_scan)
        if found_devices:
            st.success("Found devices in the network:")
            for device in found_devices:
                st.write("- ", device)
        else:
            st.warning("No devices found in the network.")
            

if __name__ == "__main__":
    service_1()