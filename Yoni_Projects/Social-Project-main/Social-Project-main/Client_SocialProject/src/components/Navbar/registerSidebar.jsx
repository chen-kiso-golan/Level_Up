import React, { useState } from "react";
import { useNavigate } from "react-router-dom";
import InventoryTwoToneIcon from "@mui/icons-material/InventoryTwoTone";
import { Profile } from "./../auth/profile";

export const RegisterSidebar = () => {
  const [buttonVisible, setButtonVisible] = useState(true);
  const navigate = useNavigate();

  const handelNavigate = () => {
    navigate("/register");
    setButtonVisible(false);
  };

  return (
    <div className="RegisterSidebar--container">
      <ul className="RegisterSidebar--menu">
        <li>
          <label className="RegisterSidebar--TitleLbl frm-lbl">
            chose your role
          </label>
        </li>
        <br />
        <li>
          <label className="RegisterSidebar--lbl frm-lbl">
            <InventoryTwoToneIcon />
            Please register on the site first in order to perform actions as our
            user
          </label>
        </li>
        {buttonVisible && (
          <li>
            <label className="RegisterSidebar--lbl frm-lbl">
              <button onClick={handelNavigate} className="btn btn-success">
                Click here
              </button>
            </label>
          </li>
        )}
        <br />
        <br />
        <li>
          <Profile />
        </li>
        <br />
      </ul>
    </div>
  );
};
