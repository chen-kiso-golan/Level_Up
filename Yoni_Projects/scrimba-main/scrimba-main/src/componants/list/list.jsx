import React from "react";
import "./list.css";

export const List = (props) => {
  return (
    <div className="List">
      <div className="OneList">
        <img src={props.imageUrl} className="List--image" />
        <div className="List--text">
          <div className="ListLocationAndMaps">
            <p className="List--location">{props.location}</p>
            <a href={props.googleMapsUrl}>view on google maps</a>
          </div>
          <h1 className="List--title">{props.title}</h1>
          <br />
          <h4 className="List--date">{`${props.startDate} - ${props.endDate}`}</h4>
          <p className="List--description">{props.description}</p>
        </div>
      </div>
    </div>
  );
};
