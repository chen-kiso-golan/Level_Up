using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MiniProject.Data.Sql;
using MiniProject.Model;

namespace MiniProject.Entities
{
    public class ProductManager
    {
       public DataTable ProducTable = new DataTable();

        public void ShowAllProducstFromDB()
        {
            ProducTable.Clear();
            DS_Product dS_Product = new DS_Product();
            ProducTable = dS_Product.SendQueryToGetAllProduct();  
        }

        public void Delete_Product(string productID)
        {
            DS_Product dS_Product = new DS_Product();
            dS_Product.DeleteProduct(productID);
        }

        public void Update_Product(M_Products product)
        {
            DS_Product dS_Product = new DS_Product();
            dS_Product.UpdateProductInDB(product);
        }

    }
}
