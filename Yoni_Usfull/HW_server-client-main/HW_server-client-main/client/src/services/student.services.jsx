import axios from "axios";

export const getStudents = async () => {
  let result = await fetch("http://localhost:3000/api/students");
  let arrayOfStudents = await result.json();
  return arrayOfStudents;
};

export const addStudent = async (student) => {
  await axios.post("http://localhost:3000/api/students", student);
};

export const removeStudentByName = async (firstName) => {
  await axios.delete(`http://localhost:3000/api/students/${firstName}`);
};
