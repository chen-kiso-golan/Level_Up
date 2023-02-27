import axios from "axios";

export const getStudents = async () => {
  let result = await fetch("http://localhost:3000/api/students");
  let arrayOfStudents = await result.json();
  return arrayOfStudents;
  //   await axios.get("http://localhost:3000/api/students");
};

export const addStudent = async (newStudent) => {
  await axios.post("http://localhost:3000/api/students", newStudent);
};

export const removeStudentByName = async (firstName) => {
  await axios.delete(`http://localhost:3000/api/students/${firstName}`);
};
