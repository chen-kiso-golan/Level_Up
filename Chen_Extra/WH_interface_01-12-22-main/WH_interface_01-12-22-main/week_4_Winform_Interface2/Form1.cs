using System.Security.Cryptography.X509Certificates;
using System.Windows.Forms;

namespace week_4_Winform_Interface2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        enum Shapes
        {
            Moon, 
            Triangle, 
            Rectangle,
        }

        IShape[] ShapesArr = new IShape[100];
        int ArrIndex = 0;
        int Counter = 0;
        

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void addBtn_Click(object sender, EventArgs e)
        {
            if (circleBtn.Checked) 
            {
                ShapesArr[ArrIndex] = new Circle();
                ArrIndex++;
                //Counter = Counter + 0;
            }
            if (rectangleBtn.Checked)
            {
                ShapesArr[ArrIndex] = new Rectangle();
                ArrIndex++;
                Counter = Counter + 4;
            }
            if (triangleBtn.Checked)
            {
                ShapesArr[ArrIndex] = new Triangle();
                ArrIndex++;
                Counter = Counter + 3;
            }
            if (moonBtn.Checked)
            {
                ShapesArr[ArrIndex] = new Moon();
                ArrIndex++;
                Counter = Counter + 2;
            }
            if (ellipseBtn.Checked)
            {
                ShapesArr[ArrIndex] = new Ellipse();
                ArrIndex++;
                //Counter = Counter + 0;
            }

            MessageBox.Show("added your shapes to the count!");

        }

        private void ShowResultBtn_Click(object sender, EventArgs e)
        {
            arrayLabel.Text = Counter.ToString();   
        }

        private void arrayLabel_Click(object sender, EventArgs e)
        {

        }

        private void DeletAllBtn_Click(object sender, EventArgs e)
        {
            arrayLabel.Text = "---";
            Counter = 0;
            ArrIndex = 0;
            ellipseBtn.Checked= false;
            moonBtn.Checked= false;
            triangleBtn.Checked= false; 
            rectangleBtn.Checked= false;    
            circleBtn.Checked= false;
                
        }

        private void CheckBtn_Click(object sender, EventArgs e)
        {
            try
            {
                Shapes UserShape1;
                Shapes UserShape2;

                Moon moon1 = new Moon();
                Triangle Triangle1 = new Triangle();
                Rectangle Rectangle1 = new Rectangle();

                UserShape1 = (Shapes)Enum.Parse(typeof(Shapes), textBox1.Text);
                UserShape2 = (Shapes)Enum.Parse(typeof(Shapes), textBox2.Text);

                int userChoise1 = 0;

                if (UserShape1 == Shapes.Moon)
                {
                    userChoise1 = moon1.ApexNumber();
                }
                else if (UserShape1 == Shapes.Triangle)
                {
                    userChoise1 = Triangle1.ApexNumber();
                }
                else if (UserShape1 == Shapes.Rectangle)
                {
                    userChoise1 = Rectangle1.ApexNumber();
                }

                int userChoise2 = 0;

                if (UserShape2 == Shapes.Moon)
                {
                    userChoise2 = moon1.ApexNumber();
                }
                else if (UserShape2 == Shapes.Triangle)
                {
                    userChoise2 = Triangle1.ApexNumber();
                }
                else if (UserShape2 == Shapes.Rectangle)
                {
                    userChoise2 = Rectangle1.ApexNumber();
                }


                if (userChoise1 > userChoise2)
                {
                    MessageBox.Show(textBox1.Text);
                }
                else
                {
                    MessageBox.Show(textBox2.Text);
                }
            }
            catch { MessageBox.Show("the shape you entered dose not have apex!"); }

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}