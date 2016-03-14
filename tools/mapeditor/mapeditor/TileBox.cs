using SFML.System;
using SFML.Graphics;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace mapeditor {
  public partial class TileBox : Control {
    public RenderWindow win;
    public Texture tileset;

    Vertex[] tilegrid;
    uint wtiles;

    public TileBox() {
      Size = new System.Drawing.Size(256, 1024);
      win = new RenderWindow(Handle);
      wtiles = (uint)Size.Width / MainForm.Inst.tileSize;
    }

    public void render() {
      win.DispatchEvents();
      win.Clear(SFML.Graphics.Color.Black);
      //Sprite s = new Sprite(tileset);
      win.Draw(tilegrid, PrimitiveType.Quads, new RenderStates(tileset));
      //win.Draw(s);
      win.Display();
    }

    public void changeTileSet(Texture ts) {
      tileset = ts;
      uint tiles = (ts.Size.X / MainForm.Inst.tileSize) * (ts.Size.Y / MainForm.Inst.tileSize);
      setTilegrid(tiles);
      Size = new System.Drawing.Size(Size.Width, (int)(tiles / wtiles) * MainForm.Inst.tileSize);
      win.SetView(new SFML.Graphics.View(new FloatRect(0, 0, Width, Height)));
    }

    public void setTilegrid(uint tiles) {
      tilegrid = new Vertex[tiles * 4];
      for (int i = 0; i < tiles; i++) {
        uint x = (uint)(i % wtiles) * MainForm.Inst.tileSize;
        uint y = (uint)(i / wtiles) * MainForm.Inst.tileSize;
        tilegrid[i * 4 + 0].Position = new Vector2f(x, y);
        tilegrid[i * 4 + 1].Position = new Vector2f(x, y + MainForm.Inst.tileSize);
        tilegrid[i * 4 + 2].Position = new Vector2f(x + MainForm.Inst.tileSize, y + MainForm.Inst.tileSize);
        tilegrid[i * 4 + 3].Position = new Vector2f(x + MainForm.Inst.tileSize, y);
        uint tx = (uint)(i % (tileset.Size.X / MainForm.Inst.tileSize)) * MainForm.Inst.tileSize;
        uint ty = (uint)(i / (tileset.Size.X / MainForm.Inst.tileSize)) * MainForm.Inst.tileSize;
        tilegrid[i * 4 + 0].TexCoords = new Vector2f(tx, ty);
        tilegrid[i * 4 + 1].TexCoords = new Vector2f(tx, ty + MainForm.Inst.tileSize);
        tilegrid[i * 4 + 2].TexCoords = new Vector2f(tx + MainForm.Inst.tileSize, ty + MainForm.Inst.tileSize);
        tilegrid[i * 4 + 3].TexCoords = new Vector2f(tx + MainForm.Inst.tileSize, ty);
        tilegrid[i * 4 + 0].Color = tilegrid[i * 4 + 1].Color = tilegrid[i * 4 + 2].Color = tilegrid[i * 4 + 3].Color = Color.White;
      }
    }

    protected override void OnResize(EventArgs e) {
      base.OnResize(e);
    }

    protected override void OnPaint(PaintEventArgs e) {
    }

    protected override void OnPaintBackground(PaintEventArgs pevent) {
    }
  }
}
