import React, { useContext } from "react";
import { Link } from "react-router-dom";
import InventoryTwoToneIcon from "@mui/icons-material/InventoryTwoTone";
import { Profile } from "./../auth/profile";
import { RollsStatus } from "./../../context/rollsStatus";
import { UserDataContext } from "./../../context/userData";

export const ActivistSidebar = () => {
  const { userInfo } = useContext(UserDataContext);
  const { role } = useContext(RollsStatus);

  return (
    <div className="ActivistSidebar--container">
      <ul className="ActivistSidebar--menu">
        <li>
          <label className="ActivistSidebar--TitleLbl frm-lbl">{role}</label>
        </li>
        <br />
        <li>
          <label className="ActivistSidebar--lbl frm-lbl">
            Money Balance:{userInfo.Money_Status}$
          </label>
        </li>
        <li>
          <Link to="/campaignsCardNPO">
            <label className="ActivistSidebar--lbl frm-lbl">
              <InventoryTwoToneIcon />
              Donate for campaign
            </label>
          </Link>
        </li>
        <li>
          <Link to="/myProductTable">
            <label className="ActivistSidebar--lbl frm-lbl">
              <InventoryTwoToneIcon />
              products I donated
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
