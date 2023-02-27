import React from "react";
import { Link } from "react-router-dom";
import LogoutButton from "../auth0/logoutBtn/logout";
import ThemeBtn from "./themeBtn";
import "./navbar.css";

function Navbar() {
  return (
    <div className="navbar--container">
      <ul className="navbar--list">
        <div className="navbar--btns">
          <li>
            <label className="navbar--logo">MY SHOP!</label>
          </li>
          <li className="navbar--btns--logout">
            <LogoutButton />
          </li>
          <li className="navbar--btns--theme">
            <ThemeBtn />
          </li>
        </div>
        <li>
          <Link to={"/"}>
            <label>Home</label>
          </Link>
        </li>
        <li>
          <Link to={"/about"}>
            <label>About</label>
          </Link>
        </li>
        <li>
          <Link to={"/shoes"}>
            <label>Shoes</label>
          </Link>
        </li>
        <li>
          <Link to={"/tshirt"}>
            <label>Tshirt</label>
          </Link>
        </li>
        <li>
          <Link to={"/cart"}>
            <label>Cart</label>
          </Link>
        </li>
      </ul>
    </div>
  );
}

export default Navbar;
