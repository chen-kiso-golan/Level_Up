using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CW17_WinFormsAppLink
{

    public partial class Form1 : Form
    {
        class Item
        {
            public int Id { get; set; }
            public string Name { get; set; }
        }

        System.Collections.Generic.Queue<Item> itemsQueue;

        public Form1()
        {
            InitializeComponent();
            itemsQueue = new System.Collections.Generic.Queue<Item>();
        }

    }
}
