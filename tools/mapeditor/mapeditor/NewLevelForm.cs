using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mapeditor {
  public partial class NewLevelForm : Form {

    public ushort width, height;
    public bool aborted;

    private void btnOk_Click(object sender, EventArgs e) {
      width = (ushort)nudWidth.Value;
      height = (ushort)nudHeight.Value;
      aborted = false;
      Hide();
    }

    protected override void OnClosed(EventArgs e) {
      aborted = true;
      Hide();
    }

    public NewLevelForm() {
      InitializeComponent();
    }
  }
}
