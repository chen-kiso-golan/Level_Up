using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CW13_worker
{
    public partial class Frm_worker : Form
    {
        public Frm_worker()
        {
            InitializeComponent();
            ReasetAllControls(this);
        }
        //פונקציה הבודקת תקינות מספר זהות
        private bool CheckID(string ID)
        {
            long result =0;
            //בדיקה האם אפשר להמיר את הטקסט למספר, ואם אי אפשר נחזיר "לא נכון" או באנגלית פולס
            if(!long.TryParse(ID, out result)) return false;

            //ריצה על כל הטקסט
            int sum =0;
            for (int i = 0; i < ID.Length-1; i++)
            {
                // מחשב כל ספרה ומכפיל אותה או באחד או בשתיים
                int checksum = int.Parse(ID[i].ToString()) * ((i % 2) + 1);
                //הוספת התוצאה לסך הכללי כולל צמצום הסיפרה העשרונית
                sum += checksum % 10 + checksum / 10;
            }
            return (sum + int.Parse(ID[ID.Length-1].ToString()))%10==0;
        }

        //פונקציה המנקה את כל השדות
        private void ReasetAllControls(Control control)
        {
            if (control != null) return;

            foreach (Control ctr in control.Controls)
            {
                if (ctr is TextBox) ctr.Text = "";
                if (ctr is RadioButton) ((RadioButton)ctr).Checked = false;
                if (ctr is Panel) ReasetAllControls(ctr);
                if(ctr is DateTimePicker)((DateTimePicker)ctr).Value = DateTime.Now.AddYears(-18);
            }
        }

        public string Status
        {
            get
            {
                foreach (Control ctr in pStatus.Controls)
                {
                    if(ctr is RadioButton)
                    if (((RadioButton)ctr).Checked) return ctr.Text;
                }
                return "";
            }
            set
            {
                foreach (Control ctr in pStatus.Controls)
                {
                    if(ctr is RadioButton && ctr.Text==value)
                    {
                        ((RadioButton)ctr).Checked = true;
                    }
                }
            }
        }

        private void TBox_Id_TextChanged(object sender, EventArgs e)
        {

        }

        private void TBox_Id_Leave(object sender, EventArgs e)
        {
            if (!CheckID(TBox_Id.Text))
            {
                MessageBox.Show("Invalid");
                TBox_Id.Focus(); 
            }
        }

        private void btn_New_Click(object sender, EventArgs e)
        {
            ReasetAllControls(this);
        }

        private void RBtn_Mail_CheckedChanged(object sender, EventArgs e)
        {
            if (RBtn_Mail.Checked)
            {
                rdbSingle.Text = "רווק";
                rdbMarride.Text = "נשוי";
                rdbDivorce.Text = "גרוש";
                rdbWidow.Text = "אלמן";
            }
        }

        private void RButton_Fmale_CheckedChanged(object sender, EventArgs e)
        {
            if (RButton_Fmale.Checked)
            {
                rdbSingle.Text = "רווקה";
                rdbMarride.Text = "נשואה";
                rdbDivorce.Text = "גרושה";
                rdbWidow.Text = "אלמנה";
            }
        }
    }
}
