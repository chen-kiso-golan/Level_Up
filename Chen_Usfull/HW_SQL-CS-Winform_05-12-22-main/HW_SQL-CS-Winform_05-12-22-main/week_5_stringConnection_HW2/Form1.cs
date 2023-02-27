using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace week_5_stringConnection_HW2
{
    public partial class Form1 : Form
    {
        const string connectionString = @"Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Northwind;Data Source=localhost\sqlexpress";
                
        public Form1()
        {
            InitializeComponent();
        }

        //-----------------------------------------------------------------------------------------q1
        int result = 0;

        //customersBtn - problem with name, could not change
        private void OrderTextbox_Click(object sender, EventArgs e)
        {
            try
            {
                // Connection
                using (SqlConnection connection = new SqlConnection(connectionString))
                {

                    string queryString = "select COUNT([CustomerID]) from [dbo].[Customers]";

                    // Adapter
                    using (SqlCommand command = new SqlCommand(queryString, connection))
                    {
                        connection.Open();

                        //Reader
                        using (SqlDataReader reader = command.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                int num = reader.GetInt32(0);
                                result = num;
                                MessageBox.Show("there are " + result.ToString() + " customers!");
                            }
                        }
                    }

                }


            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void OrdersBtn_Click(object sender, EventArgs e)
        {
            try
            {
                // Connection
                using (SqlConnection connection = new SqlConnection(connectionString))
                {

                    string queryString = "select COUNT([OrderID]) from [dbo].[Orders]";

                    // Adapter
                    using (SqlCommand command = new SqlCommand(queryString, connection))
                    {
                        connection.Open();

                        //Reader
                        using (SqlDataReader reader = command.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                int num = reader.GetInt32(0);
                                result = num;
                                textBox1.Text = result.ToString();
                            }
                        }
                    }

                }


            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }


        //------------------------------------------------------------------------------------------q2
        Hashtable workersTbl = new Hashtable();
        int HtblKey;
        private void RefreshBtn_Click(object sender, EventArgs e)
        {
            workersTbl.Clear();

            try
            {
                // Connection
                using (SqlConnection connection = new SqlConnection(connectionString))
                {

                    string queryString = "select [EmployeeID],[FirstName],[LastName] from [dbo].[Employees]";

                    // Adapter
                    using (SqlCommand command = new SqlCommand(queryString, connection))
                    {
                        connection.Open();

                        //Reader
                        using (SqlDataReader reader = command.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                int employeeID = reader.GetInt32(reader.GetOrdinal("EmployeeID"));
                                string lastName = reader.GetString(reader.GetOrdinal("LastName"));
                                string firstName = reader.GetString(reader.GetOrdinal("FirstName"));
                                workersTbl.Add(employeeID, (lastName + " " + firstName));
                            }
                        }
                    }

                }


            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void WorkerIdFromUser_TextChanged(object sender, EventArgs e)
        {
            HtblKey = Convert.ToInt32(WorkerIdFromUser.Text);
        }

        private void WorkerBtn_Click(object sender, EventArgs e)
        {
            MessageBox.Show(Convert.ToString(workersTbl[HtblKey]));
        }


        //-------------------------------------------------------------------------------------------q3
        public class Product
        {
            public Product(int Id, string Name, SqlMoney Price, int Stock)
            {
                this.ProductId = Id;
                this.ProductName = Name;
                this.UnitPrice = Price;
                this.UnitInStock = Stock;
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

        Hashtable ProductTbl = new Hashtable();

        private void RefreshProductsBtn_Click(object sender, EventArgs e)
        {
            ProductTbl.Clear();
            // Connection
            using (SqlConnection connection = new SqlConnection(connectionString))
            {

                string queryString = "select [ProductID], [ProductName], [UnitPrice], [UnitsInStock] from [dbo].[Products]";

                // Adapter
                using (SqlCommand command = new SqlCommand(queryString, connection))
                {
                    connection.Open();

                    //Reader
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            int ProductID = reader.GetInt32(reader.GetOrdinal("ProductID"));
                            string ProductName = reader.GetString(reader.GetOrdinal("ProductName"));
                            SqlMoney UnitPrice = reader.GetSqlMoney(reader.GetOrdinal("UnitPrice"));
                            int UnitInStock = reader.GetInt16(reader.GetOrdinal("UnitsInStock"));
                            Product NP = new Product(ProductID, ProductName, UnitPrice, UnitInStock);
                            ProductTbl.Add(NP.ProductId, NP);
                        }
                    }
                }
            }
        }

        private void ShowProductBtn_Click(object sender, EventArgs e)
        {
            Product pulledProduct = (Product)ProductTbl[Convert.ToInt32(ProductIdFromUser.Text)];
            ProductPriceLabel.Text = "Price : " + pulledProduct.UnitPrice.Value.ToString();
            ProductUnitLabel.Text = "Number of Units : " + pulledProduct.UnitInStock.ToString();
            ProductNameLabel.Text = "Name : " + pulledProduct.ProductName;
        }

        private void ProductIdFromUser_TextChanged(object sender, EventArgs e)
        {

        }

        private void ProductPriceLabel_Click(object sender, EventArgs e)
        {
            
        }

        private void ProductUnitLabel_Click(object sender, EventArgs e)
        {

        }

        private void ProductNameLabel_Click(object sender, EventArgs e)
        {

        }

        private void groupBox4_Enter(object sender, EventArgs e)
        {

        }

        private void ProductsAbovePriceBtn_Click(object sender, EventArgs e)
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {

                string queryString = "select count([ProductID]) from [dbo].[Products] where [UnitPrice]>"+textBox2.Text;

                // Adapter
                using (SqlCommand command = new SqlCommand(queryString, connection))
                {
                    connection.Open();

                    //Reader
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            int ProductNum = reader.GetInt32(0);
                            MessageBox.Show("there are " + ProductNum.ToString() + " products above your price!");
                        }
                    }
                }
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
