import React from "react";

import { Link } from "react-router-dom";
import HomeIcon from "@mui/icons-material/Home";
import InfoIcon from "@mui/icons-material/Info";
import CallIcon from "@mui/icons-material/Call";
import FaceIcon from "@mui/icons-material/Face";
import InventoryTwoToneIcon from "@mui/icons-material/InventoryTwoTone";
import "./sidebarStyle.css";

import YoniAuth0 from "../auth/yoniAuth0";
import Toggle from "./../toggle/toggle.component";

export const Sidebar = (props) => {
  return (
    <div className="container">
      <ul className="menu">
        <li>
          <YoniAuth0></YoniAuth0>
          <Toggle />
        </li>
        <li>
          <Link to="/">
            <HomeIcon />
            <label className="label--sidebar">Home</label>
          </Link>
        </li>
        <li>
          <Link to="/about">
            <InfoIcon />
            <label className="label--sidebar">About</label>
          </Link>
        </li>
        <li>
          <Link to="/contactUs">
            <CallIcon />
            <label className="label--sidebar">Contact Us</label>
          </Link>
        </li>
        <li>
          <Link to="/Products">
            <InventoryTwoToneIcon />
            <label className="label--sidebar">All Products</label>
          </Link>
        </li>
        <li className="yoni-li">
          <Link to="/notfound">
            <FaceIcon />
            <label className="label--sidebar">yoni the men</label>
          </Link>
        </li>
      </ul>
    </div>
  );
};
