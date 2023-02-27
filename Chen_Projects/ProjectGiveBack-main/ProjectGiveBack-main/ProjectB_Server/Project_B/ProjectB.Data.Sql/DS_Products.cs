using ProjectB.Dal;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Data.Sql
{
    public class DS_Products: BaseDataSql
    {
        BaseDAL BaseDAL;
        public DS_Products(LogManager log) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
        }


        public DataTable ReadAllProductsFromDB()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Products \ ReadAllProductsFromDB ran Successfully - ");
                string SQLquery = "select * from Products";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }



        public void EnterProductToDB(ProductsModel form)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Products \ EnterProductToDB ran Successfully - ");
                string SQLquery = "insert into Products values ('" + form.Name + "','" + form.Price + "','" + form.Units_In_Stock + "' ,'" + form.BC_code + "','" + form.Campaign_code + "','" + form.Image + "')";
                SqlDB.WriteToDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }

    }
}
