import React, { useState } from "react";

import { addFormRole } from "../../services/allPostServices";
import { ToastContainer, toast } from "react-toastify";
import "./styleRegister.css";

export const FormNPO = () => {
  const [formDataNPO, setFormDataNPO] = useState({
    Name: "",
    Email: "",
    Website_URL: "",
    Image: "",
  });

  function handleChange(event) {
    const { name, value, type, checked } = event.target;
    setFormDataNPO((prevFormData) => ({
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
    let json = formDataNPO;
    await addFormRole(json, "-NPO");
  };

  function handleSubmit(event) {
    event.preventDefault();
    if (
      formDataNPO.Name === "" ||
      formDataNPO.Email === "" ||
      formDataNPO.Website_URL === "" ||
      formDataNPO.Image === ""
    ) {
      notify_error();
      return;
    } else {
      handleAddData();
      console.log("Successfully send form request");
      notify_success();
    }
    setFormDataNPO({
      Name: "",
      Email: "",
      Image: "",
      Website_URL: "",
    });
  }

  return (
    <div className="form-container">
      <form onSubmit={handleSubmit}>
        <h1>Non Profit Organization form</h1>
        <div className="form-group">
          <label htmlFor="Name" className="frm-lbl">
            Name
          </label>
          <input
            type="text"
            placeholder="Enter your Name"
            className="form-control"
            name="Name"
            onChange={handleChange}
            value={formDataNPO.Name}
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
            value={formDataNPO.Email}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Website_URL" className="frm-lbl">
            Website URL
          </label>
          <input
            type="text"
            placeholder="Website URL"
            className="form-control"
            name="Website_URL"
            onChange={handleChange}
            value={formDataNPO.Website_URL}
          />
        </div>
        <textarea
          value={formDataNPO.Image}
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
