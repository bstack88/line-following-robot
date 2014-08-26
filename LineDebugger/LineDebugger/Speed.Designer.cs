namespace LineDebugger
{
    partial class Speed
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
            this.tbSpeedLimit = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.cbSpeedLimit = new System.Windows.Forms.CheckBox();
            this.cbAutoStop = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.tbThrottleSet = new System.Windows.Forms.TrackBar();
            this.tbActThrottle = new System.Windows.Forms.TextBox();
            this.tbThrottle = new System.Windows.Forms.TextBox();
            this.lActThrottle = new System.Windows.Forms.Label();
            this.lThrottle = new System.Windows.Forms.Label();
            this.lActTurn = new System.Windows.Forms.Label();
            this.tbActTurn = new System.Windows.Forms.TextBox();
            this.textTurn = new System.Windows.Forms.TextBox();
            this.lTurn = new System.Windows.Forms.Label();
            this.tbTurn = new System.Windows.Forms.TrackBar();
            this.cbManualDrive = new System.Windows.Forms.CheckBox();
            this.cbControllerDrive = new System.Windows.Forms.CheckBox();
            this.label1 = new System.Windows.Forms.Label();
            this.lRPM = new System.Windows.Forms.Label();
            this.cbDiagMode = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.tbThrottleSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbTurn)).BeginInit();
            this.SuspendLayout();
            // 
            // tbSpeedLimit
            // 
            this.tbSpeedLimit.Enabled = false;
            this.tbSpeedLimit.Location = new System.Drawing.Point(97, 76);
            this.tbSpeedLimit.Name = "tbSpeedLimit";
            this.tbSpeedLimit.Size = new System.Drawing.Size(39, 20);
            this.tbSpeedLimit.TabIndex = 54;
            this.tbSpeedLimit.Text = "100";
            this.tbSpeedLimit.TextChanged += new System.EventHandler(this.tbSpeedLimit_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(31, 79);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(61, 13);
            this.label3.TabIndex = 53;
            this.label3.Text = "Max Speed";
            // 
            // cbSpeedLimit
            // 
            this.cbSpeedLimit.AutoSize = true;
            this.cbSpeedLimit.Location = new System.Drawing.Point(15, 59);
            this.cbSpeedLimit.Name = "cbSpeedLimit";
            this.cbSpeedLimit.Size = new System.Drawing.Size(121, 17);
            this.cbSpeedLimit.TabIndex = 52;
            this.cbSpeedLimit.Text = "Enforce Speed Limit";
            this.cbSpeedLimit.UseVisualStyleBackColor = true;
            this.cbSpeedLimit.CheckedChanged += new System.EventHandler(this.cbSpeedLimit_CheckedChanged);
            // 
            // cbAutoStop
            // 
            this.cbAutoStop.DisplayMember = "200";
            this.cbAutoStop.FormattingEnabled = true;
            this.cbAutoStop.Items.AddRange(new object[] {
            "20",
            "40",
            "60",
            "80",
            "100",
            "120",
            "140",
            "160",
            "180",
            "200",
            "220",
            "240",
            "260",
            "280",
            "300",
            "320",
            "340",
            "360",
            "380",
            "400"});
            this.cbAutoStop.Location = new System.Drawing.Point(97, 120);
            this.cbAutoStop.Name = "cbAutoStop";
            this.cbAutoStop.Size = new System.Drawing.Size(50, 21);
            this.cbAutoStop.TabIndex = 51;
            this.cbAutoStop.Text = "200";
            this.cbAutoStop.ValueMember = "200";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(15, 123);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(77, 13);
            this.label2.TabIndex = 50;
            this.label2.Text = "AutoStop Time";
            // 
            // tbThrottleSet
            // 
            this.tbThrottleSet.Location = new System.Drawing.Point(160, 106);
            this.tbThrottleSet.Maximum = 1000;
            this.tbThrottleSet.Name = "tbThrottleSet";
            this.tbThrottleSet.Size = new System.Drawing.Size(104, 45);
            this.tbThrottleSet.TabIndex = 49;
            this.tbThrottleSet.TickFrequency = 50;
            this.tbThrottleSet.Scroll += new System.EventHandler(this.tbThrottleSet_Scroll);
            // 
            // tbActThrottle
            // 
            this.tbActThrottle.Location = new System.Drawing.Point(345, 77);
            this.tbActThrottle.Name = "tbActThrottle";
            this.tbActThrottle.Size = new System.Drawing.Size(75, 20);
            this.tbActThrottle.TabIndex = 48;
            // 
            // tbThrottle
            // 
            this.tbThrottle.Location = new System.Drawing.Point(205, 80);
            this.tbThrottle.Name = "tbThrottle";
            this.tbThrottle.Size = new System.Drawing.Size(59, 20);
            this.tbThrottle.TabIndex = 47;
            // 
            // lActThrottle
            // 
            this.lActThrottle.AutoSize = true;
            this.lActThrottle.Location = new System.Drawing.Point(274, 80);
            this.lActThrottle.Name = "lActThrottle";
            this.lActThrottle.Size = new System.Drawing.Size(69, 13);
            this.lActThrottle.TabIndex = 46;
            this.lActThrottle.Text = "Throttle (real)";
            // 
            // lThrottle
            // 
            this.lThrottle.AutoSize = true;
            this.lThrottle.Location = new System.Drawing.Point(160, 83);
            this.lThrottle.Name = "lThrottle";
            this.lThrottle.Size = new System.Drawing.Size(43, 13);
            this.lThrottle.TabIndex = 45;
            this.lThrottle.Text = "Throttle";
            // 
            // lActTurn
            // 
            this.lActTurn.AutoSize = true;
            this.lActTurn.Location = new System.Drawing.Point(274, 13);
            this.lActTurn.Name = "lActTurn";
            this.lActTurn.Size = new System.Drawing.Size(55, 13);
            this.lActTurn.TabIndex = 44;
            this.lActTurn.Text = "Turn (real)";
            // 
            // tbActTurn
            // 
            this.tbActTurn.Location = new System.Drawing.Point(345, 10);
            this.tbActTurn.Name = "tbActTurn";
            this.tbActTurn.Size = new System.Drawing.Size(75, 20);
            this.tbActTurn.TabIndex = 43;
            // 
            // textTurn
            // 
            this.textTurn.Location = new System.Drawing.Point(205, 10);
            this.textTurn.Name = "textTurn";
            this.textTurn.Size = new System.Drawing.Size(59, 20);
            this.textTurn.TabIndex = 42;
            // 
            // lTurn
            // 
            this.lTurn.AutoSize = true;
            this.lTurn.Location = new System.Drawing.Point(160, 13);
            this.lTurn.Name = "lTurn";
            this.lTurn.Size = new System.Drawing.Size(29, 13);
            this.lTurn.TabIndex = 41;
            this.lTurn.Text = "Turn";
            // 
            // tbTurn
            // 
            this.tbTurn.Location = new System.Drawing.Point(160, 29);
            this.tbTurn.Maximum = 700;
            this.tbTurn.Name = "tbTurn";
            this.tbTurn.Size = new System.Drawing.Size(104, 45);
            this.tbTurn.TabIndex = 40;
            this.tbTurn.TickFrequency = 50;
            this.tbTurn.Scroll += new System.EventHandler(this.tbTurn_Scroll);
            // 
            // cbManualDrive
            // 
            this.cbManualDrive.AutoSize = true;
            this.cbManualDrive.Checked = true;
            this.cbManualDrive.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbManualDrive.Location = new System.Drawing.Point(15, 13);
            this.cbManualDrive.Name = "cbManualDrive";
            this.cbManualDrive.Size = new System.Drawing.Size(89, 17);
            this.cbManualDrive.TabIndex = 55;
            this.cbManualDrive.Text = "Manual Drive";
            this.cbManualDrive.UseVisualStyleBackColor = true;
            // 
            // cbControllerDrive
            // 
            this.cbControllerDrive.AutoSize = true;
            this.cbControllerDrive.Checked = true;
            this.cbControllerDrive.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbControllerDrive.Location = new System.Drawing.Point(15, 36);
            this.cbControllerDrive.Name = "cbControllerDrive";
            this.cbControllerDrive.Size = new System.Drawing.Size(98, 17);
            this.cbControllerDrive.TabIndex = 56;
            this.cbControllerDrive.Text = "Controller Drive";
            this.cbControllerDrive.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(274, 120);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(31, 13);
            this.label1.TabIndex = 57;
            this.label1.Text = "RPM";
            // 
            // lRPM
            // 
            this.lRPM.AutoSize = true;
            this.lRPM.Location = new System.Drawing.Point(312, 120);
            this.lRPM.Name = "lRPM";
            this.lRPM.Size = new System.Drawing.Size(13, 13);
            this.lRPM.TabIndex = 58;
            this.lRPM.Text = "0";
            // 
            // cbDiagMode
            // 
            this.cbDiagMode.AutoSize = true;
            this.cbDiagMode.Checked = true;
            this.cbDiagMode.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbDiagMode.Location = new System.Drawing.Point(15, 102);
            this.cbDiagMode.Name = "cbDiagMode";
            this.cbDiagMode.Size = new System.Drawing.Size(106, 17);
            this.cbDiagMode.TabIndex = 59;
            this.cbDiagMode.Text = "AutoStop Enable";
            this.cbDiagMode.UseVisualStyleBackColor = true;
            // 
            // Speed
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(433, 152);
            this.Controls.Add(this.cbDiagMode);
            this.Controls.Add(this.lRPM);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cbControllerDrive);
            this.Controls.Add(this.cbManualDrive);
            this.Controls.Add(this.tbSpeedLimit);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.cbSpeedLimit);
            this.Controls.Add(this.cbAutoStop);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.tbThrottleSet);
            this.Controls.Add(this.tbActThrottle);
            this.Controls.Add(this.tbThrottle);
            this.Controls.Add(this.lActThrottle);
            this.Controls.Add(this.lThrottle);
            this.Controls.Add(this.lActTurn);
            this.Controls.Add(this.tbActTurn);
            this.Controls.Add(this.textTurn);
            this.Controls.Add(this.lTurn);
            this.Controls.Add(this.tbTurn);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.SizableToolWindow;
            this.Name = "Speed";
            this.Text = "Speed & Turning";
            ((System.ComponentModel.ISupportInitialize)(this.tbThrottleSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbTurn)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lActThrottle;
        private System.Windows.Forms.Label lThrottle;
        private System.Windows.Forms.Label lActTurn;
        private System.Windows.Forms.Label lTurn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbSpeedLimit;
        private System.Windows.Forms.CheckBox cbSpeedLimit;
        private System.Windows.Forms.ComboBox cbAutoStop;
        private System.Windows.Forms.TrackBar tbThrottleSet;
        private System.Windows.Forms.TextBox tbActThrottle;
        private System.Windows.Forms.TextBox tbThrottle;
        private System.Windows.Forms.TextBox tbActTurn;
        private System.Windows.Forms.TextBox textTurn;
        private System.Windows.Forms.TrackBar tbTurn;
        private System.Windows.Forms.CheckBox cbManualDrive;
        private System.Windows.Forms.CheckBox cbControllerDrive;
        private System.Windows.Forms.Label lRPM;
        private System.Windows.Forms.CheckBox cbDiagMode;
    }
}