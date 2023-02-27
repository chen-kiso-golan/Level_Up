namespace CW12_Shbat_host_guest
{
    partial class frm_host
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
            this.label1 = new System.Windows.Forms.Label();
            this.textBox_host = new System.Windows.Forms.TextBox();
            this.btn_host = new System.Windows.Forms.Button();
            this.listBox_host = new System.Windows.Forms.ListBox();
            this.DGV_SumOfOrder = new System.Windows.Forms.DataGridView();
            this.btn_SumOfOrder = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.DGV_SumOfOrder)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label1.Location = new System.Drawing.Point(409, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(174, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "מארח-הכנס קטגוריות";
            // 
            // textBox_host
            // 
            this.textBox_host.Location = new System.Drawing.Point(417, 72);
            this.textBox_host.Name = "textBox_host";
            this.textBox_host.Size = new System.Drawing.Size(136, 22);
            this.textBox_host.TabIndex = 1;
            this.textBox_host.TextChanged += new System.EventHandler(this.textBox_host_TextChanged);
            // 
            // btn_host
            // 
            this.btn_host.BackColor = System.Drawing.Color.DarkCyan;
            this.btn_host.Location = new System.Drawing.Point(417, 136);
            this.btn_host.Name = "btn_host";
            this.btn_host.Size = new System.Drawing.Size(136, 26);
            this.btn_host.TabIndex = 2;
            this.btn_host.Text = "הכנס";
            this.btn_host.UseVisualStyleBackColor = false;
            this.btn_host.Click += new System.EventHandler(this.btn_host_Click);
            // 
            // listBox_host
            // 
            this.listBox_host.FormattingEnabled = true;
            this.listBox_host.ItemHeight = 16;
            this.listBox_host.Location = new System.Drawing.Point(113, 30);
            this.listBox_host.Name = "listBox_host";
            this.listBox_host.Size = new System.Drawing.Size(250, 132);
            this.listBox_host.TabIndex = 3;
            this.listBox_host.SelectedIndexChanged += new System.EventHandler(this.listBox_host_SelectedIndexChanged);
            // 
            // DGV_SumOfOrder
            // 
            this.DGV_SumOfOrder.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DGV_SumOfOrder.Location = new System.Drawing.Point(113, 236);
            this.DGV_SumOfOrder.Name = "DGV_SumOfOrder";
            this.DGV_SumOfOrder.RowHeadersWidth = 51;
            this.DGV_SumOfOrder.RowTemplate.Height = 24;
            this.DGV_SumOfOrder.Size = new System.Drawing.Size(388, 202);
            this.DGV_SumOfOrder.TabIndex = 4;
            this.DGV_SumOfOrder.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.DGV_SumOfOrder_CellContentClick);
            // 
            // btn_SumOfOrder
            // 
            this.btn_SumOfOrder.BackColor = System.Drawing.Color.DarkCyan;
            this.btn_SumOfOrder.Location = new System.Drawing.Point(541, 326);
            this.btn_SumOfOrder.Name = "btn_SumOfOrder";
            this.btn_SumOfOrder.Size = new System.Drawing.Size(97, 40);
            this.btn_SumOfOrder.TabIndex = 5;
            this.btn_SumOfOrder.Text = "סיכום הזמנות";
            this.btn_SumOfOrder.UseVisualStyleBackColor = false;
            this.btn_SumOfOrder.Click += new System.EventHandler(this.btn_SumOfOrder_Click);
            // 
            // frm_host
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Cornsilk;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btn_SumOfOrder);
            this.Controls.Add(this.DGV_SumOfOrder);
            this.Controls.Add(this.listBox_host);
            this.Controls.Add(this.btn_host);
            this.Controls.Add(this.textBox_host);
            this.Controls.Add(this.label1);
            this.Name = "frm_host";
            this.Text = "frm_host";
            ((System.ComponentModel.ISupportInitialize)(this.DGV_SumOfOrder)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox_host;
        private System.Windows.Forms.Button btn_host;
        private System.Windows.Forms.ListBox listBox_host;
        private System.Windows.Forms.DataGridView DGV_SumOfOrder;
        private System.Windows.Forms.Button btn_SumOfOrder;
    }
}