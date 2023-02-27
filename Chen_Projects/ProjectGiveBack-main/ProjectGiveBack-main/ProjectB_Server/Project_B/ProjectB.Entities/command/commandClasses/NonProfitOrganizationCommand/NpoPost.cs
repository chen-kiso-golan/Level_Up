using Newtonsoft.Json;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.NonProfitOrganizationCommand
{
    public class NpoPost : CommandManager, ICommand
    {
        public NpoPost(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ NonProfitOrganizationCommand \ NpoPost ran Successfully - ");

                NonProfitOrganizationModel NpoData = new NonProfitOrganizationModel();
                NpoData = System.Text.Json.JsonSerializer.Deserialize<NonProfitOrganizationModel>((string)param[0]);
                MainManager.Instance.NonProfitOrganizationManager.SendNpoToDB(NpoData);

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
