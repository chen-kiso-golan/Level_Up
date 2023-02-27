using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace ProjectB.Model
{
    public class SocialActivistModel
    {
        public int Code { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Address { get; set; }
        public string PhoneNumber { get; set; }
        public decimal Money { get; set; }
        public string Image { get; set; }
        public string Twitter_Name { get; set; }    
    }
}

