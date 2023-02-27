using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.TextBox;

namespace MiniProject.UI
{
    public partial class Form1 : Form
    {
        string ConnectionString = @"Integrated Security=SSPI;   Persist Security Info=False;    Initial Catalog=Northwind;  Data Source=localhost\sqlexpress";

        public Form1()
        {
            InitializeComponent();

        }

        private void ShowCurrentGuestsSelections()
        {
            string select = "select * from products";
            SqlDataAdapter adapter = new SqlDataAdapter(select, ConnectionString);
            //יצירת טבלה בזיכרון
            DataTable table = new DataTable();
            //מילוי הנתונים בתוך הטבלה הזמנית בזיכרון
            adapter.Fill(table);

            dataGridView1.DataSource = table;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ShowCurrentGuestsSelections();
          
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            ShowCurrentGuestsSelections();  
        }

    }
}
