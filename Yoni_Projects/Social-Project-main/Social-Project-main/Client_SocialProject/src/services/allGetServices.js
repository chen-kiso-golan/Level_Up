import axios from "axios";

const ServerAddress = "http://localhost:7153/api/Users";
const TwitterAddress = "http://localhost:7153/api/twitter";

export const getRolesData = async (userId) => {
  let endpoint = await axios.get(`${ServerAddress}/get-role/${userId}`);
  console.log(userId, "test");
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getUserInfoData = async (email, role) => {
  // console.log(1, email, role);
  let endpoint = await axios.get(
    `${ServerAddress}/get-UserInfoData/${email}/${role}`
  );
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getPending = async (email) => {
  let endpoint = await axios.get(`${ServerAddress}/get-Pending/${email}`);
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
    console.log("problem");
  }
};

export const getPendingList = async () => {
  let endpoint = await axios.get(`${ServerAddress}/get-PendingList`);
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getAllTwitted = async () => {
  let endpoint = await axios.get(`${ServerAddress}/get-AllTwitted`);
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getAllSA_Rows = async () => {
  let endpoint = await axios.get(`${ServerAddress}/get-AllSARows`);
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getAllNPO_Rows = async () => {
  let endpoint = await axios.get(`${ServerAddress}/get-AllNPORows`);
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getAllCompany_Rows = async () => {
  let endpoint = await axios.get(`${ServerAddress}/get-AllCompanyRows`);
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getAllCampaignsByNPO_code = async (NPO_code) => {
  let endpoint = await axios.get(
    `${ServerAddress}/get-AllCampaignsByNPO_code/${NPO_code}`
  );
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getAllCampaigns = async () => {
  let endpoint = await axios.get(`${ServerAddress}/get-AllCampaigns`);
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getProductPerCompany = async (BC_Code) => {
  console.log(10, BC_Code);
  let endpoint = await axios.get(
    `${ServerAddress}/get-ProductPerCompany/${BC_Code}`
  );
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getProductListForActivist = async (Campaign_code) => {
  let endpoint = await axios.get(
    `${ServerAddress}/get-ProductListForActivist/${Campaign_code}`
  );
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getAllMyProduct = async (SA_Code) => {
  let endpoint = await axios.get(
    `${ServerAddress}/get-AllMyProduct/${SA_Code}`
  );
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const getOrderDetail = async (BC_Code) => {
  console.log(55, BC_Code);
  let endpoint = await axios.get(`${ServerAddress}/get-OrderDetail/${BC_Code}`);
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const UpdateMoneyStatus = async (TotalMoneyStatus, SA_Code) => {
  let endpoint = await axios.get(
    `${ServerAddress}/get-UpdateMoneyStatus/${TotalMoneyStatus}/${SA_Code}`
  );
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const UpdateAddMoneyStatus = async (userInfoCode) => {
  let endpoint = await axios.get(
    `${ServerAddress}/update-AddMoneyStatus/${userInfoCode}`
  );
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};

export const get_twitterPostForUpdate = async () => {
  let endpoint = await axios.get(`${TwitterAddress}/get-twitterPostForUpdate`);
  if (endpoint.status === 200) {
    return endpoint.data;
  } else {
    return null;
  }
};
