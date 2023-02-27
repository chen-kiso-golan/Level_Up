import React from "react";

import { Link } from "react-router-dom";
import HomeIcon from "@mui/icons-material/Home";
import PersonAddIcon from "@mui/icons-material/PersonAdd";
import "./styleNavbar.css";

export const Navbar = (props) => {
  return (
    <div>
      <nav className="navbar bg-light">
        <div className="container">
          <ul>
            <Link to="/">
              <li className="navbar-brand">
                <HomeIcon />
                Home
              </li>
            </Link>
            <Link to="/AddStudent">
              <li className="navbar-brand">
                <PersonAddIcon />
                Add Student
              </li>
            </Link>
          </ul>
        </div>
      </nav>
    </div>
  );
};
