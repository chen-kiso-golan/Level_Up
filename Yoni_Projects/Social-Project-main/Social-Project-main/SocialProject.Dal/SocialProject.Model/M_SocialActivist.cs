using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Model
{
    public class M_SocialActivist
    {
        public int Code { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Email { get; set; }
        public string Address { get; set; }
        public string Phone_Number { get; set; }
        public decimal Money_Status { get; set; }
        public string Image { get; set; }
        public DateTime Register_Time { get; set; }

        public string Twitter_Name { get; set; }
    }
}
