import axios from "axios";

const ServerAddress = "http://localhost:7153/api/Users";
const TwitterAddress = "http://localhost:7153/api/twitter";

export const addFormToContactUs = async (frm) => {
  try {
    await axios.post(`${ServerAddress}/post-ContactUs`, frm);
  } catch (error) {}
};

export const addFormRole = async (frm, role) => {
  try {
    await axios.post(`${ServerAddress}/post${role}`, frm);
  } catch (error) {}
};

export const UpdateIs_Approved = async (Is_ApprovedToUpdate) => {
  try {
    await axios.post(
      `${ServerAddress}/update-Is_Approved`,
      Is_ApprovedToUpdate
    );
  } catch (error) {}
};

export const UpdateIs_Active = async (Is_ActiveToUpdate) => {
  // console.log(Is_ActiveToUpdate);
  await axios.post(`${ServerAddress}/update-Is_Active`, Is_ActiveToUpdate);
};

export const AddOrEditForm = async (frm, action, Type) => {
  // console.log(frm);
  // console.log(action);
  // console.log(Type);
  try {
    await axios.post(`${ServerAddress}/post${action}/${Type}`, frm);
  } catch (error) {}
};

export const sendToOrderDetails = async (Order, UnitsInStock) => {
  try {
    await axios.post(
      `${ServerAddress}/post-sendToOrderDetails/${UnitsInStock}`,
      Order
    );
  } catch (error) {}
};

export const UpdateIs_send = async (Is_sendToUpdate) => {
  try {
    await axios.post(`${ServerAddress}/update-Is_send`, Is_sendToUpdate);
  } catch (error) {}
};

export const AddTweetToDB = async (Tweet, SA_code) => {
  try {
    await axios.post(`${ServerAddress}/Post-tweet/${SA_code}`, Tweet);
  } catch (error) {}
};

export const MakeA_TweetInTwitter = async (Tweet) => {
  try {
    await axios.post(`${TwitterAddress}/post-MakeATweet`, Tweet);
  } catch (error) {}
};
