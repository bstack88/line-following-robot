using System;
using System.Collections.Generic;
using System.Text;

namespace LineDebugger
{
    class FixedPoint
    {
        public int IntSize, FracSize;
        private int IntPart, FracPart;
        public int Number;

        public FixedPoint()
        {
        }
        public FixedPoint(int intSize, int fracSize, float number)
        {
            IntSize = intSize;
            FracSize = fracSize;

            IntPart = ((int)Math.Floor(number)) << fracSize;
            FracPart = (int)((number - Math.Floor(number))*(Math.Pow(2,fracSize)));

            Number = IntPart | FracPart;
        }

        public float GetFloat(int intSize, int fracSize, int num)
        {
            IntSize = intSize;
            FracSize = fracSize;
            Number = num;

            

            int mask = 0;
            for (int i = 0; i < FracSize; i++)
                mask += (int)Math.Pow(2, i);

            IntPart = Number & ~mask;

            FracPart = (Number & mask);

            return GetFloat();
        }

        public float GetFloat()
        {
            float result;

            result = (float)((IntPart >> FracSize) + (FracPart / (Math.Pow(2, FracSize))));
            result = (float)Math.Round(result, 3);
            return result;
        }

        public byte[] GetNumber()
        {
            byte[] b = BitConverter.GetBytes(Number);
            return b;
        }

    }
}
