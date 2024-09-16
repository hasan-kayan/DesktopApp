import React, { useState } from 'react';
import useStore from '../../state/store';

const DataConfigForm = () => {
  const [name, setName] = useState('');
  const [type, setType] = useState('');

  // Access Zustand store
  const addDataPoint = useStore((state) => state.addDataPoint);

  const handleSubmit = (e) => {
    e.preventDefault();
    const dataPoint = {
      id: Date.now(),  // Simple unique ID for demo purposes
      name,
      type,
    };
    addDataPoint(dataPoint);
    setName('');
    setType('');
  };

  return (
    <div>
      <h2>Configure Data</h2>
      <form onSubmit={handleSubmit}>
        <div>
          <label>Name:</label>
          <input 
            type="text" 
            value={name} 
            onChange={(e) => setName(e.target.value)} 
            required 
          />
        </div>
        <div>
          <label>Type:</label>
          <input 
            type="text" 
            value={type} 
            onChange={(e) => setType(e.target.value)} 
            required 
          />
        </div>
        <button type="submit">Add Data Point</button>
      </form>
    </div>
  );
};

export default DataConfigForm;
