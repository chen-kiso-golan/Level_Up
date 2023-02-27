namespace CW8_WinFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Random random = new Random(DateTime.Now.Millisecond);
            System.Threading.Thread.Sleep(50);

            int a = 0;
            do
            {
                try
                {
                    int rand = random.Next(5809, 7500);
                    pictureBox1.Image = Image.FromFile(@"C:\Users\yoni golan\Desktop\GAMING\Wedding pictur\filed_pictur\Filter image in JPG\DSC_" + rand +".jpg");
                    pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
                    a = 1;
                }
                catch (Exception)
                {
                    a = 0;
                    //MessageBox.Show("no pictur was found!\n" + err.Message);

                }

            } while (a == 0);
        }
    }
}