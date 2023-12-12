import streamlit as st
from functions.customping import *

def send_data_app():
    st.title("Data Sender App")

    # User input for target IP and data to send
    target_ip = st.text_input("Enter the target IP address:")
    data_to_send = st.text_input("Enter the data to send:")

    # Option to send data to all ports
    if st.button("Send Data to All Ports"):
        send_data_to_all_ports(target_ip, data_to_send)
        st.success(f"Data sent to {target_ip} on all ports.")

    # Option to send data to a specific port
    port_to_send = st.number_input("Enter the port to send data to:", min_value=1, max_value=65535, value=8080, step=1)
    if st.button("Send Data to Specific Port"):
        send_data_to_port(target_ip, port_to_send, data_to_send)
        st.success(f"Data sent to {target_ip}:{port_to_send}.")

# Run the app
if __name__ == "__main__":
    send_data_app()
