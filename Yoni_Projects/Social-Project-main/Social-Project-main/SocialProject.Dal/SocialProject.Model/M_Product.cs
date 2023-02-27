using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Model
{
    public class M_Product
    {
        public int Code { get; set; }
        public string Name { get; set; }
        public float Price { get; set; }
        public string Description { get; set; }
        public int Units_In_Stock { get; set; }
        public int BC_code { get; set; }
        public int Campaign_code { get; set; }
        public string Image { get; set; }
    }
}
