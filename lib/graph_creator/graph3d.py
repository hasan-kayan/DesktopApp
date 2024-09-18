import pyqtgraph as pg
import pyqtgraph.opengl as gl
import numpy as np
from pyqtgraph.Qt import QtWidgets

class Graph3D:
    def __init__(self, title="3D Line Graph"):
        self.app = QtWidgets.QApplication([])
        self.view = gl.GLViewWidget()
        self.view.setWindowTitle(title)
        self.view.setCameraPosition(distance=40)  # Adjust camera distance for a good 3D view
        self.view.show()

        # Create a grid on the 3D view
        self.grid = gl.GLGridItem()
        self.grid.scale(2, 2, 1)
        self.view.addItem(self.grid)

        # Store the line plot object
        self.line_plot = None

    def set_data(self, x_data, y_data, z_data):
        """Sets new 3D line data to the graph."""
        pos = np.vstack([x_data, y_data, z_data]).transpose()
        if self.line_plot is None:
            # Create a 3D line plot
            self.line_plot = gl.GLLinePlotItem(pos=pos, color=(1, 1, 1, 1), width=2, antialias=True)
            self.view.addItem(self.line_plot)
        else:
            self.line_plot.setData(pos=pos)

    def update_graph(self, x_data, y_data, z_data):
        """Updates the graph dynamically with new data."""
        self.set_data(x_data, y_data, z_data)
        QtWidgets.QApplication.processEvents()  # Keep the GUI responsive

    def start(self):
        """Starts the application loop."""
        self.app.exec_()

