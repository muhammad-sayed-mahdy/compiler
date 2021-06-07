#include <stdio.h>
#include "compiler.h"
#include "parser.hpp"

static int lbl;
char buff[100];
int type1, type2;

int ex(nodeType *p) {
    int lbl1, lbl2;

    if (!p) return 0;
    switch(p->type) {
    case typeCon:       
        switch(p->con.type){
            case INT_TYPE: 
                sprintf(buff, "\tpush_int\t%d\n", p->con.value.valInt);msgs.push_back(buff);
                return INT_TYPE;
            case CHAR_TYPE: 
                sprintf(buff, "\tpush_char\t'%c'\n", p->con.value.valChar);msgs.push_back(buff);
                return CHAR_TYPE;
            case BOOL_TYPE: 
                sprintf(buff, "\tpush_bool\t%s\n", p->con.value.valBool? "true" : "false");msgs.push_back(buff);
                return BOOL_TYPE;
            case FLOAT_TYPE: 
                sprintf(buff, "\tpush_float\t%f\n", p->con.value.valFloat);msgs.push_back(buff);
                return FLOAT_TYPE;
        }
        break;
    case typeId:        
        sprintf(buff, "\tpush_%s\t%s\n", intToType(p->id.type).c_str(), p->id.i); msgs.push_back(buff);
        return p->id.type;
        
    case typeOpr:
        switch(p->opr.oper) {
        case WHILE:
            sprintf(buff, "L%03d:\n", lbl1 = lbl++);msgs.push_back(buff);
            ex(p->opr.op[0]);
            sprintf(buff, "\tjz\tL%03d\n", lbl2 = lbl++);msgs.push_back(buff);
            ex(p->opr.op[1]);
            sprintf(buff, "\tjmp\tL%03d\n", lbl1);msgs.push_back(buff);
            sprintf(buff, "L%03d:\n", lbl2);msgs.push_back(buff);
            break;
        case IF:
            ex(p->opr.op[0]);
            if (p->opr.nops > 2) {
                /* if else */
                sprintf(buff, "\tjz\tL%03d\n", lbl1 = lbl++);msgs.push_back(buff);
                ex(p->opr.op[1]);
                sprintf(buff, "\tjmp\tL%03d\n", lbl2 = lbl++);msgs.push_back(buff);
                sprintf(buff, "L%03d:\n", lbl1);msgs.push_back(buff);
                ex(p->opr.op[2]);
                sprintf(buff, "L%03d:\n", lbl2);msgs.push_back(buff);
            } else {
                /* if */
                sprintf(buff, "\tjz\tL%03d\n", lbl1 = lbl++);msgs.push_back(buff);
                ex(p->opr.op[1]);
                sprintf(buff, "L%03d:\n", lbl1);msgs.push_back(buff);
            }
            break;
        case PRINT:     
            ex(p->opr.op[0]);
            sprintf(buff, "\tprint\n");msgs.push_back(buff);
            break;
        case '=':       
            type1 = ex(p->opr.op[1]);
            type2 = p->opr.op[0]->id.type;
            if (type1 != type2)
                msgs.push_back("\t" + intToType(type1) + "_TO_" + intToType(type2) + "\n");
            sprintf(buff, "\tpop_%s\t%s\n", intToType(type2).c_str(), p->opr.op[0]->id.i);msgs.push_back(buff);
            break;
        case UMINUS:    
            ex(p->opr.op[0]);
            sprintf(buff, "\tneg\n");msgs.push_back(buff);
            break;
        default:
            type1 = ex(p->opr.op[0]);
            int sz1 = msgs.size();
            type2 = ex(p->opr.op[1]);
            if (type1 < type2) {
                std::string convertOp = "\t" + intToType(type1) + "_TO_" + intToType(type2) + "\n";
                msgs.insert(msgs.begin()+sz1, convertOp);
            } else if (type2 < type1) {
                std::string convertOp = "\t" + intToType(type2) + "_TO_" + intToType(type1) + "\n";
                msgs.push_back(convertOp);
            }

            switch(p->opr.oper) {
                case '+':   sprintf(buff, "\tadd"); msgs.push_back(buff); break;
                case '-':   sprintf(buff, "\tsub"); msgs.push_back(buff); break; 
                case '*':   sprintf(buff, "\tmul"); msgs.push_back(buff); break;
                case '/':   sprintf(buff, "\tdiv"); msgs.push_back(buff); break;
                case '<':   sprintf(buff, "\tcompLT"); msgs.push_back(buff); break;
                case '>':   sprintf(buff, "\tcompGT"); msgs.push_back(buff); break;
                case GE:    sprintf(buff, "\tcompGE"); msgs.push_back(buff); break;
                case LE:    sprintf(buff, "\tcompLE"); msgs.push_back(buff); break;
                case NE:    sprintf(buff, "\tcompNE"); msgs.push_back(buff); break;
                case EQ:    sprintf(buff, "\tcompEQ"); msgs.push_back(buff); break;
            }
            int type = std::max(type1, type2);
            msgs.back() += "_" + intToType(type) + "\n";
            return type;
        }
    }
    return 0;
}

void logError(const std::string& msg) {
    sprintf(buff, "%s\n", msg.c_str());msgs.push_back(buff);
    // print other error parameters here.
}

std::string intToType(int type)
{
    switch (type)
    {
    case VOID:
        logError("can't convert void");
        return "";
    case BOOL_TYPE:
        return "BOOL";
    case CHAR_TYPE:
        return "CHAR";
    case INT_TYPE:
        return "INT";
    case FLOAT_TYPE:
        return "FLOAT";
    }
    return "";
}