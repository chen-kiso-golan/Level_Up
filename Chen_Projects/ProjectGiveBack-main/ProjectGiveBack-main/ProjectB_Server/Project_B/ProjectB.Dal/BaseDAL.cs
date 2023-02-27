using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Dal
{
    public class BaseDAL
    {
            public static LogManager Log;
            public BaseDAL(LogManager log) { Log = log; }
            public BaseDAL() { }
    }
}
