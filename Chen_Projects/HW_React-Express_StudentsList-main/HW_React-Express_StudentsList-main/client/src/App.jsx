import "./App.css";
import React from "react";
import Inputs from "./components/InsertStudent/inputs";
import Navbar from "./components/Navbar/navbar";
import StudentList from "./components/StudentList/studentlist";
import { Routes, Route } from "react-router-dom";

function App() {
  return (
    <div className="App">
      <header>
        <Navbar />
      </header>
      <div>
        <Routes>
          <Route path="/" element={<StudentList />}></Route>
          <Route path="/addstudent" element={<Inputs />}></Route>
        </Routes>
      </div>
    </div>
  );
}

export default App;
