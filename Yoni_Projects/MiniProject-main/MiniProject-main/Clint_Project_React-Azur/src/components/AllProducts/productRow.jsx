import React, { useState, useEffect } from "react";
import { deleteProduct, getData } from "../../services/services";
import { useNavigate } from "react-router-dom";

export const ProductRow = (props) => {
  const [AllProducts, setAllProducts] = useState([]);
  const [expand, setExpand] = useState(false);
  const [key, setKey] = useState(null);

  const navigate = useNavigate();

  const getDB = async () => {
    let result = await getData();
    console.log("hi");
    setAllProducts(result.data);
  };

  useEffect(() => {
    getDB();
  }, []);

  const handleClick = (proKey) => {
    setExpand(!expand);
    setKey(proKey);
  };

  const handleUpdate = (Product) => {
    navigate("/edit-Products", {
      state: {
        Product,
      },
    });
  };

  const handleDelete = async (productID) => {
    await deleteProduct(productID);
    setExpand(!expand);
    getDB();
  };

  return (
    <>
      {AllProducts.length > 0 ? (
        AllProducts.map((item) => {
          let { ProductID, ProductName, UnitPrice, UnitsInStock } = item;
          return (
            <>
              <tr onClick={() => handleClick(item.ProductID)}>
                <th scope="row">{ProductID}</th>
                <td>{ProductName}</td>
                <td>{UnitPrice}$</td>
                <td>{UnitsInStock}</td>
              </tr>
              {expand && item.ProductID === key ? (
                <tr>
                  <td>
                    <button
                      className="btn btn-warning"
                      onClick={() => {
                        handleUpdate(item);
                      }}
                    >
                      Edit Item
                    </button>
                  </td>
                  <td colSpan={2}>
                    <h5>{item.ProductName} Description : </h5>
                    QuantityPerUnit:{item.QuantityPerUnit}
                  </td>
                  <td>
                    <button
                      className="btn btn-danger"
                      onClick={() => {
                        handleDelete(item.ProductID);
                      }}
                    >
                      Remove Item
                    </button>
                  </td>
                </tr>
              ) : null}
            </>
          );
        })
      ) : (
        <h1>loading</h1>
      )}
    </>
  );
};

{
  /* <td>{SupplierID}</td>
              <td>{CategoryID}</td>
              <td>{QuantityPerUnit}</td>
              <td>{UnitsOnOrder}</td>
              <td>{ReorderLevel}</td>
              <td>{Discontinued}</td> */
}
