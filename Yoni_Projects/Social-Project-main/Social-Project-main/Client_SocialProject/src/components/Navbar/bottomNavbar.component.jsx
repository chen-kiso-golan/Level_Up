import React from "react";

import { Link } from "react-router-dom";
import InfoIcon from "@mui/icons-material/Info";
import Logo_yoni_website from "../../image/Logo_yoni_website.png";
import "./AllNavbar.css";

export const BottomNavbar = () => {
  return (
    <div className="BottomNavbar--container">
      <ul className="BottomNavbar--menu">
        <li>
          <Link to="/about">
            <InfoIcon />
            <label className="label--BottomNavbar">About</label>
          </Link>
        </li>
        <li>
          <Link to="/">
            <img src={Logo_yoni_website} alt="" />
          </Link>
        </li>
      </ul>
    </div>
  );
};
