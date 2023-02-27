using Newtonsoft.Json;
using ProjectB.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command.commandClasses.ProductsCommand
{
    public class ProductPost : CommandManager, ICommand
    {
        public ProductPost(LogManager log) : base(log)
        {
        }

        public object Execute(params object[] param)
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ ProductsCommand \ ProductPost ran Successfully - ");
                ProductsModel ProductsData = new ProductsModel();
                ProductsData = System.Text.Json.JsonSerializer.Deserialize<ProductsModel>((string)param[0]);
                MainManager.Instance.ProductsManager.SendProductToDB(ProductsData);

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
