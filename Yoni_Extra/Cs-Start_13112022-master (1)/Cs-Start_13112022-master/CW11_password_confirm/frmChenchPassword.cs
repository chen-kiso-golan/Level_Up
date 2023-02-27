using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace CW11_password_confirm
{
    public partial class frmChenchPassword : Form
    {
        frmTimeClock parent;
        public frmChenchPassword(frmTimeClock Parent, string ID)
        {
            InitializeComponent();
            this.parent = Parent;
            label_ID.Text = ID;

        }

        private string sendDetails(string ID,string old_password, string new_password)
        {
            if (!parent.Connect_check()) return "the connection is not sucssed";
            string insert = "declare @emloyee_Uniqkey int, @answer nvarchar(100)\r\nselect @emloyee_Uniqkey = (select [UniqKey] from[dbo].[Employees] where ID = @ID)\r\nif @emloyee_Uniqkey is null\r\nbegin\r\nselect @answer = 'user name or password is not correct. rutren to school A'\r\nend\r\nelse\r\nbegin\r\nif not exists(select * from passwords where employee_UniqKey=@emloyee_Uniqkey and password=@old_password and is_active = 'true')\r\nbegin\r\nselect @answer = 'user name or password is not correct. rutren to school B'\r\nend\r\nelse\r\nbegin\r\nif exists (select * from Passwords where employee_UniqKey=@emloyee_Uniqkey and password=@new_password)\r\nbegin\r\nselect @answer ='you use this password in the past, plesa enter new password'\r\nend\r\nelse\r\nbegin\r\nupdate Passwords set is_active=0 where employee_UniqKey=@emloyee_Uniqkey\r\ninsert into Passwords values (@emloyee_Uniqkey,@new_password, getdate() +180,'true')\r\nselect @answer='the password is change secssfuuly, and the password is invile for 180 day'\r\nend\r\nend\r\nend\t\r\nselect @answer\r\n";
            SqlCommand command = new SqlCommand(insert, parent.connection);

            command.Parameters.AddWithValue("@ID ", ID);
            command.Parameters.AddWithValue("@new_password ", new_password);
            command.Parameters.AddWithValue("@old_password", old_password);

            string answer = command.ExecuteScalar().ToString();
            parent.connection.Close();

            return answer;
        }

        private void button_confirm_Click(object sender, EventArgs e)
        {
            if (textBox_NewPassword.Text != textBox_confirm_NewPassword.Text) return;
            MessageBox.Show(sendDetails(label_ID.Text, textBox_OldPassword.Text, textBox_NewPassword.Text));
        }


        private void label_ID_Click(object sender, EventArgs e)
        {

        }

        private void textBox_NewPassword_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_confirm_NewPassword_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_OldPassword_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
