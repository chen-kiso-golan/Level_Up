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

namespace CW12_Shbat_host_guest
{
    public partial class frm_guests : Form
    {
        public string ConnectionString = @"Integrated Security=SSPI; Persist Security Info=False;    Initial Catalog=Shabat; Data Source=localhost\sqlexpress";

        //אובייקט המכיל צינור התחברות למסד הנתונים
        public SqlConnection connection;
        public frm_guests()
        {
            InitializeComponent();
            //הפעלת הצינור לפי ההגדרות שמופיעות בקונקטשן סטרינג
            connection = new SqlConnection(ConnectionString);
            showAllGuests("");
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

     
        //הכנסת אורח לטבלה במסד הנתונים
        private void EnterGuests (string name)
        {

            if (!Connect_check()) return;
            string insert = "if not exists (select * from guests where name1 = @guest_name)\r\nbegin\r\n\tinsert into guests values(@guest_name)\r\nend\r\n";
            //יצירת דף פקודה בכולל את משפט ההכנסה ומשתמש באובייקט האחראי על החיבור למסד הנתונים
            SqlCommand command = new SqlCommand(insert ,connection);
            //הוספת משתנה הכוללת את שם האורח
            command.Parameters.AddWithValue("@guest_name", name);
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


        //פונקציה המציגה את כל האורחים בתיבת רשימה
        private void showAllGuests (string name)
        {
            //ניקוי הרשימה משמות קודמים
            listBox_gusts_main.Items.Clear();

            if (!Connect_check()) return;
            string select = "select name1 from guests where name1 like'%" + name + "%'";
            SqlCommand command = new SqlCommand(select, connection);
            //ביצוע הפקודה לתוך טבלה מוכנה
            SqlDataReader reader = command.ExecuteReader();
            //בדיקה האם יש שורות בטבלה
            if(reader.HasRows)
            {
                //ריצה על כל השורות
                while (reader.Read())
                {
                    //קריאה מכל שורה את העמודה הראשונה שהיא אצלינו גם העמודה היחידה
                    listBox_gusts_main.Items.Add( reader[0].ToString());

                }
            }
            //סגירת החיבור
            connection.Close();
        }

        //אירוע של בחירת שורה ברשימה
        private void listBox_gusts_main_SelectedIndexChanged(object sender, EventArgs e)
        {
            //העתקת השורה שנבחרה בתיבת הרשימה לתוך תיבת הטקסט
            TBox_gusts_main.Text = listBox_gusts_main.Text;
        }

        //אירוע המופעל בזמן שינוי הטקסט בתיבת הטקסט
        private void TBox_gusts_main_TextChanged(object sender, EventArgs e)
        {
            showAllGuests(TBox_gusts_main.Text);
        }



        //פונקציה הפותחת טפסים לפי הקטגוריות בטבלה במסד הנתונים 
        private void CreateFormByCategories(string guestName)
        {
            string select = "select name1 from categories";
            if (!Connect_check()) return;
            SqlCommand command = new SqlCommand(select, connection);
            SqlDataReader reader = command.ExecuteReader();
            //רשימת טפסים       //frmCategory[] categories = new frmCategory[0];
            List<frmCategory> categories = new List<frmCategory>();
            int index = 0;

            if(reader.HasRows)
            {
                while (reader.Read())
                {
                    //בניית טופס חדש לכל קטגוריה במערך ולהכניסו לרשימהשל הטפסים
                    categories.Add(new frmCategory(this, guestName, reader[0].ToString(), index++));
                }
                categories.First().Brothers = categories;
                categories.First().Show();
            }
            connection.Close();
        }



        //מפעיל את הפונקציה המכיסנה את האורח החדש לטבלת מסד הנתונים
        private void Enter_guests_btn_Click(object sender, EventArgs e)
        {
            if (TBox_gusts_main.Text == "") return;

            //מפעיל את הפונקציה המכניסה את האורח החדש לטבלה במסד הנתונים
            EnterGuests(TBox_gusts_main.Text);
           
            //מפעיל את הפונקציה הבונה טפסים
            CreateFormByCategories(TBox_gusts_main.Text);

            //הפעלת האירוע של שינוי הטקסט בתיבת הטקסט
            TBox_gusts_main.Text = "";
        }
    }
}
