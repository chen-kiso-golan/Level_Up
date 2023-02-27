import React, { useState, useEffect, useContext } from "react";
import { deleteCampaign, getAllCampaignsFromDB } from "../../services/CampaignsServices";
import { useNavigate } from "react-router-dom";
import { RoleStatus } from "../../context/roleStatus";
import { useAuth0 } from "@auth0/auth0-react";

export const CampaignsReportRow = (props) => {
  const [AllCampaigns, setAllCampaigns] = useState([]);
  const [expand, setExpand] = useState(false);
  const [key, setKey] = useState(null);
  const { role, setRole } = useContext(RoleStatus);
  const { user } = useAuth0();

  const navigate = useNavigate();

  const getDB = async () => {
    let result = await getAllCampaignsFromDB();
    setAllCampaigns(result.data);
  };

  useEffect(() => {
    getDB();
  }, []);

  const handleClick = (proKey) => {
    setExpand(!expand);
    setKey(proKey);
  };

  const handleEdit = (Campaign) => {
    navigate("/AllCampaignsReportPageEdit", {
      state: {
        Campaign,
      },
    });
  };

  const handleDelete = async (Code) => {
    console.log(Code);
    await deleteCampaign(Code);
    setExpand(!expand);
    getDB();
  };

  return (
    <>
      {AllCampaigns.length > 0 ? (
        AllCampaigns.map((Campaign) => {
          let { Code, Name, Email, Link_URL, Hashtag, NPO_code, Image, Is_Active } = Campaign;
          return (
            <>
              <tr className={Campaign.Email === user.email ? "table-danger" : ""} onClick={() => handleClick(Campaign.Code)}>
                <th scope="row">{Code}</th>
                <td>{Name}</td>
                <td>{Email}</td>
                <td>{Link_URL}</td>
                <td>{Hashtag}</td>
                <td>{NPO_code}</td>
                <td>
                  <img style={{ width: "50px", height: "50px", borderRadius: "50%" }} src={Image} alt="" />
                </td>
                <td>{Is_Active ? "true" : "false"}</td>
              </tr>

              {role === "NPO" && Campaign.Email === user.email && expand && Campaign.Code === key ? (
                <tr>
                  <td>
                    <button
                      className="btn btn-warning"
                      onClick={() => {
                        handleEdit(Campaign);
                      }}
                    >
                      Edit Campaign
                    </button>
                  </td>
                  <td colSpan={2}>
                    <h5>{Campaign.Name} Description : </h5>
                    blablabla...
                  </td>
                  <td>
                    <button
                      className="btn btn-danger"
                      onClick={() => {
                        handleDelete(Campaign.Code);
                      }}
                    >
                      Remove Campaign
                    </button>
                  </td>
                </tr>
              ) : null}
            </>
          );
        })
      ) : (
        <h1>There are no campaigns.</h1>
      )}
    </>
  );
};
