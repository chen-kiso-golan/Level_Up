using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace ProjectB.Entities
{
    public class BasePromotionSystem
    {
        public LogManager Log;
        public BasePromotionSystem(LogManager log) 
        {
            Log = log;
        }
    }
}
