namespace ProjectStudent.UI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Add_Student_btn = new System.Windows.Forms.Button();
            this.label_name = new System.Windows.Forms.Label();
            this.label2_age = new System.Windows.Forms.Label();
            this.label_Adress = new System.Windows.Forms.Label();
            this.label_ID = new System.Windows.Forms.Label();
            this.Reset_btn = new System.Windows.Forms.Button();
            this.Show_all_data_by_id = new System.Windows.Forms.Button();
            this.textBox_Name = new System.Windows.Forms.TextBox();
            this.textBox_Age = new System.Windows.Forms.TextBox();
            this.textBox_Adress = new System.Windows.Forms.TextBox();
            this.textBox_ID = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Add_Student_btn
            // 
            this.Add_Student_btn.BackColor = System.Drawing.Color.LightBlue;
            this.Add_Student_btn.Location = new System.Drawing.Point(105, 258);
            this.Add_Student_btn.Name = "Add_Student_btn";
            this.Add_Student_btn.Size = new System.Drawing.Size(123, 34);
            this.Add_Student_btn.TabIndex = 0;
            this.Add_Student_btn.Text = "Add Student";
            this.Add_Student_btn.UseVisualStyleBackColor = false;
            this.Add_Student_btn.Click += new System.EventHandler(this.Add_Student_btn_Click);
            // 
            // label_name
            // 
            this.label_name.AutoSize = true;
            this.label_name.Location = new System.Drawing.Point(55, 80);
            this.label_name.Name = "label_name";
            this.label_name.Size = new System.Drawing.Size(44, 16);
            this.label_name.TabIndex = 3;
            this.label_name.Text = "Name";
            // 
            // label2_age
            // 
            this.label2_age.AutoSize = true;
            this.label2_age.Location = new System.Drawing.Point(55, 121);
            this.label2_age.Name = "label2_age";
            this.label2_age.Size = new System.Drawing.Size(32, 16);
            this.label2_age.TabIndex = 3;
            this.label2_age.Text = "Age";
            // 
            // label_Adress
            // 
            this.label_Adress.AutoSize = true;
            this.label_Adress.Location = new System.Drawing.Point(55, 159);
            this.label_Adress.Name = "label_Adress";
            this.label_Adress.Size = new System.Drawing.Size(50, 16);
            this.label_Adress.TabIndex = 3;
            this.label_Adress.Text = "Adress";
            // 
            // label_ID
            // 
            this.label_ID.AutoSize = true;
            this.label_ID.Location = new System.Drawing.Point(55, 205);
            this.label_ID.Name = "label_ID";
            this.label_ID.Size = new System.Drawing.Size(20, 16);
            this.label_ID.TabIndex = 3;
            this.label_ID.Text = "ID";
            // 
            // Reset_btn
            // 
            this.Reset_btn.BackColor = System.Drawing.Color.LightBlue;
            this.Reset_btn.Location = new System.Drawing.Point(12, 258);
            this.Reset_btn.Name = "Reset_btn";
            this.Reset_btn.Size = new System.Drawing.Size(87, 34);
            this.Reset_btn.TabIndex = 4;
            this.Reset_btn.Text = "Reset";
            this.Reset_btn.UseVisualStyleBackColor = false;
            this.Reset_btn.Click += new System.EventHandler(this.Reset_btn_Click);
            // 
            // Show_all_data_by_id
            // 
            this.Show_all_data_by_id.BackColor = System.Drawing.Color.LightBlue;
            this.Show_all_data_by_id.Location = new System.Drawing.Point(234, 199);
            this.Show_all_data_by_id.Name = "Show_all_data_by_id";
            this.Show_all_data_by_id.Size = new System.Drawing.Size(124, 29);
            this.Show_all_data_by_id.TabIndex = 5;
            this.Show_all_data_by_id.Text = "Show data by id";
            this.Show_all_data_by_id.UseVisualStyleBackColor = false;
            this.Show_all_data_by_id.Click += new System.EventHandler(this.Show_all_data_by_id_Click);
            // 
            // textBox_Name
            // 
            this.textBox_Name.Location = new System.Drawing.Point(105, 74);
            this.textBox_Name.Name = "textBox_Name";
            this.textBox_Name.Size = new System.Drawing.Size(100, 22);
            this.textBox_Name.TabIndex = 6;
            this.textBox_Name.TextChanged += new System.EventHandler(this.textBox_Name_TextChanged);
            // 
            // textBox_Age
            // 
            this.textBox_Age.Location = new System.Drawing.Point(105, 118);
            this.textBox_Age.Name = "textBox_Age";
            this.textBox_Age.Size = new System.Drawing.Size(100, 22);
            this.textBox_Age.TabIndex = 7;
            this.textBox_Age.TextChanged += new System.EventHandler(this.textBox_Age_TextChanged);
            // 
            // textBox_Adress
            // 
            this.textBox_Adress.Location = new System.Drawing.Point(105, 156);
            this.textBox_Adress.Name = "textBox_Adress";
            this.textBox_Adress.Size = new System.Drawing.Size(100, 22);
            this.textBox_Adress.TabIndex = 8;
            this.textBox_Adress.TextChanged += new System.EventHandler(this.textBox_Adress_TextChanged);
            // 
            // textBox_ID
            // 
            this.textBox_ID.Location = new System.Drawing.Point(105, 202);
            this.textBox_ID.Name = "textBox_ID";
            this.textBox_ID.Size = new System.Drawing.Size(100, 22);
            this.textBox_ID.TabIndex = 9;
            this.textBox_ID.TextChanged += new System.EventHandler(this.textBox_ID_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textBox_ID);
            this.Controls.Add(this.textBox_Adress);
            this.Controls.Add(this.textBox_Age);
            this.Controls.Add(this.textBox_Name);
            this.Controls.Add(this.Show_all_data_by_id);
            this.Controls.Add(this.Reset_btn);
            this.Controls.Add(this.label_ID);
            this.Controls.Add(this.label_Adress);
            this.Controls.Add(this.label2_age);
            this.Controls.Add(this.label_name);
            this.Controls.Add(this.Add_Student_btn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Add_Student_btn;
        private System.Windows.Forms.Button Show_data_by_id;
        private System.Windows.Forms.Label label_name;
        private System.Windows.Forms.Label label2_age;
        private System.Windows.Forms.Label label_Adress;
        private System.Windows.Forms.Label label_ID;
        private System.Windows.Forms.Button Reset_btn;
        private System.Windows.Forms.Button Show_all_data_by_id;
        private System.Windows.Forms.TextBox textBox_Name;
        private System.Windows.Forms.TextBox textBox_Age;
        private System.Windows.Forms.TextBox textBox_Adress;
        private System.Windows.Forms.TextBox textBox_ID;
    }
}

