using System;
using System.IO;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;
using System.Text.Json;
using Newtonsoft.Json;
using ProjectTemplate.Model;
using System.Collections.Generic;

namespace ProjectTemplate.MicroServer
{
    public static class Function1
    {
        [FunctionName("Function1")]
        public static async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Function, "get", "post", Route = null)] HttpRequest req,
            ILogger log)
        {
            log.LogInformation("C# HTTP trigger function processed a request.");

            string name = req.Query["name"];


            Model.Student student = new Model.Student()
            {
                Name = "Yossi",
                Id = 123,
                Age = 30,
                Address = "Ben Gurion12 Rishon"
            };



            string responseMessage = System.Text.Json.JsonSerializer.Serialize(student);

            Model.Student student2;

            student2 = System.Text.Json.JsonSerializer.Deserialize<Student>(responseMessage);

            Dictionary<int, Student> list = new Dictionary<int, Student>();
            list.Add(1, new Student() { Address = "aaaaa", Age = 23, Id = 444 });
            list.Add(2, new Student() { Address = "bbbbb", Age = 23, Id = 444 });
            list.Add(3, new Student() { Address = "cccccc", Age = 23, Id = 444 });

            responseMessage = System.Text.Json.JsonSerializer.Serialize(list);

            Dictionary<int, Student> list2 = System.Text.Json.JsonSerializer.Deserialize<Dictionary<int, Student>>(responseMessage);


            Entities.MainManager.Instance.Students.CalcMilga();
            // convert to JSON




            return new OkObjectResult(responseMessage);
        }
    }
}
