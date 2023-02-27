using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CW17_WinFormsAppLink
{
    interface Ilogger
    {
        void Init();
       public void LogEvent(string msg);
       public void LogException(string msg,Exception exce);

       public void LogCheckHoseKeeping();
    }
    internal class Provider
    {
        class Logger
        {
            static Ilogger myLog;
            public static void LogEvent(string msg)
            {
                myLog.LogEvent(msg);
            }
            public static void LogException(string msg, Exception exce)
            {
                myLog.LogException(msg ,null);
            }
        }

        public enum providerType
        {
            car, korkinet,none
        }
        public IMotion CurrMotion { get; set; }


        public IMotion Run(providerType aProvider)
        {
            if(aProvider == providerType.car)
            {
                //car
                CurrMotion = new Car();
            }
            else if (aProvider == providerType.korkinet)
            {
                //korkinet
                CurrMotion = new korkinet();
            }
            else
            {
                //none
            }

            return CurrMotion;

        }
    }
    //Desing Pattern :Provider

    public interface IMotion
    {
        void F(int km);
        void B(int km);
        int GetKm(int km);
        int Init(int km);
    }

    class Car :IMotion
    {
        public void OpenWindow() { }
        public void F(int km)
        {
            km += km;
        }
        public void B(int km)
        {
            km += km;
        }
        public int GetKm(int km)
        {
            return km;
        }
        public int Init(int km)
        {
            return km = 0;
        }
    }

    class korkinet : IMotion
    {
        public void OpenWindow() { }
        public void F(int km)
        {
            km += km;
        }
        public void B(int km)
        {
            km += km;
        }
        public int GetKm(int km)
        {
            return km;
        }
        public int Init(int km)
        {
           return km = 0;
        }
    }

}
