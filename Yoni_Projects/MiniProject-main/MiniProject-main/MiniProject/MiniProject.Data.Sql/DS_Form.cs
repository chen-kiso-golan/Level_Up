using MiniProject.Model;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MiniProject.Data.Sql
{
    public class DS_Form
    {
        //הכנסת אורח לטבלה במסד הנתונים
        public void EnterFormToDB(M_InsertFormToDB M_InsertFormToDB3)
        {       
            string sqlQuery = "insert into Form values ('"+ M_InsertFormToDB3.FirstName+"','"+ M_InsertFormToDB3.LastName +"','"+ M_InsertFormToDB3.Email + "','"+ M_InsertFormToDB3.Password + "','"+ M_InsertFormToDB3.Comments + "','"+ M_InsertFormToDB3.JoinedNewsletter + "')";
            MiniProject.Dal.SqlQuery.WriteToDB(sqlQuery);
        }
    }
}
