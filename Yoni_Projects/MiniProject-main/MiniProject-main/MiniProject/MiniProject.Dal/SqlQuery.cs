using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MiniProject.Dal
{
    public class SqlQuery
    {
        public static string ConnectionString = @"Integrated Security=SSPI;   Persist Security Info=False;    Initial Catalog=Northwind2;  Data Source=localhost\sqlexpress";
       
        public static DataTable ReadTableFormDB(string Sql_Query)
        {
            SqlDataAdapter adapter = new SqlDataAdapter(Sql_Query, ConnectionString);
            //יצירת טבלה בזיכרון
            DataTable table = new DataTable();
            //מילוי הנתונים בתוך הטבלה הזמנית בזיכרון
            adapter.Fill(table);

            return table;
        }

        public static void WriteToDB(string Sql_Query)
        {
            //הפעלת הצינור לפי ההגדרות שמופיעות בקונקטשן סטרינג
            using (SqlConnection connection = new SqlConnection(ConnectionString))
            {
                using (SqlCommand command = new SqlCommand(Sql_Query, connection))
                {
                    connection.Open();

                    command.ExecuteNonQuery();
                }
            }
        }
    }
}
