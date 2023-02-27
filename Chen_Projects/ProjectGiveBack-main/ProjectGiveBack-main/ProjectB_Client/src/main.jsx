import React from "react";
import ReactDOM from "react-dom/client";
import { BrowserRouter } from "react-router-dom";
import { Auth0Provider } from "@auth0/auth0-react";
import App from "./App";
import "./index.css";
import "../node_modules/bootstrap/dist/css/bootstrap.css";
import "react-toastify/dist/ReactToastify.css";
import { TwitterTimelineEmbed, TwitterShareButton, TwitterFollowButton, TwitterHashtagButton, TwitterMentionButton, TwitterTweetEmbed, TwitterMomentShare, TwitterDMButton, TwitterVideoEmbed, TwitterOnAirButton } from "react-twitter-embed";

ReactDOM.createRoot(document.getElementById("root")).render(
  <React.StrictMode>
    <BrowserRouter>
      <Auth0Provider domain="dev-bexlompeu36s5051.us.auth0.com" clientId="QH8X1oVJliqDHySN6YbA4RSR7mHoggp3" redirectUri={window.location.origin}>
        <App />
      </Auth0Provider>
    </BrowserRouter>
  </React.StrictMode>
);
