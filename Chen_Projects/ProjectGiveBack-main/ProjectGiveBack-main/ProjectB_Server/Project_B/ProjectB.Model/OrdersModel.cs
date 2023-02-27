﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectB.Model
{
    public class OrdersModel
    {
        public int Code { get; set; }
        public int? SA_code { get; set; }
        public int BC_code { get; set; }
        public int Campaign_code { get; set; }
        public int Product_code { get; set; }
        public DateTime Order_Time { get; set; }
        public bool Is_Sent { get; set; }

    }
}

