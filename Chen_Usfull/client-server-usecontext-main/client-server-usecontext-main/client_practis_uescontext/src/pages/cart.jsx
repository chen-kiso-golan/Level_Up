import React from "react";
import Cart from "../components/shopsComponents/cartComponent/cart";
import "./PageStyle.css";

export function CartPage(props) {
  return (
    <div className="PageStyle">
      <h1>Cart Page</h1>
      <Cart />
    </div>
  );
}
