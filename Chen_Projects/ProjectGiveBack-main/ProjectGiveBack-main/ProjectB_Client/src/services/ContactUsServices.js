import axios from "axios";

const ServerAddress = "http://localhost:7205/api/ContactUs";

export const addFormToContactUs = async (frm) => {
  try {
    console.log("services - ContactUsServices - addFormToContactUs ran Successfully");
    await axios.post(`${ServerAddress}/ContactUsPost`, frm);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the addFormToContactUs Service : ${ex}`);
  }
};
