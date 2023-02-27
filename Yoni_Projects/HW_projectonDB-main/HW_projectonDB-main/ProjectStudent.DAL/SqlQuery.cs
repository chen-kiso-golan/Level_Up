using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace ProjectStudent.DAL
{
    public class SqlQuery
    {

        public delegate void SetDataReader_delegate(SqlDataReader reader);
        public delegate object SetResulrDataReader_delegate(SqlDataReader reader);
        public static void RunCommand(string sqlQuery, SetDataReader_delegate func)
        {
            string ConnectionString = ConfigurationManager.AppSettings["ConnectionString"];
           // Connection
           using (SqlConnection connection = new SqlConnection(ConnectionString))
           {
               string queryString = sqlQuery;
               // Adapter
               using (SqlCommand command = new SqlCommand(queryString, connection))
               {
                   connection.Open();
                    //Reader
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        func(reader);
                    }   
               }
           }      
        }
        public static object RunCommandResult(string sqlQuery, SetResulrDataReader_delegate func)
        {
            object ret = null;
            string connectionString = ConfigurationManager.AppSettings["connectionString"];
            using (SqlConnection connection = new SqlConnection(connectionString))
            {

                string queryString = sqlQuery;

                // Adapter
                using (SqlCommand command = new SqlCommand(queryString, connection))
                {
                    connection.Open();
                    //Reader
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        ret = func(reader);
                    }
                }

            }

            return ret;
        }
    }
}
