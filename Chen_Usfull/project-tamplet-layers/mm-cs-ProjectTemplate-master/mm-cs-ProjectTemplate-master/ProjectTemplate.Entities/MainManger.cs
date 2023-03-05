using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectTemplate.Entities
{
    public class MainManager
    {

        private MainManager() {
           
        }
        private static readonly MainManager instance = new MainManager();
        public static MainManager Instance { get { return instance; } }

        public Students Students = new Students();
        public Books Books = new Books();
        public Teachers TeachersTeachers = new Teachers();

        public MyQueue MyQueue ;

        public void Init()
        {
            MyQueue = new MyQueue();
        }


    }
}
