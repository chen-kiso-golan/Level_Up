import React from "react";

import { Link } from "react-router-dom";
import HomeIcon from "@mui/icons-material/Home";
import InventoryTwoToneIcon from "@mui/icons-material/InventoryTwoTone";
import "./TopNavbar.css";
import { useAuth0 } from "@auth0/auth0-react";
import LoginButton from "../../Auth0/LoginButton";
import LogoutButton from "./../../Auth0/LogoutButton";

function TopNavbar(props) {
  const { isAuthenticated } = useAuth0();

  return (
    <div className="topnavbar--container">
      <ul className="topnavbar--menu">
        <li>{isAuthenticated ? <LogoutButton /> : <LoginButton />}</li>
        <li>
          <Link to="/">
            <HomeIcon />
            <label className="label--topnavbar">Logo - Home</label>
          </Link>
        </li>
      </ul>
    </div>
  );
}

export default TopNavbar;
