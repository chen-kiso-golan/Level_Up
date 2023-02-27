using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Model
{
    public class M_Tweets
    {
        public int Code { get; set; }
        public int SA_code { get; set; }
        public int Campaign_code { get; set;}
        public string HashTag { get; set; }
        public string Landing_Page_URL { get; set; }
        public string Tweet_Content { get; set; }
        public DateTime Tweet_Time { get; set; }
        public string Tweet_id { get; set; }
    }
}
