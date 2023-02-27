import axios from "axios";

const ServerAddress = "http://localhost:7205/api/Orders";

export const getAllOrdersFromDB = async () => {
  try {
    console.log("services - Orders - getAllOrdersFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getAllOrdersFromDB`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllOrdersFromDB Service : ${ex}`);
  }
};

export const addOrderToDB = async (frm) => {
  try {
    console.log("services - Orders - addOrderToDB ran Successfully");
    await axios.post(`${ServerAddress}/OrderPost`, frm);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the addOrderToDB Service : ${ex}`);
  }
};

export const UpdateOrderIsSentInDB = async (Order) => {
  try {
    console.log("services - Orders - UpdateOrderIsSentInDB ran Successfully");
    await axios.post(`${ServerAddress}/UpdateOrderIsSent`, Order);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the UpdateOrderIsSentInDB Service : ${ex}`);
  }
};
