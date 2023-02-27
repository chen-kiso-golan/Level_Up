using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs_Start_13112022
{
    internal class penBooster
    {
        private pen[] penArr1;
        public penBooster(pen[] penArr)
        {
            this.penArr1 = penArr;  
        }
        public void printBlue()
        {
            int sumPenBlue=0;
            for(int i=0; i<penArr1.Length;i++)
            {
                if (penArr1[i].color == "blue")
                {
                    sumPenBlue++;
                }
            }
            Console.WriteLine("you have "+sumPenBlue+ " Blue color");
        }
        public void printRed()
        {
            int sumPenRed = 0;
            for (int i = 0; i < penArr1.Length; i++)
            {
                if (penArr1[i].color == "red")
                {
                    sumPenRed++;
                }
            }
            Console.WriteLine("you have " + sumPenRed + " Red color");
        }
        public void printBlack()
        {
            int sumPenBlack = 0;
            for (int i = 0; i < penArr1.Length; i++)
            {
                if (penArr1[i].color == "black")
                {
                    sumPenBlack++;
                }
            }
            Console.WriteLine("you have " + sumPenBlack + " Black color");
        }
    }
}
