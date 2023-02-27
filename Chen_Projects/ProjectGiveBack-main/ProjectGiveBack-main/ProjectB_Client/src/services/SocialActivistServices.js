import axios from "axios";

const ServerAddress = "http://localhost:7205/api/SocialActivist";

export const getAllActivistsFromDB = async () => {
  try {
    console.log("services - SocialActivist - getAllActivistsFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getAllActivistsFromDB`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllActivistsFromDB Service : ${ex}`);
  }
};

export const addActivistToDB = async (frm) => {
  try {
    console.log("services - SocialActivist - addActivistToDB ran Successfully");
    await axios.post(`${ServerAddress}/ActivistPost`, frm);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the addActivistToDB Service : ${ex}`);
  }
};
