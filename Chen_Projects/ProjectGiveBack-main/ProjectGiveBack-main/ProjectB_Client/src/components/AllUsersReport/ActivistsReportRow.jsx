import React, { useState, useEffect } from "react";
import { getAllActivistsFromDB } from "../../services/SocialActivistServices";

export const ActivistsReportRow = (props) => {
  const [AllActivists, setAllActivists] = useState([]);

  const getDB = async () => {
    let result = await getAllActivistsFromDB();
    setAllActivists(result.data);
  };

  useEffect(() => {
    getDB();
  }, []);

  return (
    <>
      {AllActivists.length > 0 ? (
        AllActivists.map((Activist) => {
          let { Name, Email, Address, PhoneNumber, Money, Image } = Activist;
          return (
            <>
              <tr>
                <td>{Name}</td>
                <td>{Email}</td>
                <td>{Address}</td>
                <td>{PhoneNumber}</td>
                <td>{Money}</td>
                <td>
                  <img style={{ width: "50px", borderRadius: "50%" }} src={Image} alt="" />
                </td>
              </tr>
            </>
          );
        })
      ) : (
        <h1>There are no Activists.</h1>
      )}
    </>
  );
};
