using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW_WinFormsApp_interface
{
    //---------------------------------interface-----------------------------
    internal interface IShape
    {
        public string ColorFrame();
        public int ThicknessFrame();

    }
    internal interface IApex
    {
        public int NumberOfApex();

    }
    internal interface IRall
    {
        public void RallShape();
    }
    //---------------------------------interface-----------------------------


    //---------------------------------Rectangle-----------------------------
    public class Rectangle : IShape,IApex
    {
       
        private int _sideWidth;
        public int SideWidth
        {
            get { return _sideWidth; }
            set { _sideWidth = value; }
        }


        private int _sideHeight;
        public int SideHeight
        {
            get { return _sideHeight; }
            set { _sideHeight = value; }
        }

      public string ColorFrame()
      {
            return "red";
      }
      public int ThicknessFrame()
      {
            return 4;
      }
      public int NumberOfApex() 
      {
            return 4;
      }
    }

    //---------------------------------Circle-----------------------------
    public class Circle : IShape, IRall
    {
       
        private int _radiusLength;

        public int RadiusLength
        {
            get { return _radiusLength; }
            set { _radiusLength = value; }
        }


        public string ColorFrame()
        {
            return "blue";
        }
        public int ThicknessFrame()
        {
            return 1;
        }
        public void RallShape()
        {
            Console.WriteLine("ralling the circle");
        }
    }
 

    //---------------------------------Ellipse-----------------------------

    public class Ellipse : IShape,IRall
    {
      
        
        private int _radiusLength2;

        public int RadiusLength2
        {
            get { return _radiusLength2; }
            set { _radiusLength2 = value; }
        }


        public string ColorFrame()
        {
            return "yellow";
        }
        public int ThicknessFrame()
        {
            return 1;
        }

        public void RallShape()
        {
            Console.WriteLine("ralling the circle");
        }
    }

    //---------------------------------Triangle-----------------------------
    public class Triangle: IShape,IApex
    {
      
        private int _triangleHeight;
        public int TriangleHeight
        {
            get { return _triangleHeight; }
            set { _triangleHeight = value; }
        }


        private int _triangleWidth;
        public int TriangleWidth
        {
            get { return _triangleWidth; }
            set { _triangleWidth = value; }
        }

        public string ColorFrame()
        {
            return "red";
        }
        public int ThicknessFrame()
        {
            return 3;
        }

        public int NumberOfApex()
        {
            return 3;
        }
    }



    //---------------------------------Moon-----------------------------
    public class Moon : IShape,IApex,IRall
    {
      
        private int _diameter_of_the_Moon;
        public int Diameter_of_the_Moon
        {
            get { return _diameter_of_the_Moon; }
            set { _diameter_of_the_Moon = value; }
        }


        public string ColorFrame()
        {
            return "white";
        }
        public int ThicknessFrame()
        {
            return 2;
        }

        public int NumberOfApex()
        {
            return 2;
        }
        public void RallShape()
        {
            Console.WriteLine("ralling the circle");
        }
    }
}
