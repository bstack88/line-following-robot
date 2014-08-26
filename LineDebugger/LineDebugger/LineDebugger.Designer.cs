namespace LineDebugger
{
    partial class LineDebugger
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
            this.cbComPort = new System.Windows.Forms.ComboBox();
            this.bOpenPort = new System.Windows.Forms.Button();
            this.bStartDebug = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.accelerationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sensorsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.speedAndTurningToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fixedPointConverterToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // cbComPort
            // 
            this.cbComPort.FormattingEnabled = true;
            this.cbComPort.Location = new System.Drawing.Point(241, 3);
            this.cbComPort.Name = "cbComPort";
            this.cbComPort.Size = new System.Drawing.Size(70, 21);
            this.cbComPort.TabIndex = 0;
            // 
            // bOpenPort
            // 
            this.bOpenPort.Location = new System.Drawing.Point(317, 3);
            this.bOpenPort.Name = "bOpenPort";
            this.bOpenPort.Size = new System.Drawing.Size(71, 21);
            this.bOpenPort.TabIndex = 1;
            this.bOpenPort.Text = "Open";
            this.bOpenPort.UseVisualStyleBackColor = true;
            this.bOpenPort.Click += new System.EventHandler(this.OpenPort);
            // 
            // bStartDebug
            // 
            this.bStartDebug.Location = new System.Drawing.Point(394, 3);
            this.bStartDebug.Name = "bStartDebug";
            this.bStartDebug.Size = new System.Drawing.Size(79, 23);
            this.bStartDebug.TabIndex = 30;
            this.bStartDebug.Text = "Start Debug";
            this.bStartDebug.UseVisualStyleBackColor = true;
            this.bStartDebug.Click += new System.EventHandler(this.bStartDebug_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.viewToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(861, 24);
            this.menuStrip1.TabIndex = 33;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.accelerationToolStripMenuItem,
            this.sensorsToolStripMenuItem,
            this.speedAndTurningToolStripMenuItem,
            this.fixedPointConverterToolStripMenuItem});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.viewToolStripMenuItem.Text = "&View";
            // 
            // accelerationToolStripMenuItem
            // 
            this.accelerationToolStripMenuItem.Name = "accelerationToolStripMenuItem";
            this.accelerationToolStripMenuItem.Size = new System.Drawing.Size(187, 22);
            this.accelerationToolStripMenuItem.Text = "&Acceleration";
            this.accelerationToolStripMenuItem.Click += new System.EventHandler(this.accelerationToolStripMenuItem_Click);
            // 
            // sensorsToolStripMenuItem
            // 
            this.sensorsToolStripMenuItem.Name = "sensorsToolStripMenuItem";
            this.sensorsToolStripMenuItem.Size = new System.Drawing.Size(187, 22);
            this.sensorsToolStripMenuItem.Text = "&Sensors";
            this.sensorsToolStripMenuItem.Click += new System.EventHandler(this.sensorsToolStripMenuItem_Click);
            // 
            // speedAndTurningToolStripMenuItem
            // 
            this.speedAndTurningToolStripMenuItem.Name = "speedAndTurningToolStripMenuItem";
            this.speedAndTurningToolStripMenuItem.Size = new System.Drawing.Size(187, 22);
            this.speedAndTurningToolStripMenuItem.Text = "Speed and &Turning";
            this.speedAndTurningToolStripMenuItem.Click += new System.EventHandler(this.speedAndTurningToolStripMenuItem_Click);
            // 
            // fixedPointConverterToolStripMenuItem
            // 
            this.fixedPointConverterToolStripMenuItem.Name = "fixedPointConverterToolStripMenuItem";
            this.fixedPointConverterToolStripMenuItem.Size = new System.Drawing.Size(187, 22);
            this.fixedPointConverterToolStripMenuItem.Text = "Fixed Point Converter";
            this.fixedPointConverterToolStripMenuItem.Click += new System.EventHandler(this.fixedPointConverterToolStripMenuItem_Click);
            // 
            // LineDebugger
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(861, 595);
            this.Controls.Add(this.bStartDebug);
            this.Controls.Add(this.bOpenPort);
            this.Controls.Add(this.cbComPort);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "LineDebugger";
            this.Text = "Line Debugger v0.1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.LineDebugger_FormClosed);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cbComPort;
        private System.Windows.Forms.Button bOpenPort;
        private System.Windows.Forms.Button bStartDebug;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem accelerationToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sensorsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem speedAndTurningToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem fixedPointConverterToolStripMenuItem;
    }
}

