using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Windows;
using System.IO.Ports;
using System.Threading;
using System.Timers;
using ZedGraph;
using ZedGraph.Web;


namespace LineDebugger
{
    public partial class LineDebugger : Form
    {
        // Other forms
        Sensors SensorForm;
        Accelerometer AccForm;
        Speed SpeedForm;
        FixedPointConverter FixedPointForm;

        #region Variables

        private static int DEBUG_MSG_TIME = 180;
        private static int UPDATE_TIME = 200;

        public DebugPort DebugPort;
        
        private System.Timers.Timer MsgTimer = new System.Timers.Timer(DEBUG_MSG_TIME);
        private System.Timers.Timer UpdateTimer = new System.Timers.Timer(UPDATE_TIME);
        

        

        private int[] CurrentSensorData = new int[8];
        private BarItem[] BarItemSensors = new BarItem[8];

        #endregion

        public LineDebugger()
        {
           
            InitializeComponent();

            // Initialize all other windows
            SensorForm = new Sensors(ref DebugPort);
            AccForm = new Accelerometer();
            SpeedForm = new Speed(ref DebugPort);

            cbComPort.Items.AddRange(SerialPort.GetPortNames());
        }

        


        #region Utility
        
        private void OpenPort(object sender, EventArgs e)
        {
            if (DebugPort != null && DebugPort.IsOpen)
            {
                DebugPort.Close();
                MsgTimer.Enabled = false;
                UpdateTimer.Enabled = false;

                bOpenPort.Text = "Open";
                bStartDebug.Text = "Start Debugging";
                return;
            }

            DebugPort = new DebugPort(cbComPort.SelectedItem.ToString());
            

            // Start the timer to ensure a message is sent every X ms
            MsgTimer.Elapsed += new ElapsedEventHandler(CheckAlive);
            MsgTimer.Enabled = true;
            MsgTimer.Start();

            bOpenPort.Text = "Close";
            
            DebugPort.Write(new Command(CommandType.Request,10,0,null));
            Command c = DebugPort.Read();

            if (c.Data != null && c.Data.Length > 0 && c.Data[0] == 1)
                SpeedForm.SetDiagChecked(true, c.Data[1]);
            else
                SpeedForm.SetDiagChecked(false);

        }

        private void UpdateAll(object sender, ElapsedEventArgs e)
        {
            Console.WriteLine("here");

            Command c = new Command(CommandType.Request, 7, 0, null);
            c = DebugPort.WriteRead(c);
            //c = DebugPort.Read();


            SpeedForm.Update(c);            
            SensorForm.Update(c);
                       
            AccForm.AddData(c.Data[16], c.Data[17], c.Data[18]);
        }

        private void CheckAlive(object source, ElapsedEventArgs e)
        {
            if (DebugPort.MsgSent == true)
            {
                DebugPort.MsgSent = false;
                return;
            }
            else
            {
                // Send the alive command
                Command c = new Command(CommandType.Ack, 5, 0, null);
                DebugPort.Write(c);
            }
        }

         

        #endregion


        #region Form Event Handlers

        private void bStartDebug_Click(object sender, EventArgs e)
        {
            if (UpdateTimer.Enabled == true)
            {
                UpdateTimer.Enabled = false;
                bStartDebug.Text = "Start Debugging";
                return;
            }
            else
            {
                bStartDebug.Text = "Stop";
                // Start the update timer to automatically update all fields periodically
                UpdateTimer.Elapsed += new ElapsedEventHandler(UpdateAll);
                UpdateTimer.Enabled = true;
                UpdateTimer.Start();
            }
        }

        

        

        private void LineDebugger_FormClosed(object sender, FormClosedEventArgs e)
        {
            if(DebugPort != null && DebugPort.IsOpen)
                DebugPort.Close();
        }

        #region MenuBarActions
        private void accelerationToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (AccForm != null)
                AccForm.Dispose();

            AccForm = new Accelerometer();
            AccForm.MdiParent = this;
            AccForm.Show();
        }

        private void sensorsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (SensorForm != null)
                SensorForm.Dispose();

            SensorForm = new Sensors(ref DebugPort);
            SensorForm.MdiParent = this;
            SensorForm.Show();
        }
        #endregion

        private void cbDiagMode_CheckedChanged(object sender, EventArgs e)
        {
            byte[] dOut = new byte[2];
            dOut[0] = BitConverter.GetBytes(SpeedForm.GetDiagChecked())[0];
            dOut[1] = (byte)(BitConverter.GetBytes(SpeedForm.GetAutoStopTime())[0] + 1);
            Array.Reverse(dOut);

            Command c = new Command(CommandType.Set, 9, 2, dOut);
            DebugPort.Write(c);
        }
                
        #endregion        

        private void speedAndTurningToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (SpeedForm != null)
                SpeedForm.Dispose();

            SpeedForm = new Speed(ref DebugPort);
            SpeedForm.MdiParent = this;
            SpeedForm.Show();
        }

        private void fixedPointConverterToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (FixedPointForm != null)
                FixedPointForm.Dispose();

            FixedPointForm = new FixedPointConverter();
            FixedPointForm.Show();
        }

     }

}
