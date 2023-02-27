using ProjectB.Dal;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Data.Sql
{
    public class DS_RegisterApplications: BaseDataSql
    {
        BaseDAL BaseDAL;
        public DS_RegisterApplications(LogManager log) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
        }
        public DataTable ReadUserInfoFromDB(string email, string role)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_RegisterApplications \ ReadUserInfoFromDB ran Successfully - ");
                if (role == "NPO")
                {
                    return SqlDB.ReadFormDB("select * from Non_Profit_Organizations where Email='" + email + "' ");
                }
                else if (role == "BC")
                {
                    return SqlDB.ReadFormDB("select * from Buisness_Companies where Email='" + email + "' ");
                }
                else
                {
                    return SqlDB.ReadFormDB("select * from Social_Activist where Email='" + email + "' ");
                }
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }




    }
}
