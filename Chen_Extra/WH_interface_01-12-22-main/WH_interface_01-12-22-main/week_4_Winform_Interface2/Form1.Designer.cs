namespace week_4_Winform_Interface2
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
            this.CheckBtn = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.circleBtn = new System.Windows.Forms.CheckBox();
            this.triangleBtn = new System.Windows.Forms.CheckBox();
            this.rectangleBtn = new System.Windows.Forms.CheckBox();
            this.moonBtn = new System.Windows.Forms.CheckBox();
            this.ellipseBtn = new System.Windows.Forms.CheckBox();
            this.addBtn = new System.Windows.Forms.Button();
            this.arrayLabel = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.ShowResultBtn = new System.Windows.Forms.Button();
            this.DeletAllBtn = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // CheckBtn
            // 
            this.CheckBtn.Location = new System.Drawing.Point(147, 226);
            this.CheckBtn.Name = "CheckBtn";
            this.CheckBtn.Size = new System.Drawing.Size(112, 34);
            this.CheckBtn.TabIndex = 0;
            this.CheckBtn.Text = "Check ";
            this.CheckBtn.UseVisualStyleBackColor = true;
            this.CheckBtn.Click += new System.EventHandler(this.CheckBtn_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(131, 123);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(150, 31);
            this.textBox1.TabIndex = 1;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(131, 169);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(150, 31);
            this.textBox2.TabIndex = 2;
            this.textBox2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // circleBtn
            // 
            this.circleBtn.AutoSize = true;
            this.circleBtn.Location = new System.Drawing.Point(15, 40);
            this.circleBtn.Name = "circleBtn";
            this.circleBtn.Size = new System.Drawing.Size(77, 29);
            this.circleBtn.TabIndex = 3;
            this.circleBtn.Text = "circle";
            this.circleBtn.UseVisualStyleBackColor = true;
            // 
            // triangleBtn
            // 
            this.triangleBtn.AutoSize = true;
            this.triangleBtn.Location = new System.Drawing.Point(15, 75);
            this.triangleBtn.Name = "triangleBtn";
            this.triangleBtn.Size = new System.Drawing.Size(97, 29);
            this.triangleBtn.TabIndex = 4;
            this.triangleBtn.Text = "triangle";
            this.triangleBtn.UseVisualStyleBackColor = true;
            // 
            // rectangleBtn
            // 
            this.rectangleBtn.AutoSize = true;
            this.rectangleBtn.Location = new System.Drawing.Point(15, 110);
            this.rectangleBtn.Name = "rectangleBtn";
            this.rectangleBtn.Size = new System.Drawing.Size(110, 29);
            this.rectangleBtn.TabIndex = 5;
            this.rectangleBtn.Text = "rectangle";
            this.rectangleBtn.UseVisualStyleBackColor = true;
            // 
            // moonBtn
            // 
            this.moonBtn.AutoSize = true;
            this.moonBtn.Location = new System.Drawing.Point(15, 145);
            this.moonBtn.Name = "moonBtn";
            this.moonBtn.Size = new System.Drawing.Size(86, 29);
            this.moonBtn.TabIndex = 6;
            this.moonBtn.Text = "moon";
            this.moonBtn.UseVisualStyleBackColor = true;
            // 
            // ellipseBtn
            // 
            this.ellipseBtn.AutoSize = true;
            this.ellipseBtn.Location = new System.Drawing.Point(15, 180);
            this.ellipseBtn.Name = "ellipseBtn";
            this.ellipseBtn.Size = new System.Drawing.Size(87, 29);
            this.ellipseBtn.TabIndex = 7;
            this.ellipseBtn.Text = "ellipse";
            this.ellipseBtn.UseVisualStyleBackColor = true;
            // 
            // addBtn
            // 
            this.addBtn.Location = new System.Drawing.Point(609, 297);
            this.addBtn.Name = "addBtn";
            this.addBtn.Size = new System.Drawing.Size(112, 34);
            this.addBtn.TabIndex = 8;
            this.addBtn.Text = "ADD";
            this.addBtn.UseVisualStyleBackColor = true;
            this.addBtn.Click += new System.EventHandler(this.addBtn_Click);
            // 
            // arrayLabel
            // 
            this.arrayLabel.AutoSize = true;
            this.arrayLabel.Location = new System.Drawing.Point(736, 346);
            this.arrayLabel.Name = "arrayLabel";
            this.arrayLabel.Size = new System.Drawing.Size(33, 25);
            this.arrayLabel.TabIndex = 9;
            this.arrayLabel.Text = "---";
            this.arrayLabel.Click += new System.EventHandler(this.arrayLabel_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.circleBtn);
            this.groupBox1.Controls.Add(this.triangleBtn);
            this.groupBox1.Controls.Add(this.rectangleBtn);
            this.groupBox1.Controls.Add(this.ellipseBtn);
            this.groupBox1.Controls.Add(this.moonBtn);
            this.groupBox1.Location = new System.Drawing.Point(456, 257);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(138, 236);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "shapes:";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // ShowResultBtn
            // 
            this.ShowResultBtn.Location = new System.Drawing.Point(609, 341);
            this.ShowResultBtn.Name = "ShowResultBtn";
            this.ShowResultBtn.Size = new System.Drawing.Size(112, 34);
            this.ShowResultBtn.TabIndex = 11;
            this.ShowResultBtn.Text = "ShowResult";
            this.ShowResultBtn.UseVisualStyleBackColor = true;
            this.ShowResultBtn.Click += new System.EventHandler(this.ShowResultBtn_Click);
            // 
            // DeletAllBtn
            // 
            this.DeletAllBtn.Location = new System.Drawing.Point(609, 388);
            this.DeletAllBtn.Name = "DeletAllBtn";
            this.DeletAllBtn.Size = new System.Drawing.Size(112, 34);
            this.DeletAllBtn.TabIndex = 12;
            this.DeletAllBtn.Text = "DeleteAll";
            this.DeletAllBtn.UseVisualStyleBackColor = true;
            this.DeletAllBtn.Click += new System.EventHandler(this.DeletAllBtn_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(43, 54);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(388, 50);
            this.label1.TabIndex = 13;
            this.label1.Text = "enter your choice (Triangle, Rectangle or Moon) \r\nand check who has the most apex" +
    "es:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(432, 167);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(368, 75);
            this.label2.TabIndex = 14;
            this.label2.Text = "choose shapes and add them to your array. \r\npress the \"ShowResult\" button to chec" +
    "k how \r\nmany apexes your array has:\r\n";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(865, 522);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.DeletAllBtn);
            this.Controls.Add(this.ShowResultBtn);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.arrayLabel);
            this.Controls.Add(this.addBtn);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.CheckBtn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Button CheckBtn;
        private TextBox textBox1;
        private TextBox textBox2;
        private CheckBox circleBtn;
        private CheckBox triangleBtn;
        private CheckBox rectangleBtn;
        private CheckBox moonBtn;
        private CheckBox ellipseBtn;
        private Button addBtn;
        private Label arrayLabel;
        private GroupBox groupBox1;
        private Button ShowResultBtn;
        private Button DeletAllBtn;
        private Label label1;
        private Label label2;
    }
}