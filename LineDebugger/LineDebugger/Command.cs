using System;
using System.Collections.Generic;
using System.Text;

namespace LineDebugger
{
    public enum CommandType { Set = 0x00, Request = 0x01, Ack = 0x02 };

    public class Command
    {
        public CommandType Type;
        public int Number;
        public int DataBytes;
        public byte[] Data;
        public byte Checksum;

        public Command()
        {
        }
        public Command(CommandType type, int number, int dataBytes, byte[] data)
        {
            Type = type;
            Number = number;
            DataBytes = dataBytes;
            Data = data;
        }

        public byte[] GetBytes()
        {
            int dataSpot = 0;

            byte[] data;

            if (Data == null)
                data = new byte[6];
            else
                data = new byte[6 + Data.Length];

            // Set the preamble
            data[dataSpot++] = 0xAA;

            // Convert the type to bytes
            byte[] typeTemp;
            typeTemp = BitConverter.GetBytes((int)Type);
            data[dataSpot++] = typeTemp[0];

            // Convert Command Number to Bytes
            byte[] cmdTemp;
            cmdTemp = BitConverter.GetBytes(Number);
            data[dataSpot++] = cmdTemp[0];
            
            // Convert DataBytes to bytes
            byte[] dTemp;
            dTemp = BitConverter.GetBytes(DataBytes);
            data[dataSpot++] = dTemp[0];

            if(Data != null && Data.Length > 0)
                Array.Copy(Data, 0, data, dataSpot++, Data.Length);

            byte checksum = 0;
            // sum up all the data
            for (int i = 1; i < data.Length - 2; i++)
            {
                checksum += data[i];
            }

            data[data.Length - 2] = checksum;

            data[data.Length - 1] = 0xAF;

            return data;
        }
    }
}
