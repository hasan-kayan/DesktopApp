import graph_creator
import numpy as np  # Add this at the top of the file

# 2D graph
graph_2d = graph_creator.Graph2D("Live 2D Sine Wave")
x_data = np.linspace(0, 2 * np.pi, 100)
y_data = np.sin(x_data)
graph_2d.set_data(x_data, y_data)

# Dynamically update the graph
for i in range(100):
    y_data = np.sin(x_data + i / 10.0)
    graph_2d.update_graph(x_data, y_data)

graph_2d.start()

# 3D graph
graph_3d = graph_creator.Graph3D("Random 3D Points")
x_data = np.random.rand(100)
y_data = np.random.rand(100)
z_data = np.random.rand(100)
graph_3d.set_data(x_data, y_data, z_data)
graph_3d.start()
