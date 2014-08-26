using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace LineDebugger
{
    public partial class Speed : Form
    {
        DebugPort DebugPort;
        private Controller Controller;

        public Speed(ref DebugPort dPort)
        {
            InitializeComponent();

            DebugPort = dPort;

            if (DebugPort != null)
            {
                Controller = new Controller();
                Controller.DirectionChange += new ValueChangeHandler(DirectionChange);
                Controller.ThrottleChange += new ValueChangeHandler(ThrottleChange);

                Controller.Start();
            }


        }

        private void tbThrottleSet_Scroll(object sender, EventArgs e)
        {
            if (!cbManualDrive.Checked) return;

            tbThrottle.Text = tbThrottleSet.Value.ToString();

            byte[] buf = BitConverter.GetBytes(Convert.ToInt16(tbThrottleSet.Value));
            Command c = new Command(CommandType.Set, 2, 2, buf);
            DebugPort.Write(c);

            // Read the response
            c = DebugPort.Read();
            tbActThrottle.Text = Support.GetStringFromUnsignedWord(ref c, 0);
        }

        private void tbTurn_Scroll(object sender, EventArgs e)
        {
            if (!cbManualDrive.Checked) return;

            textTurn.Text = tbTurn.Value.ToString();

            byte[] buf = BitConverter.GetBytes(Convert.ToInt16(tbTurn.Value));
            Command c = new Command(CommandType.Set, 0, 2, buf);
            DebugPort.Write(c);

            // Read the response
            c = DebugPort.Read();
            tbActTurn.Text = Support.GetStringFromUnsignedWord(ref c, 0);

        }

        private void textTurn_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Enter)
            {
                try
                {
                    tbTurn.Value = Convert.ToInt16(textTurn.Text);
                    tbTurn_Scroll(null, null);
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.StackTrace);
                }
            }

        }


        public void SetAutoStopTime(int d)
        {
            cbAutoStop.SelectedIndex = d;
        }
        public int GetAutoStopTime()
        {
            return cbAutoStop.SelectedIndex;
        }

        public short GetSpeedLimit()
        {
            short sl;
            Int16.TryParse(tbSpeedLimit.Text, out sl);
            return sl;
        }
        public bool GetSpeedLimitChecked()
        {
            return cbSpeedLimit.Checked;
        }

        #region Controller Event Handlers
        private void ThrottleChange(int val)
        {
            if (!cbManualDrive.Checked || !cbControllerDrive.Checked) return;

            Command c = new Command(CommandType.Set, 2, 2, BitConverter.GetBytes((Int16)val));
            DebugPort.Write(c);
            DebugPort.MsgSent = true;

            c = DebugPort.Read();
            Support.UpdateTextFromThread(tbActThrottle, Support.GetStringFromUnsignedWord(ref c, 0));
        }

        private void DirectionChange(int val)
        {
            if (!cbManualDrive.Checked || !cbControllerDrive.Checked) return;

            Command c = new Command(CommandType.Set, 0, 2, BitConverter.GetBytes((Int16)val));
            DebugPort.Write(c);
            DebugPort.MsgSent = true;

            c = DebugPort.Read();
            Support.UpdateTextFromThread(tbActTurn, Support.GetStringFromUnsignedWord(ref c, 0));
        }
        #endregion

        private void cbSpeedLimit_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSpeedLimit.Checked == true)
            {
                tbSpeedLimit.Enabled = true;
            }
            else
                tbSpeedLimit.Enabled = false;

            SendSpeedLimit();
        }

        private void tbSpeedLimit_TextChanged(object sender, EventArgs e)
        {
            SendSpeedLimit();
        }

        private void SendSpeedLimit()
        {

            byte[] d = BitConverter.GetBytes(GetSpeedLimit());


            Command c = new Command(CommandType.Set, 11, 4, new byte[] { d[0], d[1], 0x00, BitConverter.GetBytes(GetSpeedLimitChecked())[0] });
            DebugPort.Write(c);
        }

        public void Update(Command c)
        {
            Support.UpdateTextFromThread(tbActTurn, Support.GetStringFromUnsignedWord(ref c, 0));
            Support.UpdateTextFromThread(tbActThrottle, Support.GetStringFromUnsignedWord(ref c, 2));
            Support.UpdateLabelFromThread(lRPM, Support.GetStringFromUnsignedWord(ref c, 6));
        }

        public bool GetDiagChecked()
        {
            return cbDiagMode.Checked;
        }

        public void SetDiagChecked(bool enabled)
        {
            SetDiagChecked(enabled, cbAutoStop.SelectedIndex);
        }
        public void SetDiagChecked(bool enabled, int index)
        {
            cbDiagMode.Checked = enabled;
            cbAutoStop.SelectedIndex = index;
        }
    }
}
