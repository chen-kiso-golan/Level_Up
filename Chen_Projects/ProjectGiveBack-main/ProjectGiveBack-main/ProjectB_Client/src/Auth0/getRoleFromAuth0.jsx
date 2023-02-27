import React, { useEffect, useContext } from "react";
import { useAuth0 } from "@auth0/auth0-react";
import { RoleStatus } from "./../context/roleStatus";
import { getRolesData, getUserInfoData } from "../../src/services/RegisterApplicationsServices";
import { UserDataContext } from "./../context/UserData";
import { getAllTweetsToUpdateDB } from "./../services/twitterServices";

export const GetRoleFromAuth0 = (props) => {
  const { role, setRole } = useContext(RoleStatus);
  const { setUserInfo } = useContext(UserDataContext);
  const { user } = useAuth0();

  const handleRoles = async () => {
    let userId = user.sub;
    let RoleData = await getRolesData(userId);
    if (Object.keys(RoleData).length === 0) {
      setRole("");
    } else {
      let RoleName = RoleData[0].name;
      setRole(RoleName);
    }
  };

  useEffect(() => {
    handleRoles();
  }, []);

  const handleUserInfo = async () => {
    if (role === "NPO" || role === "BC" || role === "SA") {
      let userInfo = await getUserInfoData(user.email, role);
      let userInfoFullData = userInfo[0];
      setUserInfo(userInfoFullData);
    }
  };

  useEffect(() => {
    handleUserInfo();
    getAllTweetsToUpdateDB();
  }, [role]);

  // return <div>{role}</div>;
};
