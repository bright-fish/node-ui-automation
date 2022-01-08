using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Applications
{
    static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            global::System.Windows.Forms.Application.SetHighDpiMode(HighDpiMode.SystemAware);
            global::System.Windows.Forms.Application.EnableVisualStyles();
            global::System.Windows.Forms.Application.SetCompatibleTextRenderingDefault(false);
            global::System.Windows.Forms.Application.Run(new TestApplication());
        }
    }
}
