%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "compiler.h"
#include <string>

/* prototypes */

int noOfCases;

nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
struct switchStatement * conc(int oper, nodeType * exp, nodeType * stmnt, struct switchStatement * nxt);
nodeType *switchOpr(nodeType* exp, struct switchStatement * ss);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(const std::string& s);
int sym[26];                    /* symbol table */
%}

%union {
    int iValue;                         /* integer value */
    double dValue;                      /* double value */
    char cValue;                        /* char value */
    bool bValue;                        /* boolean value */
    char sIndex;                        /* symbol table index */
    nodeType *nPtr;                     /* node pointer */
    switchstatement *swtch;  
};

%token <iValue> INTEGER
%token <dValue> DOUBLE
%token <cValue> CHARACTER
%token <bValue> BOOLEAN
%token <sIndex> VARIABLE
%token WHILE IF PRINT FOR REPEAT UNTIL SWITCH CASE DEFAULT VOID INT DOB CHAR BOOL CONST RETURN CONTINUE BREAK
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
%nonassoc UMINUS UPLUS '~' '!'

%type <nPtr> stmt expr stmt_list const_expr decl param_list arg_list
%type <swtch> switch_stmt

%%

program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2); freeNode($2); }
        | /* NULL */
        ;

decl:
    typ VARIABLE                                          { $$ = id($2); }
    | typ VARIABLE '=' expr                               { $$ = opr('=', 2, id($2), $4); }
    | CONST typ VARIABLE                                  { $$ = id($3); }
    | CONST typ VARIABLE '=' expr                         { $$ = opr('=', 2, id($3), $5); }
    ;

stmt:
          ';'                                                    { $$ = opr(';', 2, NULL, NULL); }
        | CONTINUE ';'                                           { $$ = NULL; }
        | BREAK ';'                                              { $$ = NULL; }  
        | expr ';'                                               { $$ = $1; }
        | PRINT expr ';'                                         { $$ = opr(PRINT, 1, $2); }
        | WHILE '(' expr ')' stmt                                { $$ = opr(WHILE, 2, $3, $5); }
        | decl ';'                                               { $$ = $1; }
        | typ VARIABLE '(' param_list ')' stmt                   { $$ = NULL; }
        | VOID VARIABLE '(' param_list ')' stmt                   { $$ = NULL; }
        | RETURN expr ';'                                        { $$ = opr(RETURN, 1, $2); }
        | RETURN ';'                                             { $$ = opr(RETURN, 0); }
        | REPEAT stmt  UNTIL '(' expr ')' ';'                    { $$ = opr(REPEAT, 2, $2, $5); }
        | FOR '(' expr ';' expr ';' expr ')' stmt                { $$ = opr(FOR, 4, $3, $5, $7, $9); }
        | FOR '(' decl ';' expr ';' expr ')' stmt                { $$ = opr(FOR, 4, $3, $5, $7, $9); }
        | SWITCH '(' expr ')' '{' switch_stmt '}'                { $$ = switchOpr( $3, $6); }
        | IF '(' expr ')' stmt %prec IFX                         { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt                         { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'                                      { $$ = $2; }
        ;

param_list:
        decl                                                     { $$ = NULL; }
        | param_list ',' decl                                    { $$ = NULL; }
        | /* NULL */                                             { $$ = NULL; }
        ;

arg_list:
        expr                                                     { $$ = NULL; }
        | arg_list ',' expr                                { $$ = NULL; }
        | /* NULL */                                             { $$ = NULL; }
        ;

switch_stmt:
            CASE const_expr ':' stmt                                   { $$ = conc(CASE, $2, $4, NULL);}
        | CASE const_expr ':' stmt switch_stmt                         { $$ = conc(CASE, $2, $4, $5);}
        | DEFAULT ':' stmt                                       { $$ = conc(DEFAULT, NULL, $3, NULL);}
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

const_expr:
          INTEGER                           { $$ = con($1); }
        | DOUBLE                            { $$ = con($1); }
        | CHARACTER                         { $$ = con($1); }
        | BOOLEAN                           { $$ = con($1); }
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
        | const_expr '%' const_expr         { $$ = opr('%', 2, $1, $3); }
        | const_expr '<' const_expr         { $$ = opr('<', 2, $1, $3); }
        | const_expr '>' const_expr         { $$ = opr('>', 2, $1, $3); }
        | const_expr GE const_expr          { $$ = opr(GE, 2, $1, $3); }
        | const_expr LE const_expr          { $$ = opr(LE, 2, $1, $3); }
        | const_expr NE const_expr          { $$ = opr(NE, 2, $1, $3); }
        | const_expr EQ const_expr          { $$ = opr(EQ, 2, $1, $3); }
        | const_expr SHIFT_LEFT const_expr      { $$ = opr(SHIFT_LEFT, 2, $1, $3); }
        | const_expr SHIFT_RIGHT const_expr     { $$ = opr(SHIFT_RIGHT, 2, $1, $3); }
        | '(' const_expr ')'              { $$ = $2; }
        ;

expr:
     INTEGER                        { $$ = con($1); }
        | DOUBLE                    { $$ = con($1); }
        | CHARACTER                 { $$ = con($1); }
        | BOOLEAN                   { $$ = con($1); }
        | VARIABLE                  { $$ = id($1); }
        | VARIABLE '(' arg_list ')' { $$ = NULL; }
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
        | '+' expr %prec UPLUS      { $$ = opr(UPLUS, 1, $2); }
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

typ: 
    INT                             
    | CHAR                          
    | BOOL                          
    | DOB                           
%%

nodeType *con(int value) {
    nodeType *p = new nodeType();


    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p = new nodeType();


    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p = new nodeType();
    int i;


    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    p->opr.op = new nodeType* [nops];
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

nodeType *switchOpr(nodeType* exp, struct switchStatement * ss) {
    nodeType *p = new nodeType();
    int i = 2, casesNo = 0, nops = 2;
    struct switchStatement *tmp = ss;
    // No of operands =         1            +        1        +        3*No of Cases       -       1
    //                  (switch expression)     (No of Cases)           (each Case)             (if default exists)

    while(tmp){
        if(tmp->oper == DEFAULT) nops--;
        tmp = tmp->nxt;
        casesNo++;
        nops += 3;
    }

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = SWITCH;
    p->opr.nops = nops;
    p->opr.op = new nodeType* [nops];
    p->opr.op[0] = exp;
    p->opr.op[1] = new nodeType();
    p->opr.op[1]->con.value = casesNo;
    while(ss){
        tmp = ss;
        if(ss->oper == DEFAULT){
            p->opr.op[i] = new nodeType();
            p->opr.op[i++]->con.value = DEFAULT;
            p->opr.op[i++] = ss->stmnt;
        }
        else{
            p->opr.op[i] = new nodeType();
            p->opr.op[i++]->con.value = CASE;
            p->opr.op[i++] = ss->exp;
            p->opr.op[i++] = ss->stmnt;
        }
        ss = ss->nxt;
        delete tmp;
    }
    return p;
}



void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
        delete[] p->opr.op;
    }
    delete p;
}

void yyerror(const std::string& s) {
    fprintf(stdout, "%s\n", s.c_str());
}

int main(void) {
    yyparse();
    return 0;
}

struct switchStatement * conc(int oper, nodeType * exp, nodeType * stmnt, struct switchStatement * nxt){
    struct switchStatement * ret = new switchstatement();
    ret->oper = oper;
    ret->stmnt = stmnt;
    ret->nxt = nxt;
    if(oper == CASE){
        ret->exp = exp;
    }
    return ret;
}
/*
x = 1;
switch(x){
    case 0: print 0;
    case 1: print 1;
    case 2: print 2;
    default: print 3;
}

*/