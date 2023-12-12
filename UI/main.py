import streamlit as st
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Function to generate random data for the graphics
def generate_data():
    x = np.linspace(0, 2 * np.pi, 100)
    y1 = np.sin(x)
    y2 = np.cos(x)
    return x, y1, y2

# Function to update the graphics in real-time
def update_graph(i, x, y1, y2, line1, line2):
    line1.set_ydata(np.sin(x + i/10.0))
    line2.set_ydata(np.cos(x + i/10.0))
    return line1, line2

# Streamlit UI
def main():
    st.title("Real-Time Graphics with Buttons")

    # Create buttons
    button1 = st.button("Button 1")
    button2 = st.button("Button 2")
    button3 = st.button("Button 3")
    button4 = st.button("Button 4")

    # Generate initial data for the graphics
    x, y1, y2 = generate_data()

    # Create two subplots for the graphics
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(8, 6))
    line1, = ax1.plot(x, y1, label="Sin(x)")
    line2, = ax2.plot(x, y2, label="Cos(x)")

    # Set plot titles and labels
    ax1.set_title("Real-Time Sin(x) Plot")
    ax2.set_title("Real-Time Cos(x) Plot")
    ax1.set_xlabel("x")
    ax2.set_xlabel("x")
    ax1.set_ylabel("sin(x)")
    ax2.set_ylabel("cos(x)")
    ax1.legend()
    ax2.legend()

    # Update graphics in real-time using FuncAnimation
    ani = FuncAnimation(fig, update_graph, fargs=(x, y1, y2, line1, line2), interval=100)

    # Display the Streamlit UI
    st.pyplot(fig)

if __name__ == "__main__":
    main()
