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
    public class DS_Orders: BaseDataSql
    {
        BaseDAL BaseDAL;
        public DS_Orders(LogManager log) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
        }

        public DataTable ReadAllOrdersFromDB()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Orders \ ReadAllOrdersFromDB ran Successfully - ");
                string SQLquery = "select * from Orders";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }


        public void EnterOrderToDB(ProductsModel data)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Orders \ EnterOrderToDB ran Successfully - ");
                string SQLquery = "insert into Orders values (null ,'" + data.BC_code + "','" + data.Campaign_code + "' ,'" + data.Code + "',getdate(),0)";
                SqlDB.WriteToDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }


        public void UpdateOrderIsSentInDB(OrdersModel Order)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Orders \ UpdateOrderIsSentInDB ran Successfully - ");
                string SqlQuery = "update Orders set Is_Sent = 1 where Code = " + Order.Code.ToString();
                SqlDB.WriteToDB(SqlQuery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
