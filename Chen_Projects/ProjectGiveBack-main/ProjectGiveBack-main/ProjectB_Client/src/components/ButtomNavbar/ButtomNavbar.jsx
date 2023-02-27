import React from "react";

import { Link } from "react-router-dom";
import HomeIcon from "@mui/icons-material/Home";
import CallIcon from "@mui/icons-material/Call";
import FaceIcon from "@mui/icons-material/Face";
import "./ButtomNavbar.css";

function ButtomNavbar(props) {
  return (
    <div className="buttomNavbar--container">
      <ul className="buttomNavbar--menu">
        <li>
          <Link to="/">
            <HomeIcon />
            <label className="label--buttomnavbar">Logo - Home</label>
          </Link>
        </li>
        <li>
          <Link to="/ContactUsPage">
            <CallIcon />
            <label className="label--buttomnavbar">Contact Us</label>
          </Link>
        </li>
        <li>
          <Link to="/AboutPage">
            <FaceIcon />
            <label className="label--buttomnavbar">About</label>
          </Link>
        </li>
      </ul>
    </div>
  );
}

export default ButtomNavbar;
