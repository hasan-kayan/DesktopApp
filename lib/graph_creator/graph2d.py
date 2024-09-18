import pyqtgraph as pg
from pyqtgraph.Qt import QtWidgets
import numpy as np

class Graph2D:
    def __init__(self, title="2D Graph"):
        self.app = QtWidgets.QApplication([])
        self.win = pg.GraphicsLayoutWidget(show=True, title=title)
        self.win.resize(800, 600)
        self.plot = self.win.addPlot(title=title)
        self.curve = self.plot.plot()

    def set_data(self, x_data, y_data):
        """Sets new data to the graph."""
        self.curve.setData(x_data, y_data)

    def update_graph(self, x_data, y_data):
        """Updates the graph dynamically with new data."""
        self.curve.setData(x_data, y_data)
        QtWidgets.QApplication.processEvents()  # Keep the GUI responsive

    def start(self):
        """Starts the application loop."""
        self.app.exec_()
