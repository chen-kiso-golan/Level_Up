using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;


//****nuget package to instal:
//NUnit3TestAdapter 
//NUNIT
//Microsoft.NET.Test.Sdk

//****add NUnit as reference and using NUnit.Framework;


namespace NUnit.test 
{
    [TestFixture]
    public class TestCalc
    {
        [Test]
        public void RunTest()
        {
            Assert.AreEqual(10, 10);
            Assert.AreEqual(10, 11);
        }
    }
}
