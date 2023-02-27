using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;
using Newtonsoft.Json;



namespace ProjectB.Entities.command.commandClasses.CampaignsCommand
{
    public class getAllCampaignsFromDB: CommandManager, ICommand
    {
        public getAllCampaignsFromDB(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param) 
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ CampaignsCommand \ getAllCampaignsFromDB ran Successfully - ");

                return JsonConvert.SerializeObject(MainManager.Instance.CampaignsManager.ShowAllCampaignsFromDB());
                   
            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);  
            }

            return JsonConvert.SerializeObject(null);
        }


    }
}
