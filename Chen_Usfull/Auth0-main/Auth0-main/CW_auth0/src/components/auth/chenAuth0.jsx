import React from "react";

import LogoutButton from "./logout";
import { Profile } from "./profile";
import "../sidebar/sidebarStyle.css";

const ChenAuth0 = (props) => {
  return (
    <div className="profile--background">
      <LogoutButton></LogoutButton>
      <Profile></Profile>
    </div>
  );
};

export default ChenAuth0;
