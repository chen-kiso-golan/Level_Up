namespace week_4_Winform_Interface
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

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //option1:
            string userInfo = textBox1.Text + "," + textBox2.Text + "," + textBox3.Text + ",\n";
            File.AppendAllText("MyNewFile.txt", userInfo);
            MessageBox.Show("YOUR FILE HAS BEEN UPLOADED!\n");

            //option2:
            //StreamWriter sw = File.AppendText("MyNewFile.txt");
            //sw.WriteLine(userInfo);
            //sw.Close();


        }

        public enum Days
        {
            Sunday,
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday
        }
        private void LoadBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string[] lines = File.ReadAllLines("MyNewFile.txt");
                string[] lineSplit;
                Days day;
                ShowTxtBtn.Text = "";

                for (int i = 0; i < lines.Length; i++)
                {
                    lineSplit = lines[i].Split(',');
                    day = (Days)Enum.Parse(typeof(Days), lineSplit[1]);
                    ShowTxtBtn.Text += lineSplit[0] + "," + day.ToString() + "," + lineSplit[2]+"\n";
                }
               
                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";

            } 
            catch(Exception ex) { MessageBox.Show("OOPS!\n"); }
            
        }

        private void ShowTxtBtn_Click(object sender, EventArgs e)
        {

        }

        private void DeletBtn_Click(object sender, EventArgs e)
        {
            File.WriteAllText("MyNewFile.txt", "");
            ShowTxtBtn.Text = "your text is...";
        }




        Item[] ItemArr = new Item[5];
        public static int Index = 0;
        private void ItemBtn_Click(object sender, EventArgs e)
        {
            Item Item1 = new Cola();
            Item1.GetPrice();
            ItemArr[Index] = Item1;
            Index++;

            if (Index == 5)
            {
                MessageBox.Show("no more room for more cola and kinly!");
            }
        }

        private void KinlyBtn_Click(object sender, EventArgs e)
        {
            Item Item2 = new Kinly();
            Item2.GetPrice();
            ItemArr[Index] = Item2;
            Index++;

            if(Index == 5) 
            {
                MessageBox.Show("no more room for more cola and kinly!");
            }
        }

        private void ShowArrayBtn_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < ItemArr.Length; i++)
            {
                MessageBox.Show("price "+ i +" " + ":" + " " + ItemArr[i].GetPrice().ToString());
            }
        }
    }
}