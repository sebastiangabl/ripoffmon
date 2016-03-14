using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.IO;
using SFML.Graphics;
using System.Drawing;

namespace mapeditor {

  public partial class MainForm : Form {

    static public MainForm Inst;

    public string rootDir = "D:\\Daten\\Dropbox\\C++ Files\\ripoffmon";
    public ushort tileSize = 16;
    public float defaultZoom = 1;
    public List<Texture> tileSets = new List<Texture>();
    public Level activeLevel = null;
    public ushort[,] clipboardTilesB, clipboardTilesF;
    public byte[,] clipboardMovement, clipboardFloors;

    NewLevelForm newLevelForm = new NewLevelForm();
    AboutBox aboutBox = new AboutBox();
    TileBox tileBox;

    public MainForm() {
      InitializeComponent();
      Inst = this;
      loadTileSets();
      tsmiZoomIn.ShortcutKeys = Keys.Control | Keys.Add;
      tsmiZoomOut.ShortcutKeys = Keys.Control | Keys.Subtract;
      tileBox = new TileBox();
      tileBox.changeTileSet(tileSets[1]);
      pTileBox.Controls.Add(tileBox);
      pTileBox.Width = 256 + SystemInformation.VerticalScrollBarWidth + SystemInformation.Border3DSize.Width * 2;
      tsmiZoomIn.Enabled = (defaultZoom < 5);
      tsmiZoomOut.Enabled = (defaultZoom > 1);
    }

    public void MainLoop() {
      while (Visible) {
        Application.DoEvents();

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
        tileBox.render();
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
        addLevel("", newLevelForm.width, newLevelForm.height, 1);
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
        addLevel(d.FileName, 0, 0, 1);
      }
    }

    private void addLevel(string fileName, ushort width = 0, ushort height = 0, byte tileset = 1) {
      TabPage t = new TabPage(Path.GetFileName(fileName) != "" ? Path.GetFileName(fileName) : ("new" + tcMain.TabCount));
      Level l = new Level(fileName, width, height, tileset);
      t.AutoScroll = true;
      t.Scroll += tabPanelScroll;
      t.Controls.Add(l);
      t.Enter += changeActiveLevel;
      t.HandleCreated += changeActiveLevel;
      tcMain.TabPages.Add(t);
      tcMain.SelectedIndex = tcMain.TabPages.Count - 1;
    }

    private void changeActiveLevel(object sender, EventArgs e) {
      TabPage s = (TabPage)sender;
      activeLevel = (Level)s.Controls[0];
      if (activeLevel != null) {
        tileBox.changeTileSet(tileSets[activeLevel.tileSet]);
      }
    }

    private void tsbSelection_Click(object sender, EventArgs e) {
      tsbToolSelect.Checked = true;
      tsbToolSingle.Checked = false;
      tsbToolFill.Checked = false;
      tsbToolReplace.Checked = false;
    }

    private void tsbToolSingle_Click(object sender, EventArgs e) {
      tsbToolSelect.Checked = false;
      tsbToolSingle.Checked = true;
      tsbToolFill.Checked = false;
      tsbToolReplace.Checked = false;
    }

    private void tsbToolFill_Click(object sender, EventArgs e) {
      tsbToolSelect.Checked = false;
      tsbToolSingle.Checked = false;
      tsbToolFill.Checked = true;
      tsbToolReplace.Checked = false;
    }

    private void tsbToolReplace_Click(object sender, EventArgs e) {
      tsbToolSelect.Checked = false;
      tsbToolSingle.Checked = false;
      tsbToolFill.Checked = false;
      tsbToolReplace.Checked = true;
    }

    private void cut(object sender, EventArgs e) {

    }

    private void copy(object sender, EventArgs e) {
      Rectangle selection = activeLevel.selection;
      clipboardMovement = new byte[selection.Width, selection.Height];
      clipboardFloors = new byte[selection.Width, selection.Height];
      clipboardTilesB = new ushort[selection.Width, selection.Height];
      clipboardTilesF = new ushort[selection.Width, selection.Height];
      for (int x = 0; x < selection.Width; x++) {
        for (int y = 0; y < selection.Height; y++) {
          clipboardMovement[x, y] = activeLevel.dataMovement[selection.X + x, selection.Y + y];
          clipboardFloors[x, y] = activeLevel.dataFloor[selection.X + x, selection.Y + y];
          clipboardTilesB[x, y] = activeLevel.dataTilesB[selection.X + x, selection.Y + y];
          clipboardTilesF[x, y] = activeLevel.dataTilesF[selection.X + x, selection.Y + y];
        }
      }
    }

    private void paste(object sender, EventArgs e) {
      Rectangle selection = activeLevel.selection;
      if (selection.Width == 1 && selection.Height == 1) {
        // If no selection, paste whole clipboard
        selection.Width = clipboardMovement.GetLength(0);
        selection.Height = clipboardMovement.GetLength(1);
      }
      int cw = clipboardMovement.GetLength(0);
      int ch = clipboardMovement.GetLength(1);
      selection.Width = Math.Min(selection.Width, activeLevel.width - selection.X);
      selection.Height = Math.Min(selection.Height, activeLevel.height - selection.Y);
      for (int x = 0; x < selection.Width; x++) {
        for (int y = 0; y < selection.Height; y++) {
          activeLevel.dataMovement[selection.X + x, selection.Y + y] = clipboardMovement[x % cw, y % ch];
          activeLevel.dataFloor[selection.X + x, selection.Y + y] = clipboardFloors[x % cw, y % ch];
          activeLevel.dataTilesB[selection.X + x, selection.Y + y] = clipboardTilesB[x % cw, y % ch];
          activeLevel.dataTilesF[selection.X + x, selection.Y + y] = clipboardTilesF[x % cw, y % ch];
        }
      }
      activeLevel.selection = selection;
    }

    private void resetZoom(object sender, EventArgs e) {
      activeLevel.setZoom(defaultZoom);
      tsmiZoomIn.Enabled = (defaultZoom < 5);
      tsmiZoomOut.Enabled = (defaultZoom > 1);
    }

    private void zoomIn(object sender, EventArgs e) {
      activeLevel.setZoom(activeLevel.scale + 0.5f);
      tsmiZoomIn.Enabled = (activeLevel.scale < 5);
      tsmiZoomOut.Enabled = true;
    }

    private void zoomOut(object sender, EventArgs e) {
      activeLevel.setZoom(activeLevel.scale - 0.5f);
      tsmiZoomIn.Enabled = true;
      tsmiZoomOut.Enabled = (activeLevel.scale > 1);
    }

    private void aboutToolStripMenuItem_Click(object sender, EventArgs e) {
      aboutBox.ShowDialog();
    }

    private void refreshOnScroll(object sender, ScrollEventArgs e) {
      tileBox.render();
    }

    private void refreshOnSizeChange(object sender, EventArgs e) {
      tileBox.render();
    }

    protected override void OnResize(EventArgs e) {
      base.OnResize(e);
      if (activeLevel != null) {
        activeLevel.render();
      }
    }

    private void tabPanelScroll(object sender, ScrollEventArgs e) {
      if (activeLevel != null) {
        activeLevel.render();
      }
    }
  }
}
