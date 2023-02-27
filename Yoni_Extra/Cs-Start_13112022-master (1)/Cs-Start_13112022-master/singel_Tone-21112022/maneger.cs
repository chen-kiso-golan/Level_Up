using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace singel_Tone_21112022
{
	
    internal class maneger
    {
        private maneger() { }

        private readonly static maneger _Instance = new maneger();

        public static maneger Instance
        {
            get
            { return _Instance; }

        }

        //** creat the bank array

        Bank[] bankArray;

        public const string BANK_FILE = "snifim.txt";
        public int fileLineCounter()
        {
            StreamReader sr = new StreamReader(BANK_FILE);
            sr.ReadLine();
            int count = 0;
            while (sr.ReadLine() is string line)
            {
                count++;
            }
            return count;
        }

        //*** read the banks file and take the ditails to the array

        public void LoadFile(string BANK_FILE)
        {

            bankArray = new Bank[fileLineCounter()];
            StreamReader sr = new StreamReader(BANK_FILE);
            sr.ReadLine();
            string bankLine;
            string[] bankInfoArray;
            for (int i = 0; i < fileLineCounter(); i++)
            {
                bankLine = sr.ReadLine();
                bankInfoArray = bankLine.Split(',');

                bankArray[i] = new Bank(bankInfoArray[0], bankInfoArray[2]);
                bankArray[i].bankName = bankInfoArray[1];
                bankArray[i].adress = bankInfoArray[4];
                bankArray[i].city = bankInfoArray[5];
                bankArray[i].phoneNumber = bankInfoArray[8];
            }
        }


        //*** get bank id from user and find it in bankArray
        public Bank GetSnif(string bankCode, string snifNUm)
        {
            Bank FounfBank = null;

            for (int i = 0; i < bankArray.Length; i++)
            {
                if (bankArray[i].bankId == bankCode && bankArray[i].branchId == snifNUm)
                {
                    FounfBank = bankArray[i];
                }
            }
            return FounfBank;
        }

    }
}
