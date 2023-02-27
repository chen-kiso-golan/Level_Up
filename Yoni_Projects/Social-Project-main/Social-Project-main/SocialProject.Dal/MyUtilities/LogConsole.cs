using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyUtilities_CS_yoni
{
    public class LogConsole: ILogger
    {
        public void Init()
        {
        }

        public void LogEvent(string message)
        {
            Console.WriteLine("[EVENT][" + DateTime.Now + "] " + message);
        }


        public void LogError(string message)
        {
            Console.WriteLine("[ERROR][" + DateTime.Now + "] " + message);
        }

        public void LogException(string message, Exception ex)
        {
            Console.WriteLine("[EXCEPTION][" + DateTime.Now + "] " + ex.Message);
            Console.WriteLine("Stack Trace: " + ex.StackTrace);
        }

        public void LogCheckHouseKeeping()
        {
        }
    }
}
