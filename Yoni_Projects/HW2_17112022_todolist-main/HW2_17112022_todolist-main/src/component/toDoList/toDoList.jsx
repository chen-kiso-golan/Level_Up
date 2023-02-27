import React from "react";

export const ToDoList = (props) => {
  return (
    <div className="card">
      <div className="card-header">Task</div>
      <div className="card-body">
        <h5 className="card-title">{props.task}</h5>

        <button className="btn btn-primary" onClick={() => props.WhenDone()}>
          Done
        </button>
      </div>
    </div>
  );
};
