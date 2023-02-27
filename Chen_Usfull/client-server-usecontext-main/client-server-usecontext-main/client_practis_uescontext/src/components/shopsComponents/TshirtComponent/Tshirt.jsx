import React, { useEffect, useState, useContext } from "react";
import Product from "../generalProduct/product";
import { getShirts } from "../../../services/services";
import { CartContext } from "../../contextComponent/cartContext";

function Tshirts() {
  const [tshirtsData, setTshirtsData] = useState([]);
  const { setCart } = useContext(CartContext);

  const HandleTshirtsData = async () => {
    let Data = await getShirts();

    if (Data.status === 200) {
      setTshirtsData(Data.data);
    } else {
      return <div>there is a problem with the DB...</div>;
    }
  };

  useEffect(() => {
    HandleTshirtsData();
  }, []);

  //console.log("hi");
  const handleAddProduct = (product) => {
    setCart((prev) => [...prev, product]);
  };

  return (
    <div className="PageStyle">
      {tshirtsData.length > 0 &&
        tshirtsData.map((tshirt) => {
          return <Product addProduct={() => handleAddProduct(tshirt)} title={tshirt.product_title[0]} description={tshirt.product_title} imageUrl={tshirt.product_main_image_url} price={tshirt.app_sale_price} />;
        })}
    </div>
  );
}

export default Tshirts;
