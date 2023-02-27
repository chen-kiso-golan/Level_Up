import { Route, Routes } from "react-router";
import { AboutPage, HomePage, CartPage, ShoesPage, TshirtPage } from "./pages/allpages";
import "./App.css";
import Navbar from "./components/navbarComponent/navbar";
import { useAuth0 } from "@auth0/auth0-react";
import LoginButton from "./components/auth0/loginBtn/login";
import { CartContext } from "./components/contextComponent/cartContext";
import { themeContext } from "./components/contextComponent/themeContext";
import { useState } from "react";

function App() {
  const { isAuthenticated, isLoading } = useAuth0();
  const [Cart, setCart] = useState([]);
  const [theme, setTheme] = useState(true);

  if (!isAuthenticated) {
    return (
      <div className="circle--body">
        <div className="circle">
          <LoginButton />
        </div>
      </div>
    );
  }

  if (isLoading) {
    return <div>is loading...</div>;
  }

  if (isAuthenticated) {
    return (
      <div className="App">
        <CartContext.Provider value={{ Cart, setCart }}>
          <themeContext.Provider value={{ theme, setTheme }}>
            <header>
              <Navbar></Navbar>
            </header>
            <div className="PagesContent">
              <Routes>
                <Route path="/" element={<HomePage />}></Route>
                <Route path="/about" element={<AboutPage />}></Route>
                <Route path="/shoes" element={<ShoesPage />}></Route>
                <Route path="/tshirt" element={<TshirtPage />}></Route>
                <Route path="/cart" element={<CartPage />}></Route>
              </Routes>
            </div>
          </themeContext.Provider>
        </CartContext.Provider>
      </div>
    );
  }
}

export default App;
