%{
#include <stdlib.h>
#include "compiler.h"
#include "parser.hpp"
#include <string>
#include <string.h>
void yyerror(const std::string& s);
%}

%option yylineno

%%

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"&&"            return AND;
"||"            return OR;
"<<"            return SHIFT_LEFT;
">>"            return SHIFT_RIGHT;
"+="            return PLUS_EQ;
"-="            return MINUS_EQ;
"*="            return MUL_EQ;
"/="            return DIV_EQ;
"%="            return MOD_EQ;
"<<="           return SH_LE_EQ;
">>="           return SH_RI_EQ;
"&="            return AND_EQ;
"^="            return XOR_EQ;
"|="            return OR_EQ;
"while"         return WHILE;
"for"           return FOR;
"repeat"        return REPEAT;
"until"         return UNTIL;
"if"            return IF;
"else"          return ELSE;
"switch"        return SWITCH;
"case"          return CASE;
"continue"      return CONTINUE;
"break"         return BREAK;
"default"       return DEFAULT;
"print"         return PRINT;
"int"           return INT_TYPE;
"double"        return FLOAT_TYPE;
"char"          return CHAR_TYPE;
"bool"          return BOOL_TYPE;
"void"          return VOID;
"const"         return CONST;
"return"        return RETURN;

"false"         {
                    yylval.bValue = false;
                    return BOOL;
                }

"true"          {
                    yylval.bValue = true;
                    return BOOL;
                }

[-()<>=+*/%;{}.|&~^!:,] {
                return *yytext;
             }

[a-zA-Z_][a-zA-Z_0-9]*       { 
                yylval.sIndex = strdup(yytext);
                return VARIABLE;
            }




0           {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[1-9][0-9]* {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)  {
                char * tmp = strdup(yytext);
                yylval.dValue = atof(tmp);
                return FLOAT;
            }

'[^'\n]'   {
                    yylval.cValue = yytext[1];
                    return CHAR;
                }

[ \t\n]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}

void yyerror(const std::string& s) {
    fprintf(stderr,"Line: %d: error: %s\n",yylineno,s.c_str());
}
