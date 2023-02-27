import axios from "axios";

const ServerAddress = "http://localhost:7205/api/BuisnessCompanies";

export const getAllCompaniesFromDB = async () => {
  try {
    console.log("services - BuisnessCompaniesServices - getAllCompaniesFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getAllCompaniesFromDB`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllCompaniesFromDB Service : ${ex}`);
  }
};

export const getAllCompaniesNamesFromDB = async (email) => {
  try {
    console.log("services - BuisnessCompaniesServices - getAllCompaniesNamesFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getAllCompaniesNamesFromDB/${email}`);
    return endpoint;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getAllCompaniesNamesFromDB Service : ${ex}`);
  }
};

export const getBcCodeByNameFromDB = async (Name) => {
  try {
    console.log("services - BuisnessCompaniesServices - getBcCodeByNameFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getBcCodeByNameFromDB/${Name}`);
    console.log(endpoint.data);
    return endpoint.data;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getBcCodeByNameFromDB Service : ${ex}`);
  }
};

export const getBcCodeByEmailFromDB = async (email) => {
  try {
    console.log("services - BuisnessCompaniesServices - getBcCodeByEmailFromDB ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/getBcCodeByEmailFromDB/${email}`);
    console.log(endpoint.data);
    return endpoint.data;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getBcCodeByEmailFromDB Service : ${ex}`);
  }
};

export const addCompanyToDB = async (frm) => {
  try {
    console.log("services - BuisnessCompaniesServices - addCompanyToDB ran Successfully");
    await axios.post(`${ServerAddress}/CompanyPost`, frm);
    console.log("Company form was sent to DB :)");
  } catch (ex) {
    console.log(`An Exception occurred while initializing the addCompanyToDB Service : ${ex}`);
  }
};
