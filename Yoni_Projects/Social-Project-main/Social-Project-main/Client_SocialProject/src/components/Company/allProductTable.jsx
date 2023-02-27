import React, { useState, useEffect, useContext } from "react";

import { useNavigate, useLocation } from "react-router-dom";
import {
  getProductListForActivist,
  getProductPerCompany,
  getUserInfoData,
} from "../../services/allGetServices";
import "./styleCompany.css";
import { UserDataContext } from "./../../context/userData";
import { RollsStatus } from "./../../context/rollsStatus";
import { ToastContainer, toast } from "react-toastify";
import { DeleteProduct } from "./../../services/allDeleteServices";
import { sendToOrderDetails } from "../../services/allPostServices";
import { UpdateMoneyStatus } from "./../../services/allGetServices";
import { useAuth0 } from "@auth0/auth0-react";
import { MakeA_TweetInTwitter } from "./../../services/allPostServices";

export const ProductParCompanyTable = () => {
  const { role } = useContext(RollsStatus);
  const { userInfo, setUserInfo } = useContext(UserDataContext);

  console.log(50, role);
  const { user } = useAuth0();
  const navigate = useNavigate();
  const location = useLocation();

  const [CompanyProduct, setCompanyProduct] = useState([]);
  const [expand, setExpand] = useState(false);
  const [key, setKey] = useState(null);
  const [bigImg, setBigImg] = useState(false);
  const [UnitsInStock, seUnitsInStock] = useState("");

  const getProductForCompanyDB = async () => {
    let result = await getProductPerCompany(userInfo.Code);
    setCompanyProduct(result);
  };

  const getProductForActivistDB = async (Campaign) => {
    let result = await getProductListForActivist(Campaign.Code);
    setCompanyProduct(result);
  };

  const handleUserInfo = async () => {
    if (role === "N.P.O" || role === "company" || role === "Activist") {
      let userInfo = await getUserInfoData(user.email, role);
      let userInfoFullData = userInfo[0];
      console.log(3, userInfoFullData);
      setUserInfo(userInfoFullData);
    }
  };

  useEffect(() => {
    if (role === "company") {
      getProductForCompanyDB();
    } else if (location.state && location.state.Campaign) {
      const { Campaign } = location.state;
      getProductForActivistDB(Campaign);
    }
  }, [userInfo]);

  const notify_success = (msg) =>
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

  const notify_error = (error) =>
    toast.error(error, {
      position: "top-right",
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: "dark",
    });

  const handleClick = (pro_Key) => {
    setExpand(!expand);
    setKey(pro_Key);
    if (!expand) seUnitsInStock((prev) => ({ ...prev, [pro_Key]: 0 }));
  };

  const handelImg = (pro_Key) => {
    setBigImg((perv) => !perv);
    setKey(pro_Key);
  };

  const handelUnits_In_Stock = (Code, value) => {
    seUnitsInStock((prev) => ({ ...prev, [Code]: value }));
  };

  const handleDonate = async (Product, TotalPrice) => {
    let TotalMoneyStatus = userInfo.Money_Status - TotalPrice;
    if (Product.Price > userInfo.Money_Status) {
      notify_error("There is not enough money to donate");
    } else if (location.state && location.state.Campaign) {
      const { Campaign } = location.state;
      const AddOrder = {
        SA_code: parseInt(userInfo.Code),
        BC_code: parseInt(Product.BC_code),
        Campaign_code: parseInt(Campaign.Code),
        Product_code: parseInt(Product.Code),
      };
      const AddTweet = {
        Twitter_Name: userInfo.Twitter_Name,
        Quantity: UnitsInStock[Product.Code],
        ProductName: Product.Name,
        CampaignName: Campaign.Name,
        CampaignHashTag: Campaign.HashTag,
      };
      await sendToOrderDetails(AddOrder, UnitsInStock[Product.Code]);
      await getProductForActivistDB(Campaign);
      await MakeA_TweetInTwitter(AddTweet);
      await UpdateMoneyStatus(TotalMoneyStatus, userInfo.Code);
      await handleUserInfo();
      setExpand(!expand);
    }
  };

  const handleUpdate = (product) => {
    navigate("/editOrAddProduct", {
      state: {
        product,
      },
    });
  };

  const handleDeleteProduct = async (productId) => {
    setExpand(!expand);
    await DeleteProduct(productId);
    getProductForCompanyDB();
  };

  return (
    <div className="table--all">
      <h1 className="table--title">List of All My Product</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">Code</th>
            <th scope="col">Image</th>
            <th scope="col">Name</th>
            <th scope="col">Price</th>
            <th scope="col">Units_In_Stock</th>
            <th scope="col">BC_code</th>
          </tr>
        </thead>
        <tbody>
          {CompanyProduct.length > 0 ? (
            CompanyProduct.map((item) => {
              let {
                Code,
                Name,
                Price,
                Description,
                Units_In_Stock,
                BC_code,
                Image,
              } = item;
              return (
                <>
                  <tr onClick={() => handleClick(item.Code)}>
                    <th scope="row">{Code}</th>
                    <td onClick={() => handelImg(Code)} className="td--image">
                      {bigImg && item.Code === key && (
                        <img src={Image} alt="img" />
                      )}
                      {!bigImg && <img src={Image} alt="img" />}
                    </td>
                    <td>{Name}</td>
                    <td>{Price}$</td>
                    <td>
                      {Units_In_Stock === 0 ? "out of Stock" : Units_In_Stock}
                    </td>
                    <td>{BC_code}</td>
                  </tr>
                  {role === "company" && expand && item.Code === key ? (
                    <tr className="tr--ProductExpand">
                      <td colSpan={2}>
                        <button
                          className="btn btn-warning"
                          onClick={() => {
                            handleUpdate(item);
                          }}
                        >
                          Edit Product
                        </button>
                      </td>
                      <td colSpan={3}>{`${"Description: " + Description}`}</td>
                      <td colSpan={1}>
                        <button
                          className="btn btn-danger"
                          onClick={() => {
                            handleDeleteProduct(item.Code);
                          }}
                        >
                          Delete Product
                        </button>
                      </td>
                    </tr>
                  ) : null}
                  {role === "Activist" && expand && item.Code === key ? (
                    <tr className="tr--ProductExpand">
                      <td colSpan={3}>
                        <h5>{Name} Description:</h5>
                        {Description}
                      </td>
                      <td>
                        Units_In_Stock <br />
                        <input
                          type="number"
                          min={0}
                          max={Units_In_Stock}
                          onChange={(event) =>
                            handelUnits_In_Stock(Code, event.target.value)
                          }
                        />
                      </td>
                      <td>
                        Total Price <br />
                        {(Price * UnitsInStock[Code]).toFixed(2)}$
                      </td>
                      <td>
                        <button
                          className="btn btn-danger"
                          onClick={() => {
                            handleDonate(item, Price * UnitsInStock[Code]);
                          }}
                        >
                          Donate
                        </button>
                        <ToastContainer />
                      </td>
                    </tr>
                  ) : null}
                </>
              );
            })
          ) : (
            <h1>loading</h1>
          )}
        </tbody>
      </table>
    </div>
  );
};
