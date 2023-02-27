import React from "react";
import Tshirts from "../components/shopsComponents/TshirtComponent/Tshirt";
import "./PageStyle.css";

export function TshirtPage(props) {
  return (
    <div className="PageStyle">
      <h1>Tshirts Page</h1>
      <Tshirts />
    </div>
  );
}
