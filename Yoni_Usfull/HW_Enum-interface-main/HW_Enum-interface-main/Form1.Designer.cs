namespace CW9_TheInterfaceApp
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
            this.textBox_Name = new System.Windows.Forms.TextBox();
            this.textBox_Day = new System.Windows.Forms.TextBox();
            this.textBox_Age = new System.Windows.Forms.TextBox();
            this.Save_Btn = new System.Windows.Forms.Button();
            this.label_Name = new System.Windows.Forms.Label();
            this.label_Age = new System.Windows.Forms.Label();
            this.label_Day = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.Create_Item_Btn = new System.Windows.Forms.Button();
            this.Cola_for_arr = new System.Windows.Forms.Button();
            this.Kinly_for_arr = new System.Windows.Forms.Button();
            this.Print_Arr = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox_Name
            // 
            this.textBox_Name.Location = new System.Drawing.Point(97, 13);
            this.textBox_Name.Name = "textBox_Name";
            this.textBox_Name.Size = new System.Drawing.Size(125, 27);
            this.textBox_Name.TabIndex = 0;
            this.textBox_Name.TextChanged += new System.EventHandler(this.textBox_Name_TextChanged);
            // 
            // textBox_Day
            // 
            this.textBox_Day.Location = new System.Drawing.Point(97, 69);
            this.textBox_Day.Name = "textBox_Day";
            this.textBox_Day.Size = new System.Drawing.Size(125, 27);
            this.textBox_Day.TabIndex = 0;
            this.textBox_Day.TextChanged += new System.EventHandler(this.textBox_Day_TextChanged);
            // 
            // textBox_Age
            // 
            this.textBox_Age.Location = new System.Drawing.Point(97, 123);
            this.textBox_Age.Name = "textBox_Age";
            this.textBox_Age.Size = new System.Drawing.Size(125, 27);
            this.textBox_Age.TabIndex = 0;
            this.textBox_Age.TextChanged += new System.EventHandler(this.textBox_Age_TextChanged);
            // 
            // Save_Btn
            // 
            this.Save_Btn.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.Save_Btn.Location = new System.Drawing.Point(305, 13);
            this.Save_Btn.Name = "Save_Btn";
            this.Save_Btn.Size = new System.Drawing.Size(137, 36);
            this.Save_Btn.TabIndex = 1;
            this.Save_Btn.Text = "Save to File";
            this.Save_Btn.UseVisualStyleBackColor = false;
            this.Save_Btn.Click += new System.EventHandler(this.button1_Click);
            // 
            // label_Name
            // 
            this.label_Name.AutoSize = true;
            this.label_Name.Location = new System.Drawing.Point(20, 13);
            this.label_Name.Name = "label_Name";
            this.label_Name.Size = new System.Drawing.Size(49, 20);
            this.label_Name.TabIndex = 2;
            this.label_Name.Text = "Name";
            // 
            // label_Age
            // 
            this.label_Age.AutoSize = true;
            this.label_Age.Location = new System.Drawing.Point(20, 123);
            this.label_Age.Name = "label_Age";
            this.label_Age.Size = new System.Drawing.Size(36, 20);
            this.label_Age.TabIndex = 2;
            this.label_Age.Text = "Age";
            // 
            // label_Day
            // 
            this.label_Day.AutoSize = true;
            this.label_Day.Location = new System.Drawing.Point(20, 69);
            this.label_Day.Name = "label_Day";
            this.label_Day.Size = new System.Drawing.Size(35, 20);
            this.label_Day.TabIndex = 2;
            this.label_Day.Text = "Day";
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.SystemColors.Info;
            this.button2.Location = new System.Drawing.Point(305, 69);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(137, 34);
            this.button2.TabIndex = 3;
            this.button2.Text = "Lode and Show";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Create_Item_Btn
            // 
            this.Create_Item_Btn.Location = new System.Drawing.Point(587, 13);
            this.Create_Item_Btn.Name = "Create_Item_Btn";
            this.Create_Item_Btn.Size = new System.Drawing.Size(166, 36);
            this.Create_Item_Btn.TabIndex = 4;
            this.Create_Item_Btn.Text = "Create one Cola Item";
            this.Create_Item_Btn.UseVisualStyleBackColor = true;
            this.Create_Item_Btn.Click += new System.EventHandler(this.Create_Item_Btn_Click);
            // 
            // Cola_for_arr
            // 
            this.Cola_for_arr.Location = new System.Drawing.Point(551, 74);
            this.Cola_for_arr.Name = "Cola_for_arr";
            this.Cola_for_arr.Size = new System.Drawing.Size(94, 29);
            this.Cola_for_arr.TabIndex = 5;
            this.Cola_for_arr.Text = "Cola for arr";
            this.Cola_for_arr.UseVisualStyleBackColor = true;
            this.Cola_for_arr.Click += new System.EventHandler(this.Cola_for_arr_Click);
            // 
            // Kinly_for_arr
            // 
            this.Kinly_for_arr.Location = new System.Drawing.Point(694, 74);
            this.Kinly_for_arr.Name = "Kinly_for_arr";
            this.Kinly_for_arr.Size = new System.Drawing.Size(94, 29);
            this.Kinly_for_arr.TabIndex = 6;
            this.Kinly_for_arr.Text = "Kinly for arr";
            this.Kinly_for_arr.UseVisualStyleBackColor = true;
            this.Kinly_for_arr.Click += new System.EventHandler(this.Kinly_for_arr_Click);
            // 
            // Print_Arr
            // 
            this.Print_Arr.Location = new System.Drawing.Point(623, 123);
            this.Print_Arr.Name = "Print_Arr";
            this.Print_Arr.Size = new System.Drawing.Size(94, 29);
            this.Print_Arr.TabIndex = 7;
            this.Print_Arr.Text = "Print Arr";
            this.Print_Arr.UseVisualStyleBackColor = true;
            this.Print_Arr.Click += new System.EventHandler(this.Print_Arr_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Menu;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.Print_Arr);
            this.Controls.Add(this.Kinly_for_arr);
            this.Controls.Add(this.Cola_for_arr);
            this.Controls.Add(this.Create_Item_Btn);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label_Day);
            this.Controls.Add(this.label_Age);
            this.Controls.Add(this.label_Name);
            this.Controls.Add(this.Save_Btn);
            this.Controls.Add(this.textBox_Age);
            this.Controls.Add(this.textBox_Day);
            this.Controls.Add(this.textBox_Name);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private TextBox textBox_Name;
        private TextBox textBox_Day;
        private TextBox textBox_Age;
        private Button Save_Btn;
        private Label label_Name;
        private Label label_Age;
        private Label label_Day;
        private Button button2;
        private Button Create_Item_Btn;
        private Button Cola_for_arr;
        private Button Kinly_for_arr;
        private Button Print_Arr;
    }
}