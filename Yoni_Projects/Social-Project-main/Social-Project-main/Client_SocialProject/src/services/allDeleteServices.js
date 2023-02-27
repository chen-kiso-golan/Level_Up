import axios from "axios";

const ServerAddress = "http://localhost:7153/api/Users";

export const DeleteProduct = async (ProductId) => {
  try {
    await axios.delete(`${ServerAddress}/delete-CompanyProduct/${ProductId}`);
  } catch (error) {
    console.error(error);
  }
};
