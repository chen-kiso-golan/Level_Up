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
    public class DS_NonProfitOrganization: BaseDataSql
    {
        BaseDAL BaseDAL;
        public DS_NonProfitOrganization(LogManager log) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
        }

        public DataTable ReadAllNpoFromDB()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_NonProfitOrganization \ ReadAllNpoFromDB ran Successfully - ");
                string SQLquery = "select * from Non_Profit_Organizations";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }



        public DataTable ReadAllNpoEmailsFromDB()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_NonProfitOrganization \ ReadAllNpoEmailsFromDB ran Successfully - ");
                string SQLquery = "select Email from Non_Profit_Organizations";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }


        public void EnterNpoToDB(NonProfitOrganizationModel form)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_NonProfitOrganization \ EnterNpoToDB ran Successfully - ");
                string SQLquery = "insert into Non_Profit_Organizations values ('" + form.Name + "','" + form.Email + "','" + form.Website_URL + "' ,'" + form.Image + "')";
                SqlDB.WriteToDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }


        public void EnterNpoCodeByEmailToDB(string data)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_NonProfitOrganization \ EnterNpoCodeByEmailToDB ran Successfully - ");
                string SQLquery = "update Campaigns set NPO_code = (SELECT Code FROM Non_Profit_Organizations WHERE Email = '" + data + "') WHERE Email = '" + data + "'";
                SqlDB.WriteToDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }



    }
}
