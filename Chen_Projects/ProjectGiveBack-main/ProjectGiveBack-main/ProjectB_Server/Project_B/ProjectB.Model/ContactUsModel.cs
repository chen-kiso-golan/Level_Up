﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace ProjectB.Model
{
    public class ContactUsModel
    {
        public int Code { get; set; }
        public string Name { get; set; }
        public string Message { get; set; }
        public string Phone { get; set; }
        public string Email { get; set; }
        public DateTime date { get; set; }

    }
}
