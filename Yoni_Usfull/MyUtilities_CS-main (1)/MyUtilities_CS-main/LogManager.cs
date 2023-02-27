﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Text;
using System.Threading.Tasks;

namespace MyUtilities_CS_yoni
{
    public class LogManager
    {
        public enum providerType
        {
            File, DB, Console, none
        }

        public static ILogger MyLog { get; set; }

        public LogManager(providerType aProvider) 
        {
            if (aProvider == providerType.File)
            {
                MyLog = new LogFile();
            }
            else if (aProvider == providerType.DB)
            {
                MyLog = new LogDB();
            }
            else if (aProvider == providerType.Console)
            {
                MyLog = new LogConsole();
            }
            else
            {
                MyLog = new LogNone();
            }

            MyLog.Init();
            LogQueue = new Queue<SingleLogData>();
            DequeueMyLog();
            CheckHouseKeeping();
            
        }

        //log queue
        private static System.Collections.Generic.Queue<SingleLogData> LogQueue;

        //thread for dequeue
        private void DequeueMyLog()
        {
            bool stop = false;

            Task.Run(() =>
            {
                while (!stop)
                {
                    if (LogManager.LogQueue.Count > 0)
                    {
                        SingleLogData item = LogManager.LogQueue.Dequeue();
                        if (item.LogType == "Event")
                        {
                            MyLog.LogEvent(item.msg);
                        }
                        else if (item.LogType == "Error")
                        {
                            MyLog.LogError(item.msg);
                        }
                        else if (item.LogType == "Exception")
                        {
                            MyLog.LogException(item.msg, item.exce);
                        }
                    }
                   Thread.Sleep(1000);
                }

            });
        }

        private void CheckHouseKeeping()
        {
            bool stop = false;

            Task.Run(() =>
            {
                while (!stop)
                {
                    MyLog.LogCheckHouseKeeping();
                    Thread.Sleep(1000*60*60); //MiliSecond * Second * minute
                }

            });
        }
        public static void LogEvent(string msg)
        {
            if (MyLog != null)
            {
                SingleLogData item = new SingleLogData("Event", msg);
                LogManager.LogQueue.Enqueue(item);
            }
        }

        public static void LogError(string msg)
        {
            if (MyLog != null)
            {
                SingleLogData item = new SingleLogData("Error", msg);
                LogManager.LogQueue.Enqueue(item);
            }
        }

        public static void LogException(string msg, Exception exce)
        {
            if (MyLog != null)
            {
                SingleLogData item = new SingleLogData("Error", msg, exce);
                LogManager.LogQueue.Enqueue(item);
            }
        }

    }

}
