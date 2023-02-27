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
    public partial class frmCategory : Form
    {
        static List<frmCategory> brothers;
        frm_guests parent;
        int Index;
        public frmCategory(frm_guests parent, string GustName, string CategoryName, int Index)
        {
            InitializeComponent();
            this.parent = parent;
            this.Index= Index;
            lalGuestsName.Text = GustName;
            lalCategory.Text = CategoryName;
            ShowCurrentGuestsSelections();
            ShowAllGuestsSelections();
        }
        //פונקציה המוסיפה מאכל לפי האורח ולפי הקטגוריה
        private void AddFood(string food)
        {
            string insert = "declare @guest_code int, @category_code int\r\n\r\nif exists(select code from guests where name1= @guest_name)\r\nbegin\r\nselect @guest_code=(select code from guests where name1= @guest_name)\r\nend\r\nelse\r\nbegin\r\ninsert into guests values(@guest_name)\r\nselect @guest_code=@@IDENTITY\r\nend\r\nif exists(select code from categories where name1= @category_name)\r\nbegin\r\nselect @category_code=(select code from categories where name1= @category_name)\r\ninsert into foods values (@food_name,@guest_code,@category_code)\r\nend";
            if (!parent.Connect_check()) return;
            SqlCommand command = new SqlCommand(insert, parent.connection);
            command.Parameters.AddWithValue("@guest_name", lalGuestsName.Text);
            command.Parameters.AddWithValue("@category_name", lalCategory.Text);
            command.Parameters.AddWithValue("@food_name", food);
            command.ExecuteNonQuery();
            parent.connection.Close();
        }
        public List<frmCategory> Brothers { set { brothers = value; } }
        private void lalGuestsName_Click(object sender, EventArgs e)
        {

        }

        private void lalCategory_Click(object sender, EventArgs e)
        {

        }

        private void btn_Beck_category_Click(object sender, EventArgs e)
        {
            this.Visible = false;
            if (Index > 0)
            {
                brothers[Index-1].Visible = true;
            }
        }

        private void btn_next_category_Click(object sender, EventArgs e)
        {
            this.Visible= false;
            if(Index< brothers.Count - 1)
            {
                 brothers[Index+1].Visible = true;
            }          
        }

        private void btn_AddFood_Click(object sender, EventArgs e)
        {
            textBox1.Visible= true;
            btn_confirm.Visible= true;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void btn_confirm_Click(object sender, EventArgs e)
        {
            AddFood(textBox1.Text);
            textBox1.Visible = false;
            btn_confirm.Visible = false;
            ShowCurrentGuestsSelections();
            ShowAllGuestsSelections();
        }



        //פונקציה המציגה את הבחירה של כל האורחים בקטגוריה הנוכחית
        private void ShowAllGuestsSelections()
        {
            string select = "select guests.name1 as 'guest name',categories.name1 as 'categories name', foods.name1 as 'food name'\r\nfrom guests inner join foods on guests.code = foods.guest_code\r\ninner join categories on categories.code = foods.categories_code\r\nwhere categories.name1 = '" + lalCategory.Text + "'";
            SqlDataAdapter adapter = new SqlDataAdapter(select, parent.ConnectionString);
            //יצירת טבלה בזיכרון
            DataTable table = new DataTable();
            //מילוי הנתונים בתוך הטבלה הזמנית בזיכרון
            adapter.Fill(table);
            dataGridView_AllGuestChoies.DataSource = table;
        }

        //פונקציה המציגה את הבחירה של האורח הנוחכי בקטגוריה הנוכחית
        private void ShowCurrentGuestsSelections()
        {
            string select = "\r\nselect guests.name1 as 'guest name',categories.name1 as 'categories name', foods.name1 as 'food name'\r\nfrom guests inner join foods on guests.code =foods.guest_code\r\ninner join categories on categories.code = foods.categories_code\r\nwhere categories.name1 = '"+ lalCategory.Text+"'\r\nand guests.name1 ='"+ lalGuestsName.Text+"'";
            SqlDataAdapter adapter = new SqlDataAdapter(select,parent.ConnectionString);
            //יצירת טבלה בזיכרון
            DataTable table = new DataTable();
            //מילוי הנתונים בתוך הטבלה הזמנית בזיכרון
            adapter.Fill(table);
           
            dataGridView_CurrentGuestChoies.DataSource = table;

        }

        private void dataGridView_CurrentGuestChoies_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView_AllGuestChoies_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            AddFood(dataGridView_AllGuestChoies[2, e.RowIndex].Value.ToString());
            ShowCurrentGuestsSelections();
        }
    }
}
