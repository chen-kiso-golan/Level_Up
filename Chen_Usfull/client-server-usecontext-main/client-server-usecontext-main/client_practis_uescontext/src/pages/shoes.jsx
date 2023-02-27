import React from "react";
import Shoes from "../components/shopsComponents/shoesComponent/shoes";
import "./PageStyle.css";

export function ShoesPage(props) {
  return (
    <div className="PageStyle">
      <h1>shoes</h1>

      <Shoes />
    </div>
  );
}
