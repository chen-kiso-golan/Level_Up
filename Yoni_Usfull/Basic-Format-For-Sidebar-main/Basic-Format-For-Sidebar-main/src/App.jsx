import React from "react";
import "./App.css";

import { Routes, Route } from "react-router-dom";
import {
  AboutPage,
  ContactUsPage,
  GamesPage,
  HomePage,
  MoviesPage,
  NotFoundPage,
} from "./pages/page.index";
import { Sidebar } from "./components/sidebar/sidebar.component";

function App() {
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
