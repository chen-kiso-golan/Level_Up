import React, { useContext } from "react";
import { ThemeContext } from "../../context/theme.context";
import "../sidebar/sidebarStyle.css";

function Toggle(props) {
  const { theme, setTheme } = useContext(ThemeContext);

  const getButtonTheme = () => {
    return theme ? "btn btn-light btnTheme" : "btn btn-dark btnTheme";
  };

  const handleTheme = () => {
    setTheme((prev) => !prev);
  };

  return (
    <button type="button" onClick={handleTheme} className={getButtonTheme()}>
      {theme ? "light" : "dark"}
    </button>
  );
}

export default Toggle;
