import React, { useState, useEffect } from "react";
import { getAllTwitted } from "../../services/allGetServices";

import "./styleOwner.css";

export const TwitterInfo = () => {
  const [AllTwitted, setAllTwitted] = useState([]);

  const getTwittedFormDB = async () => {
    let result = await getAllTwitted();
    setAllTwitted(result);
  };

  useEffect(() => {
    getTwittedFormDB();
  }, []);

  return (
    <div className="table--all">
      <h1 className="table--title">List of All Twitter Info</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">SA code</th>
            <th scope="col">Campaign code</th>
            <th scope="col">HashTag</th>
            <th scope="col">Landing Page URL</th>
            <th scope="col">Tweet Content</th>
          </tr>
        </thead>
        <tbody>
          {AllTwitted.length > 0 ? (
            AllTwitted.map((item) => {
              let {
                SA_code,
                Campaign_code,
                HashTag,
                Landing_Page_URL,
                Tweet_Content,
              } = item;
              return (
                <tr>
                  <td>{SA_code}</td>
                  <td>{Campaign_code}</td>
                  <td>{HashTag}</td>
                  <td>{Landing_Page_URL}</td>
                  <td>{Tweet_Content}</td>
                </tr>
              );
            })
          ) : (
            <h4>Loading...</h4>
          )}
        </tbody>
      </table>
    </div>
  );
};
