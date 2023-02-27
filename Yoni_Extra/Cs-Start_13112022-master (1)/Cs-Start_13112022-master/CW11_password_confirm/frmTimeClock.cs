using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Data.SqlClient;

namespace CW11_password_confirm
{
    public partial class frmTimeClock : Form
    {
        //string ConnectionString2 = @"Data Source = localhost\\SQLEXPRESS; initial catalog =company;user id =sa; password=1234"; דוגמא של אוריאל
        const string ConnectionString = @"Integrated Security=SSPI;   Persist Security Info=False;   Initial Catalog=company;   Data Source=localhost\sqlexpress";

        //אובייקט המכיל צינור התחברות למסד הנתונים
        public SqlConnection connection;
        public frmTimeClock()
        {
            InitializeComponent();
            //הפעלת הצינור לפי ההגדרות שמופיעות בקונקטשן סטרינג
            connection = new SqlConnection(ConnectionString);
        }
        //פונקציה המתחברת למסד נתונים ומחזירה תשובה אם הצליחה
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

        //פונקציה השולחת פרטי משתמש למס הנתונים ומקבלת תשובה חזרה
        private string SendDetail(string ID, string password)
        {
            //מנסה להתחבר למסד הנתונים. ושולח הודעה אם לא הצליח
            if (!Connect_check()) return "the connection is not sucssed";
            //כל השאילתא של שפת המסד נתוניםSQL
            string insert = "declare @answer nvarchar(100), @emloyee_Uniqkey int\r\n\r\n select @emloyee_Uniqkey = (select [UniqKey] from [dbo].[Employees] where ID=@ID)\r\nif exists(select * from [Employees] where ID =@ID)\r\nbegin\r\nif exists(select * from [Passwords] where password=@password and is_active='true' and employee_UniqKey = @emloyee_Uniqkey)\r\nbegin\r\nif exists(select * from [Passwords] where expiry >= getdate() and is_active='true' and password=@password and employee_UniqKey = @emloyee_Uniqkey)\r\nbegin\r\nif exists (select * from [times] where exit_time is NULL and employee_UniqKey = @emloyee_Uniqkey)\r\nbegin\r\nselect @answer = 'goodbye!' + CONVERT(nvarchar(20),GETDATE(),103)+ '-' +CONVERT(nvarchar(20),GETDATE(),108) \r\nupdate [times] set exit_time = getdate() where employee_UniqKey = @emloyee_Uniqkey\r\nend\r\nelse\r\nbegin\r\nselect @answer = 'have a good day at work!'+ CONVERT(nvarchar(20),GETDATE(),103)+ '-' +CONVERT(nvarchar(20),GETDATE(),108)\r\ninsert into times values (@emloyee_Uniqkey,getdate(),null)\r\nend\r\nend\r\n else\r\nbegin\r\nselect @answer = 'your password has expiered, please change your password'\r\nend\r\nend\r\nelse \r\nbegin\r\nselect @answer = 'the password is not valid'\r\nend\r\nend\r\nelse \r\nbegin\r\nselect @answer = 'the id does not exists in the system'\r\nend\r\nselect @answer";
            //יצירת אוביקט הביצוע והוספת השאילתא והחיבור לאובייקט
            SqlCommand command = new SqlCommand(insert, connection);
            //הוספת הפרמטרים
            command.Parameters.AddWithValue("@ID", ID);
            command.Parameters.AddWithValue("@password", password);
            //האובייקט חוזר לסקלאר והופכים אותו לסרינג
            string answer = command.ExecuteScalar().ToString();
            //סגירת הברז
            connection.Close();

            return answer;

        }

        private bool checkID(string ID)
        {
            return true;
        }
       
       

        private void textBox_password_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == (char)13)
            {
                //בדיקה האם המשתמש כתב גם מספר זהות וגם סיסמא
                if(textBox_UserID.Text == ""|| textBox_password.Text == string.Empty)
                {

                    MessageBox.Show("נא להכניס מספר זהות וסיסמא","מספר זהות וסיסמא",MessageBoxButtons.OK,MessageBoxIcon.Exclamation);
                    return;
                }
                MessageBox.Show(SendDetail(textBox_UserID.Text, textBox_password.Text));
            }

        
        }

        private void textBox_UserID_TextChanged(object sender, EventArgs e)
        {

        }

        private void btn_chench_password_Click(object sender, EventArgs e)
        {
            string ID = textBox_UserID.Text;
            if(ID == string.Empty)
            {
                ID = Microsoft.VisualBasic.Interaction.InputBox("please enten ID", "swich password");
            }
            frmChenchPassword password = new frmChenchPassword(this, ID);
            password.Show();
        }
    }
}
