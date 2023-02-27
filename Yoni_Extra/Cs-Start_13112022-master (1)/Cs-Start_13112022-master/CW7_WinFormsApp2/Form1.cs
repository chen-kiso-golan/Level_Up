namespace CW7_WinFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                label3.Text = (int.Parse(textBox1.Text) + int.Parse(textBox2.Text)).ToString();
            }
            catch (FormatException err)
            {
                MessageBox.Show("THIS IS NOT A NUMBER!\n" + err.Message);
            }
           
        }
    }
}