using MiniProject.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MiniProject.Data.Sql
{
    public class DS_Product
    {
        public DataTable SendQueryToGetAllProduct()
        {
           return MiniProject.Dal.SqlQuery.ReadTableFormDB("select * from products");
        }
        public void DeleteProduct(string productID)
        {
            string deleteQuery = "delete from Products where ProductID = " + productID;
            MiniProject.Dal.SqlQuery.WriteToDB(deleteQuery);
        }
        public void UpdateProductInDB(M_Products product)
        {
            string updateQuery = "update Products set ProductName = '" + product.ProductName + "', QuantityPerUnit = '" + product.QuantityPerUnit + "', UnitPrice = " + product.UnitPrice.ToString() + ", UnitsInStock = " + product.UnitsInStock.ToString() + " where ProductID = " + product.ProductID.ToString();
            MiniProject.Dal.SqlQuery.WriteToDB(updateQuery);
        }
    }
}
