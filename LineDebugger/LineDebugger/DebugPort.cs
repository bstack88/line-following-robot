using System;
using System.Collections.Generic;
using System.Text;
using System.IO.Ports;

namespace LineDebugger
{
    public class DebugPort : SerialPort
    {
        public bool MsgSent = false;

        public DebugPort(string portName)
        {
            BaudRate = 115200;
            PortName = portName;
            Open();

            ReadTimeout = 200;
        }

        public Command WriteRead(Command c)
        {
            lock (this)
            {
                Write(c);
                return Read();
            }
        }


        public void Write(Command command)
        {
            lock(this)
            {
                byte[] cmd = command.GetBytes();
                Array.Reverse(cmd, 4, command.DataBytes);
                Write(cmd, 0, cmd.Length);
                MsgSent = true;
                this.DiscardInBuffer();
            }
        }

        public Command Read()
        {
            lock (this)
            {                
                Command c = new Command();

                try
                {

                    byte[] buf = new byte[1];

                    // wait for the preamble
                    while (buf[0] != 0xAA)
                    {
                        Read(buf, 0, 1);
                        Console.WriteLine(1);
                    }

                    // read the command type
                    Read(buf, 0, 1);
                    c.Type = (CommandType)buf[0];
                    Console.WriteLine(2);

                    // read the command number
                    Read(buf, 0, 1);
                    c.Number = buf[0];
                    Console.WriteLine(3);

                    // read data byte count
                    Read(buf, 0, 1);
                    c.DataBytes = buf[0];
                    Console.WriteLine(4);

                    // read until all data bytes are read
                    int dbRead = 0;
                    c.Data = new byte[c.DataBytes];


                    while (dbRead < c.DataBytes)
                    {
                        Read(buf, 0, 1);
                        c.Data[dbRead++] = buf[0];
                        Console.WriteLine(5);
                    }

                    buf = new byte[1];
                    Read(buf, 0, 1);
                    c.Checksum = buf[0];

                    buf[0] = 0x00;
                    // wait for end of command
                    while (buf[0] != 0xAF)
                    {
                        Read(buf, 0, 1);
                        Console.WriteLine(6);
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.StackTrace);
                }

                return c;
            }
        }
    }
}
