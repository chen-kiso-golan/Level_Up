import React, { useState } from "react";
import "bootstrap/dist/css/bootstrap.css";
import "./inputs.css";
import { addStudent } from "../../services/student.services";
import { ToastContainer, toast } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";

function Inputs() {
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
    toast.warn("error: 🦄 Make sure to fill in all the fields", {
      position: "top-right",
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: "light",
    });

  const handleAddData = async () => {
    if (firstName == "" || lastName == "" || age == "") {
      notify_error();
    } else {
      let newStudent = { firstName: firstName, lastName: lastName, age: age };
      await addStudent(newStudent);
      notify_success();
    }
  };

  return (
    <div className="container--all">
      <div className="input-group flex-nowrap">
        <span className="input-group-text" id="addon-wrapping">
          First Name:
        </span>
        <input onChange={(o) => setFirstName(o.target.value)} type="text" className="form-control" placeholder="write your first name here..." aria-label="Username" aria-describedby="addon-wrapping" />
      </div>
      <div className="input-group flex-nowrap">
        <span className="input-group-text" id="addon-wrapping">
          Last Name:
        </span>
        <input onChange={(o) => setLastName(o.target.value)} type="text" className="form-control" placeholder="write your last name here..." aria-label="Username" aria-describedby="addon-wrapping" />
      </div>
      <div className="input-group flex-nowrap">
        <span className="input-group-text" id="addon-wrapping">
          Age:
        </span>
        <input onChange={(o) => setAge(o.target.value)} type="number" className="form-control" placeholder="write your age here..." aria-label="Username" aria-describedby="addon-wrapping" />
      </div>
      <input onClick={handleAddData} className="btn btn-primary" type="submit" value="Submit"></input>
      <ToastContainer />
    </div>
  );
}

export default Inputs;
