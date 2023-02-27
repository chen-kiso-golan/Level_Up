import React from "react";

export const Header = (props) => {
  console.log("shlom");
  return (
    <div>
      <header>
        <img className="image-main" src={props.image} alt="" />
        <h1>{props.title}</h1>
      </header>
      <main>
        <h2>{props.description}</h2>
        <p>
          Lorem ipsum dolor sit amet consectetur, adipisicing elit. Excepturi
          autem, laboriosam minima a error necessitatibus similique quae,
          accusamus, facere deserunt officia tempore ab eum maiores!
        </p>
      </main>
    </div>
  );
};
