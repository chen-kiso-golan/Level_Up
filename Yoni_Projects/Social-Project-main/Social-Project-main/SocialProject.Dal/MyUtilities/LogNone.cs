﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyUtilities_CS_yoni
{
    public class LogNone: ILogger
    {
        public void Init() { }
        public void LogEvent(string msg) { }
        public void LogError(string msg) { }
        public void LogException(string msg, Exception exce) { }
        public void LogCheckHouseKeeping() { }
    }
}
