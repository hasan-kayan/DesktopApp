import React from 'react';
import { Link } from 'react-router-dom';

function Navbar() {
  return (
    <nav>
      <ul>
        <li>
          <Link to="/">Home</Link>
        </li>
        <li>
          <Link to="/configure">Configure Data</Link>
        </li>
        <li>
          <Link to="/manage-graphs">Manage Graphs</Link>
        </li>
      </ul>
    </nav>
  );
}

export default Navbar;
