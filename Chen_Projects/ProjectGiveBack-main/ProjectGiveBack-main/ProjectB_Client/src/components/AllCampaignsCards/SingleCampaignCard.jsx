import React, { useContext } from "react";
import "./AllCampaignsCardsStyle.css";
import { useState, useEffect } from "react";
import { getAllCampaignsFromDB } from "../../services/CampaignsServices";
import { TwitterShareButton } from "react-twitter-embed";
import { RoleStatus } from "./../../context/roleStatus";

export const SingleCampaignCard = (props) => {
  const { role } = useContext(RoleStatus);
  const [AllCampaigns, setAllCampaigns] = useState([]);

  const getDB = async () => {
    let result = await getAllCampaignsFromDB();
    setAllCampaigns(result.data);
  };

  useEffect(() => {
    getDB();
  }, [role]);

  return (
    <>
      {AllCampaigns.length > 0 ? (
        AllCampaigns.map((Campaign) => {
          let { Code, Name, Email, Link_URL, Hashtag, NPO_code, Image, Is_Active } = Campaign;
          return (
            <>
              <div>
                <div className="card">
                  <img className="card-img-top" src={Image} alt="Card image cap" />
                  <div className="card-body">
                    <h5 className="card-title">{Name}</h5>
                    <p className="card-text">{Email}</p>
                    <p className="card-text">{Link_URL}</p>

                    <a className="twitter-share-button" href="https://twitter.com/intent/tweet">
                      Tweet about us!
                    </a>

                    {/* {role === "SA" && (
                      <div className="card--button">
                        <TwitterShareButton
                          url={Campaign.Link_URL}
                          options={{
                            text: "#ProjectGiveBack " + Hashtag + " Campaign for " + Name,
                          }}
                        />
                      </div>
                    )} */}
                  </div>
                  <div className="card-footer">
                    <small className="text-muted">{Hashtag}</small>
                  </div>
                </div>
              </div>
            </>
          );
        })
      ) : (
        <h1>There are no campaigns.</h1>
      )}
    </>
  );
};
