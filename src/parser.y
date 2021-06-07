%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "compiler.h"
#include <string>
#include <string.h>
#include <vector>

/* prototypes */

int noOfCases;

nodeType *opr(int oper, int nops, ...);
nodeType *id(char * i);
nodeType *con(int typ, ...);
struct switchStatement * conc(int oper, nodeType * exp, nodeType * stmnt, struct switchStatement * nxt);
nodeType *switchOpr(nodeType* exp, struct switchStatement * ss);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(const std::string& s);
void flushMsgs(std::vector<std:: string>& msgs);
std::vector<std::string> msgs;

%}

%union {
    int iValue;                         /* integer value */
    float dValue;                      /* double value */
    char cValue;                        /* char value */
    bool bValue;                        /* boolean value */
    char* sIndex;                        /* symbol table index */
    nodeType *nPtr;                     /* node pointer */
    switchstatement *swtch;  
};

%token <iValue> INTEGER
%token <dValue> FLOAT
%token <cValue> CHAR
%token <bValue> BOOL
%token <sIndex> VARIABLE
%token WHILE IF PRINT FOR REPEAT UNTIL SWITCH CASE DEFAULT VOID BOOL_TYPE CHAR_TYPE INT_TYPE FLOAT_TYPE CONST RETURN CONTINUE BREAK
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

%define parse.error verbose
%locations

%%

program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2); flushMsgs(msgs); freeNode($2); }
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
          INTEGER                        { $$ = con(INT_TYPE, $1); }
        | FLOAT                     { $$ = con(FLOAT_TYPE, $1); }
        | CHAR                      { $$ = con(CHAR_TYPE, $1); }
        | BOOL                      { $$ = con(BOOL_TYPE, $1); }
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
     INTEGER                        { $$ = con(INT_TYPE, $1); }
        | FLOAT                     { $$ = con(FLOAT_TYPE, $1); }
        | CHAR                      { $$ = con(CHAR_TYPE, $1); }
        | BOOL                      { $$ = con(BOOL_TYPE, $1); }
        | VARIABLE                  { $$ = id($1); }
        | VARIABLE '(' arg_list ')' { $$ = NULL; }
        | VARIABLE '=' expr         { $$ = opr('=', 2, id($1), $3); }
        | VARIABLE PLUS_EQ expr     { $$ = opr('=', 2, id($1), opr('+', 2, id($1), $3)); }
        | VARIABLE MINUS_EQ expr    { $$ = opr('=', 2, id($1), opr('-', 2, id($1), $3)); }
        | VARIABLE MUL_EQ expr      { $$ = opr('=', 2, id($1), opr('*', 2, id($1), $3)); }
        | VARIABLE DIV_EQ expr      { $$ = opr('=', 2, id($1), opr('/', 2, id($1), $3)); }
        | VARIABLE MOD_EQ expr      { $$ = opr('=', 2, id($1), opr('%', 2, id($1), $3)); }
        | VARIABLE SH_LE_EQ expr    { $$ = opr('=', 2, id($1), opr(SHIFT_LEFT, 2, id($1), $3)); }
        | VARIABLE SH_RI_EQ expr    { $$ = opr('=', 2, id($1), opr(SHIFT_RIGHT, 2, id($1), $3)); }
        | VARIABLE AND_EQ expr      { $$ = opr('=', 2, id($1), opr('&', 2, id($1), $3)); }
        | VARIABLE OR_EQ expr       { $$ = opr('=', 2, id($1), opr('|', 2, id($1), $3)); }
        | VARIABLE XOR_EQ expr      { $$ = opr('=', 2, id($1), opr('^', 2, id($1), $3)); }
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
    INT_TYPE                          
    | CHAR_TYPE                          
    | BOOL_TYPE                          
    | FLOAT_TYPE                           
%%

nodeType *con(int typ, ...) {
    va_list ap;
    nodeType *p = new nodeType();


    /* copy information */
    p->type = typeCon;
    p->con.type = typ;
    va_start(ap,typ);
    if(typ != FLOAT_TYPE)
        p->con.value = va_arg(ap, valType);
    else 
        p->con.value.valFloat = float(va_arg(ap, double));
    va_end(ap);

    return p;
}

nodeType *id(char * i) {
    nodeType *p = new nodeType();


    /* copy information */
    p->type = typeId;
    p->id.i = strdup(i);

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
    p->opr.op[1]->con.value.valInt = casesNo;
    while(ss){
        tmp = ss;
        if(ss->oper == DEFAULT){
            p->opr.op[i] = new nodeType();
            p->opr.op[i++]->con.value.valInt = DEFAULT;
            p->opr.op[i++] = ss->stmnt;
        }
        else{
            p->opr.op[i] = new nodeType();
            p->opr.op[i++]->con.value.valInt = CASE;
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
    } else if (p->type == typeId) {
        free(p->id.i);
    }
    delete p;
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

void flushMsgs(std::vector<std:: string>& msgs) {
    for (auto& msg: msgs) {
        printf("%s", msg.c_str());
    }
    msgs.clear();
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