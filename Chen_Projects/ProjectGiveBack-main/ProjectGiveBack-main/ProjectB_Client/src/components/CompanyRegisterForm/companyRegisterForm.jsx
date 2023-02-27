import React, { useState } from "react";

import { ToastContainer, toast } from "react-toastify";
import "./companyRegisterFormStyle.css";
import { addCompanyToDB } from "../../services/BuisnessCompaniesServices";

export const CompanyRegisterForm = () => {
  const [formData, setFormData] = useState({
    Name: "",
    Email: "",
    Image: "",
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
    await addCompanyToDB(json);
  };

  function handleSubmit(event) {
    event.preventDefault();
    if (formData.Name === "" || formData.Email === "") {
      console.log("Passwords do not match or some filed is missing");
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
      Image: "",
    });
  }

  return (
    <div className="form-container">
      <form onSubmit={handleSubmit}>
        <div className="form-group">
          <label htmlFor="Name" className="frm-lbl">
            Company Name
          </label>
          <input type="text" placeholder="Enter your Company Name" className="form-control" name="Name" onChange={handleChange} value={formData.Name} />
        </div>
        <div className="form-group">
          <label htmlFor="Email" className="frm-lbl">
            Email
          </label>
          <input type="email" placeholder="Email address" className="form-control" name="Email" onChange={handleChange} value={formData.Email} />
        </div>
        <div className="form-group">
          <label htmlFor="Image" className="frm-lbl">
            Image URL
          </label>
          <input type="text" placeholder="Enter your Image URL" className="form-control" name="Image" onChange={handleChange} value={formData.Image} />
        </div>
        <div className="form-group">
          <button className="form--submit btn btn-danger">Sign up</button>
          <ToastContainer />
        </div>
      </form>
    </div>
  );
};
