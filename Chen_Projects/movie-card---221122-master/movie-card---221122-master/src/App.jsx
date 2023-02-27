import React from "react";

import CardComponent from "./components/CardComponent/cardComponent";
import HadderComponent from "./components/HadderComponent/hadderComponent";
import data from "./data";

function App() {
  const handelCard = data.map((item) => {
    return <CardComponent id={item.id} image={item.image} title={item.title} description={item.description} />;
  });

  return (
    <div className="container">
      <HadderComponent image="../public/images/marvel.jpg" title="Marvel Movies" description="this is my movie list:" />
      {handelCard}
    </div>
  );
}

export default App;
