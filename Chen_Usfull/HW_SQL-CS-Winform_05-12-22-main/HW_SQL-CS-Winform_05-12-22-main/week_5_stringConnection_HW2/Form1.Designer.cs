namespace week_5_stringConnection_HW2
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.CustomersBtn = new System.Windows.Forms.Button();
            this.OrdersBtn = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.WorkerIdFromUser = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.WorkerBtn = new System.Windows.Forms.Button();
            this.RefreshBtn = new System.Windows.Forms.Button();
            this.RefreshProductsBtn = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.ProductIdFromUser = new System.Windows.Forms.TextBox();
            this.ShowProductBtn = new System.Windows.Forms.Button();
            this.ProductPriceLabel = new System.Windows.Forms.Label();
            this.ProductUnitLabel = new System.Windows.Forms.Label();
            this.ProductNameLabel = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.ProductsAbovePriceBtn = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.CustomersBtn);
            this.groupBox1.Controls.Add(this.OrdersBtn);
            this.groupBox1.Location = new System.Drawing.Point(24, 29);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(316, 202);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Q1 - two buttons:";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(171, 60);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 26);
            this.textBox1.TabIndex = 2;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // CustomersBtn
            // 
            this.CustomersBtn.Location = new System.Drawing.Point(20, 111);
            this.CustomersBtn.Name = "CustomersBtn";
            this.CustomersBtn.Size = new System.Drawing.Size(124, 67);
            this.CustomersBtn.TabIndex = 1;
            this.CustomersBtn.Text = "Number Of Customers";
            this.CustomersBtn.UseVisualStyleBackColor = true;
            this.CustomersBtn.Click += new System.EventHandler(this.OrderTextbox_Click);
            // 
            // OrdersBtn
            // 
            this.OrdersBtn.Location = new System.Drawing.Point(20, 42);
            this.OrdersBtn.Name = "OrdersBtn";
            this.OrdersBtn.Size = new System.Drawing.Size(124, 63);
            this.OrdersBtn.TabIndex = 0;
            this.OrdersBtn.Text = "Number Of Orders";
            this.OrdersBtn.UseVisualStyleBackColor = true;
            this.OrdersBtn.Click += new System.EventHandler(this.OrdersBtn_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.WorkerIdFromUser);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.WorkerBtn);
            this.groupBox2.Controls.Add(this.RefreshBtn);
            this.groupBox2.Location = new System.Drawing.Point(24, 248);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(316, 212);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Q2 - workers list:";
            // 
            // WorkerIdFromUser
            // 
            this.WorkerIdFromUser.Location = new System.Drawing.Point(42, 85);
            this.WorkerIdFromUser.Name = "WorkerIdFromUser";
            this.WorkerIdFromUser.Size = new System.Drawing.Size(100, 26);
            this.WorkerIdFromUser.TabIndex = 3;
            this.WorkerIdFromUser.TextChanged += new System.EventHandler(this.WorkerIdFromUser_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(142, 40);
            this.label1.TabIndex = 2;
            this.label1.Text = "enter a worker\'s ID\r\n(between 1-9):";
            // 
            // WorkerBtn
            // 
            this.WorkerBtn.Location = new System.Drawing.Point(29, 117);
            this.WorkerBtn.Name = "WorkerBtn";
            this.WorkerBtn.Size = new System.Drawing.Size(126, 77);
            this.WorkerBtn.TabIndex = 1;
            this.WorkerBtn.Text = "Show Worker\'s Name";
            this.WorkerBtn.UseVisualStyleBackColor = true;
            this.WorkerBtn.Click += new System.EventHandler(this.WorkerBtn_Click);
            // 
            // RefreshBtn
            // 
            this.RefreshBtn.Location = new System.Drawing.Point(182, 63);
            this.RefreshBtn.Name = "RefreshBtn";
            this.RefreshBtn.Size = new System.Drawing.Size(113, 67);
            this.RefreshBtn.TabIndex = 0;
            this.RefreshBtn.Text = "Refresh the Workers List";
            this.RefreshBtn.UseVisualStyleBackColor = true;
            this.RefreshBtn.Click += new System.EventHandler(this.RefreshBtn_Click);
            // 
            // RefreshProductsBtn
            // 
            this.RefreshProductsBtn.Location = new System.Drawing.Point(25, 29);
            this.RefreshProductsBtn.Name = "RefreshProductsBtn";
            this.RefreshProductsBtn.Size = new System.Drawing.Size(110, 63);
            this.RefreshProductsBtn.TabIndex = 2;
            this.RefreshProductsBtn.Text = "Refresh the Products List";
            this.RefreshProductsBtn.UseVisualStyleBackColor = true;
            this.RefreshProductsBtn.Click += new System.EventHandler(this.RefreshProductsBtn_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(21, 100);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(138, 40);
            this.label2.TabIndex = 3;
            this.label2.Text = "enter a product ID\r\n(between 1-77):";
            // 
            // ProductIdFromUser
            // 
            this.ProductIdFromUser.Location = new System.Drawing.Point(25, 143);
            this.ProductIdFromUser.Name = "ProductIdFromUser";
            this.ProductIdFromUser.Size = new System.Drawing.Size(110, 26);
            this.ProductIdFromUser.TabIndex = 4;
            this.ProductIdFromUser.TextChanged += new System.EventHandler(this.ProductIdFromUser_TextChanged);
            // 
            // ShowProductBtn
            // 
            this.ShowProductBtn.Location = new System.Drawing.Point(213, 25);
            this.ShowProductBtn.Name = "ShowProductBtn";
            this.ShowProductBtn.Size = new System.Drawing.Size(115, 62);
            this.ShowProductBtn.TabIndex = 5;
            this.ShowProductBtn.Text = "Show Product";
            this.ShowProductBtn.UseVisualStyleBackColor = true;
            this.ShowProductBtn.Click += new System.EventHandler(this.ShowProductBtn_Click);
            // 
            // ProductPriceLabel
            // 
            this.ProductPriceLabel.AutoSize = true;
            this.ProductPriceLabel.Location = new System.Drawing.Point(218, 120);
            this.ProductPriceLabel.Name = "ProductPriceLabel";
            this.ProductPriceLabel.Size = new System.Drawing.Size(43, 20);
            this.ProductPriceLabel.TabIndex = 6;
            this.ProductPriceLabel.Text = "price";
            this.ProductPriceLabel.Click += new System.EventHandler(this.ProductPriceLabel_Click);
            // 
            // ProductUnitLabel
            // 
            this.ProductUnitLabel.AutoSize = true;
            this.ProductUnitLabel.Location = new System.Drawing.Point(218, 149);
            this.ProductUnitLabel.Name = "ProductUnitLabel";
            this.ProductUnitLabel.Size = new System.Drawing.Size(119, 20);
            this.ProductUnitLabel.TabIndex = 7;
            this.ProductUnitLabel.Text = "number of units";
            this.ProductUnitLabel.Click += new System.EventHandler(this.ProductUnitLabel_Click);
            // 
            // ProductNameLabel
            // 
            this.ProductNameLabel.AutoSize = true;
            this.ProductNameLabel.Location = new System.Drawing.Point(218, 90);
            this.ProductNameLabel.Name = "ProductNameLabel";
            this.ProductNameLabel.Size = new System.Drawing.Size(49, 20);
            this.ProductNameLabel.TabIndex = 8;
            this.ProductNameLabel.Text = "name";
            this.ProductNameLabel.Click += new System.EventHandler(this.ProductNameLabel_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.RefreshProductsBtn);
            this.groupBox3.Controls.Add(this.ProductUnitLabel);
            this.groupBox3.Controls.Add(this.ProductNameLabel);
            this.groupBox3.Controls.Add(this.ProductPriceLabel);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.ProductIdFromUser);
            this.groupBox3.Controls.Add(this.ShowProductBtn);
            this.groupBox3.Location = new System.Drawing.Point(373, 40);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(356, 191);
            this.groupBox3.TabIndex = 9;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Q3 - products list:";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.ProductsAbovePriceBtn);
            this.groupBox4.Controls.Add(this.label3);
            this.groupBox4.Controls.Add(this.textBox2);
            this.groupBox4.Location = new System.Drawing.Point(373, 259);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(356, 201);
            this.groupBox4.TabIndex = 10;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Q4 - product list by price:";
            this.groupBox4.Enter += new System.EventHandler(this.groupBox4_Enter);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(25, 61);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 26);
            this.textBox2.TabIndex = 0;
            this.textBox2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(25, 39);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(101, 20);
            this.label3.TabIndex = 1;
            this.label3.Text = "enter a price:";
            // 
            // ProductsAbovePriceBtn
            // 
            this.ProductsAbovePriceBtn.Location = new System.Drawing.Point(22, 106);
            this.ProductsAbovePriceBtn.Name = "ProductsAbovePriceBtn";
            this.ProductsAbovePriceBtn.Size = new System.Drawing.Size(113, 59);
            this.ProductsAbovePriceBtn.TabIndex = 2;
            this.ProductsAbovePriceBtn.Text = "products above price";
            this.ProductsAbovePriceBtn.UseVisualStyleBackColor = true;
            this.ProductsAbovePriceBtn.Click += new System.EventHandler(this.ProductsAbovePriceBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(782, 482);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button CustomersBtn;
        private System.Windows.Forms.Button OrdersBtn;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox WorkerIdFromUser;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button WorkerBtn;
        private System.Windows.Forms.Button RefreshBtn;
        private System.Windows.Forms.Button RefreshProductsBtn;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox ProductIdFromUser;
        private System.Windows.Forms.Button ShowProductBtn;
        private System.Windows.Forms.Label ProductPriceLabel;
        private System.Windows.Forms.Label ProductUnitLabel;
        private System.Windows.Forms.Label ProductNameLabel;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button ProductsAbovePriceBtn;
    }
}

