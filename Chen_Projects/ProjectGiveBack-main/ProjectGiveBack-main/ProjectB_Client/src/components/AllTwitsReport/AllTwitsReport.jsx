import React from "react";
import "./AllTwitsReportStyle.css";
import { TwitsReportRow } from "./TwitsReportRow";

export function AllTwitsReport(props) {
  return (
    <table className="table">
      <thead>
        <tr>
          <th scope="col">SA_code</th>
          <th scope="col">Campaign_code</th>
          <th scope="col">Hashtag</th>
          <th scope="col">Link_URL</th>
          <th scope="col">Tweet_Time</th>
          <th scope="col">Tweet_id</th>
        </tr>
      </thead>
      <tbody className="table-group-divider">
        <TwitsReportRow />
      </tbody>
    </table>
  );
}
