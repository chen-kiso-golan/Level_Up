import React, { useState } from "react";

import { addFormRole } from "../../services/allPostServices";
import { ToastContainer, toast } from "react-toastify";
import "./styleRegister.css";

export const FormCompany = () => {
  const [formDataCompany, setFormDataCompany] = useState({
    Name: "",
    Email: "",
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

  function handleChange(event) {
    const { name, value, type, checked } = event.target;
    setFormDataCompany((prevFormData) => ({
      ...prevFormData,
      [name]: type === "checkbox" ? checked : value,
    }));
  }

  const handleAddData = async () => {
    let json = formDataCompany;
    await addFormRole(json, "-Company");
  };

  function handleSubmit(event) {
    event.preventDefault();
    if (
      formDataCompany.Name === "" ||
      formDataCompany.Email === "" ||
      formDataCompany.Image === ""
    ) {
      notify_error();
      return;
    } else {
      handleAddData();
      console.log("Successfully send form request");
      notify_success();
    }
    setFormDataCompany({
      Name: "",
      Email: "",
      Image: "",
    });
  }

  return (
    <div className="form-container">
      <form onSubmit={handleSubmit}>
        <h1>Business Companies form</h1>
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
            value={formDataCompany.Name}
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
            value={formDataCompany.Email}
          />
        </div>
        <textarea
          value={formDataCompany.Image}
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
