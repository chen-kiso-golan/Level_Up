using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Model
{
    public class M_BusinessCompany
    {
        public int Code { get; set; }

        public string Name { get; set; }

        public string Email { get; set; }

        public string Image { get; set; }

        public DateTime Register_Time { get; set; }
    }
}
