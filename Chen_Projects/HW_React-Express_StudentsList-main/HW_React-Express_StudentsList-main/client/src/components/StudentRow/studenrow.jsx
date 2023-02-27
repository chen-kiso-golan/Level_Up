import React, { useState } from "react";
import "bootstrap/dist/css/bootstrap.css";
import "./studentrow.css";
import { removeStudentByName } from "../../services/student.services";
import { ToastContainer, toast } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";

function StudenRow(props) {
  //   const [firstName, setFirstName] = useState("");

  const notify_info = () =>
    toast.info("🦄 student deleted from list", {
      position: "top-center",
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: "colored",
    });

  const handleDelete = async () => {
    // await setFirstName(props.firstName);
    notify_info();
    await removeStudentByName(props.firstName);
  };

  return (
    <tr className="table">
      <td>{props.firstName}</td>
      <td>{props.lastName}</td>
      <td>{props.age}</td>
      <td>
        <button onClick={() => handleDelete()} type="button" className="btn btn-outline-danger">
          remove from list
        </button>
        <ToastContainer />
      </td>
    </tr>
  );
}

export default StudenRow;
