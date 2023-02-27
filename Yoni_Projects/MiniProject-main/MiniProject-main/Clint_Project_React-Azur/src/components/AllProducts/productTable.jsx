import React from "react";
import "./productsStyle.css";
import { ProductRow } from "./productRow";

export const ProductTable = (props) => {
  return (
    <div className="table--all">
      <h1 className="table--title">List of All Products</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">ProductID</th>
            <th scope="col">ProductName</th>
            <th scope="col">UnitPrice</th>
            <th scope="col">UnitsInStock</th>
          </tr>
        </thead>
        <tbody>
          <ProductRow />
        </tbody>
      </table>
    </div>
  );
};
