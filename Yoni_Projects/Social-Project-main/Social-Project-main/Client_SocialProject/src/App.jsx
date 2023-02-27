import React, { useState } from "react";
import { Routes, Route } from "react-router-dom";
import { ThemeContext } from "./context/theme.context";
import { RollsStatus } from "./context/rollsStatus";
import { UserDataContext } from "./context/userData";
import { useAuth0 } from "@auth0/auth0-react";

import {
  AllUserSidebar,
  BottomNavbar,
  TopNavbar,
} from "./components/components.index";

import {
  AboutPage,
  ContactUsPage,
  HomePage,
  RegisterPage,
  RegisterTypeFormPage,
  PendingRegistrationListPage,
  TwitterInfoPage,
  AllUsersTablePage,
  CampaignsTablePage,
  EditCampaignsPage,
  CampaignsTableNPOPage,
  CampaignsCardNPOPage,
  EditOrAddProductPage,
  ProductTablePage,
  MyProductTablePage,
  OrderTablePage,
} from "./pages/page.index";
import "./App.css";

function App() {
  const { isAuthenticated, isLoading } = useAuth0();
  const [theme, setTheme] = useState(true);
  const [role, setRole] = useState("");
  const [userInfo, setUserInfo] = useState({});
  if (!isLoading) {
    if (isAuthenticated) {
      return (
        <ThemeContext.Provider value={{ theme, setTheme }}>
          <RollsStatus.Provider value={{ role, setRole }}>
            <UserDataContext.Provider value={{ userInfo, setUserInfo }}>
              <div
                className={`App--${
                  theme ? "Accessibility" : "CancelAccessibility"
                }`}
              >
                <header>
                  <TopNavbar />
                </header>
                <div className="App--AllUserSidebar">
                  <AllUserSidebar />
                </div>
                <div className="App--Routes">
                  <Routes>
                    <Route path="/" element={<HomePage />}></Route>
                    <Route path="/about" element={<AboutPage />}></Route>
                    <Route
                      path="/contactUs"
                      element={<ContactUsPage />}
                    ></Route>
                    <Route path="/register" element={<RegisterPage />}></Route>
                    <Route
                      path="/registerTypeForm"
                      element={<RegisterTypeFormPage />}
                    ></Route>
                    <Route
                      path="/PendingRegistrationList"
                      element={<PendingRegistrationListPage />}
                    ></Route>
                    <Route
                      path="/twitterInfo"
                      element={<TwitterInfoPage />}
                    ></Route>
                    <Route
                      path="/allUsersTable"
                      element={<AllUsersTablePage />}
                    ></Route>
                    <Route
                      path="/campaignsTable"
                      element={<CampaignsTablePage />}
                    ></Route>
                    <Route
                      path="/edit-Campaigns"
                      element={<EditCampaignsPage />}
                    ></Route>
                    <Route
                      path="/campaignsTableNPO"
                      element={<CampaignsTableNPOPage />}
                    ></Route>
                    <Route
                      path="/campaignsCardNPO"
                      element={<CampaignsCardNPOPage />}
                    ></Route>
                    <Route
                      path="/editOrAddProduct"
                      element={<EditOrAddProductPage />}
                    ></Route>
                    <Route
                      path="/productTable"
                      element={<ProductTablePage />}
                    ></Route>
                    <Route
                      path="/myProductTable"
                      element={<MyProductTablePage />}
                    ></Route>
                    <Route
                      path="/orderTable"
                      element={<OrderTablePage />}
                    ></Route>
                  </Routes>
                </div>
                <footer>
                  <BottomNavbar />
                </footer>
              </div>
            </UserDataContext.Provider>
          </RollsStatus.Provider>
        </ThemeContext.Provider>
      );
    } else {
      return (
        <ThemeContext.Provider value={{ theme, setTheme }}>
          <div
            className={`App--${
              theme ? "Accessibility" : "CancelAccessibility"
            }`}
          >
            <header>
              <TopNavbar />
            </header>
            <div className="App--Routes">
              <Routes>
                <Route path="/" element={<HomePage />}></Route>
                <Route path="/about" element={<AboutPage />}></Route>
                <Route path="/contactUs" element={<ContactUsPage />}></Route>
                <Route path="/register" element={<RegisterPage />}></Route>
                <Route
                  path="/registerTypeForm"
                  element={<RegisterTypeFormPage />}
                ></Route>
                <Route
                  path="/PendingRegistrationList"
                  element={<PendingRegistrationListPage />}
                ></Route>
              </Routes>
            </div>
            <footer>
              <BottomNavbar />
            </footer>
          </div>
        </ThemeContext.Provider>
      );
    }
  } else {
    return <h1>loading</h1>;
  }
}

export default App;
