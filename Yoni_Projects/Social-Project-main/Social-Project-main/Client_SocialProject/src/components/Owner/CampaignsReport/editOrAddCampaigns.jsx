import React, { useState, useContext, useEffect } from "react";
import { ToastContainer, toast } from "react-toastify";
import { AddOrEditForm } from "../../../services/allPostServices";

import { UserDataContext } from "./../../../context/userData";
import "../styleOwner.css";
import { useLocation, useNavigate } from "react-router-dom";

export const EditCampaigns = (props) => {
  const { userInfo } = useContext(UserDataContext);
  const [ActionType, setActionType] = useState("Add");
  const [formCampaignsData, setFormCampaignsData] = useState({
    Name: "",
    Email: "",
    Description: "",
    Landing_Page_URL: "",
    HashTag: "",
    NPO_code: userInfo.Code,
    Image: "",
  });

  const notify_success = () =>
    toast.success("🦄 we get your message!", {
      position: "top-left",
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: "light",
    });

  const notify_error = () =>
    toast.error("error: Make sure to fill in all the fields", {
      position: "top-left",
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: "dark",
    });

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormCampaignsData((prevFormData) => ({
      ...prevFormData,
      [name]: value,
    }));
  };

  const handleAddData = async () => {
    let json = formCampaignsData;
    await AddOrEditForm(json, "-AddOrEditCampaigns", ActionType);
  };

  const handleSubmit = (event) => {
    event.preventDefault();
    if (
      formCampaignsData.Name === "" ||
      formCampaignsData.Email === "" ||
      formCampaignsData.Landing_Page_URL === "" ||
      formCampaignsData.HashTag === "" ||
      formCampaignsData.NPO_code === "" ||
      formCampaignsData.Image === ""
    ) {
      notify_error();
      return;
    } else {
      handleAddData();
      console.log("Successfully send form request");
      notify_success();
    }
    setFormCampaignsData({
      Name: "",
      Email: "",
      Description: "",
      Landing_Page_URL: "",
      HashTag: "",
      NPO_code: "",
      Image: "",
    });
    setActionType("Add");
    navigate("/");
  };
  const navigate = useNavigate();
  const location = useLocation();
  useEffect(() => {
    if (location.state && location.state.Campaigns) {
      setActionType("Edit");
      const { Campaigns } = location.state;
      setFormCampaignsData({
        Code: Campaigns.Code,
        Name: Campaigns.Name,
        Email: Campaigns.Email,
        Description: Campaigns.Description,
        Landing_Page_URL: Campaigns.Landing_Page_URL,
        HashTag: Campaigns.HashTag,
        NPO_code: Campaigns.NPO_code,
        Image: Campaigns.Image,
      });
    }
  }, []);
  return (
    <div className="form-container">
      <form onSubmit={handleSubmit}>
        <h1>Campaigns form</h1>
        <div className="form-group">
          <label htmlFor="Name" className="frm-lbl">
            Name:
          </label>
          <input
            type="text"
            placeholder="Enter your Name"
            className="form-control"
            name="Name"
            onChange={handleChange}
            value={formCampaignsData.Name}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Email" className="frm-lbl">
            Email:
          </label>
          <input
            type="email"
            placeholder="Enter your Email"
            name="Email"
            className="form-control"
            onChange={handleChange}
            value={formCampaignsData.Email}
          />
        </div>
        <div className="form-group">
          <label htmlFor="description" className="frm-lbl">
            Description:
          </label>
          <textarea
            name="Description"
            placeholder="A few words about the campaign"
            className="form-control"
            onChange={handleChange}
            value={formCampaignsData.Description}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Landing_Page_URL" className="frm-lbl">
            Landing Page URL:
          </label>
          <input
            type="url"
            placeholder="Enter your Landing Page URL"
            className="form-control"
            name="Landing_Page_URL"
            onChange={handleChange}
            value={formCampaignsData.Landing_Page_URL}
          />
        </div>
        <div className="form-group">
          <label htmlFor="hashtag" className="frm-lbl">
            HashTag:
          </label>
          <input
            type="text"
            placeholder="Enter your hashtag"
            name="HashTag"
            className="form-control"
            onChange={handleChange}
            value={formCampaignsData.HashTag}
          />
        </div>
        <div className="form-group">
          <label htmlFor="NPO_code" className="frm-lbl">
            NPO Code:
          </label>
          <input
            readOnly
            name="NPO_code"
            className="form-control"
            value={formCampaignsData.NPO_code}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Image" className="frm-lbl">
            Image:
          </label>
          <textarea
            name="Image"
            placeholder="Enter your Image"
            className="form-control"
            value={formCampaignsData.Image}
            onChange={handleChange}
          />
        </div>
        <div className="form-group">
          <button type="submit" className="btn btn-danger">
            Send
          </button>
          <ToastContainer />
        </div>
      </form>
    </div>
  );
};
