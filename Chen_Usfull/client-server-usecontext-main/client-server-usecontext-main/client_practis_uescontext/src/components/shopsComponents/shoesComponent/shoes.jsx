import React, { useEffect, useState, useContext } from "react";
import Product from "../generalProduct/product";
import { getShoes } from "../../../services/services";
import { CartContext } from "../../contextComponent/cartContext";
import "../../../pages/PageStyle.css";

function Shoes() {
  const [shoesData, setShoesData] = useState([]);
  const { setCart } = useContext(CartContext);

  const HandleShoesData = async () => {
    let Data = await getShoes();

    if (Data.status === 200) {
      setShoesData(Data.data);
    } else {
      return <div>there is a problem with the DB...</div>;
    }
  };

  useEffect(() => {
    HandleShoesData();
  }, []);

  const handleAddProduct = (product) => {
    setCart((prev) => [...prev, product]);
  };

  return (
    <div className="PageStyle">
      {shoesData.length > 0 &&
        shoesData.map((shoe) => {
          return <Product addProduct={() => handleAddProduct(shoe)} title={shoe.product_title[0]} description={shoe.product_title} imageUrl={shoe.product_main_image_url} price={shoe.app_sale_price} />;
        })}
    </div>
  );
}

export default Shoes;
