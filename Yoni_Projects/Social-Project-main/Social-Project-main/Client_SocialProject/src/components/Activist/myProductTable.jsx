import React, { useState, useEffect, useContext } from "react";
import { getAllMyProduct } from "../../services/allGetServices";
import { UserDataContext } from "./../../context/userData";

export const MyProductTable = () => {
  const { userInfo } = useContext(UserDataContext);
  const [AllMyProduct, setAllMyProduct] = useState([]);

  const getMyProductFormDB = async () => {
    let result = await getAllMyProduct(userInfo.Code);
    setAllMyProduct(result);
  };

  useEffect(() => {
    getMyProductFormDB();
  }, []);

  return (
    <div className="table--all">
      <h1 className="table--title">List of Product I Donate</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">Product Name</th>
            <th scope="col">Price</th>
            <th scope="col">Total Donations</th>
            <th scope="col">Quantity</th>
            <th scope="col">Total Price</th>
            <th scope="col">Campaign Name</th>
          </tr>
        </thead>
        <tbody>
          {AllMyProduct.length > 0 ? (
            AllMyProduct.map((item) => {
              let {
                Product_Name,
                Price,
                Total_Donations,
                Quantity,
                Total_Price,
                Campaign_Name,
              } = item;
              return (
                <tr>
                  <td>{Product_Name}</td>
                  <td>{Price}</td>
                  <td>{Total_Donations}</td>
                  <td>{Quantity}</td>
                  <td>{Total_Price}</td>
                  <td>{Campaign_Name}</td>
                </tr>
              );
            })
          ) : (
            <h4>Loading...</h4>
          )}
        </tbody>
      </table>
    </div>
  );
};
