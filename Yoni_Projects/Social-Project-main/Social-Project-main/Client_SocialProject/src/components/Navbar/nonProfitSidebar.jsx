import React, { useContext } from "react";
import { Link } from "react-router-dom";
import InventoryTwoToneIcon from "@mui/icons-material/InventoryTwoTone";
import AddTwoToneIcon from "@mui/icons-material/AddTwoTone";
import { Profile } from "./../auth/profile";
import { RollsStatus } from "./../../context/rollsStatus";

export const NonProfitSidebar = () => {
  const { role } = useContext(RollsStatus);

  return (
    <div className="NonProfitSidebar--container">
      <ul className="NonProfitSidebar--menu">
        <li>
          <label className="NonProfitSidebar--TitleLbl frm-lbl">{role}</label>
        </li>
        <li>
          <Link to="/edit-Campaigns">
            <label className="NonProfitSidebar--lbl frm-lbl">
              <AddTwoToneIcon />
              Creating a campaign
            </label>
          </Link>
        </li>
        <li>
          <Link to="/campaignsTableNPO">
            <label className="NonProfitSidebar--lbl frm-lbl">
              <InventoryTwoToneIcon />
              Campaigns report
            </label>
          </Link>
        </li>
        <li>
          <Link to="/campaignsCardNPO">
            <label className="NonProfitSidebar--lbl frm-lbl">
              <InventoryTwoToneIcon />
              My Campaigns
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
