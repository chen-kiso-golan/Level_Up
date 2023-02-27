import React, { useState, useEffect } from "react";
import { getAllCampaignNamesFromDB } from "../../services/CampaignsServices";

export function ChooseCampaignRow({ chooseCampaign }) {
  const [AllCampaigns, setAllCampaigns] = useState([]);

  const getDB = async () => {
    let result = await getAllCampaignNamesFromDB();
    setAllCampaigns(result.data);
  };

  useEffect(() => {
    getDB();
  }, []);

  return (
    <>
      <label htmlFor="Campaign" className="frm-lbl">
        Campaign
      </label>
      <select name="Campaign" className="form-select" aria-label="Default select example" onChange={(event) => chooseCampaign(event.target.value)}>
        <option defaultValue={"Choose The Name Of The Campaign"}>Choose The Name Of The Campaign</option>
        {AllCampaigns.length > 0 ? (
          AllCampaigns.map((Campaign) => {
            return (
              <>
                <option value={Campaign.Name}>{Campaign.Name}</option>
              </>
            );
          })
        ) : (
          <option value="1">There are no Campaigns.</option>
        )}
      </select>
    </>
  );
}
