using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Model
{
    public class M_NonProfitOrganization
    {
        public int Code { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Website_URL { get; set; }
        public string Image { get; set;}
        public DateTime Register_Time { get; set; }
    }
}
