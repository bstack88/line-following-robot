using System;
using System.Collections.Generic;
using System.Text;
using System.IO.Ports;
using System.Threading;

namespace BluetoothConfiger
{
    class BluetoothCommand
    {
        private SerialPort SerialPort, Com2;

        public byte Start = 0x02;
        public byte PacketType;
        public byte OpCode;
        public short DataLength;
        public byte Checksum;
        public byte[] Data;
        public byte EndByte = 0x03;

        public enum PacketTypeEnum { Request = 0x52, Confirm = 0x43, Indication = 0x69, Resposne = 0x72 };

        public BluetoothCommand()
        {
            SerialPort = new SerialPort("COM4", 115200, Parity.None, 8, StopBits.One);
            SerialPort.Open();

         //   Com2 = new SerialPort("COM5", 9600, Parity.None, 8, StopBits.One);
         //   Com2.Open();
                        
            Thread read = new Thread(new ThreadStart(ReadPort));
            read.IsBackground = true;
            read.Start();

            Send();
        }

        void ReadPort()
        {
            byte[] buf = new byte[7];
            int i = 0;
            while (true)
            {
                SerialPort.Read(buf, 0, 1);
                Console.Write("COM5: " + BitConverter.ToChar(buf, 0));
         //       Console.WriteLine("\n" + i++);
            }
        }

        
        public void Send()
        {
            SerialPort.BreakState = true;            
            Thread.Sleep(30);
            SerialPort.BreakState = false;


            Thread.Sleep(3);
            //SerialPort.Write(new byte[] { 0x02, 0x52, 0x07, 0x06, 0x00, 0x5F, 0x05, 0x06, 0x03, 0x00, 0x00, 0x00, 0x03 }, 0, 13);

           // SerialPort.Write(new byte[] { 0x02, 0x52, 0x23, 0x01, 0x00, 0x76, 0x07, 0x03 }, 0, 8);

            // enter transparent mode
            SerialPort.Write(new byte[]{0x02, 0x52 ,0x11 ,0x00 ,0x05 ,0x64 ,0x01 ,0x03 } ,0 ,8 );
 
            /*
            byte[] data = new byte[20];
            
            while(true)
            {
                SerialPort.Read(data, 0,1);
                Console.Write("COM5: " + BitConverter.ToChar(data, 0));

            }*/
            while (true) ;
        }
    }
}
