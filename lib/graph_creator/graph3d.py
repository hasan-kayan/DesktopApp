import pyqtgraph as pg
import pyqtgraph.opengl as gl
import numpy as np
from pyqtgraph.Qt import QtWidgets

class Graph3D:
    def __init__(self, title="3D Graph"):
        self.app = QtWidgets.QApplication([])
        self.view = gl.GLViewWidget()
        self.view.setWindowTitle(title)
        self.view.setCameraPosition(distance=40)  # Adjust the distance for a good 3D view
        self.view.show()

        # Create a grid on the 3D view
        self.grid = gl.GLGridItem()
        self.grid.scale(2, 2, 1)
        self.view.addItem(self.grid)

        # Store scatter plot object
        self.scatter_plot = None

    def set_data(self, x_data, y_data, z_data):
        """Sets new 3D data to the graph."""
        pos = np.vstack([x_data, y_data, z_data]).transpose()
        if self.scatter_plot is None:
            self.scatter_plot = gl.GLScatterPlotItem(pos=pos, size=5, color=(1, 1, 1, 1), pxMode=False)
            self.view.addItem(self.scatter_plot)
        else:
            self.scatter_plot.setData(pos=pos)

    def update_graph(self, x_data, y_data, z_data):
        """Updates the graph dynamically with new data."""
        self.set_data(x_data, y_data, z_data)
        QtWidgets.QApplication.processEvents()  # Keep the GUI responsive

    def start(self):
        """Starts the application loop."""
        self.app.exec_()

# Test the 3D graph directly
if __name__ == "__main__":
    graph = Graph3D("Random 3D Points")
    x = np.random.rand(100)
    y = np.random.rand(100)
    z = np.random.rand(100)
    graph.set_data(x, y, z)
    graph.start()
