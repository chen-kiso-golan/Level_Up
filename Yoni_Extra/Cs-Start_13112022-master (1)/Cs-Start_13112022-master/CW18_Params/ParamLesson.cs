using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CW18_Params
{
    internal class ParamLesson
    {
        public void RunAnonymusClass()
        {
            var a = new { id = 12, name = "Avi" };
            string s = a.name;
        }


        public void Run()
        {
            RunParams(new ParamsTwitter() { name = "", description = "", id = 0 });

            RunParams1("hukhuk", "ghjkhkjh", "uihukhug", "");

            //RunParams2("jkhkjh","jhkjhk"); שגיאה!! מה שמיוחד בפארמס זה שניתן להעביר בו זמנית כמה משתנים
        }


        public void RunParams2(object[] list)
        {
            foreach (var item in list)
            {
                Console.WriteLine(item);
            }
        }

        public void RunParams1(params object[] list)
        {
            foreach (var item in list) 
            {
                Console.WriteLine(item);
            }
        }
        public void RunParams(object o)
        {

        }

        class ParamsTwitter
        {
            public int id;
            public string name;
            public string description;
        }

 



    }
}
