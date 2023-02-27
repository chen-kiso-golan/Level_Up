import React, { useState } from "react";

import "../styleOwner.css";

import { SocialActivistRow } from "./socialActivistRow";
import { CompanyRow } from "./companyRow";
import { NPORow } from "./npoRow";

export const AllUsersTable = () => {
  const [filter, setFilter] = useState("all");

  const handleFilterChange = (event) => {
    setFilter(event.target.value);
  };

  return (
    <>
      <div className="filter-container">
        <br />
        <label className="frm-lbl">
          <b>Filter by:</b>
        </label>
        <select value={filter} onChange={handleFilterChange}>
          <option value="all">All</option>
          <option value="socialActivist">Social Activist</option>
          <option value="npo">Non Profit Organization</option>
          <option value="company">Company</option>
        </select>
      </div>
      {filter === "all" || filter === "socialActivist" ? (
        <div className="table--all">
          <h2 className="table--title">List of All Social Activist</h2>
          <br />
          <table className="table">
            <thead>
              <tr>
                <th scope="col">FirstName</th>
                <th scope="col">LastName</th>
                <th scope="col">Email</th>
                <th scope="col">Address</th>
                <th scope="col">Phone Number</th>
                <th scope="col">Money Status</th>
                <th scope="col">Image URL</th>
                <th scope="col">Register Time</th>
              </tr>
            </thead>
            <tbody>
              <SocialActivistRow />
            </tbody>
          </table>
        </div>
      ) : null}
      {filter === "all" || filter === "npo" ? (
        <div className="table--all">
          <h2 className="table--title">List of All Non Profit Organization</h2>
          <br />
          <table className="table">
            <thead>
              <tr>
                <th scope="col">Name</th>
                <th scope="col">Email</th>
                <th scope="col">Website URL</th>
                <th scope="col">Image URL</th>
                <th scope="col">Register Time</th>
              </tr>
            </thead>
            <tbody>
              <NPORow />
            </tbody>
          </table>
        </div>
      ) : null}
      {filter === "all" || filter === "company" ? (
        <div className="table--all">
          <h2 className="table--title">List of All Company</h2>
          <br />
          <table className="table">
            <thead>
              <tr>
                <th scope="col">Name</th>
                <th scope="col">Email</th>
                <th scope="col">Image URL</th>
                <th scope="col">Register Time</th>
              </tr>
            </thead>
            <tbody>
              <CompanyRow />
            </tbody>
          </table>
        </div>
      ) : null}
    </>
  );
};
