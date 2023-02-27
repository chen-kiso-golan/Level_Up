import React from "react";
import { useAuth0 } from "@auth0/auth0-react";
import "../sidebar/sidebarStyle.css";

export const Profile = () => {
  const { user, isAuthenticated, isLoading } = useAuth0();
  console.log(user);
  if (isLoading) {
    return <div>Loading ...</div>;
  }

  return (
    isAuthenticated && (
      <div className="profile--background">
        <img
          className="img-profile--background"
          src={user.picture}
          alt={user.name}
        />
        <h2 className="profile--background">{user.name}</h2>
        <p className="profile--background">{user.email}</p>
      </div>
    )
  );
};
