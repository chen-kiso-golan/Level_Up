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
    public class CampaignsManager: BaseEntity
    {
        BaseDataSql BaseDataSql;
        public CampaignsManager(LogManager log) : base(log) 
        {
            BaseDataSql = new BaseDataSql(Log);
        }



        public DataTable CampaignsTable = new DataTable();
        public DataTable ShowAllCampaignsFromDB()
        {
            try
            {
                Log.LogEvent(@"Entities \ CampaignsManager \ ShowAllCampaignsFromDB ran Successfully - ");
                CampaignsTable.Clear();
                DS_Campaigns DS_Campaigns = new DS_Campaigns(Log);
                return CampaignsTable = DS_Campaigns.ReadAllCampaignsFromDB();               
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return CampaignsTable;
        }



        public DataTable CampaignNames = new DataTable();
        public DataTable ShowAllCampaignNamesFromDB()
        {
            try
            {
                Log.LogEvent(@"Entities \ CampaignsManager \ ShowAllCampaignNamesFromDB ran Successfully - ");
                CampaignNames.Clear();
                DS_Campaigns DS_Campaigns = new DS_Campaigns(Log);
                return CampaignNames = DS_Campaigns.ReadCampaignNamesFromDB();
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return CampaignNames;
        }


        public int ShowCampaignCodeByNameFromDB(string Name)
        {
            try
            {
                Log.LogEvent(@"Entities \ CampaignsManager \ ShowCampaignCodeByNameFromDB ran Successfully - ");
                DS_Campaigns DS_Campaigns = new DS_Campaigns(Log);
                return DS_Campaigns.ReadCampaignCodeByNameFromDB(Name);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return 0;
        }


        public void SendCampaignToDB(CampaignsModel form)
        { 
            try
            {
                Log.LogEvent(@"Entities \ CampaignsManager \ SendCampaignToDB ran Successfully - ");
                DS_Campaigns DS_Campaigns = new DS_Campaigns(Log);
                DS_Campaigns.EnterCampaignToDB(form);
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
                Log.LogEvent(@"Entities \ CampaignsManager \ DeleteCampaign ran Successfully - ");
                DS_Campaigns DS_Campaigns = new DS_Campaigns(Log);
                DS_Campaigns.DeleteCampaign(Code);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }



        public void UpdateCampaign(CampaignsModel Campaign)
        {
            try
            {
                Log.LogEvent(@"Entities \ CampaignsManager \ UpdateCampaign ran Successfully - ");
                DS_Campaigns DS_Campaigns = new DS_Campaigns(Log);
                DS_Campaigns.UpdateCampaignInDB(Campaign);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
