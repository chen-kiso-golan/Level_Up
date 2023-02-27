// import React, { useState } from "react";
// import { useNavigate } from "react-router-dom";
// import { UpdateProduct } from "../../services/services";

// export const EditProducts = ({ Product }) => {
//   const navigate = useNavigate();

//   const [productName, setProductName] = useState(Product.ProductName);
//   const [unitPrice, setUnitPrice] = useState(Product.unitPrice);
//   const [unitsInStock, setUnitsInStock] = useState(Product.UnitsInStock);
//   const [quantityPerUnit, setQuantityPerUnit] = useState(
//     Product.QuantityPerUnit
//   );

//   const handleSubmit = async (event) => {
//     event.preventDefault();
//     if (
//       productName === "" ||
//       unitPrice === "" ||
//       unitsInStock === "" ||
//       quantityPerUnit === ""
//     ) {
//       alert("Please fill all fields");
//     } else {
//       const updatedProduct = {
//         ...Product,
//         ProductName: productName,
//         UnitPrice: parseFloat(unitPrice),
//         UnitsInStock: parseInt(unitsInStock),
//         QuantityPerUnit: quantityPerUnit,
//       };
//       await UpdateProduct(updatedProduct);
//       alert("Product Was Updated");
//       navigate("/Products");
//     }
//   };

//   const handleReturn = () => {
//     navigate("/Products");
//   };

//   return (
//     <div className="form-container">
//       <form onSubmit={handleSubmit}>
//         <div className="form-group">
//           <label htmlFor="productID" className="frm-lbl">
//             Product ID:
//           </label>
//           <input
//             readOnly
//             type="number"
//             className="form-control"
//             id="productID"
//             defaultValue={Product.ProductID}
//           />
//         </div>
//         <div className="form-group">
//           <label htmlFor="productName" className="frm-lbl">
//             Product Name:
//           </label>
//           <input
//             type="text"
//             className="form-control"
//             id="productName"
//             value={productName}
//             onChange={(event) => setProductName(event.target.value)}
//           />
//         </div>
//         <div className="form-group">
//           <label htmlFor="unitPrice" className="frm-lbl">
//             Unit Price:
//           </label>
//           <input
//             type="number"
//             className="form-control"
//             id="unitPrice"
//             value={unitPrice}
//             onChange={(event) => setUnitPrice(event.target.value)}
//           />
//         </div>
//         <div className="form-group">
//           <label htmlFor="unitsInStock" className="frm-lbl">
//             Units In Stock:
//           </label>
//           <input
//             type="number"
//             className="form-control"
//             id="unitsInStock"
//             value={unitsInStock}
//             onChange={(event) => setUnitsInStock(event.target.value)}
//           />
//         </div>
//         <div className="form-group">
//           <label htmlFor="quantityPerUnit" className="frm-lbl">
//             Quantity Per Unit:
//           </label>
//           <input
//             type="text"
//             className="form-control"
//             id="quantityPerUnit"
//             value={quantityPerUnit}
//             onChange={(event) => setQuantityPerUnit(event.target.value)}
//           />
//         </div>
//         <div>
//           <button type="submit" className="btn btn-primary">
//             Submit
//           </button>
//           <button
//             type="submit"
//             className="btn btn-danger"
//             onClick={handleReturn}
//           >
//             Return
//           </button>
//         </div>
//       </form>
//     </div>
//   );
// };
