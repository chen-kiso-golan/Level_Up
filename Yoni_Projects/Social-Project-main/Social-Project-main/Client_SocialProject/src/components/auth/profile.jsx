import React from "react";
import { useAuth0 } from "@auth0/auth0-react";
import "../Navbar/AllNavbar.css";

export const Profile = () => {
  const { user } = useAuth0();

  return (
    <div className="profile--div-background">
      <img className="img-profile" src={user.picture} alt={user.name} />
      <h2 className="profile--background profile--name">{user.name}</h2>
      <p className="profile--background profile--email">{user.email}</p>
    </div>
  );
};
