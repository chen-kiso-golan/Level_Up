using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs_Start_13112022
{
    internal class pen
    {
        
        public String color;
        public float length;
        public float lengthHOD;

        public pen(string color)
        {
            this.color = color;
        }   

        public void print()
        {
            Console.WriteLine("**the color is: "+color +" **the length is: " +length + " **the lengthHOD is: "+ lengthHOD);

        }

        public void SetRandonSize()
        {
           
            Random random = new Random(DateTime.Now.Millisecond);
            System.Threading.Thread.Sleep(50);
            length = random.Next(5, 110);
            Console.WriteLine(length);
        }
    }
}
    