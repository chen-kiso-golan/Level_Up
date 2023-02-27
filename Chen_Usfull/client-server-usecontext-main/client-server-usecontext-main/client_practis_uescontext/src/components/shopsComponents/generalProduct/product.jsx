import React from "react";
import "bootstrap/dist/css/bootstrap.css";
import "./productStyle.css";

function Product({ title, description, imageUrl, price, addProduct }) {
  return (
    <div className="myCard">
      <div className="card">
        <img width={20} height={220} src={imageUrl} className="card-img-top" alt="..." />
        <div className="card-body">
          <h5 className="card-title">
            {title} - {price}$
          </h5>
          <p className="card-text">{description}</p>
          <button onClick={addProduct} className="btn btn-primary buyButton">
            Add To Card
          </button>
        </div>
      </div>
    </div>
  );
}

export default Product;
