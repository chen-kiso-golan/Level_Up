using ProjectStudent.Entities;
using ProjectStudent.Model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace ProjectStudent.UI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        private void Add_Student_btn_Click(object sender, EventArgs e)
        {
            Entities.MainManager.Instance.students.AddNewStudent(textBox_Name.Text, Convert.ToInt16(textBox_Age.Text), textBox_Adress.Text,Convert.ToInt32(textBox_ID.Text));
            Entities.MainManager.Instance.students.CalcMilga(textBox_Name.Text, Convert.ToInt16(textBox_Age.Text), textBox_Adress.Text, Convert.ToInt32(textBox_ID.Text));
        }

        private void textBox_Name_TextChanged(object sender, EventArgs e)
        {

        }
        private void textBox_Age_TextChanged(object sender, EventArgs e)
        {

        }
        private void textBox_Adress_TextChanged(object sender, EventArgs e)
        {

        }
        private void textBox_ID_TextChanged(object sender, EventArgs e)
        {

        }

        private void Show_all_data_by_id_Click(object sender, EventArgs e)
        {
            try
            {
                MStudent mStudent1 = (MStudent)Entities.MainManager.Instance.hashtableStudent[Convert.ToInt32(textBox_ID.Text)];
                textBox_Name.Text = mStudent1.Name;
                textBox_Age.Text = mStudent1.Age.ToString();
                textBox_Adress.Text = mStudent1.Address;
                textBox_ID.Text = mStudent1.Id.ToString();
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
          
        }

        private void Reset_btn_Click(object sender, EventArgs e)
        {
            Entities.MainManager.Instance.hashtableStudent.Clear();

            Entities.MainManager.Instance.students.InsertDB_ToHash();
        }
    }
}
