using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.CampaignsCommand
{
    public class getAllCampaignNamesFromDB : CommandManager, ICommand
    {
        public getAllCampaignNamesFromDB(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ CampaignsCommand \ getAllCampaignNamesFromDB ran Successfully - ");

                return JsonConvert.SerializeObject(MainManager.Instance.CampaignsManager.ShowAllCampaignNamesFromDB());

            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }

            return JsonConvert.SerializeObject(null);
        }


    }
}
