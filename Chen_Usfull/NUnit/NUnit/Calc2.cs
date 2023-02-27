using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NUnit
{
    public class Calc2
    {
        public int plus(int x, int y)
        {
            return x + y;
        }

        public int minus(int x, int y)
        {
            return x - y;
        }

        public int mult(int x, int y)
        {
            return x * y;
        }

        public int div(int x, int y)
        {
            if (y == 0)
            {
                throw new ArgumentException("Divisor cannot be zero.");
            }

            return x / y;
        }
        public int Calculate(int x, int y, Func<int, int, int> operation)
        {
            int result = operation(x, y);
            return result;
        }
    }
}
