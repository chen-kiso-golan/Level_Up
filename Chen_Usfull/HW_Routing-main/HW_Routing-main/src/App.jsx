import { Routes, Route } from "react-router-dom";
import { About, ContactUs, Games, Home, Movies, NotFound } from "./pages/pagesIndex";
import { Sidebar } from "./components/sidebar/sidebar";
import "./App.css";

function App() {
  return (
    <div className="page-order">
      <header>
        <Sidebar />
      </header>
      <div className="pageContent">
        <Routes>
          <Route path="/" element={<Home />}></Route>
          <Route path="/about" element={<About />}></Route>
          <Route path="/contactus" element={<ContactUs />}></Route>
          <Route path="/games" element={<Games />}></Route>
          <Route path="/movies" element={<Movies />}></Route>
          <Route path="/notfound" element={<NotFound />}></Route>
        </Routes>
      </div>
    </div>
  );
}

export default App;
