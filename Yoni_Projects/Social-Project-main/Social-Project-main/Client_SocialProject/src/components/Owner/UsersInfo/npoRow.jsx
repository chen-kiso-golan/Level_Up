import React, { useState, useEffect } from "react";
import { getAllNPO_Rows } from "../../../services/allGetServices";
import "../styleOwner.css";

export const NPORow = () => {
  const [AllNPORows, setAllNPORows] = useState([]);

  const getNPO_DB = async () => {
    let result = await getAllNPO_Rows();
    setAllNPORows(result);
  };

  useEffect(() => {
    getNPO_DB();
  }, []);

  return (
    <>
      {AllNPORows.length > 0 ? (
        AllNPORows.map((item) => {
          let { Name, Email, Website_URL, Image, Register_Time } = item;
          return (
            <tr>
              <td>{Name}</td>
              <td>{Email}</td>
              <td>{Website_URL}</td>
              <td className="td--img">
                <img src={Image} alt="" />
              </td>
              <td>{Register_Time}</td>
            </tr>
          );
        })
      ) : (
        <h4>There are no Non Profit Organization</h4>
      )}
    </>
  );
};
