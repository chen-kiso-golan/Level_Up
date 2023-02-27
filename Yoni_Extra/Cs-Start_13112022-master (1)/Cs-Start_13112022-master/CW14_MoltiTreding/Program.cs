using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;
using System.Threading;

namespace CW14_MoltiTreding
{
    public class Program
    {
        static void Main(string[] args)
        {

            //PrintLoop pl = new PrintLoop("Hello");
            //pl.LoopAndPrint();


            //FileHandler fileHandler = new FileHandler("mylog");
            //fileHandler.CreateFile();
            //fileHandler.WriteToFile("HelloWorld2");



            ThreadPractis thread = new ThreadPractis();

            ////Q1-multi_thread
            //Thread threadA = new Thread(thread.PrintA);
            ////Task.Run(thread.PrintA);
            //Thread threadB = new Thread(thread.PrintB);

            //threadA.Start();
            //threadB.Start();



            ////Q2-multi_thread
            //Thread threadA2 = new Thread(() => thread.Print("A", 1000));
            //Thread threadB2 = new Thread(() => thread.Print("B", 500));
            //Thread threadC2 = new Thread(() => thread.Print("C", 250));

            //threadA2.Start();
            //threadB2.Start();
            //threadC2.Start();


            ////Q4-multi_thread
            FileLoop _fileLoop = new FileLoop();

            _fileLoop.MultFileTread();




            Console.ReadLine();
        }
    }


    class ThreadPractis
    {
        public void PrintA()
        {
            for (int i = 1; i <= 10; i++)
            {
                Console.WriteLine("A " + i);
                Thread.Sleep(1000); // wait for 1 second
            }
        }

        public void PrintB()
        {
            for (int i = 1; i <= 10; i++)
            {
                Console.WriteLine("B " + i);
                Thread.Sleep(1000); // wait for 1 second
            }
        }

        public void Print(string message, int sleepTime)
        {
            for (int i = 1; i <= 100; i++)
            {
                Console.WriteLine(message + " " + i);
                Thread.Sleep(sleepTime);
            }
        }
    }

    class FileLoop
    {
        static int count = 1;
        public void MultFileTread()
        {
            for (int i = 0; i < 4; i++)
            { 
                FileHandler FileTread = new FileHandler($"logForTread{count}.txt");
                //FileTread.CreateFile();
                Task.Run(FileTread.CreateFile);
                count++;
            }
        }
    }

    class PrintLoop
    {
        private string _inputString;

        public PrintLoop(string inputString)
        {
            _inputString = inputString;
        }

        public void LoopAndPrint()
        {
            for (int i = 1; i <= 10; i++)
            {
                Console.WriteLine(_inputString + " " + i);
            }
        }
    }

    class FileHandler
    {
        public static Object obj = new object();
        Random random = new Random();

        private string fileName;
        

        public FileHandler(string fileName)
        {
            this.fileName = fileName;
        }



        public void CreateFile()
        {
            if (!File.Exists(fileName))
            {
                using (File.Create(fileName))
                {
                    Console.WriteLine("File created successfully.");

                }
                    for (int i = 1; i <= 10; i++)
                    {
                        int num = random.Next(1, 10);
                        WriteToFile(num.ToString());
                    }
            }
            else
            {
                using (File.Create(fileName))
                {
                    Console.WriteLine("create new File: " + fileName);
                }
                    for (int i = 1; i <= 10; i++)
                    {
                        int num = random.Next(1, 10);
                        WriteToFile(num.ToString());
                    }
            }
        }

        public void WriteToFile(string text) 
        {
           if (File.Exists(fileName) && !CheckFileSize()) 
           {
               using (StreamWriter sw = new StreamWriter(fileName,true))
               {
                   sw.WriteLine(text);
               }
           }
           else
           {
               Console.WriteLine("File is full, new file was created");
               File.Create(fileName);
               using (StreamWriter sw = new StreamWriter(fileName, true))
               {
                   sw.WriteLine(text);
               }
           }
        }


        private bool CheckFileSize()
        {
            FileInfo file = new FileInfo(fileName);
            try
            {
                if (file.Length > 1000000) // check size in bytes
                {
                    return true;
                }
            }
            catch (Exception e)
            {
                Console.WriteLine($"there was a problem with 'CheckFileSize' function: {e.Message}");
                throw;
            }
  
            return false;
        }

    }


}
