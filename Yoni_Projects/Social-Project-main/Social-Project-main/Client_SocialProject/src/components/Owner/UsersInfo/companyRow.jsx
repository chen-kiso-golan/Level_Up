import React, { useState, useEffect } from "react";
import { getAllCompany_Rows } from "./../../../services/allGetServices";
import "../styleOwner.css";

export const CompanyRow = () => {
  const [AllCompanyRows, setAllCompanyRows] = useState([]);

  const getCompany_DB = async () => {
    let result = await getAllCompany_Rows();
    setAllCompanyRows(result);
  };

  useEffect(() => {
    getCompany_DB();
  }, []);

  return (
    <>
      {AllCompanyRows.length > 0 ? (
        AllCompanyRows.map((item) => {
          let { Name, Email, Image, Register_Time } = item;
          return (
            <tr>
              <td>{Name}</td>
              <td>{Email}</td>
              <td className="td--img">
                <img src={Image} alt="" />
              </td>
              <td>{Register_Time}</td>
            </tr>
          );
        })
      ) : (
        <h4>There are no Company</h4>
      )}
    </>
  );
};
