using ProjectB.Data.Sql;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities
{
    public class ProductsManager: BaseEntity
    {
        BaseDataSql BaseDataSql;
        public ProductsManager(LogManager log) : base(log) 
        {
            BaseDataSql = new BaseDataSql(Log);
        }



        public DataTable ProductsTable = new DataTable();
        public DataTable ShowAllProductsFromDB()
        {
            try
            {
                Log.LogEvent(@"Entities \ ProductsManager \ ShowAllProductsFromDB ran Successfully - ");
                ProductsTable.Clear();
                DS_Products DS_Products = new DS_Products(Log);
                return ProductsTable = DS_Products.ReadAllProductsFromDB();
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return ProductsTable;
        }


        public void SendProductToDB(ProductsModel form)
        {
            try
            {
                Log.LogEvent(@"Entities \ ProductsManager \ SendProductToDB ran Successfully - ");
                DS_Products DS_Products = new DS_Products(Log);
                DS_Products.EnterProductToDB(form);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
