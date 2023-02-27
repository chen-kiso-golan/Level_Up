namespace CW11_password_confirm
{
    partial class frmTimeClock
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
            this.UserNaem_label = new System.Windows.Forms.Label();
            this.Password_label = new System.Windows.Forms.Label();
            this.textBox_UserID = new System.Windows.Forms.TextBox();
            this.textBox_password = new System.Windows.Forms.TextBox();
            this.btn_chench_password = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // UserNaem_label
            // 
            this.UserNaem_label.AutoSize = true;
            this.UserNaem_label.Location = new System.Drawing.Point(242, 69);
            this.UserNaem_label.Name = "UserNaem_label";
            this.UserNaem_label.Size = new System.Drawing.Size(106, 16);
            this.UserNaem_label.TabIndex = 0;
            this.UserNaem_label.Text = "הכנס תעודה זהות";
            // 
            // Password_label
            // 
            this.Password_label.AutoSize = true;
            this.Password_label.Location = new System.Drawing.Point(274, 182);
            this.Password_label.Name = "Password_label";
            this.Password_label.Size = new System.Drawing.Size(44, 16);
            this.Password_label.TabIndex = 1;
            this.Password_label.Text = "סיסמא";
            // 
            // textBox_UserID
            // 
            this.textBox_UserID.Location = new System.Drawing.Point(227, 98);
            this.textBox_UserID.Name = "textBox_UserID";
            this.textBox_UserID.Size = new System.Drawing.Size(121, 22);
            this.textBox_UserID.TabIndex = 2;
            this.textBox_UserID.TextChanged += new System.EventHandler(this.textBox_UserID_TextChanged);
            // 
            // textBox_password
            // 
            this.textBox_password.Location = new System.Drawing.Point(227, 212);
            this.textBox_password.Name = "textBox_password";
            this.textBox_password.Size = new System.Drawing.Size(121, 22);
            this.textBox_password.TabIndex = 3;
            this.textBox_password.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox_password_KeyPress);
            // 
            // btn_chench_password
            // 
            this.btn_chench_password.BackColor = System.Drawing.Color.DarkKhaki;
            this.btn_chench_password.Location = new System.Drawing.Point(438, 294);
            this.btn_chench_password.Name = "btn_chench_password";
            this.btn_chench_password.Size = new System.Drawing.Size(112, 58);
            this.btn_chench_password.TabIndex = 4;
            this.btn_chench_password.Text = "החלפת סיסמא";
            this.btn_chench_password.UseVisualStyleBackColor = false;
            this.btn_chench_password.Click += new System.EventHandler(this.btn_chench_password_Click);
            // 
            // frmTimeClock
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Cornsilk;
            this.ClientSize = new System.Drawing.Size(795, 533);
            this.Controls.Add(this.btn_chench_password);
            this.Controls.Add(this.textBox_password);
            this.Controls.Add(this.textBox_UserID);
            this.Controls.Add(this.Password_label);
            this.Controls.Add(this.UserNaem_label);
            this.Name = "frmTimeClock";
            this.Text = "frmTimeClock";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label UserNaem_label;
        private System.Windows.Forms.Label Password_label;
        private System.Windows.Forms.TextBox textBox_UserID;
        private System.Windows.Forms.TextBox textBox_password;
        private System.Windows.Forms.Button btn_chench_password;
    }
}