import React, { useContext } from "react";

import { Link } from "react-router-dom";
import InventoryTwoToneIcon from "@mui/icons-material/InventoryTwoTone";
import { Profile } from "./../auth/profile";
import { RollsStatus } from "./../../context/rollsStatus";

export const OwnerSidebar = () => {
  const { role } = useContext(RollsStatus);

  return (
    <div className="OwnerSidebar--container">
      <ul className="OwnerSidebar--menu">
        <li>
          <label className="OwnerSidebar--TitleLbl frm-lbl">{role}</label>
        </li>
        <li>
          <Link to="/campaignsTable">
            <label className="OwnerSidebar--lbl frm-lbl">
              <InventoryTwoToneIcon />
              Campaigns report
            </label>
          </Link>
        </li>
        <li>
          <Link to="/allUsersTable">
            <label className="OwnerSidebar--lbl frm-lbl">
              <InventoryTwoToneIcon />
              Users Info
            </label>
          </Link>
        </li>
        <li>
          <Link to="/twitterInfo">
            <label className="OwnerSidebar--lbl frm-lbl">
              <InventoryTwoToneIcon />
              twits Info
            </label>
          </Link>
        </li>
        <li>
          <Link to="/PendingRegistrationList">
            <label className="OwnerSidebar--lbl frm-lbl">
              <InventoryTwoToneIcon />
              Pending registration confirmation
            </label>
          </Link>
        </li>
        <br />
        <li>
          <Profile />
        </li>
        <br />
      </ul>
    </div>
  );
};
