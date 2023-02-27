import React, { useState } from "react";
import { addStudent } from "../../services/student.services";
import { ToastContainer, toast } from "react-toastify";
import "./style.css";

export const Insertstudent = (props) => {
  const [firstName, setFirstName] = useState("");
  const [lastName, setLastName] = useState("");
  const [age, setAge] = useState("");

  const notify_success = () =>
    toast.success("🦄 you add student!", {
      position: "top-left",
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: "light",
    });

  const notify_error = () =>
    toast.error("error: Make sure to fill in all the fields", {
      position: "top-left",
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: "dark",
    });

  const handleAddData = async () => {
    if (firstName == "" || lastName == "" || age == "") {
      notify_error();
    } else {
      let json = { firstName: firstName, lastName: lastName, age: age };
      await addStudent(json);
      notify_success();
    }
  };

  return (
    <div className="container--Insertstudent">
      <div className="input-group">
        <span className="input-group-text" id="addon-wrapping">
          First Name
        </span>
        <input
          type="text"
          className="form-control"
          placeholder="First Name"
          aria-label="Username"
          aria-describedby="addon-wrapping"
          onChange={(o) => setFirstName(o.target.value)}
        />
      </div>
      <div className="input-group">
        <span className="input-group-text" id="addon-wrapping">
          Last Name
        </span>
        <input
          type="text"
          className="form-control"
          placeholder="Last Name"
          aria-label="Username"
          aria-describedby="addon-wrapping"
          onChange={(o) => setLastName(o.target.value)}
        />
      </div>
      <div className="input-group">
        <span className="input-group-text" id="addon-wrapping">
          Age
        </span>
        <input
          type="number"
          className="form-control"
          placeholder="Age"
          aria-label="Username"
          aria-describedby="addon-wrapping"
          onChange={(o) => setAge(o.target.value)}
        />
      </div>
      <input
        className="btn btn-primary"
        type="submit"
        value="Add student"
        onClick={handleAddData}
      ></input>
      <ToastContainer />
    </div>
  );
};
