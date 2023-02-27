using ProjectStudent.Model;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectStudent.Entities
{
    public class MainManager
    {
        private MainManager() { }

        private static readonly MainManager instance = new MainManager(); 
        public static MainManager Instance { get { return instance; } }

       public Hashtable hashtableStudent = new Hashtable();

       





        public EStudents students = new EStudents();
        public EBook Books= new EBook();
        public ETecher Techer = new ETecher();
    }
}
