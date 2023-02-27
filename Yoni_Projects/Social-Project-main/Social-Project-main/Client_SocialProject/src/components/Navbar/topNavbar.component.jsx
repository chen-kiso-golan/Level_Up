import React from "react";

import { Link } from "react-router-dom";
import CallIcon from "@mui/icons-material/Call";

import { useAuth0 } from "@auth0/auth0-react";
import { BlindAccessibility } from "./../AccessibilityBtn/BlindAccessibilityBtn";
import Logo_yoni_website from "../../image/Logo_yoni_website.png";
import { LogoutButton } from "../auth/logout";
import { LoginButton } from "../auth/login";
import "./AllNavbar.css";

export const TopNavbar = () => {
  const { isAuthenticated } = useAuth0();
  return (
    <div className="TopNavbar--container">
      <ul className="TopNavbar--menu">
        <li>
          <Link to="/">
            <img src={Logo_yoni_website} alt="" />
          </Link>
        </li>
        <li>
          <BlindAccessibility />
        </li>
        <li>
          <Link to="/contactUs">
            <CallIcon />
            <label className="frm-lbl">Contact Us</label>
          </Link>
        </li>
        <li>{isAuthenticated ? <LogoutButton /> : <LoginButton />}</li>
      </ul>
    </div>
  );
};
