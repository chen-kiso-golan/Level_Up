import React, { useState, useContext, useEffect } from "react";
import { ToastContainer, toast } from "react-toastify";

import { useLocation, useNavigate } from "react-router-dom";
// import "../styleOwner.css";
import { AddOrEditForm } from "./../../services/allPostServices";
import { UserDataContext } from "./../../context/userData";

export const AddOrEditProduct = (props) => {
  const { userInfo } = useContext(UserDataContext);
  const navigate = useNavigate();
  const location = useLocation();
  const { Campaign, product } = location.state;

  console.log(20, userInfo);
  const [formProduct, setFormProduct] = useState({});
  const [ActionType, setActionType] = useState("Add");

  useEffect(() => {
    if (location.state && location.state.Campaign) {
      setFormProduct({
        Name: "",
        Price: "",
        Description: "",
        Units_In_Stock: "",
        BC_code: userInfo.Code,
        Campaign_code: Campaign.Code,
        Image: "",
      });
    } else if (location.state && location.state.product) {
      setActionType("Edit");
      setFormProduct({
        Code: product.Code,
        Name: product.Name,
        Price: product.Price,
        Description: product.Description,
        Units_In_Stock: product.Units_In_Stock,
        BC_code: userInfo.Code,
        Campaign_code: product.Campaign_code,
        Image: product.Image,
      });
    }
  }, []);

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
    setFormProduct((prevFormData) => ({
      ...prevFormData,
      [name]: value,
    }));
  };

  const handleAddData = async () => {
    let json = formProduct;
    json.Price = parseFloat(json.Price);
    json.Units_In_Stock = parseInt(json.Units_In_Stock);
    json.BC_code = parseInt(json.BC_code);
    json.Campaign_code = parseInt(json.Campaign_code);
    await AddOrEditForm(json, "-AddOrEditProduct", ActionType);
  };

  const handleSubmit = (event) => {
    event.preventDefault();
    if (
      formProduct.Name === "" ||
      formProduct.Price === "" ||
      formProduct.Description === "" ||
      formProduct.Units_In_Stock === "" ||
      formProduct.BC_code === "" ||
      formProduct.Image === ""
    ) {
      notify_error();
      return;
    } else {
      handleAddData();
      navigate("/productTable");
      console.log("Successfully send form request");
      notify_success();
      setActionType("Add");
    }
  };

  return (
    <div className="form-container">
      <form onSubmit={handleSubmit}>
        <h1>Product form</h1>
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
            value={formProduct.Name}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Price" className="frm-lbl">
            Price:
          </label>
          <input
            type="Price"
            placeholder="Enter The Price of yours product"
            name="Price"
            className="form-control"
            onChange={handleChange}
            value={formProduct.Price}
          />
        </div>
        <div className="form-group">
          <label htmlFor="description" className="frm-lbl">
            Description:
          </label>
          <textarea
            name="Description"
            placeholder="A few words about the Product"
            className="form-control"
            onChange={handleChange}
            value={formProduct.Description}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Units_In_Stock" className="frm-lbl">
            Units In Stock:
          </label>
          <input
            type="number"
            placeholder="Enter your Units In Stock"
            className="form-control"
            name="Units_In_Stock"
            onChange={handleChange}
            value={formProduct.Units_In_Stock}
          />
        </div>
        <div className="form-group">
          <label htmlFor="BC_code" className="frm-lbl">
            Business Companies code:
          </label>
          <input
            readOnly
            name="BC_code"
            className="form-control"
            value={formProduct.BC_code}
          />
        </div>
        <div className="form-group">
          <label htmlFor="Campaign_code" className="frm-lbl">
            Campaign Code:
          </label>
          <input
            readOnly
            name="Campaign_code"
            className="form-control"
            value={formProduct.Campaign_code}
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
            value={formProduct.Image}
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
