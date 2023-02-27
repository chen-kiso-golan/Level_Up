using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace properties_set_get
{
    internal class car
    {
        private int MaxCarName = 0;
        private int _km = 0;
        public int Km
        {
            get {return _km;}

            set
            {
                if (value < 0)
                {
                    _km = 0;
                }
                else
                {
                    _km = value;
                }
            }
        }

        private string _carName;
        public string CarName
        {
            get
            {
                return _carName;
            }

            set
            {
               if (MaxCarName < 3)
               {
                    _carName = value;
                    MaxCarName++;
               }
            }
        }

        private int _id = 2055;
        public int Id
        {
            get
            {
                return _id;
            }
        }

    }
}
