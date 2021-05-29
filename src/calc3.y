%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(char *s);
int sym[26];                    /* symbol table */
%}

%union {
    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
};

%token <iValue> INTEGER
%token <sIndex> VARIABLE
%token WHILE IF PRINT FOR REPEAT UNTIL /*SWITCH CASE DEFALUT CONST*/
%nonassoc IFX
%nonassoc ELSE

%right '=' PLUS_EQ MINUS_EQ MUL_EQ DIV_EQ MOD_EQ SH_LE_EQ SH_RI_EQ AND_EQ XOR_EQ OR_EQ
%left OR
%left AND
%left '|' 
%left '^' 
%left '&'
%left GE LE EQ NE '>' '<'
%left SHIFT_LEFT SHIFT_RIGHT
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS '~' '!'

%type <nPtr> stmt expr stmt_list

%%

program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2); freeNode($2); }
        | /* NULL */
        ;

stmt:
          ';'                                                    { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                                               { $$ = $1; }
        | PRINT expr ';'                                         { $$ = opr(PRINT, 1, $2); }
        | WHILE '(' expr ')' stmt                                { $$ = opr(WHILE, 2, $3, $5); }
        | REPEAT stmt  UNTIL '(' expr ')' ';'                    { $$ = opr(REPEAT, 2, $2, $5); }
        | FOR '(' expr ';' expr ';' expr ')' stmt                { $$ = opr(FOR, 4, $3, $5, $7, $9); }
        // | SWITCH '(' expr ')' '{' switch_stmt '}'                { $$ = opr(SWITCH, 3, $) }
        | IF '(' expr ')' stmt %prec IFX                         { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt                         { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'                                      { $$ = $2; }
        ;

/*switch_stmt:
            CASE const_expr ':' stmt
        | CASE const_expr ':' stmt switch_stmt
        | DEFALUT ':' stmt
        ;*/

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

/*const_expr:
          INTEGER                           { $$ = con($1); }
        | '!' const_expr                    { $$ = opr('!', 1, $2); }
        | '~' const_expr                    { $$ = opr('~', 1, $2); }
        | '-' const_expr %prec UMINUS       { $$ = opr(UMINUS, 1, $2); }
        | const_expr OR const_expr          { $$ = opr(OR, 2, $1, $3); }
        | const_expr AND const_expr         { $$ = opr(AND, 2, $1, $3); }
        | const_expr '|' const_expr         { $$ = opr('|', 2, $1, $3); }
        | const_expr '^' const_expr         { $$ = opr('^', 2, $1, $3); }
        | const_expr '&' const_expr         { $$ = opr('&', 2, $1, $3); }
        | const_expr '+' const_expr         { $$ = opr('+', 2, $1, $3); }
        | const_expr '-' const_expr         { $$ = opr('-', 2, $1, $3); }
        | const_expr '*' const_expr         { $$ = opr('*', 2, $1, $3); }
        | const_expr '/' const_expr         { $$ = opr('/', 2, $1, $3); }
        | const_expr '<' const_expr         { $$ = opr('<', 2, $1, $3); }
        | const_expr '>' const_expr         { $$ = opr('>', 2, $1, $3); }
        | const_expr GE const_expr          { $$ = opr(GE, 2, $1, $3); }
        | const_expr LE const_expr          { $$ = opr(LE, 2, $1, $3); }
        | const_expr NE const_expr          { $$ = opr(NE, 2, $1, $3); }
        | const_expr EQ const_expr          { $$ = opr(EQ, 2, $1, $3); }
        | '(' const_expr ')'                { $$ = $2; }
        ;*/

expr:
     INTEGER                        { $$ = con($1); }
        | VARIABLE                  { $$ = id($1); }
        | VARIABLE '=' expr         { $$ = opr('=', 2, id($1), $3); }
        | VARIABLE PLUS_EQ expr     { $$ = opr(PLUS_EQ, 2, id($1), $3); }
        | VARIABLE MINUS_EQ expr    { $$ = opr(MINUS_EQ, 2, id($1), $3); }
        | VARIABLE MUL_EQ expr      { $$ = opr(MUL_EQ, 2, id($1), $3); }
        | VARIABLE DIV_EQ expr      { $$ = opr(DIV_EQ, 2, id($1), $3); }
        | VARIABLE MOD_EQ expr      { $$ = opr(PLUS_EQ, 2, id($1), $3); }
        | VARIABLE SH_LE_EQ expr    { $$ = opr(SH_LE_EQ, 2, id($1), $3); }
        | VARIABLE SH_RI_EQ expr    { $$ = opr(PLUS_EQ, 2, id($1), $3); }
        | VARIABLE AND_EQ expr      { $$ = opr(AND_EQ, 2, id($1), $3); }
        | VARIABLE OR_EQ expr       { $$ = opr(OR_EQ, 2, id($1), $3); }
        | VARIABLE XOR_EQ expr      { $$ = opr(PLUS_EQ, 2, id($1), $3); }
        | '!' expr                  { $$ = opr('!', 1, $2); }
        | '~' expr                  { $$ = opr('~', 1, $2); }
        | '-' expr %prec UMINUS     { $$ = opr(UMINUS, 1, $2); }
        | expr OR expr              { $$ = opr(OR, 2, $1, $3); }
        | expr AND expr             { $$ = opr(AND, 2, $1, $3); }
        | expr '|' expr             { $$ = opr('|', 2, $1, $3); }
        | expr '^' expr             { $$ = opr('^', 2, $1, $3); }
        | expr '&' expr             { $$ = opr('&', 2, $1, $3); }
        | expr '+' expr             { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr             { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr             { $$ = opr('*', 2, $1, $3); }
        | expr '/' expr             { $$ = opr('/', 2, $1, $3); }
        | expr '%' expr             { $$ = opr('%', 2, $1, $3); }
        | expr '<' expr             { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr             { $$ = opr('>', 2, $1, $3); }
        | expr GE expr              { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr              { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr              { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr              { $$ = opr(EQ, 2, $1, $3); }
        | expr SHIFT_LEFT expr      { $$ = opr(SHIFT_LEFT, 2, $1, $3); }
        | expr SHIFT_RIGHT expr     { $$ = opr(SHIFT_RIGHT, 2, $1, $3); }
        | '(' expr ')'              { $$ = $2; }
        ;
    
%%

nodeType *con(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
