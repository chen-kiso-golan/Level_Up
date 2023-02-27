import React, { useState, useEffect } from "react";
import { getAllCompaniesFromDB } from "../../services/BuisnessCompaniesServices";

export const CompaniesReportRow = (props) => {
  const [AllCompanies, setAllCompanies] = useState([]);

  const getDB = async () => {
    let result = await getAllCompaniesFromDB();
    setAllCompanies(result.data);
  };

  useEffect(() => {
    getDB();
  }, []);

  return (
    <>
      {AllCompanies.length > 0 ? (
        AllCompanies.map((Company) => {
          let { Name, Email, Image } = Company;
          return (
            <>
              <tr>
                <td>{Name}</td>
                <td>{Email}</td>
                <td>
                  <img style={{ width: "70px", borderRadius: "50%" }} src={Image} alt="" />
                </td>
              </tr>
            </>
          );
        })
      ) : (
        <h1>There are no Companies.</h1>
      )}
    </>
  );
};
