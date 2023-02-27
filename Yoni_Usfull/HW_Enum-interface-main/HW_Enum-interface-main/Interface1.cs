using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CW9_TheInterfaceApp
{

    //public class Run
    //{
    //    Cola Cola1 = new Cola();
    //}
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
