import React from "react";
import { Link } from "react-router-dom";
import HomeIcon from "@mui/icons-material/Home";
import InfoIcon from "@mui/icons-material/Info";
import CallIcon from "@mui/icons-material/Call";
import MovieCreationIcon from "@mui/icons-material/MovieCreation";
import SmartToyIcon from "@mui/icons-material/SmartToy";
import FaceIcon from "@mui/icons-material/Face";
import "./sidebarStyle.css";

export const Sidebar = (props) => {
  return (
    <div className="container">
      <ul className="menu">
        <li>
          <Link to="/">
            <HomeIcon />
            <label>Home</label>
          </Link>
        </li>
        <li>
          <Link to="/about">
            <InfoIcon />
            <label>About</label>
          </Link>
        </li>
        <li>
          <Link to="/contactus">
            <CallIcon />
            <label>Contact Us</label>
          </Link>
        </li>
        <li>
          <Link to="/movies">
            <MovieCreationIcon />
            <label>Movies</label>
          </Link>
        </li>
        <li>
          <Link to="/games">
            <SmartToyIcon />
            <label>Games</label>
          </Link>
        </li>
        <li className="notfound-li">
          <Link to="/notfound">
            <FaceIcon />
            <label>Hi !</label>
          </Link>
        </li>
      </ul>
    </div>
  );
};
