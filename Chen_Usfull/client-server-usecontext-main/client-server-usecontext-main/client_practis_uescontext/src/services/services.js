import axios from "axios";

export const getShoes = async () => {
  let endpoint = "http://localhost:4000/api/shoes";
  let response = await axios.get(endpoint);
  console.log(response);
  return response;
};
export const getShirts = async () => {
  let endpoint = "http://localhost:4000/api/tshirts";
  let response = await axios.get(endpoint);
  return response;
};
