using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace LineDebugger
{
    public partial class FixedPointConverter : Form
    {
        FixedPoint F;

        public FixedPointConverter()
        {
            InitializeComponent();

            F = new FixedPoint();
        }


        private void UpdateData()
        {
            try
            {
                int w, f, n;
                if (!int.TryParse(tbI.Text, out w))
                    int.Parse(tbI.Text, System.Globalization.NumberStyles.HexNumber);
                if (!int.TryParse(tbF.Text, out f))
                    int.Parse(tbF.Text, System.Globalization.NumberStyles.HexNumber);

                if (cbF2F.Checked == true)
                {

                    if (!int.TryParse(tbFixed.Text, out n))
                        n = int.Parse(tbFixed.Text, System.Globalization.NumberStyles.HexNumber);

                    tbFloat.Text = F.GetFloat(w, f, n).ToString();
                }
                else
                {
                    float nf = 0;

                    if (!float.TryParse(tbFloat.Text, out nf))
                        nf = float.Parse(tbFloat.Text, System.Globalization.NumberStyles.HexNumber);

                    F = new FixedPoint(w, f, nf);
                    tbFixed.Text = F.Number.ToString();
                }
            }
            catch (Exception e)
            {
            }

        }

        private void bGo_Click(object sender, EventArgs e)
        {
            UpdateData();
        }

    }
}
