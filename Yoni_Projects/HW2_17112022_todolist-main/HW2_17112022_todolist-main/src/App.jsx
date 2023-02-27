import React, { useState } from "react";
import "bootstrap/dist/css/bootstrap.css";

import { AddWorkItem } from "./component/addWorkItem/addWorkItem";

function App() {
  return (
    <div className="container">
      <h1>Today work item that should be done</h1>
      <AddWorkItem />
    </div>
  );
}

export default App;
