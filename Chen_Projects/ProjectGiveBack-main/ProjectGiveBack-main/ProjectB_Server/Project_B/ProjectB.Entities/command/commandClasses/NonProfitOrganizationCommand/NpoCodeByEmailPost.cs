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
    public class NpoCodeByEmailPost : CommandManager, ICommand
    {
        public NpoCodeByEmailPost(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ NonProfitOrganizationCommand \ NpoCodeByEmailPost ran Successfully - ");

                string NpoCodeByEmailData = System.Text.Json.JsonSerializer.Deserialize<string>((string)param[0]);
                MainManager.Instance.NonProfitOrganizationManager.SendNpoCodeByEmailToDB((string)param[1]);

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
