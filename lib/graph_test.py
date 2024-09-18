import numpy as np
from graph_creator import Graph2D, Graph3D
import time

def test_graph2d():
    print("Testing 2D graph...")
    graph = Graph2D("Dynamic 2D Sine Wave")
    x_data = np.linspace(0, 2 * np.pi, 100)
    y_data = np.sin(x_data)
    graph.set_data(x_data, y_data)
    for i in range(100):
        y_data = np.sin(x_data + i / 10.0)
        graph.update_graph(x_data, y_data)
        time.sleep(0.1)
    graph.start()

def test_graph3d():
    print("Testing 3D graph...")
    graph = Graph3D("Random 3D Points")
    x_data = np.random.rand(100)
    y_data = np.random.rand(100)
    z_data = np.random.rand(100)
    graph.set_data(x_data, y_data, z_data)
    for i in range(100):
        x_data = np.random.rand(100)
        y_data = np.random.rand(100)
        z_data = np.random.rand(100)
        graph.update_graph(x_data, y_data, z_data)
        time.sleep(0.1)
    graph.start()

if __name__ == "__main__":
    test_graph2d()
    test_graph3d()
