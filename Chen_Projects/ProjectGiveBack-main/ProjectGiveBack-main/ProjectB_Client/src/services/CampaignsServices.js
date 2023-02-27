import axios from "axios";

const ServerAddress = "http://localhost:7205/api/Campaigns";

export const getAllCampaignsFromDB = async () => {
  try {
    console.log("services - CampaignsServices - getAllCampaignsFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getAllCampaignsFromDB`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllCampaignsFromDB Service : ${ex}`);
  }
};

export const getAllCampaignNamesFromDB = async () => {
  try {
    console.log("services - CampaignsServices - getAllCampaignNamesFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getAllCampaignNamesFromDB`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllCampaignNamesFromDB Service : ${ex}`);
  }
};

export const getCampaignCodeByNameFromDB = async (Name) => {
  try {
    console.log("services - CampaignsServices - getCampaignCodeByNameFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getCampaignCodeByNameFromDB/${Name}`);

    return endpoint.data;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getCampaignCodeByNameFromDB Service : ${ex}`);
  }
};

export const getCampaignNameAndHashtagByCodeFromDB = async (Code) => {
  try {
    console.log("services - CampaignsServices - getCampaignNameAndHashtagByCodeFromDB ran Successfully");
    let endpoint = await axios.get(`${TwitterAddress}/getCampaignNameAndHashtagByCodeFromDB/${Code}`);
    return endpoint.data;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getCampaignNameAndHashtagByCodeFromDB Service : ${ex}`);
  }
};

export const addCampaignToDB = async (frm) => {
  try {
    console.log("services - CampaignsServices - addCampaignToDB ran Successfully");
    await axios.post(`${ServerAddress}/CampaignPost`, frm);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the addCampaignToDB Service : ${ex}`);
  }
};

export const UpdateCampaign = async (CampaignToUpdate) => {
  try {
    console.log("services - CampaignsServices - UpdateCampaign ran Successfully");
    await axios.post(`${ServerAddress}/UpdateCampaign`, CampaignToUpdate);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the UpdateCampaign Service : ${ex}`);
  }
};

export const deleteCampaign = async (Code) => {
  try {
    console.log("services - CampaignsServices - deleteCampaign ran Successfully");
    await axios.delete(`${ServerAddress}/deleteCampaign/${Code}`);
  } catch (ex) {
    console.log(`An Exception occurred while initializing the deleteCampaign Service : ${ex}`);
  }
};
