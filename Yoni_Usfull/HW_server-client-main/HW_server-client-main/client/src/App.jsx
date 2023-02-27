import React from "react";
import "./App.css";
import "bootstrap/dist/css/bootstrap.css";

import "react-toastify/dist/ReactToastify.css";
import { Navbar } from "./components/Navbar/navbar";

import { Routes, Route } from "react-router-dom";
import { AddStudentPage, HomePage, NotFoundPage } from "./pages/page.index";

function App() {
  return (
    <div className="App">
      <header>
        <Navbar></Navbar>
      </header>
      <div>
        <Routes>
          <Route path="/" element={<HomePage />}></Route>
          <Route path="/notfound" element={<NotFoundPage />}></Route>
          <Route path="/AddStudent" element={<AddStudentPage />}></Route>
        </Routes>
      </div>
    </div>
  );
}

export default App;
