using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Model
{
    public class M_Campaign
    {
        public int Code { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Description { get; set; }
        public string Landing_Page_URL { get; set; }
        public string HashTag { get; set; }
        public int NPO_code { get; set; }
        public string Image { get; set; }  
        public bool Is_Active { get; set; }    
    }
}
