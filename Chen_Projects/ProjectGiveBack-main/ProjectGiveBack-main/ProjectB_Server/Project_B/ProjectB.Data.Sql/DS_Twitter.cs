using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ProjectB.Model;
using ProjectB.Dal;
using System.Data;
using Utilities;

namespace ProjectB.Data.Sql
{
    public class DS_Twitter: BaseDataSql
    {
        BaseDAL BaseDAL;
        public DS_Twitter(LogManager log) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
        }


        public void UpdateTweetAndSA_MoneyQuery(TweetsModel newTweet)
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Twitter \ UpdateTweetAndSA_MoneyQuery ran Successfully - ");
                string updateQuery = "if not exists(select Code from Tweets where Tweet_id like '" + newTweet.Tweet_id + "')\r\n\tbegin\r\n\t\tinsert into Tweets values (" + newTweet.SA_code + ", " + newTweet.Campaign_code + ", '" + newTweet.Hashtag + "', '" + newTweet.Link_URL + "', '" + newTweet.Tweet_Content + "', getdate(), '" + newTweet.Tweet_id + "')\r\n\t\tupdate Social_Activist set Money = Money + 10 where Code = " + newTweet.SA_code + "\r\n\tend";
                SqlDB.WriteToDB(updateQuery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }

        public DataTable Send_getSocialActivistListQuery()
        { 
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Twitter \ Send_getSocialActivistListQuery ran Successfully - ");
                return SqlDB.ReadFormDB("select * from Social_Activist");
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }

        public DataTable Send_getAllCampaignsListQuery()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Twitter \ Send_getAllCampaignsListQuery ran Successfully - ");
                return SqlDB.ReadFormDB("select * from Campaigns");
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }
        
        public DataTable ReadAllTwitsFromDB()
        {
            try
            {
                Log.LogEvent(@"Data.Sql \ DS_Twitter \ ReadAllTwitsFromDB ran Successfully - ");
                string SQLquery = "select * from Tweets";
                return SqlDB.ReadFormDB(SQLquery);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return new DataTable();
        }



    }
}
