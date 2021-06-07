#include <stdio.h>
#include "compiler.h"
#include "parser.hpp"
#include <string.h>
#include <algorithm>

const int MAX_LEVEL = 101;
static int lbl;
static int lvl = 0, mx_lvl = 0;
static int numOfVars = 0;
static std::map<std::string, symbolEntry> symbol_table[MAX_LEVEL], temp_table[MAX_LEVEL];
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
        {
            int i = lvl;
            for(; ~i; --i){
                auto itr = temp_table[i].find(strdup(p->id.i));
                if(itr != temp_table[i].end()){
                    p->id.type = itr->second.type;
                    sprintf(buff, "\tpush_%s\t%s_%d\n", intToType(p->id.type).c_str(), p->id.i, i); msgs.push_back(buff);
                    return p->id.type;
                }
            }
            logError("use of un declared variable");
            return INT_TYPE;
        }
        
    case typeOpr:
        switch(p->opr.oper) {
        case BLOCK_STRUCTURE:
            lvl += 1;
            mx_lvl = std::max(mx_lvl, lvl);
            ex(p->opr.op[0]);
            temp_table[lvl].clear();
            lvl -= 1;
            break;
        case DECL:
            {
                symbolEntry* se = new symbolEntry(strdup(p->opr.op[0]->id.i), p->opr.op[0]->id.type, "Variable", lvl, numOfVars++);
                symbol_table[lvl].insert({strdup(p->opr.op[0]->id.i), *se});
                temp_table[lvl].insert({strdup(p->opr.op[0]->id.i), *se});
            }
            break;
        case DECL_CONST:
            {
                symbolEntry* se = new symbolEntry(strdup(p->opr.op[0]->id.i), p->opr.op[0]->id.type, "Constant", lvl, numOfVars++);
                symbol_table[lvl].insert({strdup(p->opr.op[0]->id.i), *se});
                temp_table[lvl].insert({strdup(p->opr.op[0]->id.i), *se});
            }
            break;
        case ASSIGN:
            {
                symbolEntry* se = new symbolEntry(strdup(p->opr.op[0]->id.i), p->opr.op[0]->id.type, "Variable", lvl, numOfVars++);
                symbol_table[lvl].insert({strdup(p->opr.op[0]->id.i), *se});
                temp_table[lvl].insert({strdup(p->opr.op[0]->id.i), *se});
            }
            ex(p->opr.op[1]);
            break;
        case ASSIGN_CONST:
            {
                symbolEntry* se = new symbolEntry(strdup(p->opr.op[0]->id.i), p->opr.op[0]->id.type, "Constant", lvl, numOfVars++);
                symbol_table[lvl].insert({strdup(p->opr.op[0]->id.i), *se});
                temp_table[lvl].insert({strdup(p->opr.op[0]->id.i), *se});
            }
            ex(p->opr.op[1]);
            break;
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
            {
                int i = lvl;
                for(; ~i; --i){
                    auto itr = temp_table[i].find(strdup(p->opr.op[0]->id.i));
                    if(itr != temp_table[i].end()){
                        p->opr.op[0]->id.type = itr->second.type;
                        type2 = p->opr.op[0]->id.type;
                        if (type1 != type2)
                            msgs.push_back("\t" + intToType(type1) + "_TO_" + intToType(type2) + "\n");
                        sprintf(buff, "\tpop_%s\t%s_%d\n", intToType(type2).c_str(), p->opr.op[0]->id.i, i);msgs.push_back(buff);
                        return type2;
                    }
                }
            }
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
    printf("Scope\t|\tSymbol Type\t|\tReturn Type\t|\t\t\t\tName\n");
    for(auto i : sytable){
        printf("\n%d\t|\t%s\t|\t%s\t\t|", i.scope, i.symbolType.c_str(), intToType(i.type).c_str());
        for(int j = 0; j < i.scope; ++j) printf("\t");
        printf("%s\n", i.name.c_str());
    }
}
/*

Scope   symbolType      Type      Name

0       const           int         x
1       variable        int                 y
2       variable        int                         z
1       variable        int                 n

{
int x = 0;
char y = x;
{
int z = x+y;
}
const float n = x;
}
*/
