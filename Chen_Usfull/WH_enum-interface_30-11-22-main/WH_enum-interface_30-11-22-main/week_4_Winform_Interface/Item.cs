using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace week_4_Winform_Interface
{
    internal interface Item
    {
        public int GetPrice(); 
    }

    public class Cola : Item    
    {
        public int GetPrice()
        {
            return 10;
        }
    }

    public class Kinly : Item
    {
        public int GetPrice()
        {
            return 11;
        }
    }

}