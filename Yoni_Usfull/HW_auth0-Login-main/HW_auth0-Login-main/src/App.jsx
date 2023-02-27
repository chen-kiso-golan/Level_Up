import React from "react";

import "./App.css";

import { Sidebar } from "./components/sidebar/sidebar.component";
import { Routes, Route } from "react-router-dom";
import {
  AboutPage,
  ContactUsPage,
  GamesPage,
  HomePage,
  MoviesPage,
  NotFoundPage,
} from "./pages/page.index";
import { useAuth0 } from "@auth0/auth0-react";
import DesignedLogin from "../src/components/auth/designedLogin";

function App() {
  const { loginWithRedirect, isAuthenticated, isLoading } = useAuth0();

  if (!isAuthenticated) {
    console.log("i am stuck in a loop");
    return (
      <div>
        <DesignedLogin />
      </div>
    );
  }

  if (isLoading) {
    return <div>Loading ...</div>;
  }
  return (
    <div className="page-order">
      <header>
        <Sidebar />
      </header>

      <div className="pageContent">
        <Routes>
          <Route path="/" element={<HomePage />}></Route>
          <Route path="/about" element={<AboutPage />}></Route>
          <Route path="/contactUs" element={<ContactUsPage />}></Route>
          <Route path="/games" element={<GamesPage />}></Route>
          <Route path="/movies" element={<MoviesPage />}></Route>
          <Route path="/notfound" element={<NotFoundPage />}></Route>
        </Routes>
      </div>
    </div>
  );
}

export default App;
