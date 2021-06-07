#include <stdio.h>
#include <algorithm>
#include "compiler.h"
#include "parser.hpp"

static int lbl;
char buff[100];
int type, type1, type2;

int ex(nodeType *p) {
    int lbl1, lbl2;

    if (!p) return VOID;
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
            type = ex(p->opr.op[0]);
            sprintf(buff, "\tNEG_%s\n", intToType(type).c_str());msgs.push_back(buff);
            return type;
        case '!':
            type = ex(p->opr.op[0]);
            if (type != BOOL_TYPE)
                msgs.push_back("\t"+intToType(type)+"_TO_BOOL\n");
            msgs.push_back("\tNOT_BOOL\n");
            return BOOL_TYPE;
        case '~':
            type = ex(p->opr.op[0]);
            if (type == FLOAT_TYPE)
                yyerror("Expression must have integral type");
            msgs.push_back("\tBIT_NOT_"+intToType(type)+'\n');
            return type;
        default:
            type1 = ex(p->opr.op[0]);
            int sz1 = msgs.size();
            type2 = ex(p->opr.op[1]);
            if (isIntOper(p->opr.oper) && std::max(type1, type2) == FLOAT_TYPE)
                yyerror("Expression must have integral type");
            else if (isLogicalOper(p->opr.oper))
            {
                if (type1 != BOOL_TYPE)
                    msgs.insert(msgs.begin()+sz1, "\t"+intToType(type1)+"_TO_BOOL\n"), type1 = BOOL_TYPE;
                if (type2 != BOOL_TYPE)
                    msgs.push_back("\t"+intToType(type2)+"_TO_BOOL\n"), type2 = BOOL_TYPE;
            }
            else
            {
                if (type1 < type2) {
                    std::string convertOp = "\t" + intToType(type1) + "_TO_" + intToType(type2) + "\n";
                    msgs.insert(msgs.begin()+sz1, convertOp), type1 = type2;
                } else if (type2 < type1) {
                    std::string convertOp = "\t" + intToType(type2) + "_TO_" + intToType(type1) + "\n";
                    msgs.push_back(convertOp), type2 = type1;
                }
            }
            

            switch(p->opr.oper) {
                case '+':   sprintf(buff, "\tADD"); msgs.push_back(buff); break;
                case '-':   sprintf(buff, "\tSUB"); msgs.push_back(buff); break; 
                case '*':   sprintf(buff, "\tMUL"); msgs.push_back(buff); break;
                case '/':   sprintf(buff, "\tDIV"); msgs.push_back(buff); break;
                case '%':   sprintf(buff, "\tMOD"); msgs.push_back(buff); break;
                case '<':   sprintf(buff, "\tLT"); msgs.push_back(buff); break;
                case '>':   sprintf(buff, "\tGT"); msgs.push_back(buff); break;
                case GE:    sprintf(buff, "\tGE"); msgs.push_back(buff); break;
                case LE:    sprintf(buff, "\tLE"); msgs.push_back(buff); break;
                case NE:    sprintf(buff, "\tNE"); msgs.push_back(buff); break;
                case EQ:    sprintf(buff, "\tEQ"); msgs.push_back(buff); break;
                case '&':    sprintf(buff, "\tBIT_AND"); msgs.push_back(buff); break;
                case '|':    sprintf(buff, "\tBIT_OR"); msgs.push_back(buff); break;
                case '^':    sprintf(buff, "\tBIT_XOR"); msgs.push_back(buff); break;
                case SHIFT_LEFT:    sprintf(buff, "\tSHL"); msgs.push_back(buff); break;
                case SHIFT_RIGHT:    sprintf(buff, "\tSHR"); msgs.push_back(buff); break;
                case AND:    sprintf(buff, "\tAND"); msgs.push_back(buff); break;
                case OR:    sprintf(buff, "\tOR"); msgs.push_back(buff); break;
            }
            
            msgs.back() += "_" + intToType(type1) + "\n";
            if (isRelationalOper(p->opr.oper) || isLogicalOper(p->opr.oper))
                return BOOL_TYPE;
            return type1;
        }
    }
    return VOID;
}


std::string intToType(int type)
{
    switch (type)
    {
    case VOID:
        yyerror("can't convert void");
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

bool isRelationalOper(int oper)
{
    int operators[] = {'<', '>', GE, LE, NE, EQ };
    return std::find(operators, operators+6, oper) != operators+6;
}

bool isIntOper(int oper)
{
    int operators[] = {SHIFT_LEFT, SHIFT_RIGHT, '%', '|', '^', '&', '~'};
    return std::find(operators, operators+7, oper) != operators+7;
}

bool isLogicalOper(int oper)
{
    int operators[] = {AND, OR, '!'};
    return std::find(operators, operators+3, oper) != operators+3;
}