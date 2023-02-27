using MiniProject.Model;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MiniProject.Data.Sql;

namespace MiniProject.Entities
{
    public class InsertFormToDB
    {     
        public void SendFormToDB(M_InsertFormToDB M_InsertFormToDB)
        {
            DS_Form dS_Form = new DS_Form();
            dS_Form.EnterFormToDB(M_InsertFormToDB);
        }
    }
}
