import React, { useEffect, useState } from "react";
import "./style.StudentRow.css";
import { removeStudentByName } from "../../services/student.services";

import { getStudents } from "../../services/student.services";
import { ToastContainer, toast } from "react-toastify";

export const StudentRow = (props) => {
  const [studentsArr, setStudentsArr] = useState([]);
  const [Del, setDel] = useState(true);

  const notify_info = () =>
    toast.info("student deleted from list", {
      position: "top-left",
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: "colored",
    });

  const initComponent = async () => {
    let students = await getStudents();
    setStudentsArr(students);
  };

  useEffect(() => {
    initComponent();
  }, [Del]);

  const handleDelete = async (firstName) => {
    notify_info();
    setDel((prev) => !prev);
    await removeStudentByName(firstName);
  };

  return (
    <>
      {studentsArr.length > 0 ? (
        studentsArr.map((s) => {
          let { firstName, lastName, age } = s;
          return (
            <tr className="table">
              <td>{firstName}</td>
              <td>{lastName}</td>
              <td>{age}</td>
              <td>
                <button
                  type="button"
                  className="btn btn-outline-danger"
                  onClick={() => handleDelete(firstName)}
                >
                  remove from list
                </button>
                <ToastContainer />
              </td>
            </tr>
          );
        })
      ) : (
        <h1>loading</h1>
      )}
    </>
  );
};
