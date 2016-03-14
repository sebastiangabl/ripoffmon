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
      this.ssMain = new System.Windows.Forms.StatusStrip();
      this.tsslCoords = new System.Windows.Forms.ToolStripStatusLabel();
      this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
      this.msMain = new System.Windows.Forms.MenuStrip();
      this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiNew = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiOpen = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiSep1 = new System.Windows.Forms.ToolStripSeparator();
      this.tsmiSave = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiSaveAs = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiSaveAll = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiSep2 = new System.Windows.Forms.ToolStripSeparator();
      this.tsmiExit = new System.Windows.Forms.ToolStripMenuItem();
      this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiCut = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiCopy = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiPaste = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
      this.entitiesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripSeparator();
      this.levelSettingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.resizeLevelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
      this.tsmiPreferences = new System.Windows.Forms.ToolStripMenuItem();
      this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiViewGrid = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiSep = new System.Windows.Forms.ToolStripSeparator();
      this.tsmiViewTilesB = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiViewTilesF = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiViewMovement = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiViewFloor = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
      this.tsmiZoom = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiZoomIn = new System.Windows.Forms.ToolStripMenuItem();
      this.tsmiZoomOut = new System.Windows.Forms.ToolStripMenuItem();
      this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
      this.tsmiZoomReset = new System.Windows.Forms.ToolStripMenuItem();
      this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.tsMain = new System.Windows.Forms.ToolStrip();
      this.tsbNew = new System.Windows.Forms.ToolStripButton();
      this.tsbOpen = new System.Windows.Forms.ToolStripButton();
      this.tsbSave = new System.Windows.Forms.ToolStripButton();
      this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
      this.tsbCut = new System.Windows.Forms.ToolStripButton();
      this.tsbCopy = new System.Windows.Forms.ToolStripButton();
      this.tsbPaste = new System.Windows.Forms.ToolStripButton();
      this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
      this.tsbToolSelect = new System.Windows.Forms.ToolStripButton();
      this.tsbToolSingle = new System.Windows.Forms.ToolStripButton();
      this.tsbToolFill = new System.Windows.Forms.ToolStripButton();
      this.tsbToolReplace = new System.Windows.Forms.ToolStripButton();
      this.tcMain = new System.Windows.Forms.TabControl();
      this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
      this.gbToolSettings = new System.Windows.Forms.GroupBox();
      this.pTileBox = new System.Windows.Forms.Panel();
      this.ssMain.SuspendLayout();
      this.msMain.SuspendLayout();
      this.tsMain.SuspendLayout();
      this.tableLayoutPanel1.SuspendLayout();
      this.gbToolSettings.SuspendLayout();
      this.SuspendLayout();
      // 
      // ssMain
      // 
      this.ssMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsslCoords,
            this.toolStripStatusLabel1});
      this.ssMain.Location = new System.Drawing.Point(0, 706);
      this.ssMain.Name = "ssMain";
      this.ssMain.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
      this.ssMain.Size = new System.Drawing.Size(1264, 24);
      this.ssMain.TabIndex = 0;
      // 
      // tsslCoords
      // 
      this.tsslCoords.AutoSize = false;
      this.tsslCoords.Name = "tsslCoords";
      this.tsslCoords.Size = new System.Drawing.Size(40, 19);
      this.tsslCoords.Text = "0/0";
      // 
      // toolStripStatusLabel1
      // 
      this.toolStripStatusLabel1.BorderSides = System.Windows.Forms.ToolStripStatusLabelBorderSides.Left;
      this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
      this.toolStripStatusLabel1.Size = new System.Drawing.Size(47, 19);
      this.toolStripStatusLabel1.Text = "Mouse";
      // 
      // msMain
      // 
      this.msMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.viewToolStripMenuItem,
            this.helpToolStripMenuItem});
      this.msMain.Location = new System.Drawing.Point(0, 0);
      this.msMain.Name = "msMain";
      this.msMain.Size = new System.Drawing.Size(1264, 24);
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
      // tsmiNew
      // 
      this.tsmiNew.Image = global::mapeditor.Properties.Resources._new;
      this.tsmiNew.Name = "tsmiNew";
      this.tsmiNew.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
      this.tsmiNew.Size = new System.Drawing.Size(187, 22);
      this.tsmiNew.Text = "New...";
      this.tsmiNew.Click += new System.EventHandler(this.newLevel);
      // 
      // tsmiOpen
      // 
      this.tsmiOpen.Image = global::mapeditor.Properties.Resources.open;
      this.tsmiOpen.Name = "tsmiOpen";
      this.tsmiOpen.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
      this.tsmiOpen.Size = new System.Drawing.Size(187, 22);
      this.tsmiOpen.Text = "Open...";
      this.tsmiOpen.Click += new System.EventHandler(this.openLevel);
      // 
      // tsmiSep1
      // 
      this.tsmiSep1.Name = "tsmiSep1";
      this.tsmiSep1.Size = new System.Drawing.Size(184, 6);
      // 
      // tsmiSave
      // 
      this.tsmiSave.Image = global::mapeditor.Properties.Resources.save;
      this.tsmiSave.Name = "tsmiSave";
      this.tsmiSave.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
      this.tsmiSave.Size = new System.Drawing.Size(187, 22);
      this.tsmiSave.Text = "Save";
      // 
      // tsmiSaveAs
      // 
      this.tsmiSaveAs.Name = "tsmiSaveAs";
      this.tsmiSaveAs.Size = new System.Drawing.Size(187, 22);
      this.tsmiSaveAs.Text = "Save As...";
      // 
      // tsmiSaveAll
      // 
      this.tsmiSaveAll.Image = global::mapeditor.Properties.Resources.save_all;
      this.tsmiSaveAll.Name = "tsmiSaveAll";
      this.tsmiSaveAll.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.S)));
      this.tsmiSaveAll.Size = new System.Drawing.Size(187, 22);
      this.tsmiSaveAll.Text = "Save All";
      // 
      // tsmiSep2
      // 
      this.tsmiSep2.Name = "tsmiSep2";
      this.tsmiSep2.Size = new System.Drawing.Size(184, 6);
      // 
      // tsmiExit
      // 
      this.tsmiExit.Image = global::mapeditor.Properties.Resources.close;
      this.tsmiExit.Name = "tsmiExit";
      this.tsmiExit.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F4)));
      this.tsmiExit.Size = new System.Drawing.Size(187, 22);
      this.tsmiExit.Text = "Exit";
      this.tsmiExit.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
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
            this.resizeLevelToolStripMenuItem,
            this.toolStripSeparator6,
            this.tsmiPreferences});
      this.editToolStripMenuItem.Name = "editToolStripMenuItem";
      this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
      this.editToolStripMenuItem.Text = "&Edit";
      // 
      // tsmiCut
      // 
      this.tsmiCut.Image = global::mapeditor.Properties.Resources.cut;
      this.tsmiCut.Name = "tsmiCut";
      this.tsmiCut.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X)));
      this.tsmiCut.Size = new System.Drawing.Size(155, 22);
      this.tsmiCut.Text = "Cut";
      this.tsmiCut.Click += new System.EventHandler(this.cut);
      // 
      // tsmiCopy
      // 
      this.tsmiCopy.Image = global::mapeditor.Properties.Resources.copy;
      this.tsmiCopy.Name = "tsmiCopy";
      this.tsmiCopy.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C)));
      this.tsmiCopy.Size = new System.Drawing.Size(155, 22);
      this.tsmiCopy.Text = "Copy";
      this.tsmiCopy.Click += new System.EventHandler(this.copy);
      // 
      // tsmiPaste
      // 
      this.tsmiPaste.Image = global::mapeditor.Properties.Resources.paste;
      this.tsmiPaste.Name = "tsmiPaste";
      this.tsmiPaste.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
      this.tsmiPaste.Size = new System.Drawing.Size(155, 22);
      this.tsmiPaste.Text = "Paste";
      this.tsmiPaste.Click += new System.EventHandler(this.paste);
      // 
      // toolStripSeparator3
      // 
      this.toolStripSeparator3.Name = "toolStripSeparator3";
      this.toolStripSeparator3.Size = new System.Drawing.Size(152, 6);
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
      // resizeLevelToolStripMenuItem
      // 
      this.resizeLevelToolStripMenuItem.Name = "resizeLevelToolStripMenuItem";
      this.resizeLevelToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
      this.resizeLevelToolStripMenuItem.Text = "Resize Level...";
      // 
      // toolStripSeparator6
      // 
      this.toolStripSeparator6.Name = "toolStripSeparator6";
      this.toolStripSeparator6.Size = new System.Drawing.Size(152, 6);
      // 
      // tsmiPreferences
      // 
      this.tsmiPreferences.Image = global::mapeditor.Properties.Resources.settings;
      this.tsmiPreferences.Name = "tsmiPreferences";
      this.tsmiPreferences.Size = new System.Drawing.Size(155, 22);
      this.tsmiPreferences.Text = "Preferences...";
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
      // toolStripSeparator4
      // 
      this.toolStripSeparator4.Name = "toolStripSeparator4";
      this.toolStripSeparator4.Size = new System.Drawing.Size(162, 6);
      // 
      // tsmiZoom
      // 
      this.tsmiZoom.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiZoomIn,
            this.tsmiZoomOut,
            this.toolStripSeparator5,
            this.tsmiZoomReset});
      this.tsmiZoom.Image = global::mapeditor.Properties.Resources.zoom;
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
      // helpToolStripMenuItem
      // 
      this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
      this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
      this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
      this.helpToolStripMenuItem.Text = "&Help";
      // 
      // aboutToolStripMenuItem
      // 
      this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
      this.aboutToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
      this.aboutToolStripMenuItem.Text = "About";
      this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
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
            this.tsbToolSelect,
            this.tsbToolSingle,
            this.tsbToolFill,
            this.tsbToolReplace});
      this.tsMain.Location = new System.Drawing.Point(0, 24);
      this.tsMain.Name = "tsMain";
      this.tsMain.Size = new System.Drawing.Size(1264, 25);
      this.tsMain.TabIndex = 2;
      // 
      // tsbNew
      // 
      this.tsbNew.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbNew.Image = global::mapeditor.Properties.Resources._new;
      this.tsbNew.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbNew.Name = "tsbNew";
      this.tsbNew.Size = new System.Drawing.Size(23, 22);
      this.tsbNew.Text = "New Level (Ctrl + N)";
      this.tsbNew.Click += new System.EventHandler(this.newLevel);
      // 
      // tsbOpen
      // 
      this.tsbOpen.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbOpen.Image = global::mapeditor.Properties.Resources.open;
      this.tsbOpen.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbOpen.Name = "tsbOpen";
      this.tsbOpen.Size = new System.Drawing.Size(23, 22);
      this.tsbOpen.Text = "Open Level (Ctrl + O)";
      this.tsbOpen.Click += new System.EventHandler(this.openLevel);
      // 
      // tsbSave
      // 
      this.tsbSave.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbSave.Image = global::mapeditor.Properties.Resources.save;
      this.tsbSave.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbSave.Name = "tsbSave";
      this.tsbSave.Size = new System.Drawing.Size(23, 22);
      this.tsbSave.Text = "Save Level (Ctrl + S)";
      // 
      // toolStripSeparator1
      // 
      this.toolStripSeparator1.Name = "toolStripSeparator1";
      this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
      // 
      // tsbCut
      // 
      this.tsbCut.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbCut.Image = global::mapeditor.Properties.Resources.cut;
      this.tsbCut.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbCut.Name = "tsbCut";
      this.tsbCut.Size = new System.Drawing.Size(23, 22);
      this.tsbCut.Text = "Cut";
      this.tsbCut.Click += new System.EventHandler(this.cut);
      // 
      // tsbCopy
      // 
      this.tsbCopy.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbCopy.Image = global::mapeditor.Properties.Resources.copy;
      this.tsbCopy.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbCopy.Name = "tsbCopy";
      this.tsbCopy.Size = new System.Drawing.Size(23, 22);
      this.tsbCopy.Text = "Copy";
      this.tsbCopy.Click += new System.EventHandler(this.copy);
      // 
      // tsbPaste
      // 
      this.tsbPaste.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbPaste.Image = global::mapeditor.Properties.Resources.paste;
      this.tsbPaste.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbPaste.Name = "tsbPaste";
      this.tsbPaste.Size = new System.Drawing.Size(23, 22);
      this.tsbPaste.Text = "Paste";
      this.tsbPaste.Click += new System.EventHandler(this.paste);
      // 
      // toolStripSeparator2
      // 
      this.toolStripSeparator2.Name = "toolStripSeparator2";
      this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
      // 
      // tsbToolSelect
      // 
      this.tsbToolSelect.Checked = true;
      this.tsbToolSelect.CheckState = System.Windows.Forms.CheckState.Checked;
      this.tsbToolSelect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbToolSelect.Image = global::mapeditor.Properties.Resources.select;
      this.tsbToolSelect.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbToolSelect.Name = "tsbToolSelect";
      this.tsbToolSelect.Size = new System.Drawing.Size(23, 22);
      this.tsbToolSelect.Text = "Selection Tool";
      this.tsbToolSelect.Click += new System.EventHandler(this.tsbSelection_Click);
      // 
      // tsbToolSingle
      // 
      this.tsbToolSingle.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbToolSingle.Image = global::mapeditor.Properties.Resources.single;
      this.tsbToolSingle.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbToolSingle.Name = "tsbToolSingle";
      this.tsbToolSingle.Size = new System.Drawing.Size(23, 22);
      this.tsbToolSingle.Text = "Pen Tool";
      this.tsbToolSingle.Click += new System.EventHandler(this.tsbToolSingle_Click);
      // 
      // tsbToolFill
      // 
      this.tsbToolFill.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbToolFill.Image = global::mapeditor.Properties.Resources.fill;
      this.tsbToolFill.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbToolFill.Name = "tsbToolFill";
      this.tsbToolFill.Size = new System.Drawing.Size(23, 22);
      this.tsbToolFill.Text = "Fill Tool";
      this.tsbToolFill.Click += new System.EventHandler(this.tsbToolFill_Click);
      // 
      // tsbToolReplace
      // 
      this.tsbToolReplace.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
      this.tsbToolReplace.Image = global::mapeditor.Properties.Resources.replace;
      this.tsbToolReplace.ImageTransparentColor = System.Drawing.Color.Magenta;
      this.tsbToolReplace.Name = "tsbToolReplace";
      this.tsbToolReplace.Size = new System.Drawing.Size(23, 22);
      this.tsbToolReplace.Text = "Replace Tool";
      this.tsbToolReplace.Click += new System.EventHandler(this.tsbToolReplace_Click);
      // 
      // tcMain
      // 
      this.tcMain.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.tcMain.Location = new System.Drawing.Point(277, 3);
      this.tcMain.Name = "tcMain";
      this.tcMain.SelectedIndex = 0;
      this.tcMain.Size = new System.Drawing.Size(984, 645);
      this.tcMain.TabIndex = 8;
      // 
      // tableLayoutPanel1
      // 
      this.tableLayoutPanel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.tableLayoutPanel1.ColumnCount = 2;
      this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
      this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutPanel1.Controls.Add(this.tcMain, 1, 0);
      this.tableLayoutPanel1.Controls.Add(this.gbToolSettings, 0, 0);
      this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 52);
      this.tableLayoutPanel1.Name = "tableLayoutPanel1";
      this.tableLayoutPanel1.RowCount = 1;
      this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutPanel1.Size = new System.Drawing.Size(1264, 651);
      this.tableLayoutPanel1.TabIndex = 9;
      // 
      // gbToolSettings
      // 
      this.gbToolSettings.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
      this.gbToolSettings.AutoSize = true;
      this.gbToolSettings.Controls.Add(this.pTileBox);
      this.gbToolSettings.Location = new System.Drawing.Point(3, 3);
      this.gbToolSettings.Name = "gbToolSettings";
      this.gbToolSettings.Size = new System.Drawing.Size(268, 645);
      this.gbToolSettings.TabIndex = 9;
      this.gbToolSettings.TabStop = false;
      this.gbToolSettings.Text = "Tool Settings";
      // 
      // pTileBox
      // 
      this.pTileBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
      this.pTileBox.AutoScroll = true;
      this.pTileBox.BackColor = System.Drawing.Color.Black;
      this.pTileBox.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
      this.pTileBox.Location = new System.Drawing.Point(6, 34);
      this.pTileBox.MinimumSize = new System.Drawing.Size(256, 192);
      this.pTileBox.Name = "pTileBox";
      this.pTileBox.Size = new System.Drawing.Size(256, 192);
      this.pTileBox.TabIndex = 0;
      this.pTileBox.Scroll += new System.Windows.Forms.ScrollEventHandler(this.refreshOnScroll);
      this.pTileBox.SizeChanged += new System.EventHandler(this.refreshOnSizeChange);
      // 
      // MainForm
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(1264, 730);
      this.Controls.Add(this.tableLayoutPanel1);
      this.Controls.Add(this.tsMain);
      this.Controls.Add(this.ssMain);
      this.Controls.Add(this.msMain);
      this.DoubleBuffered = true;
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
      this.tableLayoutPanel1.ResumeLayout(false);
      this.tableLayoutPanel1.PerformLayout();
      this.gbToolSettings.ResumeLayout(false);
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
    public System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
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
    public System.Windows.Forms.ToolStripButton tsbToolSelect;
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
    private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
    private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
    private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
    private System.Windows.Forms.ToolStripMenuItem resizeLevelToolStripMenuItem;
    private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
    public System.Windows.Forms.Panel pTileBox;
    public System.Windows.Forms.GroupBox gbToolSettings;
  }
}

