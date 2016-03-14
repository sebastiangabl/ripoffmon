using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.IO;
using SFML.Graphics;

namespace mapeditor {

  public partial class MainForm : Form {

    static public MainForm Inst;

    public string rootDir = "D:\\Daten\\Dropbox\\C++ Files\\ripoffmon";
    public ushort tileSize = 16;
    public float defaultZoom = (float)1;
    public List<Texture> tileSets = new List<Texture>();
    public Level activeLevel = null;
    public ushort[] clipboardTilesB, clipboardTilesF;
    public byte[] clipboardMovement, clipboardFloors;

    NewLevelForm newLevelForm = new NewLevelForm();

    public MainForm() {
      InitializeComponent();
      Inst = this;
      loadTileSets();
      tsmiZoomIn.ShortcutKeys = Keys.Control | Keys.Add;
      tsmiZoomOut.ShortcutKeys = Keys.Control | Keys.Subtract;
    }

    public void MainLoop() {
      while (Visible) {
        Application.DoEvents();

        if (tcMain.SelectedTab != null && tcMain.SelectedTab.Controls.Count > 0) {
          activeLevel = (Level)tcMain.SelectedTab.Controls[0];
        } else {
          activeLevel = null;
        }

        tsbSave.Enabled = tsmiSave.Enabled  = activeLevel != null;
        tsmiSaveAs.Enabled = activeLevel != null;
        tsmiSaveAll.Enabled = activeLevel != null;
        tsbCut.Enabled = tsmiCut.Enabled = (activeLevel != null && (activeLevel.selection.Width > 1 || activeLevel.selection.Height > 1));
        tsbCopy.Enabled = tsmiCopy.Enabled = (activeLevel != null && (activeLevel.selection.Width > 1 || activeLevel.selection.Height > 1));
        tsbPaste.Enabled = tsmiPaste.Enabled = (clipboardFloors != null || clipboardMovement != null || clipboardTilesB != null || clipboardTilesF != null);
        tsmiZoom.Enabled = activeLevel != null;

        if (activeLevel != null) {
          activeLevel.render();
          
        }
      }
    }

    private void loadTileSets() {
      string[] files = Directory.GetFiles(rootDir + "\\tilesets", "*.png");
      foreach (var f in files) {
        Texture tex = new Texture(f);
        tileSets.Add(tex);
      }
    }

    private void newLevel(object sender, EventArgs e) {
      newLevelForm.ShowDialog();
      if (!newLevelForm.aborted) {
        TabPage t = new TabPage("new");
        t.AutoScroll = true;
        t.Controls.Add(new Level("", newLevelForm.width, newLevelForm.height, 1));
        tcMain.TabPages.Add(t);
        tcMain.SelectedIndex = tcMain.TabPages.Count - 1;
      }
    }

    private void exitToolStripMenuItem_Click(object sender, EventArgs e) {
      Close();
    }

    private void openLevel(object sender, EventArgs e) {
      OpenFileDialog d = new OpenFileDialog();
      d.Filter = "Level files (*.dat)|*.dat";
      d.InitialDirectory = rootDir + "\\leveldata";
      d.ShowDialog();
      if (File.Exists(d.FileName)) {
        if (Path.GetExtension(d.FileName) != ".dat") {
          MessageBox.Show("This is not a level file!");
          return;
        }
        TabPage t = new TabPage(Path.GetFileName(d.FileName));
        t.AutoScroll = true;
        t.Controls.Add(new Level(d.FileName, 0, 0, 1));
        tcMain.TabPages.Add(t);
        tcMain.SelectedIndex = tcMain.TabPages.Count - 1;
      }
    }

    private void tsbSelection_Click(object sender, EventArgs e) {
      tsbSelection.Checked = true;
      tsbToolSingle.Checked = false;
      tsbToolFill.Checked = false;
      tsbToolReplace.Checked = false;
    }

    private void tsbToolSingle_Click(object sender, EventArgs e) {
      tsbSelection.Checked = false;
      tsbToolSingle.Checked = true;
      tsbToolFill.Checked = false;
      tsbToolReplace.Checked = false;
    }

    private void tsbToolFill_Click(object sender, EventArgs e) {
      tsbSelection.Checked = false;
      tsbToolSingle.Checked = false;
      tsbToolFill.Checked = true;
      tsbToolReplace.Checked = false;
    }

    private void tsbToolReplace_Click(object sender, EventArgs e) {
      tsbSelection.Checked = false;
      tsbToolSingle.Checked = false;
      tsbToolFill.Checked = false;
      tsbToolReplace.Checked = true;
    }

    private void cut(object sender, EventArgs e) {

    }

    private void copy(object sender, EventArgs e) {

    }

    private void resetZoom(object sender, EventArgs e) {
      activeLevel.setZoom(defaultZoom);
    }

    private void zoomIn(object sender, EventArgs e) {
      activeLevel.setZoom(activeLevel.scale + 0.5f);
    }

    private void zoomOut(object sender, EventArgs e) {
      activeLevel.setZoom(activeLevel.scale - 0.5f);
    }

    private void paste(object sender, EventArgs e) {

    }

    protected override void OnResize(EventArgs e) {
      base.OnResize(e);
      if (activeLevel != null) {
        activeLevel.render();
      }
    }
  }
}
