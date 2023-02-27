using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace week_4_Winform_Interface2
{
    //------------------------------------interface:
    internal interface IShape
    {
        public string Color();
        public int FrameThickness();
    }

    internal interface IApex
    {
        public int ApexNumber();
    }

    internal interface IRoll
    {
        public void Roll();
    }


    //---------------------------------------class Rectangle:
    public class Rectangle : IShape, IApex 
    {
        private int _SideWidth;

        public int SideWidth
        {
            get { return _SideWidth; }
            set { _SideWidth = value; }
        }

        private int _SideHeight;

        public int SideHeight
        {
            get { return _SideHeight; }
            set { _SideHeight = value; }
        }
      
        public string Color()
        {
            return "red";
        }

        public int FrameThickness()
        {
            return 10;
        }

        public int ApexNumber()
        {
            return 4;   
        }

    }

    //-----------------------------------class circle:
    public class Circle : IShape, IRoll
    {
        private int _RadiusLength;

        public int RadiusLength
        {
            get { return _RadiusLength; }
            set { _RadiusLength = value; }
        }
        public string Color()
        {
            return "blue";
        }

        public int FrameThickness()
        {
            return 7;
        }

        public void Roll()
        {
            Console.WriteLine("rolling the circle");
        }
    }

    //---------------------------------------class ellipse:
    public class Ellipse : IShape, IRoll
    {
        private int _RadiusLength2;

        public int RadiusLength2
        {
            get { return _RadiusLength2; }
            set { _RadiusLength2 = value; }
        }

        public string Color()
        {
            return "green";
        }

        public int FrameThickness()
        {
            return 11;
        }

        public void Roll()
        {
            Console.WriteLine("rolling the ellipse");
        }
    }

    //-----------------------------------class triangle:
    public class Triangle : IShape, IApex
    {
        private int _TriangleHight;

        public int TriangleHight
        {
            get { return _TriangleHight; }
            set { _TriangleHight = value; }
        }

        private int _BaseWidth;

        public int BaseWidth
        {
            get { return _BaseWidth; }
            set { _BaseWidth = value; }
        }

        public string Color()
        {
            return "black";
        }

        public int FrameThickness()
        {
            return 6;
        }

        public int ApexNumber()
        {
            return 3;
        }
    }

    //----------------------------------------class moon:
    public class Moon : IShape, IApex, IRoll
    {
        private int _MoonDiameter;

        public int MoonDiameter
        {
            get { return _MoonDiameter; }
            set { _MoonDiameter = value; }
        }

        public string Color()
        {
            return "yellow";
        }

        public int FrameThickness()
        {
            return 9;
        }

        public int ApexNumber()
        {
            return 2;
        }

        public void Roll()
        {
            Console.WriteLine("rolling the moon");
        }
    }

  

}
