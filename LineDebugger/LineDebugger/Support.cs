using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace LineDebugger
{
    public static class Support
    {
        public delegate void UpdateTextCallback(TextBox tb, string text);
        public delegate void UpdateLabelCallback(System.Windows.Forms.Label label, string text);

        #region Callbacks
        /// <summary>
        /// Updates text in a textbox
        /// </summary>
        /// <param name="tb"></param>
        /// <param name="text"></param>
        private static void UpdateText(TextBox tb, string text)
        {
            if (text != null)
                tb.Text = text;
        }

        /// <summary>
        /// Callback to update text from a thread
        /// </summary>
        /// <param name="tb"></param>
        /// <param name="text"></param>
        public static void UpdateTextFromThread(TextBox tb, string text)
        {
            tb.Invoke(new UpdateTextCallback(UpdateText), new object[] { tb, text });
        }

        /// <summary>
        /// Updates text in a label
        /// </summary>
        /// <param name="label"></param>
        /// <param name="text"></param>
        private static void UpdateLabel(System.Windows.Forms.Label label, string text)
        {
            if (text != null)
                label.Text = text;
        }

        /// <summary>
        /// Callback to update a label from a thread
        /// </summary>
        /// <param name="label"></param>
        /// <param name="text"></param>
        public static void UpdateLabelFromThread(System.Windows.Forms.Label label, string text)
        {
            label.Invoke(new UpdateLabelCallback(UpdateLabel), new object[] { label, text });
        }
        /// <summary>
        /// Callback to update a label from a thread
        /// </summary>
        /// <param name="label"></param>
        /// <param name="data"></param>
        public static void UpdateLabelFromThread(System.Windows.Forms.Label label, byte data)
        {
            string text = BitConverter.ToInt16(new byte[] { data, 0x00 }, 0).ToString();
            label.Invoke(new UpdateLabelCallback(UpdateLabel), new object[] { label, text });
        }
        #endregion

        /// <summary>
        /// Converts an integer array to a double array
        /// </summary>
        /// <param name="dIn"></param>
        /// <returns></returns>
        public static double[] ConvertToDouble(int[] dIn)
        {
            if (dIn == null)
                return null;

            double[] dOut = new double[dIn.Length];

            for (int i = 0; i < dIn.Length; i++)
                dOut[i] = (double)dIn[i];
            return dOut;
        }

        /// <summary>
        /// Converts a byte from a Command to a string
        /// </summary>
        /// <param name="c">Command containing data</param>
        /// <param name="pos">Position in data to convert</param>
        /// <returns>String representation of byte</returns>
        public static string GetStringFromByte(ref Command c, int pos)
        {
            try
            {
                return (c.Data[pos]).ToString();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
                return null;
            }
        }

        /// <summary>
        /// Converts a word from a Command to a string
        /// </summary>
        /// <param name="c">Command containing data</param>
        /// <param name="start">Position in data to convert</param>
        /// <returns>String representation of word</returns>
        public static string GetStringFromUnsignedWord(ref Command c, int start)
        {
            try
            {

                return (c.Data[start] << 8 | c.Data[start + 1]).ToString();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
                return null;
            }
        }

        /// <summary>
        /// Converts a word from a Command to a string
        /// </summary>
        /// <param name="c">Command containing data</param>
        /// <param name="start">Position in data to convert</param>
        /// <returns>String representation of word</returns>
        public static string GetStringFromSignedWord(ref Command c, int start)
        {
            try
            {
                sbyte[] d = new sbyte[] { (sbyte)c.Data[start], (sbyte)c.Data[start + 1] };
                /*
                if(c.Data[start] > 127)
                    c.Data[start] = (byte)(~c.Data[start]+1);
                if (c.Data[start+1] > 127)
                    c.Data[start+1] = (byte)(~c.Data[start+1] + 1);
                */

                int dO = (int)(d[0] << 8 | d[1]);
              //  if (c.Data[start] == 1)
              //      d *= -1;


                return dO.ToString();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
                return null;
            }
        }

        public static int GetIntFromSignedWord(ref Command c, int start)
        {
            try
            {
                sbyte[] d = new sbyte[] { (sbyte)c.Data[start], (sbyte)c.Data[start + 1] };


                int dO = 0 + (int)(d[0] << 8 | (byte)d[1]);
                //  if (c.Data[start] == 1)
                //      d *= -1;


                return dO;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
                return 0;
            }
        }
    }
}
