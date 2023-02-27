using Newtonsoft.Json;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.OrdersCommand
{
    public class OrderPost : CommandManager, ICommand
    {
        public OrderPost(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ OrdersCommand \ OrderPost ran Successfully - ");
                ProductsModel OrderData = new ProductsModel();
                OrderData = System.Text.Json.JsonSerializer.Deserialize<ProductsModel>((string)param[0]);
                MainManager.Instance.OrdersManager.SendOrderToDB(OrderData);

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
