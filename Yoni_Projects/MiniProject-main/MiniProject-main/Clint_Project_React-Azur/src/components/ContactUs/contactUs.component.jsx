import React, { useState } from "react";

import { addFormToContactUs } from "../../services/services";
import { ToastContainer, toast } from "react-toastify";
import "./styleForm.css";

export const FormContactUs = () => {
  const [formData, setFormData] = useState({
    FirstName: "",
    LastName: "",
    Email: "",
    Password: "",
    PasswordConfirm: "",
    Comments: "",
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
    if (
      formData.Password !== formData.PasswordConfirm ||
      formData.FirstName === "" ||
      formData.LastName === "" ||
      formData.Email === "" ||
      formData.Password === ""
    ) {
      console.log("Passwords do not match of sum filed is missing");
      notify_error();
      return;
    } else {
      handleAddData();
      console.log("Successfully signed up");
      notify_success();
    }
    setFormData({
      FirstName: "",
      LastName: "",
      Email: "",
      Password: "",
      PasswordConfirm: "",
      Comments: "",
      JoinedNewsletter: "",
    });
  }

  return (
    <div className="form-container">
      <form onSubmit={handleSubmit}>
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
            value={formData.FirstName}
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
            value={formData.LastName}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Email" className="frm-lbl">
            Email
          </label>
          <input
            type="email"
            placeholder="Email address"
            className="form-control"
            name="Email"
            onChange={handleChange}
            value={formData.Email}
          />
        </div>
        <div className="form-group">
          <label htmlFor="password" className="frm-lbl">
            Password
          </label>
          <input
            type="password"
            placeholder="Password"
            className="form-control"
            name="Password"
            onChange={handleChange}
            value={formData.Password}
          />
        </div>
        <div className="form-group">
          <label htmlFor="passwordConfirm" className="frm-lbl">
            confirm password
          </label>
          <input
            type="password"
            placeholder="Confirm password"
            className="form-control"
            name="PasswordConfirm"
            onChange={handleChange}
            value={formData.PasswordConfirm}
          />
        </div>
        <textarea
          value={formData.Comments}
          placeholder="Comments"
          onChange={handleChange}
          name="Comments"
        />
        <div className="form-group">
          <input
            id="okayToEmail"
            type="checkbox"
            name="JoinedNewsletter"
            onChange={handleChange}
            checked={formData.JoinedNewsletter}
          />
          <label htmlFor="okayToEmail" className="frm-lbl">
            I want to join the newsletter
          </label>
        </div>
        <div className="form-group">
          <button className="form--submit btn btn-danger">Sign up</button>
          <ToastContainer />
        </div>
      </form>
    </div>
  );
};
