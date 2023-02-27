import React, { useState } from "react";
import "./App.css";
import { Routes, Route } from "react-router-dom";
import { AllOrdersReportPage, HomePage, AboutPage, AllCampaignsPage, ContactUsPage, ActivistRegisterFormPage, AllCampaignsReportPageEdit, AllCampaignsReportPage, AllProductsReportPage, AllTwitsReportPage, AllUsersReportPage, CompanyRegisterFormPage, CreatCampaignPage, CreatProductPage, NonprofitRegisterFormPage } from "./pages/pagesIndex";
import TopNavbar from "./components/TopNavbar/TopNavbar";
import SideNavbar from "./components/SideNavbar/SideNavbar";
import ButtomNavbar from "./components/ButtomNavbar/ButtomNavbar";
import { RoleStatus } from "./context/roleStatus";
import { GetRoleFromAuth0 } from "./Auth0/getRoleFromAuth0";
import { useAuth0 } from "@auth0/auth0-react";
import { UserDataContext } from "./context/UserData";
import { TwitterShareButton } from "react-twitter-embed";

function App() {
  const [role, setRole] = useState("");
  const [UserInfo, setUserInfo] = useState("");
  const { isLoading, isAuthenticated } = useAuth0();

  if (!isLoading) {
    if (isAuthenticated) {
      return (
        <RoleStatus.Provider value={{ role, setRole }}>
          <UserDataContext.Provider value={{ UserInfo, setUserInfo }}>
            <div className="App">
              <div>
                <header>
                  <GetRoleFromAuth0 />
                  <TopNavbar />
                </header>
                <div className="app--body">
                  <div className="app--sidebar">
                    <SideNavbar />
                  </div>
                  <div className="app--pageContent">
                    <Routes>
                      <Route path="/" element={<HomePage />}></Route>
                      <Route path="/AllCampaignsPage" element={<AllCampaignsPage />}></Route>
                      <Route path="/ContactUsPage" element={<ContactUsPage />}></Route>
                      <Route path="/AboutPage" element={<AboutPage />}></Route>
                      <Route path="/ActivistRegisterFormPage" element={<ActivistRegisterFormPage />}></Route>
                      <Route path="/AllCampaignsReportPageEdit" element={<AllCampaignsReportPageEdit />}></Route>
                      <Route path="/AllCampaignsReportPage" element={<AllCampaignsReportPage />}></Route>
                      <Route path="/AllProductsReportPage" element={<AllProductsReportPage />}></Route>
                      <Route path="/AllTwitsReportPage" element={<AllTwitsReportPage />}></Route>
                      <Route path="/AllUsersReportPage" element={<AllUsersReportPage />}></Route>
                      <Route path="/AllOrdersReportPage" element={<AllOrdersReportPage />}></Route>
                      <Route path="/CompanyRegisterFormPage" element={<CompanyRegisterFormPage />}></Route>
                      <Route path="/CreatCampaignPage" element={<CreatCampaignPage />}></Route>
                      <Route path="/CreatProductPage" element={<CreatProductPage />}></Route>
                      <Route path="/NonprofitRegisterFormPage" element={<NonprofitRegisterFormPage />}></Route>
                    </Routes>
                  </div>
                </div>
                <footer>
                  <ButtomNavbar />
                </footer>
              </div>
            </div>
          </UserDataContext.Provider>
        </RoleStatus.Provider>
      );
    } else {
      return (
        <div className="App">
          <div>
            <header>
              <TopNavbar />
            </header>
            <div className="app--body">
              <div className="app--sidebar">
                <SideNavbar />
              </div>
              <div className="app--pageContent">
                <Routes>
                  <Route path="/" element={<HomePage />}></Route>
                  <Route path="/AllCampaignsPage" element={<AllCampaignsPage />}></Route>
                  <Route path="/ContactUsPage" element={<ContactUsPage />}></Route>
                  <Route path="/AboutPage" element={<AboutPage />}></Route>
                </Routes>
              </div>
            </div>
            <footer>
              <ButtomNavbar />
            </footer>
          </div>
        </div>
      );
    }
  } else {
    return <h1>loading</h1>;
  }
}

export default App;
