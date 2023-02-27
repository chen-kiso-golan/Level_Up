import axios from "axios";

const ServerAddress = "http://localhost:7205/api/NonProfitOrganization";

export const getAllNpoFromDB = async () => {
  try {
    console.log("services - NonProfitOrganization - getAllNpoFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getAllNpoFromDB`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllNpoFromDB Service : ${ex}`);
  }
};

export const getAllNpoEmailsFromDB = async () => {
  try {
    console.log("services - NonProfitOrganization - getAllNpoEmailsFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getAllNpoEmailsFromDB`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllNpoEmailsFromDB Service : ${ex}`);
  }
};

export const addNpoToDB = async (frm) => {
  try {
    console.log("services - NonProfitOrganization - addNpoToDB ran Successfully");
    await axios.post(`${ServerAddress}/NpoPost`, frm);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the addNpoToDB Service : ${ex}`);
  }
};

export const addNpoCodeByEmailFromDB = async (frm) => {
  try {
    console.log("services - NonProfitOrganization - addNpoCodeByEmailFromDB ran Successfully");
    await axios.post(`${ServerAddress}/NpoCodeByEmailPost/${frm}`);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the addNpoCodeByEmailFromDB Service : ${ex}`);
  }
};
