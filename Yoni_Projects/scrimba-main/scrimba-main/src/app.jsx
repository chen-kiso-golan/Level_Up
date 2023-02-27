import React from "react";
import "./app.css";
import { List } from "./componants/list/list";
import { Navbar } from "./componants/navbar/navbar";
import data from "./data";

export function App() {
  const Lists = data.map((item) => {
    return <List key={item.id} {...item} />;
  });

  return (
    <div className="App">
      <Navbar />
      <section className="List">{Lists}</section>
    </div>
  );
}
