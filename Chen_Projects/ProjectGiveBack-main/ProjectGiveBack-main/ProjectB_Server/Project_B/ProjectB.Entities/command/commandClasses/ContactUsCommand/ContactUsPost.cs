using Newtonsoft.Json;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.ContactUsCommand
{
    public class ContactUsPost : CommandManager, ICommand
    {
        public ContactUsPost(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ ContactUsCommand \ ContactUsPost ran Successfully - ");

                ContactUsModel FormData = new ContactUsModel();
                FormData = System.Text.Json.JsonSerializer.Deserialize<ContactUsModel>((string)param[0]);
                MainManager.Instance.ContactUsManager.SendContactUsToDB(FormData);
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
