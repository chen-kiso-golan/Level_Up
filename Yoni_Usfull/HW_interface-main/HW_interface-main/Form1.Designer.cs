namespace HW_WinFormsApp_interface
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.calculate = new System.Windows.Forms.Button();
            this.shape1_textbox = new System.Windows.Forms.TextBox();
            this.shape2_textbox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.checkBox_Rectangle = new System.Windows.Forms.CheckBox();
            this.checkBox_Circle = new System.Windows.Forms.CheckBox();
            this.checkBox_Ellipse = new System.Windows.Forms.CheckBox();
            this.checkBox_Triangle = new System.Windows.Forms.CheckBox();
            this.checkBox_Moon = new System.Windows.Forms.CheckBox();
            this.add_shape_to_array = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.show_result_btn = new System.Windows.Forms.Button();
            this.label_Result = new System.Windows.Forms.Label();
            this.DeleteBtn = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // calculate
            // 
            this.calculate.BackColor = System.Drawing.SystemColors.Info;
            this.calculate.Location = new System.Drawing.Point(144, 263);
            this.calculate.Name = "calculate";
            this.calculate.Size = new System.Drawing.Size(94, 29);
            this.calculate.TabIndex = 0;
            this.calculate.Text = "calculate";
            this.calculate.UseVisualStyleBackColor = false;
            this.calculate.Click += new System.EventHandler(this.calculate_Click);
            // 
            // shape1_textbox
            // 
            this.shape1_textbox.Location = new System.Drawing.Point(51, 219);
            this.shape1_textbox.Name = "shape1_textbox";
            this.shape1_textbox.Size = new System.Drawing.Size(125, 27);
            this.shape1_textbox.TabIndex = 1;
            this.shape1_textbox.TextChanged += new System.EventHandler(this.shape1_textbox_TextChanged);
            // 
            // shape2_textbox
            // 
            this.shape2_textbox.Location = new System.Drawing.Point(205, 219);
            this.shape2_textbox.Name = "shape2_textbox";
            this.shape2_textbox.Size = new System.Drawing.Size(125, 27);
            this.shape2_textbox.TabIndex = 1;
            this.shape2_textbox.TextChanged += new System.EventHandler(this.shape2_textbox_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(87, 186);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(62, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Shape 1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(241, 186);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(62, 20);
            this.label2.TabIndex = 2;
            this.label2.Text = "Shape 2";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(71, 146);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(232, 20);
            this.label3.TabIndex = 3;
            this.label3.Text = "Number Apex of the Bigest shape";
            // 
            // checkBox_Rectangle
            // 
            this.checkBox_Rectangle.AutoSize = true;
            this.checkBox_Rectangle.Location = new System.Drawing.Point(6, 37);
            this.checkBox_Rectangle.Name = "checkBox_Rectangle";
            this.checkBox_Rectangle.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.checkBox_Rectangle.Size = new System.Drawing.Size(97, 24);
            this.checkBox_Rectangle.TabIndex = 4;
            this.checkBox_Rectangle.Text = "Rectangle";
            this.checkBox_Rectangle.UseVisualStyleBackColor = true;
            // 
            // checkBox_Circle
            // 
            this.checkBox_Circle.AutoSize = true;
            this.checkBox_Circle.Location = new System.Drawing.Point(6, 67);
            this.checkBox_Circle.Name = "checkBox_Circle";
            this.checkBox_Circle.Size = new System.Drawing.Size(68, 24);
            this.checkBox_Circle.TabIndex = 4;
            this.checkBox_Circle.Text = "Circle";
            this.checkBox_Circle.UseVisualStyleBackColor = true;
            // 
            // checkBox_Ellipse
            // 
            this.checkBox_Ellipse.AutoSize = true;
            this.checkBox_Ellipse.Location = new System.Drawing.Point(6, 97);
            this.checkBox_Ellipse.Name = "checkBox_Ellipse";
            this.checkBox_Ellipse.Size = new System.Drawing.Size(74, 24);
            this.checkBox_Ellipse.TabIndex = 4;
            this.checkBox_Ellipse.Text = "Ellipse";
            this.checkBox_Ellipse.UseVisualStyleBackColor = true;
            // 
            // checkBox_Triangle
            // 
            this.checkBox_Triangle.AutoSize = true;
            this.checkBox_Triangle.Location = new System.Drawing.Point(6, 127);
            this.checkBox_Triangle.Name = "checkBox_Triangle";
            this.checkBox_Triangle.Size = new System.Drawing.Size(84, 24);
            this.checkBox_Triangle.TabIndex = 4;
            this.checkBox_Triangle.Text = "Triangle";
            this.checkBox_Triangle.UseVisualStyleBackColor = true;
            // 
            // checkBox_Moon
            // 
            this.checkBox_Moon.AutoSize = true;
            this.checkBox_Moon.Location = new System.Drawing.Point(6, 157);
            this.checkBox_Moon.Name = "checkBox_Moon";
            this.checkBox_Moon.Size = new System.Drawing.Size(70, 24);
            this.checkBox_Moon.TabIndex = 4;
            this.checkBox_Moon.Text = "Moon";
            this.checkBox_Moon.UseVisualStyleBackColor = true;
            // 
            // add_shape_to_array
            // 
            this.add_shape_to_array.BackColor = System.Drawing.SystemColors.Info;
            this.add_shape_to_array.Location = new System.Drawing.Point(443, 138);
            this.add_shape_to_array.Name = "add_shape_to_array";
            this.add_shape_to_array.Size = new System.Drawing.Size(106, 58);
            this.add_shape_to_array.TabIndex = 5;
            this.add_shape_to_array.Text = "Add Shape";
            this.add_shape_to_array.UseVisualStyleBackColor = false;
            this.add_shape_to_array.Click += new System.EventHandler(this.add_shape_to_array_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.checkBox_Triangle);
            this.groupBox1.Controls.Add(this.checkBox_Rectangle);
            this.groupBox1.Controls.Add(this.checkBox_Moon);
            this.groupBox1.Controls.Add(this.checkBox_Circle);
            this.groupBox1.Controls.Add(this.checkBox_Ellipse);
            this.groupBox1.Location = new System.Drawing.Point(569, 65);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(105, 190);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "add to array";
            // 
            // show_result_btn
            // 
            this.show_result_btn.BackColor = System.Drawing.SystemColors.Info;
            this.show_result_btn.Location = new System.Drawing.Point(443, 261);
            this.show_result_btn.Name = "show_result_btn";
            this.show_result_btn.Size = new System.Drawing.Size(106, 54);
            this.show_result_btn.TabIndex = 7;
            this.show_result_btn.Text = "Show Result ";
            this.show_result_btn.UseVisualStyleBackColor = false;
            this.show_result_btn.Click += new System.EventHandler(this.show_result_btn_Click);
            // 
            // label_Result
            // 
            this.label_Result.AutoSize = true;
            this.label_Result.Location = new System.Drawing.Point(530, 336);
            this.label_Result.Name = "label_Result";
            this.label_Result.Size = new System.Drawing.Size(49, 20);
            this.label_Result.TabIndex = 8;
            this.label_Result.Text = "Result";
            this.label_Result.Click += new System.EventHandler(this.label_Result_Click);
            // 
            // DeleteBtn
            // 
            this.DeleteBtn.BackColor = System.Drawing.SystemColors.Info;
            this.DeleteBtn.Location = new System.Drawing.Point(567, 261);
            this.DeleteBtn.Name = "DeleteBtn";
            this.DeleteBtn.Size = new System.Drawing.Size(105, 54);
            this.DeleteBtn.TabIndex = 9;
            this.DeleteBtn.Text = "Delete All";
            this.DeleteBtn.UseVisualStyleBackColor = false;
            this.DeleteBtn.Click += new System.EventHandler(this.DeleteBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.DeleteBtn);
            this.Controls.Add(this.label_Result);
            this.Controls.Add(this.show_result_btn);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.add_shape_to_array);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.shape2_textbox);
            this.Controls.Add(this.shape1_textbox);
            this.Controls.Add(this.calculate);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Button calculate;
        private TextBox shape1_textbox;
        private TextBox shape2_textbox;
        private Label label1;
        private Label label2;
        private Label label3;
        private CheckBox checkBox_Rectangle;
        private CheckBox checkBox_Circle;
        private CheckBox checkBox_Ellipse;
        private CheckBox checkBox_Triangle;
        private CheckBox checkBox_Moon;
        private Button add_shape_to_array;
        private GroupBox groupBox1;
        private Button show_result_btn;
        private Label label_Result;
        private Button DeleteBtn;
    }
}