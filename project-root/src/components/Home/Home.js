import React from 'react';
import ReactDOM from 'react-dom';
import './Home.css';

const Home = () => {
  return (
    <div>
      <h1>Welcome to the Electron React App</h1>
    </div>
  );
};

ReactDOM.render(<Home />, document.getElementById('root'));
