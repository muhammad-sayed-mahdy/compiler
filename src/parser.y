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
nodeType *new_id(int oper, int nops, nodeType * typ, char * name, ...);
nodeType *id(char * i);
nodeType *types(int i);
nodeType *con(int typ, ...);
struct switchStatement * conc(int oper, nodeType * exp, nodeType * stmnt, struct switchStatement * nxt);
nodeType *switchOpr(nodeType* exp, struct switchStatement * ss);
void freeNode(nodeType *p);
int ex(nodeType *p, int contLbl = -1, int breakLbl = -1);
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
%token INCR DECR WHILE IF PRINT FOR DO SWITCH CASE DEFAULT CONST VOID BOOL_TYPE CHAR_TYPE INT_TYPE FLOAT_TYPE RETURN CONTINUE BREAK
%token BLOCK_STRUCTURE DECL DECL_CONST ASSIGN ASSIGN_CONST
%token PARAM_LIST ARG_LIST VOID_FUNC FUNC_DEC CAL
%token POST_INC POST_DEC PRE_INC PRE_DEC
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

%type <nPtr> stmt expr stmt_list const_expr decl param_list arg_list typ
%type <swtch> switch_stmt

%define parse.error verbose
%locations

%%

program:
        function                {  }
        ;

function:
          function stmt         { ex($2); freeNode($2); }
        | /* NULL */
        ;

decl:
    typ VARIABLE                                          { $$ = new_id(DECL, 2, $1, $2); } // req
    | typ VARIABLE '=' expr                               { $$ = new_id(ASSIGN, 3, $1, $2, $4); } // req
    | CONST typ VARIABLE                                  { $$ = new_id(DECL_CONST, 2, $2, $3); } // req
    | CONST typ VARIABLE '=' expr                         { $$ = new_id(ASSIGN_CONST, 3, $2, $3, $5); } // req
    ;

stmt:
          ';'                                                    { $$ = NULL; }
        | CONTINUE ';'                                           { $$ = opr(CONTINUE, 0); }
        | BREAK ';'                                              { $$ = opr(BREAK, 0); }  
        | expr ';'                                               { $$ = $1; }
        | PRINT expr ';'                                         { $$ = opr(PRINT, 1, $2); }
        | WHILE '(' expr ')' stmt                                { $$ = opr(WHILE, 2, $3, $5); }
        | decl ';'                                               { $$ = $1; } // req
        | typ VARIABLE '(' param_list ')'  stmt                  { $$ = opr(FUNC_DEC, 3, new_id(FUNC_DEC, 2, $1, $2), $4, $6); } 
        | VOID VARIABLE '(' param_list ')' stmt                  { $$ = opr(VOID_FUNC, 3, id($2), $4, $6); } 
        | RETURN expr ';'                                        { $$ = opr(RETURN, 1, $2); }
        | RETURN ';'                                             { $$ = opr(RETURN, 0); }
        | DO stmt  WHILE '(' expr ')' ';'                        { $$ = opr(DO, 2, $2, $5); }
        | FOR '(' expr ';' expr ';' expr ')' stmt                { $$ = opr(FOR, 4, $3, $5, $7, $9); }
        | FOR '(' decl ';' expr ';' expr ')' stmt                { $$ = opr(FOR, 4, $3, $5, $7, $9); }
        | SWITCH '(' expr ')' '{' switch_stmt '}'                { $$ = switchOpr( $3, $6); }
        | IF '(' expr ')' stmt %prec IFX                         { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt                         { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'                                      { $$ = opr(BLOCK_STRUCTURE, 1, $2); } // req
        | error ';'                                              { $$ = NULL; }
        | error '}'                                              { $$ = NULL; }
        ;

param_list:
        decl                                                     { $$ = $1; }
        | decl ',' param_list                                    { $$ = opr(PARAM_LIST, 2, $1, $3); }
        | /* NULL */                                             { $$ = opr(PARAM_LIST,0); }
        ;

arg_list:
        expr                                                     { $$ = opr(ARG_LIST, 1, $1); }
        | expr ',' arg_list                                      { $$ = opr(ARG_LIST, 2, $1, $3);  }
        | /* NULL */                                             { $$ = opr(ARG_LIST,0); }
        ;

switch_stmt:
            CASE const_expr ':' stmt_list                                { $$ = conc(CASE, $2, $4, NULL);}
        | CASE const_expr ':' stmt_list switch_stmt                      { $$ = conc(CASE, $2, $4, $5);}
        | DEFAULT ':' stmt_list                                               { $$ = conc(DEFAULT, NULL, $3, NULL);}
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

const_expr:
          INTEGER                           { $$ = con(INT_TYPE, $1); }
        | FLOAT                             { $$ = con(FLOAT_TYPE, $1); }
        | CHAR                              { $$ = con(CHAR_TYPE, $1); }
        | BOOL                              { $$ = con(BOOL_TYPE, $1); }
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
        | const_expr SHIFT_LEFT const_expr  { $$ = opr(SHIFT_LEFT, 2, $1, $3); }
        | const_expr SHIFT_RIGHT const_expr { $$ = opr(SHIFT_RIGHT, 2, $1, $3); }
        | '(' const_expr ')'                { $$ = $2; }
        ;

expr:
     INTEGER                        { $$ = con(INT_TYPE, $1); }
        | FLOAT                     { $$ = con(FLOAT_TYPE, $1); }
        | CHAR                      { $$ = con(CHAR_TYPE, $1); }
        | BOOL                      { $$ = con(BOOL_TYPE, $1); }
        | VARIABLE                  { $$ = id($1); }
        | INCR VARIABLE             { $$ = opr(PRE_INC,1,id($2)); }
        | VARIABLE INCR             { $$ = opr(POST_INC,1,id($1)); }
        | DECR VARIABLE             { $$ = opr(PRE_DEC,1,id($2)); }
        | VARIABLE DECR             { $$ = opr(POST_DEC,1,id($1)); }
        | VARIABLE '(' arg_list ')' { $$ = opr(CAL, 2, id($1), $3); }
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
    INT_TYPE                        {$$ = types(0);}
    | CHAR_TYPE                     {$$ = types(1);}
    | BOOL_TYPE                     {$$ = types(2);}
    | FLOAT_TYPE                    {$$ = types(3);}
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

nodeType *new_id(int oper, int nops, nodeType * typ, char * name, ...){
    va_list ap;
    nodeType *p = new nodeType();


    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops-1;
    p->opr.op = new nodeType* [nops-1];
    p->opr.op[0] = new nodeType();
    p->opr.op[0]->type = typeId;
    p->opr.op[0]->id.i = strdup(name);
    p->opr.op[0]->id.type = typ->id.type;

    if(nops < 3) 
        return p;
    va_start(ap,name);
    nodeType* aux = va_arg(ap, nodeType*);
    va_end(ap);
    p->opr.op[1] = opr('=', 2, id(name), aux);

    return p;
}

nodeType *types(int i){
    nodeType *p = new nodeType();


    /* copy information */
    p->type = typeId;
    switch(i){
        case 0: p->id.type = INT_TYPE; break;
        case 1: p->id.type = CHAR_TYPE; break;
        case 2: p->id.type = BOOL_TYPE; break;
        case 3: p->id.type = FLOAT_TYPE; break;
        case 4: p->id.type = VOID; break;
    }

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
    p->opr.op[1]->type = typeCon;
    p->opr.op[1]->con.value.valInt = casesNo;
    while(ss){
        tmp = ss;
        if(ss->oper == DEFAULT){
            p->opr.op[i] = new nodeType();
            p->opr.op[i]->type = typeCon;
            p->opr.op[i++]->con.value.valInt = DEFAULT;
            p->opr.op[i++] = ss->stmnt;
        }
        else{
            p->opr.op[i] = new nodeType();
            p->opr.op[i]->type = typeCon;
            p->opr.op[i++]->con.value.valInt = CASE;
            p->opr.op[i++] = opr(EQ, 2, exp, ss->exp);
            p->opr.op[i++] = ss->stmnt;
        }
        ss = ss->nxt;
        delete tmp;
    }
    return p;
}



void freeNode(nodeType *p) {
    int i = 0;;
    if (!p) return;
    if (p->type == typeOpr) {
        if(p->opr.oper == SWITCH) i++;
        for (; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
        delete[] p->opr.op;
    } else if (p->type == typeId) {
        free(p->id.i);
    }
    delete p;
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