using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Data.Sql
{
    public class BaseDataSql
    {
        public LogManager Log;
        public BaseDataSql(LogManager log) { Log = log; }

        public BaseDataSql() { }
    }
}
