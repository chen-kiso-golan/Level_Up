namespace week_4_Winform_Interface
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
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.LoadBtn = new System.Windows.Forms.Button();
            this.ShowTxtBtn = new System.Windows.Forms.Label();
            this.DeletBtn = new System.Windows.Forms.Button();
            this.ColaBtn = new System.Windows.Forms.Button();
            this.KinlyBtn = new System.Windows.Forms.Button();
            this.ShowArrayBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(381, 122);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(178, 64);
            this.button1.TabIndex = 0;
            this.button1.Text = "Upload to file";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(41, 136);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 25);
            this.label1.TabIndex = 1;
            this.label1.Text = "name:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(41, 236);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(45, 25);
            this.label2.TabIndex = 2;
            this.label2.Text = "day:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(41, 345);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(45, 25);
            this.label3.TabIndex = 3;
            this.label3.Text = "age:";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(166, 130);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(150, 31);
            this.textBox1.TabIndex = 4;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(166, 230);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(150, 31);
            this.textBox2.TabIndex = 5;
            this.textBox2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(166, 339);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(150, 31);
            this.textBox3.TabIndex = 6;
            this.textBox3.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(41, 40);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(153, 25);
            this.label4.TabIndex = 7;
            this.label4.Text = "enter your details:";
            // 
            // LoadBtn
            // 
            this.LoadBtn.Location = new System.Drawing.Point(381, 211);
            this.LoadBtn.Name = "LoadBtn";
            this.LoadBtn.Size = new System.Drawing.Size(178, 69);
            this.LoadBtn.TabIndex = 8;
            this.LoadBtn.Text = "Load from file";
            this.LoadBtn.UseVisualStyleBackColor = true;
            this.LoadBtn.Click += new System.EventHandler(this.LoadBtn_Click);
            // 
            // ShowTxtBtn
            // 
            this.ShowTxtBtn.AutoSize = true;
            this.ShowTxtBtn.Location = new System.Drawing.Point(417, 339);
            this.ShowTxtBtn.Name = "ShowTxtBtn";
            this.ShowTxtBtn.Size = new System.Drawing.Size(111, 25);
            this.ShowTxtBtn.TabIndex = 9;
            this.ShowTxtBtn.Text = "your text is...";
            this.ShowTxtBtn.Click += new System.EventHandler(this.ShowTxtBtn_Click);
            // 
            // DeletBtn
            // 
            this.DeletBtn.Location = new System.Drawing.Point(417, 286);
            this.DeletBtn.Name = "DeletBtn";
            this.DeletBtn.Size = new System.Drawing.Size(112, 34);
            this.DeletBtn.TabIndex = 10;
            this.DeletBtn.Text = "Delet file";
            this.DeletBtn.UseVisualStyleBackColor = true;
            this.DeletBtn.Click += new System.EventHandler(this.DeletBtn_Click);
            // 
            // ColaBtn
            // 
            this.ColaBtn.Location = new System.Drawing.Point(630, 57);
            this.ColaBtn.Name = "ColaBtn";
            this.ColaBtn.Size = new System.Drawing.Size(112, 34);
            this.ColaBtn.TabIndex = 11;
            this.ColaBtn.Text = "Cola Price";
            this.ColaBtn.UseVisualStyleBackColor = true;
            this.ColaBtn.Click += new System.EventHandler(this.ItemBtn_Click);
            // 
            // KinlyBtn
            // 
            this.KinlyBtn.Location = new System.Drawing.Point(630, 111);
            this.KinlyBtn.Name = "KinlyBtn";
            this.KinlyBtn.Size = new System.Drawing.Size(112, 34);
            this.KinlyBtn.TabIndex = 13;
            this.KinlyBtn.Text = "Kinly Price";
            this.KinlyBtn.UseVisualStyleBackColor = true;
            this.KinlyBtn.Click += new System.EventHandler(this.KinlyBtn_Click);
            // 
            // ShowArrayBtn
            // 
            this.ShowArrayBtn.Location = new System.Drawing.Point(630, 163);
            this.ShowArrayBtn.Name = "ShowArrayBtn";
            this.ShowArrayBtn.Size = new System.Drawing.Size(112, 34);
            this.ShowArrayBtn.TabIndex = 14;
            this.ShowArrayBtn.Text = "show array";
            this.ShowArrayBtn.UseVisualStyleBackColor = true;
            this.ShowArrayBtn.Click += new System.EventHandler(this.ShowArrayBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.ShowArrayBtn);
            this.Controls.Add(this.KinlyBtn);
            this.Controls.Add(this.ColaBtn);
            this.Controls.Add(this.DeletBtn);
            this.Controls.Add(this.ShowTxtBtn);
            this.Controls.Add(this.LoadBtn);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Button button1;
        private Label label1;
        private Label label2;
        private Label label3;
        private TextBox textBox1;
        private TextBox textBox2;
        private TextBox textBox3;
        private Label label4;
        private Button LoadBtn;
        private Label ShowTxtBtn;
        private Button DeletBtn;
        private Button ColaBtn;
        private Button KinlyBtn;
        private Button ShowArrayBtn;
    }
}