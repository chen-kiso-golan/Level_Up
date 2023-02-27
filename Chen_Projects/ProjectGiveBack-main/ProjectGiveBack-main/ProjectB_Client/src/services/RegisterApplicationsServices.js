import axios from "axios";

const ServerAddress = "http://localhost:7205/api/RegisterApplications";

export const getRolesData = async (userId) => {
  try {
    console.log("services - RegisterApplications - getRolesData ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/get_role/${userId}`);
    return endpoint.data;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getRolesData Service : ${ex}`);
  }
};

export const getUserInfoData = async (email, role) => {
  try {
    console.log("services - RegisterApplications - getUserInfoData ran Successfully");
    let endpoint = await axios.get(`${ServerAddress}/get_UserInfoData/${email}/${role}`);
    return endpoint.data;
  } catch (ex) {
    console.log(`An Exception occurred while initializing the getUserInfoData Service : ${ex}`);
  }
};
