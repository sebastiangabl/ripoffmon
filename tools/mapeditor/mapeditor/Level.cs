using System;
using System.Drawing;
using System.Windows.Forms;
using System.IO;
using SFML.System;
using SFML.Graphics;
using SFML.Window;

namespace mapeditor {
  public partial class Level : Control {
    public float scale;
    public bool changed = false;
    public string savedAs;
    public RenderWindow win;
    public Vertex[][] vertices;
    public Vertex[] grid;
    public Rectangle selection;

    public ushort width, height;
    public ushort[] neighbourID = new ushort[4];
    public short[] neighbourOffset = new short[4];
    public byte flags, tileSet, music;
    public byte[,] dataMovement, dataFloor;
    public ushort[,] dataTilesB, dataTilesF;
    public ushort[,] outTiles = new ushort[2, 4];

    public Level(string name, ushort w, ushort h, byte tileset) {
      savedAs = name;
      scale = MainForm.Inst.defaultZoom;
      if (savedAs == "") {
        width = w;
        height = h;
        tileSet = tileset;
        dataMovement = new byte[width, height];
        dataFloor = new byte[width, height];
        dataTilesB = new ushort[width, height];
        dataTilesF = new ushort[width, height];
        for (int x = 0; x < width; x++) {
          for (int y = 0; y < height; y++) {
            dataMovement[x, y] = 1;
            dataFloor[x, y] = 2;
            dataTilesB[x, y] = 1;
            dataTilesF[x, y] = 0;
          }
        }
      } else {
        Load(savedAs);
      }
      Size = new Size(width * MainForm.Inst.tileSize, height * MainForm.Inst.tileSize);
      win = new RenderWindow(Handle);
      win.Size = new Vector2u((uint)(width * MainForm.Inst.tileSize * scale), (uint)(height * MainForm.Inst.tileSize * scale));
      vertices = new Vertex[3][];
      grid = new Vertex[width * 2 + height * 2];
      selection.Width = 1;
      selection.Height = 1;
      setupVertices();
    }

    private void setupVertices() {
      for (int i = 0; i < 3; i++) {
        vertices[i] = new Vertex[(uint)width * height * 4];
      }
      for (int i = 0; i < (uint)width * height; i++) {
        uint x = (uint)i % width;
        uint y = (uint)i / width;
        for (int j = 0; j < 3; j++) {
          vertices[j][i * 4 + 0].Position = new Vector2f(x * MainForm.Inst.tileSize, y * MainForm.Inst.tileSize);
          vertices[j][i * 4 + 1].Position = new Vector2f(x * MainForm.Inst.tileSize, (y + 1) * MainForm.Inst.tileSize);
          vertices[j][i * 4 + 2].Position = new Vector2f((x + 1) * MainForm.Inst.tileSize, (y + 1) * MainForm.Inst.tileSize);
          vertices[j][i * 4 + 3].Position = new Vector2f((x + 1) * MainForm.Inst.tileSize, y * MainForm.Inst.tileSize);
          vertices[j][i * 4 + 0].Color = vertices[j][i * 4 + 1].Color = vertices[j][i * 4 + 2].Color = vertices[j][i * 4 + 3].Color = SFML.Graphics.Color.White;
        }
        if (i < width) {
          grid[i * 2 + 0].Position = new Vector2f(i * MainForm.Inst.tileSize, 0);
          grid[i * 2 + 1].Position = new Vector2f(i * MainForm.Inst.tileSize, height * MainForm.Inst.tileSize);
          grid[i * 2 + 0].Color = grid[i * 2 + 1].Color = SFML.Graphics.Color.White;
        } 
        if (i < height) {
          grid[(i + width) * 2 + 0].Position = new Vector2f(0, i * MainForm.Inst.tileSize);
          grid[(i + width) * 2 + 1].Position = new Vector2f(width * MainForm.Inst.tileSize, i * MainForm.Inst.tileSize);
          grid[(i + width) * 2 + 0].Color = grid[(i + width) * 2 + 1].Color = SFML.Graphics.Color.White;
        }
      }
    }

    private void Load(string name) {
      BinaryReader f = new BinaryReader(File.OpenRead(name));

      width = f.ReadUInt16();
      height = f.ReadUInt16();

      dataMovement = new byte[width, height];
      dataFloor = new byte[width, height];
      dataTilesB = new ushort[width, height];
      dataTilesF = new ushort[width, height];

      // Neighbours
      for (int i = 0; i < 4; i++) {
        neighbourID[i] = f.ReadUInt16();
        neighbourOffset[i] = f.ReadInt16();
      }

      // Flags
      flags = f.ReadByte();
      // Tileset
      tileSet = f.ReadByte();
      // Music
      music = f.ReadByte();

      // Load data
      for (int i = 0; i < width * height; i += 1) {
        dataMovement[i % width, i / width] = f.ReadByte();
        dataFloor[i % width, i / width] = f.ReadByte();
        dataTilesB[i % width, i / width] = f.ReadUInt16();
        dataTilesF[i % width, i / width] = f.ReadUInt16();
      }
      // Outside tiles
      for (int i = 0; i < 4; i += 1) {
        outTiles[0, i] = f.ReadUInt16();
        outTiles[1, i] = f.ReadUInt16();
      }

      f.Close();
    }

    public void render() {
      win.DispatchEvents();

      win.Clear(SFML.Graphics.Color.Black);
      for (int i = 0; i < width * height; i++) {
        uint x = (uint)i % width;
        uint y = (uint)i / width;
        uint tilex = (dataTilesB[x, y] % (MainForm.Inst.tileSets[tileSet].Size.X / MainForm.Inst.tileSize)) * MainForm.Inst.tileSize;
        uint tiley = (dataTilesB[x, y] / (MainForm.Inst.tileSets[tileSet].Size.X / MainForm.Inst.tileSize)) * MainForm.Inst.tileSize;
        vertices[0][i * 4 + 0].TexCoords = new Vector2f(tilex, tiley);
        vertices[0][i * 4 + 1].TexCoords = new Vector2f(tilex, tiley + MainForm.Inst.tileSize);
        vertices[0][i * 4 + 2].TexCoords = new Vector2f(tilex + MainForm.Inst.tileSize, tiley + MainForm.Inst.tileSize);
        vertices[0][i * 4 + 3].TexCoords = new Vector2f(tilex + MainForm.Inst.tileSize, tiley);

        tilex = (dataTilesF[x, y] % (MainForm.Inst.tileSets[tileSet].Size.X / MainForm.Inst.tileSize)) * MainForm.Inst.tileSize;
        tiley = (dataTilesF[x, y] / (MainForm.Inst.tileSets[tileSet].Size.X / MainForm.Inst.tileSize)) * MainForm.Inst.tileSize;
        vertices[1][i * 4 + 0].TexCoords = new Vector2f(tilex, tiley);
        vertices[1][i * 4 + 1].TexCoords = new Vector2f(tilex, tiley + MainForm.Inst.tileSize);
        vertices[1][i * 4 + 2].TexCoords = new Vector2f(tilex + MainForm.Inst.tileSize, tiley + MainForm.Inst.tileSize);
        vertices[1][i * 4 + 3].TexCoords = new Vector2f(tilex + MainForm.Inst.tileSize, tiley);
      }
      if (MainForm.Inst.tsmiViewTilesB.Checked) {
        win.Draw(vertices[0], PrimitiveType.Quads, new RenderStates(MainForm.Inst.tileSets[tileSet]));
      }
      if (MainForm.Inst.tsmiViewTilesF.Checked) {
        win.Draw(vertices[1], PrimitiveType.Quads, new RenderStates(MainForm.Inst.tileSets[tileSet]));
      }
      if (MainForm.Inst.tsmiViewGrid.Checked) {
        win.Draw(grid, PrimitiveType.Lines);
      }
      if (selection.Width > 1 || selection.Height > 1) {
        RectangleShape sel = new RectangleShape(new Vector2f(selection.Width * MainForm.Inst.tileSize - 1, selection.Height * MainForm.Inst.tileSize - 2));
        sel.Position = new Vector2f(selection.X * MainForm.Inst.tileSize, selection.Y * MainForm.Inst.tileSize + 1);
        sel.FillColor = SFML.Graphics.Color.Transparent;
        sel.OutlineThickness = 2;
        win.Draw(sel);
      }

      Vector2i mpos = Mouse.GetPosition(win);
      RectangleShape r = new RectangleShape(new Vector2f(MainForm.Inst.tileSize, MainForm.Inst.tileSize));
      r.Position = new Vector2f(MainForm.Inst.tileSize * ((int)(mpos.X / scale) / MainForm.Inst.tileSize), MainForm.Inst.tileSize * ((int)(mpos.Y / scale) / MainForm.Inst.tileSize));
      r.OutlineColor = new SFML.Graphics.Color(255, 255, 255, 255);
      r.FillColor = new SFML.Graphics.Color(255, 255, 255, 100);
      win.Draw(r);
      win.Display();
    }

    public void setZoom(float z) {
      scale = z;
      scale = Math.Max(1, scale);
      win.Size = new Vector2u((uint)(width * MainForm.Inst.tileSize * scale), (uint)(height * MainForm.Inst.tileSize * scale));
    }

    protected override void OnMouseMove(MouseEventArgs e) {
      Vector2f pos = new Vector2f(MainForm.Inst.tileSize * (Mouse.GetPosition(win).X / MainForm.Inst.tileSize), MainForm.Inst.tileSize * (Mouse.GetPosition(win).Y / MainForm.Inst.tileSize));
      MainForm.Inst.tsslCoords.Text = "Mouse: " + pos.X + " | " + pos.Y;
    }

    protected override void OnMouseDown(MouseEventArgs e) {
      int mx = e.X / (int)(MainForm.Inst.tileSize * scale);
      int my = e.Y / (int)(MainForm.Inst.tileSize * scale);
      selection.X = mx;
      selection.Width = 0;
      selection.Y = my;
      selection.Height = 0;
    }

    protected override void OnMouseUp(MouseEventArgs e) {
      int mx = e.X / (int)(MainForm.Inst.tileSize * scale);
      int my = e.Y / (int)(MainForm.Inst.tileSize * scale);
      if (mx < selection.X) {
        selection.Width = selection.X - mx + 1;
        selection.X = mx;
      } else {
        selection.Width = mx - selection.X + 1;
      }
      if (my < selection.Y) {
        selection.Height = selection.Y - my + 1;
        selection.Y = my;
      } else {
        selection.Height = my - selection.Y + 1;
      }
    }

    protected override void OnPaint(PaintEventArgs e) {
    }

    protected override void OnPaintBackground(PaintEventArgs pevent) {
    }
  }
}
