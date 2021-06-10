using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace compiler
{
    public static class SymbolTableService
    {
        public static List<SymbolTable> ReadFile(string filepath)
        {
            List<SymbolTable> data = new List<SymbolTable>();

            var lines = File.ReadAllLines(filepath);
            for (int i = 1; i < lines.Length; i++)
            {
                string[] split = lines[i].Split('|');
                if (split.Length == 5)
                {
                    data.Add(new SymbolTable
                    {
                        function = split[0].Trim(),
                        scope = int.Parse(split[1].Trim()),
                        symType = split[2].Trim(),
                        retType = split[3].Trim(),
                        name = split[4].Trim()
                    });
                }
            }

            return data;
        }
    }
}
