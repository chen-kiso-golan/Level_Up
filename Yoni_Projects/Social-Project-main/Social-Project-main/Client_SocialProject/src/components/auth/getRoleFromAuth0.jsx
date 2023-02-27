import React, { useEffect, useContext } from "react";
import { useAuth0 } from "@auth0/auth0-react";
import { RollsStatus } from "./../../context/rollsStatus";
import { getRolesData, getUserInfoData } from "../../services/allGetServices";
import { UserDataContext } from "./../../context/userData";
import { get_twitterPostForUpdate } from "./../../services/allGetServices";

export const GetRoleFromAuth0 = (props) => {
  const { role, setRole } = useContext(RollsStatus);
  const { userInfo, setUserInfo } = useContext(UserDataContext);
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
    if (role === "N.P.O" || role === "company" || role === "Activist") {
      let userInfo = await getUserInfoData(user.email, role);
      let userInfoFullData = userInfo[0];
      // console.log(3, userInfoFullData);
      setUserInfo(userInfoFullData);
    }
  };

  useEffect(() => {
    handleUserInfo();
    get_twitterPostForUpdate();
  }, [role]);

  useEffect(() => {
    console.log(4, userInfo);
    console.log(2, role);
  }, [userInfo]);

  // return <div>{role}</div>;
};
