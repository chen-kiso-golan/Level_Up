import React, { useState } from "react";
import { ToDoList } from "../toDoList/toDoList";

export const AddWorkItem = () => {
  const [userInput, setUserInput] = useState("");
  const [list, setList] = useState([]);

  console.log(event.currentTarget.value);
  const AddTodo = (todo) => {
    const newTodo = {
      id: Math.random(),
      todo: todo,
    };
    //add the todo to the list
    setList([...list, newTodo]);

    //clear input box
    setUserInput("");
  };

  const WhenDone = (id) => {
    const newList = list.filter((todo) => todo.id !== id);
    setList(newList);
    console.log("yoni");
  };

  return (
    <div className="input-group mb-3">
      <div className="input_and_button">
        <input
          type="text"
          className="form-control"
          placeholder="Add new Task"
          aria-label="Recipient's username"
          aria-describedby="button-addon2"
          onChange={(event) => setUserInput(event.currentTarget.value)}
          value={userInput}
        />
        <button
          className="btn btn-outline-secondary"
          type="button"
          id="button-addon2"
          onClick={() => AddTodo(userInput)}
        >
          Add Task
        </button>
      </div>
      <div>
        {list.map((todo) => (
          <ToDoList
            key={todo.id}
            task={todo.todo}
            WhenDone={() => WhenDone(todo.id)}
          />
        ))}
      </div>
    </div>
  );
};
