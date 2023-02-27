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
    public class DS_Campaigns: BaseDataSql
    {
        BaseDAL BaseDAL;
        public DS_Campaigns(LogManager log) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
        }


        public DataTable ReadAllCampaignsFromDB()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Campaigns \ ReadAllCampaignsFromDB ran Successfully - ");
                string SQLquery = "select * from Campaigns";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }


        public DataTable ReadCampaignNamesFromDB()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Campaigns \ ReadCampaignNamesFromDB ran Successfully - ");
                string SQLquery = "select Name from Campaigns";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }



        public int ReadCampaignCodeByNameFromDB(string Name)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Campaigns \ ReadCampaignCodeByNameFromDB ran Successfully - ");
                string SQLquery = "select Code from Campaigns where Name='" + Name + "'";
                int code = (int)SqlDB.GetScalarFromDB(SQLquery);
                return code;
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return 0;
        }



        public void EnterCampaignToDB(CampaignsModel form)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Campaigns \ EnterCampaignToDB ran Successfully - ");
                string SQLquery = "insert into Campaigns values ('" + form.Name + "','" + form.Email + "','" + form.Link_URL + "' ,'" + form.Hashtag + "',null,'" + form.Image + "','" + form.Is_Active + "')";
                SqlDB.WriteToDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }


        public void DeleteCampaign(string Code)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Campaigns \ DeleteCampaign ran Successfully - ");
                string SqlQuery = "delete from Campaigns where Code = " + Code;
                SqlDB.WriteToDB(SqlQuery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }



        public void UpdateCampaignInDB(CampaignsModel Campaign)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Campaigns \ UpdateCampaignInDB ran Successfully - ");
                string SqlQuery = "update Campaigns set Hashtag = '" + Campaign.Hashtag + "', Is_Active = '" + Campaign.Is_Active + "', Image = '" + Campaign.Image + "', Link_URL = '" + Campaign.Link_URL + "', NPO_code = '" + Campaign.NPO_code.ToString() + "', Name = '" + Campaign.Name + "', Email = '" + Campaign.Email + "' where Code = " + Campaign.Code.ToString();
                SqlDB.WriteToDB(SqlQuery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }


    }
}
