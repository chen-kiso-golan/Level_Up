using System;
using System.IO;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using ProjectB.Entities;
using RestSharp;
using ProjectB.Model;
using static System.Collections.Specialized.BitVector32;
using ProjectB.Entities.command;

namespace ProjectB.MicroServer
{
    public static class BuisnessCompanies
    {
        [FunctionName("BuisnessCompanies")]
        public static async Task<IActionResult> Run(
        [HttpTrigger(AuthorizationLevel.Anonymous, "get", "post", "delete", Route = "BuisnessCompanies/{action}/{Value?}/{Value2?}")] HttpRequest req,
        string action, string Value, string Value2, ILogger log)
        {
            log.LogInformation("C# HTTP trigger function processed a request.");

            string dictionaryKey = action;
            string requestBody;
            string responseMessage;

            ICommand commmand = MainManager.Instance.CommandManager.CommandList[dictionaryKey];

            try
            {
                MainManager.Instance.log.LogEvent(@"MicroServer \ BuisnessCompanies ran Successfully - ");
                requestBody = await req.ReadAsStringAsync();
                return new OkObjectResult(commmand.Execute(requestBody, Value));
            }
            catch (Exception ex)
            {
                MainManager.Instance.log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }
            return null; //new BadRequestObjectResult("Problam Was Found");


            
        }
    }
}



