using ProjectB.Data.Sql;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities
{
    public class TwitterManager: BaseEntity
    {
        BaseDataSql BaseDataSql;
        public TwitterManager(LogManager log) : base(log) 
        {
            BaseDataSql = new BaseDataSql(Log);
        }



        private DataTable getSocialActivist = new DataTable();

        public List<SocialActivistModel> FillSocialActivistListFromDB()
        {
            try
            {
                Log.LogEvent(@"Entities \ TwitterManager \ FillSocialActivistListFromDB ran Successfully - ");
                List<SocialActivistModel> SocialActivistList = new List<SocialActivistModel>();

                getSocialActivist.Clear();
                SocialActivistList.Clear();
                DS_Twitter DS_Twitter = new DS_Twitter(Log);
                getSocialActivist = DS_Twitter.Send_getSocialActivistListQuery();
                int NumOfRows_Activist = getSocialActivist.Rows.Count;

                for (int i = 0; i < NumOfRows_Activist; i++)
                {
                    SocialActivistModel SA = new SocialActivistModel();
                    SA.Code = (int)getSocialActivist.Rows[i][0];
                    SA.Twitter_Name = (string)getSocialActivist.Rows[i][7];
                    SocialActivistList.Add(SA);
                }
                return SocialActivistList;
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new List<SocialActivistModel>();
        }




        private DataTable getAllCampaigns = new DataTable();

        public List<CampaignsModel> FillAllCampaignsListFromDB()
        {
            try
            {
                Log.LogEvent(@"Entities \ TwitterManager \ FillAllCampaignsListFromDB ran Successfully - ");
                List<CampaignsModel> CampaignList = new List<CampaignsModel>();

                getAllCampaigns.Clear();
                CampaignList.Clear();
                DS_Twitter DS_Twitter = new DS_Twitter(Log);
                getAllCampaigns = DS_Twitter.Send_getAllCampaignsListQuery();
                int NumOfRows_Campaigns = getAllCampaigns.Rows.Count;

                for (int i = 0; i < NumOfRows_Campaigns; i++)
                {
                    CampaignsModel Campaign = new CampaignsModel();
                    Campaign.Code = (int)getAllCampaigns.Rows[i][0];
                    Campaign.Hashtag = (string)getAllCampaigns.Rows[i][4];
                    Campaign.Link_URL = (string)getAllCampaigns.Rows[i][3];
                    CampaignList.Add(Campaign);
                }
                return CampaignList;
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new List<CampaignsModel>();
        }




        public void UpdateTweetAndMoneyInDB(TweetsModel newTweet)
        {
            try
            {
                Log.LogEvent(@"Entities \ TwitterManager \ UpdateTweetAndMoneyInDB ran Successfully - ");
                DS_Twitter DS_Twitter = new DS_Twitter(Log);
                DS_Twitter.UpdateTweetAndSA_MoneyQuery(newTweet);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }

   




        private DataTable getCampaignByCode = new DataTable();

        public List<CampaignsModel> ShowCampaignNameAndHashtagByCodeFromDB(string code)
        {
            try
            {
                Log.LogEvent(@"Entities \ TwitterManager \ ShowCampaignNameAndHashtagByCodeFromDB ran Successfully - ");
                List<CampaignsModel> CampaignByCodeList = new List<CampaignsModel>();

                getCampaignByCode.Clear();
                CampaignByCodeList.Clear();
                DS_Twitter DS_Twitter = new DS_Twitter(Log);
                getCampaignByCode = DS_Twitter.Send_getAllCampaignsListQuery();
                int NumOfRows_Campaigns = getCampaignByCode.Rows.Count;

                for (int i = 0; i < NumOfRows_Campaigns; i++)
                {
                    if ((int)getCampaignByCode.Rows[i][0] == Int32.Parse(code))
                    {
                        CampaignsModel Campaign = new CampaignsModel();
                        Campaign.Hashtag = (string)getCampaignByCode.Rows[i][4];
                        Campaign.Name = (string)getCampaignByCode.Rows[i][1];
                        CampaignByCodeList.Add(Campaign);
                    }

                }
                return CampaignByCodeList;
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new List<CampaignsModel>();
        }



        
        public DataTable TwitsTable = new DataTable();
        public DataTable ShowAllTwitsFromDB()
        {
            try
            {
                Log.LogEvent(@"Entities \ TwitterManager \ ShowAllTwitsFromDB ran Successfully - ");
                TwitsTable.Clear();
                DS_Twitter DS_Twitter = new DS_Twitter(Log);
                return TwitsTable = DS_Twitter.ReadAllTwitsFromDB();
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return TwitsTable;
        }
    }
}
