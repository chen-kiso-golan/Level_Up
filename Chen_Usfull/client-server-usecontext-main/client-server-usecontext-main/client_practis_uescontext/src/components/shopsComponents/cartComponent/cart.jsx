import React, { useContext } from "react";
import { CartContext } from "../../contextComponent/cartContext";
import Product from "../generalProduct/product";

function Cart(props) {
  const { Cart } = useContext(CartContext);

  return (
    <div className="PageStyle">
      {Cart &&
        Cart.length > 0 &&
        Cart.map((c) => {
          return <Product title={c.product_title[0]} description={c.product_title} price={c.app_sale_price} imageUrl={c.product_main_image_url}></Product>;
        })}
    </div>
  );
}

export default Cart;
