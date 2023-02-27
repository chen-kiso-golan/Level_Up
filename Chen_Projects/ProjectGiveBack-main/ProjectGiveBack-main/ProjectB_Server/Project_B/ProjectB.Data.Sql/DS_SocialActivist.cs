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
    public class DS_SocialActivist: BaseDataSql
    {
        BaseDAL BaseDAL;
        public DS_SocialActivist(LogManager log) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
        }


        public DataTable ReadAllActivistsFromDB()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_SocialActivist \ ReadAllActivistsFromDB ran Successfully - ");
                string SQLquery = "select * from Social_Activist";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }


        public void EnterActivistToDB(SocialActivistModel form)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_SocialActivist \ EnterActivistToDB ran Successfully - ");
                string SQLquery = "insert into Social_Activist values ('" + form.Name + "','" + form.Email + "','" + form.Address + "','" + form.PhoneNumber + "',0,'" + form.Image + "','" + form.Twitter_Name + "')";
                SqlDB.WriteToDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
