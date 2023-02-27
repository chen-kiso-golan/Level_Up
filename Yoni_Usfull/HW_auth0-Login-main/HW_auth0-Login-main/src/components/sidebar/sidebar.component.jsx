import React from "react";

import { Link } from "react-router-dom";
import HomeIcon from "@mui/icons-material/Home";
import InfoIcon from "@mui/icons-material/Info";
import CallIcon from "@mui/icons-material/Call";
import MovieCreationIcon from "@mui/icons-material/MovieCreation";
import SmartToyIcon from "@mui/icons-material/SmartToy";
import FaceIcon from "@mui/icons-material/Face";
import "./sidebarStyle.css";

import YoniAuth0 from "../auth/yoniAuth0";

export const Sidebar = (props) => {
  return (
    <div className="container">
      <ul className="menu">
        <li>
          <YoniAuth0></YoniAuth0>
        </li>
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
          <Link to="/contactUs">
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
        <li className="yoni-li">
          <Link to="/notfound">
            <FaceIcon />
            <label>yoni the men</label>
          </Link>
        </li>
      </ul>
    </div>
  );
};
