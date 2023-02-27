import React, { useState, useContext } from "react";
import { themeContext } from "../contextComponent/themeContext";

function ThemeBtn(props) {
  const { theme, setTheme } = useContext(themeContext);

  const getButtonTheme = () => {
    return theme ? "btn btn-light" : "btn btn-dark";
  };

  const handleTheme = () => {
    setTheme((prev) => !prev);
  };

  return (
    <button type="button" onClick={handleTheme} className={getButtonTheme()}>
      {theme ? "Light" : "Dark"}
    </button>
  );
}

export default ThemeBtn;
