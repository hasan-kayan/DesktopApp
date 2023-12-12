import streamlit as st
from functions.ping import * 

def ping_ip_app():
    st.title("Ping IP Checker")

    # User input for target IP
    target_ip = st.text_input("Enter the target IP address:")

    # Button to trigger the ping
    if st.button("Ping"):
        result = ping_ip(target_ip)
        
        # Customize the visual output based on the result
        if result:
            st.success(f"Target {target_ip} is reachable!")
        else:
            st.error(f"Target {target_ip} is unreachable.")
            
if __name__ == "__main__":
    ping_ip_app()