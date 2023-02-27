using Newtonsoft.Json;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.SocialActivistCommand
{
    public class ActivistPost : CommandManager, ICommand
    {
        public ActivistPost(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ SocialActivistCommand \ ActivistPost ran Successfully - ");
                SocialActivistModel ActivistData = new SocialActivistModel();
                ActivistData = System.Text.Json.JsonSerializer.Deserialize<SocialActivistModel>((string)param[0]);
                MainManager.Instance.SocialActivistManager.SendActivistToDB(ActivistData);

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
