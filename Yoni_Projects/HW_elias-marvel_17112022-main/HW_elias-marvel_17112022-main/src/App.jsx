import React from "react";

import { Card } from "./components/card";
import { Header } from "./components/header";
import data from "../server/data";

function App() {
  const handelCard = data.map((item) => {
    return (
      <Card
        key={item.id}
        image={item.image}
        title={item.title}
        description={item.description}
      />
    );
  });

  return (
    <div className="container">
      <Header
        image="../public/images/marvel.jpg"
        title="Marvel Movies"
        description="this is my movie list:"
      />
      {handelCard}
    </div>
  );
}

export default App;
