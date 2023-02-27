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
    public class SocialActivistManager: BaseEntity
    {
        BaseDataSql BaseDataSql;
        public SocialActivistManager(LogManager log) : base(log) 
        {
            BaseDataSql = new BaseDataSql(Log);
        }



        public DataTable ActivistsTable = new DataTable();
        public DataTable ShowAllActivistsFromDB()
        {
            try
            {
                Log.LogEvent(@"Entities \ SocialActivistManager \ ShowAllActivistsFromDB ran Successfully - ");
                ActivistsTable.Clear();
                DS_SocialActivist DS_SocialActivist = new DS_SocialActivist(Log);
                return ActivistsTable = DS_SocialActivist.ReadAllActivistsFromDB();
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return ActivistsTable;
        }


        public void SendActivistToDB(SocialActivistModel form)
        {
            try
            {
                Log.LogEvent(@"Entities \ SocialActivistManager \ SendActivistToDB ran Successfully - ");
                DS_SocialActivist DS_SocialActivist = new DS_SocialActivist(Log);
                DS_SocialActivist.EnterActivistToDB(form);
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
        }
    }
}
