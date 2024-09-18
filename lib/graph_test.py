# test.py

import numpy as np
from graph_creator import Graph2D, Graph3D
import time

def test_graph2d():
    print("Testing 2D graph...")
    
    # Create the 2D graph
    graph = Graph2D("Dynamic 2D Sine Wave")
    x_data = np.linspace(0, 2 * np.pi, 100)
    y_data = np.sin(x_data)
    graph.set_data(x_data, y_data)
    
    # Simulate dynamic updates to the graph
    for i in range(100):
        y_data = np.sin(x_data + i / 10.0)
        graph.update_graph(x_data, y_data)
        time.sleep(0.1)  # Simulate data updating over time
    
    graph.start()  # Start the app

def test_graph3d():
    print("Testing 3D graph...")
    
    # Create the 3D graph
    graph = Graph3D("Random 3D Points")
    x_data = np.random.rand(100)
    y_data = np.random.rand(100)
    z_data = np.random.rand(100)
    graph.set_data(x_data, y_data, z_data)
    
    # Simulate dynamic updates to the 3D graph
    for i in range(100):
        x_data = np.random.rand(100)
        y_data = np.random.rand(100)
        z_data = np.random.rand(100)
        graph.update_graph(x_data, y_data, z_data)
        time.sleep(0.1)  # Simulate data updating over time

    graph.start()  # Start the app

if __name__ == "__main__":
    # Test the 2D and 3D graphs
    test_graph2d()  # Test 2D dynamic graph
    test_graph3d()  # Test 3D dynamic graph
