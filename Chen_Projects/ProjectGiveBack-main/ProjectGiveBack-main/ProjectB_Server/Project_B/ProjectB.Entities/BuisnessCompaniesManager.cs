using ProjectB.Data.Sql;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Utilities;

namespace ProjectB.Entities
{
    public class BuisnessCompaniesManager: BaseEntity
    {
        BaseDataSql BaseDataSql;
        public BuisnessCompaniesManager(LogManager log) : base(log) 
        {
            BaseDataSql = new BaseDataSql(Log);
        }



        public DataTable CompaniesTable = new DataTable();
        public DataTable ShowAllCompaniesFromDB()
        {
            try
            {
                Log.LogEvent(@"Entities \ BuisnessCompaniesManager \ ShowAllCompaniesFromDB ran Successfully - ");
                CompaniesTable.Clear();
                DS_BuisnessCompanies DS_BuisnessCompanies = new DS_BuisnessCompanies(Log);
                return CompaniesTable = DS_BuisnessCompanies.ReadAllCompaniesFromDB();
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return CompaniesTable;
        }



        public DataTable CompaniesNames = new DataTable();
        public DataTable ShowAllCompaniesNamesFromDB(string email)
        {
            try
            {
                Log.LogEvent(@"Entities \ BuisnessCompaniesManager \ ShowAllCompaniesNamesFromDB ran Successfully - ");
                CompaniesNames.Clear();
                DS_BuisnessCompanies DS_BuisnessCompanies = new DS_BuisnessCompanies(Log);
                return CompaniesNames = DS_BuisnessCompanies.ReadAllCompaniesNamesFromDB(email);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return CompaniesNames;
        }



        public int ShowBcCodeByNameFromDB(string Name)
        {
            try
            {
                Log.LogEvent(@"Entities \ BuisnessCompaniesManager \ ShowBcCodeByNameFromDB ran Successfully - ");
                DS_BuisnessCompanies DS_BuisnessCompanies = new DS_BuisnessCompanies(Log);
                return DS_BuisnessCompanies.ReadBcCodeByNameFromDB(Name);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return 0;
        }



        public int ShowBcCodeByEmailFromDB(string email)
        {
            try
            {
                Log.LogEvent(@"Entities \ BuisnessCompaniesManager \ ShowBcCodeByEmailFromDB ran Successfully - ");
                DS_BuisnessCompanies DS_BuisnessCompanies = new DS_BuisnessCompanies(Log);
                return DS_BuisnessCompanies.ReadBcCodeByEmailFromDB(email);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return 0;
        }



        public void SendCompanyToDB(BuisnessCompaniesModel form)
        {
            try
            {
                Log.LogEvent(@"Entities \ BuisnessCompaniesManager \ SendCompanyToDB ran Successfully - ");
                DS_BuisnessCompanies DS_BuisnessCompanies = new DS_BuisnessCompanies(Log);
                DS_BuisnessCompanies.EnterCompanyToDB(form);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
