namespace LineDebugger
{
    partial class Accelerometer
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.zgcAcc = new ZedGraph.ZedGraphControl();
            this.SuspendLayout();
            // 
            // zgcAcc
            // 
            this.zgcAcc.Location = new System.Drawing.Point(12, 12);
            this.zgcAcc.Name = "zgcAcc";
            this.zgcAcc.ScrollGrace = 0D;
            this.zgcAcc.ScrollMaxX = 0D;
            this.zgcAcc.ScrollMaxY = 0D;
            this.zgcAcc.ScrollMaxY2 = 0D;
            this.zgcAcc.ScrollMinX = 0D;
            this.zgcAcc.ScrollMinY = 0D;
            this.zgcAcc.ScrollMinY2 = 0D;
            this.zgcAcc.Size = new System.Drawing.Size(533, 312);
            this.zgcAcc.TabIndex = 0;
            // 
            // Accelerometer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(557, 336);
            this.Controls.Add(this.zgcAcc);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.SizableToolWindow;
            this.Name = "Accelerometer";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.Text = "Accelerometer";
            this.Resize += new System.EventHandler(this.Accelerometer_Resize);
            this.ResumeLayout(false);

        }

        #endregion

        private ZedGraph.ZedGraphControl zgcAcc;
    }
}