import axios from "axios";

const ServerAddress = "http://localhost:7129/api/Users";

//get data ues axios function
export const getData = async () => {
  let endpoint = await axios.get(`${ServerAddress}/get`);
  console.log(endpoint);
  return endpoint;
};

export const addFormToContactUs = async (frm) => {
  await axios.post(`${ServerAddress}/post`, frm);
};

export const UpdateProduct = async (ProductToUpdate) => {
  await axios.post(`${ServerAddress}/update`, ProductToUpdate);
  console.log(ProductToUpdate);
};

export const deleteProduct = async (ProductId) => {
  try {
    await axios.delete(`${ServerAddress}/delete/${ProductId}`);
  } catch (error) {
    console.error(error);
  }
};
