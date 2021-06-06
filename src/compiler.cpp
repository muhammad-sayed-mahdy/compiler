#include <stdio.h>
#include "compiler.h"
#include "parser.hpp"

static int lbl;

int ex(nodeType *p) {
    int lbl1, lbl2;

    if (!p) return 0;
    switch(p->type) {
    case typeCon:       
        switch(p->con.type){
            case INT_TYPE: 
                printf("\tpush_int\t%d\n", p->con.value.valInt);
                break;
            case CHAR_TYPE: 
                printf("\tpush_char\t%c\n", p->con.value.valChar);
                break;
            case BOOL_TYPE: 
                printf("\tpush_bool\t%s\n", p->con.value.valBool? "true" : "false");
                break;
            case FLOAT_TYPE: 
                printf("\tpush_float\t%f\n", p->con.value.valFloat);
                break;
        }
        break;
    case typeId:        
        printf("\tpush\t%s\n", p->id.i); 
        // TODO: return the type of the identifier here
        break;
    case typeOpr:
        switch(p->opr.oper) {
        case WHILE:
            printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[0]);
            printf("\tjz\tL%03d\n", lbl2 = lbl++);
            ex(p->opr.op[1]);
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case IF:
            ex(p->opr.op[0]);
            if (p->opr.nops > 2) {
                /* if else */
                printf("\tjz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("\tjmp\tL%03d\n", lbl2 = lbl++);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2]);
                printf("L%03d:\n", lbl2);
            } else {
                /* if */
                printf("\tjz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("L%03d:\n", lbl1);
            }
            break;
        case PRINT:     
            ex(p->opr.op[0]);
            printf("\tprint\n");
            break;
        case '=':       
            ex(p->opr.op[1]);
            printf("\tpop\t%s\n", p->opr.op[0]->id.i);
            break;
        case UMINUS:    
            ex(p->opr.op[0]);
            printf("\tneg\n");
            break;
        default:
            int type1 = ex(p->opr.op[0]);
            int type2 = ex(p->opr.op[1]);
            switch(p->opr.oper) {
                case '+':   printf("\tadd\n"); break;
                case '-':   printf("\tsub\n"); break; 
                case '*':   printf("\tmul\n"); break;
                case '/':   printf("\tdiv\n"); break;
                case '<':   printf("\tcompLT\n"); break;
                case '>':   printf("\tcompGT\n"); break;
                case GE:    printf("\tcompGE\n"); break;
                case LE:    printf("\tcompLE\n"); break;
                case NE:    printf("\tcompNE\n"); break;
                case EQ:    printf("\tcompEQ\n"); break;
            }
            
        }
    }
    return 0;
}

void logError(const std::string& msg) {
    printf("%s\n", msg.c_str());
    // print other error parameters here.
}