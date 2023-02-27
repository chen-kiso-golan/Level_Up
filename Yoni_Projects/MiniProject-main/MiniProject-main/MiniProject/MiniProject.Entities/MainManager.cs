using System;
using System.Collections;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MiniProject.Entities;

namespace MiniProject.Entities
{
    public class MainManager
    {
        public ProductManager ProductManager1;
        public InsertFormToDB InsertFormToDB1;
        private MainManager()
        {
            ProductManager1 = new ProductManager();
            InsertFormToDB1 = new InsertFormToDB();
        }

        private static readonly MainManager instance = new MainManager();
        public static MainManager Instance { get { return instance; } }



   

    }
}
