using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using ProjectB.Model;
using RestSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.RegisterApplicationsCommand
{
    public class get_role : CommandManager, ICommand
    {
        public get_role(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ RegisterApplicationsCommand \ get_role ran Successfully - ");

                string Auth0BearerCode = $"Bearer {MainManager.Instance.Config.Auth0BearerCode}";

                var rolesURL = $"https://dev-bexlompeu36s5051.us.auth0.com/api/v2/users/{(string)param[1]}/roles";
                var client = new RestClient(rolesURL);
                var request = new RestRequest("", Method.Get);
                request.AddHeader("authorization",  Auth0BearerCode);
                var response = client.Execute(request);
                if (response.IsSuccessful)
                {
                    var json = JArray.Parse(response.Content);
                    return json;
                }
                else
                {
                    return null;
                }

            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }

            return JsonConvert.SerializeObject(null);
        }


    }
}
