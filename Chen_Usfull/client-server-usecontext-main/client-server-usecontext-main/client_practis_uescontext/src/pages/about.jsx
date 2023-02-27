import React from "react";
import Profile from "../components/auth0/profileInfo/profile";
import "./PageStyle.css";

export function AboutPage() {
  return (
    <div className="PageStyle">
      <h1>
        <Profile />
      </h1>
    </div>
  );
}
