import express, { Request, Response } from "express";
import { arrayOfStudent, Student } from "./DataBase/studentArray";
import { logger } from "./myMiddleware";
import cors from "cors";

const app = express();
app.use(cors());
app.use(express.json());
app.use(logger);
let data = arrayOfStudent;

app.get("/", function (req: Request, res: Response) {
  res.send("Hello World");
});

app.get("/api/students", function (req: Request, res: Response) {
  console.log("handle request");
  let students = data;
  res.send(students);
});

app.post("/api/students", function (req: Request, res: Response) {
  let student: Student = {
    firstName: req.body.firstName,
    lastName: req.body.lastName,
    age: req.body.age,
  };
  data.push(student);
  res.send(student);
});

app.delete("/api/students/:firstName", function (req: Request, res: Response) {
  let firstName = req.params.firstName;
  let temp = data.filter((s) => s.firstName !== firstName);
  data = temp;
  res.send();
});

app.listen(3000, () => {
  console.log("app is running");
});
