using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CW19_Out_Ref
{
    internal class Out_Ref
    {
        static void Main(string[] args)
        {
            //באאוט הפונקציה מחויבת לתוכנית וברף התוכנית מחויבת לפונקציה
            // when we use ref we must iniishata the parameter befor enter to the function

            //int a = 5;
            //MyMethod(ref a);
            //Console.WriteLine(a);


            // when we use out we cen iniishata the parameter befor enter to the function

            //int y =21;
            int y;
            MyMethod2(out y);
            Console.WriteLine(y);


            //דוגמא לשימוש באאוט
            Console.WriteLine("enter a number for TryParseint");
            string str = Console.ReadLine();
            int num;

            if(int.TryParse(str,out num))
            {
                Console.WriteLine(num);
            }


            Console.ReadLine();
        }


        //static void MyMethod(ref int x)
        //{
        //    x = x + 10;
        //}

        static void MyMethod2(out int x)
        {
            x = 10;
        }


      
    }
}
