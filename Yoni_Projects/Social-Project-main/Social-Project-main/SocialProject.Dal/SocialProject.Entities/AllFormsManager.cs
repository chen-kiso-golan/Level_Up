using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SocialProject.Model;
using SocialProject.DataSql;

namespace SocialProject.Entities
{
    public class AllFormsManager :BaseEntity
    {
        public void SendContactUsFormToDB(M_ContactUs m_ContactUs)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterContactUsFormToDB(m_ContactUs);
        }

        public void SendSocialActivistFormToDB(M_SocialActivist m_Social)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterSocialActivistFormToDB(m_Social);
        }

        public void SendNPOFormToDB(M_NonProfitOrganization m_NonProfit)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterNPOFormToDB(m_NonProfit);
        }

        public void SendCompanyFormToDB(M_BusinessCompany m_Company)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterCompanyFormToDB(m_Company);
        }
        public void SendCampaignForm_ToDB(M_Campaign m_Campaign)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterCampaignFormToDB(m_Campaign);
        }

        public void SendEditCampaignForm_ToDB(M_Campaign m_Campaign)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterEditCampaignFormToDB(m_Campaign);
        }
        public void SendProductForm_ToDB(M_Product m_Product)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterProductFormToDB(m_Product);
        }
        public void SendEditProductForm_ToDB(M_Product m_Product)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterEditProductFormToDB(m_Product);
        }

        //************************************Order******************** 

        public void SendOrderDetailsFormToDB(M_Order m_Order,int UnitsInStock)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterOrderDetailsFormToDB(m_Order, UnitsInStock);
        }


        //*********************************Twitter**************

        public void SendTweetToDB(M_Campaign m_Campaign, string SA_code)
        {
            DS_Forms dS_Form = new DS_Forms();
            dS_Form.EnterTweetToDB(m_Campaign, SA_code);
        }

        
    }
}
