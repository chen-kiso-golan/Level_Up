using ProjectB.Entities.command.commandClasses.BuisnessCompaniesCommand;
using ProjectB.Entities.command.commandClasses.CampaignsCommand;
using ProjectB.Entities.command.commandClasses.ContactUsCommand;
using ProjectB.Entities.command.commandClasses.NonProfitOrganizationCommand;
using ProjectB.Entities.command.commandClasses.OrdersCommand;
using ProjectB.Entities.command.commandClasses.ProductsCommand;
using ProjectB.Entities.command.commandClasses.RegisterApplicationsCommand;
using ProjectB.Entities.command.commandClasses.SocialActivistCommand;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities.command
{

    public class CommandManager : BaseEntity
    {

        public CommandManager(LogManager log) : base(log) { }



        private Dictionary<string, ICommand> _commandList = null;
        public Dictionary<string, ICommand> CommandList
        {
            get
            {
                if (_commandList == null) init();
                return _commandList;
            }
        }


        private void init()
        {
            try
            {
                Log.LogEvent(@"Entities \ command \ CommandManager \ init ran Successfully - ");

                //Build all Dictionary
                _commandList = new Dictionary<string, ICommand>
            {
                //Campaigns
                { "getAllCampaignsFromDB", new getAllCampaignsFromDB(Log)},
                { "getAllCampaignNamesFromDB", new getAllCampaignNamesFromDB(Log)},
                { "getCampaignCodeByNameFromDB", new getCampaignCodeByNameFromDB(Log)},
                { "CampaignPost", new CampaignPost(Log)},
                { "UpdateCampaign", new UpdateCampaign(Log)},
                { "deleteCampaign", new deleteCampaign(Log)},
                //Companies
                { "getAllCompaniesFromDB", new getAllCompaniesFromDB(Log)},
                { "getAllCompaniesNamesFromDB", new getAllCompaniesNamesFromDB(Log)},
                { "getBcCodeByNameFromDB", new getBcCodeByNameFromDB(Log)},
                { "getBcCodeByEmailFromDB", new getBcCodeByEmailFromDB(Log)},
                { "CompanyPost", new CompanyPost(Log)},
                //ContactUs
                { "ContactUsPost", new ContactUsPost(Log)},
                //NPO
                { "getAllNpoFromDB", new getAllNpoFromDB(Log)},
                { "getAllNpoEmailsFromDB", new getAllNpoEmailsFromDB(Log)},
                { "NpoPost", new NpoPost(Log)},
                { "NpoCodeByEmailPost", new NpoCodeByEmailPost(Log)},
                //Orders
                { "getAllOrdersFromDB", new getAllOrdersFromDB(Log)},
                { "OrderPost", new OrderPost(Log)},
                { "UpdateOrderIsSent", new UpdateOrderIsSent(Log)},
                //Products
                { "getAllProductsFromDB", new getAllProductsFromDB(Log)},
                { "ProductPost", new ProductPost(Log)},
                //SocialActivists
                { "getAllActivistsFromDB", new getAllActivistsFromDB(Log)},
                { "ActivistPost", new ActivistPost(Log)},
                //RegisterApplications
                { "get_role", new get_role(Log)},
                { "get_UserInfoData", new get_UserInfoData(Log)},



            };


            }
            catch (Exception ex)
            {
                Log.LogException($@"An Exception occurred while initializing the {ex.StackTrace} : {ex.Message}", ex);
            }

        }
    }

    
}
