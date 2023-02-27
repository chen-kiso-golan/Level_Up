import React, { useState, useEffect, useContext } from "react";
import { getAllTwitsFromDB } from "../../services/twitterServices";
//import { RoleStatus } from "../../context/roleStatus";
//import { useAuth0 } from "@auth0/auth0-react";

export const TwitsReportRow = (props) => {
  const [AllTwits, setAllTwits] = useState([]);
  const [expand, setExpand] = useState(false);
  const [key, setKey] = useState(null);
  //const { role, setRole } = useContext(RoleStatus);
  //const { user } = useAuth0();

  const getDB = async () => {
    let result = await getAllTwitsFromDB();
    setAllTwits(result.data);
  };

  useEffect(() => {
    getDB();
  }, []);

  const handleClick = (proKey) => {
    setExpand(!expand);
    setKey(proKey);
  };

  return (
    <>
      {AllTwits.length > 0 ? (
        AllTwits.map((tweet) => {
          let { Code, SA_code, Campaign_code, Hashtag, Link_URL, Tweet_Content, Tweet_Time, Tweet_id } = tweet;

          return (
            <>
              <tr onClick={() => handleClick(tweet.Code)}>
                <td scope="row">{SA_code}</td>
                <td>{Campaign_code}</td>
                <td>{Hashtag}</td>
                <td>{Link_URL}</td>
                <td>{Tweet_Time}</td>
                <td>{Tweet_id}</td>
              </tr>

              {expand && tweet.Code === key ? (
                <tr>
                  <td colSpan={6}>
                    <h5>Tweet Content : </h5>
                    {Tweet_Content}
                  </td>
                </tr>
              ) : null}
            </>
          );
        })
      ) : (
        <h1>There are no Twits.</h1>
      )}
    </>
  );
};
