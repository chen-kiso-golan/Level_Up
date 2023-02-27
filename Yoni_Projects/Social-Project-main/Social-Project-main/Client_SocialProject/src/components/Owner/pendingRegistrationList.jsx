import React, { useState, useEffect } from "react";

import "./styleOwner.css";

import { getPendingList } from "../../services/allGetServices";
import { UpdateIs_Approved } from "./../../services/allPostServices";

export const PendingRegistrationList = () => {
  const [AllUsers, setAllUsers] = useState([]);

  const getDB = async () => {
    let result = await getPendingList();
    setAllUsers(result);
  };

  useEffect(() => {
    getDB();
  }, []);

  const handleApproved = async (item) => {
    await UpdateIs_Approved(item);
    getDB();
  };

  return (
    <div className="table--all">
      <h1 className="table--title">List of All Pending Registration Request</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">Name</th>
            <th scope="col">Email</th>
            <th scope="col">Role Request</th>
            <th scope="col">Is Approved</th>
          </tr>
        </thead>
        <tbody>
          {AllUsers.length > 0 ? (
            AllUsers.map((item) => {
              let { Name, Email, Role_Request } = item;
              return (
                <tr>
                  <td>{Name}</td>
                  <td>{Email}</td>
                  <td>{Role_Request}</td>
                  <td>
                    <button
                      onClick={() => handleApproved(item)}
                      className="btn btn-success"
                    >
                      Approved
                    </button>
                  </td>
                </tr>
              );
            })
          ) : (
            <h4>There are no more registration requests</h4>
          )}
        </tbody>
      </table>
    </div>
  );
};
