%{
#include <stdlib.h>
#include "calc3.h"
#include "parser.hpp"
#include <string>
void yyerror(const std::string& s);
%}

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
"default"       return DEFAULT;
"print"         return PRINT;
"int"           return INT;
"double"        return DOB;
"char"          return CHAR;
"bool"          return BOOL;
"const"         return CONST;
"return"        return RETURN;

"false"         {
                    yylval.bValue = false;
                    return BOOLEAN;
                }

"true"          {
                    yylval.bValue = true;
                    return BOOLEAN;
                }

[-()<>=+*/%;{}.|&~^!:,] {
                return *yytext;
             }

[a-zA-Z_][a-zA-Z_0-9]*       { 
                yylval.sIndex = *yytext - 'a';
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

(0|[1-9][0-9]*).(0|[1-9][0-9]*)  {
                yylval.dValue = atof(yytext);
                return DOUBLE;
            }

'[^'\n]'   {
                    yylval.cValue = yytext[1];
                    return CHARACTER;
                }

[ \t\n]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
