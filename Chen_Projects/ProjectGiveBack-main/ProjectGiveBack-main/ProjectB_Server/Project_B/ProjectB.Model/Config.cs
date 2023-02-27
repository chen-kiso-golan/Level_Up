using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectB.Model
{
    public class Config
    {
        public int Code { set; get; }
        public string Auth0BearerCode { set; get; }
        public string TwitterBearerCode { set; get; }
        public string TwitterConsumerKey { set; get; }
        public string TwitterConsumerKeySecret { set; get; }
        public string TwitterAccessKey { set; get; }
        public string TwitterAccessKeySecret { set; get; }
    }
}
