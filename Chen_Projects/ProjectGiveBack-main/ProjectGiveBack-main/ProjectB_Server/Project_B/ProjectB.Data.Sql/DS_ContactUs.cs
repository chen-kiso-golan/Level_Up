using ProjectB.Dal;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Data.Sql
{
    public class DS_ContactUs: BaseDataSql
    {
        BaseDAL BaseDAL;
        public DS_ContactUs(LogManager log) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
        }
        public void EnterContactUsToDB(ContactUsModel form)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_ContactUs \ EnterContactUsToDB ran Successfully - ");
                string SQLquery = "insert into Contact_Us values ('" + form.Name + "','" + form.Message + "','" + form.Phone + "','" + form.Email + "',getdate())";
                SqlDB.WriteToDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
