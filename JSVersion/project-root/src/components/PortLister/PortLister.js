import React, { useEffect, useState } from 'react';

const PortLister = () => {
  const [ports, setPorts] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    // Fetch ports using the Electron IPC API
    const fetchPorts = async () => {
      try {
        const portList = await window.electronAPI.getPorts();
        if (portList.error) {
          console.error('Error fetching ports:', portList.error);
        } else {
          setPorts(portList);
        }
      } catch (error) {
        console.error('Error:', error);
      } finally {
        setLoading(false);
      }
    };

    fetchPorts();
  }, []);

  if (loading) {
    return <div>Loading ports...</div>;
  }

  return (
    <div>
      <h2>Available Ports</h2>
      {ports.length === 0 ? (
        <p>No devices connected</p>
      ) : (
        <ul>
          {ports.map((port) => (
            <li key={port.path}>
              <strong>Port:</strong> {port.path} <br />
              <strong>Manufacturer:</strong> {port.manufacturer || 'Unknown'} <br />
              <strong>Product ID:</strong> {port.productId || 'N/A'} <br />
              <strong>Vendor ID:</strong> {port.vendorId || 'N/A'}
            </li>
          ))}
        </ul>
      )}
    </div>
  );
};

export default PortLister;
