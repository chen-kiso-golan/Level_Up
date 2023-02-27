using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NUnit
{
    public class Calc
    {
        public int Plus (int a, int b)
        {
            return a + b;
        }

        public int Minus(int a, int b)
        {
            return a - b;
        }

        public int Mult(int a, int b)
        {
            return a * b;
        }

        public int Div(int a, int b)
        {
            return a / b;
        }

        public enum Operation
        {
            Add,
            Subtract,
            Multiply,
            Divide,
        }
        public int UserChoise(int a, int b, Operation c)
        {
            switch (c)
            {
                case Operation.Add:
                    return Plus(a, b);
                case Operation.Subtract:
                    return Minus(a, b);
                case Operation.Multiply:
                    return Mult(a, b);
                case Operation.Divide:
                    return Div(a, b);
                default:
                    return 0;
            }
        }





    }
}

