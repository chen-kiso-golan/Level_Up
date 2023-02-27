namespace CW16_WinForm_link
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
            this.button2 = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.WriteToFileBtn = new System.Windows.Forms.Button();
            this.CountDownBtn = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.webDataBtn = new System.Windows.Forms.Button();
            this.webText = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.YnetTitelBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(962, 123);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(154, 53);
            this.button1.TabIndex = 0;
            this.button1.Text = "start";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(867, 54);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "label1";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(962, 40);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(154, 55);
            this.button2.TabIndex = 2;
            this.button2.Text = "משפיע על שתי הלייבלים";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(867, 114);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "label2";
            // 
            // WriteToFileBtn
            // 
            this.WriteToFileBtn.Location = new System.Drawing.Point(962, 207);
            this.WriteToFileBtn.Name = "WriteToFileBtn";
            this.WriteToFileBtn.Size = new System.Drawing.Size(154, 52);
            this.WriteToFileBtn.TabIndex = 4;
            this.WriteToFileBtn.Text = "WriteToFile";
            this.WriteToFileBtn.UseVisualStyleBackColor = true;
            this.WriteToFileBtn.Click += new System.EventHandler(this.WriteToFileBtn_Click);
            // 
            // CountDownBtn
            // 
            this.CountDownBtn.Location = new System.Drawing.Point(962, 309);
            this.CountDownBtn.Name = "CountDownBtn";
            this.CountDownBtn.Size = new System.Drawing.Size(154, 49);
            this.CountDownBtn.TabIndex = 5;
            this.CountDownBtn.Text = "CountDown";
            this.CountDownBtn.UseVisualStyleBackColor = true;
            this.CountDownBtn.Click += new System.EventHandler(this.CountDownBtn_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(867, 309);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(50, 20);
            this.label3.TabIndex = 6;
            this.label3.Text = "label3";
            // 
            // webDataBtn
            // 
            this.webDataBtn.Location = new System.Drawing.Point(367, 54);
            this.webDataBtn.Name = "webDataBtn";
            this.webDataBtn.Size = new System.Drawing.Size(128, 50);
            this.webDataBtn.TabIndex = 7;
            this.webDataBtn.Text = "webData";
            this.webDataBtn.UseVisualStyleBackColor = true;
            this.webDataBtn.Click += new System.EventHandler(this.webDataBtn_Click);
            // 
            // webText
            // 
            this.webText.Location = new System.Drawing.Point(48, 136);
            this.webText.Multiline = true;
            this.webText.Name = "webText";
            this.webText.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.webText.Size = new System.Drawing.Size(799, 534);
            this.webText.TabIndex = 8;
            this.webText.TextChanged += new System.EventHandler(this.webText_TextChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(576, 68);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(50, 20);
            this.label4.TabIndex = 9;
            this.label4.Text = "label4";
            // 
            // YnetTitelBtn
            // 
            this.YnetTitelBtn.Location = new System.Drawing.Point(202, 54);
            this.YnetTitelBtn.Name = "YnetTitelBtn";
            this.YnetTitelBtn.Size = new System.Drawing.Size(142, 50);
            this.YnetTitelBtn.TabIndex = 10;
            this.YnetTitelBtn.Text = "YnetTitel";
            this.YnetTitelBtn.UseVisualStyleBackColor = true;
            this.YnetTitelBtn.Click += new System.EventHandler(this.YnetTitelBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1163, 720);
            this.Controls.Add(this.YnetTitelBtn);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.webText);
            this.Controls.Add(this.webDataBtn);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.CountDownBtn);
            this.Controls.Add(this.WriteToFileBtn);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button2);
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
        private Button button2;
        private Label label2;
        private Button WriteToFileBtn;
        private Button CountDownBtn;
        private Label label3;
        private Button webDataBtn;
        private TextBox webText;
        private Label label4;
        private Button YnetTitelBtn;
    }
}