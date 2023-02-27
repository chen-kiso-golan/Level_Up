import React, { useState } from "react";
import { useLocation, useNavigate } from "react-router-dom";
import { UpdateCampaign } from "../../services/CampaignsServices";

export const AllCampaignsReportEdit = () => {
  const navigate = useNavigate();
  const location = useLocation();
  const { Campaign } = location.state;

  const [Code, setCode] = useState(Campaign.Code);
  const [NPO_code, setNPO_code] = useState(Campaign.NPO_code);
  const [Name, setName] = useState(Campaign.Name);
  const [Email, setEmail] = useState(Campaign.Email);
  const [Link_URL, setLink_URL] = useState(Campaign.Link_URL);
  const [Hashtag, setHashtag] = useState(Campaign.Hashtag);
  const [Is_Active, setIs_Active] = useState(Campaign.Is_Active);
  const [Image, setImage] = useState(Campaign.Image);

  const handleSubmit = async (event) => {
    event.preventDefault();
    if (Name === "" || Email === "" || Link_URL === "" || Hashtag === "") {
      alert("Please fill all fields");
    } else {
      const updatedCampaign = {
        ...Campaign,
        Code: parseInt(Code),
        NPO_code: parseInt(NPO_code),
        Name: Name,
        Email: Email,
        Link_URL: Link_URL,
        Hashtag: Hashtag,
        Is_Active: Is_Active,
        Image: Image,
      };
      await UpdateCampaign(updatedCampaign);
      alert("Campaign Was Updated");
      navigate("/AllCampaignsReportPage");
    }
  };

  const handleReturn = () => {
    navigate("/AllCampaignsReportPage");
  };

  return (
    <div className="form-container">
      <form onSubmit={handleSubmit}>
        <div className="form-group">
          <label htmlFor="Code" className="frm-lbl">
            Campaign Code:
          </label>
          <input type="text" className="form-control" id="Code" value={Code} onChange={(event) => setCode(event.target.value)} />
        </div>
        <div className="form-group">
          <label htmlFor="NPO_code" className="frm-lbl">
            NPO code:
          </label>
          <input type="text" className="form-control" id="NPO_code" value={NPO_code} onChange={(event) => setNPO_code(event.target.value)} />
        </div>
        <div className="form-group">
          <label htmlFor="Name" className="frm-lbl">
            Campaign Name:
          </label>
          <input type="text" className="form-control" id="Name" value={Name} onChange={(event) => setName(event.target.value)} />
        </div>
        <div className="form-group">
          <label htmlFor="Email" className="frm-lbl">
            Campaign Email:
          </label>
          <input type="email" className="form-control" id="Email" value={Email} onChange={(event) => setEmail(event.target.value)} />
        </div>
        <div className="form-group">
          <label htmlFor="Link_URL" className="frm-lbl">
            Link:
          </label>
          <input type="text" className="form-control" id="Link_URL" value={Link_URL} onChange={(event) => setLink_URL(event.target.value)} />
        </div>
        <div className="form-group">
          <label htmlFor="Hashtag" className="frm-lbl">
            Hashtag:
          </label>
          <input type="text" className="form-control" id="Hashtag" value={Hashtag} onChange={(event) => setHashtag(event.target.value)} />
        </div>
        <div className="form-group">
          <label htmlFor="Image" className="frm-lbl">
            Image:
          </label>
          <input type="text" className="form-control" id="Image" value={Image} onChange={(event) => setImage(event.target.value)} />
        </div>
        <div className="form-group">
          <input id="Is_Active" type="checkbox" name="Is_Active" onChange={(event) => setIs_Active(event.target.checked)} checked={Is_Active} />
          <label htmlFor="Is_Active" className="frm-lbl">
            Is Active
          </label>
        </div>
        <div>
          <button type="submit" className="btn btn-primary">
            Submit
          </button>
          <button type="submit" className="btn btn-danger" onClick={handleReturn}>
            Return
          </button>
        </div>
      </form>
    </div>
  );
};
