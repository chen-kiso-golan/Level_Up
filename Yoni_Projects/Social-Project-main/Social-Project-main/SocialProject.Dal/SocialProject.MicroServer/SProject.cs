using System;
using System.IO;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using RestSharp;
using SocialProject.Model;
using SocialProject.Entities;
using Microsoft.VisualBasic;
using static System.Net.Mime.MediaTypeNames;

namespace SocialProject.MicroServer
{
    public static class SProject
    {
        [FunctionName("SProject")]
        public static async Task<IActionResult> Run(
        [HttpTrigger(AuthorizationLevel.Anonymous, "get", "post", "delete", Route = "Users/{action}/{value?}/{value2?}")] HttpRequest req,
        string action, string value, string value2, ILogger log)
        {
         string requestBody;

         string responseMessage;

         switch (action)
         {
             case "get-role":

                    try
                    {
                        var rolesURL = $"https://dev-yvfkvt7guh4kvmut.us.auth0.com/api/v2/users/{value}/roles";
                        var client = new RestClient(rolesURL);
                        var request = new RestRequest("", Method.Get);
                        request.AddHeader("authorization", "Bearer eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCIsImtpZCI6IjdBR3I4SFdQdmx6MmFIQnVEZ3RkTyJ9.eyJpc3MiOiJodHRwczovL2Rldi15dmZrdnQ3Z3VoNGt2bXV0LnVzLmF1dGgwLmNvbS8iLCJzdWIiOiJXNk41UEFHNk01QUxhMFlpMTFuNGd0emhETks2dWFlOEBjbGllbnRzIiwiYXVkIjoiaHR0cHM6Ly9kZXYteXZma3Z0N2d1aDRrdm11dC51cy5hdXRoMC5jb20vYXBpL3YyLyIsImlhdCI6MTY3MzQ3MDU0NCwiZXhwIjoxNjc2MDYyNTQzLCJhenAiOiJXNk41UEFHNk01QUxhMFlpMTFuNGd0emhETks2dWFlOCIsInNjb3BlIjoicmVhZDpjbGllbnRfZ3JhbnRzIGNyZWF0ZTpjbGllbnRfZ3JhbnRzIGRlbGV0ZTpjbGllbnRfZ3JhbnRzIHVwZGF0ZTpjbGllbnRfZ3JhbnRzIHJlYWQ6dXNlcnMgdXBkYXRlOnVzZXJzIGRlbGV0ZTp1c2VycyBjcmVhdGU6dXNlcnMgcmVhZDp1c2Vyc19hcHBfbWV0YWRhdGEgdXBkYXRlOnVzZXJzX2FwcF9tZXRhZGF0YSBkZWxldGU6dXNlcnNfYXBwX21ldGFkYXRhIGNyZWF0ZTp1c2Vyc19hcHBfbWV0YWRhdGEgcmVhZDp1c2VyX2N1c3RvbV9ibG9ja3MgY3JlYXRlOnVzZXJfY3VzdG9tX2Jsb2NrcyBkZWxldGU6dXNlcl9jdXN0b21fYmxvY2tzIGNyZWF0ZTp1c2VyX3RpY2tldHMgcmVhZDpjbGllbnRzIHVwZGF0ZTpjbGllbnRzIGRlbGV0ZTpjbGllbnRzIGNyZWF0ZTpjbGllbnRzIHJlYWQ6Y2xpZW50X2tleXMgdXBkYXRlOmNsaWVudF9rZXlzIGRlbGV0ZTpjbGllbnRfa2V5cyBjcmVhdGU6Y2xpZW50X2tleXMgcmVhZDpjb25uZWN0aW9ucyB1cGRhdGU6Y29ubmVjdGlvbnMgZGVsZXRlOmNvbm5lY3Rpb25zIGNyZWF0ZTpjb25uZWN0aW9ucyByZWFkOnJlc291cmNlX3NlcnZlcnMgdXBkYXRlOnJlc291cmNlX3NlcnZlcnMgZGVsZXRlOnJlc291cmNlX3NlcnZlcnMgY3JlYXRlOnJlc291cmNlX3NlcnZlcnMgcmVhZDpkZXZpY2VfY3JlZGVudGlhbHMgdXBkYXRlOmRldmljZV9jcmVkZW50aWFscyBkZWxldGU6ZGV2aWNlX2NyZWRlbnRpYWxzIGNyZWF0ZTpkZXZpY2VfY3JlZGVudGlhbHMgcmVhZDpydWxlcyB1cGRhdGU6cnVsZXMgZGVsZXRlOnJ1bGVzIGNyZWF0ZTpydWxlcyByZWFkOnJ1bGVzX2NvbmZpZ3MgdXBkYXRlOnJ1bGVzX2NvbmZpZ3MgZGVsZXRlOnJ1bGVzX2NvbmZpZ3MgcmVhZDpob29rcyB1cGRhdGU6aG9va3MgZGVsZXRlOmhvb2tzIGNyZWF0ZTpob29rcyByZWFkOmFjdGlvbnMgdXBkYXRlOmFjdGlvbnMgZGVsZXRlOmFjdGlvbnMgY3JlYXRlOmFjdGlvbnMgcmVhZDplbWFpbF9wcm92aWRlciB1cGRhdGU6ZW1haWxfcHJvdmlkZXIgZGVsZXRlOmVtYWlsX3Byb3ZpZGVyIGNyZWF0ZTplbWFpbF9wcm92aWRlciBibGFja2xpc3Q6dG9rZW5zIHJlYWQ6c3RhdHMgcmVhZDppbnNpZ2h0cyByZWFkOnRlbmFudF9zZXR0aW5ncyB1cGRhdGU6dGVuYW50X3NldHRpbmdzIHJlYWQ6bG9ncyByZWFkOmxvZ3NfdXNlcnMgcmVhZDpzaGllbGRzIGNyZWF0ZTpzaGllbGRzIHVwZGF0ZTpzaGllbGRzIGRlbGV0ZTpzaGllbGRzIHJlYWQ6YW5vbWFseV9ibG9ja3MgZGVsZXRlOmFub21hbHlfYmxvY2tzIHVwZGF0ZTp0cmlnZ2VycyByZWFkOnRyaWdnZXJzIHJlYWQ6Z3JhbnRzIGRlbGV0ZTpncmFudHMgcmVhZDpndWFyZGlhbl9mYWN0b3JzIHVwZGF0ZTpndWFyZGlhbl9mYWN0b3JzIHJlYWQ6Z3VhcmRpYW5fZW5yb2xsbWVudHMgZGVsZXRlOmd1YXJkaWFuX2Vucm9sbG1lbnRzIGNyZWF0ZTpndWFyZGlhbl9lbnJvbGxtZW50X3RpY2tldHMgcmVhZDp1c2VyX2lkcF90b2tlbnMgY3JlYXRlOnBhc3N3b3Jkc19jaGVja2luZ19qb2IgZGVsZXRlOnBhc3N3b3Jkc19jaGVja2luZ19qb2IgcmVhZDpjdXN0b21fZG9tYWlucyBkZWxldGU6Y3VzdG9tX2RvbWFpbnMgY3JlYXRlOmN1c3RvbV9kb21haW5zIHVwZGF0ZTpjdXN0b21fZG9tYWlucyByZWFkOmVtYWlsX3RlbXBsYXRlcyBjcmVhdGU6ZW1haWxfdGVtcGxhdGVzIHVwZGF0ZTplbWFpbF90ZW1wbGF0ZXMgcmVhZDptZmFfcG9saWNpZXMgdXBkYXRlOm1mYV9wb2xpY2llcyByZWFkOnJvbGVzIGNyZWF0ZTpyb2xlcyBkZWxldGU6cm9sZXMgdXBkYXRlOnJvbGVzIHJlYWQ6cHJvbXB0cyB1cGRhdGU6cHJvbXB0cyByZWFkOmJyYW5kaW5nIHVwZGF0ZTpicmFuZGluZyBkZWxldGU6YnJhbmRpbmcgcmVhZDpsb2dfc3RyZWFtcyBjcmVhdGU6bG9nX3N0cmVhbXMgZGVsZXRlOmxvZ19zdHJlYW1zIHVwZGF0ZTpsb2dfc3RyZWFtcyBjcmVhdGU6c2lnbmluZ19rZXlzIHJlYWQ6c2lnbmluZ19rZXlzIHVwZGF0ZTpzaWduaW5nX2tleXMgcmVhZDpsaW1pdHMgdXBkYXRlOmxpbWl0cyBjcmVhdGU6cm9sZV9tZW1iZXJzIHJlYWQ6cm9sZV9tZW1iZXJzIGRlbGV0ZTpyb2xlX21lbWJlcnMgcmVhZDplbnRpdGxlbWVudHMgcmVhZDphdHRhY2tfcHJvdGVjdGlvbiB1cGRhdGU6YXR0YWNrX3Byb3RlY3Rpb24gcmVhZDpvcmdhbml6YXRpb25zIHVwZGF0ZTpvcmdhbml6YXRpb25zIGNyZWF0ZTpvcmdhbml6YXRpb25zIGRlbGV0ZTpvcmdhbml6YXRpb25zIGNyZWF0ZTpvcmdhbml6YXRpb25fbWVtYmVycyByZWFkOm9yZ2FuaXphdGlvbl9tZW1iZXJzIGRlbGV0ZTpvcmdhbml6YXRpb25fbWVtYmVycyBjcmVhdGU6b3JnYW5pemF0aW9uX2Nvbm5lY3Rpb25zIHJlYWQ6b3JnYW5pemF0aW9uX2Nvbm5lY3Rpb25zIHVwZGF0ZTpvcmdhbml6YXRpb25fY29ubmVjdGlvbnMgZGVsZXRlOm9yZ2FuaXphdGlvbl9jb25uZWN0aW9ucyBjcmVhdGU6b3JnYW5pemF0aW9uX21lbWJlcl9yb2xlcyByZWFkOm9yZ2FuaXphdGlvbl9tZW1iZXJfcm9sZXMgZGVsZXRlOm9yZ2FuaXphdGlvbl9tZW1iZXJfcm9sZXMgY3JlYXRlOm9yZ2FuaXphdGlvbl9pbnZpdGF0aW9ucyByZWFkOm9yZ2FuaXphdGlvbl9pbnZpdGF0aW9ucyBkZWxldGU6b3JnYW5pemF0aW9uX2ludml0YXRpb25zIHJlYWQ6b3JnYW5pemF0aW9uc19zdW1tYXJ5IGNyZWF0ZTphY3Rpb25zX2xvZ19zZXNzaW9ucyBjcmVhdGU6YXV0aGVudGljYXRpb25fbWV0aG9kcyByZWFkOmF1dGhlbnRpY2F0aW9uX21ldGhvZHMgdXBkYXRlOmF1dGhlbnRpY2F0aW9uX21ldGhvZHMgZGVsZXRlOmF1dGhlbnRpY2F0aW9uX21ldGhvZHMiLCJndHkiOiJjbGllbnQtY3JlZGVudGlhbHMifQ.LRO02arLSaap80plLRtDq_XVURyUjWeKLqf_RGpAHJFMkMposoKFxJMDE__Y9fJLHoU2fO6YDmFJrFoKG8XV1QnfQvInzQq39HsTvG0k6KoAitvFp-RFTjVoE3yTQQbyrNnVMz1CMb3sqbD6c_bHWPCuS6cXezOYjMOLwGTDvu9quFnP_p2zLKbCz499jjSmxbeJBxUSDhfQ7UWPr4MzstvCJsRMvsa7AA7Y6Y1l7cGkL-FQnl636NNbrZ70vfo8YGK8ggAjj1t008mL0B9kKmLbwNpjC0HS-oDxnDGE9UBydx98sna6f18jbcoSLY1iOQU3Clm_eE-VEUmK2XmXUw");
                        var response = client.Execute(request);
                        if (response.IsSuccessful)
                        {
                            var json = JArray.Parse(response.Content);
                            return new OkObjectResult(json);
                        }
                        else
                        {
                            return new NotFoundResult();
                        }
                    }
                    catch (Exception)
                    {

                        throw;
                    }
               

                   
             case "get-UserInfoData":

                    try
                    {
                        MainManager.Instance.UsersManager.get_UserInfo_FromDB(value, value2);
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getUserInfo);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }

             case "get-Pending":

                    try
                    {
                        responseMessage = System.Text.Json.JsonSerializer.Serialize(MainManager.Instance.UsersManager.get_Pending_FromDB(value));
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }

                

             case "get-PendingList":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowAllPendingListFromDB();
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getPendingList);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                 

             case "get-AllTwitted":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowTweetsListFromDB();
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getTweetsList);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
               

             case "get-AllSARows":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowSocialActivistListFromDB();
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getSocialActivistList);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                

             case "get-AllNPORows":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowNPOListFromDB();
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getNPOList);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                

             case "get-AllCompanyRows":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowCompanyListFromDB();
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getCompanyList);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                

             case "get-AllCampaignsByNPO_code":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowAllCampaignsListByNPOFromDB(value);
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getAllCampaignsByCode);
                        return new OkObjectResult(responseMessage);

                    }
                    catch (Exception)
                    {

                        throw;
                    }
                
             case "get-AllCampaigns":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowAllCampaignsListFromDB();
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getAllCampaigns);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
               

            case "get-ProductPerCompany":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowProductListFromDB(value);
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getProductList);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
              

            case "get-ProductListForActivist":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowProductListForActivistFromDB(value);
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getProductListForActivist);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                

            case "get-UpdateMoneyStatus":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowNewMoneyStatusForActivistFromDB(value, value2);
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getNewMoneyStatusForActivist);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
               

            case "get-AllMyProduct":
                    try
                    {
                        MainManager.Instance.UsersManager.ShowAllMyProductForActivistFromDB(value);
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getAllMyProductForActivist);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }              

            case "get-OrderDetail":

                    try
                    {
                        MainManager.Instance.UsersManager.ShowOrderDetailForCompanyFromDB(value);
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getOrderDetail);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }
               

            case "post-ContactUs":
                    try
                    {
                        M_ContactUs ContacUSForm = new M_ContactUs();
                        ContacUSForm = System.Text.Json.JsonSerializer.Deserialize<M_ContactUs>(req.Body);
                        MainManager.Instance.AllFormsManager.SendContactUsFormToDB(ContacUSForm);
                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                
                    
            case "post-SocialActivist":

                    try
                    {
                        M_SocialActivist SocialActivistForm = new M_SocialActivist();
                        SocialActivistForm = System.Text.Json.JsonSerializer.Deserialize<M_SocialActivist>(req.Body);
                        MainManager.Instance.AllFormsManager.SendSocialActivistFormToDB(SocialActivistForm);
                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }
               
                   
             case "post-NPO":

                    try
                    {
                        M_NonProfitOrganization NPOForm = new M_NonProfitOrganization();
                        NPOForm = System.Text.Json.JsonSerializer.Deserialize<M_NonProfitOrganization>(req.Body);
                        MainManager.Instance.AllFormsManager.SendNPOFormToDB(NPOForm);
                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                

             case "post-Company":

                    try
                    {
                        M_BusinessCompany CompanyForm = new M_BusinessCompany();
                        CompanyForm = System.Text.Json.JsonSerializer.Deserialize<M_BusinessCompany>(req.Body);
                        MainManager.Instance.AllFormsManager.SendCompanyFormToDB(CompanyForm);
                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                 

             case "post-sendToOrderDetails":

                    try
                    {
                        M_Order m_Order = new M_Order();
                        m_Order = System.Text.Json.JsonSerializer.Deserialize<M_Order>(req.Body);
                        MainManager.Instance.AllFormsManager.SendOrderDetailsFormToDB(m_Order, int.Parse(value));
                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                

             case "update-Is_Approved":

                    try
                    {
                        requestBody = await new StreamReader(req.Body).ReadToEndAsync();
                        M_Register_Applications Is_ApprovedUpdate = System.Text.Json.JsonSerializer.Deserialize<M_Register_Applications>(requestBody);
                        MainManager.Instance.UsersManager.UpdateApproveUserInDB(Is_ApprovedUpdate);
                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                

             case "update-Is_Active":

                    try
                    {
                        requestBody = await new StreamReader(req.Body).ReadToEndAsync();
                        M_Campaign Is_ActiveUpdate = System.Text.Json.JsonSerializer.Deserialize<M_Campaign>(requestBody);
                        MainManager.Instance.UsersManager.UpdateIs_ActiveInDB(Is_ActiveUpdate);
                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                

             case "update-Is_send":

                    try
                    {
                        requestBody = await new StreamReader(req.Body).ReadToEndAsync();
                        M_Order Is_sendUpdate = System.Text.Json.JsonSerializer.Deserialize<M_Order>(requestBody);
                        MainManager.Instance.UsersManager.UpdateIs_sendInDB(Is_sendUpdate);
                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }           

             case "update-AddMoneyStatus":

                    try
                    {
                        MainManager.Instance.UsersManager.UpdateMoneyStatusInDB(value);
                        responseMessage = JsonConvert.SerializeObject(MainManager.Instance.UsersManager.getOrderDetail);
                        return new OkObjectResult(responseMessage);
                    }
                    catch (Exception)
                    {

                        throw;
                    }            

             case "post-AddOrEditCampaigns":
                    try
                    {
                        if (value == "Add")
                        {
                            M_Campaign m_Campaign = new M_Campaign();
                            m_Campaign = System.Text.Json.JsonSerializer.Deserialize<M_Campaign>(req.Body);
                            MainManager.Instance.AllFormsManager.SendCampaignForm_ToDB(m_Campaign);
                            break;
                        }
                        else if (value == "Edit")
                        {
                            M_Campaign m_Campaign = new M_Campaign();
                            m_Campaign = System.Text.Json.JsonSerializer.Deserialize<M_Campaign>(req.Body);
                            MainManager.Instance.AllFormsManager.SendEditCampaignForm_ToDB(m_Campaign);
                            break;
                        }
                    }
                    catch (Exception)
                    {

                        throw;
                    }
               
                 break;

             case "post-AddOrEditProduct":
                    try
                    {
                        if (value == "Add")
                        {
                            M_Product m_Product = new M_Product();
                            m_Product = System.Text.Json.JsonSerializer.Deserialize<M_Product>(req.Body);
                            MainManager.Instance.AllFormsManager.SendProductForm_ToDB(m_Product);
                            break;
                        }
                        else if (value == "Edit")
                        {
                            M_Product m_Product = new M_Product();
                            m_Product = System.Text.Json.JsonSerializer.Deserialize<M_Product>(req.Body);
                            MainManager.Instance.AllFormsManager.SendEditProductForm_ToDB(m_Product);
                            break;
                        }
                    }
                    catch (Exception)
                    {

                        throw;
                    }
               
                 break;

             case "Post-tweet":

                    try
                    {
                        M_Campaign m_Campaign1 = new M_Campaign();
                        m_Campaign1 = System.Text.Json.JsonSerializer.Deserialize<M_Campaign>(req.Body);
                        MainManager.Instance.AllFormsManager.SendTweetToDB(m_Campaign1, value);
                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }             

             case "delete-CompanyProduct":
                    try
                    {
                        MainManager.Instance.UsersManager.Delete_Product(value);

                        break;
                    }
                    catch (Exception)
                    {

                        throw;
                    }
                   

             default:
                 break;

         }


         return null;
        }
    }
}
