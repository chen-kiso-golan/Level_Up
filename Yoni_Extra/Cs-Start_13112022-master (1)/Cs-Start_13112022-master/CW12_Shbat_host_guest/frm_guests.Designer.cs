namespace CW12_Shbat_host_guest
{
    partial class frm_guests
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
            this.Enter_guests_btn = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.TBox_gusts_main = new System.Windows.Forms.TextBox();
            this.listBox_gusts_main = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // Enter_guests_btn
            // 
            this.Enter_guests_btn.BackColor = System.Drawing.Color.CornflowerBlue;
            this.Enter_guests_btn.Location = new System.Drawing.Point(299, 341);
            this.Enter_guests_btn.Name = "Enter_guests_btn";
            this.Enter_guests_btn.Size = new System.Drawing.Size(141, 43);
            this.Enter_guests_btn.TabIndex = 0;
            this.Enter_guests_btn.Text = "אישור";
            this.Enter_guests_btn.UseVisualStyleBackColor = false;
            this.Enter_guests_btn.Click += new System.EventHandler(this.Enter_guests_btn_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label1.Location = new System.Drawing.Point(296, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(207, 29);
            this.label1.TabIndex = 1;
            this.label1.Text = "ברוכים הבאים לשבת";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label2.Location = new System.Drawing.Point(321, 89);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(120, 24);
            this.label2.TabIndex = 2;
            this.label2.Text = "הכנס שם אורח";
            // 
            // TBox_gusts_main
            // 
            this.TBox_gusts_main.Location = new System.Drawing.Point(301, 157);
            this.TBox_gusts_main.Name = "TBox_gusts_main";
            this.TBox_gusts_main.Size = new System.Drawing.Size(139, 22);
            this.TBox_gusts_main.TabIndex = 3;
            this.TBox_gusts_main.TextChanged += new System.EventHandler(this.TBox_gusts_main_TextChanged);
            // 
            // listBox_gusts_main
            // 
            this.listBox_gusts_main.FormattingEnabled = true;
            this.listBox_gusts_main.ItemHeight = 16;
            this.listBox_gusts_main.Location = new System.Drawing.Point(301, 220);
            this.listBox_gusts_main.Name = "listBox_gusts_main";
            this.listBox_gusts_main.Size = new System.Drawing.Size(139, 84);
            this.listBox_gusts_main.TabIndex = 4;
            this.listBox_gusts_main.SelectedIndexChanged += new System.EventHandler(this.listBox_gusts_main_SelectedIndexChanged);
            // 
            // frm_guests
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Cornsilk;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.listBox_gusts_main);
            this.Controls.Add(this.TBox_gusts_main);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Enter_guests_btn);
            this.Name = "frm_guests";
            this.Text = "frm_guests";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Enter_guests_btn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox TBox_gusts_main;
        private System.Windows.Forms.ListBox listBox_gusts_main;
    }
}