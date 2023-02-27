using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectB.Model
{
    public class TweetsModel
    {
        public int Code { get; set; }
        public string Hashtag { get; set; }
        public string Link_URL { get; set; }
        public string Tweet_Content { get; set; }
        public DateTime Tweet_Time { get; set; }
        public int SA_code { get; set; }
        public int Campaign_code { get; set; }
        public string Tweet_id { get; set; }
       
    }
}
