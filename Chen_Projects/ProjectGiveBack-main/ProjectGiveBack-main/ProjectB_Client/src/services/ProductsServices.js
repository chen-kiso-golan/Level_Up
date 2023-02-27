import axios from "axios";

const ServerAddress = "http://localhost:7205/api/Products";

export const getAllProductsFromDB = async () => {
  try {
    console.log("services - Products - getAllProductsFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getAllProductsFromDB`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllProductsFromDB Service : ${ex}`);
  }
};

export const addProductToDB = async (frm) => {
  try {
    console.log("services - Products - addProductToDB ran Successfully");
    await axios.post(`${ServerAddress}/ProductPost`, frm);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the addProductToDB Service : ${ex}`);
  }
};
