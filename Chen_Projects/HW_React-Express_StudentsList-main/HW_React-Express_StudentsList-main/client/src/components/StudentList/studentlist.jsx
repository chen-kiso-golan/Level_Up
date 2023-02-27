import React, { useEffect, useState } from "react";
import "bootstrap/dist/css/bootstrap.css";
import "./studentlist.css";
import StudenRow from "../StudentRow/studenrow";
import { getStudents } from "./../../services/student.services";

function StudentList(props) {
  const [studentsArr, setStudentsArr] = useState([]);

  const initComponent = async () => {
    let students = await getStudents();
    setStudentsArr(students);
  };

  useEffect(() => {
    initComponent();
  }, []);

  return (
    <div className="table--all">
      <table className="table">
        <thead>
          <tr>
            <th scope="col">First Name</th>
            <th scope="col">Last Name</th>
            <th scope="col">Age</th>
            <th scope="col"></th>
          </tr>
        </thead>
        <tbody>
          {studentsArr.length > 0 ? (
            studentsArr.map((s) => {
              let { firstName, lastName, age } = s;
              return <StudenRow firstName={firstName} lastName={lastName} age={age} />;
            })
          ) : (
            <p>loading</p>
          )}
        </tbody>
      </table>
    </div>
  );
}

export default StudentList;
