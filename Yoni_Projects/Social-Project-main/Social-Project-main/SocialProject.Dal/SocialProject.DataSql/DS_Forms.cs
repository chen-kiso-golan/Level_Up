using SocialProject.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SocialProject.Dal;
using System.Xml.Linq;
using static System.Net.Mime.MediaTypeNames;

namespace SocialProject.DataSql
{
    public class DS_Forms
    {
        public void EnterContactUsFormToDB(M_ContactUs M_ContactUs)
        {
            string sqlQuery = "insert into Contact_Us values ('" + M_ContactUs.FirstName + "','" + M_ContactUs.LastName + "','" + M_ContactUs.Email + "','"+ M_ContactUs.Message+ "','" + M_ContactUs.JoinedNewsletter + "',getdate())";
            SqlQuery.Write_ToDB(sqlQuery);
        }

        public void EnterSocialActivistFormToDB(M_SocialActivist m_Social)
        {
            string Register_ApplicationsQuery = "insert into Register_Applications values ('" + m_Social.FirstName + m_Social.LastName + "', '" + m_Social.Email + "', 'Activist', 0)";
            SqlQuery.Write_ToDB(Register_ApplicationsQuery);

            string sqlQuery = "insert into Social_Activist values ('" + m_Social.FirstName + "','" + m_Social.LastName + "','" + m_Social.Email + "','" + m_Social.Address + "','" + m_Social.Phone_Number + "',0,'"+ m_Social.Image + "' ,getdate(),'"+ m_Social.Twitter_Name+ "')";
            SqlQuery.Write_ToDB(sqlQuery);
        }

        public void EnterNPOFormToDB(M_NonProfitOrganization m_NonProfit)
        {
            string Register_ApplicationsQuery = "insert into Register_Applications values ('" + m_NonProfit.Name + "', '" + m_NonProfit.Email + "', 'N.P.O', 0)";
            SqlQuery.Write_ToDB(Register_ApplicationsQuery);

            string sqlQuery = "insert into Non_Profit_Organizations values ('" + m_NonProfit.Name + "','" + m_NonProfit.Email + "','" + m_NonProfit.Website_URL + "','" + m_NonProfit.Image + "',getdate())";
            SqlQuery.Write_ToDB(sqlQuery);
        }
        
        public void EnterCompanyFormToDB(M_BusinessCompany m_Company)
        {
            string Register_ApplicationsQuery = "insert into Register_Applications values ('" + m_Company.Name + "', '" + m_Company.Email + "', 'Company', 0)";
            SqlQuery.Write_ToDB(Register_ApplicationsQuery);

            string sqlQuery = "insert into Buisness_Companies values ('" + m_Company.Name + "','" + m_Company.Email + "','" + m_Company.Image + "',getdate())";
            SqlQuery.Write_ToDB(sqlQuery);
        }

        public void EnterCampaignFormToDB(M_Campaign m_Campaign)
        { 
            string sqlQuery = "insert into Campaigns values ('" + m_Campaign.Name + "','" + m_Campaign.Email + "','" + m_Campaign.Description + "','" + m_Campaign.Landing_Page_URL + "','"+ m_Campaign.HashTag + "','"+ m_Campaign.NPO_code+ "','" + m_Campaign.Image + "',1)";
            SqlQuery.Write_ToDB(sqlQuery);
        }
        public void EnterEditCampaignFormToDB(M_Campaign m_Campaign)
        {
            string sqlQuery = "update Campaigns set Name = '" + m_Campaign.Name + "', Email = '" + m_Campaign.Email + "', Description = '" + m_Campaign.Description + "', Landing_Page_URL = '" + m_Campaign.Landing_Page_URL + "',HashTag = '" + m_Campaign.HashTag + "', Image = '" + m_Campaign.Image + "' where Code = "+m_Campaign.Code;
            SqlQuery.Write_ToDB(sqlQuery);
        }
        public void EnterProductFormToDB(M_Product m_Product)
        {
            string sqlQuery = "insert into Products values ('" + m_Product.Name + "','" + m_Product.Price + "','" + m_Product.Description + "','" + m_Product.Units_In_Stock + "','" + m_Product.BC_code + "','" + m_Product.Campaign_code + "','" + m_Product.Image + "')";
            SqlQuery.Write_ToDB(sqlQuery);
        }
        public void EnterEditProductFormToDB(M_Product m_Product)
        {
            string sqlQuery = "update Products set Name = '" + m_Product.Name + "', Price = '" + m_Product.Price + "', Description = '" + m_Product.Description + "', Units_In_Stock = '" + m_Product.Units_In_Stock + "',BC_code = '" + m_Product.BC_code + "', Campaign_code = '" + m_Product.Campaign_code + "', Image = '" + m_Product.Image + "' where Code = " + m_Product.Code;
            SqlQuery.Write_ToDB(sqlQuery);
        }

        //***************************************Order******************************** 

        public void EnterOrderDetailsFormToDB(M_Order m_Order, int UnitsInStock)
        {
            string sqlQuery = "insert into Orders values ('"+ m_Order.SA_code + "', '"+ m_Order.BC_code + "', '"+ m_Order.Campaign_code + "', '"+ m_Order.Product_code + "',"+ UnitsInStock + ", getdate(), 0)  update Products set Units_In_Stock = Units_In_Stock - "+UnitsInStock+"  where Code = " + m_Order.Product_code;
            SqlQuery.Write_ToDB(sqlQuery);
        }

        public void EnterTweetToDB(M_Campaign m_Campaign, string SA_code)
        {
            string sqlQuery = "insert into Tweets values('" + SA_code + "','" + m_Campaign.Code + "','" + m_Campaign.HashTag + "','" + m_Campaign.Landing_Page_URL + "','" + m_Campaign.Description + "', getdate())";
            SqlQuery.Write_ToDB(sqlQuery);
        }

        
    }
}

