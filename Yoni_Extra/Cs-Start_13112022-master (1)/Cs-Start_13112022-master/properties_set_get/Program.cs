using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace properties_set_get
{
    internal class Program
    {
        static void Main(string[] args)
        {
            car car1= new car();

            //posibale to do:
            car1.Km = car1.Km + 100;
            car1.CarName = "toyota";
            car1.CarName = "mazda";
            car1.CarName = "nissan";
            Console.WriteLine("car mame is: "+ car1.CarName +", car km is: "+ car1.Km +", car id is: " +car1.Id );

            //not posibale to do:
            car1.Km = car1.Km - 200;
            car1.CarName = "shevi";
            //car1.Id = 2067;
            Console.WriteLine("car mame is: " + car1.CarName + ", car km is: " + car1.Km + ", car id is: " + car1.Id);

            Console.ReadLine(); 
        }
    }
}
