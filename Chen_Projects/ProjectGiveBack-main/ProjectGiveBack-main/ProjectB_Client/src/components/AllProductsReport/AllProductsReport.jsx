import React from "react";
import "./AllProductsReportStyle.css";
import { ProductsReportRow } from "./ProductsReportRow";

export function AllProductsReport(props) {
  return (
    <>
      <h1>All Products Report:</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">Code</th>
            <th scope="col">Name</th>
            <th scope="col">Price</th>
            <th scope="col">Units_In_Stock</th>
            <th scope="col">BC_code</th>
            <th scope="col">Campaign_code</th>
            <th scope="col">Image</th>
            <td></td>
          </tr>
        </thead>
        <tbody className="table-group-divider">
          <ProductsReportRow />
        </tbody>
      </table>
    </>
  );
}
