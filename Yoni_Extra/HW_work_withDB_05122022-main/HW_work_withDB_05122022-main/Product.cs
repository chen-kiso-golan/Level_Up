using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CW10_WorkingWithDB
{
    internal class Product
    {
            public Product(int Id, string Name, SqlMoney Price, int Stock)
            {
                ProductId = Id;
                ProductName = Name;
                UnitPrice = Price;
                UnitInStock = Stock;
            }

            private int _productId;
            public int ProductId
            {
                get { return _productId; }
                set { _productId = value; }
            }

            private string _productName;
            public string ProductName
            {
                get { return _productName; }
                set { _productName = value; }
            }

            private SqlMoney _unitPrice;
            public SqlMoney UnitPrice
            {
                get { return _unitPrice; }
                set { _unitPrice = value; }
            }

            private int _unitInStock;
            public int UnitInStock
            {
                get { return _unitInStock; }
                set { _unitInStock = value; }
            }
    }
}

