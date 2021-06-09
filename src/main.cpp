#include "compiler.h"
#include "parser.hpp"
#include <string>
#include <vector>


extern FILE* yyin;
extern std::vector<std::string> msgs;
extern bool ERRORS;
void printSymbolTable();

int main(int argc, char** argv)
{
    std::string inFileName = "data/in.cpp";
    std::string outFileName = "data/out.quad";
    std::string symFileName = "data/symbol_table.txt";
    if (argc > 1)
        inFileName = argv[1];
    if (argc > 2)
        outFileName = argv[2];
    if (argc > 3)
        symFileName = argv[3];

    yyin = fopen(inFileName.c_str(), "r");
    if (yyin == NULL)
    {
        fprintf(stderr, "Couldn't open input file: %s\n", inFileName.c_str());
        return 0;
    }
    yyparse();

    FILE* quad = fopen(outFileName.c_str(), "w");
    if (quad == NULL)
    {
        fprintf(stderr, "Couldn't open quad output file: %s", outFileName.c_str());
        return 0;
    }

    FILE* p = freopen(symFileName.c_str(), "w", stdout);
    if (p == NULL)
    {
        fprintf(stderr, "Couldn't open symbol table output file: %s", symFileName.c_str());
        return 0;
    }
    if (!ERRORS)
    {
        for (auto& msg: msgs)
            fprintf(quad, "%s", msg.c_str());
        printSymbolTable();
    }

    fclose(quad);
    fclose(yyin);
    
    return 0;
}