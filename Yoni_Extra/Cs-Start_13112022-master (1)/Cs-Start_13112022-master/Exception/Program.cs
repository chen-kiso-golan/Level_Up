using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace CW5_Exception
{
    internal class Program
    {
        static void Main(string[] args)
        {

            ////Exception_Q1
            //int r = Practice_Exception.GetTwoNumber(10, 0);
            // Console.WriteLine(r);
            ////Exception_Q2
            //double r = Practice_Exception.Divide770();
            // Console.WriteLine(r);

            ////Exception_Q3
            //Practice_Exception.wirteText("hen.txt");
            //Practice_Exception.ReadText("hen.txt");

            ////throwException_Q1 + 2
            //try
            //{
            //    Practice_Exception.Read10Strings();
            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine("massage: " + e.Message);
            //}
            


            Console.ReadLine();
        }
    }

    public class Practice_Exception
    {
        //Exception_Q1
        static public int GetTwoNumber(int a,int b)
        {
            int c;
            try
            {
                c = a / b;
            }
            catch (DivideByZeroException e)
            {

                c = 0;
                Console.WriteLine(e);
            }
         
            return c;
        }

        //Exception_Q2
        static public double Divide770()
        {
            int a = 0;
            double c=0;
            do
            {
                try
                {
                    Console.WriteLine("\nplese enter a number:");
                    a = int.Parse(Console.ReadLine());
                    c = 770/a;
                }
                catch (DivideByZeroException e)
                {

                    Console.WriteLine("\nyou can't divide number with zero\n\n");
                    Console.WriteLine(e);

                }

            } while (a == 0);

            return c;
        }

        //Exception_Q3
        static public void wirteText(string filename)
        {
            StreamWriter sw = new StreamWriter(filename);

            sw.WriteLine("***");
            sw.WriteLine("we are Family");
            sw.WriteLine("***");

            sw.Close();
        }
        static public void ReadText(string filename)
        {
            try
            {
                StreamReader sr = new StreamReader(filename);
                Console.WriteLine(sr.ReadToEnd());
                sr.Close();
            }
            catch (FileNotFoundException e)
            {
                Console.WriteLine(e);
            }
            

           
        }



        //throwException_Q1-7
        static public void Read10Strings()
        {
           string[] myStringArr = new string[10];
           int charCount = 0;
           for (int i = 0; i < 10; i++)
           {
               Console.WriteLine("plaese enter a string to cell #{0}", i);
               myStringArr[i] = Console.ReadLine();
               charCount += myStringArr[i].Length;
               if (charCount > 100)
               {
                   throw new ArgumentException("you passed the 100 characters limit");
               }
           }
        }
    }
}
