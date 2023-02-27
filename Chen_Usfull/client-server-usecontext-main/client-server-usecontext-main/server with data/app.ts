import cors from "cors";
import express, { Request, Response } from "express";
import { ShoesDatabase } from "./data/shoes.database";
import { TshirtDatabase } from "./data/tshirt.database";

const app = express();
app.use(express.json());
app.use(cors());

app.get("/api/tshirts", (req: Request, res: Response) => {
  res.send(TshirtDatabase);
});
app.get("/api/shoes", (req: Request, res: Response) => {
  res.send(ShoesDatabase);
});

app.listen(4000, () => {
  console.log("server running over 4000");
});
