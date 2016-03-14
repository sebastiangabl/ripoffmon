namespace mapeditor {
  partial class NewLevelForm {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing) {
      if (disposing && (components != null)) {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent() {
      this.groupBox1 = new System.Windows.Forms.GroupBox();
      this.nudHeight = new System.Windows.Forms.NumericUpDown();
      this.nudWidth = new System.Windows.Forms.NumericUpDown();
      this.label2 = new System.Windows.Forms.Label();
      this.label1 = new System.Windows.Forms.Label();
      this.btnOk = new System.Windows.Forms.Button();
      this.groupBox1.SuspendLayout();
      ((System.ComponentModel.ISupportInitialize)(this.nudHeight)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.nudWidth)).BeginInit();
      this.SuspendLayout();
      // 
      // groupBox1
      // 
      this.groupBox1.Controls.Add(this.nudHeight);
      this.groupBox1.Controls.Add(this.nudWidth);
      this.groupBox1.Controls.Add(this.label2);
      this.groupBox1.Controls.Add(this.label1);
      this.groupBox1.Location = new System.Drawing.Point(13, 13);
      this.groupBox1.Name = "groupBox1";
      this.groupBox1.Size = new System.Drawing.Size(196, 59);
      this.groupBox1.TabIndex = 1;
      this.groupBox1.TabStop = false;
      this.groupBox1.Text = "Dimensions";
      // 
      // nudHeight
      // 
      this.nudHeight.Location = new System.Drawing.Point(143, 29);
      this.nudHeight.Maximum = new decimal(new int[] {
            99,
            0,
            0,
            0});
      this.nudHeight.Minimum = new decimal(new int[] {
            8,
            0,
            0,
            0});
      this.nudHeight.Name = "nudHeight";
      this.nudHeight.Size = new System.Drawing.Size(40, 20);
      this.nudHeight.TabIndex = 5;
      this.nudHeight.Value = new decimal(new int[] {
            15,
            0,
            0,
            0});
      // 
      // nudWidth
      // 
      this.nudWidth.Location = new System.Drawing.Point(50, 29);
      this.nudWidth.Maximum = new decimal(new int[] {
            99,
            0,
            0,
            0});
      this.nudWidth.Minimum = new decimal(new int[] {
            8,
            0,
            0,
            0});
      this.nudWidth.Name = "nudWidth";
      this.nudWidth.Size = new System.Drawing.Size(40, 20);
      this.nudWidth.TabIndex = 4;
      this.nudWidth.Value = new decimal(new int[] {
            15,
            0,
            0,
            0});
      // 
      // label2
      // 
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(96, 31);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(41, 13);
      this.label2.TabIndex = 3;
      this.label2.Text = "Height:";
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(6, 31);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(38, 13);
      this.label1.TabIndex = 2;
      this.label1.Text = "Width:";
      // 
      // btnOk
      // 
      this.btnOk.Location = new System.Drawing.Point(134, 78);
      this.btnOk.Name = "btnOk";
      this.btnOk.Size = new System.Drawing.Size(75, 23);
      this.btnOk.TabIndex = 0;
      this.btnOk.Text = "OK";
      this.btnOk.UseVisualStyleBackColor = true;
      this.btnOk.Click += new System.EventHandler(this.btnOk_Click);
      // 
      // NewLevelForm
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(216, 106);
      this.Controls.Add(this.btnOk);
      this.Controls.Add(this.groupBox1);
      this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
      this.Name = "NewLevelForm";
      this.ShowIcon = false;
      this.ShowInTaskbar = false;
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
      this.Text = "New Level";
      this.groupBox1.ResumeLayout(false);
      this.groupBox1.PerformLayout();
      ((System.ComponentModel.ISupportInitialize)(this.nudHeight)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.nudWidth)).EndInit();
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.GroupBox groupBox1;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Button btnOk;
    private System.Windows.Forms.NumericUpDown nudHeight;
    private System.Windows.Forms.NumericUpDown nudWidth;
  }
}