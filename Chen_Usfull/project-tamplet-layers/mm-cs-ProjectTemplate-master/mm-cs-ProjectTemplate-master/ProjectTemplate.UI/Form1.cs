using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ProjectTemplate.Entities;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;
using ProjectTemplate.Model;

namespace ProjectTemplate.UI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Entities.MainManager.Instance.Students.AddNewStudent(textBox1.Text, 20);
        }

        private void button2_Click(object sender, EventArgs e)
        {


            MainManager.Instance.Students.CalcMilga();




            Model.Item item1 = new Model.Item() { UserText = textBox1.Text };
            Model.Item item2 = new Model.Item() { UserText = "1341342134234" };


            System.Collections.Generic.Queue<Item> q = new Queue<Item>();
             
            q.Enqueue(item1);
            q.Enqueue(item2);
            Model.Item item3 =  q.Dequeue();
            int a = q.Count();
            q.Clear();

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Item item = new Item() { UserText = textBox1.Text };
            MainManager.Instance.MyQueue.Push(item);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Item item = null;
            item = MainManager.Instance.MyQueue.Pop();

            if(item!=null)
                textBox3.Text = item.UserText;
        }
    }
}
