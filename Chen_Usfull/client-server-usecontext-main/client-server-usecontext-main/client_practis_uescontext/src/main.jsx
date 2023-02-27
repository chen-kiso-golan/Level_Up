import React from "react";
import ReactDOM from "react-dom/client";
import { BrowserRouter } from "react-router-dom";
import { Auth0Provider } from "@auth0/auth0-react";
import App from "./App";
import "./index.css";
import "../node_modules/bootstrap/dist/css/bootstrap.css";

ReactDOM.createRoot(document.getElementById("root")).render(
  <React.StrictMode>
    <BrowserRouter>
      <Auth0Provider domain="dev-bexlompeu36s5051.us.auth0.com" clientId="O1B4uxX5cBkxgPNXorWMfPzFFnzbT5Lh" redirectUri={window.location.origin}>
        <App />
      </Auth0Provider>
    </BrowserRouter>
  </React.StrictMode>
);
