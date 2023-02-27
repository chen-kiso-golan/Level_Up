using Newtonsoft.Json;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.OrdersCommand
{
    public class UpdateOrderIsSent : CommandManager, ICommand
    {
        public UpdateOrderIsSent(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ OrdersCommand \ UpdateOrderIsSent ran Successfully - ");
              
                OrdersModel Order = System.Text.Json.JsonSerializer.Deserialize<OrdersModel>((string)param[0]);
                MainManager.Instance.OrdersManager.UpdateOrderIsSent(Order);

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
