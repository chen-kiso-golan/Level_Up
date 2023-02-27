using SocialProject.DataSql;
using SocialProject.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Entities
{
    public class UsersManager: BaseEntity
    {
        //*************************************************************** NPO + company + social_Activist ***********************************

        public DataTable getUserInfo = new DataTable();
        public void get_UserInfo_FromDB(string email, string role)
        {
            getUserInfo.Clear();

            if(role == "N.P.O")
            {
                DS_UsersQ DS_UsersQ = new DS_UsersQ();
                getUserInfo = DS_UsersQ.Send_UserInfoQuery(email, role);
            }
            else if (role == "company")
            {
                DS_UsersQ DS_UsersQ = new DS_UsersQ();
                getUserInfo = DS_UsersQ.Send_UserInfoQuery(email, role);
            }
            else
            {
                DS_UsersQ DS_UsersQ = new DS_UsersQ();
                getUserInfo = DS_UsersQ.Send_UserInfoQuery(email, role);
            }
        }

        //**************************************************** Owner *****************************************

        public DataTable getPendingList = new DataTable();

        public void ShowAllPendingListFromDB()
        {
            getPendingList.Clear();
            DS_UsersQ DS_UsersQ = new DS_UsersQ();
            getPendingList = DS_UsersQ.Send_getPendingListQuery();
        }
        public bool? get_Pending_FromDB (string email)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            return dS_UsersQ.Send_PenddingQuery(email);
        }
        public void UpdateApproveUserInDB(M_Register_Applications m_Register_App)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            dS_UsersQ.ApproveUserQuery(m_Register_App);
        }
        public void UpdateIs_ActiveInDB(M_Campaign m_Campaign)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            dS_UsersQ.Is_ActiveCampaignsQuery(m_Campaign);
        }

        public DataTable getTweetsList = new DataTable();
        public void ShowTweetsListFromDB()
        {
            getTweetsList.Clear();
            DS_UsersQ DS_UsersQ = new DS_UsersQ();
            getTweetsList = DS_UsersQ.Send_getTweetsListQuery();
        }

        
        public DataTable getSocialActivistList = new DataTable();
        public void ShowSocialActivistListFromDB()
        {
            getSocialActivistList.Clear();
            DS_UsersQ DS_UsersQ = new DS_UsersQ();
            getSocialActivistList = DS_UsersQ.Send_getSocialActivistListQuery();
        }

        public DataTable getNPOList = new DataTable();
        public void ShowNPOListFromDB()
        {
            getNPOList.Clear();
            DS_UsersQ DS_UsersQ = new DS_UsersQ();
            getNPOList = DS_UsersQ.Send_getNPOListQuery();
        }

        public DataTable getCompanyList = new DataTable();
        public void ShowCompanyListFromDB()
        {
            getCompanyList.Clear();
            DS_UsersQ DS_UsersQ = new DS_UsersQ();
            getCompanyList = DS_UsersQ.Send_getCompanyListQuery();
        }
        public DataTable getAllCampaignsByCode = new DataTable();
        public void ShowAllCampaignsListByNPOFromDB(string NPO_code)
        {
            getAllCampaignsByCode.Clear();
            DS_UsersQ DS_UsersQ = new DS_UsersQ();
            getAllCampaignsByCode = DS_UsersQ.Send_getAllCampaignsListByNPO_CodeQuery(NPO_code);
        }
        

        public DataTable getAllCampaigns = new DataTable();
        public void ShowAllCampaignsListFromDB()
        {
            getAllCampaigns.Clear();
            DS_UsersQ DS_UsersQ = new DS_UsersQ();
            getAllCampaigns = DS_UsersQ.Send_getAllCampaignsListQuery();
        }


        //*************************************************************** Company ***********************************

        public DataTable getProductList = new DataTable();
        public void ShowProductListFromDB(string BC_code)
        {
          DS_UsersQ dS_UsersQ = new DS_UsersQ();
          getProductList = dS_UsersQ.Send_getProductListQuery(BC_code);
        }

        public void Delete_Product(string productCode)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            dS_UsersQ.DeleteProductQuery(productCode);
        }

        public DataTable getOrderDetail = new DataTable();
        public void ShowOrderDetailForCompanyFromDB(string BC_code)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            getOrderDetail = dS_UsersQ.Send_getOrderDetailQuery(BC_code);
        }

        public void UpdateIs_sendInDB(M_Order m_Order)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            dS_UsersQ.Is_sendForOrderQuery(m_Order);
        }

        
        //*************************************************************** Activist ***********************************

        public DataTable getProductListForActivist = new DataTable();
        public void ShowProductListForActivistFromDB(string Campaign_code)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            getProductListForActivist = dS_UsersQ.Send_getProductListForActivistQuery(Campaign_code);
        }

        public DataTable getNewMoneyStatusForActivist = new DataTable();
        public void ShowNewMoneyStatusForActivistFromDB(string NEWMoneyStatus,string SA_Code)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            getNewMoneyStatusForActivist = dS_UsersQ.Send_getNEWMoneyStatusForActivistQuery(NEWMoneyStatus, SA_Code);
        }

        public DataTable getAllMyProductForActivist = new DataTable();
        public void ShowAllMyProductForActivistFromDB(string SA_code)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            getAllMyProductForActivist = dS_UsersQ.Send_getAllMyProductForActivistQuery(SA_code);
        }


        public DataTable getMoneyStatusForActivist = new DataTable();
        public void UpdateMoneyStatusInDB(string userInfoCode)
        {
            DS_UsersQ dS_UsersQ = new DS_UsersQ();
            getMoneyStatusForActivist = dS_UsersQ.MoneyByTwitterQuery(userInfoCode);
        }

    }

}
