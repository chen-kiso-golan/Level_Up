using Newtonsoft.Json;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.CampaignsCommand
{
    public class UpdateCampaign : CommandManager, ICommand
    {
        public UpdateCampaign(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ CampaignsCommand \ UpdateCampaign ran Successfully - ");

                CampaignsModel Campaign = System.Text.Json.JsonSerializer.Deserialize<CampaignsModel>((string)param[0]);
                MainManager.Instance.CampaignsManager.UpdateCampaign(Campaign);

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
