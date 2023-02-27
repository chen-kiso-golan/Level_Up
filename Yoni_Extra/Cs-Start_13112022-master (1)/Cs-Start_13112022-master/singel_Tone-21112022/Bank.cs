using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace singel_Tone_21112022
{
    public class Bank
    {
        private readonly string _bankId;
        private readonly string _branchId;
        public string bankId
        {
            get { return _bankId; }
        }
        public string branchId
        {
            get { return _branchId; }
        }
        public string bankName { get; set; }
        public string adress { get; set; }
        public string city { get; set; }
        public string phoneNumber { get; set; }

        public Bank(string bankId, string branchId)
        {
            this._bankId = bankId;
            this._branchId = branchId;
        }
    }
}
