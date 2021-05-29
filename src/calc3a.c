#include <stdio.h>
#include "calc3.h"
#include "y.tab.h"

int ex(nodeType *p) {
    if (!p) return 0;
    switch(p->type) {
    case typeCon:       return p->con.value;
    case typeId:        return sym[p->id.i];
    case typeOpr:
        switch(p->opr.oper) {
        case WHILE:             while(ex(p->opr.op[0])) ex(p->opr.op[1]); return 0;
        case FOR:               for(ex(p->opr.op[0]); ex(p->opr.op[1]); ex(p->opr.op[2])) ex(p->opr.op[3]); return 0;
        case REPEAT:            do {ex(p->opr.op[0]);} while (!ex(p->opr.op[1])); return 0;
                
        case IF:                if (ex(p->opr.op[0]))
                                    ex(p->opr.op[1]);
                                else if (p->opr.nops > 2)
                                    ex(p->opr.op[2]);
                                return 0;
        case SWITCH:  
        {
            int operts = 2;        
            for(int i = 0; i < p->opr.op[1]->con.value; ++i, operts += 3){
                if(p->opr.op[operts]->con.value == CASE){
                    if(ex(p->opr.op[operts+1]) == ex(p->opr.op[0])){
                        ex(p->opr.op[operts+2]);
                    }
                }
                else{
                    ex(p->opr.op[operts+1]);
                }
            }
            return 0;
        }
        case PRINT:             printf("%d\n", ex(p->opr.op[0])); return 0;
        case ';':               ex(p->opr.op[0]); return ex(p->opr.op[1]);
        case '=':               return sym[p->opr.op[0]->id.i] = ex(p->opr.op[1]);
        case PLUS_EQ:           return sym[p->opr.op[0]->id.i] += ex(p->opr.op[1]);
        case MINUS_EQ:          return sym[p->opr.op[0]->id.i] -= ex(p->opr.op[1]);
        case MUL_EQ:            return sym[p->opr.op[0]->id.i] *= ex(p->opr.op[1]);
        case DIV_EQ:            return sym[p->opr.op[0]->id.i] /= ex(p->opr.op[1]);
        case MOD_EQ:            return sym[p->opr.op[0]->id.i] %= ex(p->opr.op[1]);
        case SH_LE_EQ:          return sym[p->opr.op[0]->id.i] <<= ex(p->opr.op[1]);
        case SH_RI_EQ:          return sym[p->opr.op[0]->id.i] >>= ex(p->opr.op[1]);
        case AND_EQ:            return sym[p->opr.op[0]->id.i] &= ex(p->opr.op[1]);
        case OR_EQ:             return sym[p->opr.op[0]->id.i] |= ex(p->opr.op[1]);
        case XOR_EQ:            return sym[p->opr.op[0]->id.i] ^= ex(p->opr.op[1]);
        case UMINUS:            return -ex(p->opr.op[0]);
        case '!':               return !ex(p->opr.op[0]);
        case '~':               return ~ex(p->opr.op[0]);
        case OR:                return ex(p->opr.op[0]) || ex(p->opr.op[1]);
        case AND:               return ex(p->opr.op[0]) && ex(p->opr.op[1]);
        case '|':               return ex(p->opr.op[0]) | ex(p->opr.op[1]);
        case '^':               return ex(p->opr.op[0]) ^ ex(p->opr.op[1]);
        case '&':               return ex(p->opr.op[0]) & ex(p->opr.op[1]);
        case '+':               return ex(p->opr.op[0]) + ex(p->opr.op[1]);
        case '-':               return ex(p->opr.op[0]) - ex(p->opr.op[1]);
        case '*':               return ex(p->opr.op[0]) * ex(p->opr.op[1]);
        case '/':               return ex(p->opr.op[0]) / ex(p->opr.op[1]);
        case '%':               return ex(p->opr.op[0]) % ex(p->opr.op[1]);
        case '<':               return ex(p->opr.op[0]) < ex(p->opr.op[1]);
        case '>':               return ex(p->opr.op[0]) > ex(p->opr.op[1]);
        case GE:                return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
        case LE:                return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
        case NE:                return ex(p->opr.op[0]) != ex(p->opr.op[1]);
        case EQ:                return ex(p->opr.op[0]) == ex(p->opr.op[1]);
        case SHIFT_LEFT:        return ex(p->opr.op[0]) << ex(p->opr.op[1]);
        case SHIFT_RIGHT:       return ex(p->opr.op[0]) >> ex(p->opr.op[1]);
        }
    }
    return 0;
}
