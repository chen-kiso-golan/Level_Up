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
    public class getAllCompaniesNamesFromDB: CommandManager, ICommand
    {
        public getAllCompaniesNamesFromDB(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ BuisnessCompaniesCommand \ getAllCompaniesNamesFromDB ran Successfully - ");

                return JsonConvert.SerializeObject(MainManager.Instance.BuisnessCompaniesManager.ShowAllCompaniesNamesFromDB((string)param[1]));

            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }

            return JsonConvert.SerializeObject(null);
        }
    }
}
