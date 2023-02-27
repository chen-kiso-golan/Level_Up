import React, { useState, useEffect, useContext } from "react";

import {
  getAllCampaignsByNPO_code,
  getAllCampaigns,
} from "../../../services/allGetServices";
import { useNavigate } from "react-router-dom";
import { UpdateIs_Active } from "../../../services/allPostServices";
import { UserDataContext } from "./../../../context/userData";
import "../styleOwner.css";
import { RollsStatus } from "./../../../context/rollsStatus";

export const CampaignsTable = () => {
  const { role } = useContext(RollsStatus);
  const { userInfo } = useContext(UserDataContext);
  const [AllCampaigns, setAllCampaigns] = useState([]);
  const [expand, setExpand] = useState(false);
  const [key, setKey] = useState(null);

  const navigate = useNavigate();

  const get_CampaignsByNPO_Code = async () => {
    let result = await getAllCampaignsByNPO_code(userInfo.Code);
    setAllCampaigns(result);
  };

  const get_AllCampaignsDB = async () => {
    let result = await getAllCampaigns();
    setAllCampaigns(result);
  };

  useEffect(() => {
    if (role === "Owner") {
      get_AllCampaignsDB();
    } else {
      get_CampaignsByNPO_Code();
    }
  }, []);

  const handleClick = (proKey) => {
    setExpand(!expand);
    setKey(proKey);
  };

  const handleUpdate = (Campaigns) => {
    navigate("/edit-Campaigns", {
      state: {
        Campaigns,
      },
    });
  };

  const handleCampaignsEnd = async (Campaigns) => {
    setExpand(!expand);
    await UpdateIs_Active(Campaigns);
    getCampaignsDB();
  };

  return (
    <div className="table--all">
      <h1 className="table--title">List of All Campaigns</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">Code</th>
            <th scope="col">Image</th>
            <th scope="col">Name</th>
            <th scope="col">Email</th>
            <th scope="col">Landing_Page_URL</th>
            <th scope="col">HashTag</th>
            <th scope="col">NPO_code</th>
          </tr>
        </thead>
        <tbody>
          {AllCampaigns.length > 0 ? (
            AllCampaigns.map((item) => {
              let {
                Code,
                Name,
                Email,
                Description,
                Landing_Page_URL,
                HashTag,
                NPO_code,
                Image,
              } = item;
              return (
                <>
                  <tr
                    className={`${
                      !item.Is_Active ? "Ended--Campaigns" : "Active--Campaigns"
                    }`}
                    onClick={() => handleClick(item.Code)}
                  >
                    <th scope="row">{Code}</th>
                    <td className="td--image">
                      <img src={Image} alt="" />
                    </td>
                    <td>{Name}</td>
                    <td>{Email}</td>
                    <td>{Landing_Page_URL}</td>
                    <td>{HashTag}</td>
                    <td>{NPO_code}</td>
                  </tr>
                  {expand && item.Code === key ? (
                    <tr
                      className={`${
                        item.Is_Active ? "tr--expand" : "Ended--Campaigns"
                      }`}
                    >
                      <td colSpan={2}>
                        <button
                          className="btn btn-warning"
                          onClick={() => {
                            handleUpdate(item);
                          }}
                        >
                          Edit Campaigns
                        </button>
                      </td>
                      <td colSpan={3}>{`${
                        !item.Is_Active
                          ? "The Campaigns is End"
                          : "Description: " + Description
                      }`}</td>
                      <td colSpan={3}>
                        <button
                          className="btn btn-danger"
                          onClick={() => {
                            handleCampaignsEnd(item);
                          }}
                        >
                          {`${
                            !item.Is_Active
                              ? "Activate Campaigns"
                              : "End Campaigns"
                          }`}
                        </button>
                      </td>
                    </tr>
                  ) : null}
                </>
              );
            })
          ) : (
            <h1>loading</h1>
          )}
        </tbody>
      </table>
    </div>
  );
};
