using System;
using System.IO;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;
using Newtonsoft.Json;
using MiniProject.Entities;
using System.Text.Json;
using System.Data;
using MiniProject.Model;
using System.Reflection;

namespace MiniProject.Server
{
    public static class Products
    {
        [FunctionName("Products")]
        public static async Task<IActionResult> Run(
        [HttpTrigger(AuthorizationLevel.Anonymous, "get", "post", "delete", Route = "Users/{action}/{IdNumber?}")] HttpRequest req,
        string action, string IdNumber, ILogger log)
        {
            log.LogInformation("C# HTTP trigger function processed a request.");

           
            string requestBody;
            switch (action)
            {
                case "get":
                    MainManager.Instance.ProductManager1.ShowAllProducstFromDB();
                    string responseMessage = JsonConvert.SerializeObject(MainManager.Instance.ProductManager1.ProducTable);
                    return new OkObjectResult(responseMessage);

                case "post":
                    M_InsertFormToDB FormData = new M_InsertFormToDB();
                    FormData = System.Text.Json.JsonSerializer.Deserialize<M_InsertFormToDB>(req.Body);                  
                    MainManager.Instance.InsertFormToDB1.SendFormToDB(FormData);     
                    break;

                case "update":
                    requestBody = await new StreamReader(req.Body).ReadToEndAsync();
                    M_Products product = System.Text.Json.JsonSerializer.Deserialize<M_Products>(requestBody);
                    MainManager.Instance.ProductManager1.Update_Product(product);               
                    break;

                case "delete":
                    MainManager.Instance.ProductManager1.Delete_Product(IdNumber);
                    break;

                default:
                    break;

            }


            return null;
        }     
    }
}