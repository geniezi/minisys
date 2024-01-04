#ifndef _ACTION_YACC_H
#define _ACTION_YACC_H
#include "structDefine.h"
#include "supportFunction.h"
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>
using namespace std;extern unsigned int offset;
string p;
extern vector<string> filelist;
extern deque<StackItem> st;
extern stack<string> paramStack;
pair<unsigned int, string> performAction(unsigned int index, map<string, string>& reduceHead) {
	size_t stackSize = st.size() - 1;
	switch(index) {
	case 0 ://S->program 
		emit("nop", "", "", "");
	return pair<unsigned int, string>(1,"S");

	case 1 ://program->stmts 
		backpatch(st[stackSize - 1 + 1]._map["nextlist"], "LABEL_"+gen(nextInstr));
	return pair<unsigned int, string>(1,"program");

	case 2 ://stmts->stmts M stmt 
 backpatch(st[stackSize - 3 + 1]._map["nextlist"], st[stackSize - 3 + 2]._map["instr"]);
 reduceHead["nextlist"] = st[stackSize - 3 + 3]._map["nextlist"];

	return pair<unsigned int, string>(3,"stmts");

	case 3 ://stmts->stmt 
		backpatch(st[stackSize - 1+ 1]._map["nextlist"], "LABEL_" + gen(nextInstr));
 
	return pair<unsigned int, string>(1,"stmts");

	case 4 ://stmt->includestmt 

	return pair<unsigned int, string>(1,"stmt");

	case 5 ://stmt->{ stmts } 
 reduceHead["nextlist"] = st[stackSize - 3 + 2]._map["nextlist"];
 
	return pair<unsigned int, string>(3,"stmt");

	case 6 ://stmt->fun_define 
	returnToGlobalTable();
	reduceHead["nextlist"] = st[stackSize - 1 + 1]._map["nextlist"];
	return pair<unsigned int, string>(1,"stmt");

	case 7 ://stmt->if_stmt 
 reduceHead["nextlist"] = st[stackSize - 1 + 1]._map["nextlist"];
	return pair<unsigned int, string>(1,"stmt");

	case 8 ://stmt->while_stmt 
 reduceHead["nextlist"] = st[stackSize - 1 + 1]._map["nextlist"];
 
	return pair<unsigned int, string>(1,"stmt");

	case 9 ://stmt->var_decl ; 
 reduceHead["nextlist"] = st[stackSize - 2 + 1]._map["nextlist"];
 
	return pair<unsigned int, string>(2,"stmt");

	case 10 ://stmt->static var_decl ; 
 reduceHead["nextlist"] = st[stackSize - 3 + 2]._map["nextlist"];
 
	return pair<unsigned int, string>(3,"stmt");
 
	case 11 ://stmt->expr_stmt ; 
		reduceHead["nextlist"] = st[stackSize - 2 + 1]._map["nextlist"];
	return pair<unsigned int, string>(2,"stmt");

	case 12 ://stmt->return expr ; 
 emit("return",st[stackSize - 3 + 2]._map["place"],"","");
 		//setOutLiveVar(st[stackSize - 3 + 2]._map["place"]);
 	
	return pair<unsigned int, string>(3,"stmt");

	case 13 ://includestmt->include " filename " 
 filelist.push_back(st[stackSize - 4 + 3]._map["lexeme"]);

	return pair<unsigned int, string>(4,"includestmt");

	case 14 ://includestmt->include < filename > 
 filelist.push_back(st[stackSize - 4 + 3]._map["lexeme"]);

	return pair<unsigned int, string>(4,"includestmt");

	case 15 ://fun_define->fun_decl_head BlockLeader { stmts } 
 reduceHead["name"] = st[stackSize - 5 + 1]._map["name"];
 reduceHead["nextlist"] = st[stackSize - 5 + 4]._map["nextlist"];
 
	return pair<unsigned int, string>(5,"fun_define");

	case 16 ://fun_decl_head->type_spec id ( ) 
 reduceHead["name"] = st[stackSize - 4 + 2]._map["lexeme"];
 					 createSymbolTable(st[stackSize - 4 + 2]._map["lexeme"], atoi(st[stackSize - 4 + 1]._map["width"].c_str()));
 					 addFunLabel(nextInstr, st[stackSize - 4 + 2]._map["lexeme"]);

	return pair<unsigned int, string>(4,"fun_decl_head");

	case 17 ://fun_decl_head->type_spec id ( param_list ) 
 			reduceHead["name"] = st[stackSize - 5 + 2]._map["lexeme"];
 			createSymbolTable(st[stackSize - 5 + 2]._map["lexeme"], atoi(st[stackSize - 5 + 1]._map["width"].c_str()));
 			addToSymbolTable(st[stackSize - 5 + 4]._map["itemlist"]);
 			addFunLabel(nextInstr, st[stackSize - 5 + 2]._map["lexeme"]);

	return pair<unsigned int, string>(5,"fun_decl_head");

	case 18 ://param_list->param_list , param 
 reduceHead["itemlist"] = st[stackSize - 3 + 1]._map["itemlist"]  +  st[stackSize - 3 + 3]._map["itemlist"];
 
	return pair<unsigned int, string>(3,"param_list");

	case 19 ://param_list->param 
 reduceHead["itemlist"] = st[stackSize - 1 + 1]._map["itemlist"];
 
	return pair<unsigned int, string>(1,"param_list");

	case 20 ://param->type_spec id 
 reduceHead["itemlist"] = makeParam(st[stackSize - 2 + 2]._map["lexeme"],st[stackSize - 2 + 1]._map["type"],atoi(st[stackSize - 2 + 1]._map["width"].c_str()));
 
	return pair<unsigned int, string>(2,"param");

	case 21 ://param->type_spec id [ num ] 
			reduceHead["itemlist"] = makeParam(st[stackSize - 5 + 2]._map["lexeme"],make_array(atoi(st[stackSize - 5 + 4]._map["lexeme"].c_str()),st[stackSize - 5 + 1]._map["type"]),			atoi(st[stackSize - 5 + 4]._map["lexeme"].c_str()) * atoi(st[stackSize - 5 + 1]._map["width"].c_str()));
 			
	return pair<unsigned int, string>(5,"param");

	case 22 ://var_decl->type_spec id 
enter(st[stackSize - 2 + 2]._map["lexeme"],st[stackSize - 2 + 1]._map["type"],atoi(st[stackSize - 2 + 1]._map["width"].c_str()));
 
	return pair<unsigned int, string>(2,"var_decl");

	case 23 ://var_decl->type_spec id = expr 
		p = enter(st[stackSize - 4 + 2]._map["lexeme"],st[stackSize - 4 + 1]._map["type"],atoi(st[stackSize - 4 + 1]._map["width"].c_str()));
 		emit("MOV",st[stackSize - 4 + 4]._map["place"],"",p);
 		
	return pair<unsigned int, string>(4,"var_decl");

	case 24 ://var_decl->type_spec id [ num ] 
		enter(st[stackSize - 5 + 2]._map["lexeme"],make_array(atoi(st[stackSize - 5 + 4]._map["lexeme"].c_str()),st[stackSize - 5 + 1]._map["type"]),atoi(st[stackSize - 5 + 4]._map["lexeme"].c_str()) * atoi(st[stackSize - 5 + 1]._map["width"].c_str()));
 	
	return pair<unsigned int, string>(5,"var_decl");

	case 25 ://type_spec->int 
 reduceHead["type"] = "int";
		    reduceHead["width"] = "4";
		   
	return pair<unsigned int, string>(1,"type_spec");

	case 26 ://type_spec->double 
	reduceHead["type"] = "double";
			reduceHead["width"] = "8";
		      
	return pair<unsigned int, string>(1,"type_spec");

	case 27 ://type_spec->void 
 reduceHead["type"] = "void";
		    reduceHead["width"] = "0";
		    
	return pair<unsigned int, string>(1,"type_spec");

	case 28 ://type_spec->char 
 reduceHead["type"] = "char";
		    reduceHead["width"] = "1";
		    
	return pair<unsigned int, string>(1,"type_spec");

	case 29 ://type_spec->bool 
 reduceHead["type"] = "bool";
		    reduceHead["width"] = "1";
		    
	return pair<unsigned int, string>(1,"type_spec");

	case 30 ://type_spec->float 
 reduceHead["type"] = "float";
		    reduceHead["width"] = "4";
		    
	return pair<unsigned int, string>(1,"type_spec");

	case 31 ://expr_stmt->id = expr 
 			p = lookupPlace(st[stackSize - 3 + 1]._map["lexeme"]);
 			if (p.empty()) error("undefined variable used");
 			emit("MOV",st[stackSize - 3 + 3]._map["place"],"",p);
 			
	return pair<unsigned int, string>(3,"expr_stmt");

	case 32 ://expr_stmt->id [ expr ] = expr 
			{				string ty=getType(st[stackSize - 6 + 1]._map["lexeme"]);
				if(ty.find("array")==ty.npos) error(ty+"cannot be converted to array");
				emit("MOVaddr",lookupPlace(st[stackSize - 6 + 1]._map["lexeme"]),st[stackSize - 6 + 3]._map["place"],"");
				emit("MOVoff","",st[stackSize - 6 + 6]._map["place"],lookupPlace(st[stackSize - 6 + 1]._map["lexeme"]));
			}			
	return pair<unsigned int, string>(6,"expr_stmt");

	case 33 ://expr->expr + expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("add", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
                     
	return pair<unsigned int, string>(3,"expr");

	case 34 ://expr->expr - expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("sub", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
                     
	return pair<unsigned int, string>(3,"expr");

	case 35 ://expr->expr * expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("mul", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
                     
	return pair<unsigned int, string>(3,"expr");

	case 36 ://expr->expr / expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("div", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
                     
	return pair<unsigned int, string>(3,"expr");

	case 37 ://expr->expr % expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("rem", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
                     
	return pair<unsigned int, string>(3,"expr");

	case 38 ://expr->expr & expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("and", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
                     
	return pair<unsigned int, string>(3,"expr");

	case 39 ://expr->expr | expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("or", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
			                     
	return pair<unsigned int, string>(3,"expr");

	case 40 ://expr->expr ^ expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("xor", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
                     
	return pair<unsigned int, string>(3,"expr");

	case 41 ://expr->expr >> expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("srl", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
                      
	return pair<unsigned int, string>(3,"expr");

	case 42 ://expr->expr << expr 
                	reduceHead["place"] = newtemp(st[stackSize - 3 + 1]._map["place"]);
			emit("sll", st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], reduceHead["place"]);
                      
	return pair<unsigned int, string>(3,"expr");

	case 43 ://expr->( expr ) 
                	reduceHead["place"] = st[stackSize - 3 + 2]._map["place"];
                     
	return pair<unsigned int, string>(3,"expr");

	case 44 ://expr->id 
			reduceHead["place"] = lookupPlace(st[stackSize - 1 + 1]._map["lexeme"]);
            	     
	return pair<unsigned int, string>(1,"expr");

	case 45 ://expr->id ( arg_list ) 
				p = gen(paramStack.size());
				while (!paramStack.empty()) {				    emit("param", paramStack.top(),"","");
				    paramStack.pop();
			        }				emit("call", p, st[stackSize - 4 + 1]._map["lexeme"],"");
				enter("#","int",4);
				reduceHead["place"] = newtemp("int");
				emit("MOV","#","",reduceHead["place"]);
 
	return pair<unsigned int, string>(4,"expr");

	case 46 ://expr->num 
		reduceHead["lexval"] = st[stackSize - 1 + 1]._map["lexeme"];
		reduceHead["place"] = addNum(st[stackSize - 1 + 1]._map["lexeme"]);
	     
	return pair<unsigned int, string>(1,"expr");

	case 47 ://expr->- expr 
		reduceHead["place"] = newtemp(st[stackSize - 2 + 2]._map["place"]);
		emit("neg",st[stackSize - 2 + 2]._map["place"],"",reduceHead["place"]);
	
	return pair<unsigned int, string>(2,"expr");

	case 48 ://expr->id [ expr ] 
		{			string ty=getType(st[stackSize - 4 + 1]._map["lexeme"]);
			if(ty.find("array")==ty.npos) error(ty+"cannot be converted to array");
			int p1=ty.find('<');
			int p2=ty.find(',');
			reduceHead["place"] = newtemp(ty.substr(p1+1,p2-p1-1));
			emit("MOVaddr",lookupPlace(st[stackSize - 4 + 1]._map["lexeme"])	,st[stackSize - 4 + 3]._map["place"],"");
			emit("MOVoff",reduceHead["place"],"",lookupPlace(st[stackSize - 4 + 1]._map["lexeme"]));
		}	
	return pair<unsigned int, string>(4,"expr");

	case 49 ://arg_list->arg_list , expr 
 paramStack.push(st[stackSize - 3 + 3]._map["place"]);
 
	return pair<unsigned int, string>(3,"arg_list");

	case 50 ://arg_list->expr 
 paramStack.push(st[stackSize - 1 + 1]._map["place"]);
	
	return pair<unsigned int, string>(1,"arg_list");

	case 51 ://arg_list->
 
	return pair<unsigned int, string>(0,"arg_list");

	case 52 ://if_stmt->if BlockLeader ( logic_expr ) M stmt 
							backpatch(st[stackSize - 7 + 4]._map["truelist"], st[stackSize - 7 + 6]._map["instr"]);
							reduceHead["nextlist"] = merge(st[stackSize - 7 + 4]._map["falselist"], st[stackSize - 7 + 7]._map["nextlist"]);
						     
	return pair<unsigned int, string>(7,"if_stmt");

	case 53 ://if_stmt->if BlockLeader ( logic_expr ) M stmt N else M stmt 
									backpatch(st[stackSize - 11 + 4]._map["truelist"], st[stackSize - 11 + 6]._map["instr"]);
									backpatch(st[stackSize - 11 + 4]._map["falselist"], st[stackSize - 11 + 10]._map["instr"]);
									reduceHead["nextlist"] = merge(merge(st[stackSize - 11 + 7]._map["nextlist"], st[stackSize - 11 + 8]._map["instr"]), st[stackSize - 11 + 11]._map["nextlist"]);
	return pair<unsigned int, string>(11,"if_stmt");

	case 54 ://while_stmt->while BlockLeader M ( logic_expr ) M stmt 
								backpatch(st[stackSize - 8 + 8]._map["nextlist"], st[stackSize - 8 + 3]._map["instr"]);
								backpatch(st[stackSize - 8 + 5]._map["truelist"], st[stackSize - 8 + 7]._map["instr"]);
								reduceHead["nextlist"] = st[stackSize - 8 + 5]._map["falselist"];
								emit("j","","",st[stackSize - 8 + 3]._map["instr"]);
								addToLabel(st[stackSize - 8 + 3]._map["instr"]);
							     
	return pair<unsigned int, string>(8,"while_stmt");

	case 55 ://logic_expr->logic_expr && M logic_expr 
				backpatch(st[stackSize - 4 + 1]._map["truelist"], st[stackSize - 4 + 3]._map["instr"]);
				reduceHead["truelist"] = st[stackSize - 4 + 4]._map["truelist"];
				reduceHead["falselist"] = merge(st[stackSize - 4 + 1]._map["falselist"], st[stackSize - 4 + 4]._map["falselist"]);
			
	return pair<unsigned int, string>(4,"logic_expr");

	case 56 ://logic_expr->logic_expr || M logic_expr 
				backpatch(st[stackSize - 4 + 1]._map["falselist"], st[stackSize - 4 + 3]._map["instr"]);
				reduceHead["truelist"] = merge(st[stackSize - 4 + 1]._map["truelist"], st[stackSize - 4 + 4]._map["truelist"]);
				reduceHead["falselist"] = st[stackSize - 4 + 4]._map["falselist"];
			
	return pair<unsigned int, string>(4,"logic_expr");

	case 57 ://logic_expr->! logic_expr 
				reduceHead["truelist"] = st[stackSize - 2 + 2]._map["falselist"];
				reduceHead["falselist"] = st[stackSize - 2 + 2]._map["truelist"];
			
	return pair<unsigned int, string>(2,"logic_expr");

	case 58 ://logic_expr->( logic_expr ) 
				reduceHead["truelist"] = st[stackSize - 3 + 2]._map["truelist"];
				reduceHead["falselist"] = st[stackSize - 3 + 2]._map["falselist"];
			
	return pair<unsigned int, string>(3,"logic_expr");

	case 59 ://logic_expr->expr rel expr 
				reduceHead["truelist"] = makelist(nextInstr);
				reduceHead["falselist"] = makelist(nextInstr+1);
				emit("j"+st[stackSize - 3 + 2]._map["op"], st[stackSize - 3 + 1]._map["place"], st[stackSize - 3 + 3]._map["place"], "_");
				emit("j","","","_");
			
	return pair<unsigned int, string>(3,"logic_expr");

	case 60 ://logic_expr->expr 
 				reduceHead["truelist"] = makelist(nextInstr);
				reduceHead["falselist"] = makelist(nextInstr+1);
				emit("j!=", st[stackSize - 1 + 1]._map["place"], "0", "_");
				emit("j","","","_");
			
	return pair<unsigned int, string>(1,"logic_expr");

	case 61 ://logic_expr->true 
				reduceHead["truelist"] = makelist(nextInstr);
				emit("j","","","_");
			
	return pair<unsigned int, string>(1,"logic_expr");

	case 62 ://logic_expr->false 
				reduceHead["falselist"] = makelist(nextInstr);
				emit("j","","","_");
			
	return pair<unsigned int, string>(1,"logic_expr");

	case 63 ://M->
reduceHead["instr"] = "LABEL_" + gen(nextInstr);

	return pair<unsigned int, string>(0,"M");

	case 64 ://N->
 reduceHead["instr"] = makelist(nextInstr);
      emit("j","","","_");

	return pair<unsigned int, string>(0,"N");

	case 65 ://BlockLeader->
      addLeader(nextInstr);
    
	return pair<unsigned int, string>(0,"BlockLeader");

	case 66 ://rel->< 
reduceHead["op"] = "<";

	return pair<unsigned int, string>(1,"rel");

	case 67 ://rel->> 
reduceHead["op"] = ">";

	return pair<unsigned int, string>(1,"rel");

	case 68 ://rel-><= 
reduceHead["op"] = "<=";

	return pair<unsigned int, string>(1,"rel");

	case 69 ://rel-><= 
reduceHead["op"] = ">=";

	return pair<unsigned int, string>(1,"rel");

	case 70 ://rel->== 
reduceHead["op"] = "==";

	return pair<unsigned int, string>(1,"rel");

	case 71 ://rel->!= 
reduceHead["op"] = "!=";

	return pair<unsigned int, string>(1,"rel");

	default: return pair<unsigned int, string>(0,"");
	}
}// end function
string getProduction(unsigned int index) {
	switch(index) {
		case 0 :return "S->program ";
		case 1 :return "program->stmts ";
		case 2 :return "stmts->stmts M stmt ";
		case 3 :return "stmts->stmt ";
		case 4 :return "stmt->includestmt ";
		case 5 :return "stmt->{ stmts } ";
		case 6 :return "stmt->fun_define ";
		case 7 :return "stmt->if_stmt ";
		case 8 :return "stmt->while_stmt ";
		case 9 :return "stmt->var_decl ; ";
		case 10 :return "stmt->static var_decl ; ";
		case 11 :return "stmt->expr_stmt ; ";
		case 12 :return "stmt->return expr ; ";
		case 13 :return "includestmt->include \" filename \" ";
		case 14 :return "includestmt->include < filename > ";
		case 15 :return "fun_define->fun_decl_head BlockLeader { stmts } ";
		case 16 :return "fun_decl_head->type_spec id ( ) ";
		case 17 :return "fun_decl_head->type_spec id ( param_list ) ";
		case 18 :return "param_list->param_list , param ";
		case 19 :return "param_list->param ";
		case 20 :return "param->type_spec id ";
		case 21 :return "param->type_spec id [ num ] ";
		case 22 :return "var_decl->type_spec id ";
		case 23 :return "var_decl->type_spec id = expr ";
		case 24 :return "var_decl->type_spec id [ num ] ";
		case 25 :return "type_spec->int ";
		case 26 :return "type_spec->double ";
		case 27 :return "type_spec->void ";
		case 28 :return "type_spec->char ";
		case 29 :return "type_spec->bool ";
		case 30 :return "type_spec->float ";
		case 31 :return "expr_stmt->id = expr ";
		case 32 :return "expr_stmt->id [ expr ] = expr ";
		case 33 :return "expr->expr + expr ";
		case 34 :return "expr->expr - expr ";
		case 35 :return "expr->expr * expr ";
		case 36 :return "expr->expr / expr ";
		case 37 :return "expr->expr % expr ";
		case 38 :return "expr->expr & expr ";
		case 39 :return "expr->expr | expr ";
		case 40 :return "expr->expr ^ expr ";
		case 41 :return "expr->expr >> expr ";
		case 42 :return "expr->expr << expr ";
		case 43 :return "expr->( expr ) ";
		case 44 :return "expr->id ";
		case 45 :return "expr->id ( arg_list ) ";
		case 46 :return "expr->num ";
		case 47 :return "expr->- expr ";
		case 48 :return "expr->id [ expr ] ";
		case 49 :return "arg_list->arg_list , expr ";
		case 50 :return "arg_list->expr ";
		case 51 :return "arg_list->";
		case 52 :return "if_stmt->if BlockLeader ( logic_expr ) M stmt ";
		case 53 :return "if_stmt->if BlockLeader ( logic_expr ) M stmt N else M stmt ";
		case 54 :return "while_stmt->while BlockLeader M ( logic_expr ) M stmt ";
		case 55 :return "logic_expr->logic_expr && M logic_expr ";
		case 56 :return "logic_expr->logic_expr || M logic_expr ";
		case 57 :return "logic_expr->! logic_expr ";
		case 58 :return "logic_expr->( logic_expr ) ";
		case 59 :return "logic_expr->expr rel expr ";
		case 60 :return "logic_expr->expr ";
		case 61 :return "logic_expr->true ";
		case 62 :return "logic_expr->false ";
		case 63 :return "M->";
		case 64 :return "N->";
		case 65 :return "BlockLeader->";
		case 66 :return "rel->< ";
		case 67 :return "rel->> ";
		case 68 :return "rel-><= ";
		case 69 :return "rel-><= ";
		case 70 :return "rel->== ";
		case 71 :return "rel->!= ";
		default: return "";
	}
}
#endif
