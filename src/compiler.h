#include <string>
#include <vector>
#include <map>

typedef enum { typeCon, typeId, typeOpr } nodeEnum;

struct valType
{
    union{
        int valInt;
        float valFloat;
        bool valBool;
        char valChar;
    };
};   

/* constants */
typedef struct {
    valType value;                  /* value of constant */
    int type;
} conNodeType;

/* identifiers */
typedef struct {
    char * i;                      /* subscript to sym array */
    int type;
} idNodeType;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag **op;	/* operands, extended at runtime */
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        oprNodeType opr;        /* operators */
    };
} nodeType;


typedef struct switchStatement{
    int oper; // 0: Case     1: Default
    nodeType * exp;
    nodeType * stmnt;
    struct switchStatement *nxt;
} switchstatement;


struct symbolEntry{
    std::string name;
    int type; // int, float, ..
    std::string symbolType; // function, variable, constant
    int scope;
    int timestamp;
    symbolEntry(std::string nm, int ty, std::string sty, int sc, int ts){
        name = nm, type = ty, symbolType = sty, scope = sc, timestamp = ts;
    }
};


void logError(const std::string& msg);
extern std::vector<std::string> msgs;
std::string intToType(int type);
bool isArithOper(int oper);
bool isBoolOper(int oper);
void printSymbolTable();


/*

Scope   symbolType      Type      Name

0       const           int         x
1       variable        int                 y
2       variable        int                         z
1       variable        int                 n

*/