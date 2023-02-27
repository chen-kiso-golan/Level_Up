import React from "react";
import "./styleStudentList.css";
import { StudentRow } from "../StudentRow/studentRow";

export const StudentList = (props) => {
  return (
    <div className="table--all">
      <table className="table">
        <thead>
          <tr>
            <th scope="col">First Name</th>
            <th scope="col">Last Name</th>
            <th scope="col">Age</th>
            <th scope="col">Operation</th>
          </tr>
        </thead>
        <tbody>
          <StudentRow />
        </tbody>
      </table>
    </div>
  );
};
