using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs_Start_13112022
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Random random = new Random();

            pen pen1 = new pen("red");
            pen1.length = 2;
            pen1.lengthHOD = 1.2f; 
            pen1.print();
            pen1.SetRandonSize();
            pen1.SetRandonSize();
            pen1.SetRandonSize();

            int RndColor=0;

            pen[] penArr = new pen[1000];
            for(int i = 0; i < penArr.Length; i++)
            {
                RndColor = random.Next(1, 4);
                if (RndColor == 1) {
                    penArr[i] = new pen("red");
                    penArr[i].length = random.Next(10,26);
                    penArr[i].lengthHOD = random.Next();
                }
                else if(RndColor == 2) {
                    penArr[i] = new pen("blue");
                    penArr[i].length = random.Next(10, 26);
                    penArr[i].lengthHOD = random.Next();
                }
                else {
                    penArr[i] = new pen("black");
                    penArr[i].length = random.Next(10, 26);
                    penArr[i].lengthHOD = random.Next();
                }
                
            }
            penBooster penBooster1 = new penBooster(penArr);

            penBooster1.printBlack();
            penBooster1.printRed();
            penBooster1.printBlue();


            Console.ReadLine();
        }
    }
}


////**************Q1-4***************
//Console.WriteLine("please enter a name:");
//string str = Console.ReadLine();

//Console.WriteLine("How meny times you want to doplicate your name?");
//int num = int.Parse(Console.ReadLine());
//for (int i = 1; i <= num; i++)
//{
//    Console.WriteLine("#" + i + "-shlom " + str);
//}
//Console.ReadLine();

//int Rnum;
//int countMAX=0;
//int countMIN=0;
//for (int i = 0; i < 1000; i++)
//{
//    Rnum = random.Next(99, 1000);
//    if (Rnum >= 500)
//    {
//        countMAX++;

//    }
//    else
//    {
//        countMIN++;
//    }
//}
//Console.WriteLine("you have "+countMAX+" above 500");
//Console.WriteLine("you have " + countMIN + " under 500");