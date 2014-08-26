using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using ZedGraph;

namespace LineDebugger
{
    public partial class Sensors : Form
    {
        private int[] CurrentSensorData = {0,1,2,3,4,5,6,7};
        private DebugPort DebugPort;

        private const int COEFFICIENT_SCALE = 10;
        private const int SENSOR_SCALE      = 7;
        private const int ERROR_SCALE       = 7;

        public Sensors(ref DebugPort debugPort)
        {
            InitializeComponent();

            DebugPort = debugPort;
            InitZed();
        }

        private void InitZed()
        {
            UpdateGraph();

            SetSize();
        }

        private void UpdateGraph()
        {
            GraphPane pane = zgSensorsCurrent.GraphPane;
            pane.Title.Text = "Sensor Current Value";
            pane.XAxis.Title.Text = "Sensor";
            pane.YAxis.Title.Text = "Value";

            pane.CurveList.Clear();


            BarItem bar = pane.AddBar(null, null, Support.ConvertToDouble(CurrentSensorData), Color.Black);
            bar.Bar.Fill = new Fill(Color.Blue);

            pane.XAxis.MajorTic.IsBetweenLabels = true;
            pane.XAxis.Scale.TextLabels = new string[] { "0", "1", "2", "3", "4", "5", "6", "7" };
            pane.XAxis.Type = AxisType.Text;

            pane.YAxis.Scale.Min = 0;
            pane.YAxis.Scale.Max = 255;

            zgSensorsCurrent.AxisChange();
            zgSensorsCurrent.Invalidate();
        }

        private void SetSize()
        {
            zgSensorsCurrent.Location = new Point(193, 43);
            zgSensorsCurrent.Size = new Size(ClientRectangle.Width - 20 - 193, ClientRectangle.Height - 20 - 43);
        }

        public void Update(Command c)
        {

            for (int i = 0; i < 8; i++)
            {
                CurrentSensorData[i] = BitConverter.ToInt16(new byte[] { c.Data[i + 8], 0x00 }, 0);
            }
            

            Support.UpdateLabelFromThread(lSensor0, CurrentSensorData[0].ToString());
            Support.UpdateLabelFromThread(lSensor1, CurrentSensorData[1].ToString());
            Support.UpdateLabelFromThread(lSensor2, CurrentSensorData[2].ToString());
            Support.UpdateLabelFromThread(lSensor3, CurrentSensorData[3].ToString());
            Support.UpdateLabelFromThread(lSensor4, CurrentSensorData[4].ToString());
            Support.UpdateLabelFromThread(lSensor5, CurrentSensorData[5].ToString());
            Support.UpdateLabelFromThread(lSensor6, CurrentSensorData[6].ToString());
            Support.UpdateLabelFromThread(lSensor7, CurrentSensorData[7].ToString());

            FixedPoint f = new FixedPoint();
            float d = f.GetFloat(8, 7, Support.GetIntFromSignedWord(ref c, 20));
            Support.UpdateLabelFromThread(lPIDValue, d.ToString());

            UpdateGraph();
        }

        private void Sensors_Resize(object sender, EventArgs e)
        {
            SetSize();
        }

        private void SendSensorWeight()
        {
            
            if (Updating == true)
                return;

            int[] sensorWeight = new int[8];

            float d;

            FixedPoint f;

            float.TryParse(tbSensorWeight0.Text, out d);
            f = new FixedPoint(8, 7, d);
            sensorWeight[0] = f.Number;

            float.TryParse(tbSensorWeight1.Text, out  d);
            f = new FixedPoint(8, 7, d);
            sensorWeight[1] = f.Number;

            float.TryParse(tbSensorWeight2.Text, out  d);
            f = new FixedPoint(8, 7, d);
            sensorWeight[2] = f.Number;

            float.TryParse(tbSensorWeight3.Text, out  d);
            f = new FixedPoint(8, 7, d);
            sensorWeight[3] = f.Number;

            float.TryParse(tbSensorWeight4.Text, out  d);
            f = new FixedPoint(8, 7, d);
            sensorWeight[4] = f.Number;

            float.TryParse(tbSensorWeight5.Text, out  d);
            f = new FixedPoint(8, 7, d);
            sensorWeight[5] = f.Number;

            float.TryParse(tbSensorWeight6.Text, out  d);
            f = new FixedPoint(8, 7, d);
            sensorWeight[6] = f.Number;

            float.TryParse(tbSensorWeight7.Text, out  d);
            f = new FixedPoint(8, 7, d);
            sensorWeight[7] = f.Number;

            Command c = new Command();
            c.Type = CommandType.Set;
            c.Number = 13;
            c.DataBytes = 16;

            byte[] data = new byte[16];

            for (int i = 0; i < 8; i++)
            {
                byte[] res = BitConverter.GetBytes(sensorWeight[i]);

                data[i*2] = res[1];
                data[(i*2 + 1)] = res[0];
            }
            Array.Reverse(data);
            c.Data = data;

            DebugPort.Write(c);
             
            
        }

        #region Sensor Weight Change
        private void tbSensorWeight0_TextChanged(object sender, EventArgs e)
        {
            SendSensorWeight();
        }

        private void tbSensorWeight1_TextChanged(object sender, EventArgs e)
        {
            SendSensorWeight();
        }

        private void tbSensorWeight2_TextChanged(object sender, EventArgs e)
        {
            SendSensorWeight();
        }

        private void tbSensorWeight3_TextChanged(object sender, EventArgs e)
        {
            SendSensorWeight();
        }

        private void tbSensorWeight4_TextChanged(object sender, EventArgs e)
        {
            SendSensorWeight();
        }

        private void tbSensorWeight5_TextChanged(object sender, EventArgs e)
        {
            SendSensorWeight();
        }

        private void tbSensorWeight6_TextChanged(object sender, EventArgs e)
        {
            SendSensorWeight();
        }

        private void tbSensorWeight7_TextChanged(object sender, EventArgs e)
        {
            SendSensorWeight();
        }
        #endregion


        private void SendCoefficients()
        {
            
            if (Updating == true)
                return;

            Command c = new Command();

            c.Type = CommandType.Set;
            c.Number = 15;
            c.DataBytes = 6;

            byte[] data = new byte[6];
            byte[] b;

            float s;

            float.TryParse(tbKp.Text, out s);
            FixedPoint f = new FixedPoint(5, 10, s);
            b = BitConverter.GetBytes(f.Number);
            data[5] = b[1];
            data[4] = b[0];

            float.TryParse(tbKi.Text, out s);
            f = new FixedPoint(5, 10, s);
            b = BitConverter.GetBytes(f.Number);
            data[3] = b[1];
            data[2] = b[0];

            float.TryParse(tbKd.Text, out s);
            f = new FixedPoint(5, 10, s);
            b = BitConverter.GetBytes(f.Number);
            data[1] = b[1];
            data[0] = b[0];

            c.Data = data;
            DebugPort.Write(c);
             
        }

        private void tbKp_TextChanged(object sender, EventArgs e)
        {
            SendCoefficients();
        }

        private void tbKi_TextChanged(object sender, EventArgs e)
        {
            SendCoefficients();
        }

        private void tbKd_TextChanged(object sender, EventArgs e)
        {            
            SendCoefficients();
        }

        private bool Updating = false;

        private void bGetSteerData_Click(object sender, EventArgs e)
        {
            Updating = true;
            Command c = new Command(CommandType.Request, 14, 0, null);
            c = DebugPort.WriteRead(c);

            if (c.Data == null || c.Data.Length == 0)
                return;

           // c = DebugPort.Read();
            FixedPoint f = new FixedPoint(8,7,0f);

            tbSensorWeight0.Text =  f.GetFloat(8,7,Support.GetIntFromSignedWord(ref c, 0)).ToString();
            tbSensorWeight1.Text =  f.GetFloat(8,7,Support.GetIntFromSignedWord(ref c, 2)).ToString();
            tbSensorWeight2.Text =  f.GetFloat(8,7,Support.GetIntFromSignedWord(ref c, 4)).ToString();
            tbSensorWeight3.Text =  f.GetFloat(8,7,Support.GetIntFromSignedWord(ref c, 6)).ToString();
            tbSensorWeight4.Text =  f.GetFloat(8,7,Support.GetIntFromSignedWord(ref c, 8)).ToString();
            tbSensorWeight5.Text =  f.GetFloat(8,7,Support.GetIntFromSignedWord(ref c, 10)).ToString();
            tbSensorWeight6.Text =  f.GetFloat(8,7,Support.GetIntFromSignedWord(ref c, 12)).ToString();
            tbSensorWeight7.Text =  f.GetFloat(8, 7, Support.GetIntFromSignedWord(ref c, 14)).ToString();

          // Thread.Sleep(100);
            
            c = new Command(CommandType.Request, 16, 0, null);
            c = DebugPort.WriteRead(c);
            //c = DebugPort.Read();

            tbKp.Text = f.GetFloat(5,10,Support.GetIntFromSignedWord(ref c, 0)).ToString();
            tbKi.Text = f.GetFloat(5, 10, Support.GetIntFromSignedWord(ref c, 2)).ToString();
            tbKd.Text = f.GetFloat(5, 10, Support.GetIntFromSignedWord(ref c, 4)).ToString();
            Updating = false;

        }
    }
}
