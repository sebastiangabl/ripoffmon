namespace mapeditor {
  partial class MainForm {
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
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
      this.ssMain = new System.Windows.Forms.StatusStrip();
      this.msMain = new System.Windows.Forms.MenuStrip();
      this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiSep1 = new System.Windows.Forms.ToolStripSeparator();
      this.tsmiSep2 = new System.Windows.Forms.ToolStripSeparator();
      this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.entitiesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripSeparator();
      this.levelSettingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiViewTilesB = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiViewTilesF = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiViewMovement = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiViewFloor = new System.Windows.Forms.ToolStripMenuItem();
      this.tsMain = new System.Windows.Forms.ToolStrip();
      this.cbMovementData = new System.Windows.Forms.CheckBox();
      this.cbFloorData = new System.Windows.Forms.CheckBox();
      this.groupBox1 = new System.Windows.Forms.GroupBox();
      this.groupBox2 = new System.Windows.Forms.GroupBox();
      this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
      this.groupBox4 = new System.Windows.Forms.GroupBox();
      this.cbEditBgTiles = new System.Windows.Forms.CheckBox();
      this.groupBox5 = new System.Windows.Forms.GroupBox();
      this.cbEditFgTiles = new System.Windows.Forms.CheckBox();
      this.tcMain = new System.Windows.Forms.TabControl();
      this.tsmiViewGrid = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiSep = new System.Windows.Forms.ToolStripSeparator();
      this.tsslCoords = new System.Windows.Forms.ToolStripStatusLabel();
      this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
      this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
      this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
      this.tsmiSaveAs = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
      this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
      this.tsbNew = new System.Windows.Forms.ToolStripButton();
      this.tsbOpen = new System.Windows.Forms.ToolStripButton();
      this.tsbSave = new System.Windows.Forms.ToolStripButton();
      this.tsbCut = new System.Windows.Forms.ToolStripButton();
      this.tsbCopy = new System.Windows.Forms.ToolStripButton();
      this.tsbPaste = new System.Windows.Forms.ToolStripButton();
      this.tsbSelection = new System.Windows.Forms.ToolStripButton();
      this.tsbToolSingle = new System.Windows.Forms.ToolStripButton();
      this.tsbToolFill = new System.Windows.Forms.ToolStripButton();
      this.tsbToolReplace = new System.Windows.Forms.ToolStripButton();
      this.tsmiNew = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiOpen = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiSave = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiSaveAll = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiExit = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiCut = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiCopy = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiPaste = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiPreferences = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiZoom = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiZoomIn = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiZoomOut = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
      this.tsmiZoomReset = new System.Windows.Forms.ToolStripMenuItem();
      this.ssMain.SuspendLayout();
      this.msMain.SuspendLayout();
      this.tsMain.SuspendLayout();
      this.groupBox1.SuspendLayout();
      this.groupBox2.SuspendLayout();
      this.tableLayoutPanel2.SuspendLayout();
      this.groupBox4.SuspendLayout();
      this.groupBox5.SuspendLayout();
      this.SuspendLayout();
      // 
      // ssMain
      // 
      this.ssMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsslCoords});
      this.ssMain.Location = new System.Drawing.Point(0, 708);
      this.ssMain.Name = "ssMain";
      this.ssMain.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
      this.ssMain.Size = new System.Drawing.Size(1008, 22);
      this.ssMain.TabIndex = 0;
      // 
      // msMain
      // 
      this.msMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.viewToolStripMenuItem});
      this.msMain.Location = new System.Drawing.Point(0, 0);
      this.msMain.Name = "msMain";
      this.msMain.Size = new System.Drawing.Size(1008, 24);
      this.msMain.TabIndex = 1;
      this.msMain.Text = "menuStrip1";
      // 
      // fileToolStripMenuItem
      // 
      this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiNew,
            this.tsmiOpen,
            this.tsmiSep1,
            this.tsmiSave,
            this.tsmiSaveAs,
            this.tsmiSaveAll,
            this.tsmiSep2,
            this.tsmiExit});
      this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
      this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
      this.fileToolStripMenuItem.Text = "&File";
      // 
      // tsmiSep1
      // 
      this.tsmiSep1.Name = "tsmiSep1";
      this.tsmiSep1.Size = new System.Drawing.Size(184, 6);
      // 
      // tsmiSep2
      // 
      this.tsmiSep2.Name = "tsmiSep2";
      this.tsmiSep2.Size = new System.Drawing.Size(184, 6);
      // 
      // editToolStripMenuItem
      // 
      this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiCut,
            this.tsmiCopy,
            this.tsmiPaste,
            this.toolStripSeparator3,
            this.entitiesToolStripMenuItem,
            this.toolStripMenuItem3,
            this.levelSettingsToolStripMenuItem,
            this.toolStripSeparator6,
            this.tsmiPreferences});
      this.editToolStripMenuItem.Name = "editToolStripMenuItem";
      this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
      this.editToolStripMenuItem.Text = "&Edit";
      // 
      // entitiesToolStripMenuItem
      // 
      this.entitiesToolStripMenuItem.Name = "entitiesToolStripMenuItem";
      this.entitiesToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
      this.entitiesToolStripMenuItem.Text = "Entities...";
      // 
      // toolStripMenuItem3
      // 
      this.toolStripMenuItem3.Name = "toolStripMenuItem3";
      this.toolStripMenuItem3.Size = new System.Drawing.Size(152, 6);
      // 
      // levelSettingsToolStripMenuItem
      // 
      this.levelSettingsToolStripMenuItem.Name = "levelSettingsToolStripMenuItem";
      this.levelSettingsToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
      this.levelSettingsToolStripMenuItem.Text = "Level Settings...";
      // 
      // viewToolStripMenuItem
      // 
      this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiViewGrid,
            this.tsmiSep,
            this.tsmiViewTilesB,
            this.tsmiViewTilesF,
            this.tsmiViewMovement,
            this.tsmiViewFloor,
            this.toolStripSeparator4,
            this.tsmiZoom});
      this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
      this.viewToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
      this.viewToolStripMenuItem.Text = "&View";
      // 
      // tsmiViewTilesB
      // 
      this.tsmiViewTilesB.Checked = true;
      this.tsmiViewTilesB.CheckOnClick = true;
      this.tsmiViewTilesB.CheckState = System.Windows.Forms.CheckState.Checked;
      this.tsmiViewTilesB.Name = "tsmiViewTilesB";
      this.tsmiViewTilesB.Size = new System.Drawing.Size(165, 22);
      this.tsmiViewTilesB.Text = "Background Tiles";
      // 
      // tsmiViewTilesF
      // 
      this.tsmiViewTilesF.Checked = true;
      this.tsmiViewTilesF.CheckOnClick = true;
      this.tsmiViewTilesF.CheckState = System.Windows.Forms.CheckState.Checked;
      this.tsmiViewTilesF.Name = "tsmiViewTilesF";
      this.tsmiViewTilesF.Size = new System.Drawing.Size(165, 22);
      this.tsmiViewTilesF.Text = "Foreground Tiles";
      // 
      // tsmiViewMovement
      // 
      this.tsmiViewMovement.CheckOnClick = true;
      this.tsmiViewMovement.Name = "tsmiViewMovement";
      this.tsmiViewMovement.Size = new System.Drawing.Size(165, 22);
      this.tsmiViewMovement.Text = "Movement Info";
      // 
      // tsmiViewFloor
      // 
      this.tsmiViewFloor.CheckOnClick = true;
      this.tsmiViewFloor.Name = "tsmiViewFloor";
      this.tsmiViewFloor.Size = new System.Drawing.Size(165, 22);
      this.tsmiViewFloor.Text = "Floor Info";
      // 
      // tsMain
      // 
      this.tsMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbNew,
            this.tsbOpen,
            this.tsbSave,
            this.toolStripSeparator1,
            this.tsbCut,
            this.tsbCopy,
            this.tsbPaste,
            this.toolStripSeparator2,
            this.tsbSelection,
            this.tsbToolSingle,
            this.tsbToolFill,
            this.tsbToolReplace});
      this.tsMain.Location = new System.Drawing.Point(0, 24);
      this.tsMain.Name = "tsMain";
      this.tsMain.Size = new System.Drawing.Size(1008, 25);
      this.tsMain.TabIndex = 2;
      // 
      // cbMovementData
      // 
      this.cbMovementData.AutoSize = true;
      this.cbMovementData.Location = new System.Drawing.Point(6, 19);
      this.cbMovementData.Name = "cbMovementData";
      this.cbMovementData.Size = new System.Drawing.Size(74, 17);
      this.cbMovementData.TabIndex = 0;
      this.cbMovementData.Text = "Edit Mode";
      this.cbMovementData.UseVisualStyleBackColor = true;
      // 
      // cbFloorData
      // 
      this.cbFloorData.AutoSize = true;
      this.cbFloorData.Location = new System.Drawing.Point(6, 19);
      this.cbFloorData.Name = "cbFloorData";
      this.cbFloorData.Size = new System.Drawing.Size(74, 17);
      this.cbFloorData.TabIndex = 0;
      this.cbFloorData.Text = "Edit Mode";
      this.cbFloorData.UseVisualStyleBackColor = true;
      // 
      // groupBox1
      // 
      this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.groupBox1.Controls.Add(this.cbMovementData);
      this.groupBox1.Location = new System.Drawing.Point(507, 3);
      this.groupBox1.Name = "groupBox1";
      this.groupBox1.Size = new System.Drawing.Size(246, 94);
      this.groupBox1.TabIndex = 3;
      this.groupBox1.TabStop = false;
      this.groupBox1.Text = "Movement Data";
      // 
      // groupBox2
      // 
      this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.groupBox2.Controls.Add(this.cbFloorData);
      this.groupBox2.Location = new System.Drawing.Point(759, 3);
      this.groupBox2.Name = "groupBox2";
      this.groupBox2.Size = new System.Drawing.Size(246, 94);
      this.groupBox2.TabIndex = 4;
      this.groupBox2.TabStop = false;
      this.groupBox2.Text = "Floor Data";
      // 
      // tableLayoutPanel2
      // 
      this.tableLayoutPanel2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.tableLayoutPanel2.ColumnCount = 4;
      this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
      this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
      this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
      this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
      this.tableLayoutPanel2.Controls.Add(this.groupBox2, 3, 0);
      this.tableLayoutPanel2.Controls.Add(this.groupBox1, 2, 0);
      this.tableLayoutPanel2.Controls.Add(this.groupBox4, 0, 0);
      this.tableLayoutPanel2.Controls.Add(this.groupBox5, 1, 0);
      this.tableLayoutPanel2.Location = new System.Drawing.Point(0, 52);
      this.tableLayoutPanel2.Name = "tableLayoutPanel2";
      this.tableLayoutPanel2.RowCount = 1;
      this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 100F));
      this.tableLayoutPanel2.Size = new System.Drawing.Size(1008, 100);
      this.tableLayoutPanel2.TabIndex = 7;
      // 
      // groupBox4
      // 
      this.groupBox4.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.groupBox4.Controls.Add(this.cbEditBgTiles);
      this.groupBox4.Location = new System.Drawing.Point(3, 3);
      this.groupBox4.Name = "groupBox4";
      this.groupBox4.Size = new System.Drawing.Size(246, 94);
      this.groupBox4.TabIndex = 0;
      this.groupBox4.TabStop = false;
      this.groupBox4.Text = "Background Tiles";
      // 
      // cbEditBgTiles
      // 
      this.cbEditBgTiles.AutoSize = true;
      this.cbEditBgTiles.Location = new System.Drawing.Point(6, 20);
      this.cbEditBgTiles.Name = "cbEditBgTiles";
      this.cbEditBgTiles.Size = new System.Drawing.Size(74, 17);
      this.cbEditBgTiles.TabIndex = 0;
      this.cbEditBgTiles.Text = "Edit Mode";
      this.cbEditBgTiles.UseVisualStyleBackColor = true;
      // 
      // groupBox5
      // 
      this.groupBox5.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.groupBox5.Controls.Add(this.cbEditFgTiles);
      this.groupBox5.Location = new System.Drawing.Point(255, 3);
      this.groupBox5.Name = "groupBox5";
      this.groupBox5.Size = new System.Drawing.Size(246, 94);
      this.groupBox5.TabIndex = 1;
      this.groupBox5.TabStop = false;
      this.groupBox5.Text = "Foreground Tiles";
      // 
      // cbEditFgTiles
      // 
      this.cbEditFgTiles.AutoSize = true;
      this.cbEditFgTiles.Location = new System.Drawing.Point(7, 20);
      this.cbEditFgTiles.Name = "cbEditFgTiles";
      this.cbEditFgTiles.Size = new System.Drawing.Size(74, 17);
      this.cbEditFgTiles.TabIndex = 0;
      this.cbEditFgTiles.Text = "Edit Mode";
      this.cbEditFgTiles.UseVisualStyleBackColor = true;
      // 
      // tcMain
      // 
      this.tcMain.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.tcMain.Location = new System.Drawing.Point(-1, 154);
      this.tcMain.Name = "tcMain";
      this.tcMain.SelectedIndex = 0;
      this.tcMain.Size = new System.Drawing.Size(1012, 556);
      this.tcMain.TabIndex = 8;
      // 
      // tsmiViewGrid
      // 
      this.tsmiViewGrid.Checked = true;
      this.tsmiViewGrid.CheckOnClick = true;
      this.tsmiViewGrid.CheckState = System.Windows.Forms.CheckState.Checked;
      this.tsmiViewGrid.Name = "tsmiViewGrid";
      this.tsmiViewGrid.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.G)));
      this.tsmiViewGrid.Size = new System.Drawing.Size(165, 22);
      this.tsmiViewGrid.Text = "Grid";
      // 
      // tsmiSep
      // 
      this.tsmiSep.Name = "tsmiSep";
      this.tsmiSep.Size = new System.Drawing.Size(162, 6);
      // 
      // tsslCoords
      // 
      this.tsslCoords.Name = "tsslCoords";
      this.tsslCoords.Size = new System.Drawing.Size(43, 17);
      this.tsslCoords.Text = "Mouse";
      // 
      // toolStripSeparator1
      // 
      this.toolStripSeparator1.Name = "toolStripSeparator1";
      this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
      // 
      // toolStripSeparator2
      // 
      this.toolStripSeparator2.Name = "toolStripSeparator2";
      this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
      // 
      // toolStripSeparator3
      // 
      this.toolStripSeparator3.Name = "toolStripSeparator3";
      this.toolStripSeparator3.Size = new System.Drawing.Size(152, 6);
      // 
      // tsmiSaveAs
      // 
      this.tsmiSaveAs.Name = "tsmiSaveAs";
      this.tsmiSaveAs.Size = new System.Drawing.Size(187, 22);
      this.tsmiSaveAs.Text = "Save As...";
      // 
      // toolStripSeparator4
      // 
      this.toolStripSeparator4.Name = "toolStripSeparator4";
      this.toolStripSeparator4.Size = new System.Drawing.Size(162, 6);
      // 
      // toolStripSeparator6
      // 
      this.toolStripSeparator6.Name = "toolStripSeparator6";
      this.toolStripSeparator6.Size = new System.Drawing.Size(152, 6);
      // 
      // tsbNew
      // 
      this.tsbNew.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbNew.Image = global::mapeditor.Properties.Resources.document_new;
      this.tsbNew.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbNew.Name = "tsbNew";
      this.tsbNew.Size = new System.Drawing.Size(23, 22);
      this.tsbNew.Text = "New Level (Ctrl + N)";
      this.tsbNew.Click += new System.EventHandler(this.newLevel);
      // 
      // tsbOpen
      // 
      this.tsbOpen.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbOpen.Image = global::mapeditor.Properties.Resources.document_open;
      this.tsbOpen.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbOpen.Name = "tsbOpen";
      this.tsbOpen.Size = new System.Drawing.Size(23, 22);
      this.tsbOpen.Text = "Open Level (Ctrl + O)";
      this.tsbOpen.Click += new System.EventHandler(this.openLevel);
      // 
      // tsbSave
      // 
      this.tsbSave.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbSave.Image = global::mapeditor.Properties.Resources.document_save;
      this.tsbSave.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbSave.Name = "tsbSave";
      this.tsbSave.Size = new System.Drawing.Size(23, 22);
      this.tsbSave.Text = "Save Level (Ctrl + S)";
      // 
      // tsbCut
      // 
      this.tsbCut.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbCut.Image = global::mapeditor.Properties.Resources.edit_cut;
      this.tsbCut.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbCut.Name = "tsbCut";
      this.tsbCut.Size = new System.Drawing.Size(23, 22);
      this.tsbCut.Text = "Cut";
      this.tsbCut.Click += new System.EventHandler(this.cut);
      // 
      // tsbCopy
      // 
      this.tsbCopy.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbCopy.Image = global::mapeditor.Properties.Resources.edit_copy;
      this.tsbCopy.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbCopy.Name = "tsbCopy";
      this.tsbCopy.Size = new System.Drawing.Size(23, 22);
      this.tsbCopy.Text = "Copy";
      this.tsbCopy.Click += new System.EventHandler(this.copy);
      // 
      // tsbPaste
      // 
      this.tsbPaste.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbPaste.Image = global::mapeditor.Properties.Resources.edit_paste;
      this.tsbPaste.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbPaste.Name = "tsbPaste";
      this.tsbPaste.Size = new System.Drawing.Size(23, 22);
      this.tsbPaste.Text = "Paste";
      this.tsbPaste.Click += new System.EventHandler(this.paste);
      // 
      // tsbSelection
      // 
      this.tsbSelection.Checked = true;
      this.tsbSelection.CheckState = System.Windows.Forms.CheckState.Checked;
      this.tsbSelection.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbSelection.Image = ((System.Drawing.Image)(resources.GetObject("tsbSelection.Image")));
      this.tsbSelection.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbSelection.Name = "tsbSelection";
      this.tsbSelection.Size = new System.Drawing.Size(23, 22);
      this.tsbSelection.Text = "Selection";
      this.tsbSelection.Click += new System.EventHandler(this.tsbSelection_Click);
      // 
      // tsbToolSingle
      // 
      this.tsbToolSingle.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbToolSingle.Image = ((System.Drawing.Image)(resources.GetObject("tsbToolSingle.Image")));
      this.tsbToolSingle.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbToolSingle.Name = "tsbToolSingle";
      this.tsbToolSingle.Size = new System.Drawing.Size(23, 22);
      this.tsbToolSingle.Text = "Single Cell";
      this.tsbToolSingle.Click += new System.EventHandler(this.tsbToolSingle_Click);
      // 
      // tsbToolFill
      // 
      this.tsbToolFill.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbToolFill.Image = ((System.Drawing.Image)(resources.GetObject("tsbToolFill.Image")));
      this.tsbToolFill.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbToolFill.Name = "tsbToolFill";
      this.tsbToolFill.Size = new System.Drawing.Size(23, 22);
      this.tsbToolFill.Text = "Fill";
      this.tsbToolFill.Click += new System.EventHandler(this.tsbToolFill_Click);
      // 
      // tsbToolReplace
      // 
      this.tsbToolReplace.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbToolReplace.Image = ((System.Drawing.Image)(resources.GetObject("tsbToolReplace.Image")));
      this.tsbToolReplace.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbToolReplace.Name = "tsbToolReplace";
      this.tsbToolReplace.Size = new System.Drawing.Size(23, 22);
      this.tsbToolReplace.Text = "Replace";
      this.tsbToolReplace.Click += new System.EventHandler(this.tsbToolReplace_Click);
      // 
      // tsmiNew
      // 
      this.tsmiNew.Image = global::mapeditor.Properties.Resources.document_new;
      this.tsmiNew.Name = "tsmiNew";
      this.tsmiNew.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
      this.tsmiNew.Size = new System.Drawing.Size(187, 22);
      this.tsmiNew.Text = "New...";
      this.tsmiNew.Click += new System.EventHandler(this.newLevel);
      // 
      // tsmiOpen
      // 
      this.tsmiOpen.Image = global::mapeditor.Properties.Resources.document_open;
      this.tsmiOpen.Name = "tsmiOpen";
      this.tsmiOpen.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
      this.tsmiOpen.Size = new System.Drawing.Size(187, 22);
      this.tsmiOpen.Text = "Open...";
      this.tsmiOpen.Click += new System.EventHandler(this.openLevel);
      // 
      // tsmiSave
      // 
      this.tsmiSave.Image = global::mapeditor.Properties.Resources.document_save;
      this.tsmiSave.Name = "tsmiSave";
      this.tsmiSave.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
      this.tsmiSave.Size = new System.Drawing.Size(187, 22);
      this.tsmiSave.Text = "Save";
      // 
      // tsmiSaveAll
      // 
      this.tsmiSaveAll.Image = global::mapeditor.Properties.Resources.document_save_as;
      this.tsmiSaveAll.Name = "tsmiSaveAll";
      this.tsmiSaveAll.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.S)));
      this.tsmiSaveAll.Size = new System.Drawing.Size(187, 22);
      this.tsmiSaveAll.Text = "Save All";
      // 
      // tsmiExit
      // 
      this.tsmiExit.Image = global::mapeditor.Properties.Resources.process_stop;
      this.tsmiExit.Name = "tsmiExit";
      this.tsmiExit.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F4)));
      this.tsmiExit.Size = new System.Drawing.Size(187, 22);
      this.tsmiExit.Text = "Exit";
      this.tsmiExit.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
      // 
      // tsmiCut
      // 
      this.tsmiCut.Image = global::mapeditor.Properties.Resources.edit_cut;
      this.tsmiCut.Name = "tsmiCut";
      this.tsmiCut.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X)));
      this.tsmiCut.Size = new System.Drawing.Size(155, 22);
      this.tsmiCut.Text = "Cut";
      this.tsmiCut.Click += new System.EventHandler(this.cut);
      // 
      // tsmiCopy
      // 
      this.tsmiCopy.Image = global::mapeditor.Properties.Resources.edit_copy;
      this.tsmiCopy.Name = "tsmiCopy";
      this.tsmiCopy.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C)));
      this.tsmiCopy.Size = new System.Drawing.Size(155, 22);
      this.tsmiCopy.Text = "Copy";
      this.tsmiCopy.Click += new System.EventHandler(this.copy);
      // 
      // tsmiPaste
      // 
      this.tsmiPaste.Image = global::mapeditor.Properties.Resources.edit_paste;
      this.tsmiPaste.Name = "tsmiPaste";
      this.tsmiPaste.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
      this.tsmiPaste.Size = new System.Drawing.Size(155, 22);
      this.tsmiPaste.Text = "Paste";
      this.tsmiPaste.Click += new System.EventHandler(this.paste);
      // 
      // tsmiPreferences
      // 
      this.tsmiPreferences.Image = global::mapeditor.Properties.Resources.preferences_system;
      this.tsmiPreferences.Name = "tsmiPreferences";
      this.tsmiPreferences.Size = new System.Drawing.Size(155, 22);
      this.tsmiPreferences.Text = "Preferences...";
      // 
      // tsmiZoom
      // 
      this.tsmiZoom.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiZoomIn,
            this.tsmiZoomOut,
            this.toolStripSeparator5,
            this.tsmiZoomReset});
      this.tsmiZoom.Image = global::mapeditor.Properties.Resources.system_search;
      this.tsmiZoom.Name = "tsmiZoom";
      this.tsmiZoom.Size = new System.Drawing.Size(165, 22);
      this.tsmiZoom.Text = "Zoom";
      // 
      // tsmiZoomIn
      // 
      this.tsmiZoomIn.Name = "tsmiZoomIn";
      this.tsmiZoomIn.ShortcutKeys = System.Windows.Forms.Keys.Delete;
      this.tsmiZoomIn.Size = new System.Drawing.Size(177, 22);
      this.tsmiZoomIn.Text = "Zoom In";
      this.tsmiZoomIn.Click += new System.EventHandler(this.zoomIn);
      // 
      // tsmiZoomOut
      // 
      this.tsmiZoomOut.Name = "tsmiZoomOut";
      this.tsmiZoomOut.Size = new System.Drawing.Size(177, 22);
      this.tsmiZoomOut.Text = "Zoom Out";
      this.tsmiZoomOut.Click += new System.EventHandler(this.zoomOut);
      // 
      // toolStripSeparator5
      // 
      this.toolStripSeparator5.Name = "toolStripSeparator5";
      this.toolStripSeparator5.Size = new System.Drawing.Size(174, 6);
      // 
      // tsmiZoomReset
      // 
      this.tsmiZoomReset.Name = "tsmiZoomReset";
      this.tsmiZoomReset.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.D0)));
      this.tsmiZoomReset.Size = new System.Drawing.Size(177, 22);
      this.tsmiZoomReset.Text = "Reset Zoom";
      this.tsmiZoomReset.Click += new System.EventHandler(this.resetZoom);
      // 
      // MainForm
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(1008, 730);
      this.Controls.Add(this.tcMain);
      this.Controls.Add(this.tableLayoutPanel2);
      this.Controls.Add(this.tsMain);
      this.Controls.Add(this.ssMain);
      this.Controls.Add(this.msMain);
      this.KeyPreview = true;
      this.MainMenuStrip = this.msMain;
      this.Name = "MainForm";
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
      this.Text = "Leveleditor";
      this.ssMain.ResumeLayout(false);
      this.ssMain.PerformLayout();
      this.msMain.ResumeLayout(false);
      this.msMain.PerformLayout();
      this.tsMain.ResumeLayout(false);
      this.tsMain.PerformLayout();
      this.groupBox1.ResumeLayout(false);
      this.groupBox1.PerformLayout();
      this.groupBox2.ResumeLayout(false);
      this.groupBox2.PerformLayout();
      this.tableLayoutPanel2.ResumeLayout(false);
      this.groupBox4.ResumeLayout(false);
      this.groupBox4.PerformLayout();
      this.groupBox5.ResumeLayout(false);
      this.groupBox5.PerformLayout();
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    public System.Windows.Forms.StatusStrip ssMain;
    public System.Windows.Forms.MenuStrip msMain;
    public System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
    public System.Windows.Forms.ToolStrip tsMain;
    public System.Windows.Forms.ToolStripButton tsbNew;
    public System.Windows.Forms.ToolStripButton tsbOpen;
    public System.Windows.Forms.ToolStripButton tsbSave;
    public System.Windows.Forms.ToolStripMenuItem tsmiNew;
    public System.Windows.Forms.ToolStripMenuItem tsmiOpen;
    public System.Windows.Forms.ToolStripSeparator tsmiSep1;
    public System.Windows.Forms.ToolStripMenuItem tsmiSave;
    public System.Windows.Forms.ToolStripMenuItem tsmiSaveAs;
    public System.Windows.Forms.ToolStripMenuItem tsmiSaveAll;
    public System.Windows.Forms.ToolStripSeparator tsmiSep2;
    public System.Windows.Forms.ToolStripMenuItem tsmiExit;
    public System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
    public System.Windows.Forms.ToolStripMenuItem levelSettingsToolStripMenuItem;
    public System.Windows.Forms.CheckBox cbMovementData;
    public System.Windows.Forms.CheckBox cbFloorData;
    public System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
    public System.Windows.Forms.GroupBox groupBox1;
    public System.Windows.Forms.GroupBox groupBox2;
    public System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
    public System.Windows.Forms.GroupBox groupBox4;
    public System.Windows.Forms.CheckBox cbEditBgTiles;
    public System.Windows.Forms.GroupBox groupBox5;
    public System.Windows.Forms.CheckBox cbEditFgTiles;
    public System.Windows.Forms.ToolStripMenuItem entitiesToolStripMenuItem;
    public System.Windows.Forms.ToolStripSeparator toolStripMenuItem3;
    public System.Windows.Forms.TabControl tcMain;
    public System.Windows.Forms.ToolStripMenuItem tsmiViewTilesB;
    public System.Windows.Forms.ToolStripMenuItem tsmiViewTilesF;
    public System.Windows.Forms.ToolStripMenuItem tsmiViewMovement;
    public System.Windows.Forms.ToolStripMenuItem tsmiViewFloor;
    public System.Windows.Forms.ToolStripMenuItem tsmiViewGrid;
    public System.Windows.Forms.ToolStripSeparator tsmiSep;
    public System.Windows.Forms.ToolStripStatusLabel tsslCoords;
    public System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
    public System.Windows.Forms.ToolStripButton tsbCopy;
    public System.Windows.Forms.ToolStripButton tsbPaste;
    public System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
    public System.Windows.Forms.ToolStripButton tsbToolSingle;
    public System.Windows.Forms.ToolStripButton tsbToolFill;
    public System.Windows.Forms.ToolStripButton tsbToolReplace;
    public System.Windows.Forms.ToolStripButton tsbCut;
    public System.Windows.Forms.ToolStripButton tsbSelection;
    public System.Windows.Forms.ToolStripMenuItem tsmiCut;
    public System.Windows.Forms.ToolStripMenuItem tsmiCopy;
    public System.Windows.Forms.ToolStripMenuItem tsmiPaste;
    public System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
    public System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
    public System.Windows.Forms.ToolStripMenuItem tsmiZoom;
    public System.Windows.Forms.ToolStripMenuItem tsmiZoomIn;
    public System.Windows.Forms.ToolStripMenuItem tsmiZoomOut;
    public System.Windows.Forms.ToolStripMenuItem tsmiZoomReset;
    public System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
    public System.Windows.Forms.ToolStripSeparator toolStripSeparator6;
    public System.Windows.Forms.ToolStripMenuItem tsmiPreferences;
  }
}

