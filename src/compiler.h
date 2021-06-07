#include <string>
#include <vector>

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

void logError(const std::string& msg);
extern std::vector<std::string> msgs;
std::string intToType(int type);
bool isArithOper(int oper);
bool isBoolOper(int oper);