using ProjectB.Dal;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Utilities;

namespace ProjectB.Data.Sql
{
    public class DS_BuisnessCompanies: BaseDataSql
    {
        BaseDAL BaseDAL;
        public DS_BuisnessCompanies(LogManager log) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
        }


        public DataTable ReadAllCompaniesFromDB()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_BuisnessCompanies \ ReadAllCompaniesFromDB ran Successfully - ");
                string SQLquery = "select * from Buisness_Companies";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }


        public DataTable ReadAllCompaniesNamesFromDB(string email)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_BuisnessCompanies \ ReadAllCompaniesNamesFromDB ran Successfully - ");
                string SQLquery = "select Name from Buisness_Companies where Email = '" + email + "'";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }



        public int ReadBcCodeByNameFromDB(string Name)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_BuisnessCompanies \ ReadBcCodeByNameFromDB ran Successfully - ");
                string SQLquery = "select Code from Buisness_Companies where Name='" + Name + "'";
                int code = (int)SqlDB.GetScalarFromDB(SQLquery);
                return code;
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return 0;
        }



        public int ReadBcCodeByEmailFromDB(string email)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_BuisnessCompanies \ ReadBcCodeByEmailFromDB ran Successfully - ");
                string SQLquery = "select Code from Buisness_Companies where Email='" + email + "'";
                int code = (int)SqlDB.GetScalarFromDB(SQLquery);
                return code;
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return 0;
        }


        public void EnterCompanyToDB(BuisnessCompaniesModel form)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_BuisnessCompanies \ EnterCompanyToDB ran Successfully - ");
                string SQLquery = "insert into Buisness_Companies values ('" + form.Name + "','" + form.Email + "','" + form.Image + "')";
                SqlDB.WriteToDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
