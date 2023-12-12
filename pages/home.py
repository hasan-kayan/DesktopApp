import streamlit as st
from functions.scanner import * 

def homepage():
    st.title("Welcome to SecSingle")
    st.write("This is a very simple network scanner and basic information creator.")
    
    

if __name__ == "__main__":
    homepage()