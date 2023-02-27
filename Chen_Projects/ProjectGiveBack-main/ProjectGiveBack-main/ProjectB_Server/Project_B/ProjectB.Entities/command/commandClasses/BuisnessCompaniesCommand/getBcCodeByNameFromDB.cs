using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.BuisnessCompaniesCommand
{
    public class getBcCodeByNameFromDB : CommandManager, ICommand
    {
        public getBcCodeByNameFromDB(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ BuisnessCompaniesCommand \ getBcCodeByNameFromDB ran Successfully - ");

                return System.Text.Json.JsonSerializer.Serialize(MainManager.Instance.BuisnessCompaniesManager.ShowBcCodeByNameFromDB((string)param[1]));

            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }

            return JsonConvert.SerializeObject(null);
        }
    }
}
