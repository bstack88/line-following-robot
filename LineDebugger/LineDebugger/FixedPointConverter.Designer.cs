namespace LineDebugger
{
    partial class FixedPointConverter
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
            this.tbI = new System.Windows.Forms.TextBox();
            this.tbF = new System.Windows.Forms.TextBox();
            this.tbFixed = new System.Windows.Forms.TextBox();
            this.tbFloat = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.cbF2F = new System.Windows.Forms.CheckBox();
            this.bGo = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tbI
            // 
            this.tbI.Location = new System.Drawing.Point(29, 12);
            this.tbI.Name = "tbI";
            this.tbI.Size = new System.Drawing.Size(23, 20);
            this.tbI.TabIndex = 0;
            // 
            // tbF
            // 
            this.tbF.Location = new System.Drawing.Point(58, 12);
            this.tbF.Name = "tbF";
            this.tbF.Size = new System.Drawing.Size(27, 20);
            this.tbF.TabIndex = 1;
            // 
            // tbFixed
            // 
            this.tbFixed.Location = new System.Drawing.Point(104, 12);
            this.tbFixed.Name = "tbFixed";
            this.tbFixed.Size = new System.Drawing.Size(100, 20);
            this.tbFixed.TabIndex = 2;
            // 
            // tbFloat
            // 
            this.tbFloat.Location = new System.Drawing.Point(104, 51);
            this.tbFloat.Name = "tbFloat";
            this.tbFloat.Size = new System.Drawing.Size(100, 20);
            this.tbFloat.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(8, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(15, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Q";
            // 
            // cbF2F
            // 
            this.cbF2F.AutoSize = true;
            this.cbF2F.Checked = true;
            this.cbF2F.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbF2F.Location = new System.Drawing.Point(12, 53);
            this.cbF2F.Name = "cbF2F";
            this.cbF2F.Size = new System.Drawing.Size(89, 17);
            this.cbF2F.TabIndex = 5;
            this.cbF2F.Text = "Fixed to Float";
            this.cbF2F.UseVisualStyleBackColor = true;
            // 
            // bGo
            // 
            this.bGo.Location = new System.Drawing.Point(211, 10);
            this.bGo.Name = "bGo";
            this.bGo.Size = new System.Drawing.Size(47, 23);
            this.bGo.TabIndex = 6;
            this.bGo.Text = "Go";
            this.bGo.UseVisualStyleBackColor = true;
            this.bGo.Click += new System.EventHandler(this.bGo_Click);
            // 
            // FixedPointConverter
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(270, 88);
            this.Controls.Add(this.bGo);
            this.Controls.Add(this.cbF2F);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbFloat);
            this.Controls.Add(this.tbFixed);
            this.Controls.Add(this.tbF);
            this.Controls.Add(this.tbI);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.SizableToolWindow;
            this.Name = "FixedPointConverter";
            this.Text = "FixedPointConverter";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbI;
        private System.Windows.Forms.TextBox tbF;
        private System.Windows.Forms.TextBox tbFixed;
        private System.Windows.Forms.TextBox tbFloat;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox cbF2F;
        private System.Windows.Forms.Button bGo;
    }
}