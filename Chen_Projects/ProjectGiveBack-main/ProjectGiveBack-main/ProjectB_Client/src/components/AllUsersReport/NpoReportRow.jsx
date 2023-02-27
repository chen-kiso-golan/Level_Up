import React, { useState, useEffect } from "react";
import { getAllNpoFromDB } from "../../services/NonProfitOrganizationServices";

export const NpoReportRow = (props) => {
  const [AllNpo, setAllNpo] = useState([]);

  const getDB = async () => {
    let result = await getAllNpoFromDB();
    setAllNpo(result.data);
  };

  useEffect(() => {
    getDB();
  }, []);

  return (
    <>
      {AllNpo.length > 0 ? (
        AllNpo.map((Npo) => {
          let { Name, Email, Website_URL, Image } = Npo;
          return (
            <>
              <tr>
                <td>{Name}</td>
                <td>{Email}</td>
                <td>{Website_URL}</td>
                <td>
                  <img style={{ width: "70px", borderRadius: "50%" }} src={Image} alt="" />
                </td>
              </tr>
            </>
          );
        })
      ) : (
        <h1>There are no Npo.</h1>
      )}
    </>
  );
};
