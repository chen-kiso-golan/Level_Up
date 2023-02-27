import React, { useContext, useEffect, useState } from "react";
import { RollsStatus } from "./../../context/rollsStatus";
import { OwnerSidebar } from "./ownerSidebar";
import { NonProfitSidebar } from "./nonProfitSidebar";
import { CompanySidebar } from "./companySidebar";
import { ActivistSidebar } from "./activistSidebar";
import { GetRoleFromAuth0 } from "./../auth/getRoleFromAuth0";

import { useAuth0 } from "@auth0/auth0-react";
import { RegisterSidebar } from "./registerSidebar";
import { getPending } from "../../services/allGetServices";

export const AllUserSidebar = () => {
  const { role } = useContext(RollsStatus);
  const { user } = useAuth0();
  const [pending, setPending] = useState(false);

  const handelPending = async () => {
    const result = await getPending(user.email);
    if (result === null) {
      setPending(false);
    } else if (result === false) {
      setPending(true);
    }
  };

  useEffect(() => {
    handelPending();
  }, []);

  return (
    <>
      <GetRoleFromAuth0 />
      {role === "" && !pending && (
        <>
          <RegisterSidebar />
        </>
      )}
      {role === "" && pending && (
        <>
          We will confirm you soon, Please be patient. For any further
          inquiries, you are welcome to contact us via the link above
        </>
      )}
      {role === "Owner" && (
        <>
          <OwnerSidebar />
        </>
      )}
      {role === "N.P.O" && (
        <>
          <NonProfitSidebar />
        </>
      )}
      {role === "company" && (
        <>
          <CompanySidebar />
        </>
      )}
      {role === "Activist" && (
        <>
          <ActivistSidebar />
        </>
      )}
    </>
  );
};
