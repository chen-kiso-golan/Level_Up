using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Model
{
    public class M_Register_Applications
    {
        public int Code { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Role_Request { get; set; }
        public bool Is_Aproved { get; set; }
    }
}
