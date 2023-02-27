import React from "react";
import { useAuth0 } from "@auth0/auth0-react";
import "./login.css";

const LoginButton = () => {
  const { loginWithRedirect } = useAuth0();

  return (
    <div>
      <button className="circle--loginbtn" onClick={() => loginWithRedirect()}>
        Login
      </button>
    </div>
  );
};

export default LoginButton;
