using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace ProjectB.Model
{
    public class NonProfitOrganizationModel
    {
        public int Code { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Website_URL { get; set; }
        public string Image { get; set; }

    }
}
