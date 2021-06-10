using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace compiler
{
    public class SymbolTable
    {
        public string function { set; get; }
        public int scope { set; get; }
        public string symType { set; get; }
        public string retType { set; get; }
        public string name { set; get; }

    }

}
