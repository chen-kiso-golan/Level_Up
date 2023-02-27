using SocialProject.DataSql;
using SocialProject.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace SocialProject.Entities
{
    public class TwitterManager
    {

        private DataTable getSocialActivist = new DataTable();

        public List<M_SocialActivist> FillSocialActivistListFromDB()
        {
            List<M_SocialActivist> SocialActivistList = new List<M_SocialActivist>();

            getSocialActivist.Clear();
            SocialActivistList.Clear();
            DS_UsersQ DS_UsersQ = new DS_UsersQ();
            getSocialActivist = DS_UsersQ.Send_getSocialActivistListQuery();
            int NumOfRows_Activist =  getSocialActivist.Rows.Count;

            for (int i = 0; i < NumOfRows_Activist; i++)
            {
                M_SocialActivist SA = new M_SocialActivist();
                SA.Code = (int) getSocialActivist.Rows[i][0];
                SA.Twitter_Name = (string) getSocialActivist.Rows[i][9];
                SocialActivistList.Add(SA);
            }
            return SocialActivistList;
        }




        private DataTable getAllCampaigns = new DataTable();

        public List<M_Campaign> FillAllCampaignsListFromDB()
        {
            List<M_Campaign> CampaignList = new List<M_Campaign>();

            getAllCampaigns.Clear();
            CampaignList.Clear();
            DS_UsersQ DS_UsersQ = new DS_UsersQ();
            getAllCampaigns = DS_UsersQ.Send_getAllCampaignsListQuery();
            int NumOfRows_Campaigns = getAllCampaigns.Rows.Count;

            for (int i = 0; i < NumOfRows_Campaigns; i++)
            {
                M_Campaign Campaign = new M_Campaign();
                Campaign.Code = (int) getAllCampaigns.Rows[i][0];
                Campaign.HashTag = (string) getAllCampaigns.Rows[i][5];
                Campaign.Landing_Page_URL = (string)getAllCampaigns.Rows[i][4];
                CampaignList.Add(Campaign);
            }
            return CampaignList;
        }

        public void UpdateTweetAndMoneyInDB(M_Tweets newTweet)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            dS_UsersQ.UpdateTweetAndSA_MoneyQuery(newTweet);
        }



       
    }
}
