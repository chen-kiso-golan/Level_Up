namespace CW9_TheInterfaceApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        enum WorkDays
        {
            sunday,
            monday,
            tuesday,
            Wednesday,
            Thursday,
            Friday
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                 //option 1
                string userInfo = textBox_Name.Text + " " + textBox_Day.Text + " " + textBox_Age.Text + " \n";
                File.AppendAllText("MyNewFile.txt", userInfo);

                //option 2
                //StreamWriter sw = File.AppendText("MyNewFile.txt");
                //sw.WriteLine(userInfo);
                //sw.Close();
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string[] lines = File.ReadAllLines("MyNewFile.txt");
                string[] lineSplit = lines[0].Split(' ');
                WorkDays day;
                day = (WorkDays)Enum.Parse(typeof(WorkDays), lineSplit[1]);
                textBox_Name.Text = lineSplit[0];
                textBox_Day.Text = day.ToString();
                textBox_Age.Text = lineSplit[2];
            }
            catch (Exception err)
            {

                MessageBox.Show(err.Message);
            }
        }

        private void textBox_Name_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_Day_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_Age_TextChanged(object sender, EventArgs e)
        {

        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Create_Item_Btn_Click(object sender, EventArgs e)
        {
            try
            {
                Item item = new Cola();

                int r = item.GetPrice();
                MessageBox.Show("the cola price is:"+r.ToString(),"price");
            }
            catch (Exception err)
            {
                Console.WriteLine(err.Message);
            } 
        }

        Item[] ItemaArr = new Item[5];
        public static int Index = 0;
        private void Cola_for_arr_Click(object sender, EventArgs e)
        {
            try
            {
                Item item1 = new Cola();
                ItemaArr[Index] = item1;
                Index++;
            }
            catch (Exception err)
            {

                Console.WriteLine(err.Message);
            }
        }

        private void Kinly_for_arr_Click(object sender, EventArgs e)
        {
            try
            {
                Item item2 = new Kinly();
                ItemaArr[Index] = item2;
                Index++;
            }
            catch (Exception err)
            {

                Console.WriteLine(err.Message);
            }
       
        }

        private void Print_Arr_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = 0; i < ItemaArr.Length; i++)
                {
                    MessageBox.Show("price: " + ItemaArr[i].GetPrice().ToString());
                }
            }
            catch (Exception err)
            {

                Console.WriteLine("you ara not enter product\n");
                Console.WriteLine(err.Message);
            }
        }
    }
}