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
    public class Config_DS: BaseDataSql
    {
        BaseDAL BaseDAL;
        Config config;
        public Config_DS(LogManager log, Config Config) : base(log)
        {
            BaseDAL = new BaseDAL(Log);
            config = Config;
        }

        

        public void InitConfig()
        {
            try
            {
                Log.LogEvent(@"DataSql \ Config_DS \ InitConfig ran Successfully - ");
                config.Auth0BearerCode = (string)SqlQuery.ReadScalarFromDB("select Value from Configuration where Name like 'Auth0BearerCode'");
                config.TwitterBearerCode = (string)SqlQuery.ReadScalarFromDB("select Value from Configuration where Name like 'TwitterBearerCode'");
                config.TwitterConsumerKey = (string)SqlQuery.ReadScalarFromDB("select Value from Configuration where Name like 'TwitterConsumerKey'");
                config.TwitterConsumerKeySecret = (string)SqlQuery.ReadScalarFromDB("select Value from Configuration where Name like 'TwitterConsumerKeySecret'");
                config.TwitterAccessKey = (string)SqlQuery.ReadScalarFromDB("select Value from Configuration where Name like 'TwitterAccessKey'");
                config.TwitterAccessKeySecret = (string)SqlQuery.ReadScalarFromDB("select Value from Configuration where Name like 'TwitterAccessKeySecret'");
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
