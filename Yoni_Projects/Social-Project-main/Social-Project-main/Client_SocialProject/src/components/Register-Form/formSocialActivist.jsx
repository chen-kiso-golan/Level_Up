import React, { useState } from "react";

import { addFormRole } from "../../services/allPostServices";
import { ToastContainer, toast } from "react-toastify";
import "./styleRegister.css";

export const FormSocialActivist = () => {
  const [formData_SocialActivist, setFormData_SocialActivist] = useState({
    FirstName: "",
    LastName: "",
    Email: "",
    Address: "",
    Phone_Number: "",
    Image: "",
    Twitter_Name: "",
  });

  function handleChange(event) {
    const { name, value, type, checked } = event.target;
    setFormData_SocialActivist((prevFormData) => ({
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
    let json = formData_SocialActivist;
    await addFormRole(json, "-SocialActivist");
  };

  function handleSubmit(event) {
    event.preventDefault();
    if (
      formData_SocialActivist.FirstName === "" ||
      formData_SocialActivist.LastName === "" ||
      formData_SocialActivist.Email === "" ||
      formData_SocialActivist.Phone_Number === "" ||
      formData_SocialActivist.Image === ""
    ) {
      notify_error();
      return;
    } else {
      handleAddData();
      console.log("Successfully send contactUs form");
      notify_success();
    }
    setFormData_SocialActivist({
      FirstName: "",
      LastName: "",
      Email: "",
      Address: "",
      Phone_Number: "",
      Image: "",
      Twitter_Name: "",
    });
  }

  return (
    <div className="form-container">
      <form onSubmit={handleSubmit}>
        <h1>Social Activist form</h1>
        <div className="form-group">
          <label htmlFor="FirstName" className="frm-lbl">
            FirstName
          </label>
          <input
            type="text"
            placeholder="Enter your FirstName"
            className="form-control"
            name="FirstName"
            onChange={handleChange}
            value={formData_SocialActivist.FirstName}
          />
        </div>
        <div className="form-group">
          <label htmlFor="LastName" className="frm-lbl">
            LastName
          </label>
          <input
            type="text"
            placeholder="Enter your LastName"
            className="form-control"
            name="LastName"
            onChange={handleChange}
            value={formData_SocialActivist.LastName}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Email" className="frm-lbl">
            Email
          </label>
          <input
            type="email"
            placeholder="Enter Email address"
            className="form-control"
            name="Email"
            onChange={handleChange}
            value={formData_SocialActivist.Email}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Address" className="frm-lbl">
            Address
          </label>
          <input
            type="text"
            placeholder="Enter your Address"
            className="form-control"
            name="Address"
            onChange={handleChange}
            value={formData_SocialActivist.Address}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Twitter_Name" className="frm-lbl">
            Twitter Name
          </label>
          <input
            type="text"
            placeholder="Enter your Twitter_Name"
            className="form-control"
            name="Twitter_Name"
            onChange={handleChange}
            value={formData_SocialActivist.Twitter_Name}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Phone_Number" className="frm-lbl">
            Phone Number
          </label>
          <input
            type="tel"
            placeholder="Enter your Phone Number"
            className="form-control"
            name="Phone_Number"
            onChange={handleChange}
            value={formData_SocialActivist.Phone_Number}
          />
        </div>
        <textarea
          value={formData_SocialActivist.Image}
          placeholder="Add Image"
          onChange={handleChange}
          name="Image"
        />
        <div className="form-group">
          <button className="form--submit btn btn-danger">Send</button>
          <ToastContainer />
        </div>
      </form>
    </div>
  );
};
