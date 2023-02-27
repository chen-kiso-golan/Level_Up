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
    public class OrdersManager: BaseEntity
    {
        BaseDataSql BaseDataSql;

        public OrdersManager(LogManager log) : base(log) 
        {
            BaseDataSql = new BaseDataSql(Log);
        }



        public DataTable Orders = new DataTable();
        public DataTable ShowAllOrdersFromDB()
        {
            try
            {
                Log.LogEvent(@"Entities \ OrdersManager \ ShowAllOrdersFromDB ran Successfully - ");
                Orders.Clear();
                DS_Orders DS_Orders = new DS_Orders(Log);
                return Orders = DS_Orders.ReadAllOrdersFromDB();
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return Orders;
        }



        public void SendOrderToDB(ProductsModel data)
        {
            try
            {
                Log.LogEvent(@"Entities \ OrdersManager \ SendOrderToDB ran Successfully - ");
                DS_Orders DS_Orders = new DS_Orders(Log);
                DS_Orders.EnterOrderToDB(data);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }



        public void UpdateOrderIsSent(OrdersModel Order)
        { 
            try
            {
                Log.LogEvent(@"Entities \ OrdersManager \ UpdateOrderIsSent ran Successfully - ");
                DS_Orders DS_Orders = new DS_Orders(Log);
                DS_Orders.UpdateOrderIsSentInDB(Order);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
