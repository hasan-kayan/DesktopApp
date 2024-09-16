import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Home from './pages/Home';
import ConfigureData from './pages/ConfigureData';
import ManageGraphs from './pages/ManageGraphs';
import Navbar from './components/Navbar';

function App() {
  return (
    <Router>
      <Navbar />
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/configure" element={<ConfigureData />} />
        <Route path="/manage-graphs" element={<ManageGraphs />} />
      </Routes>
    </Router>
  );
}

export default App;
