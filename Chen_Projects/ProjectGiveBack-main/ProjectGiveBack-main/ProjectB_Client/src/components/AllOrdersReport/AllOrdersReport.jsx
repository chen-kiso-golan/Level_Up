import React from "react";
import "./AllOrdersReportStyle.css";
import { OrdersReportRow } from "./OrdersReportRow";

export function AllOrdersReport(props) {
  return (
    <>
      <h1>All Orders Report:</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">Code</th>
            <th scope="col">SA_code</th>
            <th scope="col">BC_code</th>
            <th scope="col">Campaign_code</th>
            <th scope="col">Product_code</th>
            <th scope="col">Order_Time</th>
            <th scope="col">Is_Sent</th>
          </tr>
        </thead>
        <tbody className="table-group-divider">
          <OrdersReportRow />
        </tbody>
      </table>
    </>
  );
}
