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
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace CW10_WorkingWithDB
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        const string ConnectionString = @"Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Northwind;Data Source=localhost\sqlexpress";
        
        Hashtable tbl = new Hashtable();




        private void prodect_btn_Click(object sender, EventArgs e)
        {
            try
            {
                // Connection
                using (SqlConnection connection = new SqlConnection(ConnectionString))
                {

                    string queryString = "select COUNT([OrderID]) as countOrder from [dbo].[Orders]";

                    // Adapter
                    using (SqlCommand command = new SqlCommand(queryString, connection))
                    {
                        connection.Open();

                        //Reader
                        using (SqlDataReader reader = command.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                textBox_product.Text = reader.GetInt32(0).ToString();
                            }
                        }
                    }
                }
            }
            catch (Exception err)
            {

                MessageBox.Show(err.Message);
            }
        }

        private void textBox_product_TextChanged(object sender, EventArgs e)
        {

        }

        private void customersCount_btn_Click(object sender, EventArgs e)
        {
            try
            {
                // Connection
                using (SqlConnection connection = new SqlConnection(ConnectionString))
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
                                MessageBox.Show(reader.GetInt32(0).ToString());
                            }
                        }
                    }
                }
            }
            catch (Exception err)
            {

                MessageBox.Show(err.Message);
            }
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void Refresh_btn_Click(object sender, EventArgs e)
        {
            try
            {
                tbl.Clear();
                // Connection
                using (SqlConnection connection = new SqlConnection(ConnectionString))
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
                                string lastName = reader.GetString(reader.GetOrdinal("FirstName"));
                                string firstName = reader.GetString(reader.GetOrdinal("LastName"));
                                tbl.Add(employeeID, (firstName + " " + lastName));
                            }
                        }
                    }
                }
            }
            catch (Exception err)
            {

                MessageBox.Show(err.Message);
            }
           
        }

        private void textBox_employeesId_TextChanged(object sender, EventArgs e)
        {

        }

        private void Show_Employees_data_by_id_btn(object sender, EventArgs e)
        {
            try
            {
                if (((string)tbl[Convert.ToInt32(textBox_employeesId.Text)]) == null)
                {
                    MessageBox.Show("OPSS:The number you entered does not exist in the table", "OPSS");
                }
                else
                {
                    MessageBox.Show((string)tbl[Convert.ToInt32(textBox_employeesId.Text)], "Name And LastName");
                }
            }
            catch (Exception err)
            {

                MessageBox.Show(err.Message);
            }
        }

        private void refresh_customers_btn_Click(object sender, EventArgs e)
        {
            try
            {
                tbl.Clear();
                // Connection
                using (SqlConnection connection = new SqlConnection(ConnectionString))
                {

                    string queryString = "select [ProductID],[ProductName],[UnitsInStock],[UnitPrice] from [dbo].[Products]";

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
                                int UnitsInStock = reader.GetInt16(reader.GetOrdinal("UnitsInStock"));
                                Product product1 = new Product(ProductID, ProductName, UnitPrice, UnitsInStock);
                                tbl.Add(product1.ProductId, product1);
                            }
                        }
                    }
                }
            }
            catch (Exception err)
            {

                MessageBox.Show(err.Message);
            }
        }
        private void Show_Product_data_by_id_btn_Click(object sender, EventArgs e)
        {

            try
            {
                if (((Product)tbl[Convert.ToInt32(textBox_productID.Text)]) == null)
                {
                    MessageBox.Show("OPSS:The number you entered does not exist in the table", "OPSS");
                }
                else
                {
                    Product pr = (Product)tbl[Convert.ToInt32(textBox_productID.Text)];
                    label_UnitPrice.Text = pr.UnitPrice.ToString();
                    label_UnitInStock.Text = pr.UnitInStock.ToString();
                }
            }
            catch (Exception err)
            {

                MessageBox.Show(err.Message);
            }
        }
        private void textBox_productID_TextChanged(object sender, EventArgs e)
        {

        }
        private void label_UnitPrice_Click(object sender, EventArgs e)
        {

        }
        private void label_UnitInStock_Click(object sender, EventArgs e)
        {

        }

        private void btn_for_check_how_meny_product_Click(object sender, EventArgs e)
        {
            try
            {
                // Connection
                using (SqlConnection connection = new SqlConnection(ConnectionString))
                {

                    string queryString = "select COUNT([ProductID]) from [dbo].[Products] where [UnitPrice]>" + textBox_for_check_price.Text;

                    // Adapter
                    using (SqlCommand command = new SqlCommand(queryString, connection))
                    {
                        connection.Open();

                        //Reader
                        using (SqlDataReader reader = command.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                MessageBox.Show("you have " + reader.GetInt32(0).ToString()+ " product above the the price you Enter", "count of product by price");
                                textBox_for_check_price.Text = reader.GetInt32(0).ToString();
                            }
                        }
                    }
                }
            }
            catch (Exception err)
            {

                MessageBox.Show(err.Message);
            }
        }

        private void textBox_for_check_price_TextChanged(object sender, EventArgs e)
        {

        }
    }
}



//while (reader.Read())
//{
//    int colIdx = reader.GetOrdinal("email");
//    string email = reader.GetString(colIdx);
//    string code = reader.GetString(reader.GetOrdinal("code"));
//    int num = reader.GetInt32(2);
//}