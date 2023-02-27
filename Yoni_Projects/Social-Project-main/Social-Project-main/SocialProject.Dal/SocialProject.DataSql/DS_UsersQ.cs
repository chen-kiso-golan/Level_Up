using SocialProject.Dal;
using SocialProject.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.DataSql
{
    public class DS_UsersQ
    {

        //******************************** NPO + company + social_Activist ***********************************


        public DataTable Send_UserInfoQuery(string email,string role)
        {
            if (role == "N.P.O")
            {
                return SqlQuery.Read_Table_FormDB("select * from Non_Profit_Organizations where Email='"+email+"' ");
            }
            else if (role == "company")
            {
                return SqlQuery.Read_Table_FormDB("select * from Buisness_Companies where Email='" + email + "' ");
            }
            else
            {
                return SqlQuery.Read_Table_FormDB("select * from Social_Activist where Email='" + email + "' ");
            }
        }

        //**************************************************** Owner + Campaigns *****************************************
        public DataTable Send_getPendingListQuery()
        {
            return SqlQuery.Read_Table_FormDB("select * from Register_Applications where Is_Approved = 0");
        }
        

        public bool? Send_PenddingQuery(string email)
        {
          string Is_Approved = "select Is_Approved from Register_Applications where Email like '" + email + "'";
          bool? Pending = (bool?)SocialProject.Dal.SqlQuery.Read_Scalar_FromDB(Is_Approved);
          return Pending;
        }

        public void ApproveUserQuery(M_Register_Applications m_Register_App)
        {
            string updateQuery = "update Register_Applications set Is_Approved = 1 where code = " + m_Register_App.Code + "";
            SqlQuery.Write_ToDB(updateQuery);
        }

        public void Is_ActiveCampaignsQuery(M_Campaign m_Campaign)
        {
            string updateQuery = "update Campaigns set Is_Active = ~Is_Active where code = " + m_Campaign.Code + "";
            SqlQuery.Write_ToDB(updateQuery);
        }
        
        public DataTable Send_getTweetsListQuery()
        {
            return SqlQuery.Read_Table_FormDB("select * from Tweets");
        }

        public DataTable Send_getSocialActivistListQuery()
        {
            return SqlQuery.Read_Table_FormDB("select * from Social_Activist");
        }
        public DataTable Send_getNPOListQuery()
        {
            return SqlQuery.Read_Table_FormDB("select * from Non_Profit_Organizations");
        }

        public DataTable Send_getCompanyListQuery()
        {
            return SqlQuery.Read_Table_FormDB("select * from Buisness_Companies");
        }
        public DataTable Send_getAllCampaignsListByNPO_CodeQuery(string NPO_code)
        {
            return SqlQuery.Read_Table_FormDB("select * from Campaigns where NPO_code =" + NPO_code);
        }

        public DataTable Send_getAllCampaignsListQuery()
        {
            return SqlQuery.Read_Table_FormDB("select * from Campaigns");
        }

        

        //**************************************************** Company *****************************************

        public DataTable Send_getProductListQuery(string BC_code)
        {
            return SqlQuery.Read_Table_FormDB("select * from Products where BC_Code ="+ BC_code);
        }

        public void DeleteProductQuery(string productCode)
        {
            string deleteQuery = "delete from Products where Code = " + productCode;
            SqlQuery.Write_ToDB(deleteQuery);
        }

        public DataTable Send_getOrderDetailQuery(string BC_code)
        {
            return SqlQuery.Read_Table_FormDB("select Orders.*, SA.FirstName+' '+ SA.LastName as SA_Name, BC.Name as BC_Name, Campaigns.Name as Campaign_Name, Products.Name as Product_Name, \r\nSA.Address as Activist_Address, SA.Phone_Number as Activist_Phone,\r\nSA.Email as Activist_Email, Campaigns.Email as Campaign_Email \r\nfrom Orders\r\ninner join Social_Activist as SA on Orders.SA_code = SA.Code\r\ninner join Buisness_Companies as BC on Orders.BC_code = BC.Code\r\ninner join Campaigns on Orders.Campaign_code = Campaigns.Code\r\ninner join Products on Orders.Product_code = Products.Code where Orders.BC_code= " + BC_code);
        }

        public void Is_sendForOrderQuery(M_Order m_Order)
        {
            string updateQuery = "update Orders set Is_Sent = ~Is_Sent where code = " + m_Order.Code + "";
            SqlQuery.Write_ToDB(updateQuery);
        }
        


        //**************************************************** Activist *****************************************
        public DataTable Send_getProductListForActivistQuery(string Campaign_code)
        {
            return SqlQuery.Read_Table_FormDB("select * from Products where Campaign_code =" + Campaign_code);
        }


        public DataTable Send_getNEWMoneyStatusForActivistQuery(string NEWMoneyStatus, string SA_Code)
        {
            string updateQuery = "update Social_Activist set Money_Status = '" + NEWMoneyStatus + "' where Code =" + SA_Code;
            SqlQuery.Write_ToDB(updateQuery);

            return SqlQuery.Read_Table_FormDB("select * from Social_Activist");
        }

        public DataTable Send_getAllMyProductForActivistQuery(string SA_code)
        {
            return SqlQuery.Read_Table_FormDB("SELECT Products.Name as 'Product_Name', Products.Price as 'Price', COUNT(Orders.Code) as 'Total_Donations',\r\nsum(Orders.Quantity) as 'Quantity',Products.Price*sum(Orders.Quantity) as 'Total_Price', Campaigns.Name as 'Campaign_Name'\r\nFROM Orders\r\nJOIN Products ON Products.Code = Orders.Product_code\r\nJOIN Campaigns ON Orders.Campaign_code = Campaigns.Code\r\nWHERE Orders.SA_code = " + SA_code + "\r\nGROUP BY Products.Name, Products.Price, Campaigns.Name;");
        }


        public DataTable MoneyByTwitterQuery(string userInfoCode)
        {
            string updateQuery = $"update Social_Activist set Money_Status = Money_Status + 5 where code = {userInfoCode}";
            return SqlQuery.Read_Table_FormDB(updateQuery);
        }

        public void UpdateTweetAndSA_MoneyQuery(M_Tweets newTweet)
        {
            string updateQuery = "if not exists(select Code from Tweets where Tweet_id like '" + newTweet.Tweet_id + "')\r\n\tbegin\r\n\t\tinsert into Tweets values (" + newTweet.SA_code + ", " + newTweet.Campaign_code + ", '" + newTweet.HashTag + "', '" + newTweet.Landing_Page_URL + "', '" + newTweet.Tweet_Content + "', getdate(), '" + newTweet.Tweet_id + "')\r\n\t\tupdate Social_Activist set Money_Status = Money_Status + 10 where Code = " + newTweet.SA_code + "\r\n\tend";
            SqlQuery.Write_ToDB(updateQuery);
        }

    }
    

}
