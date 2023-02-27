import React, { useContext } from "react";
import { Link } from "react-router-dom";
import KeyboardArrowRightIcon from "@mui/icons-material/KeyboardArrowRight";
import "./SideNavbar.css";
import { RoleStatus } from "../../context/roleStatus";
import Profile from "../../Auth0/Profile";
import { useAuth0 } from "@auth0/auth0-react";
import { UserDataContext } from "./../../context/UserData";

function SideNavbar(props) {
  const { role, setRole } = useContext(RoleStatus);
  const { UserInfo } = useContext(UserDataContext);
  const { isAuthenticated } = useAuth0();
  console.log(role);
  //     if (role === "Owner" || role === "NPO" || role === "BC" || role === "SA")

  return (
    <div className="sidenavbar--container">
      <ul className="sidenavbar--menu">
        <li>welcome, here is your {role} account menu:</li>
        <br />

        <li>
          <Profile />
        </li>
        <br />
        {!isAuthenticated && <li>login with the buttom above!</li>}
        {role === "" && isAuthenticated && (
          <>
            <li>signup to the website so you could see more options...</li>
            <li>------</li>
            <li>
              <Link to="/ActivistRegisterFormPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">Activist Register Form</label>
              </Link>
            </li>
            <li>
              <Link to="/CompanyRegisterFormPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">Company Register Form</label>
              </Link>
            </li>
            <li>
              <Link to="/NonprofitRegisterFormPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">Nonprofit Register Form</label>
              </Link>
            </li>
          </>
        )}
        {role === "Owner" && (
          <>
            <li>
              <Link to="/AllUsersReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Users Report</label>
              </Link>
            </li>

            <li>
              <Link to="/AllCampaignsReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Campaigns Report</label>
              </Link>
            </li>
            <li>
              <Link to="/AllProductsReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Products Report</label>
              </Link>
            </li>
            <li>
              <Link to="/AllTwitsReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Twits Report</label>
              </Link>
            </li>
            <li>
              <Link to="/AllOrdersReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Orders Report</label>
              </Link>
            </li>
          </>
        )}
        {role === "NPO" && (
          <>
            <li>
              <Link to="/CreatCampaignPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">Creat Campaign</label>
              </Link>
            </li>
            <li>
              <Link to="/AllTwitsReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Twits Report</label>
              </Link>
            </li>
            <li>
              <Link to="/AllCampaignsReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Campaigns Report</label>
              </Link>
            </li>
          </>
        )}
        {role === "BC" && (
          <>
            <li>
              <Link to="/AllProductsReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Products Report</label>
              </Link>
            </li>
            <li>
              <Link to="/AllOrdersReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Orders Report</label>
              </Link>
            </li>
            <li>
              <Link to="/CreatProductPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">Creat Product</label>
              </Link>
            </li>
          </>
        )}
        {role === "SA" && (
          <>
            <li>
              <label className="label--sidenavbar">Your Money: {UserInfo.Money}$</label>
            </li>
            <br />
            <li>
              <Link to="/AllProductsReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Products Report</label>
              </Link>
            </li>
            <li>
              <Link to="/AllTwitsReportPage">
                <KeyboardArrowRightIcon />
                <label className="label--sidenavbar">All Twits Report</label>
              </Link>
            </li>
          </>
        )}
      </ul>
    </div>
  );
}

export default SideNavbar;
