using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Diagnostics;
using System.IO;

namespace compiler
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Compile_Button_Click(object sender, RoutedEventArgs e)
        {
            File.WriteAllText(@"data\in.cpp", inputArea.Text);
            if(!File.Exists(@"a.exe"))
            {

                Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
                dlg.Title = "Select the compiler executable file";
                dlg.DefaultExt = ".exe";
                dlg.Filter = "Executable Files (*.exe)|*.exe";
                Nullable<bool> result = dlg.ShowDialog();
                
                if (result == true)
                {
                    string filename = dlg.FileName;
                    File.Copy(filename, @"a.exe");
                }
            }
            var psi = new ProcessStartInfo(@"a.exe")
            {
                Arguments = @"data\in.cpp data\out.quad data\symbol_table.txt",
                UseShellExecute = false,
                CreateNoWindow = true,
                RedirectStandardError = true,
            };
            Process p = Process.Start(psi);
            errorArea.Text = p.StandardError.ReadToEnd();
            p.WaitForExit();
            outputArea.Text = File.ReadAllText(@"data\out.quad");
            symbolButton.IsEnabled = true;
        }

        private void symbolButton_Click(object sender, RoutedEventArgs e)
        {
            new SymbolTableWindow().Show();
        }
    }
}
