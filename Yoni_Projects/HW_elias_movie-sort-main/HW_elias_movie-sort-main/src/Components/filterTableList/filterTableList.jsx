import React from "react";
import "./filterTableList.css";

export const FilterTableList = ({ handleFilter, filter }) => {
  const handleClicked = (clicked) => {
    if (clicked === filter) {
      return "list-group-item active";
    } else {
      return "list-group-item";
    }
  };
  return (
    <div className="filterTableList">
      <ul className="list-group">
        <li className={handleClicked("All")}>
          <button
            onClick={() => {
              handleFilter("All");
            }}
          >
            All
          </button>
        </li>
        <li className={handleClicked("Action")}>
          <button
            onClick={() => {
              handleFilter("Action");
            }}
          >
            Action
          </button>
        </li>
        <li className={handleClicked("Drama")}>
          <button
            onClick={() => {
              handleFilter("Drama");
            }}
          >
            Drama
          </button>
        </li>
      </ul>
    </div>
  );
};
