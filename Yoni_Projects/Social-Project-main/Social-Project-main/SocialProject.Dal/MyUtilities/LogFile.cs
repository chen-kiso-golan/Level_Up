using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace MyUtilities_CS_yoni
{
    public class LogFile: ILogger
    {
        private string fileName;
        public string FileName
        {
            get { return fileName; }
            set { fileName = value; }
        }

        private static int count = 0;
        private static int MaxFileSize = 5 * 1024 * 1024;

        public void Init() 
        {
            FileName = $"Log{count}_{DateTime.Now}.txt";
            using (File.Create(FileName)) { }
        }
        public void LogEvent(string msg)
        {
            try
            {
                using (StreamWriter sw = new StreamWriter(FileName, true))
                {
                    sw.WriteLine(msg + DateTime.Now);
                }
                
            }
            catch (Exception e)
            {
                LogException($"there was a problem with LogEvent function: {e.Message}", e);
            }
        }

        public void LogError(string msg)
        {
            try
            {
                using (StreamWriter sw = new StreamWriter(FileName, true))
                {
                    sw.WriteLine(msg + DateTime.Now);
                }

            }
            catch (Exception e)
            {
                LogException($"there was a problem with LogError function: {e.Message}", e);
                throw;
            }
        }
        public void LogException(string msg, Exception exce)
        {
            try
            {
                using (StreamWriter sw = new StreamWriter(FileName, true))
                {
                    sw.WriteLine(msg + DateTime.Now);
                    sw.WriteLine(exce.ToString() + DateTime.Now);
                }

            }
            catch (Exception e)
            {
                LogError($"there was a problem with LogException function: {e.Message}");
                throw;
            }
        }
        public void LogCheckHouseKeeping()
        {
            FileInfo file = new FileInfo(FileName);
            try
            {
                if (file.Length > MaxFileSize) // check size in bytes
                {
                    count++;
                    Init();
                }
            }
            catch (Exception e)
            {
                LogException($"there was a problem with 'CheckFileSize' function: {e.Message}", e);
                Console.WriteLine($"there was a problem with 'CheckFileSize' function: {e.Message}");
                throw;
            }

        }
    }
}


