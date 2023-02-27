namespace CW11_password_confirm
{
    partial class frmChenchPassword
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
            this.label_ID = new System.Windows.Forms.Label();
            this.textBox_OldPassword = new System.Windows.Forms.TextBox();
            this.label_old_password = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox_NewPassword = new System.Windows.Forms.TextBox();
            this.textBox_confirm_NewPassword = new System.Windows.Forms.TextBox();
            this.button_confirm = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label_ID
            // 
            this.label_ID.AutoSize = true;
            this.label_ID.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label_ID.Location = new System.Drawing.Point(278, 28);
            this.label_ID.Name = "label_ID";
            this.label_ID.Size = new System.Drawing.Size(103, 25);
            this.label_ID.TabIndex = 0;
            this.label_ID.Text = "תעודת זהות";
            this.label_ID.Click += new System.EventHandler(this.label_ID_Click);
            // 
            // textBox_OldPassword
            // 
            this.textBox_OldPassword.Location = new System.Drawing.Point(350, 106);
            this.textBox_OldPassword.Name = "textBox_OldPassword";
            this.textBox_OldPassword.Size = new System.Drawing.Size(198, 22);
            this.textBox_OldPassword.TabIndex = 1;
            this.textBox_OldPassword.TextChanged += new System.EventHandler(this.textBox_OldPassword_TextChanged);
            // 
            // label_old_password
            // 
            this.label_old_password.AutoSize = true;
            this.label_old_password.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label_old_password.Location = new System.Drawing.Point(566, 102);
            this.label_old_password.Name = "label_old_password";
            this.label_old_password.Size = new System.Drawing.Size(102, 25);
            this.label_old_password.TabIndex = 2;
            this.label_old_password.Text = "סיסמא ישנה";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label2.Location = new System.Drawing.Point(571, 188);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(110, 25);
            this.label2.TabIndex = 3;
            this.label2.Text = "סיסמא חדשה";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label3.Location = new System.Drawing.Point(554, 258);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(161, 25);
            this.label3.TabIndex = 4;
            this.label3.Text = "אישור סיסמא חדשה";
            // 
            // textBox_NewPassword
            // 
            this.textBox_NewPassword.Location = new System.Drawing.Point(350, 182);
            this.textBox_NewPassword.Name = "textBox_NewPassword";
            this.textBox_NewPassword.Size = new System.Drawing.Size(198, 22);
            this.textBox_NewPassword.TabIndex = 5;
            this.textBox_NewPassword.TextChanged += new System.EventHandler(this.textBox_NewPassword_TextChanged);
            // 
            // textBox_confirm_NewPassword
            // 
            this.textBox_confirm_NewPassword.Location = new System.Drawing.Point(350, 258);
            this.textBox_confirm_NewPassword.Name = "textBox_confirm_NewPassword";
            this.textBox_confirm_NewPassword.Size = new System.Drawing.Size(198, 22);
            this.textBox_confirm_NewPassword.TabIndex = 6;
            this.textBox_confirm_NewPassword.TextChanged += new System.EventHandler(this.textBox_confirm_NewPassword_TextChanged);
            // 
            // button_confirm
            // 
            this.button_confirm.BackColor = System.Drawing.Color.DarkCyan;
            this.button_confirm.Location = new System.Drawing.Point(360, 328);
            this.button_confirm.Name = "button_confirm";
            this.button_confirm.Size = new System.Drawing.Size(165, 56);
            this.button_confirm.TabIndex = 7;
            this.button_confirm.Text = "אישור";
            this.button_confirm.UseVisualStyleBackColor = false;
            this.button_confirm.Click += new System.EventHandler(this.button_confirm_Click);
            // 
            // frmChenchPassword
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkGray;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button_confirm);
            this.Controls.Add(this.textBox_confirm_NewPassword);
            this.Controls.Add(this.textBox_NewPassword);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label_old_password);
            this.Controls.Add(this.textBox_OldPassword);
            this.Controls.Add(this.label_ID);
            this.Name = "frmChenchPassword";
            this.Text = "frmChenchPassword";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_ID;
        private System.Windows.Forms.TextBox textBox_OldPassword;
        private System.Windows.Forms.Label label_old_password;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox_NewPassword;
        private System.Windows.Forms.TextBox textBox_confirm_NewPassword;
        private System.Windows.Forms.Button button_confirm;
    }
}