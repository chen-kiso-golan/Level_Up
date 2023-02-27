using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.RegisterApplicationsCommand
{
    public class get_UserInfoData : CommandManager, ICommand
    {
        public get_UserInfoData(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ RegisterApplicationsCommand \ get_UserInfoData ran Successfully - ");
                return JsonConvert.SerializeObject(MainManager.Instance.RegisterApplicationsManager.ShowUserInfoFromDB((string)param[1], (string)param[2]));

            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }

            return JsonConvert.SerializeObject(null);
        }


    }
}
