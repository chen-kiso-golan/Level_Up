import React from "react";
import "./AllCampaignsReportStyle.css";
import { CampaignsReportRow } from "./CampaignsReportRow";

export function AllCampaignsReport(props) {
  return (
    <>
      <h1>All Campaigns Report:</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">ID</th>
            <th scope="col">Name</th>
            <th scope="col">Email</th>
            <th scope="col">Link</th>
            <th scope="col">Hashtag</th>
            <th scope="col">NPO Code</th>
            <th scope="col">Image URL</th>
            <th scope="col">is Active</th>
          </tr>
        </thead>
        <tbody className="table-group-divider">
          <CampaignsReportRow />
        </tbody>
      </table>
    </>
  );
}
