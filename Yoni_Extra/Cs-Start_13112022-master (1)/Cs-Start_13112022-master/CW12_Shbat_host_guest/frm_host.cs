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

namespace CW12_Shbat_host_guest
{
    public partial class frm_host : Form
    {
        public string ConnectionString = @"Integrated Security=SSPI; Persist Security Info=False;    Initial Catalog=Shabat; Data Source=localhost\sqlexpress";
        //אובייקט המכיל צינור התחברות למסד הנתונים
        public SqlConnection connection;

        public frm_host()
        {
            InitializeComponent();
            connection = new SqlConnection(ConnectionString);
        }

        public bool Connect_check()
        {
            try
            {
                connection.Open();
                //MessageBox.Show("the connection is good", "check ConnectionString", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return true;
            }
            catch (SqlException)
            {
                //MessageBox.Show(err.Message);
                return false;
            }
        }

        private void EnterCategory(string category_name)
        {

            if (!Connect_check()) return;
            string insert = "insert into categories values(@category_name2)";
            //יצירת דף פקודה בכולל את משפט ההכנסה ומשתמש באובייקט האחראי על החיבור למסד הנתונים
            SqlCommand command = new SqlCommand(insert, connection);
            //הוספת משתנה הכוללת את שם האורח
            
            command.Parameters.AddWithValue("@category_name2", category_name);
            try
            {
                //ביצוע הפקודה
                int number = command.ExecuteNonQuery();
            }
            catch (SqlException err)
            {
                MessageBox.Show(err.Message);

            }
            //סגירת החיבור
            connection.Close();
        }

        //פונקציה המציגה את כל הקטגוריות בתיבת רשימה
        private void showAllCategories()
        {
            //ניקוי הרשימה משמות קודמים
            listBox_host.Items.Clear();

            if (!Connect_check()) return;
            string select = "select name1 from categories";
            SqlCommand command = new SqlCommand(select, connection);
            //ביצוע הפקודה לתוך טבלה מוכנה
            SqlDataReader reader = command.ExecuteReader();
            //בדיקה האם יש שורות בטבלה
            if (reader.HasRows)
            {
                //ריצה על כל השורות
                while (reader.Read())
                {
                    //קריאה מכל שורה את העמודה הראשונה שהיא אצלינו גם העמודה היחידה
                    listBox_host.Items.Add(reader[0].ToString());

                }
            }
            //סגירת החיבור
            connection.Close();
        }

        //פונקציה שמוחקת שורה מהקטגוריות
        private void DeleteCategory(string category_name)
        {

            if (!Connect_check()) return;
            string insert = "delete from [categories] where name1=@category_name2";
            //יצירת דף פקודה בכולל את משפט ההכנסה ומשתמש באובייקט האחראי על החיבור למסד הנתונים
            SqlCommand command = new SqlCommand(insert, connection);
            //הוספת משתנה הכוללת את שם האורח

            command.Parameters.AddWithValue("@category_name2", category_name);
            try
            {
                //ביצוע הפקודה
                int number = command.ExecuteNonQuery();
            }
            catch (SqlException err)
            {
                MessageBox.Show(err.Message);

            }
            //סגירת החיבור
            connection.Close();
        }

        private void btn_host_Click(object sender, EventArgs e)
        {
            if (textBox_host.Text == "")
            {
                 showAllCategories();
                return;
            }
            EnterCategory(textBox_host.Text);
            showAllCategories();
        }

        private void textBox_host_TextChanged(object sender, EventArgs e)
        {

        }

        private void listBox_host_SelectedIndexChanged(object sender, EventArgs e)
        {
            DeleteCategory(listBox_host.Text);
            showAllCategories();
        }


      
        private void btn_SumOfOrder_Click(object sender, EventArgs e)
        {
            ShowAllGuestsOrders();
        }

        private void ShowAllGuestsOrders()
        {
            string select = "select name1, count(*) as 'sum' from foods group by name1";
            SqlDataAdapter adapter = new SqlDataAdapter(select, ConnectionString);
            //יצירת טבלה בזיכרון
            DataTable table = new DataTable();
            //מילוי הנתונים בתוך הטבלה הזמנית בזיכרון
            adapter.Fill(table);
            DGV_SumOfOrder.DataSource = table;
        }


        private void DGV_SumOfOrder_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            //ShowAllGuestsOrders();
        }
    }
}
