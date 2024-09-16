import create from 'zustand';

// Zustand store for managing data and graphs
const useStore = create((set) => ({
  dataPoints: [], // Holds the list of configured data points
  graphs: [],     // Holds the list of graphs created

  // Add a new data point
  addDataPoint: (dataPoint) => set((state) => ({
    dataPoints: [...state.dataPoints, dataPoint]
  })),

  // Remove a data point
  removeDataPoint: (id) => set((state) => ({
    dataPoints: state.dataPoints.filter((point) => point.id !== id)
  })),

  // Add a new graph
  addGraph: (graph) => set((state) => ({
    graphs: [...state.graphs, graph]
  })),

  // Remove a graph
  removeGraph: (id) => set((state) => ({
    graphs: state.graphs.filter((graph) => graph.id !== id)
  })),
}));

export default useStore;
