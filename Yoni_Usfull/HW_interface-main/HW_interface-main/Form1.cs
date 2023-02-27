using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace HW_WinFormsApp_interface
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        enum Shapes
        { 
            Rectangle,
            Triangle,
            Moon,
        }

        IShape[] ShapeArr = new IShape[100];

        int ShapeArrIndex = 0;

        int counter_Rectangle = 0;
        int counter_Triangle = 0;
        int counter_Moon = 0;
        int counter_Circle = 0;
        int counter_Ellipse = 0;


        private void shape1_textbox_TextChanged(object sender, EventArgs e)
        {

        }

        private void shape2_textbox_TextChanged(object sender, EventArgs e)
        {

        }


        private void calculate_Click(object sender, EventArgs e)
        {
            try
            {
                Moon moon1 = new Moon();
                Triangle Triangle1 = new Triangle();
                Rectangle Rectangle1 = new Rectangle();

                Shapes Shape1;
                Shapes Shape2;


                Shape1 = (Shapes)Enum.Parse(typeof(Shapes), shape1_textbox.Text);
                Shape2 = (Shapes)Enum.Parse(typeof(Shapes), shape2_textbox.Text);


                int userChoise1 = 0;

                if (Shape1 == Shapes.Moon)
                {
                    userChoise1 = moon1.NumberOfApex();
                }
                else if (Shape1 == Shapes.Triangle)
                {
                    userChoise1 = Triangle1.NumberOfApex();
                }
                else if (Shape1 == Shapes.Rectangle)
                {
                    userChoise1 = Rectangle1.NumberOfApex();
                }

                int userChoise2 = 0;

                if (Shape2 == Shapes.Moon)
                {
                    userChoise2 = moon1.NumberOfApex();
                }
                else if (Shape2 == Shapes.Triangle)
                {
                    userChoise2 = Triangle1.NumberOfApex();
                }
                else if (Shape2 == Shapes.Rectangle)
                {
                    userChoise2 = Rectangle1.NumberOfApex();
                }


                if (userChoise1 > userChoise2)
                {
                    MessageBox.Show(shape1_textbox.Text);
                }
                else
                {
                    MessageBox.Show(shape2_textbox.Text);
                }

            }
            catch (Exception err) { MessageBox.Show("OOPS!\n" + err.Message); }
        }

        private void add_shape_to_array_Click(object sender, EventArgs e)
        {
            try
            {
                if (checkBox_Circle.Checked)
                {
                    ShapeArr[ShapeArrIndex] = new Circle();
                    ShapeArrIndex++;
                    counter_Circle += 0;

                }
                if (checkBox_Ellipse.Checked)
                {
                    ShapeArr[ShapeArrIndex] = new Ellipse();
                    ShapeArrIndex++;
                    counter_Ellipse += 0;
                }
                if (checkBox_Moon.Checked)
                {
                    ShapeArr[ShapeArrIndex] = new Moon();
                    ShapeArrIndex++;
                    counter_Moon += 2;
                }
                if (checkBox_Rectangle.Checked)
                {
                    ShapeArr[ShapeArrIndex] = new Rectangle();
                    ShapeArrIndex++;
                    counter_Rectangle += 4;
                }
                if (checkBox_Triangle.Checked)
                {
                    ShapeArr[ShapeArrIndex] = new Triangle();
                    ShapeArrIndex++;
                    counter_Triangle += 3;
                }

                MessageBox.Show("you added the apex of every Shape to the specific countr","add to counter");
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
           
        }

        private void show_result_btn_Click(object sender, EventArgs e)
        {
            try
            {
              label_Result.Text = "Apex of Circle:" + counter_Circle.ToString() + "\n" + "Apex of Moon:" + counter_Moon.ToString() + "\n" + "Apex of Ellipse:" + counter_Ellipse.ToString() + "\n" + "Apex of Rectangle:" + counter_Rectangle.ToString() + "\n" + "Apex of Triangle:" + counter_Triangle.ToString();

            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        private void label_Result_Click(object sender, EventArgs e)
        {

        }

        private void DeleteBtn_Click(object sender, EventArgs e)
        {
            label_Result.Text = "---";
            ShapeArrIndex = 0;

            counter_Circle = 0;
            counter_Moon = 0;
            counter_Ellipse = 0;
            counter_Rectangle = 0;
            counter_Triangle = 0;

            checkBox_Circle.Checked = false;
            checkBox_Moon.Checked = false;
            checkBox_Ellipse.Checked = false;
            checkBox_Rectangle.Checked = false;
            checkBox_Triangle.Checked = false;
        }
    }
}