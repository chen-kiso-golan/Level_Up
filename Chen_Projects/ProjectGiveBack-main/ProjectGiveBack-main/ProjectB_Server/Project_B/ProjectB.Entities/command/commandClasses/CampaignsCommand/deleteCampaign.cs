using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.CampaignsCommand
{
    public class deleteCampaign : CommandManager, ICommand
    {
        public deleteCampaign(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ CampaignsCommand \ deleteCampaign ran Successfully - ");

                MainManager.Instance.CampaignsManager.DeleteCampaign((string)param[1]);

                return System.Text.Json.JsonSerializer.Serialize("Task Completed");

            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }

            return JsonConvert.SerializeObject(null);
        }

    }
}
