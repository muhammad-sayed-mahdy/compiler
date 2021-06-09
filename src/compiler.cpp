#include <stdio.h>
#include <algorithm>
#include "compiler.h"
#include "parser.hpp"
#include <string.h>
#include <algorithm>

static int lbl;
static int lvl = 0, mx_lvl = 0, const_assign = 0, glob_ass = 0;
static int numOfVars = 0, is_parm = 0, arg_num = 0;
static std::map<std::string, symbolEntry> temp_table[MAX_LEVEL];
static std::string cal_name;
char buff[100];
int type, type1, type2;

int ex(nodeType *p, int contLbl = -1, int breakLbl = -1) {
    int lbl1, lbl2, lbl3;

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
        {
            int ty = gtVarType(p);
            if(ty != -1){
                sprintf(buff, "\tpush_%s\t%s_%d\n", intToType(ty).c_str(), p->id.i, gtVarScope(p)); msgs.push_back(buff);
                return ty;
            }
            yyerror("use of undeclared variable");
            return VOID;
        }
        
        
    case typeOpr:
        if(!lvl && !((p->opr.oper >= VOID_FUNC && p->opr.oper <= FUNC_DEC) || (p->opr.oper >= DECL && p->opr.oper <= ASSIGN_CONST))){
            if(!glob_ass){
                yyerror("invalid global statement");
                return VOID;
            }
        }
        switch(p->opr.oper) {
        case BLOCK_STRUCTURE:
            lvl += 1;
            mx_lvl = std::max(mx_lvl, lvl);
            ex(p->opr.op[0], contLbl, breakLbl);
            temp_table[lvl].clear();
            lvl -= 1;
            break;
        case FUNC_DEC:
        {
            if(lvl) {
                yyerror("function declaration should be in global scope");
                return VOID;
            }
            addVar(p->opr.op[0]->opr.op[0], "Function");
            std::string fnm = p->opr.op[0]->opr.op[0]->id.i;
            msgs.push_back("PROC\t" + fnm + "\n");
            lvl += 1;
            mx_lvl = std::max(mx_lvl, lvl);
            is_parm = 1;
            ex(p->opr.op[1]);
            is_parm = 0;
            if(p->opr.op[2]->opr.oper == BLOCK_STRUCTURE)
                ex(p->opr.op[2]->opr.op[0]);
            else ex(p->opr.op[2]);
            temp_table[lvl].clear();
            lvl -= 1;
            msgs.push_back("ENDP\t" + fnm + "\n");
            break;
        }
        case VOID_FUNC:
        {
            if(lvl) {
                yyerror("function declaration should be in global scope");
                return VOID;
            }
            p->opr.op[0]->id.type = VOID;
            addVar(p->opr.op[0], "Function");
            std::string fnm = p->opr.op[0]->id.i;
            msgs.push_back("PROC\t" + fnm + "\n");
            lvl += 1;
            mx_lvl = std::max(mx_lvl, lvl);
            is_parm = 1;
            ex(p->opr.op[1]);
            is_parm = 0;
            if(p->opr.op[2]->opr.oper == BLOCK_STRUCTURE)
                ex(p->opr.op[2]->opr.op[0]);
            else ex(p->opr.op[2]);
            temp_table[lvl].clear();
            lvl -= 1;
            msgs.push_back("ENDP\t" + fnm + "\n");
            break;
        }
        case PARAM_LIST:
            if(p->opr.nops > 0) ex(p->opr.op[0]);
            if(p->opr.nops > 1) ex(p->opr.op[1]);
            break;
        case ARG_LIST:
            if(p->opr.nops > 0){
                arg_num++;
                if(arg_num > parm_types[cal_name].size()){
                    yyerror("More Arguements than function definition");
                    break;
                }
                if(p->opr.nops > 1) ex(p->opr.op[1]);
                else if(arg_num < parm_types[cal_name].size()){
                    yyerror("Less Arguements than function definition");
                }
                int ty = ex(p->opr.op[0]);
                arg_num--;
                if (ty != parm_types[cal_name][arg_num])
                    msgs.push_back("\t" + intToType(ty) + "_TO_" + intToType(parm_types[cal_name][arg_num]) + "\n");
            }
            else{
                if(arg_num < parm_types[cal_name].size()){
                    yyerror("Less Arguements than function definition");
                }
            }
            break;
        case CAL:
        {
            std::string fname = p->opr.op[0]->id.i;
            auto itr = parm_types.find(fname);
            if(itr == parm_types.end()){
                yyerror("cal to undefined function");
                break;
            }

            int typ = temp_table[0].find(fname)->second.type;

            int old_arg_num = arg_num;
            std::string old_cal_name = cal_name;
            arg_num = 0, cal_name = fname;

            ex(p->opr.op[1]);

            arg_num = old_arg_num;
            cal_name = old_cal_name;

            msgs.push_back("\tCALL\t" + fname +"\n");
            return typ;
        }
        case RETURN:
            {
                std::string fnm = func_names.back();
                int typ = temp_table[0].find(fnm)->second.type;
                if(p->opr.nops == 0 && typ != VOID){
                    yyerror("expected return value");
                    return VOID;
                }
                if(p->opr.nops > 0 && typ == VOID){
                    yyerror("invalid return statement for void expression");
                    return VOID;
                }
                if(p->opr.nops){
                    int exptyp = ex(p->opr.op[0]);
                    if(exptyp != typ){
                        msgs.push_back("\t" + intToType(exptyp) + "_TO_" + intToType(typ) + "\n");
                    }
                }
                msgs.push_back("\tRETURN\n");
            }
            break;
        case DECL:
            addVar(p->opr.op[0], "Variable");
            if(is_parm){
                int ty = p->opr.op[0]->id.type; parm_types[func_names.back()].push_back(ty);
                sprintf(buff, "\tpop_%s\t%s_%d\n", intToType(ty).c_str(), p->opr.op[0]->id.i, 1);msgs.push_back(buff);
            }
            break;
        case DECL_CONST:
            addVar(p->opr.op[0], "Constant");
            if(is_parm){
                int ty = p->opr.op[0]->id.type; parm_types[func_names.back()].push_back(ty);
                sprintf(buff, "\tpop_%s\t%s_%d\n", intToType(ty).c_str(), p->opr.op[0]->id.i, 1);msgs.push_back(buff);
            }
            break;
        case ASSIGN:
            addVar(p->opr.op[0], "Variable");
            if(is_parm){
                int ty = p->opr.op[0]->id.type; parm_types[func_names.back()].push_back(ty);
                sprintf(buff, "\tpop_%s\t%s_%d\n", intToType(ty).c_str(), p->opr.op[0]->id.i, 1);msgs.push_back(buff);
                yyerror("default function parameters are not allowed");
                break;
            }
            glob_ass = 1;
            ex(p->opr.op[1]);
            glob_ass = 0;
            break;
        case ASSIGN_CONST:
            addVar(p->opr.op[0], "Constant");
            if(is_parm){
                int ty = p->opr.op[0]->id.type; parm_types[func_names.back()].push_back(ty);
                sprintf(buff, "\tpop_%s\t%s_%d\n", intToType(ty).c_str(), p->opr.op[0]->id.i, 1);msgs.push_back(buff);
                yyerror("default function parameters are not allowed");
                break;
            }
            glob_ass = 1;
            const_assign = 1;
            ex(p->opr.op[1]);
            const_assign = 0;
            glob_ass = 0;
            break;
        case CONTINUE:
            if (contLbl == -1)
                yyerror("continue statement not within a loop");
            sprintf(buff, "\tJMP\tL%03d\n", contLbl);msgs.push_back(buff);
            break;
        case BREAK:
            if (breakLbl == -1)
                yyerror("break statement not within loop or switch");
            sprintf(buff, "\tJMP\tL%03d\n", breakLbl);msgs.push_back(buff);
            break;
        case WHILE:
            lvl += 1;
            mx_lvl = std::max(mx_lvl, lvl);
            sprintf(buff, "L%03d:\n", lbl1 = lbl++);msgs.push_back(buff);
            type = ex(p->opr.op[0]);
            if (type != BOOL_TYPE)
                msgs.push_back("\t"+intToType(type)+"_TO_BOOL\n");
            sprintf(buff, "\tJZ\tL%03d\n", lbl2 = lbl++);msgs.push_back(buff);
            if(p->opr.op[1]->opr.oper == BLOCK_STRUCTURE)
                ex(p->opr.op[1]->opr.op[0], lbl1, lbl2);
            else
                ex(p->opr.op[1], lbl1, lbl2);
            sprintf(buff, "\tJMP\tL%03d\n", lbl1);msgs.push_back(buff);
            sprintf(buff, "L%03d:\n", lbl2);msgs.push_back(buff);
            temp_table[lvl].clear();
            lvl -= 1;
            break;
        case DO:
            lvl += 1;
            mx_lvl = std::max(mx_lvl, lvl);
            sprintf(buff, "L%03d:\n", lbl1 = lbl++);msgs.push_back(buff);
            if(p->opr.op[0]->opr.oper == BLOCK_STRUCTURE)
                ex(p->opr.op[0]->opr.op[0], lbl2 = lbl++, lbl3 = lbl++);
            else
                ex(p->opr.op[0], lbl2 = lbl++, lbl3 = lbl++);
            sprintf(buff, "L%03d:\n", lbl2);msgs.push_back(buff);
            type = ex(p->opr.op[1]);
            if (type != BOOL_TYPE)
                msgs.push_back("\t"+intToType(type)+"_TO_BOOL\n");
            sprintf(buff, "\tJNZ\tL%03d\n", lbl1);msgs.push_back(buff);
            sprintf(buff, "L%03d:\n", lbl3);msgs.push_back(buff);
            temp_table[lvl].clear();
            lvl -= 1;
            break;
        case FOR:
            lvl += 1;
            mx_lvl = std::max(mx_lvl, lvl);
            ex(p->opr.op[0]);
            sprintf(buff, "L%03d:\n", lbl1 = lbl++);msgs.push_back(buff);
            type = ex(p->opr.op[1]);
            if (type != BOOL_TYPE)
                msgs.push_back("\t"+intToType(type)+"_TO_BOOL\n");
            sprintf(buff, "\tJZ\tL%03d\n", lbl2 = lbl++);msgs.push_back(buff);
            if(p->opr.op[3]->opr.oper == BLOCK_STRUCTURE)
                ex(p->opr.op[3]->opr.op[0], lbl1, lbl2);
            else
                ex(p->opr.op[3], lbl1, lbl2);
            ex(p->opr.op[2]);
            sprintf(buff, "\tJMP\tL%03d\n", lbl1);msgs.push_back(buff);
            sprintf(buff, "L%03d:\n", lbl2);msgs.push_back(buff);
            temp_table[lvl].clear();
            lvl -= 1;
            break;
        case IF:
            lvl += 1;
            mx_lvl = std::max(mx_lvl, lvl);
            type = ex(p->opr.op[0]);
            if (type != BOOL_TYPE)
                msgs.push_back("\t"+intToType(type)+"_TO_BOOL\n");
            if (p->opr.nops > 2) {
                /* if else */
                sprintf(buff, "\tJZ\tL%03d\n", lbl1 = lbl++);msgs.push_back(buff);
                if(p->opr.op[1]->opr.oper == BLOCK_STRUCTURE)
                    ex(p->opr.op[1]->opr.op[0], contLbl, breakLbl);
                else
                    ex(p->opr.op[1], contLbl, breakLbl);
                sprintf(buff, "\tJMP\tL%03d\n", lbl2 = lbl++);msgs.push_back(buff);
                sprintf(buff, "L%03d:\n", lbl1);msgs.push_back(buff);
                if(p->opr.op[2]->opr.oper == BLOCK_STRUCTURE)
                    ex(p->opr.op[2]->opr.op[0], contLbl, breakLbl);
                else
                    ex(p->opr.op[2], contLbl, breakLbl);
                sprintf(buff, "L%03d:\n", lbl2);msgs.push_back(buff);
            } else {
                /* if */
                sprintf(buff, "\tJZ\tL%03d\n", lbl1 = lbl++);msgs.push_back(buff);
                if(p->opr.op[1]->opr.oper == BLOCK_STRUCTURE)
                    ex(p->opr.op[1]->opr.op[0], contLbl, breakLbl);
                else
                    ex(p->opr.op[1], contLbl, breakLbl);
                sprintf(buff, "L%03d:\n", lbl1);msgs.push_back(buff);
            }
            temp_table[lvl].clear();
            lvl -= 1;
            break;
        case SWITCH:
            {
                int fstlbl = lbl;
                for (int i = 0; i < p->opr.op[1]->con.value.valInt; i++)
                {
                    if(p->opr.op[2+i*3]->con.value.valInt == CASE){
                        ex(p->opr.op[3+i*3]);
                        sprintf(buff, "\tJNZ\tL%03d\n", lbl++);msgs.push_back(buff);
                    }
                    else{
                        sprintf(buff, "\tJMP\tL%03d\n", lbl++);msgs.push_back(buff);
                    }
                }
                sprintf(buff, "\tJMP\tL%03d\n", lbl++);msgs.push_back(buff);
                for (int i = 0; i < p->opr.op[1]->con.value.valInt; i++)
                {
                    sprintf(buff, "L%03d\n", fstlbl+i);msgs.push_back(buff);
                    lvl += 1;
                    mx_lvl = std::max(mx_lvl, lvl);
                    if(p->opr.op[2+i*3]->con.value.valInt == CASE)
                        ex(p->opr.op[4+i*3], -1, fstlbl+p->opr.op[1]->con.value.valInt);
                    else
                        ex(p->opr.op[3+i*3], -1, fstlbl+p->opr.op[1]->con.value.valInt);
                    temp_table[lvl].clear();
                    lvl -= 1;
                }
                sprintf(buff, "L%03d\n", fstlbl+p->opr.op[1]->con.value.valInt);msgs.push_back(buff);
            }
            break;
        case PRINT:     
            type = ex(p->opr.op[0]);
            sprintf(buff, "\tPRINT_%s\n", intToType(type).c_str());msgs.push_back(buff);
            break;
        case '=':       
            type1 = ex(p->opr.op[1]);
            {
                int i = lvl;
                for(; ~i; --i){
                    auto itr = temp_table[i].find(strdup(p->opr.op[0]->id.i));
                    if(itr != temp_table[i].end()){
                        if(itr->second.symbolType == "Constant" && !const_assign)
                            yyerror("invalid assignment to constant after declaration");
                        p->opr.op[0]->id.type = itr->second.type;
                        type2 = p->opr.op[0]->id.type;
                        if (type1 != type2)
                            msgs.push_back("\t" + intToType(type1) + "_TO_" + intToType(type2) + "\n");
                        sprintf(buff, "\tpop_%s\t%s_%d\n", intToType(type2).c_str(), p->opr.op[0]->id.i, i);msgs.push_back(buff);
                        return type2;
                    }
                }
            }
            yyerror("use of undeclared variable");
            return VOID;
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
        case ';':
            ex(p->opr.op[0], contLbl, breakLbl);
            ex(p->opr.op[1], contLbl, breakLbl);
            return VOID;
        case PRE_INC:
        {
            int sc = gtVarScope(p->opr.op[0]), ty = gtVarType(p->opr.op[0]);
            msgs.push_back("\tINC_" + intToType(ty) + "\t" + p->opr.op[0]->id.i + "\n");
            ex(p->opr.op[0]);
            break;
        }
        case POST_INC:
        {
            ex(p->opr.op[0]);
            int sc = gtVarScope(p->opr.op[0]), ty = gtVarType(p->opr.op[0]);
            msgs.push_back("\tINC_" + intToType(ty) + "\t" + p->opr.op[0]->id.i + "\n");
            break;
        }
        case PRE_DEC:
        {
            int sc = gtVarScope(p->opr.op[0]), ty = gtVarType(p->opr.op[0]);
            msgs.push_back("\tDEC_" + intToType(ty) + "\t" + p->opr.op[0]->id.i + "\n");
            ex(p->opr.op[0]);
            break;
        }
        case POST_DEC:
        {
            ex(p->opr.op[0]);
            int sc = gtVarScope(p->opr.op[0]), ty = gtVarType(p->opr.op[0]);
            msgs.push_back("\tDEC_" + intToType(ty) + "\t" + p->opr.op[0]->id.i + "\n");
            break;
        }
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


std::string intToType(int type, int f)
{
    switch (type)
    {
    case VOID:
        if(f) return "VOID ";
        yyerror("can't convert void");
        return "";
    case BOOL_TYPE:
        return "BOOL ";
    case CHAR_TYPE:
        return "CHAR ";
    case INT_TYPE:
        return "INT  ";
    case FLOAT_TYPE:
        return "FLOAT";
    }
    return "";
}

void printSymbolTable(){
    std::vector<symbolEntry> sytable;
    for(int i = 0; i <= mx_lvl; ++i){
        for (auto x: symbol_table[i]){
            sytable.push_back(x.second);
        }
    }
    auto compFunc = [](symbolEntry a, symbolEntry b){
        return a.timestamp < b.timestamp;
    };
    std::sort(sytable.begin(), sytable.end(), compFunc);
    printf("Function\t|\tScope\t|\tSymbol Type\t|\tReturn Type\t|\t\t\t\tName\n");
    for(auto i : sytable){
        printf("\n%s\t\t|\t%d\t\t|\t%s\t|\t%s\t\t|", i.funcName.c_str(), i.scope, i.symbolType.c_str(), intToType(i.type,1).c_str());
        for(int j = 0; j < i.scope; ++j) printf("\t");
        printf("%s\n", i.name.c_str());
    }
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

void addVar(nodeType* p, std::string sytyp){
    std::string fn = (lvl)? func_names.back(): "Global";
    auto itr = temp_table[lvl].find(strdup(p->id.i));
    if(itr != temp_table[lvl].end()){
        yyerror("multiple declaration of same variable");
        return;
    }
    if(sytyp == "Function")
        func_names.push_back(p->id.i);
    symbolEntry* se = new symbolEntry(strdup(p->id.i), p->id.type, sytyp, lvl, numOfVars++, fn);
    symbol_table[lvl].insert({{strdup(p->id.i),numOfVars}, *se});
    temp_table[lvl].insert({strdup(p->id.i), *se});
}


int gtVarType(nodeType* p){
    int i = lvl;
    for(; ~i; --i){
        auto itr = temp_table[i].find(strdup(p->id.i));
        if(itr != temp_table[i].end()){
            return itr->second.type;
        }
    }
    return -1;
}
int gtVarScope(nodeType* p){
    int i = lvl;
    for(; ~i; --i){
        auto itr = temp_table[i].find(strdup(p->id.i));
        if(itr != temp_table[i].end()){
            break;
        }
    }
    return i;
}


/*
    int i = lvl;
    for(; ~i; --i){
        auto itr = temp_table[i].find(strdup(p->id.i));
        if(itr != temp_table[i].end()){
            p->id.type = itr->second.type;
            sprintf(buff, "\tpush_%s\t%s_%d\n", intToType(p->id.type).c_str(), p->id.i, i); msgs.push_back(buff);
            return p->id.type;
        }
    }
// function test case
int x = 5;
int my_func(char r = 5, bool v){
    int y = x;
    int x = 6;
    return x+y+r+v;
}
char f = my_func(5,3);
char p = my_func(my_func(x,x),3);
char my_fun(char r, bool v){
    int y = x;
    int x = 6;
    return my_fun(x,y) + my_func(v,r);
}
*/