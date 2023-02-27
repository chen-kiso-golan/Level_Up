import React, { useContext } from "react";
import { ThemeContext } from "../../context/theme.context";
import AccessibilityNewTwoToneIcon from "@mui/icons-material/AccessibilityNewTwoTone";
import "../Navbar/AllNavbar.css";

export const BlindAccessibility = (props) => {
  const { theme, setTheme } = useContext(ThemeContext);

  const getButtonTheme = () => {
    return theme ? "Accessibility frm-lbl" : "CancelAccessibility frm-lbl";
  };

  const handleTheme = () => {
    setTheme((prev) => !prev);
  };

  return (
    <>
      <a className={getButtonTheme()} onClick={handleTheme}>
        <AccessibilityNewTwoToneIcon />
      </a>
      <label onClick={handleTheme} className={getButtonTheme()}>
        {theme ? "Accessibility" : "CancelAccessibility"}
      </label>
    </>
  );
};
