import React, { useState, useEffect, useContext } from "react";
import { getAllOrdersFromDB, UpdateOrderIsSentInDB } from "../../services/OrdersServices";
import { getBcCodeByEmailFromDB } from "../../services/BuisnessCompaniesServices";
import { RoleStatus } from "../../context/roleStatus";
import { useAuth0 } from "@auth0/auth0-react";

export const OrdersReportRow = (props) => {
  const [AllOrders, setAllOrders] = useState([]);
  const [userBCcode, setuserBCcode] = useState([]);
  const { role, setRole } = useContext(RoleStatus);
  const { user } = useAuth0();

  const getDB = async () => {
    let result = await getAllOrdersFromDB();
    let userBCcode = await getBcCodeByEmailFromDB(user.email);
    setAllOrders(result.data);
    setuserBCcode(userBCcode);
  };

  useEffect(() => {
    getDB();
  }, []);

  const handelSendDonation = async (Order) => {
    await UpdateOrderIsSentInDB(Order);
    await getDB();
  };

  return (
    <>
      {AllOrders.length > 0 ? (
        AllOrders.map((Order) => {
          let { Code, SA_code, BC_code, Campaign_code, Product_code, Order_Time, Is_Sent } = Order;
          const date = new Date(Order_Time);
          const options = {
            year: "numeric",
            month: "numeric",
            day: "numeric",
            hour: "numeric",
            minute: "numeric",
            second: "numeric",
            timeZone: "Asia/Jerusalem",
            hour12: false,
          };
          const israeliFormat = new Intl.DateTimeFormat("he-IL", options).format(date);

          return (
            <>
              <tr className={userBCcode === BC_code ? "table-danger" : ""}>
                <th scope="row">{Code}</th>
                <td>{SA_code}</td>
                <td>{BC_code}</td>
                <td>{Campaign_code}</td>
                <td>{Product_code}</td>
                <td>{israeliFormat}</td>
                <td>{Is_Sent ? "Sent" : "Not Sent"}</td>
                {role === "BC" && (
                  <>
                    {!Is_Sent ? (
                      <td>
                        <button type="button" class="btn btn-primary" onClick={() => handelSendDonation(Order)}>
                          Send Donation
                        </button>
                      </td>
                    ) : (
                      <td>Donation was Sent</td>
                    )}
                  </>
                )}
              </tr>
            </>
          );
        })
      ) : (
        <h1>There are no Orders.</h1>
      )}
    </>
  );
};
