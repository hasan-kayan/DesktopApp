import streamlit as st
from functions.scanner import * 
def homepage():
    st.title("Welcome to the Home Page")
    st.write("This is the home page content.")




def service_2():
    st.title("Service 2")
    st.write("This is the content for Service 2.")

def service_3():
    st.title("Service 3")
    st.write("This is the content for Service 3.")

def service_4():
    st.title("Service 4")
    st.write("This is the content for Service 4.")

# Sidebar
sidebar_options = ["Home", "Port Scanner", "Service 2", "Service 3", "Service 4"]
selected_service = st.sidebar.selectbox("Select a service", sidebar_options)

# Content based on selected service
if selected_service == "Home":
    homepage()
elif selected_service == "Service 1":
    service_1()
elif selected_service == "Service 2":
    service_2()
elif selected_service == "Service 3":
    service_3()
elif selected_service == "Service 4":
    service_4()
