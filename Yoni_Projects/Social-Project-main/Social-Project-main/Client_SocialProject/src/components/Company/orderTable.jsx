import React, { useState, useEffect, useContext } from "react";
import { UserDataContext } from "./../../context/userData";
import { getOrderDetail } from "./../../services/allGetServices";
import { UpdateIs_send } from "./../../services/allPostServices";

export const OrderTable = () => {
  const { userInfo } = useContext(UserDataContext);
  const [OrderDetail, setOrderDetail] = useState([]);

  const [expand, setExpand] = useState(false);
  const [key, setKey] = useState(null);

  const getOrderDetailFormDB = async () => {
    let result = await getOrderDetail(userInfo.Code);
    setOrderDetail(result);
  };

  useEffect(() => {
    getOrderDetailFormDB();
  }, [userInfo]);

  const handlesSend = async (OrderDetail) => {
    await UpdateIs_send(OrderDetail);
    await getOrderDetailFormDB();
  };

  const handleClick = (pro_Key) => {
    setExpand(!expand);
    setKey(pro_Key);
  };

  return (
    <div className="table--all">
      <h1 className="table--title">List of Product I Donate</h1>
      <br />
      <table className="table">
        <thead>
          <tr>
            <th scope="col">SA_code</th>
            <th scope="col">BC_code</th>
            <th scope="col">Campaign_code</th>
            <th scope="col">Product_code</th>
            <th scope="col">Quantity</th>
            <th scope="col">Order_Time</th>
            <th scope="col">Is_Send?</th>
            <th scope="col">Send</th>
            <th scope="col"> More Info</th>
          </tr>
        </thead>
        <tbody>
          {OrderDetail.length > 0 ? (
            OrderDetail.map((item) => {
              let {
                SA_code,
                BC_code,
                Campaign_code,
                Product_code,
                Quantity,
                Order_Time,
                Is_Sent,
                SA_Name,
                BC_Name,
                Campaign_Name,
                Product_Name,
                Activist_Address,
                Activist_Phone,
                Activist_Email,
                Campaign_Email,
              } = item;
              return (
                <>
                  <tr>
                    <td>{SA_code}</td>
                    <td>{BC_code}</td>
                    <td>{Campaign_code}</td>
                    <td>{Product_code}</td>
                    <td>{Quantity}</td>
                    <td>{Order_Time}</td>
                    <td>{`${Is_Sent ? "✅" : "🐜"}`}</td>
                    <td>
                      {
                        <button
                          className="btn btn-outline-success"
                          onClick={() => {
                            handlesSend(item);
                          }}
                        >
                          Send
                        </button>
                      }
                    </td>{" "}
                    <td>
                      {
                        <button
                          className="btn btn-outline-info"
                          onClick={() => handleClick(item.Code)}
                        >
                          More Info
                        </button>
                      }
                    </td>
                  </tr>
                  {expand && item.Code === key ? (
                    <tr className="tr--ProductExpand">
                      <td>
                        <h5>SA_Name:</h5> {SA_Name}
                      </td>
                      <td>
                        <h5>BC_Name:</h5>
                        {BC_Name}
                      </td>
                      <td>
                        <h5>Campaign_Name:</h5> {Campaign_Name}
                      </td>
                      <td>
                        <h5>Product_Name:</h5>
                        {Product_Name}
                      </td>
                      <td colSpan={4}>
                        <h5>Description:</h5>
                        {`${"Activist_Address: " + Activist_Address}`}
                        <br />
                        {`${"Activist_Phone: " + Activist_Phone}`}
                        <br />
                        {`${"Activist_Email: " + Activist_Email}`} <br />
                        {`${"Campaign_Email: " + Campaign_Email}`}
                      </td>
                    </tr>
                  ) : null}
                </>
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
