import React from "react";

import "./styleRegister.css";
import { FormCompany } from "./formCompany";
import { useLocation, useNavigate } from "react-router-dom";
import { FormNPO } from "./formNPO";
import { FormSocialActivist } from "./formSocialActivist";

export const FormsForRegister = () => {
  const navigate = useNavigate();
  const location = useLocation();

  const { Role } = location.state;

  return (
    <div className="form-container">
      {Role === "Company" && <FormCompany />}
      {Role === "NPO" && <FormNPO />}
      {Role === "Social_Activist" && <FormSocialActivist />}
    </div>
  );
};
