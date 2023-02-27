using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW_13112022
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Contains
            //CopyTo 
            //Insert 
            //PadRight 
            //Replace 
            //SubString 
            //ToCharArray 
            //Split 
            //Trim 
            //TrimStart 
            //StartWith 
            //IndefOf 
            //CharAt 

            String str = "Hello World";


            String str_Contains = "hello World Family is a good thing";
            String str_Contains2 = "Hello World Family is a good thing";
            bool result1 = str_Contains.Contains(str);
            bool result2 = str_Contains2.Contains(str);
            Console.WriteLine("this is the contain functsion: ");
            Console.WriteLine("result1 " + result1);
            Console.WriteLine("result2 " + result2);



            String str_CopyTo = "hello, Family is a good thing";
            char[] Copy = { 'H', 'y', 'g' };
            str_CopyTo.CopyTo(0, Copy, 0, 1);
            str_CopyTo.CopyTo(7, Copy, 1, 1);
            Console.WriteLine("\nthis is the CopyTo functsion: ");
            Console.WriteLine(Copy);



            String str_Insert = "hello Family is a good thing";
            //str_Insert.Insert(5,"big-"); return a new string
            Console.WriteLine("\nthis is the Insert functsion: ");
            Console.WriteLine("new string: " + str_Insert.Insert(0, "big-"));



            String str_PadRight = "hello Family is a good thing";
            char ped = '.';
            Console.WriteLine("\nthis is the PadRight functsion: ");
            Console.WriteLine("new string: |" + str_PadRight.PadRight(40) + "|");
            Console.WriteLine("new string: |" + str_PadRight.PadRight(40, ped) + "|");


            String str_Replace = "hello Family is a good thing";

            Console.WriteLine("\nthis is the Replace functsion: ");
            Console.WriteLine("new string: " + str_Replace.Replace("hello", "*"));



            String str_SubString = "hello Family is a good thing";
            Console.WriteLine("\nthis is the SubString functsion: ");
            Console.WriteLine("new string: " + str_SubString.Substring(2));
            Console.WriteLine("new string: " + str_SubString.Substring(6, 9));



            String str_ToCharArray = "hello Family is a good thing";
            char[] arr;
            arr = str_ToCharArray.ToCharArray();
            Console.WriteLine("\nthis is the ToCharArray functsion: ");
            Console.Write("new array: ");
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i]);
            }
            arr = str_ToCharArray.ToCharArray(0, 5);
            Console.Write("\nnew array: ");
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i]);
            }

            String str_Split = "hello, Family is a good thing";
            string[] words = str_Split.Split(' ');
            Console.Write("\n\nthis is the Split functsion: ");
            Console.WriteLine("\nnew array: ");
            for (int i = 0; i < words.Length; i++)
            {
                Console.WriteLine(words[i]);
            }



            String str_Trim = ",,,*hello Family is a good thing**";
            char[] ToPull = { '*', ' ', ',' };
            Console.WriteLine("\nthis is the Trim functsion: ");
            Console.WriteLine("new string: " + str_Trim.Trim(ToPull));




            String str_TrimStart = ",,,*hello Family is a good thing**";

            Console.WriteLine("\nthis is the TrimStart functsion: ");
            Console.WriteLine("new string: " + str_TrimStart.TrimStart(','));



            String str_StartsWith = "hello Family is a good thing";

            Console.WriteLine("\nthis is the StartsWith functsion: ");
            Console.WriteLine(str_StartsWith.StartsWith("hello"));
            Console.WriteLine(str_StartsWith.StartsWith("Hello"));


            String str_IndexOf = "hello Family is a good thing";
            Console.WriteLine("\nthis is the IndexOf functsion: ");
            Console.WriteLine(str_IndexOf.IndexOf("Family"));


            String str_CharAt = "hello Family is a good thing";


            Console.ReadLine();
        }
    }
}