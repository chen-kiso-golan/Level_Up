import React, { useState } from "react";

import { Sidebar } from "./components/sidebar/sidebar.component";
import { Routes, Route } from "react-router-dom";
import {
  AboutPage,
  ContactUsPage,
  HomePage,
  ProductsPage,
  NotFoundPage,
  EditProductsPage,
} from "./pages/page.index";

import { useAuth0 } from "@auth0/auth0-react";
import DesignedLogin from "../src/components/auth/designedLogin";
import { ThemeContext } from "./context/theme.context";

import "./App.css";
import "react-toastify/dist/ReactToastify.css";

function App() {
  const { isAuthenticated, isLoading } = useAuth0();
  const [theme, setTheme] = useState(true);

  if (!isAuthenticated) {
    return (
      <div>
        <DesignedLogin />
      </div>
    );
  }

  if (isLoading) {
    return <div>Loading ...</div>;
  }
  return (
    <ThemeContext.Provider value={{ theme, setTheme }}>
      <div className={`page-order po-${theme ? "light" : "dark"}`}>
        <header>
          <Sidebar />
        </header>
        <div className="pageContent">
          <Routes>
            <Route path="/" element={<HomePage />}></Route>
            <Route path="/about" element={<AboutPage />}></Route>
            <Route path="/contactUs" element={<ContactUsPage />}></Route>
            <Route path="/Products" element={<ProductsPage />}></Route>
            <Route path="/edit-Products" element={<EditProductsPage />}></Route>
            <Route path="/notfound" element={<NotFoundPage />}></Route>
          </Routes>
        </div>
      </div>
    </ThemeContext.Provider>
  );
}

export default App;
