%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
void yyerror(char *);
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
/* "switch"        return SWITCH;
"case"          return CASE;
"default"       return DEFAULT;
"const"         return CONST;*/
"print"         return PRINT;

[-()<>=+*/%;{}.|&~^!:] {
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


[ \t\n]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
