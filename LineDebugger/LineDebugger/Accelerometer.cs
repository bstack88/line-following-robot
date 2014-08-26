using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using ZedGraph;

namespace LineDebugger
{
    /// <summary>
    /// Creates a form to display accelerometer data
    /// </summary>
    public partial class Accelerometer : Form
    {
        private PointPairList DataX;
        private PointPairList DataY;
        private PointPairList DataZ;

        private const int XZero = 124, YZero = 136, ZZero = 162;

        private const int YMax = 255;

        private int DataPointCount = 20;

        private float Sensitivity = .00391f / 0.8f;

        public Accelerometer()
        {
            InitializeComponent();

            UpdateGraph();
            

            DataX = new PointPairList();
            DataY = new PointPairList();
            DataZ = new PointPairList();
        }

        private void UpdateGraph()
        {
            GraphPane pane = zgcAcc.GraphPane;

            pane.CurveList.Clear();

            pane.Title.Text = "Acceleration";
            pane.XAxis.Title.Text = "Acceleration";
            pane.YAxis.Title.Text = "g";


            pane.AddCurve("X Acceleration", DataX, Color.Blue, SymbolType.Default);
            pane.AddCurve("Y Acceleration", DataY, Color.Red, SymbolType.Default);
            pane.AddCurve("Z Acceleration", DataZ, Color.LightGreen, SymbolType.Default);
            
            SetSize();


            pane.YAxis.Scale.Min = -YMax * Sensitivity;
            pane.YAxis.Scale.Max = YMax * Sensitivity;

            zgcAcc.AxisChange();

            zgcAcc.Invalidate();
         }


        private void Accelerometer_Resize(object sender, EventArgs e)
        {
            SetSize();
        }

        private void SetSize()
        {
            zgcAcc.Location = new Point(10, 10);
            zgcAcc.Size = new Size(ClientRectangle.Width - 20, ClientRectangle.Height - 20);
        }

        public void AddData(int x, int y, int z)
        {
            // Remove old data points
            if (DataX.Count > DataPointCount)
            {
                DataX.RemoveAt(0);
                DataY.RemoveAt(0);
                DataZ.RemoveAt(0);

                for (int i = 0; i < DataPointCount - 1; i++)
                {
                    DataX[i].X--;// = new PointPair(DataX[i + 1].X - 1, DataX[i + 1].Y);
                    DataY[i].X--;// = new PointPair(DataY[i + 1].X - 1, DataY[i + 1].Y);
                    DataZ[i].X--;
                }

            }

            DataX.Add(new PointPair(DataX.Count, (x-XZero)*Sensitivity));
            DataY.Add(new PointPair(DataY.Count, (y-YZero)*Sensitivity));
            DataZ.Add(new PointPair(DataZ.Count, (z-ZZero)*Sensitivity));

            UpdateGraph();

        }

    }
}
