namespace CW12_Shbat_host_guest
{
    partial class frmCategory
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
            this.lalGuestsName = new System.Windows.Forms.Label();
            this.lalCategory = new System.Windows.Forms.Label();
            this.btn_AddFood = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.btn_confirm = new System.Windows.Forms.Button();
            this.dataGridView_CurrentGuestChoies = new System.Windows.Forms.DataGridView();
            this.dataGridView_AllGuestChoies = new System.Windows.Forms.DataGridView();
            this.splitter1 = new System.Windows.Forms.Splitter();
            this.splitter2 = new System.Windows.Forms.Splitter();
            this.btn_Beck_category = new System.Windows.Forms.Button();
            this.btn_next_category = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_CurrentGuestChoies)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_AllGuestChoies)).BeginInit();
            this.SuspendLayout();
            // 
            // lalGuestsName
            // 
            this.lalGuestsName.AutoSize = true;
            this.lalGuestsName.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.lalGuestsName.Location = new System.Drawing.Point(430, 18);
            this.lalGuestsName.Name = "lalGuestsName";
            this.lalGuestsName.Size = new System.Drawing.Size(97, 25);
            this.lalGuestsName.TabIndex = 0;
            this.lalGuestsName.Text = "שם האורח";
            this.lalGuestsName.Click += new System.EventHandler(this.lalGuestsName_Click);
            // 
            // lalCategory
            // 
            this.lalCategory.AutoSize = true;
            this.lalCategory.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.lalCategory.Location = new System.Drawing.Point(212, 17);
            this.lalCategory.Name = "lalCategory";
            this.lalCategory.Size = new System.Drawing.Size(113, 25);
            this.lalCategory.TabIndex = 1;
            this.lalCategory.Text = "שם קטגוריה";
            this.lalCategory.Click += new System.EventHandler(this.lalCategory_Click);
            // 
            // btn_AddFood
            // 
            this.btn_AddFood.BackColor = System.Drawing.Color.Coral;
            this.btn_AddFood.Location = new System.Drawing.Point(477, 296);
            this.btn_AddFood.Name = "btn_AddFood";
            this.btn_AddFood.Size = new System.Drawing.Size(114, 37);
            this.btn_AddFood.TabIndex = 2;
            this.btn_AddFood.Text = "הוספת מאכל";
            this.btn_AddFood.UseVisualStyleBackColor = false;
            this.btn_AddFood.Click += new System.EventHandler(this.btn_AddFood_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(327, 303);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 22);
            this.textBox1.TabIndex = 3;
            this.textBox1.Visible = false;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // btn_confirm
            // 
            this.btn_confirm.Location = new System.Drawing.Point(181, 296);
            this.btn_confirm.Name = "btn_confirm";
            this.btn_confirm.Size = new System.Drawing.Size(102, 37);
            this.btn_confirm.TabIndex = 4;
            this.btn_confirm.Text = "אישור";
            this.btn_confirm.UseVisualStyleBackColor = true;
            this.btn_confirm.Visible = false;
            this.btn_confirm.Click += new System.EventHandler(this.btn_confirm_Click);
            // 
            // dataGridView_CurrentGuestChoies
            // 
            this.dataGridView_CurrentGuestChoies.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView_CurrentGuestChoies.Location = new System.Drawing.Point(140, 339);
            this.dataGridView_CurrentGuestChoies.Name = "dataGridView_CurrentGuestChoies";
            this.dataGridView_CurrentGuestChoies.RowHeadersWidth = 51;
            this.dataGridView_CurrentGuestChoies.RowTemplate.Height = 24;
            this.dataGridView_CurrentGuestChoies.Size = new System.Drawing.Size(495, 116);
            this.dataGridView_CurrentGuestChoies.TabIndex = 6;
            this.dataGridView_CurrentGuestChoies.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_CurrentGuestChoies_CellContentClick);
            // 
            // dataGridView_AllGuestChoies
            // 
            this.dataGridView_AllGuestChoies.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView_AllGuestChoies.Location = new System.Drawing.Point(140, 55);
            this.dataGridView_AllGuestChoies.Name = "dataGridView_AllGuestChoies";
            this.dataGridView_AllGuestChoies.RowHeadersWidth = 51;
            this.dataGridView_AllGuestChoies.RowTemplate.Height = 24;
            this.dataGridView_AllGuestChoies.Size = new System.Drawing.Size(495, 235);
            this.dataGridView_AllGuestChoies.TabIndex = 7;
            this.dataGridView_AllGuestChoies.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_AllGuestChoies_CellDoubleClick);
            // 
            // splitter1
            // 
            this.splitter1.Location = new System.Drawing.Point(0, 0);
            this.splitter1.Name = "splitter1";
            this.splitter1.Size = new System.Drawing.Size(3, 537);
            this.splitter1.TabIndex = 8;
            this.splitter1.TabStop = false;
            // 
            // splitter2
            // 
            this.splitter2.Location = new System.Drawing.Point(3, 0);
            this.splitter2.Name = "splitter2";
            this.splitter2.Size = new System.Drawing.Size(3, 537);
            this.splitter2.TabIndex = 9;
            this.splitter2.TabStop = false;
            // 
            // btn_Beck_category
            // 
            this.btn_Beck_category.BackColor = System.Drawing.Color.DarkGray;
            this.btn_Beck_category.Location = new System.Drawing.Point(451, 475);
            this.btn_Beck_category.Name = "btn_Beck_category";
            this.btn_Beck_category.Size = new System.Drawing.Size(102, 33);
            this.btn_Beck_category.TabIndex = 10;
            this.btn_Beck_category.Text = ">>>>";
            this.btn_Beck_category.UseVisualStyleBackColor = false;
            this.btn_Beck_category.Click += new System.EventHandler(this.btn_Beck_category_Click);
            // 
            // btn_next_category
            // 
            this.btn_next_category.BackColor = System.Drawing.Color.DarkGray;
            this.btn_next_category.Location = new System.Drawing.Point(217, 475);
            this.btn_next_category.Name = "btn_next_category";
            this.btn_next_category.Size = new System.Drawing.Size(98, 33);
            this.btn_next_category.TabIndex = 11;
            this.btn_next_category.Text = "<<<<";
            this.btn_next_category.UseVisualStyleBackColor = false;
            this.btn_next_category.Click += new System.EventHandler(this.btn_next_category_Click);
            // 
            // frmCategory
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Cornsilk;
            this.ClientSize = new System.Drawing.Size(749, 537);
            this.Controls.Add(this.btn_next_category);
            this.Controls.Add(this.btn_Beck_category);
            this.Controls.Add(this.splitter2);
            this.Controls.Add(this.splitter1);
            this.Controls.Add(this.dataGridView_AllGuestChoies);
            this.Controls.Add(this.dataGridView_CurrentGuestChoies);
            this.Controls.Add(this.btn_confirm);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.btn_AddFood);
            this.Controls.Add(this.lalCategory);
            this.Controls.Add(this.lalGuestsName);
            this.Name = "frmCategory";
            this.Text = "frmCategory";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_CurrentGuestChoies)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_AllGuestChoies)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lalGuestsName;
        private System.Windows.Forms.Label lalCategory;
        private System.Windows.Forms.Button btn_AddFood;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button btn_confirm;
        private System.Windows.Forms.DataGridView dataGridView_CurrentGuestChoies;
        private System.Windows.Forms.DataGridView dataGridView_AllGuestChoies;
        private System.Windows.Forms.Splitter splitter1;
        private System.Windows.Forms.Splitter splitter2;
        private System.Windows.Forms.Button btn_Beck_category;
        private System.Windows.Forms.Button btn_next_category;
    }
}