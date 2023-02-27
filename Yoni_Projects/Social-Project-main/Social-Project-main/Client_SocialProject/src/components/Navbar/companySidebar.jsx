import React, { useContext } from "react";
import { Link } from "react-router-dom";
import InventoryTwoToneIcon from "@mui/icons-material/InventoryTwoTone";
import AddTwoToneIcon from "@mui/icons-material/AddTwoTone";
import { Profile } from "./../auth/profile";
import { RollsStatus } from "./../../context/rollsStatus";

export const CompanySidebar = () => {
  const { role } = useContext(RollsStatus);
  return (
    <div className="CompanySidebar--container">
      <ul className="CompanySidebar--menu">
        <li>
          <label className="CompanySidebar--TitleLbl frm-lbl">{role}</label>
        </li>
        <br />
        <li>
          <Link to="/campaignsCardNPO">
            <label className="CompanySidebar--lbl frm-lbl">
              <AddTwoToneIcon />
              Creating a product
            </label>
          </Link>
        </li>
        <li>
          <Link to="/productTable">
            <label className="CompanySidebar--lbl frm-lbl">
              <AddTwoToneIcon />
              My product
            </label>
          </Link>
        </li>
        <li>
          <Link to="/orderTable">
            <label className="CompanySidebar--lbl frm-lbl">
              <InventoryTwoToneIcon />
              Order Report
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
