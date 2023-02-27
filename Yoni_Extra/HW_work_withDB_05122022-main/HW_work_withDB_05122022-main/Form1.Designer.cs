namespace CW10_WorkingWithDB
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
            System.Windows.Forms.Button Show_Employees_data_by_id_btn;
            this.prodect_btn = new System.Windows.Forms.Button();
            this.customersCount_btn = new System.Windows.Forms.Button();
            this.textBox_product = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.Refresh_btn = new System.Windows.Forms.Button();
            this.textBox_employeesId = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label_UnitInStock = new System.Windows.Forms.Label();
            this.label_UnitPrice = new System.Windows.Forms.Label();
            this.textBox_productID = new System.Windows.Forms.TextBox();
            this.refresh_customers_btn = new System.Windows.Forms.Button();
            this.Show_Product_data_by_id_btn = new System.Windows.Forms.Button();
            this.textBox_for_check_price = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btn_for_check_how_meny_product = new System.Windows.Forms.Button();
            Show_Employees_data_by_id_btn = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // Show_Employees_data_by_id_btn
            // 
            Show_Employees_data_by_id_btn.Location = new System.Drawing.Point(16, 87);
            Show_Employees_data_by_id_btn.Name = "Show_Employees_data_by_id_btn";
            Show_Employees_data_by_id_btn.Size = new System.Drawing.Size(133, 44);
            Show_Employees_data_by_id_btn.TabIndex = 5;
            Show_Employees_data_by_id_btn.Text = "Show Employees data by id";
            Show_Employees_data_by_id_btn.UseVisualStyleBackColor = true;
            Show_Employees_data_by_id_btn.Click += new System.EventHandler(this.Show_Employees_data_by_id_btn);
            // 
            // prodect_btn
            // 
            this.prodect_btn.BackColor = System.Drawing.SystemColors.Info;
            this.prodect_btn.Location = new System.Drawing.Point(6, 61);
            this.prodect_btn.Name = "prodect_btn";
            this.prodect_btn.Size = new System.Drawing.Size(105, 30);
            this.prodect_btn.TabIndex = 0;
            this.prodect_btn.Text = "order count";
            this.prodect_btn.UseVisualStyleBackColor = false;
            this.prodect_btn.Click += new System.EventHandler(this.prodect_btn_Click);
            // 
            // customersCount_btn
            // 
            this.customersCount_btn.BackColor = System.Drawing.SystemColors.Info;
            this.customersCount_btn.Location = new System.Drawing.Point(6, 106);
            this.customersCount_btn.Name = "customersCount_btn";
            this.customersCount_btn.Size = new System.Drawing.Size(182, 44);
            this.customersCount_btn.TabIndex = 1;
            this.customersCount_btn.Text = "count_customers";
            this.customersCount_btn.UseVisualStyleBackColor = false;
            this.customersCount_btn.Click += new System.EventHandler(this.customersCount_btn_Click);
            // 
            // textBox_product
            // 
            this.textBox_product.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.textBox_product.Location = new System.Drawing.Point(117, 61);
            this.textBox_product.Name = "textBox_product";
            this.textBox_product.Size = new System.Drawing.Size(71, 30);
            this.textBox_product.TabIndex = 2;
            this.textBox_product.TextChanged += new System.EventHandler(this.textBox_product_TextChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.customersCount_btn);
            this.groupBox1.Controls.Add(this.textBox_product);
            this.groupBox1.Controls.Add(this.prodect_btn);
            this.groupBox1.Location = new System.Drawing.Point(553, 25);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(216, 168);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "groupBox_Q1-3 DB two butoon";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // Refresh_btn
            // 
            this.Refresh_btn.BackColor = System.Drawing.SystemColors.Info;
            this.Refresh_btn.Location = new System.Drawing.Point(16, 21);
            this.Refresh_btn.Name = "Refresh_btn";
            this.Refresh_btn.Size = new System.Drawing.Size(251, 46);
            this.Refresh_btn.TabIndex = 4;
            this.Refresh_btn.Text = "Refresh (Add to Hashtable)";
            this.Refresh_btn.UseVisualStyleBackColor = false;
            this.Refresh_btn.Click += new System.EventHandler(this.Refresh_btn_Click);
            // 
            // textBox_employeesId
            // 
            this.textBox_employeesId.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.textBox_employeesId.Location = new System.Drawing.Point(167, 97);
            this.textBox_employeesId.Name = "textBox_employeesId";
            this.textBox_employeesId.Size = new System.Drawing.Size(100, 34);
            this.textBox_employeesId.TabIndex = 7;
            this.textBox_employeesId.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.textBox_employeesId.TextChanged += new System.EventHandler(this.textBox_employeesId_TextChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.Refresh_btn);
            this.groupBox2.Controls.Add(this.textBox_employeesId);
            this.groupBox2.Controls.Add(Show_Employees_data_by_id_btn);
            this.groupBox2.Location = new System.Drawing.Point(484, 260);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(285, 150);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "groupBo_Q1-4 employees List";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.btn_for_check_how_meny_product);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.textBox_for_check_price);
            this.groupBox3.Controls.Add(this.Show_Product_data_by_id_btn);
            this.groupBox3.Controls.Add(this.label_UnitInStock);
            this.groupBox3.Controls.Add(this.label_UnitPrice);
            this.groupBox3.Controls.Add(this.textBox_productID);
            this.groupBox3.Controls.Add(this.refresh_customers_btn);
            this.groupBox3.Location = new System.Drawing.Point(39, 25);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(413, 181);
            this.groupBox3.TabIndex = 9;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "groupBox_Q1-8 customers Detail";
            // 
            // label_UnitInStock
            // 
            this.label_UnitInStock.AutoSize = true;
            this.label_UnitInStock.Location = new System.Drawing.Point(98, 152);
            this.label_UnitInStock.Name = "label_UnitInStock";
            this.label_UnitInStock.Size = new System.Drawing.Size(74, 16);
            this.label_UnitInStock.TabIndex = 4;
            this.label_UnitInStock.Text = "UnitInStock";
            this.label_UnitInStock.Click += new System.EventHandler(this.label_UnitInStock_Click);
            // 
            // label_UnitPrice
            // 
            this.label_UnitPrice.AutoSize = true;
            this.label_UnitPrice.Location = new System.Drawing.Point(21, 152);
            this.label_UnitPrice.Name = "label_UnitPrice";
            this.label_UnitPrice.Size = new System.Drawing.Size(61, 16);
            this.label_UnitPrice.TabIndex = 3;
            this.label_UnitPrice.Text = "UnitPrice";
            this.label_UnitPrice.Click += new System.EventHandler(this.label_UnitPrice_Click);
            // 
            // textBox_productID
            // 
            this.textBox_productID.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.textBox_productID.Location = new System.Drawing.Point(129, 101);
            this.textBox_productID.Name = "textBox_productID";
            this.textBox_productID.Size = new System.Drawing.Size(100, 34);
            this.textBox_productID.TabIndex = 1;
            this.textBox_productID.TextChanged += new System.EventHandler(this.textBox_productID_TextChanged);
            // 
            // refresh_customers_btn
            // 
            this.refresh_customers_btn.BackColor = System.Drawing.Color.NavajoWhite;
            this.refresh_customers_btn.Location = new System.Drawing.Point(6, 40);
            this.refresh_customers_btn.Name = "refresh_customers_btn";
            this.refresh_customers_btn.Size = new System.Drawing.Size(223, 48);
            this.refresh_customers_btn.TabIndex = 0;
            this.refresh_customers_btn.Text = "Refresh (Lode Product List)";
            this.refresh_customers_btn.UseVisualStyleBackColor = false;
            this.refresh_customers_btn.Click += new System.EventHandler(this.refresh_customers_btn_Click);
            // 
            // Show_Product_data_by_id_btn
            // 
            this.Show_Product_data_by_id_btn.BackColor = System.Drawing.Color.Moccasin;
            this.Show_Product_data_by_id_btn.Location = new System.Drawing.Point(6, 94);
            this.Show_Product_data_by_id_btn.Name = "Show_Product_data_by_id_btn";
            this.Show_Product_data_by_id_btn.Size = new System.Drawing.Size(117, 48);
            this.Show_Product_data_by_id_btn.TabIndex = 5;
            this.Show_Product_data_by_id_btn.Text = "Show Product data by id";
            this.Show_Product_data_by_id_btn.UseVisualStyleBackColor = false;
            this.Show_Product_data_by_id_btn.Click += new System.EventHandler(this.Show_Product_data_by_id_btn_Click);
            // 
            // textBox_for_check_price
            // 
            this.textBox_for_check_price.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.textBox_for_check_price.Location = new System.Drawing.Point(270, 142);
            this.textBox_for_check_price.Name = "textBox_for_check_price";
            this.textBox_for_check_price.Size = new System.Drawing.Size(56, 26);
            this.textBox_for_check_price.TabIndex = 6;
            this.textBox_for_check_price.TextChanged += new System.EventHandler(this.textBox_for_check_price_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label1.Location = new System.Drawing.Point(267, 119);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(99, 16);
            this.label1.TabIndex = 7;
            this.label1.Text = "Enter a price:";
            // 
            // btn_for_check_how_meny_product
            // 
            this.btn_for_check_how_meny_product.BackColor = System.Drawing.Color.OliveDrab;
            this.btn_for_check_how_meny_product.Location = new System.Drawing.Point(266, 61);
            this.btn_for_check_how_meny_product.Name = "btn_for_check_how_meny_product";
            this.btn_for_check_how_meny_product.Size = new System.Drawing.Size(118, 48);
            this.btn_for_check_how_meny_product.TabIndex = 8;
            this.btn_for_check_how_meny_product.Text = "Show Product by the min Price";
            this.btn_for_check_how_meny_product.UseVisualStyleBackColor = false;
            this.btn_for_check_how_meny_product.Click += new System.EventHandler(this.btn_for_check_how_meny_product_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Menu;
            this.ClientSize = new System.Drawing.Size(800, 450);
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
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button prodect_btn;
        private System.Windows.Forms.Button customersCount_btn;
        private System.Windows.Forms.TextBox textBox_product;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button Refresh_btn;
        private System.Windows.Forms.TextBox textBox_employeesId;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox textBox_productID;
        private System.Windows.Forms.Button refresh_customers_btn;
        private System.Windows.Forms.Label label_UnitInStock;
        private System.Windows.Forms.Label label_UnitPrice;
        private System.Windows.Forms.Button Show_Product_data_by_id_btn;
        private System.Windows.Forms.Button btn_for_check_how_meny_product;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox_for_check_price;
    }
}

