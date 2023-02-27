using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace singel_Tone_21112022
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Console.OutputEncoding = System.Text.Encoding.UTF8;
            Console.OutputEncoding = Encoding.GetEncoding("windows-1255");

            maneger.Instance.LoadFile(maneger.BANK_FILE);
            Bank bank1 = maneger.Instance.GetSnif("10", "987");
            Console.WriteLine("NAME: " + bank1.bankName + "\nADRESS: " + bank1.adress + "\nPHONE: " + bank1.phoneNumber + "\nCITY: " + bank1.city);

            //single tone:
            //manger m1 = new manger(); --> dose not work

            //not a single tone:
            //Bank b1 = new Bank("23", "101");  --> dose work

            Console.ReadLine();

        }
    }
}
