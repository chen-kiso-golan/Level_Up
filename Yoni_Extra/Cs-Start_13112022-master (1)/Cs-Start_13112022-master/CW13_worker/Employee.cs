using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CW13_worker
{
    public class Employee
    {
        [Key]
        public int Code { get; set; }
        [Required]
        public string ID { get; set; }

        public string FirstName { get; set; }
        public string LastName { get; set; }

    }
}
