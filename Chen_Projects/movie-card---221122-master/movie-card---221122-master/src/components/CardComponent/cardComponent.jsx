import React from "react";

function CardComponent(props) {
  return (
    <div>
      <ul className="list-style">
        <li className="list-item-container">
          <img className="list-image" src={props.image} alt="" srcset="" />
          <div className="content">
            <h2>{props.title}</h2>
            <p>{props.description}</p>
          </div>
        </li>
      </ul>
    </div>
  );
}

export default CardComponent;
