using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace ProjectB.Model
{
    public class CampaignsModel
    {
        public int Code { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Link_URL { get; set; }
        public string Hashtag { get; set; }
        public string Image { get; set; }
        public int NPO_code { get; set; }
        public bool Is_Active { get; set; }

    }
}


