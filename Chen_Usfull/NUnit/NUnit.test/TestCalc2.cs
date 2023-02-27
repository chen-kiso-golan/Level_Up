using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace NUnit.test
{
    [TestFixture]
    public class TestCalc2
    {

            [SetUp]
            public void init() { }


            [Test, Order(1), Category("This is my Test")]
            public void RunTest()
            {
                Assert.AreEqual(10, 10, "should be Equal");


            }

            [Test, Order(4), Ignore("Have not finished yet 'RunTest2'")]
            public void RunTest2()
            {
                int a = 21;
                int b = 22;
                int c = a + b;
                Assert.AreEqual(c, 43);

            }

            [Test, Order(10)]
            public void RunTest3()
            {

                NUnit.Calc2 calc = new NUnit.Calc2();


                Assert.AreEqual(calc.plus(1, 4), 5);
                Assert.AreEqual(calc.mult(1, 4), 4);
                Assert.AreEqual(calc.div(4, 4), 1);
                Assert.AreEqual(calc.minus(4, 4), 0);
                Assert.AreEqual(calc.Calculate(1, 4, calc.mult), 4);


                Assert.That(calc.plus(1, 4), Is.InRange(10, 100));
                Assert.That(calc.plus(1, 4), Is.LessThan(10));
            }
        
    }
}
