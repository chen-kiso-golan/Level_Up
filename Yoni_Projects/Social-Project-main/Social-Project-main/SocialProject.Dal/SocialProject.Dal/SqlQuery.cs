using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Dal
{
    public class SqlQuery
    {
        public static string ConnectionString = @"Integrated Security=SSPI;   Persist Security Info=False;    Initial Catalog=Social_Project;  Data Source=localhost\sqlexpress";

        public static DataTable Read_Table_FormDB(string Sql_Query)
        {
            SqlDataAdapter adapter = new SqlDataAdapter(Sql_Query, ConnectionString);    
            DataTable table = new DataTable();
            adapter.Fill(table);
            return table;
        }

        public static void Write_ToDB(string Sql_Query)
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
        public static object Read_Scalar_FromDB(string SqlQuery)
        {
            object result;
            using (SqlConnection connection = new SqlConnection(ConnectionString))
            {
                using (SqlCommand command = new SqlCommand(SqlQuery, connection))
                {
                    connection.Open();

                    result = command.ExecuteScalar();
                }
            }
            return result;
        }

        //public static void WriteWithValuesToDB(string query, Dictionary<string, object> parameters)
        //{
        //    using (SqlConnection connection = new SqlConnection(connectionString))
        //    {
        //        connection.Open();

        //        using (SqlCommand command = new SqlCommand(query, connection))
        //        {
        //            foreach (KeyValuePair<string, object> param in parameters)
        //            {
        //                command.Parameters.AddWithValue(param.Key, param.Value);
        //            }

        //            command.ExecuteNonQuery();
        //        }
        //    }
        //}
    }
}
