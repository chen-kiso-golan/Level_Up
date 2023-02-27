import React, { useState } from "react";

import { ToastContainer, toast } from "react-toastify";
import "./contactUsStyle.css";
import { addFormToContactUs } from "./../../services/ContactUsServices";

export const ContactUs = () => {
  const [formData, setFormData] = useState({
    Name: "",
    Email: "",
    Phone: "",
    Message: "",
    JoinedNewsletter: true,
  });

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
    let json = formData;
    await addFormToContactUs(json);
  };

  function handleSubmit(event) {
    event.preventDefault();
    if (formData.Name === "" || formData.Email === "" || formData.Password === "" || formData.Phone === "") {
      notify_error();
      return;
    } else {
      handleAddData();
      notify_success();
    }
    setFormData({
      Name: "",
      Email: "",
      Phone: "",
      Message: "",
      JoinedNewsletter: "",
    });
  }

  return (
    <div>
      <div className="form-container">
        <form onSubmit={handleSubmit}>
          <div className="form-group">
            <label htmlFor="Name" className="frm-lbl">
              Name
            </label>
            <input type="text" placeholder="Enter your Name" className="form-control" name="Name" onChange={handleChange} value={formData.Name} />
          </div>
          <div className="form-group">
            <label htmlFor="Email" className="frm-lbl">
              Email
            </label>
            <input type="email" placeholder="Email address" className="form-control" name="Email" onChange={handleChange} value={formData.Email} />
          </div>
          <div className="form-group">
            <label htmlFor="phone" className="frm-lbl">
              Phone
            </label>
            <input type="phoneNumber" placeholder="phone" className="form-control" name="Phone" onChange={handleChange} value={formData.Phone} />
          </div>
          <textarea value={formData.Message} placeholder="Message" onChange={handleChange} name="Message" />
          <div className="form-group">
            <input id="okayToEmail" type="checkbox" name="JoinedNewsletter" onChange={handleChange} checked={formData.JoinedNewsletter} />
            <label htmlFor="okayToEmail" className="frm-lbl">
              I want to join the newsletter
            </label>
          </div>
          <div className="form-group">
            <button className="form--submit btn btn-danger">Send</button>
            <ToastContainer />
          </div>
        </form>
      </div>
    </div>
  );
};
