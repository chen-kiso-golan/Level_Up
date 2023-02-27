import React, { useState, useEffect } from "react";
import { ToastContainer, toast } from "react-toastify";
import "./CreatCampaignStyle.css";
import { addCampaignToDB } from "../../services/CampaignsServices";
import { addNpoCodeByEmailFromDB } from "../../services/NonProfitOrganizationServices";
import { ChooseEmailRow } from "./ChooseEmailRow";
import { useAuth0 } from "@auth0/auth0-react";

export const CreatCampaign = () => {
  const [formData, setFormData] = useState({
    Name: "",
    Email: "",
    Link_URL: "",
    Hashtag: "",
    //NPO_code: "",
    Image: "",
    Is_Active: true,
  });

  const { user } = useAuth0();

  useEffect(() => {
    console.log(formData);
  }, [formData]);

  const chooseEmail = (data) => {
    setFormData((prevFormData) => ({
      ...prevFormData,
      Email: data,
    }));
  };

  function handleChange(event) {
    const { name, value, type, checked } = event.target;
    setFormData((prevFormData) => ({
      ...prevFormData,
      [name]: type === "checkbox" ? checked : value,
    }));
  }

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

  const handleAddData = async () => {
    formData.Is_Active = Boolean(formData.NPO_code);
    let json = formData;
    await addCampaignToDB(json);
    await addNpoCodeByEmailFromDB(formData.Email);
  };

  function handleSubmit(event) {
    event.preventDefault();
    if (formData.Name === "" || formData.Email === "Choose The Email Of Your NPO" || formData.Email === "" || formData.Link_URL === "" || formData.Hashtag === "" || formData.Image === "") {
      console.log("some filed is missing");
      notify_error();
      return;
    } else {
      handleAddData();
      console.log("Successfully signed up");
      notify_success();
    }
    setFormData({
      Name: "",
      Email: "",
      Link_URL: "",
      Hashtag: "",
      //NPO_code: 1,
      Image: "",
      Is_Active: true,
    });
  }

  return (
    <div className="form-container">
      <form onSubmit={handleSubmit}>
        <div className="form-group">
          <label htmlFor="Name" className="frm-lbl">
            Name
          </label>
          <input type="text" placeholder="Enter your Name" className="form-control" name="Name" onChange={handleChange} value={formData.Name} />
        </div>
        <div className="form-group">
          <ChooseEmailRow chooseEmail={chooseEmail} />
        </div>
        <div className="form-group">
          <label htmlFor="Link_URL" className="frm-lbl">
            Link
          </label>
          <input type="text" placeholder="Link URL" className="form-control" name="Link_URL" onChange={handleChange} value={formData.Link_URL} />
        </div>
        <div className="form-group">
          <label htmlFor="Hashtag" className="frm-lbl">
            Hashtag
          </label>
          <input type="text" placeholder="Enter Hashtag" className="form-control" name="Hashtag" onChange={handleChange} value={formData.Hashtag} />
        </div>
        {/* <div className="form-group">
          <label htmlFor="NPO_code" className="frm-lbl">
            NPO Code
          </label>
          <input type="number" placeholder="Enter NPO Code Name" className="form-control" name="NPO_code" onChange={handleChange} value={formData.NPO_code} />
        </div> */}
        <div className="form-group">
          <label htmlFor="Image" className="frm-lbl">
            Image URL
          </label>
          <input type="text" placeholder="Enter Image URL" className="form-control" name="Image" onChange={handleChange} value={formData.Image} />
        </div>
        <div className="form-group">
          <input id="Is_Active" type="checkbox" name="Is_Active" onChange={handleChange} checked={formData.Is_Active} />
          <label htmlFor="Is_Active" className="frm-lbl">
            I want to start the campaign!
          </label>
        </div>
        <div className="form-group">
          <button className="form--submit btn btn-danger">Create Your Campaign</button>
          <ToastContainer />
        </div>
      </form>
    </div>
  );
};
