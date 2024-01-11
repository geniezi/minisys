#ifndef _TABLE_YACC_H
#define _TABLE_YACC_H
#include "StructDefine.h"
#include <vector>
#include <map>
using namespace std;
void initTable(map<unsigned int, map<string, TableItem> >& _parseTable) {
	map<string, TableItem> tran;
	// state 0
	tran.insert(make_pair("program", TableItem(3,1)));
	tran.insert(make_pair("stmts", TableItem(3,2)));
	tran.insert(make_pair("stmt", TableItem(3,3)));
	tran.insert(make_pair("includestmt", TableItem(3,4)));
	tran.insert(make_pair("{", TableItem(1,5)));
	tran.insert(make_pair("fun_define", TableItem(3,6)));
	tran.insert(make_pair("if_stmt", TableItem(3,7)));
	tran.insert(make_pair("while_stmt", TableItem(3,8)));
	tran.insert(make_pair("var_decl", TableItem(3,9)));
	tran.insert(make_pair(";", TableItem(1,10)));
	tran.insert(make_pair("static", TableItem(1,11)));
	tran.insert(make_pair("expr_stmt", TableItem(3,12)));
	tran.insert(make_pair("return", TableItem(1,13)));
	tran.insert(make_pair("call_stmt", TableItem(3,14)));
	tran.insert(make_pair("set_mem", TableItem(1,15)));
	tran.insert(make_pair("include", TableItem(1,16)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,17)));
	tran.insert(make_pair("type_spec", TableItem(3,18)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,26)));
	tran.insert(make_pair("while", TableItem(1,27)));
	_parseTable.insert(make_pair(0,tran));
	tran.clear();


	// state 1
	tran.insert(make_pair("$", TableItem(5,0)));
	_parseTable.insert(make_pair(1,tran));
	tran.clear();


	// state 2
	tran.insert(make_pair("M", TableItem(3,28)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	tran.insert(make_pair("$", TableItem(2,1)));
	_parseTable.insert(make_pair(2,tran));
	tran.clear();


	// state 3
	tran.insert(make_pair("{", TableItem(2,3)));
	tran.insert(make_pair(";", TableItem(2,3)));
	tran.insert(make_pair("static", TableItem(2,3)));
	tran.insert(make_pair("return", TableItem(2,3)));
	tran.insert(make_pair("set_mem", TableItem(2,3)));
	tran.insert(make_pair("include", TableItem(2,3)));
	tran.insert(make_pair("id", TableItem(2,3)));
	tran.insert(make_pair("int", TableItem(2,3)));
	tran.insert(make_pair("double", TableItem(2,3)));
	tran.insert(make_pair("void", TableItem(2,3)));
	tran.insert(make_pair("char", TableItem(2,3)));
	tran.insert(make_pair("bool", TableItem(2,3)));
	tran.insert(make_pair("float", TableItem(2,3)));
	tran.insert(make_pair("if", TableItem(2,3)));
	tran.insert(make_pair("while", TableItem(2,3)));
	tran.insert(make_pair("$", TableItem(2,3)));
	_parseTable.insert(make_pair(3,tran));
	tran.clear();


	// state 4
	tran.insert(make_pair("{", TableItem(2,4)));
	tran.insert(make_pair(";", TableItem(2,4)));
	tran.insert(make_pair("static", TableItem(2,4)));
	tran.insert(make_pair("return", TableItem(2,4)));
	tran.insert(make_pair("set_mem", TableItem(2,4)));
	tran.insert(make_pair("include", TableItem(2,4)));
	tran.insert(make_pair("id", TableItem(2,4)));
	tran.insert(make_pair("int", TableItem(2,4)));
	tran.insert(make_pair("double", TableItem(2,4)));
	tran.insert(make_pair("void", TableItem(2,4)));
	tran.insert(make_pair("char", TableItem(2,4)));
	tran.insert(make_pair("bool", TableItem(2,4)));
	tran.insert(make_pair("float", TableItem(2,4)));
	tran.insert(make_pair("if", TableItem(2,4)));
	tran.insert(make_pair("while", TableItem(2,4)));
	tran.insert(make_pair("$", TableItem(2,4)));
	_parseTable.insert(make_pair(4,tran));
	tran.clear();


	// state 5
	tran.insert(make_pair("stmts", TableItem(3,29)));
	tran.insert(make_pair("stmt", TableItem(3,30)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(5,tran));
	tran.clear();


	// state 6
	tran.insert(make_pair("{", TableItem(2,6)));
	tran.insert(make_pair(";", TableItem(2,6)));
	tran.insert(make_pair("static", TableItem(2,6)));
	tran.insert(make_pair("return", TableItem(2,6)));
	tran.insert(make_pair("set_mem", TableItem(2,6)));
	tran.insert(make_pair("include", TableItem(2,6)));
	tran.insert(make_pair("id", TableItem(2,6)));
	tran.insert(make_pair("int", TableItem(2,6)));
	tran.insert(make_pair("double", TableItem(2,6)));
	tran.insert(make_pair("void", TableItem(2,6)));
	tran.insert(make_pair("char", TableItem(2,6)));
	tran.insert(make_pair("bool", TableItem(2,6)));
	tran.insert(make_pair("float", TableItem(2,6)));
	tran.insert(make_pair("if", TableItem(2,6)));
	tran.insert(make_pair("while", TableItem(2,6)));
	tran.insert(make_pair("$", TableItem(2,6)));
	_parseTable.insert(make_pair(6,tran));
	tran.clear();


	// state 7
	tran.insert(make_pair("{", TableItem(2,7)));
	tran.insert(make_pair(";", TableItem(2,7)));
	tran.insert(make_pair("static", TableItem(2,7)));
	tran.insert(make_pair("return", TableItem(2,7)));
	tran.insert(make_pair("set_mem", TableItem(2,7)));
	tran.insert(make_pair("include", TableItem(2,7)));
	tran.insert(make_pair("id", TableItem(2,7)));
	tran.insert(make_pair("int", TableItem(2,7)));
	tran.insert(make_pair("double", TableItem(2,7)));
	tran.insert(make_pair("void", TableItem(2,7)));
	tran.insert(make_pair("char", TableItem(2,7)));
	tran.insert(make_pair("bool", TableItem(2,7)));
	tran.insert(make_pair("float", TableItem(2,7)));
	tran.insert(make_pair("if", TableItem(2,7)));
	tran.insert(make_pair("while", TableItem(2,7)));
	tran.insert(make_pair("$", TableItem(2,7)));
	_parseTable.insert(make_pair(7,tran));
	tran.clear();


	// state 8
	tran.insert(make_pair("{", TableItem(2,8)));
	tran.insert(make_pair(";", TableItem(2,8)));
	tran.insert(make_pair("static", TableItem(2,8)));
	tran.insert(make_pair("return", TableItem(2,8)));
	tran.insert(make_pair("set_mem", TableItem(2,8)));
	tran.insert(make_pair("include", TableItem(2,8)));
	tran.insert(make_pair("id", TableItem(2,8)));
	tran.insert(make_pair("int", TableItem(2,8)));
	tran.insert(make_pair("double", TableItem(2,8)));
	tran.insert(make_pair("void", TableItem(2,8)));
	tran.insert(make_pair("char", TableItem(2,8)));
	tran.insert(make_pair("bool", TableItem(2,8)));
	tran.insert(make_pair("float", TableItem(2,8)));
	tran.insert(make_pair("if", TableItem(2,8)));
	tran.insert(make_pair("while", TableItem(2,8)));
	tran.insert(make_pair("$", TableItem(2,8)));
	_parseTable.insert(make_pair(8,tran));
	tran.clear();


	// state 9
	tran.insert(make_pair(";", TableItem(1,48)));
	_parseTable.insert(make_pair(9,tran));
	tran.clear();


	// state 10
	tran.insert(make_pair("{", TableItem(2,16)));
	tran.insert(make_pair(";", TableItem(2,16)));
	tran.insert(make_pair("static", TableItem(2,16)));
	tran.insert(make_pair("return", TableItem(2,16)));
	tran.insert(make_pair("set_mem", TableItem(2,16)));
	tran.insert(make_pair("include", TableItem(2,16)));
	tran.insert(make_pair("id", TableItem(2,16)));
	tran.insert(make_pair("int", TableItem(2,16)));
	tran.insert(make_pair("double", TableItem(2,16)));
	tran.insert(make_pair("void", TableItem(2,16)));
	tran.insert(make_pair("char", TableItem(2,16)));
	tran.insert(make_pair("bool", TableItem(2,16)));
	tran.insert(make_pair("float", TableItem(2,16)));
	tran.insert(make_pair("if", TableItem(2,16)));
	tran.insert(make_pair("while", TableItem(2,16)));
	tran.insert(make_pair("$", TableItem(2,16)));
	_parseTable.insert(make_pair(10,tran));
	tran.clear();


	// state 11
	tran.insert(make_pair("var_decl", TableItem(3,49)));
	tran.insert(make_pair("type_spec", TableItem(3,50)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	_parseTable.insert(make_pair(11,tran));
	tran.clear();


	// state 12
	tran.insert(make_pair(";", TableItem(1,51)));
	_parseTable.insert(make_pair(12,tran));
	tran.clear();


	// state 13
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair(";", TableItem(1,53)));
	tran.insert(make_pair("expr", TableItem(3,54)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(13,tran));
	tran.clear();


	// state 14
	tran.insert(make_pair(";", TableItem(1,59)));
	_parseTable.insert(make_pair(14,tran));
	tran.clear();


	// state 15
	tran.insert(make_pair("(", TableItem(1,60)));
	_parseTable.insert(make_pair(15,tran));
	tran.clear();


	// state 16
	tran.insert(make_pair("<", TableItem(1,61)));
	tran.insert(make_pair("\"", TableItem(1,62)));
	_parseTable.insert(make_pair(16,tran));
	tran.clear();


	// state 17
	tran.insert(make_pair("{", TableItem(2,71)));
	tran.insert(make_pair("BlockLeader", TableItem(3,63)));
	_parseTable.insert(make_pair(17,tran));
	tran.clear();


	// state 18
	tran.insert(make_pair("id", TableItem(1,64)));
	_parseTable.insert(make_pair(18,tran));
	tran.clear();


	// state 19
	tran.insert(make_pair("=", TableItem(1,65)));
	tran.insert(make_pair("(", TableItem(1,66)));
	tran.insert(make_pair("[", TableItem(1,67)));
	_parseTable.insert(make_pair(19,tran));
	tran.clear();


	// state 20
	tran.insert(make_pair("id", TableItem(2,29)));
	_parseTable.insert(make_pair(20,tran));
	tran.clear();


	// state 21
	tran.insert(make_pair("id", TableItem(2,30)));
	_parseTable.insert(make_pair(21,tran));
	tran.clear();


	// state 22
	tran.insert(make_pair("id", TableItem(2,31)));
	_parseTable.insert(make_pair(22,tran));
	tran.clear();


	// state 23
	tran.insert(make_pair("id", TableItem(2,32)));
	_parseTable.insert(make_pair(23,tran));
	tran.clear();


	// state 24
	tran.insert(make_pair("id", TableItem(2,33)));
	_parseTable.insert(make_pair(24,tran));
	tran.clear();


	// state 25
	tran.insert(make_pair("id", TableItem(2,34)));
	_parseTable.insert(make_pair(25,tran));
	tran.clear();


	// state 26
	tran.insert(make_pair("(", TableItem(1,68)));
	_parseTable.insert(make_pair(26,tran));
	tran.clear();


	// state 27
	tran.insert(make_pair("M", TableItem(3,69)));
	tran.insert(make_pair("(", TableItem(2,69)));
	_parseTable.insert(make_pair(27,tran));
	tran.clear();


	// state 28
	tran.insert(make_pair("stmt", TableItem(3,70)));
	tran.insert(make_pair("includestmt", TableItem(3,4)));
	tran.insert(make_pair("{", TableItem(1,5)));
	tran.insert(make_pair("fun_define", TableItem(3,6)));
	tran.insert(make_pair("if_stmt", TableItem(3,7)));
	tran.insert(make_pair("while_stmt", TableItem(3,8)));
	tran.insert(make_pair("var_decl", TableItem(3,9)));
	tran.insert(make_pair(";", TableItem(1,10)));
	tran.insert(make_pair("static", TableItem(1,11)));
	tran.insert(make_pair("expr_stmt", TableItem(3,12)));
	tran.insert(make_pair("return", TableItem(1,13)));
	tran.insert(make_pair("call_stmt", TableItem(3,14)));
	tran.insert(make_pair("set_mem", TableItem(1,15)));
	tran.insert(make_pair("include", TableItem(1,16)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,17)));
	tran.insert(make_pair("type_spec", TableItem(3,18)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,26)));
	tran.insert(make_pair("while", TableItem(1,27)));
	_parseTable.insert(make_pair(28,tran));
	tran.clear();


	// state 29
	tran.insert(make_pair("M", TableItem(3,71)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair("}", TableItem(1,72)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(29,tran));
	tran.clear();


	// state 30
	tran.insert(make_pair("{", TableItem(2,3)));
	tran.insert(make_pair("}", TableItem(2,3)));
	tran.insert(make_pair(";", TableItem(2,3)));
	tran.insert(make_pair("static", TableItem(2,3)));
	tran.insert(make_pair("return", TableItem(2,3)));
	tran.insert(make_pair("set_mem", TableItem(2,3)));
	tran.insert(make_pair("include", TableItem(2,3)));
	tran.insert(make_pair("id", TableItem(2,3)));
	tran.insert(make_pair("int", TableItem(2,3)));
	tran.insert(make_pair("double", TableItem(2,3)));
	tran.insert(make_pair("void", TableItem(2,3)));
	tran.insert(make_pair("char", TableItem(2,3)));
	tran.insert(make_pair("bool", TableItem(2,3)));
	tran.insert(make_pair("float", TableItem(2,3)));
	tran.insert(make_pair("if", TableItem(2,3)));
	tran.insert(make_pair("while", TableItem(2,3)));
	_parseTable.insert(make_pair(30,tran));
	tran.clear();


	// state 31
	tran.insert(make_pair("{", TableItem(2,4)));
	tran.insert(make_pair("}", TableItem(2,4)));
	tran.insert(make_pair(";", TableItem(2,4)));
	tran.insert(make_pair("static", TableItem(2,4)));
	tran.insert(make_pair("return", TableItem(2,4)));
	tran.insert(make_pair("set_mem", TableItem(2,4)));
	tran.insert(make_pair("include", TableItem(2,4)));
	tran.insert(make_pair("id", TableItem(2,4)));
	tran.insert(make_pair("int", TableItem(2,4)));
	tran.insert(make_pair("double", TableItem(2,4)));
	tran.insert(make_pair("void", TableItem(2,4)));
	tran.insert(make_pair("char", TableItem(2,4)));
	tran.insert(make_pair("bool", TableItem(2,4)));
	tran.insert(make_pair("float", TableItem(2,4)));
	tran.insert(make_pair("if", TableItem(2,4)));
	tran.insert(make_pair("while", TableItem(2,4)));
	_parseTable.insert(make_pair(31,tran));
	tran.clear();


	// state 32
	tran.insert(make_pair("stmts", TableItem(3,73)));
	tran.insert(make_pair("stmt", TableItem(3,30)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(32,tran));
	tran.clear();


	// state 33
	tran.insert(make_pair("{", TableItem(2,6)));
	tran.insert(make_pair("}", TableItem(2,6)));
	tran.insert(make_pair(";", TableItem(2,6)));
	tran.insert(make_pair("static", TableItem(2,6)));
	tran.insert(make_pair("return", TableItem(2,6)));
	tran.insert(make_pair("set_mem", TableItem(2,6)));
	tran.insert(make_pair("include", TableItem(2,6)));
	tran.insert(make_pair("id", TableItem(2,6)));
	tran.insert(make_pair("int", TableItem(2,6)));
	tran.insert(make_pair("double", TableItem(2,6)));
	tran.insert(make_pair("void", TableItem(2,6)));
	tran.insert(make_pair("char", TableItem(2,6)));
	tran.insert(make_pair("bool", TableItem(2,6)));
	tran.insert(make_pair("float", TableItem(2,6)));
	tran.insert(make_pair("if", TableItem(2,6)));
	tran.insert(make_pair("while", TableItem(2,6)));
	_parseTable.insert(make_pair(33,tran));
	tran.clear();


	// state 34
	tran.insert(make_pair("{", TableItem(2,7)));
	tran.insert(make_pair("}", TableItem(2,7)));
	tran.insert(make_pair(";", TableItem(2,7)));
	tran.insert(make_pair("static", TableItem(2,7)));
	tran.insert(make_pair("return", TableItem(2,7)));
	tran.insert(make_pair("set_mem", TableItem(2,7)));
	tran.insert(make_pair("include", TableItem(2,7)));
	tran.insert(make_pair("id", TableItem(2,7)));
	tran.insert(make_pair("int", TableItem(2,7)));
	tran.insert(make_pair("double", TableItem(2,7)));
	tran.insert(make_pair("void", TableItem(2,7)));
	tran.insert(make_pair("char", TableItem(2,7)));
	tran.insert(make_pair("bool", TableItem(2,7)));
	tran.insert(make_pair("float", TableItem(2,7)));
	tran.insert(make_pair("if", TableItem(2,7)));
	tran.insert(make_pair("while", TableItem(2,7)));
	_parseTable.insert(make_pair(34,tran));
	tran.clear();


	// state 35
	tran.insert(make_pair("{", TableItem(2,8)));
	tran.insert(make_pair("}", TableItem(2,8)));
	tran.insert(make_pair(";", TableItem(2,8)));
	tran.insert(make_pair("static", TableItem(2,8)));
	tran.insert(make_pair("return", TableItem(2,8)));
	tran.insert(make_pair("set_mem", TableItem(2,8)));
	tran.insert(make_pair("include", TableItem(2,8)));
	tran.insert(make_pair("id", TableItem(2,8)));
	tran.insert(make_pair("int", TableItem(2,8)));
	tran.insert(make_pair("double", TableItem(2,8)));
	tran.insert(make_pair("void", TableItem(2,8)));
	tran.insert(make_pair("char", TableItem(2,8)));
	tran.insert(make_pair("bool", TableItem(2,8)));
	tran.insert(make_pair("float", TableItem(2,8)));
	tran.insert(make_pair("if", TableItem(2,8)));
	tran.insert(make_pair("while", TableItem(2,8)));
	_parseTable.insert(make_pair(35,tran));
	tran.clear();


	// state 36
	tran.insert(make_pair(";", TableItem(1,74)));
	_parseTable.insert(make_pair(36,tran));
	tran.clear();


	// state 37
	tran.insert(make_pair("{", TableItem(2,16)));
	tran.insert(make_pair("}", TableItem(2,16)));
	tran.insert(make_pair(";", TableItem(2,16)));
	tran.insert(make_pair("static", TableItem(2,16)));
	tran.insert(make_pair("return", TableItem(2,16)));
	tran.insert(make_pair("set_mem", TableItem(2,16)));
	tran.insert(make_pair("include", TableItem(2,16)));
	tran.insert(make_pair("id", TableItem(2,16)));
	tran.insert(make_pair("int", TableItem(2,16)));
	tran.insert(make_pair("double", TableItem(2,16)));
	tran.insert(make_pair("void", TableItem(2,16)));
	tran.insert(make_pair("char", TableItem(2,16)));
	tran.insert(make_pair("bool", TableItem(2,16)));
	tran.insert(make_pair("float", TableItem(2,16)));
	tran.insert(make_pair("if", TableItem(2,16)));
	tran.insert(make_pair("while", TableItem(2,16)));
	_parseTable.insert(make_pair(37,tran));
	tran.clear();


	// state 38
	tran.insert(make_pair("var_decl", TableItem(3,75)));
	tran.insert(make_pair("type_spec", TableItem(3,50)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	_parseTable.insert(make_pair(38,tran));
	tran.clear();


	// state 39
	tran.insert(make_pair(";", TableItem(1,76)));
	_parseTable.insert(make_pair(39,tran));
	tran.clear();


	// state 40
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair(";", TableItem(1,77)));
	tran.insert(make_pair("expr", TableItem(3,78)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(40,tran));
	tran.clear();


	// state 41
	tran.insert(make_pair(";", TableItem(1,79)));
	_parseTable.insert(make_pair(41,tran));
	tran.clear();


	// state 42
	tran.insert(make_pair("(", TableItem(1,80)));
	_parseTable.insert(make_pair(42,tran));
	tran.clear();


	// state 43
	tran.insert(make_pair("<", TableItem(1,81)));
	tran.insert(make_pair("\"", TableItem(1,82)));
	_parseTable.insert(make_pair(43,tran));
	tran.clear();


	// state 44
	tran.insert(make_pair("{", TableItem(2,71)));
	tran.insert(make_pair("BlockLeader", TableItem(3,83)));
	_parseTable.insert(make_pair(44,tran));
	tran.clear();


	// state 45
	tran.insert(make_pair("id", TableItem(1,84)));
	_parseTable.insert(make_pair(45,tran));
	tran.clear();


	// state 46
	tran.insert(make_pair("(", TableItem(1,85)));
	_parseTable.insert(make_pair(46,tran));
	tran.clear();


	// state 47
	tran.insert(make_pair("M", TableItem(3,86)));
	tran.insert(make_pair("(", TableItem(2,69)));
	_parseTable.insert(make_pair(47,tran));
	tran.clear();


	// state 48
	tran.insert(make_pair("{", TableItem(2,9)));
	tran.insert(make_pair(";", TableItem(2,9)));
	tran.insert(make_pair("static", TableItem(2,9)));
	tran.insert(make_pair("return", TableItem(2,9)));
	tran.insert(make_pair("set_mem", TableItem(2,9)));
	tran.insert(make_pair("include", TableItem(2,9)));
	tran.insert(make_pair("id", TableItem(2,9)));
	tran.insert(make_pair("int", TableItem(2,9)));
	tran.insert(make_pair("double", TableItem(2,9)));
	tran.insert(make_pair("void", TableItem(2,9)));
	tran.insert(make_pair("char", TableItem(2,9)));
	tran.insert(make_pair("bool", TableItem(2,9)));
	tran.insert(make_pair("float", TableItem(2,9)));
	tran.insert(make_pair("if", TableItem(2,9)));
	tran.insert(make_pair("while", TableItem(2,9)));
	tran.insert(make_pair("$", TableItem(2,9)));
	_parseTable.insert(make_pair(48,tran));
	tran.clear();


	// state 49
	tran.insert(make_pair(";", TableItem(1,87)));
	_parseTable.insert(make_pair(49,tran));
	tran.clear();


	// state 50
	tran.insert(make_pair("id", TableItem(1,88)));
	_parseTable.insert(make_pair(50,tran));
	tran.clear();


	// state 51
	tran.insert(make_pair("{", TableItem(2,11)));
	tran.insert(make_pair(";", TableItem(2,11)));
	tran.insert(make_pair("static", TableItem(2,11)));
	tran.insert(make_pair("return", TableItem(2,11)));
	tran.insert(make_pair("set_mem", TableItem(2,11)));
	tran.insert(make_pair("include", TableItem(2,11)));
	tran.insert(make_pair("id", TableItem(2,11)));
	tran.insert(make_pair("int", TableItem(2,11)));
	tran.insert(make_pair("double", TableItem(2,11)));
	tran.insert(make_pair("void", TableItem(2,11)));
	tran.insert(make_pair("char", TableItem(2,11)));
	tran.insert(make_pair("bool", TableItem(2,11)));
	tran.insert(make_pair("float", TableItem(2,11)));
	tran.insert(make_pair("if", TableItem(2,11)));
	tran.insert(make_pair("while", TableItem(2,11)));
	tran.insert(make_pair("$", TableItem(2,11)));
	_parseTable.insert(make_pair(51,tran));
	tran.clear();


	// state 52
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,89)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(52,tran));
	tran.clear();


	// state 53
	tran.insert(make_pair("{", TableItem(2,13)));
	tran.insert(make_pair(";", TableItem(2,13)));
	tran.insert(make_pair("static", TableItem(2,13)));
	tran.insert(make_pair("return", TableItem(2,13)));
	tran.insert(make_pair("set_mem", TableItem(2,13)));
	tran.insert(make_pair("include", TableItem(2,13)));
	tran.insert(make_pair("id", TableItem(2,13)));
	tran.insert(make_pair("int", TableItem(2,13)));
	tran.insert(make_pair("double", TableItem(2,13)));
	tran.insert(make_pair("void", TableItem(2,13)));
	tran.insert(make_pair("char", TableItem(2,13)));
	tran.insert(make_pair("bool", TableItem(2,13)));
	tran.insert(make_pair("float", TableItem(2,13)));
	tran.insert(make_pair("if", TableItem(2,13)));
	tran.insert(make_pair("while", TableItem(2,13)));
	tran.insert(make_pair("$", TableItem(2,13)));
	_parseTable.insert(make_pair(53,tran));
	tran.clear();


	// state 54
	tran.insert(make_pair("|", TableItem(1,90)));
	tran.insert(make_pair("^", TableItem(1,91)));
	tran.insert(make_pair("&", TableItem(1,92)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(1,100)));
	_parseTable.insert(make_pair(54,tran));
	tran.clear();


	// state 55
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,102)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(55,tran));
	tran.clear();


	// state 56
	tran.insert(make_pair("|", TableItem(2,48)));
	tran.insert(make_pair("^", TableItem(2,48)));
	tran.insert(make_pair("&", TableItem(2,48)));
	tran.insert(make_pair("<<", TableItem(2,48)));
	tran.insert(make_pair(">>", TableItem(2,48)));
	tran.insert(make_pair("+", TableItem(2,48)));
	tran.insert(make_pair("-", TableItem(2,48)));
	tran.insert(make_pair("*", TableItem(2,48)));
	tran.insert(make_pair("/", TableItem(2,48)));
	tran.insert(make_pair("%", TableItem(2,48)));
	tran.insert(make_pair(";", TableItem(2,48)));
	tran.insert(make_pair("(", TableItem(1,107)));
	tran.insert(make_pair("[", TableItem(1,108)));
	_parseTable.insert(make_pair(56,tran));
	tran.clear();


	// state 57
	tran.insert(make_pair("|", TableItem(2,50)));
	tran.insert(make_pair("^", TableItem(2,50)));
	tran.insert(make_pair("&", TableItem(2,50)));
	tran.insert(make_pair("<<", TableItem(2,50)));
	tran.insert(make_pair(">>", TableItem(2,50)));
	tran.insert(make_pair("+", TableItem(2,50)));
	tran.insert(make_pair("-", TableItem(2,50)));
	tran.insert(make_pair("*", TableItem(2,50)));
	tran.insert(make_pair("/", TableItem(2,50)));
	tran.insert(make_pair("%", TableItem(2,50)));
	tran.insert(make_pair(";", TableItem(2,50)));
	_parseTable.insert(make_pair(57,tran));
	tran.clear();


	// state 58
	tran.insert(make_pair("(", TableItem(1,109)));
	_parseTable.insert(make_pair(58,tran));
	tran.clear();


	// state 59
	tran.insert(make_pair("{", TableItem(2,14)));
	tran.insert(make_pair(";", TableItem(2,14)));
	tran.insert(make_pair("static", TableItem(2,14)));
	tran.insert(make_pair("return", TableItem(2,14)));
	tran.insert(make_pair("set_mem", TableItem(2,14)));
	tran.insert(make_pair("include", TableItem(2,14)));
	tran.insert(make_pair("id", TableItem(2,14)));
	tran.insert(make_pair("int", TableItem(2,14)));
	tran.insert(make_pair("double", TableItem(2,14)));
	tran.insert(make_pair("void", TableItem(2,14)));
	tran.insert(make_pair("char", TableItem(2,14)));
	tran.insert(make_pair("bool", TableItem(2,14)));
	tran.insert(make_pair("float", TableItem(2,14)));
	tran.insert(make_pair("if", TableItem(2,14)));
	tran.insert(make_pair("while", TableItem(2,14)));
	tran.insert(make_pair("$", TableItem(2,14)));
	_parseTable.insert(make_pair(59,tran));
	tran.clear();


	// state 60
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,111)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(60,tran));
	tran.clear();


	// state 61
	tran.insert(make_pair("filename", TableItem(1,116)));
	_parseTable.insert(make_pair(61,tran));
	tran.clear();


	// state 62
	tran.insert(make_pair("filename", TableItem(1,117)));
	_parseTable.insert(make_pair(62,tran));
	tran.clear();


	// state 63
	tran.insert(make_pair("{", TableItem(1,118)));
	_parseTable.insert(make_pair(63,tran));
	tran.clear();


	// state 64
	tran.insert(make_pair("=", TableItem(1,119)));
	tran.insert(make_pair(";", TableItem(2,26)));
	tran.insert(make_pair("(", TableItem(1,120)));
	tran.insert(make_pair("[", TableItem(1,121)));
	_parseTable.insert(make_pair(64,tran));
	tran.clear();


	// state 65
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,122)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(65,tran));
	tran.clear();


	// state 66
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,124)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair(",", TableItem(2,56)));
	tran.insert(make_pair(")", TableItem(2,56)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("arg_list", TableItem(3,128)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(66,tran));
	tran.clear();


	// state 67
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,131)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(67,tran));
	tran.clear();


	// state 68
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,143)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(68,tran));
	tran.clear();


	// state 69
	tran.insert(make_pair("(", TableItem(1,146)));
	_parseTable.insert(make_pair(69,tran));
	tran.clear();


	// state 70
	tran.insert(make_pair("{", TableItem(2,2)));
	tran.insert(make_pair(";", TableItem(2,2)));
	tran.insert(make_pair("static", TableItem(2,2)));
	tran.insert(make_pair("return", TableItem(2,2)));
	tran.insert(make_pair("set_mem", TableItem(2,2)));
	tran.insert(make_pair("include", TableItem(2,2)));
	tran.insert(make_pair("id", TableItem(2,2)));
	tran.insert(make_pair("int", TableItem(2,2)));
	tran.insert(make_pair("double", TableItem(2,2)));
	tran.insert(make_pair("void", TableItem(2,2)));
	tran.insert(make_pair("char", TableItem(2,2)));
	tran.insert(make_pair("bool", TableItem(2,2)));
	tran.insert(make_pair("float", TableItem(2,2)));
	tran.insert(make_pair("if", TableItem(2,2)));
	tran.insert(make_pair("while", TableItem(2,2)));
	tran.insert(make_pair("$", TableItem(2,2)));
	_parseTable.insert(make_pair(70,tran));
	tran.clear();


	// state 71
	tran.insert(make_pair("stmt", TableItem(3,147)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(71,tran));
	tran.clear();


	// state 72
	tran.insert(make_pair("{", TableItem(2,5)));
	tran.insert(make_pair(";", TableItem(2,5)));
	tran.insert(make_pair("static", TableItem(2,5)));
	tran.insert(make_pair("return", TableItem(2,5)));
	tran.insert(make_pair("set_mem", TableItem(2,5)));
	tran.insert(make_pair("include", TableItem(2,5)));
	tran.insert(make_pair("id", TableItem(2,5)));
	tran.insert(make_pair("int", TableItem(2,5)));
	tran.insert(make_pair("double", TableItem(2,5)));
	tran.insert(make_pair("void", TableItem(2,5)));
	tran.insert(make_pair("char", TableItem(2,5)));
	tran.insert(make_pair("bool", TableItem(2,5)));
	tran.insert(make_pair("float", TableItem(2,5)));
	tran.insert(make_pair("if", TableItem(2,5)));
	tran.insert(make_pair("while", TableItem(2,5)));
	tran.insert(make_pair("$", TableItem(2,5)));
	_parseTable.insert(make_pair(72,tran));
	tran.clear();


	// state 73
	tran.insert(make_pair("M", TableItem(3,71)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair("}", TableItem(1,148)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(73,tran));
	tran.clear();


	// state 74
	tran.insert(make_pair("{", TableItem(2,9)));
	tran.insert(make_pair("}", TableItem(2,9)));
	tran.insert(make_pair(";", TableItem(2,9)));
	tran.insert(make_pair("static", TableItem(2,9)));
	tran.insert(make_pair("return", TableItem(2,9)));
	tran.insert(make_pair("set_mem", TableItem(2,9)));
	tran.insert(make_pair("include", TableItem(2,9)));
	tran.insert(make_pair("id", TableItem(2,9)));
	tran.insert(make_pair("int", TableItem(2,9)));
	tran.insert(make_pair("double", TableItem(2,9)));
	tran.insert(make_pair("void", TableItem(2,9)));
	tran.insert(make_pair("char", TableItem(2,9)));
	tran.insert(make_pair("bool", TableItem(2,9)));
	tran.insert(make_pair("float", TableItem(2,9)));
	tran.insert(make_pair("if", TableItem(2,9)));
	tran.insert(make_pair("while", TableItem(2,9)));
	_parseTable.insert(make_pair(74,tran));
	tran.clear();


	// state 75
	tran.insert(make_pair(";", TableItem(1,149)));
	_parseTable.insert(make_pair(75,tran));
	tran.clear();


	// state 76
	tran.insert(make_pair("{", TableItem(2,11)));
	tran.insert(make_pair("}", TableItem(2,11)));
	tran.insert(make_pair(";", TableItem(2,11)));
	tran.insert(make_pair("static", TableItem(2,11)));
	tran.insert(make_pair("return", TableItem(2,11)));
	tran.insert(make_pair("set_mem", TableItem(2,11)));
	tran.insert(make_pair("include", TableItem(2,11)));
	tran.insert(make_pair("id", TableItem(2,11)));
	tran.insert(make_pair("int", TableItem(2,11)));
	tran.insert(make_pair("double", TableItem(2,11)));
	tran.insert(make_pair("void", TableItem(2,11)));
	tran.insert(make_pair("char", TableItem(2,11)));
	tran.insert(make_pair("bool", TableItem(2,11)));
	tran.insert(make_pair("float", TableItem(2,11)));
	tran.insert(make_pair("if", TableItem(2,11)));
	tran.insert(make_pair("while", TableItem(2,11)));
	_parseTable.insert(make_pair(76,tran));
	tran.clear();


	// state 77
	tran.insert(make_pair("{", TableItem(2,13)));
	tran.insert(make_pair("}", TableItem(2,13)));
	tran.insert(make_pair(";", TableItem(2,13)));
	tran.insert(make_pair("static", TableItem(2,13)));
	tran.insert(make_pair("return", TableItem(2,13)));
	tran.insert(make_pair("set_mem", TableItem(2,13)));
	tran.insert(make_pair("include", TableItem(2,13)));
	tran.insert(make_pair("id", TableItem(2,13)));
	tran.insert(make_pair("int", TableItem(2,13)));
	tran.insert(make_pair("double", TableItem(2,13)));
	tran.insert(make_pair("void", TableItem(2,13)));
	tran.insert(make_pair("char", TableItem(2,13)));
	tran.insert(make_pair("bool", TableItem(2,13)));
	tran.insert(make_pair("float", TableItem(2,13)));
	tran.insert(make_pair("if", TableItem(2,13)));
	tran.insert(make_pair("while", TableItem(2,13)));
	_parseTable.insert(make_pair(77,tran));
	tran.clear();


	// state 78
	tran.insert(make_pair("|", TableItem(1,90)));
	tran.insert(make_pair("^", TableItem(1,91)));
	tran.insert(make_pair("&", TableItem(1,92)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(1,150)));
	_parseTable.insert(make_pair(78,tran));
	tran.clear();


	// state 79
	tran.insert(make_pair("{", TableItem(2,14)));
	tran.insert(make_pair("}", TableItem(2,14)));
	tran.insert(make_pair(";", TableItem(2,14)));
	tran.insert(make_pair("static", TableItem(2,14)));
	tran.insert(make_pair("return", TableItem(2,14)));
	tran.insert(make_pair("set_mem", TableItem(2,14)));
	tran.insert(make_pair("include", TableItem(2,14)));
	tran.insert(make_pair("id", TableItem(2,14)));
	tran.insert(make_pair("int", TableItem(2,14)));
	tran.insert(make_pair("double", TableItem(2,14)));
	tran.insert(make_pair("void", TableItem(2,14)));
	tran.insert(make_pair("char", TableItem(2,14)));
	tran.insert(make_pair("bool", TableItem(2,14)));
	tran.insert(make_pair("float", TableItem(2,14)));
	tran.insert(make_pair("if", TableItem(2,14)));
	tran.insert(make_pair("while", TableItem(2,14)));
	_parseTable.insert(make_pair(79,tran));
	tran.clear();


	// state 80
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,151)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(80,tran));
	tran.clear();


	// state 81
	tran.insert(make_pair("filename", TableItem(1,152)));
	_parseTable.insert(make_pair(81,tran));
	tran.clear();


	// state 82
	tran.insert(make_pair("filename", TableItem(1,153)));
	_parseTable.insert(make_pair(82,tran));
	tran.clear();


	// state 83
	tran.insert(make_pair("{", TableItem(1,154)));
	_parseTable.insert(make_pair(83,tran));
	tran.clear();


	// state 84
	tran.insert(make_pair("=", TableItem(1,119)));
	tran.insert(make_pair(";", TableItem(2,26)));
	tran.insert(make_pair("(", TableItem(1,155)));
	tran.insert(make_pair("[", TableItem(1,121)));
	_parseTable.insert(make_pair(84,tran));
	tran.clear();


	// state 85
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,156)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(85,tran));
	tran.clear();


	// state 86
	tran.insert(make_pair("(", TableItem(1,157)));
	_parseTable.insert(make_pair(86,tran));
	tran.clear();


	// state 87
	tran.insert(make_pair("{", TableItem(2,10)));
	tran.insert(make_pair(";", TableItem(2,10)));
	tran.insert(make_pair("static", TableItem(2,10)));
	tran.insert(make_pair("return", TableItem(2,10)));
	tran.insert(make_pair("set_mem", TableItem(2,10)));
	tran.insert(make_pair("include", TableItem(2,10)));
	tran.insert(make_pair("id", TableItem(2,10)));
	tran.insert(make_pair("int", TableItem(2,10)));
	tran.insert(make_pair("double", TableItem(2,10)));
	tran.insert(make_pair("void", TableItem(2,10)));
	tran.insert(make_pair("char", TableItem(2,10)));
	tran.insert(make_pair("bool", TableItem(2,10)));
	tran.insert(make_pair("float", TableItem(2,10)));
	tran.insert(make_pair("if", TableItem(2,10)));
	tran.insert(make_pair("while", TableItem(2,10)));
	tran.insert(make_pair("$", TableItem(2,10)));
	_parseTable.insert(make_pair(87,tran));
	tran.clear();


	// state 88
	tran.insert(make_pair("=", TableItem(1,119)));
	tran.insert(make_pair(";", TableItem(2,26)));
	tran.insert(make_pair("[", TableItem(1,121)));
	_parseTable.insert(make_pair(88,tran));
	tran.clear();


	// state 89
	tran.insert(make_pair("|", TableItem(2,51)));
	tran.insert(make_pair("^", TableItem(2,51)));
	tran.insert(make_pair("&", TableItem(2,51)));
	tran.insert(make_pair("<<", TableItem(2,51)));
	tran.insert(make_pair(">>", TableItem(2,51)));
	tran.insert(make_pair("+", TableItem(2,51)));
	tran.insert(make_pair("-", TableItem(2,51)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,51)));
	_parseTable.insert(make_pair(89,tran));
	tran.clear();


	// state 90
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,158)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(90,tran));
	tran.clear();


	// state 91
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,159)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(91,tran));
	tran.clear();


	// state 92
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,160)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(92,tran));
	tran.clear();


	// state 93
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,161)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(93,tran));
	tran.clear();


	// state 94
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,162)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(94,tran));
	tran.clear();


	// state 95
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,163)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(95,tran));
	tran.clear();


	// state 96
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,164)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(96,tran));
	tran.clear();


	// state 97
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,165)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(97,tran));
	tran.clear();


	// state 98
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,166)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(98,tran));
	tran.clear();


	// state 99
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,167)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(99,tran));
	tran.clear();


	// state 100
	tran.insert(make_pair("{", TableItem(2,12)));
	tran.insert(make_pair(";", TableItem(2,12)));
	tran.insert(make_pair("static", TableItem(2,12)));
	tran.insert(make_pair("return", TableItem(2,12)));
	tran.insert(make_pair("set_mem", TableItem(2,12)));
	tran.insert(make_pair("include", TableItem(2,12)));
	tran.insert(make_pair("id", TableItem(2,12)));
	tran.insert(make_pair("int", TableItem(2,12)));
	tran.insert(make_pair("double", TableItem(2,12)));
	tran.insert(make_pair("void", TableItem(2,12)));
	tran.insert(make_pair("char", TableItem(2,12)));
	tran.insert(make_pair("bool", TableItem(2,12)));
	tran.insert(make_pair("float", TableItem(2,12)));
	tran.insert(make_pair("if", TableItem(2,12)));
	tran.insert(make_pair("while", TableItem(2,12)));
	tran.insert(make_pair("$", TableItem(2,12)));
	_parseTable.insert(make_pair(100,tran));
	tran.clear();


	// state 101
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,168)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(101,tran));
	tran.clear();


	// state 102
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,179)));
	_parseTable.insert(make_pair(102,tran));
	tran.clear();


	// state 103
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,180)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(103,tran));
	tran.clear();


	// state 104
	tran.insert(make_pair("|", TableItem(2,48)));
	tran.insert(make_pair("^", TableItem(2,48)));
	tran.insert(make_pair("&", TableItem(2,48)));
	tran.insert(make_pair("<<", TableItem(2,48)));
	tran.insert(make_pair(">>", TableItem(2,48)));
	tran.insert(make_pair("+", TableItem(2,48)));
	tran.insert(make_pair("-", TableItem(2,48)));
	tran.insert(make_pair("*", TableItem(2,48)));
	tran.insert(make_pair("/", TableItem(2,48)));
	tran.insert(make_pair("%", TableItem(2,48)));
	tran.insert(make_pair("(", TableItem(1,181)));
	tran.insert(make_pair(")", TableItem(2,48)));
	tran.insert(make_pair("[", TableItem(1,182)));
	_parseTable.insert(make_pair(104,tran));
	tran.clear();


	// state 105
	tran.insert(make_pair("|", TableItem(2,50)));
	tran.insert(make_pair("^", TableItem(2,50)));
	tran.insert(make_pair("&", TableItem(2,50)));
	tran.insert(make_pair("<<", TableItem(2,50)));
	tran.insert(make_pair(">>", TableItem(2,50)));
	tran.insert(make_pair("+", TableItem(2,50)));
	tran.insert(make_pair("-", TableItem(2,50)));
	tran.insert(make_pair("*", TableItem(2,50)));
	tran.insert(make_pair("/", TableItem(2,50)));
	tran.insert(make_pair("%", TableItem(2,50)));
	tran.insert(make_pair(")", TableItem(2,50)));
	_parseTable.insert(make_pair(105,tran));
	tran.clear();


	// state 106
	tran.insert(make_pair("(", TableItem(1,183)));
	_parseTable.insert(make_pair(106,tran));
	tran.clear();


	// state 107
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,124)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair(",", TableItem(2,56)));
	tran.insert(make_pair(")", TableItem(2,56)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("arg_list", TableItem(3,184)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(107,tran));
	tran.clear();


	// state 108
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,185)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(108,tran));
	tran.clear();


	// state 109
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,186)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(109,tran));
	tran.clear();


	// state 110
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,187)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(110,tran));
	tran.clear();


	// state 111
	tran.insert(make_pair("|", TableItem(1,188)));
	tran.insert(make_pair("^", TableItem(1,189)));
	tran.insert(make_pair("&", TableItem(1,190)));
	tran.insert(make_pair("<<", TableItem(1,191)));
	tran.insert(make_pair(">>", TableItem(1,192)));
	tran.insert(make_pair("+", TableItem(1,193)));
	tran.insert(make_pair("-", TableItem(1,194)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(1,198)));
	_parseTable.insert(make_pair(111,tran));
	tran.clear();


	// state 112
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,199)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(112,tran));
	tran.clear();


	// state 113
	tran.insert(make_pair("|", TableItem(2,48)));
	tran.insert(make_pair("^", TableItem(2,48)));
	tran.insert(make_pair("&", TableItem(2,48)));
	tran.insert(make_pair("<<", TableItem(2,48)));
	tran.insert(make_pair(">>", TableItem(2,48)));
	tran.insert(make_pair("+", TableItem(2,48)));
	tran.insert(make_pair("-", TableItem(2,48)));
	tran.insert(make_pair("*", TableItem(2,48)));
	tran.insert(make_pair("/", TableItem(2,48)));
	tran.insert(make_pair("%", TableItem(2,48)));
	tran.insert(make_pair("(", TableItem(1,200)));
	tran.insert(make_pair(",", TableItem(2,48)));
	tran.insert(make_pair("[", TableItem(1,201)));
	_parseTable.insert(make_pair(113,tran));
	tran.clear();


	// state 114
	tran.insert(make_pair("|", TableItem(2,50)));
	tran.insert(make_pair("^", TableItem(2,50)));
	tran.insert(make_pair("&", TableItem(2,50)));
	tran.insert(make_pair("<<", TableItem(2,50)));
	tran.insert(make_pair(">>", TableItem(2,50)));
	tran.insert(make_pair("+", TableItem(2,50)));
	tran.insert(make_pair("-", TableItem(2,50)));
	tran.insert(make_pair("*", TableItem(2,50)));
	tran.insert(make_pair("/", TableItem(2,50)));
	tran.insert(make_pair("%", TableItem(2,50)));
	tran.insert(make_pair(",", TableItem(2,50)));
	_parseTable.insert(make_pair(114,tran));
	tran.clear();


	// state 115
	tran.insert(make_pair("(", TableItem(1,202)));
	_parseTable.insert(make_pair(115,tran));
	tran.clear();


	// state 116
	tran.insert(make_pair(">", TableItem(1,203)));
	_parseTable.insert(make_pair(116,tran));
	tran.clear();


	// state 117
	tran.insert(make_pair("\"", TableItem(1,204)));
	_parseTable.insert(make_pair(117,tran));
	tran.clear();


	// state 118
	tran.insert(make_pair("stmts", TableItem(3,205)));
	tran.insert(make_pair("stmt", TableItem(3,30)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(118,tran));
	tran.clear();


	// state 119
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,206)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(119,tran));
	tran.clear();


	// state 120
	tran.insert(make_pair(")", TableItem(1,207)));
	tran.insert(make_pair("type_spec", TableItem(3,208)));
	tran.insert(make_pair("param_list", TableItem(3,209)));
	tran.insert(make_pair("param", TableItem(3,210)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	_parseTable.insert(make_pair(120,tran));
	tran.clear();


	// state 121
	tran.insert(make_pair("num", TableItem(1,211)));
	_parseTable.insert(make_pair(121,tran));
	tran.clear();


	// state 122
	tran.insert(make_pair("|", TableItem(1,90)));
	tran.insert(make_pair("^", TableItem(1,91)));
	tran.insert(make_pair("&", TableItem(1,92)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,35)));
	_parseTable.insert(make_pair(122,tran));
	tran.clear();


	// state 123
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,212)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(123,tran));
	tran.clear();


	// state 124
	tran.insert(make_pair("|", TableItem(1,213)));
	tran.insert(make_pair("^", TableItem(1,214)));
	tran.insert(make_pair("&", TableItem(1,215)));
	tran.insert(make_pair("<<", TableItem(1,216)));
	tran.insert(make_pair(">>", TableItem(1,217)));
	tran.insert(make_pair("+", TableItem(1,218)));
	tran.insert(make_pair("-", TableItem(1,219)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,55)));
	tran.insert(make_pair(")", TableItem(2,55)));
	_parseTable.insert(make_pair(124,tran));
	tran.clear();


	// state 125
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,223)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(125,tran));
	tran.clear();


	// state 126
	tran.insert(make_pair("|", TableItem(2,48)));
	tran.insert(make_pair("^", TableItem(2,48)));
	tran.insert(make_pair("&", TableItem(2,48)));
	tran.insert(make_pair("<<", TableItem(2,48)));
	tran.insert(make_pair(">>", TableItem(2,48)));
	tran.insert(make_pair("+", TableItem(2,48)));
	tran.insert(make_pair("-", TableItem(2,48)));
	tran.insert(make_pair("*", TableItem(2,48)));
	tran.insert(make_pair("/", TableItem(2,48)));
	tran.insert(make_pair("%", TableItem(2,48)));
	tran.insert(make_pair("(", TableItem(1,224)));
	tran.insert(make_pair(",", TableItem(2,48)));
	tran.insert(make_pair(")", TableItem(2,48)));
	tran.insert(make_pair("[", TableItem(1,225)));
	_parseTable.insert(make_pair(126,tran));
	tran.clear();


	// state 127
	tran.insert(make_pair("|", TableItem(2,50)));
	tran.insert(make_pair("^", TableItem(2,50)));
	tran.insert(make_pair("&", TableItem(2,50)));
	tran.insert(make_pair("<<", TableItem(2,50)));
	tran.insert(make_pair(">>", TableItem(2,50)));
	tran.insert(make_pair("+", TableItem(2,50)));
	tran.insert(make_pair("-", TableItem(2,50)));
	tran.insert(make_pair("*", TableItem(2,50)));
	tran.insert(make_pair("/", TableItem(2,50)));
	tran.insert(make_pair("%", TableItem(2,50)));
	tran.insert(make_pair(",", TableItem(2,50)));
	tran.insert(make_pair(")", TableItem(2,50)));
	_parseTable.insert(make_pair(127,tran));
	tran.clear();


	// state 128
	tran.insert(make_pair(",", TableItem(1,226)));
	tran.insert(make_pair(")", TableItem(1,227)));
	_parseTable.insert(make_pair(128,tran));
	tran.clear();


	// state 129
	tran.insert(make_pair("(", TableItem(1,228)));
	_parseTable.insert(make_pair(129,tran));
	tran.clear();


	// state 130
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,229)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(130,tran));
	tran.clear();


	// state 131
	tran.insert(make_pair("|", TableItem(1,230)));
	tran.insert(make_pair("^", TableItem(1,231)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(1,240)));
	_parseTable.insert(make_pair(131,tran));
	tran.clear();


	// state 132
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,241)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(132,tran));
	tran.clear();


	// state 133
	tran.insert(make_pair("|", TableItem(2,48)));
	tran.insert(make_pair("^", TableItem(2,48)));
	tran.insert(make_pair("&", TableItem(2,48)));
	tran.insert(make_pair("<<", TableItem(2,48)));
	tran.insert(make_pair(">>", TableItem(2,48)));
	tran.insert(make_pair("+", TableItem(2,48)));
	tran.insert(make_pair("-", TableItem(2,48)));
	tran.insert(make_pair("*", TableItem(2,48)));
	tran.insert(make_pair("/", TableItem(2,48)));
	tran.insert(make_pair("%", TableItem(2,48)));
	tran.insert(make_pair("(", TableItem(1,242)));
	tran.insert(make_pair("[", TableItem(1,243)));
	tran.insert(make_pair("]", TableItem(2,48)));
	_parseTable.insert(make_pair(133,tran));
	tran.clear();


	// state 134
	tran.insert(make_pair("|", TableItem(2,50)));
	tran.insert(make_pair("^", TableItem(2,50)));
	tran.insert(make_pair("&", TableItem(2,50)));
	tran.insert(make_pair("<<", TableItem(2,50)));
	tran.insert(make_pair(">>", TableItem(2,50)));
	tran.insert(make_pair("+", TableItem(2,50)));
	tran.insert(make_pair("-", TableItem(2,50)));
	tran.insert(make_pair("*", TableItem(2,50)));
	tran.insert(make_pair("/", TableItem(2,50)));
	tran.insert(make_pair("%", TableItem(2,50)));
	tran.insert(make_pair("]", TableItem(2,50)));
	_parseTable.insert(make_pair(134,tran));
	tran.clear();


	// state 135
	tran.insert(make_pair("(", TableItem(1,244)));
	_parseTable.insert(make_pair(135,tran));
	tran.clear();


	// state 136
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,245)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(136,tran));
	tran.clear();


	// state 137
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,247)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(137,tran));
	tran.clear();


	// state 138
	tran.insert(make_pair("||", TableItem(2,66)));
	tran.insert(make_pair("&&", TableItem(2,66)));
	tran.insert(make_pair("|", TableItem(1,248)));
	tran.insert(make_pair("^", TableItem(1,249)));
	tran.insert(make_pair("&", TableItem(1,250)));
	tran.insert(make_pair("==", TableItem(1,251)));
	tran.insert(make_pair("!=", TableItem(1,252)));
	tran.insert(make_pair("<", TableItem(1,253)));
	tran.insert(make_pair(">", TableItem(1,254)));
	tran.insert(make_pair("<=", TableItem(1,255)));
	tran.insert(make_pair(">=", TableItem(1,256)));
	tran.insert(make_pair("<<", TableItem(1,257)));
	tran.insert(make_pair(">>", TableItem(1,258)));
	tran.insert(make_pair("+", TableItem(1,259)));
	tran.insert(make_pair("-", TableItem(1,260)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,66)));
	tran.insert(make_pair("rel", TableItem(3,264)));
	_parseTable.insert(make_pair(138,tran));
	tran.clear();


	// state 139
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,265)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,266)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(139,tran));
	tran.clear();


	// state 140
	tran.insert(make_pair("||", TableItem(2,48)));
	tran.insert(make_pair("&&", TableItem(2,48)));
	tran.insert(make_pair("|", TableItem(2,48)));
	tran.insert(make_pair("^", TableItem(2,48)));
	tran.insert(make_pair("&", TableItem(2,48)));
	tran.insert(make_pair("==", TableItem(2,48)));
	tran.insert(make_pair("!=", TableItem(2,48)));
	tran.insert(make_pair("<", TableItem(2,48)));
	tran.insert(make_pair(">", TableItem(2,48)));
	tran.insert(make_pair("<=", TableItem(2,48)));
	tran.insert(make_pair(">=", TableItem(2,48)));
	tran.insert(make_pair("<<", TableItem(2,48)));
	tran.insert(make_pair(">>", TableItem(2,48)));
	tran.insert(make_pair("+", TableItem(2,48)));
	tran.insert(make_pair("-", TableItem(2,48)));
	tran.insert(make_pair("*", TableItem(2,48)));
	tran.insert(make_pair("/", TableItem(2,48)));
	tran.insert(make_pair("%", TableItem(2,48)));
	tran.insert(make_pair("(", TableItem(1,267)));
	tran.insert(make_pair(")", TableItem(2,48)));
	tran.insert(make_pair("[", TableItem(1,268)));
	_parseTable.insert(make_pair(140,tran));
	tran.clear();


	// state 141
	tran.insert(make_pair("||", TableItem(2,50)));
	tran.insert(make_pair("&&", TableItem(2,50)));
	tran.insert(make_pair("|", TableItem(2,50)));
	tran.insert(make_pair("^", TableItem(2,50)));
	tran.insert(make_pair("&", TableItem(2,50)));
	tran.insert(make_pair("==", TableItem(2,50)));
	tran.insert(make_pair("!=", TableItem(2,50)));
	tran.insert(make_pair("<", TableItem(2,50)));
	tran.insert(make_pair(">", TableItem(2,50)));
	tran.insert(make_pair("<=", TableItem(2,50)));
	tran.insert(make_pair(">=", TableItem(2,50)));
	tran.insert(make_pair("<<", TableItem(2,50)));
	tran.insert(make_pair(">>", TableItem(2,50)));
	tran.insert(make_pair("+", TableItem(2,50)));
	tran.insert(make_pair("-", TableItem(2,50)));
	tran.insert(make_pair("*", TableItem(2,50)));
	tran.insert(make_pair("/", TableItem(2,50)));
	tran.insert(make_pair("%", TableItem(2,50)));
	tran.insert(make_pair(")", TableItem(2,50)));
	_parseTable.insert(make_pair(141,tran));
	tran.clear();


	// state 142
	tran.insert(make_pair("(", TableItem(1,269)));
	_parseTable.insert(make_pair(142,tran));
	tran.clear();


	// state 143
	tran.insert(make_pair("||", TableItem(1,270)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(1,272)));
	_parseTable.insert(make_pair(143,tran));
	tran.clear();


	// state 144
	tran.insert(make_pair("||", TableItem(2,67)));
	tran.insert(make_pair("&&", TableItem(2,67)));
	tran.insert(make_pair(")", TableItem(2,67)));
	_parseTable.insert(make_pair(144,tran));
	tran.clear();


	// state 145
	tran.insert(make_pair("||", TableItem(2,68)));
	tran.insert(make_pair("&&", TableItem(2,68)));
	tran.insert(make_pair(")", TableItem(2,68)));
	_parseTable.insert(make_pair(145,tran));
	tran.clear();


	// state 146
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,273)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(146,tran));
	tran.clear();


	// state 147
	tran.insert(make_pair("{", TableItem(2,2)));
	tran.insert(make_pair("}", TableItem(2,2)));
	tran.insert(make_pair(";", TableItem(2,2)));
	tran.insert(make_pair("static", TableItem(2,2)));
	tran.insert(make_pair("return", TableItem(2,2)));
	tran.insert(make_pair("set_mem", TableItem(2,2)));
	tran.insert(make_pair("include", TableItem(2,2)));
	tran.insert(make_pair("id", TableItem(2,2)));
	tran.insert(make_pair("int", TableItem(2,2)));
	tran.insert(make_pair("double", TableItem(2,2)));
	tran.insert(make_pair("void", TableItem(2,2)));
	tran.insert(make_pair("char", TableItem(2,2)));
	tran.insert(make_pair("bool", TableItem(2,2)));
	tran.insert(make_pair("float", TableItem(2,2)));
	tran.insert(make_pair("if", TableItem(2,2)));
	tran.insert(make_pair("while", TableItem(2,2)));
	_parseTable.insert(make_pair(147,tran));
	tran.clear();


	// state 148
	tran.insert(make_pair("{", TableItem(2,5)));
	tran.insert(make_pair("}", TableItem(2,5)));
	tran.insert(make_pair(";", TableItem(2,5)));
	tran.insert(make_pair("static", TableItem(2,5)));
	tran.insert(make_pair("return", TableItem(2,5)));
	tran.insert(make_pair("set_mem", TableItem(2,5)));
	tran.insert(make_pair("include", TableItem(2,5)));
	tran.insert(make_pair("id", TableItem(2,5)));
	tran.insert(make_pair("int", TableItem(2,5)));
	tran.insert(make_pair("double", TableItem(2,5)));
	tran.insert(make_pair("void", TableItem(2,5)));
	tran.insert(make_pair("char", TableItem(2,5)));
	tran.insert(make_pair("bool", TableItem(2,5)));
	tran.insert(make_pair("float", TableItem(2,5)));
	tran.insert(make_pair("if", TableItem(2,5)));
	tran.insert(make_pair("while", TableItem(2,5)));
	_parseTable.insert(make_pair(148,tran));
	tran.clear();


	// state 149
	tran.insert(make_pair("{", TableItem(2,10)));
	tran.insert(make_pair("}", TableItem(2,10)));
	tran.insert(make_pair(";", TableItem(2,10)));
	tran.insert(make_pair("static", TableItem(2,10)));
	tran.insert(make_pair("return", TableItem(2,10)));
	tran.insert(make_pair("set_mem", TableItem(2,10)));
	tran.insert(make_pair("include", TableItem(2,10)));
	tran.insert(make_pair("id", TableItem(2,10)));
	tran.insert(make_pair("int", TableItem(2,10)));
	tran.insert(make_pair("double", TableItem(2,10)));
	tran.insert(make_pair("void", TableItem(2,10)));
	tran.insert(make_pair("char", TableItem(2,10)));
	tran.insert(make_pair("bool", TableItem(2,10)));
	tran.insert(make_pair("float", TableItem(2,10)));
	tran.insert(make_pair("if", TableItem(2,10)));
	tran.insert(make_pair("while", TableItem(2,10)));
	_parseTable.insert(make_pair(149,tran));
	tran.clear();


	// state 150
	tran.insert(make_pair("{", TableItem(2,12)));
	tran.insert(make_pair("}", TableItem(2,12)));
	tran.insert(make_pair(";", TableItem(2,12)));
	tran.insert(make_pair("static", TableItem(2,12)));
	tran.insert(make_pair("return", TableItem(2,12)));
	tran.insert(make_pair("set_mem", TableItem(2,12)));
	tran.insert(make_pair("include", TableItem(2,12)));
	tran.insert(make_pair("id", TableItem(2,12)));
	tran.insert(make_pair("int", TableItem(2,12)));
	tran.insert(make_pair("double", TableItem(2,12)));
	tran.insert(make_pair("void", TableItem(2,12)));
	tran.insert(make_pair("char", TableItem(2,12)));
	tran.insert(make_pair("bool", TableItem(2,12)));
	tran.insert(make_pair("float", TableItem(2,12)));
	tran.insert(make_pair("if", TableItem(2,12)));
	tran.insert(make_pair("while", TableItem(2,12)));
	_parseTable.insert(make_pair(150,tran));
	tran.clear();


	// state 151
	tran.insert(make_pair("|", TableItem(1,188)));
	tran.insert(make_pair("^", TableItem(1,189)));
	tran.insert(make_pair("&", TableItem(1,190)));
	tran.insert(make_pair("<<", TableItem(1,191)));
	tran.insert(make_pair(">>", TableItem(1,192)));
	tran.insert(make_pair("+", TableItem(1,193)));
	tran.insert(make_pair("-", TableItem(1,194)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(1,274)));
	_parseTable.insert(make_pair(151,tran));
	tran.clear();


	// state 152
	tran.insert(make_pair(">", TableItem(1,275)));
	_parseTable.insert(make_pair(152,tran));
	tran.clear();


	// state 153
	tran.insert(make_pair("\"", TableItem(1,276)));
	_parseTable.insert(make_pair(153,tran));
	tran.clear();


	// state 154
	tran.insert(make_pair("stmts", TableItem(3,277)));
	tran.insert(make_pair("stmt", TableItem(3,30)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(154,tran));
	tran.clear();


	// state 155
	tran.insert(make_pair(")", TableItem(1,278)));
	tran.insert(make_pair("type_spec", TableItem(3,208)));
	tran.insert(make_pair("param_list", TableItem(3,279)));
	tran.insert(make_pair("param", TableItem(3,210)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	_parseTable.insert(make_pair(155,tran));
	tran.clear();


	// state 156
	tran.insert(make_pair("||", TableItem(1,270)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(1,280)));
	_parseTable.insert(make_pair(156,tran));
	tran.clear();


	// state 157
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,281)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(157,tran));
	tran.clear();


	// state 158
	tran.insert(make_pair("|", TableItem(2,43)));
	tran.insert(make_pair("^", TableItem(1,91)));
	tran.insert(make_pair("&", TableItem(1,92)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,43)));
	_parseTable.insert(make_pair(158,tran));
	tran.clear();


	// state 159
	tran.insert(make_pair("|", TableItem(2,44)));
	tran.insert(make_pair("^", TableItem(2,44)));
	tran.insert(make_pair("&", TableItem(1,92)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,44)));
	_parseTable.insert(make_pair(159,tran));
	tran.clear();


	// state 160
	tran.insert(make_pair("|", TableItem(2,42)));
	tran.insert(make_pair("^", TableItem(2,42)));
	tran.insert(make_pair("&", TableItem(2,42)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,42)));
	_parseTable.insert(make_pair(160,tran));
	tran.clear();


	// state 161
	tran.insert(make_pair("|", TableItem(2,46)));
	tran.insert(make_pair("^", TableItem(2,46)));
	tran.insert(make_pair("&", TableItem(2,46)));
	tran.insert(make_pair("<<", TableItem(2,46)));
	tran.insert(make_pair(">>", TableItem(2,46)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,46)));
	_parseTable.insert(make_pair(161,tran));
	tran.clear();


	// state 162
	tran.insert(make_pair("|", TableItem(2,45)));
	tran.insert(make_pair("^", TableItem(2,45)));
	tran.insert(make_pair("&", TableItem(2,45)));
	tran.insert(make_pair("<<", TableItem(2,45)));
	tran.insert(make_pair(">>", TableItem(2,45)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,45)));
	_parseTable.insert(make_pair(162,tran));
	tran.clear();


	// state 163
	tran.insert(make_pair("|", TableItem(2,37)));
	tran.insert(make_pair("^", TableItem(2,37)));
	tran.insert(make_pair("&", TableItem(2,37)));
	tran.insert(make_pair("<<", TableItem(2,37)));
	tran.insert(make_pair(">>", TableItem(2,37)));
	tran.insert(make_pair("+", TableItem(2,37)));
	tran.insert(make_pair("-", TableItem(2,37)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,37)));
	_parseTable.insert(make_pair(163,tran));
	tran.clear();


	// state 164
	tran.insert(make_pair("|", TableItem(2,38)));
	tran.insert(make_pair("^", TableItem(2,38)));
	tran.insert(make_pair("&", TableItem(2,38)));
	tran.insert(make_pair("<<", TableItem(2,38)));
	tran.insert(make_pair(">>", TableItem(2,38)));
	tran.insert(make_pair("+", TableItem(2,38)));
	tran.insert(make_pair("-", TableItem(2,38)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,38)));
	_parseTable.insert(make_pair(164,tran));
	tran.clear();


	// state 165
	tran.insert(make_pair("|", TableItem(2,39)));
	tran.insert(make_pair("^", TableItem(2,39)));
	tran.insert(make_pair("&", TableItem(2,39)));
	tran.insert(make_pair("<<", TableItem(2,39)));
	tran.insert(make_pair(">>", TableItem(2,39)));
	tran.insert(make_pair("+", TableItem(2,39)));
	tran.insert(make_pair("-", TableItem(2,39)));
	tran.insert(make_pair("*", TableItem(2,39)));
	tran.insert(make_pair("/", TableItem(2,39)));
	tran.insert(make_pair("%", TableItem(2,39)));
	tran.insert(make_pair(";", TableItem(2,39)));
	_parseTable.insert(make_pair(165,tran));
	tran.clear();


	// state 166
	tran.insert(make_pair("|", TableItem(2,40)));
	tran.insert(make_pair("^", TableItem(2,40)));
	tran.insert(make_pair("&", TableItem(2,40)));
	tran.insert(make_pair("<<", TableItem(2,40)));
	tran.insert(make_pair(">>", TableItem(2,40)));
	tran.insert(make_pair("+", TableItem(2,40)));
	tran.insert(make_pair("-", TableItem(2,40)));
	tran.insert(make_pair("*", TableItem(2,40)));
	tran.insert(make_pair("/", TableItem(2,40)));
	tran.insert(make_pair("%", TableItem(2,40)));
	tran.insert(make_pair(";", TableItem(2,40)));
	_parseTable.insert(make_pair(166,tran));
	tran.clear();


	// state 167
	tran.insert(make_pair("|", TableItem(2,41)));
	tran.insert(make_pair("^", TableItem(2,41)));
	tran.insert(make_pair("&", TableItem(2,41)));
	tran.insert(make_pair("<<", TableItem(2,41)));
	tran.insert(make_pair(">>", TableItem(2,41)));
	tran.insert(make_pair("+", TableItem(2,41)));
	tran.insert(make_pair("-", TableItem(2,41)));
	tran.insert(make_pair("*", TableItem(2,41)));
	tran.insert(make_pair("/", TableItem(2,41)));
	tran.insert(make_pair("%", TableItem(2,41)));
	tran.insert(make_pair(";", TableItem(2,41)));
	_parseTable.insert(make_pair(167,tran));
	tran.clear();


	// state 168
	tran.insert(make_pair("|", TableItem(2,51)));
	tran.insert(make_pair("^", TableItem(2,51)));
	tran.insert(make_pair("&", TableItem(2,51)));
	tran.insert(make_pair("<<", TableItem(2,51)));
	tran.insert(make_pair(">>", TableItem(2,51)));
	tran.insert(make_pair("+", TableItem(2,51)));
	tran.insert(make_pair("-", TableItem(2,51)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(2,51)));
	_parseTable.insert(make_pair(168,tran));
	tran.clear();


	// state 169
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,282)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(169,tran));
	tran.clear();


	// state 170
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,283)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(170,tran));
	tran.clear();


	// state 171
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,284)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(171,tran));
	tran.clear();


	// state 172
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,285)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(172,tran));
	tran.clear();


	// state 173
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,286)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(173,tran));
	tran.clear();


	// state 174
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,287)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(174,tran));
	tran.clear();


	// state 175
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,288)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(175,tran));
	tran.clear();


	// state 176
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,289)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(176,tran));
	tran.clear();


	// state 177
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,290)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(177,tran));
	tran.clear();


	// state 178
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,291)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(178,tran));
	tran.clear();


	// state 179
	tran.insert(make_pair("|", TableItem(2,47)));
	tran.insert(make_pair("^", TableItem(2,47)));
	tran.insert(make_pair("&", TableItem(2,47)));
	tran.insert(make_pair("<<", TableItem(2,47)));
	tran.insert(make_pair(">>", TableItem(2,47)));
	tran.insert(make_pair("+", TableItem(2,47)));
	tran.insert(make_pair("-", TableItem(2,47)));
	tran.insert(make_pair("*", TableItem(2,47)));
	tran.insert(make_pair("/", TableItem(2,47)));
	tran.insert(make_pair("%", TableItem(2,47)));
	tran.insert(make_pair(";", TableItem(2,47)));
	_parseTable.insert(make_pair(179,tran));
	tran.clear();


	// state 180
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,292)));
	_parseTable.insert(make_pair(180,tran));
	tran.clear();


	// state 181
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,124)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair(",", TableItem(2,56)));
	tran.insert(make_pair(")", TableItem(2,56)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("arg_list", TableItem(3,293)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(181,tran));
	tran.clear();


	// state 182
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,294)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(182,tran));
	tran.clear();


	// state 183
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,295)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(183,tran));
	tran.clear();


	// state 184
	tran.insert(make_pair(",", TableItem(1,226)));
	tran.insert(make_pair(")", TableItem(1,296)));
	_parseTable.insert(make_pair(184,tran));
	tran.clear();


	// state 185
	tran.insert(make_pair("|", TableItem(1,230)));
	tran.insert(make_pair("^", TableItem(1,231)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(1,297)));
	_parseTable.insert(make_pair(185,tran));
	tran.clear();


	// state 186
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,298)));
	_parseTable.insert(make_pair(186,tran));
	tran.clear();


	// state 187
	tran.insert(make_pair("|", TableItem(2,51)));
	tran.insert(make_pair("^", TableItem(2,51)));
	tran.insert(make_pair("&", TableItem(2,51)));
	tran.insert(make_pair("<<", TableItem(2,51)));
	tran.insert(make_pair(">>", TableItem(2,51)));
	tran.insert(make_pair("+", TableItem(2,51)));
	tran.insert(make_pair("-", TableItem(2,51)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(2,51)));
	_parseTable.insert(make_pair(187,tran));
	tran.clear();


	// state 188
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,299)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(188,tran));
	tran.clear();


	// state 189
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,300)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(189,tran));
	tran.clear();


	// state 190
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,301)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(190,tran));
	tran.clear();


	// state 191
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,302)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(191,tran));
	tran.clear();


	// state 192
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,303)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(192,tran));
	tran.clear();


	// state 193
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,304)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(193,tran));
	tran.clear();


	// state 194
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,305)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(194,tran));
	tran.clear();


	// state 195
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,306)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(195,tran));
	tran.clear();


	// state 196
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,307)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(196,tran));
	tran.clear();


	// state 197
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,308)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(197,tran));
	tran.clear();


	// state 198
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,309)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(198,tran));
	tran.clear();


	// state 199
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,310)));
	_parseTable.insert(make_pair(199,tran));
	tran.clear();


	// state 200
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,124)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair(",", TableItem(2,56)));
	tran.insert(make_pair(")", TableItem(2,56)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("arg_list", TableItem(3,311)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(200,tran));
	tran.clear();


	// state 201
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,312)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(201,tran));
	tran.clear();


	// state 202
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,313)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(202,tran));
	tran.clear();


	// state 203
	tran.insert(make_pair("{", TableItem(2,18)));
	tran.insert(make_pair(";", TableItem(2,18)));
	tran.insert(make_pair("static", TableItem(2,18)));
	tran.insert(make_pair("return", TableItem(2,18)));
	tran.insert(make_pair("set_mem", TableItem(2,18)));
	tran.insert(make_pair("include", TableItem(2,18)));
	tran.insert(make_pair("id", TableItem(2,18)));
	tran.insert(make_pair("int", TableItem(2,18)));
	tran.insert(make_pair("double", TableItem(2,18)));
	tran.insert(make_pair("void", TableItem(2,18)));
	tran.insert(make_pair("char", TableItem(2,18)));
	tran.insert(make_pair("bool", TableItem(2,18)));
	tran.insert(make_pair("float", TableItem(2,18)));
	tran.insert(make_pair("if", TableItem(2,18)));
	tran.insert(make_pair("while", TableItem(2,18)));
	tran.insert(make_pair("$", TableItem(2,18)));
	_parseTable.insert(make_pair(203,tran));
	tran.clear();


	// state 204
	tran.insert(make_pair("{", TableItem(2,17)));
	tran.insert(make_pair(";", TableItem(2,17)));
	tran.insert(make_pair("static", TableItem(2,17)));
	tran.insert(make_pair("return", TableItem(2,17)));
	tran.insert(make_pair("set_mem", TableItem(2,17)));
	tran.insert(make_pair("include", TableItem(2,17)));
	tran.insert(make_pair("id", TableItem(2,17)));
	tran.insert(make_pair("int", TableItem(2,17)));
	tran.insert(make_pair("double", TableItem(2,17)));
	tran.insert(make_pair("void", TableItem(2,17)));
	tran.insert(make_pair("char", TableItem(2,17)));
	tran.insert(make_pair("bool", TableItem(2,17)));
	tran.insert(make_pair("float", TableItem(2,17)));
	tran.insert(make_pair("if", TableItem(2,17)));
	tran.insert(make_pair("while", TableItem(2,17)));
	tran.insert(make_pair("$", TableItem(2,17)));
	_parseTable.insert(make_pair(204,tran));
	tran.clear();


	// state 205
	tran.insert(make_pair("M", TableItem(3,71)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair("}", TableItem(1,314)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(205,tran));
	tran.clear();


	// state 206
	tran.insert(make_pair("|", TableItem(1,90)));
	tran.insert(make_pair("^", TableItem(1,91)));
	tran.insert(make_pair("&", TableItem(1,92)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,27)));
	_parseTable.insert(make_pair(206,tran));
	tran.clear();


	// state 207
	tran.insert(make_pair("{", TableItem(2,20)));
	tran.insert(make_pair(";", TableItem(2,20)));
	tran.insert(make_pair("static", TableItem(2,20)));
	tran.insert(make_pair("return", TableItem(2,20)));
	tran.insert(make_pair("set_mem", TableItem(2,20)));
	tran.insert(make_pair("include", TableItem(2,20)));
	tran.insert(make_pair("id", TableItem(2,20)));
	tran.insert(make_pair("int", TableItem(2,20)));
	tran.insert(make_pair("double", TableItem(2,20)));
	tran.insert(make_pair("void", TableItem(2,20)));
	tran.insert(make_pair("char", TableItem(2,20)));
	tran.insert(make_pair("bool", TableItem(2,20)));
	tran.insert(make_pair("float", TableItem(2,20)));
	tran.insert(make_pair("if", TableItem(2,20)));
	tran.insert(make_pair("while", TableItem(2,20)));
	tran.insert(make_pair("$", TableItem(2,20)));
	_parseTable.insert(make_pair(207,tran));
	tran.clear();


	// state 208
	tran.insert(make_pair("id", TableItem(1,315)));
	_parseTable.insert(make_pair(208,tran));
	tran.clear();


	// state 209
	tran.insert(make_pair(",", TableItem(1,316)));
	tran.insert(make_pair(")", TableItem(1,317)));
	_parseTable.insert(make_pair(209,tran));
	tran.clear();


	// state 210
	tran.insert(make_pair(",", TableItem(2,23)));
	tran.insert(make_pair(")", TableItem(2,23)));
	_parseTable.insert(make_pair(210,tran));
	tran.clear();


	// state 211
	tran.insert(make_pair("]", TableItem(1,318)));
	_parseTable.insert(make_pair(211,tran));
	tran.clear();


	// state 212
	tran.insert(make_pair("|", TableItem(2,51)));
	tran.insert(make_pair("^", TableItem(2,51)));
	tran.insert(make_pair("&", TableItem(2,51)));
	tran.insert(make_pair("<<", TableItem(2,51)));
	tran.insert(make_pair(">>", TableItem(2,51)));
	tran.insert(make_pair("+", TableItem(2,51)));
	tran.insert(make_pair("-", TableItem(2,51)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,51)));
	tran.insert(make_pair(")", TableItem(2,51)));
	_parseTable.insert(make_pair(212,tran));
	tran.clear();


	// state 213
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,319)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(213,tran));
	tran.clear();


	// state 214
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,320)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(214,tran));
	tran.clear();


	// state 215
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,321)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(215,tran));
	tran.clear();


	// state 216
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,322)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(216,tran));
	tran.clear();


	// state 217
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,323)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(217,tran));
	tran.clear();


	// state 218
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,324)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(218,tran));
	tran.clear();


	// state 219
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,325)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(219,tran));
	tran.clear();


	// state 220
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,326)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(220,tran));
	tran.clear();


	// state 221
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,327)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(221,tran));
	tran.clear();


	// state 222
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,328)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(222,tran));
	tran.clear();


	// state 223
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,329)));
	_parseTable.insert(make_pair(223,tran));
	tran.clear();


	// state 224
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,124)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair(",", TableItem(2,56)));
	tran.insert(make_pair(")", TableItem(2,56)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("arg_list", TableItem(3,330)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(224,tran));
	tran.clear();


	// state 225
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,331)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(225,tran));
	tran.clear();


	// state 226
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,332)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(226,tran));
	tran.clear();


	// state 227
	tran.insert(make_pair(";", TableItem(2,57)));
	_parseTable.insert(make_pair(227,tran));
	tran.clear();


	// state 228
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,333)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(228,tran));
	tran.clear();


	// state 229
	tran.insert(make_pair("|", TableItem(2,51)));
	tran.insert(make_pair("^", TableItem(2,51)));
	tran.insert(make_pair("&", TableItem(2,51)));
	tran.insert(make_pair("<<", TableItem(2,51)));
	tran.insert(make_pair(">>", TableItem(2,51)));
	tran.insert(make_pair("+", TableItem(2,51)));
	tran.insert(make_pair("-", TableItem(2,51)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(2,51)));
	_parseTable.insert(make_pair(229,tran));
	tran.clear();


	// state 230
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,334)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(230,tran));
	tran.clear();


	// state 231
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,335)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(231,tran));
	tran.clear();


	// state 232
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,336)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(232,tran));
	tran.clear();


	// state 233
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,337)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(233,tran));
	tran.clear();


	// state 234
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,338)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(234,tran));
	tran.clear();


	// state 235
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,339)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(235,tran));
	tran.clear();


	// state 236
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,340)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(236,tran));
	tran.clear();


	// state 237
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,341)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(237,tran));
	tran.clear();


	// state 238
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,342)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(238,tran));
	tran.clear();


	// state 239
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,343)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(239,tran));
	tran.clear();


	// state 240
	tran.insert(make_pair("=", TableItem(1,344)));
	_parseTable.insert(make_pair(240,tran));
	tran.clear();


	// state 241
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,345)));
	_parseTable.insert(make_pair(241,tran));
	tran.clear();


	// state 242
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,124)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair(",", TableItem(2,56)));
	tran.insert(make_pair(")", TableItem(2,56)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("arg_list", TableItem(3,346)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(242,tran));
	tran.clear();


	// state 243
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,347)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(243,tran));
	tran.clear();


	// state 244
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,348)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(244,tran));
	tran.clear();


	// state 245
	tran.insert(make_pair("||", TableItem(2,51)));
	tran.insert(make_pair("&&", TableItem(2,51)));
	tran.insert(make_pair("|", TableItem(2,51)));
	tran.insert(make_pair("^", TableItem(2,51)));
	tran.insert(make_pair("&", TableItem(2,51)));
	tran.insert(make_pair("==", TableItem(2,51)));
	tran.insert(make_pair("!=", TableItem(2,51)));
	tran.insert(make_pair("<", TableItem(2,51)));
	tran.insert(make_pair(">", TableItem(2,51)));
	tran.insert(make_pair("<=", TableItem(2,51)));
	tran.insert(make_pair(">=", TableItem(2,51)));
	tran.insert(make_pair("<<", TableItem(2,51)));
	tran.insert(make_pair(">>", TableItem(2,51)));
	tran.insert(make_pair("+", TableItem(2,51)));
	tran.insert(make_pair("-", TableItem(2,51)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,51)));
	_parseTable.insert(make_pair(245,tran));
	tran.clear();


	// state 246
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,349)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(246,tran));
	tran.clear();


	// state 247
	tran.insert(make_pair("||", TableItem(2,63)));
	tran.insert(make_pair("&&", TableItem(2,63)));
	tran.insert(make_pair(")", TableItem(2,63)));
	_parseTable.insert(make_pair(247,tran));
	tran.clear();


	// state 248
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,350)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(248,tran));
	tran.clear();


	// state 249
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,351)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(249,tran));
	tran.clear();


	// state 250
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,352)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(250,tran));
	tran.clear();


	// state 251
	tran.insert(make_pair("-", TableItem(2,76)));
	tran.insert(make_pair("(", TableItem(2,76)));
	tran.insert(make_pair("id", TableItem(2,76)));
	tran.insert(make_pair("num", TableItem(2,76)));
	tran.insert(make_pair("load_mem", TableItem(2,76)));
	_parseTable.insert(make_pair(251,tran));
	tran.clear();


	// state 252
	tran.insert(make_pair("-", TableItem(2,77)));
	tran.insert(make_pair("(", TableItem(2,77)));
	tran.insert(make_pair("id", TableItem(2,77)));
	tran.insert(make_pair("num", TableItem(2,77)));
	tran.insert(make_pair("load_mem", TableItem(2,77)));
	_parseTable.insert(make_pair(252,tran));
	tran.clear();


	// state 253
	tran.insert(make_pair("-", TableItem(2,72)));
	tran.insert(make_pair("(", TableItem(2,72)));
	tran.insert(make_pair("id", TableItem(2,72)));
	tran.insert(make_pair("num", TableItem(2,72)));
	tran.insert(make_pair("load_mem", TableItem(2,72)));
	_parseTable.insert(make_pair(253,tran));
	tran.clear();


	// state 254
	tran.insert(make_pair("-", TableItem(2,73)));
	tran.insert(make_pair("(", TableItem(2,73)));
	tran.insert(make_pair("id", TableItem(2,73)));
	tran.insert(make_pair("num", TableItem(2,73)));
	tran.insert(make_pair("load_mem", TableItem(2,73)));
	_parseTable.insert(make_pair(254,tran));
	tran.clear();


	// state 255
	tran.insert(make_pair("-", TableItem(2,74)));
	tran.insert(make_pair("(", TableItem(2,74)));
	tran.insert(make_pair("id", TableItem(2,74)));
	tran.insert(make_pair("num", TableItem(2,74)));
	tran.insert(make_pair("load_mem", TableItem(2,74)));
	_parseTable.insert(make_pair(255,tran));
	tran.clear();


	// state 256
	tran.insert(make_pair("-", TableItem(2,75)));
	tran.insert(make_pair("(", TableItem(2,75)));
	tran.insert(make_pair("id", TableItem(2,75)));
	tran.insert(make_pair("num", TableItem(2,75)));
	tran.insert(make_pair("load_mem", TableItem(2,75)));
	_parseTable.insert(make_pair(256,tran));
	tran.clear();


	// state 257
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,353)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(257,tran));
	tran.clear();


	// state 258
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,354)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(258,tran));
	tran.clear();


	// state 259
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,355)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(259,tran));
	tran.clear();


	// state 260
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,356)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(260,tran));
	tran.clear();


	// state 261
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,357)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(261,tran));
	tran.clear();


	// state 262
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,358)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(262,tran));
	tran.clear();


	// state 263
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("expr", TableItem(3,359)));
	tran.insert(make_pair("(", TableItem(1,246)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	_parseTable.insert(make_pair(263,tran));
	tran.clear();


	// state 264
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,361)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(264,tran));
	tran.clear();


	// state 265
	tran.insert(make_pair("||", TableItem(2,66)));
	tran.insert(make_pair("&&", TableItem(2,66)));
	tran.insert(make_pair("|", TableItem(1,248)));
	tran.insert(make_pair("^", TableItem(1,249)));
	tran.insert(make_pair("&", TableItem(1,250)));
	tran.insert(make_pair("==", TableItem(1,251)));
	tran.insert(make_pair("!=", TableItem(1,252)));
	tran.insert(make_pair("<", TableItem(1,253)));
	tran.insert(make_pair(">", TableItem(1,254)));
	tran.insert(make_pair("<=", TableItem(1,255)));
	tran.insert(make_pair(">=", TableItem(1,256)));
	tran.insert(make_pair("<<", TableItem(1,257)));
	tran.insert(make_pair(">>", TableItem(1,258)));
	tran.insert(make_pair("+", TableItem(1,259)));
	tran.insert(make_pair("-", TableItem(1,260)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,66)));
	tran.insert(make_pair("rel", TableItem(3,264)));
	_parseTable.insert(make_pair(265,tran));
	tran.clear();


	// state 266
	tran.insert(make_pair("||", TableItem(1,270)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(1,367)));
	_parseTable.insert(make_pair(266,tran));
	tran.clear();


	// state 267
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,124)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair(",", TableItem(2,56)));
	tran.insert(make_pair(")", TableItem(2,56)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("arg_list", TableItem(3,368)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(267,tran));
	tran.clear();


	// state 268
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,369)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(268,tran));
	tran.clear();


	// state 269
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,370)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(269,tran));
	tran.clear();


	// state 270
	tran.insert(make_pair("-", TableItem(2,69)));
	tran.insert(make_pair("!", TableItem(2,69)));
	tran.insert(make_pair("M", TableItem(3,371)));
	tran.insert(make_pair("(", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("num", TableItem(2,69)));
	tran.insert(make_pair("load_mem", TableItem(2,69)));
	tran.insert(make_pair("true", TableItem(2,69)));
	tran.insert(make_pair("false", TableItem(2,69)));
	_parseTable.insert(make_pair(270,tran));
	tran.clear();


	// state 271
	tran.insert(make_pair("-", TableItem(2,69)));
	tran.insert(make_pair("!", TableItem(2,69)));
	tran.insert(make_pair("M", TableItem(3,372)));
	tran.insert(make_pair("(", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("num", TableItem(2,69)));
	tran.insert(make_pair("load_mem", TableItem(2,69)));
	tran.insert(make_pair("true", TableItem(2,69)));
	tran.insert(make_pair("false", TableItem(2,69)));
	_parseTable.insert(make_pair(271,tran));
	tran.clear();


	// state 272
	tran.insert(make_pair("M", TableItem(3,373)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(272,tran));
	tran.clear();


	// state 273
	tran.insert(make_pair("||", TableItem(1,270)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(1,374)));
	_parseTable.insert(make_pair(273,tran));
	tran.clear();


	// state 274
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,375)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(274,tran));
	tran.clear();


	// state 275
	tran.insert(make_pair("{", TableItem(2,18)));
	tran.insert(make_pair("}", TableItem(2,18)));
	tran.insert(make_pair(";", TableItem(2,18)));
	tran.insert(make_pair("static", TableItem(2,18)));
	tran.insert(make_pair("return", TableItem(2,18)));
	tran.insert(make_pair("set_mem", TableItem(2,18)));
	tran.insert(make_pair("include", TableItem(2,18)));
	tran.insert(make_pair("id", TableItem(2,18)));
	tran.insert(make_pair("int", TableItem(2,18)));
	tran.insert(make_pair("double", TableItem(2,18)));
	tran.insert(make_pair("void", TableItem(2,18)));
	tran.insert(make_pair("char", TableItem(2,18)));
	tran.insert(make_pair("bool", TableItem(2,18)));
	tran.insert(make_pair("float", TableItem(2,18)));
	tran.insert(make_pair("if", TableItem(2,18)));
	tran.insert(make_pair("while", TableItem(2,18)));
	_parseTable.insert(make_pair(275,tran));
	tran.clear();


	// state 276
	tran.insert(make_pair("{", TableItem(2,17)));
	tran.insert(make_pair("}", TableItem(2,17)));
	tran.insert(make_pair(";", TableItem(2,17)));
	tran.insert(make_pair("static", TableItem(2,17)));
	tran.insert(make_pair("return", TableItem(2,17)));
	tran.insert(make_pair("set_mem", TableItem(2,17)));
	tran.insert(make_pair("include", TableItem(2,17)));
	tran.insert(make_pair("id", TableItem(2,17)));
	tran.insert(make_pair("int", TableItem(2,17)));
	tran.insert(make_pair("double", TableItem(2,17)));
	tran.insert(make_pair("void", TableItem(2,17)));
	tran.insert(make_pair("char", TableItem(2,17)));
	tran.insert(make_pair("bool", TableItem(2,17)));
	tran.insert(make_pair("float", TableItem(2,17)));
	tran.insert(make_pair("if", TableItem(2,17)));
	tran.insert(make_pair("while", TableItem(2,17)));
	_parseTable.insert(make_pair(276,tran));
	tran.clear();


	// state 277
	tran.insert(make_pair("M", TableItem(3,71)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair("}", TableItem(1,376)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(277,tran));
	tran.clear();


	// state 278
	tran.insert(make_pair("{", TableItem(2,20)));
	tran.insert(make_pair("}", TableItem(2,20)));
	tran.insert(make_pair(";", TableItem(2,20)));
	tran.insert(make_pair("static", TableItem(2,20)));
	tran.insert(make_pair("return", TableItem(2,20)));
	tran.insert(make_pair("set_mem", TableItem(2,20)));
	tran.insert(make_pair("include", TableItem(2,20)));
	tran.insert(make_pair("id", TableItem(2,20)));
	tran.insert(make_pair("int", TableItem(2,20)));
	tran.insert(make_pair("double", TableItem(2,20)));
	tran.insert(make_pair("void", TableItem(2,20)));
	tran.insert(make_pair("char", TableItem(2,20)));
	tran.insert(make_pair("bool", TableItem(2,20)));
	tran.insert(make_pair("float", TableItem(2,20)));
	tran.insert(make_pair("if", TableItem(2,20)));
	tran.insert(make_pair("while", TableItem(2,20)));
	_parseTable.insert(make_pair(278,tran));
	tran.clear();


	// state 279
	tran.insert(make_pair(",", TableItem(1,316)));
	tran.insert(make_pair(")", TableItem(1,377)));
	_parseTable.insert(make_pair(279,tran));
	tran.clear();


	// state 280
	tran.insert(make_pair("M", TableItem(3,378)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(280,tran));
	tran.clear();


	// state 281
	tran.insert(make_pair("||", TableItem(1,270)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(1,379)));
	_parseTable.insert(make_pair(281,tran));
	tran.clear();


	// state 282
	tran.insert(make_pair("|", TableItem(2,43)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(2,43)));
	_parseTable.insert(make_pair(282,tran));
	tran.clear();


	// state 283
	tran.insert(make_pair("|", TableItem(2,44)));
	tran.insert(make_pair("^", TableItem(2,44)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(2,44)));
	_parseTable.insert(make_pair(283,tran));
	tran.clear();


	// state 284
	tran.insert(make_pair("|", TableItem(2,42)));
	tran.insert(make_pair("^", TableItem(2,42)));
	tran.insert(make_pair("&", TableItem(2,42)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(2,42)));
	_parseTable.insert(make_pair(284,tran));
	tran.clear();


	// state 285
	tran.insert(make_pair("|", TableItem(2,46)));
	tran.insert(make_pair("^", TableItem(2,46)));
	tran.insert(make_pair("&", TableItem(2,46)));
	tran.insert(make_pair("<<", TableItem(2,46)));
	tran.insert(make_pair(">>", TableItem(2,46)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(2,46)));
	_parseTable.insert(make_pair(285,tran));
	tran.clear();


	// state 286
	tran.insert(make_pair("|", TableItem(2,45)));
	tran.insert(make_pair("^", TableItem(2,45)));
	tran.insert(make_pair("&", TableItem(2,45)));
	tran.insert(make_pair("<<", TableItem(2,45)));
	tran.insert(make_pair(">>", TableItem(2,45)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(2,45)));
	_parseTable.insert(make_pair(286,tran));
	tran.clear();


	// state 287
	tran.insert(make_pair("|", TableItem(2,37)));
	tran.insert(make_pair("^", TableItem(2,37)));
	tran.insert(make_pair("&", TableItem(2,37)));
	tran.insert(make_pair("<<", TableItem(2,37)));
	tran.insert(make_pair(">>", TableItem(2,37)));
	tran.insert(make_pair("+", TableItem(2,37)));
	tran.insert(make_pair("-", TableItem(2,37)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(2,37)));
	_parseTable.insert(make_pair(287,tran));
	tran.clear();


	// state 288
	tran.insert(make_pair("|", TableItem(2,38)));
	tran.insert(make_pair("^", TableItem(2,38)));
	tran.insert(make_pair("&", TableItem(2,38)));
	tran.insert(make_pair("<<", TableItem(2,38)));
	tran.insert(make_pair(">>", TableItem(2,38)));
	tran.insert(make_pair("+", TableItem(2,38)));
	tran.insert(make_pair("-", TableItem(2,38)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(2,38)));
	_parseTable.insert(make_pair(288,tran));
	tran.clear();


	// state 289
	tran.insert(make_pair("|", TableItem(2,39)));
	tran.insert(make_pair("^", TableItem(2,39)));
	tran.insert(make_pair("&", TableItem(2,39)));
	tran.insert(make_pair("<<", TableItem(2,39)));
	tran.insert(make_pair(">>", TableItem(2,39)));
	tran.insert(make_pair("+", TableItem(2,39)));
	tran.insert(make_pair("-", TableItem(2,39)));
	tran.insert(make_pair("*", TableItem(2,39)));
	tran.insert(make_pair("/", TableItem(2,39)));
	tran.insert(make_pair("%", TableItem(2,39)));
	tran.insert(make_pair(")", TableItem(2,39)));
	_parseTable.insert(make_pair(289,tran));
	tran.clear();


	// state 290
	tran.insert(make_pair("|", TableItem(2,40)));
	tran.insert(make_pair("^", TableItem(2,40)));
	tran.insert(make_pair("&", TableItem(2,40)));
	tran.insert(make_pair("<<", TableItem(2,40)));
	tran.insert(make_pair(">>", TableItem(2,40)));
	tran.insert(make_pair("+", TableItem(2,40)));
	tran.insert(make_pair("-", TableItem(2,40)));
	tran.insert(make_pair("*", TableItem(2,40)));
	tran.insert(make_pair("/", TableItem(2,40)));
	tran.insert(make_pair("%", TableItem(2,40)));
	tran.insert(make_pair(")", TableItem(2,40)));
	_parseTable.insert(make_pair(290,tran));
	tran.clear();


	// state 291
	tran.insert(make_pair("|", TableItem(2,41)));
	tran.insert(make_pair("^", TableItem(2,41)));
	tran.insert(make_pair("&", TableItem(2,41)));
	tran.insert(make_pair("<<", TableItem(2,41)));
	tran.insert(make_pair(">>", TableItem(2,41)));
	tran.insert(make_pair("+", TableItem(2,41)));
	tran.insert(make_pair("-", TableItem(2,41)));
	tran.insert(make_pair("*", TableItem(2,41)));
	tran.insert(make_pair("/", TableItem(2,41)));
	tran.insert(make_pair("%", TableItem(2,41)));
	tran.insert(make_pair(")", TableItem(2,41)));
	_parseTable.insert(make_pair(291,tran));
	tran.clear();


	// state 292
	tran.insert(make_pair("|", TableItem(2,47)));
	tran.insert(make_pair("^", TableItem(2,47)));
	tran.insert(make_pair("&", TableItem(2,47)));
	tran.insert(make_pair("<<", TableItem(2,47)));
	tran.insert(make_pair(">>", TableItem(2,47)));
	tran.insert(make_pair("+", TableItem(2,47)));
	tran.insert(make_pair("-", TableItem(2,47)));
	tran.insert(make_pair("*", TableItem(2,47)));
	tran.insert(make_pair("/", TableItem(2,47)));
	tran.insert(make_pair("%", TableItem(2,47)));
	tran.insert(make_pair(")", TableItem(2,47)));
	_parseTable.insert(make_pair(292,tran));
	tran.clear();


	// state 293
	tran.insert(make_pair(",", TableItem(1,226)));
	tran.insert(make_pair(")", TableItem(1,380)));
	_parseTable.insert(make_pair(293,tran));
	tran.clear();


	// state 294
	tran.insert(make_pair("|", TableItem(1,230)));
	tran.insert(make_pair("^", TableItem(1,231)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(1,381)));
	_parseTable.insert(make_pair(294,tran));
	tran.clear();


	// state 295
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,382)));
	_parseTable.insert(make_pair(295,tran));
	tran.clear();


	// state 296
	tran.insert(make_pair("|", TableItem(2,49)));
	tran.insert(make_pair("^", TableItem(2,49)));
	tran.insert(make_pair("&", TableItem(2,49)));
	tran.insert(make_pair("<<", TableItem(2,49)));
	tran.insert(make_pair(">>", TableItem(2,49)));
	tran.insert(make_pair("+", TableItem(2,49)));
	tran.insert(make_pair("-", TableItem(2,49)));
	tran.insert(make_pair("*", TableItem(2,49)));
	tran.insert(make_pair("/", TableItem(2,49)));
	tran.insert(make_pair("%", TableItem(2,49)));
	tran.insert(make_pair(";", TableItem(2,49)));
	_parseTable.insert(make_pair(296,tran));
	tran.clear();


	// state 297
	tran.insert(make_pair("|", TableItem(2,52)));
	tran.insert(make_pair("^", TableItem(2,52)));
	tran.insert(make_pair("&", TableItem(2,52)));
	tran.insert(make_pair("<<", TableItem(2,52)));
	tran.insert(make_pair(">>", TableItem(2,52)));
	tran.insert(make_pair("+", TableItem(2,52)));
	tran.insert(make_pair("-", TableItem(2,52)));
	tran.insert(make_pair("*", TableItem(2,52)));
	tran.insert(make_pair("/", TableItem(2,52)));
	tran.insert(make_pair("%", TableItem(2,52)));
	tran.insert(make_pair(";", TableItem(2,52)));
	_parseTable.insert(make_pair(297,tran));
	tran.clear();


	// state 298
	tran.insert(make_pair("|", TableItem(2,53)));
	tran.insert(make_pair("^", TableItem(2,53)));
	tran.insert(make_pair("&", TableItem(2,53)));
	tran.insert(make_pair("<<", TableItem(2,53)));
	tran.insert(make_pair(">>", TableItem(2,53)));
	tran.insert(make_pair("+", TableItem(2,53)));
	tran.insert(make_pair("-", TableItem(2,53)));
	tran.insert(make_pair("*", TableItem(2,53)));
	tran.insert(make_pair("/", TableItem(2,53)));
	tran.insert(make_pair("%", TableItem(2,53)));
	tran.insert(make_pair(";", TableItem(2,53)));
	_parseTable.insert(make_pair(298,tran));
	tran.clear();


	// state 299
	tran.insert(make_pair("|", TableItem(2,43)));
	tran.insert(make_pair("^", TableItem(1,189)));
	tran.insert(make_pair("&", TableItem(1,190)));
	tran.insert(make_pair("<<", TableItem(1,191)));
	tran.insert(make_pair(">>", TableItem(1,192)));
	tran.insert(make_pair("+", TableItem(1,193)));
	tran.insert(make_pair("-", TableItem(1,194)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(2,43)));
	_parseTable.insert(make_pair(299,tran));
	tran.clear();


	// state 300
	tran.insert(make_pair("|", TableItem(2,44)));
	tran.insert(make_pair("^", TableItem(2,44)));
	tran.insert(make_pair("&", TableItem(1,190)));
	tran.insert(make_pair("<<", TableItem(1,191)));
	tran.insert(make_pair(">>", TableItem(1,192)));
	tran.insert(make_pair("+", TableItem(1,193)));
	tran.insert(make_pair("-", TableItem(1,194)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(2,44)));
	_parseTable.insert(make_pair(300,tran));
	tran.clear();


	// state 301
	tran.insert(make_pair("|", TableItem(2,42)));
	tran.insert(make_pair("^", TableItem(2,42)));
	tran.insert(make_pair("&", TableItem(2,42)));
	tran.insert(make_pair("<<", TableItem(1,191)));
	tran.insert(make_pair(">>", TableItem(1,192)));
	tran.insert(make_pair("+", TableItem(1,193)));
	tran.insert(make_pair("-", TableItem(1,194)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(2,42)));
	_parseTable.insert(make_pair(301,tran));
	tran.clear();


	// state 302
	tran.insert(make_pair("|", TableItem(2,46)));
	tran.insert(make_pair("^", TableItem(2,46)));
	tran.insert(make_pair("&", TableItem(2,46)));
	tran.insert(make_pair("<<", TableItem(2,46)));
	tran.insert(make_pair(">>", TableItem(2,46)));
	tran.insert(make_pair("+", TableItem(1,193)));
	tran.insert(make_pair("-", TableItem(1,194)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(2,46)));
	_parseTable.insert(make_pair(302,tran));
	tran.clear();


	// state 303
	tran.insert(make_pair("|", TableItem(2,45)));
	tran.insert(make_pair("^", TableItem(2,45)));
	tran.insert(make_pair("&", TableItem(2,45)));
	tran.insert(make_pair("<<", TableItem(2,45)));
	tran.insert(make_pair(">>", TableItem(2,45)));
	tran.insert(make_pair("+", TableItem(1,193)));
	tran.insert(make_pair("-", TableItem(1,194)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(2,45)));
	_parseTable.insert(make_pair(303,tran));
	tran.clear();


	// state 304
	tran.insert(make_pair("|", TableItem(2,37)));
	tran.insert(make_pair("^", TableItem(2,37)));
	tran.insert(make_pair("&", TableItem(2,37)));
	tran.insert(make_pair("<<", TableItem(2,37)));
	tran.insert(make_pair(">>", TableItem(2,37)));
	tran.insert(make_pair("+", TableItem(2,37)));
	tran.insert(make_pair("-", TableItem(2,37)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(2,37)));
	_parseTable.insert(make_pair(304,tran));
	tran.clear();


	// state 305
	tran.insert(make_pair("|", TableItem(2,38)));
	tran.insert(make_pair("^", TableItem(2,38)));
	tran.insert(make_pair("&", TableItem(2,38)));
	tran.insert(make_pair("<<", TableItem(2,38)));
	tran.insert(make_pair(">>", TableItem(2,38)));
	tran.insert(make_pair("+", TableItem(2,38)));
	tran.insert(make_pair("-", TableItem(2,38)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(2,38)));
	_parseTable.insert(make_pair(305,tran));
	tran.clear();


	// state 306
	tran.insert(make_pair("|", TableItem(2,39)));
	tran.insert(make_pair("^", TableItem(2,39)));
	tran.insert(make_pair("&", TableItem(2,39)));
	tran.insert(make_pair("<<", TableItem(2,39)));
	tran.insert(make_pair(">>", TableItem(2,39)));
	tran.insert(make_pair("+", TableItem(2,39)));
	tran.insert(make_pair("-", TableItem(2,39)));
	tran.insert(make_pair("*", TableItem(2,39)));
	tran.insert(make_pair("/", TableItem(2,39)));
	tran.insert(make_pair("%", TableItem(2,39)));
	tran.insert(make_pair(",", TableItem(2,39)));
	_parseTable.insert(make_pair(306,tran));
	tran.clear();


	// state 307
	tran.insert(make_pair("|", TableItem(2,40)));
	tran.insert(make_pair("^", TableItem(2,40)));
	tran.insert(make_pair("&", TableItem(2,40)));
	tran.insert(make_pair("<<", TableItem(2,40)));
	tran.insert(make_pair(">>", TableItem(2,40)));
	tran.insert(make_pair("+", TableItem(2,40)));
	tran.insert(make_pair("-", TableItem(2,40)));
	tran.insert(make_pair("*", TableItem(2,40)));
	tran.insert(make_pair("/", TableItem(2,40)));
	tran.insert(make_pair("%", TableItem(2,40)));
	tran.insert(make_pair(",", TableItem(2,40)));
	_parseTable.insert(make_pair(307,tran));
	tran.clear();


	// state 308
	tran.insert(make_pair("|", TableItem(2,41)));
	tran.insert(make_pair("^", TableItem(2,41)));
	tran.insert(make_pair("&", TableItem(2,41)));
	tran.insert(make_pair("<<", TableItem(2,41)));
	tran.insert(make_pair(">>", TableItem(2,41)));
	tran.insert(make_pair("+", TableItem(2,41)));
	tran.insert(make_pair("-", TableItem(2,41)));
	tran.insert(make_pair("*", TableItem(2,41)));
	tran.insert(make_pair("/", TableItem(2,41)));
	tran.insert(make_pair("%", TableItem(2,41)));
	tran.insert(make_pair(",", TableItem(2,41)));
	_parseTable.insert(make_pair(308,tran));
	tran.clear();


	// state 309
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,383)));
	_parseTable.insert(make_pair(309,tran));
	tran.clear();


	// state 310
	tran.insert(make_pair("|", TableItem(2,47)));
	tran.insert(make_pair("^", TableItem(2,47)));
	tran.insert(make_pair("&", TableItem(2,47)));
	tran.insert(make_pair("<<", TableItem(2,47)));
	tran.insert(make_pair(">>", TableItem(2,47)));
	tran.insert(make_pair("+", TableItem(2,47)));
	tran.insert(make_pair("-", TableItem(2,47)));
	tran.insert(make_pair("*", TableItem(2,47)));
	tran.insert(make_pair("/", TableItem(2,47)));
	tran.insert(make_pair("%", TableItem(2,47)));
	tran.insert(make_pair(",", TableItem(2,47)));
	_parseTable.insert(make_pair(310,tran));
	tran.clear();


	// state 311
	tran.insert(make_pair(",", TableItem(1,226)));
	tran.insert(make_pair(")", TableItem(1,384)));
	_parseTable.insert(make_pair(311,tran));
	tran.clear();


	// state 312
	tran.insert(make_pair("|", TableItem(1,230)));
	tran.insert(make_pair("^", TableItem(1,231)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(1,385)));
	_parseTable.insert(make_pair(312,tran));
	tran.clear();


	// state 313
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,386)));
	_parseTable.insert(make_pair(313,tran));
	tran.clear();


	// state 314
	tran.insert(make_pair("{", TableItem(2,19)));
	tran.insert(make_pair(";", TableItem(2,19)));
	tran.insert(make_pair("static", TableItem(2,19)));
	tran.insert(make_pair("return", TableItem(2,19)));
	tran.insert(make_pair("set_mem", TableItem(2,19)));
	tran.insert(make_pair("include", TableItem(2,19)));
	tran.insert(make_pair("id", TableItem(2,19)));
	tran.insert(make_pair("int", TableItem(2,19)));
	tran.insert(make_pair("double", TableItem(2,19)));
	tran.insert(make_pair("void", TableItem(2,19)));
	tran.insert(make_pair("char", TableItem(2,19)));
	tran.insert(make_pair("bool", TableItem(2,19)));
	tran.insert(make_pair("float", TableItem(2,19)));
	tran.insert(make_pair("if", TableItem(2,19)));
	tran.insert(make_pair("while", TableItem(2,19)));
	tran.insert(make_pair("$", TableItem(2,19)));
	_parseTable.insert(make_pair(314,tran));
	tran.clear();


	// state 315
	tran.insert(make_pair(",", TableItem(2,24)));
	tran.insert(make_pair(")", TableItem(2,24)));
	tran.insert(make_pair("[", TableItem(1,387)));
	_parseTable.insert(make_pair(315,tran));
	tran.clear();


	// state 316
	tran.insert(make_pair("type_spec", TableItem(3,208)));
	tran.insert(make_pair("param", TableItem(3,388)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	_parseTable.insert(make_pair(316,tran));
	tran.clear();


	// state 317
	tran.insert(make_pair("{", TableItem(2,21)));
	tran.insert(make_pair(";", TableItem(2,21)));
	tran.insert(make_pair("static", TableItem(2,21)));
	tran.insert(make_pair("return", TableItem(2,21)));
	tran.insert(make_pair("set_mem", TableItem(2,21)));
	tran.insert(make_pair("include", TableItem(2,21)));
	tran.insert(make_pair("id", TableItem(2,21)));
	tran.insert(make_pair("int", TableItem(2,21)));
	tran.insert(make_pair("double", TableItem(2,21)));
	tran.insert(make_pair("void", TableItem(2,21)));
	tran.insert(make_pair("char", TableItem(2,21)));
	tran.insert(make_pair("bool", TableItem(2,21)));
	tran.insert(make_pair("float", TableItem(2,21)));
	tran.insert(make_pair("if", TableItem(2,21)));
	tran.insert(make_pair("while", TableItem(2,21)));
	tran.insert(make_pair("$", TableItem(2,21)));
	_parseTable.insert(make_pair(317,tran));
	tran.clear();


	// state 318
	tran.insert(make_pair(";", TableItem(2,28)));
	_parseTable.insert(make_pair(318,tran));
	tran.clear();


	// state 319
	tran.insert(make_pair("|", TableItem(2,43)));
	tran.insert(make_pair("^", TableItem(1,214)));
	tran.insert(make_pair("&", TableItem(1,215)));
	tran.insert(make_pair("<<", TableItem(1,216)));
	tran.insert(make_pair(">>", TableItem(1,217)));
	tran.insert(make_pair("+", TableItem(1,218)));
	tran.insert(make_pair("-", TableItem(1,219)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,43)));
	tran.insert(make_pair(")", TableItem(2,43)));
	_parseTable.insert(make_pair(319,tran));
	tran.clear();


	// state 320
	tran.insert(make_pair("|", TableItem(2,44)));
	tran.insert(make_pair("^", TableItem(2,44)));
	tran.insert(make_pair("&", TableItem(1,215)));
	tran.insert(make_pair("<<", TableItem(1,216)));
	tran.insert(make_pair(">>", TableItem(1,217)));
	tran.insert(make_pair("+", TableItem(1,218)));
	tran.insert(make_pair("-", TableItem(1,219)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,44)));
	tran.insert(make_pair(")", TableItem(2,44)));
	_parseTable.insert(make_pair(320,tran));
	tran.clear();


	// state 321
	tran.insert(make_pair("|", TableItem(2,42)));
	tran.insert(make_pair("^", TableItem(2,42)));
	tran.insert(make_pair("&", TableItem(2,42)));
	tran.insert(make_pair("<<", TableItem(1,216)));
	tran.insert(make_pair(">>", TableItem(1,217)));
	tran.insert(make_pair("+", TableItem(1,218)));
	tran.insert(make_pair("-", TableItem(1,219)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,42)));
	tran.insert(make_pair(")", TableItem(2,42)));
	_parseTable.insert(make_pair(321,tran));
	tran.clear();


	// state 322
	tran.insert(make_pair("|", TableItem(2,46)));
	tran.insert(make_pair("^", TableItem(2,46)));
	tran.insert(make_pair("&", TableItem(2,46)));
	tran.insert(make_pair("<<", TableItem(2,46)));
	tran.insert(make_pair(">>", TableItem(2,46)));
	tran.insert(make_pair("+", TableItem(1,218)));
	tran.insert(make_pair("-", TableItem(1,219)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,46)));
	tran.insert(make_pair(")", TableItem(2,46)));
	_parseTable.insert(make_pair(322,tran));
	tran.clear();


	// state 323
	tran.insert(make_pair("|", TableItem(2,45)));
	tran.insert(make_pair("^", TableItem(2,45)));
	tran.insert(make_pair("&", TableItem(2,45)));
	tran.insert(make_pair("<<", TableItem(2,45)));
	tran.insert(make_pair(">>", TableItem(2,45)));
	tran.insert(make_pair("+", TableItem(1,218)));
	tran.insert(make_pair("-", TableItem(1,219)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,45)));
	tran.insert(make_pair(")", TableItem(2,45)));
	_parseTable.insert(make_pair(323,tran));
	tran.clear();


	// state 324
	tran.insert(make_pair("|", TableItem(2,37)));
	tran.insert(make_pair("^", TableItem(2,37)));
	tran.insert(make_pair("&", TableItem(2,37)));
	tran.insert(make_pair("<<", TableItem(2,37)));
	tran.insert(make_pair(">>", TableItem(2,37)));
	tran.insert(make_pair("+", TableItem(2,37)));
	tran.insert(make_pair("-", TableItem(2,37)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,37)));
	tran.insert(make_pair(")", TableItem(2,37)));
	_parseTable.insert(make_pair(324,tran));
	tran.clear();


	// state 325
	tran.insert(make_pair("|", TableItem(2,38)));
	tran.insert(make_pair("^", TableItem(2,38)));
	tran.insert(make_pair("&", TableItem(2,38)));
	tran.insert(make_pair("<<", TableItem(2,38)));
	tran.insert(make_pair(">>", TableItem(2,38)));
	tran.insert(make_pair("+", TableItem(2,38)));
	tran.insert(make_pair("-", TableItem(2,38)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,38)));
	tran.insert(make_pair(")", TableItem(2,38)));
	_parseTable.insert(make_pair(325,tran));
	tran.clear();


	// state 326
	tran.insert(make_pair("|", TableItem(2,39)));
	tran.insert(make_pair("^", TableItem(2,39)));
	tran.insert(make_pair("&", TableItem(2,39)));
	tran.insert(make_pair("<<", TableItem(2,39)));
	tran.insert(make_pair(">>", TableItem(2,39)));
	tran.insert(make_pair("+", TableItem(2,39)));
	tran.insert(make_pair("-", TableItem(2,39)));
	tran.insert(make_pair("*", TableItem(2,39)));
	tran.insert(make_pair("/", TableItem(2,39)));
	tran.insert(make_pair("%", TableItem(2,39)));
	tran.insert(make_pair(",", TableItem(2,39)));
	tran.insert(make_pair(")", TableItem(2,39)));
	_parseTable.insert(make_pair(326,tran));
	tran.clear();


	// state 327
	tran.insert(make_pair("|", TableItem(2,40)));
	tran.insert(make_pair("^", TableItem(2,40)));
	tran.insert(make_pair("&", TableItem(2,40)));
	tran.insert(make_pair("<<", TableItem(2,40)));
	tran.insert(make_pair(">>", TableItem(2,40)));
	tran.insert(make_pair("+", TableItem(2,40)));
	tran.insert(make_pair("-", TableItem(2,40)));
	tran.insert(make_pair("*", TableItem(2,40)));
	tran.insert(make_pair("/", TableItem(2,40)));
	tran.insert(make_pair("%", TableItem(2,40)));
	tran.insert(make_pair(",", TableItem(2,40)));
	tran.insert(make_pair(")", TableItem(2,40)));
	_parseTable.insert(make_pair(327,tran));
	tran.clear();


	// state 328
	tran.insert(make_pair("|", TableItem(2,41)));
	tran.insert(make_pair("^", TableItem(2,41)));
	tran.insert(make_pair("&", TableItem(2,41)));
	tran.insert(make_pair("<<", TableItem(2,41)));
	tran.insert(make_pair(">>", TableItem(2,41)));
	tran.insert(make_pair("+", TableItem(2,41)));
	tran.insert(make_pair("-", TableItem(2,41)));
	tran.insert(make_pair("*", TableItem(2,41)));
	tran.insert(make_pair("/", TableItem(2,41)));
	tran.insert(make_pair("%", TableItem(2,41)));
	tran.insert(make_pair(",", TableItem(2,41)));
	tran.insert(make_pair(")", TableItem(2,41)));
	_parseTable.insert(make_pair(328,tran));
	tran.clear();


	// state 329
	tran.insert(make_pair("|", TableItem(2,47)));
	tran.insert(make_pair("^", TableItem(2,47)));
	tran.insert(make_pair("&", TableItem(2,47)));
	tran.insert(make_pair("<<", TableItem(2,47)));
	tran.insert(make_pair(">>", TableItem(2,47)));
	tran.insert(make_pair("+", TableItem(2,47)));
	tran.insert(make_pair("-", TableItem(2,47)));
	tran.insert(make_pair("*", TableItem(2,47)));
	tran.insert(make_pair("/", TableItem(2,47)));
	tran.insert(make_pair("%", TableItem(2,47)));
	tran.insert(make_pair(",", TableItem(2,47)));
	tran.insert(make_pair(")", TableItem(2,47)));
	_parseTable.insert(make_pair(329,tran));
	tran.clear();


	// state 330
	tran.insert(make_pair(",", TableItem(1,226)));
	tran.insert(make_pair(")", TableItem(1,389)));
	_parseTable.insert(make_pair(330,tran));
	tran.clear();


	// state 331
	tran.insert(make_pair("|", TableItem(1,230)));
	tran.insert(make_pair("^", TableItem(1,231)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(1,390)));
	_parseTable.insert(make_pair(331,tran));
	tran.clear();


	// state 332
	tran.insert(make_pair("|", TableItem(1,213)));
	tran.insert(make_pair("^", TableItem(1,214)));
	tran.insert(make_pair("&", TableItem(1,215)));
	tran.insert(make_pair("<<", TableItem(1,216)));
	tran.insert(make_pair(">>", TableItem(1,217)));
	tran.insert(make_pair("+", TableItem(1,218)));
	tran.insert(make_pair("-", TableItem(1,219)));
	tran.insert(make_pair("*", TableItem(1,220)));
	tran.insert(make_pair("/", TableItem(1,221)));
	tran.insert(make_pair("%", TableItem(1,222)));
	tran.insert(make_pair(",", TableItem(2,54)));
	tran.insert(make_pair(")", TableItem(2,54)));
	_parseTable.insert(make_pair(332,tran));
	tran.clear();


	// state 333
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,391)));
	_parseTable.insert(make_pair(333,tran));
	tran.clear();


	// state 334
	tran.insert(make_pair("|", TableItem(2,43)));
	tran.insert(make_pair("^", TableItem(1,231)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(2,43)));
	_parseTable.insert(make_pair(334,tran));
	tran.clear();


	// state 335
	tran.insert(make_pair("|", TableItem(2,44)));
	tran.insert(make_pair("^", TableItem(2,44)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(2,44)));
	_parseTable.insert(make_pair(335,tran));
	tran.clear();


	// state 336
	tran.insert(make_pair("|", TableItem(2,42)));
	tran.insert(make_pair("^", TableItem(2,42)));
	tran.insert(make_pair("&", TableItem(2,42)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(2,42)));
	_parseTable.insert(make_pair(336,tran));
	tran.clear();


	// state 337
	tran.insert(make_pair("|", TableItem(2,46)));
	tran.insert(make_pair("^", TableItem(2,46)));
	tran.insert(make_pair("&", TableItem(2,46)));
	tran.insert(make_pair("<<", TableItem(2,46)));
	tran.insert(make_pair(">>", TableItem(2,46)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(2,46)));
	_parseTable.insert(make_pair(337,tran));
	tran.clear();


	// state 338
	tran.insert(make_pair("|", TableItem(2,45)));
	tran.insert(make_pair("^", TableItem(2,45)));
	tran.insert(make_pair("&", TableItem(2,45)));
	tran.insert(make_pair("<<", TableItem(2,45)));
	tran.insert(make_pair(">>", TableItem(2,45)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(2,45)));
	_parseTable.insert(make_pair(338,tran));
	tran.clear();


	// state 339
	tran.insert(make_pair("|", TableItem(2,37)));
	tran.insert(make_pair("^", TableItem(2,37)));
	tran.insert(make_pair("&", TableItem(2,37)));
	tran.insert(make_pair("<<", TableItem(2,37)));
	tran.insert(make_pair(">>", TableItem(2,37)));
	tran.insert(make_pair("+", TableItem(2,37)));
	tran.insert(make_pair("-", TableItem(2,37)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(2,37)));
	_parseTable.insert(make_pair(339,tran));
	tran.clear();


	// state 340
	tran.insert(make_pair("|", TableItem(2,38)));
	tran.insert(make_pair("^", TableItem(2,38)));
	tran.insert(make_pair("&", TableItem(2,38)));
	tran.insert(make_pair("<<", TableItem(2,38)));
	tran.insert(make_pair(">>", TableItem(2,38)));
	tran.insert(make_pair("+", TableItem(2,38)));
	tran.insert(make_pair("-", TableItem(2,38)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(2,38)));
	_parseTable.insert(make_pair(340,tran));
	tran.clear();


	// state 341
	tran.insert(make_pair("|", TableItem(2,39)));
	tran.insert(make_pair("^", TableItem(2,39)));
	tran.insert(make_pair("&", TableItem(2,39)));
	tran.insert(make_pair("<<", TableItem(2,39)));
	tran.insert(make_pair(">>", TableItem(2,39)));
	tran.insert(make_pair("+", TableItem(2,39)));
	tran.insert(make_pair("-", TableItem(2,39)));
	tran.insert(make_pair("*", TableItem(2,39)));
	tran.insert(make_pair("/", TableItem(2,39)));
	tran.insert(make_pair("%", TableItem(2,39)));
	tran.insert(make_pair("]", TableItem(2,39)));
	_parseTable.insert(make_pair(341,tran));
	tran.clear();


	// state 342
	tran.insert(make_pair("|", TableItem(2,40)));
	tran.insert(make_pair("^", TableItem(2,40)));
	tran.insert(make_pair("&", TableItem(2,40)));
	tran.insert(make_pair("<<", TableItem(2,40)));
	tran.insert(make_pair(">>", TableItem(2,40)));
	tran.insert(make_pair("+", TableItem(2,40)));
	tran.insert(make_pair("-", TableItem(2,40)));
	tran.insert(make_pair("*", TableItem(2,40)));
	tran.insert(make_pair("/", TableItem(2,40)));
	tran.insert(make_pair("%", TableItem(2,40)));
	tran.insert(make_pair("]", TableItem(2,40)));
	_parseTable.insert(make_pair(342,tran));
	tran.clear();


	// state 343
	tran.insert(make_pair("|", TableItem(2,41)));
	tran.insert(make_pair("^", TableItem(2,41)));
	tran.insert(make_pair("&", TableItem(2,41)));
	tran.insert(make_pair("<<", TableItem(2,41)));
	tran.insert(make_pair(">>", TableItem(2,41)));
	tran.insert(make_pair("+", TableItem(2,41)));
	tran.insert(make_pair("-", TableItem(2,41)));
	tran.insert(make_pair("*", TableItem(2,41)));
	tran.insert(make_pair("/", TableItem(2,41)));
	tran.insert(make_pair("%", TableItem(2,41)));
	tran.insert(make_pair("]", TableItem(2,41)));
	_parseTable.insert(make_pair(343,tran));
	tran.clear();


	// state 344
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair("expr", TableItem(3,392)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(344,tran));
	tran.clear();


	// state 345
	tran.insert(make_pair("|", TableItem(2,47)));
	tran.insert(make_pair("^", TableItem(2,47)));
	tran.insert(make_pair("&", TableItem(2,47)));
	tran.insert(make_pair("<<", TableItem(2,47)));
	tran.insert(make_pair(">>", TableItem(2,47)));
	tran.insert(make_pair("+", TableItem(2,47)));
	tran.insert(make_pair("-", TableItem(2,47)));
	tran.insert(make_pair("*", TableItem(2,47)));
	tran.insert(make_pair("/", TableItem(2,47)));
	tran.insert(make_pair("%", TableItem(2,47)));
	tran.insert(make_pair("]", TableItem(2,47)));
	_parseTable.insert(make_pair(345,tran));
	tran.clear();


	// state 346
	tran.insert(make_pair(",", TableItem(1,226)));
	tran.insert(make_pair(")", TableItem(1,393)));
	_parseTable.insert(make_pair(346,tran));
	tran.clear();


	// state 347
	tran.insert(make_pair("|", TableItem(1,230)));
	tran.insert(make_pair("^", TableItem(1,231)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(1,394)));
	_parseTable.insert(make_pair(347,tran));
	tran.clear();


	// state 348
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,395)));
	_parseTable.insert(make_pair(348,tran));
	tran.clear();


	// state 349
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,366)));
	_parseTable.insert(make_pair(349,tran));
	tran.clear();


	// state 350
	tran.insert(make_pair("||", TableItem(2,43)));
	tran.insert(make_pair("&&", TableItem(2,43)));
	tran.insert(make_pair("|", TableItem(2,43)));
	tran.insert(make_pair("^", TableItem(1,249)));
	tran.insert(make_pair("&", TableItem(1,250)));
	tran.insert(make_pair("==", TableItem(2,43)));
	tran.insert(make_pair("!=", TableItem(2,43)));
	tran.insert(make_pair("<", TableItem(2,43)));
	tran.insert(make_pair(">", TableItem(2,43)));
	tran.insert(make_pair("<=", TableItem(2,43)));
	tran.insert(make_pair(">=", TableItem(2,43)));
	tran.insert(make_pair("<<", TableItem(1,257)));
	tran.insert(make_pair(">>", TableItem(1,258)));
	tran.insert(make_pair("+", TableItem(1,259)));
	tran.insert(make_pair("-", TableItem(1,260)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,43)));
	_parseTable.insert(make_pair(350,tran));
	tran.clear();


	// state 351
	tran.insert(make_pair("||", TableItem(2,44)));
	tran.insert(make_pair("&&", TableItem(2,44)));
	tran.insert(make_pair("|", TableItem(2,44)));
	tran.insert(make_pair("^", TableItem(2,44)));
	tran.insert(make_pair("&", TableItem(1,250)));
	tran.insert(make_pair("==", TableItem(2,44)));
	tran.insert(make_pair("!=", TableItem(2,44)));
	tran.insert(make_pair("<", TableItem(2,44)));
	tran.insert(make_pair(">", TableItem(2,44)));
	tran.insert(make_pair("<=", TableItem(2,44)));
	tran.insert(make_pair(">=", TableItem(2,44)));
	tran.insert(make_pair("<<", TableItem(1,257)));
	tran.insert(make_pair(">>", TableItem(1,258)));
	tran.insert(make_pair("+", TableItem(1,259)));
	tran.insert(make_pair("-", TableItem(1,260)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,44)));
	_parseTable.insert(make_pair(351,tran));
	tran.clear();


	// state 352
	tran.insert(make_pair("||", TableItem(2,42)));
	tran.insert(make_pair("&&", TableItem(2,42)));
	tran.insert(make_pair("|", TableItem(2,42)));
	tran.insert(make_pair("^", TableItem(2,42)));
	tran.insert(make_pair("&", TableItem(2,42)));
	tran.insert(make_pair("==", TableItem(2,42)));
	tran.insert(make_pair("!=", TableItem(2,42)));
	tran.insert(make_pair("<", TableItem(2,42)));
	tran.insert(make_pair(">", TableItem(2,42)));
	tran.insert(make_pair("<=", TableItem(2,42)));
	tran.insert(make_pair(">=", TableItem(2,42)));
	tran.insert(make_pair("<<", TableItem(1,257)));
	tran.insert(make_pair(">>", TableItem(1,258)));
	tran.insert(make_pair("+", TableItem(1,259)));
	tran.insert(make_pair("-", TableItem(1,260)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,42)));
	_parseTable.insert(make_pair(352,tran));
	tran.clear();


	// state 353
	tran.insert(make_pair("||", TableItem(2,46)));
	tran.insert(make_pair("&&", TableItem(2,46)));
	tran.insert(make_pair("|", TableItem(2,46)));
	tran.insert(make_pair("^", TableItem(2,46)));
	tran.insert(make_pair("&", TableItem(2,46)));
	tran.insert(make_pair("==", TableItem(2,46)));
	tran.insert(make_pair("!=", TableItem(2,46)));
	tran.insert(make_pair("<", TableItem(2,46)));
	tran.insert(make_pair(">", TableItem(2,46)));
	tran.insert(make_pair("<=", TableItem(2,46)));
	tran.insert(make_pair(">=", TableItem(2,46)));
	tran.insert(make_pair("<<", TableItem(2,46)));
	tran.insert(make_pair(">>", TableItem(2,46)));
	tran.insert(make_pair("+", TableItem(1,259)));
	tran.insert(make_pair("-", TableItem(1,260)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,46)));
	_parseTable.insert(make_pair(353,tran));
	tran.clear();


	// state 354
	tran.insert(make_pair("||", TableItem(2,45)));
	tran.insert(make_pair("&&", TableItem(2,45)));
	tran.insert(make_pair("|", TableItem(2,45)));
	tran.insert(make_pair("^", TableItem(2,45)));
	tran.insert(make_pair("&", TableItem(2,45)));
	tran.insert(make_pair("==", TableItem(2,45)));
	tran.insert(make_pair("!=", TableItem(2,45)));
	tran.insert(make_pair("<", TableItem(2,45)));
	tran.insert(make_pair(">", TableItem(2,45)));
	tran.insert(make_pair("<=", TableItem(2,45)));
	tran.insert(make_pair(">=", TableItem(2,45)));
	tran.insert(make_pair("<<", TableItem(2,45)));
	tran.insert(make_pair(">>", TableItem(2,45)));
	tran.insert(make_pair("+", TableItem(1,259)));
	tran.insert(make_pair("-", TableItem(1,260)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,45)));
	_parseTable.insert(make_pair(354,tran));
	tran.clear();


	// state 355
	tran.insert(make_pair("||", TableItem(2,37)));
	tran.insert(make_pair("&&", TableItem(2,37)));
	tran.insert(make_pair("|", TableItem(2,37)));
	tran.insert(make_pair("^", TableItem(2,37)));
	tran.insert(make_pair("&", TableItem(2,37)));
	tran.insert(make_pair("==", TableItem(2,37)));
	tran.insert(make_pair("!=", TableItem(2,37)));
	tran.insert(make_pair("<", TableItem(2,37)));
	tran.insert(make_pair(">", TableItem(2,37)));
	tran.insert(make_pair("<=", TableItem(2,37)));
	tran.insert(make_pair(">=", TableItem(2,37)));
	tran.insert(make_pair("<<", TableItem(2,37)));
	tran.insert(make_pair(">>", TableItem(2,37)));
	tran.insert(make_pair("+", TableItem(2,37)));
	tran.insert(make_pair("-", TableItem(2,37)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,37)));
	_parseTable.insert(make_pair(355,tran));
	tran.clear();


	// state 356
	tran.insert(make_pair("||", TableItem(2,38)));
	tran.insert(make_pair("&&", TableItem(2,38)));
	tran.insert(make_pair("|", TableItem(2,38)));
	tran.insert(make_pair("^", TableItem(2,38)));
	tran.insert(make_pair("&", TableItem(2,38)));
	tran.insert(make_pair("==", TableItem(2,38)));
	tran.insert(make_pair("!=", TableItem(2,38)));
	tran.insert(make_pair("<", TableItem(2,38)));
	tran.insert(make_pair(">", TableItem(2,38)));
	tran.insert(make_pair("<=", TableItem(2,38)));
	tran.insert(make_pair(">=", TableItem(2,38)));
	tran.insert(make_pair("<<", TableItem(2,38)));
	tran.insert(make_pair(">>", TableItem(2,38)));
	tran.insert(make_pair("+", TableItem(2,38)));
	tran.insert(make_pair("-", TableItem(2,38)));
	tran.insert(make_pair("*", TableItem(1,261)));
	tran.insert(make_pair("/", TableItem(1,262)));
	tran.insert(make_pair("%", TableItem(1,263)));
	tran.insert(make_pair(")", TableItem(2,38)));
	_parseTable.insert(make_pair(356,tran));
	tran.clear();


	// state 357
	tran.insert(make_pair("||", TableItem(2,39)));
	tran.insert(make_pair("&&", TableItem(2,39)));
	tran.insert(make_pair("|", TableItem(2,39)));
	tran.insert(make_pair("^", TableItem(2,39)));
	tran.insert(make_pair("&", TableItem(2,39)));
	tran.insert(make_pair("==", TableItem(2,39)));
	tran.insert(make_pair("!=", TableItem(2,39)));
	tran.insert(make_pair("<", TableItem(2,39)));
	tran.insert(make_pair(">", TableItem(2,39)));
	tran.insert(make_pair("<=", TableItem(2,39)));
	tran.insert(make_pair(">=", TableItem(2,39)));
	tran.insert(make_pair("<<", TableItem(2,39)));
	tran.insert(make_pair(">>", TableItem(2,39)));
	tran.insert(make_pair("+", TableItem(2,39)));
	tran.insert(make_pair("-", TableItem(2,39)));
	tran.insert(make_pair("*", TableItem(2,39)));
	tran.insert(make_pair("/", TableItem(2,39)));
	tran.insert(make_pair("%", TableItem(2,39)));
	tran.insert(make_pair(")", TableItem(2,39)));
	_parseTable.insert(make_pair(357,tran));
	tran.clear();


	// state 358
	tran.insert(make_pair("||", TableItem(2,40)));
	tran.insert(make_pair("&&", TableItem(2,40)));
	tran.insert(make_pair("|", TableItem(2,40)));
	tran.insert(make_pair("^", TableItem(2,40)));
	tran.insert(make_pair("&", TableItem(2,40)));
	tran.insert(make_pair("==", TableItem(2,40)));
	tran.insert(make_pair("!=", TableItem(2,40)));
	tran.insert(make_pair("<", TableItem(2,40)));
	tran.insert(make_pair(">", TableItem(2,40)));
	tran.insert(make_pair("<=", TableItem(2,40)));
	tran.insert(make_pair(">=", TableItem(2,40)));
	tran.insert(make_pair("<<", TableItem(2,40)));
	tran.insert(make_pair(">>", TableItem(2,40)));
	tran.insert(make_pair("+", TableItem(2,40)));
	tran.insert(make_pair("-", TableItem(2,40)));
	tran.insert(make_pair("*", TableItem(2,40)));
	tran.insert(make_pair("/", TableItem(2,40)));
	tran.insert(make_pair("%", TableItem(2,40)));
	tran.insert(make_pair(")", TableItem(2,40)));
	_parseTable.insert(make_pair(358,tran));
	tran.clear();


	// state 359
	tran.insert(make_pair("||", TableItem(2,41)));
	tran.insert(make_pair("&&", TableItem(2,41)));
	tran.insert(make_pair("|", TableItem(2,41)));
	tran.insert(make_pair("^", TableItem(2,41)));
	tran.insert(make_pair("&", TableItem(2,41)));
	tran.insert(make_pair("==", TableItem(2,41)));
	tran.insert(make_pair("!=", TableItem(2,41)));
	tran.insert(make_pair("<", TableItem(2,41)));
	tran.insert(make_pair(">", TableItem(2,41)));
	tran.insert(make_pair("<=", TableItem(2,41)));
	tran.insert(make_pair(">=", TableItem(2,41)));
	tran.insert(make_pair("<<", TableItem(2,41)));
	tran.insert(make_pair(">>", TableItem(2,41)));
	tran.insert(make_pair("+", TableItem(2,41)));
	tran.insert(make_pair("-", TableItem(2,41)));
	tran.insert(make_pair("*", TableItem(2,41)));
	tran.insert(make_pair("/", TableItem(2,41)));
	tran.insert(make_pair("%", TableItem(2,41)));
	tran.insert(make_pair(")", TableItem(2,41)));
	_parseTable.insert(make_pair(359,tran));
	tran.clear();


	// state 360
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,396)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(360,tran));
	tran.clear();


	// state 361
	tran.insert(make_pair("||", TableItem(2,65)));
	tran.insert(make_pair("&&", TableItem(2,65)));
	tran.insert(make_pair("|", TableItem(1,397)));
	tran.insert(make_pair("^", TableItem(1,398)));
	tran.insert(make_pair("&", TableItem(1,399)));
	tran.insert(make_pair("<<", TableItem(1,400)));
	tran.insert(make_pair(">>", TableItem(1,401)));
	tran.insert(make_pair("+", TableItem(1,402)));
	tran.insert(make_pair("-", TableItem(1,403)));
	tran.insert(make_pair("*", TableItem(1,404)));
	tran.insert(make_pair("/", TableItem(1,405)));
	tran.insert(make_pair("%", TableItem(1,406)));
	tran.insert(make_pair(")", TableItem(2,65)));
	_parseTable.insert(make_pair(361,tran));
	tran.clear();


	// state 362
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,407)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(362,tran));
	tran.clear();


	// state 363
	tran.insert(make_pair("||", TableItem(2,48)));
	tran.insert(make_pair("&&", TableItem(2,48)));
	tran.insert(make_pair("|", TableItem(2,48)));
	tran.insert(make_pair("^", TableItem(2,48)));
	tran.insert(make_pair("&", TableItem(2,48)));
	tran.insert(make_pair("<<", TableItem(2,48)));
	tran.insert(make_pair(">>", TableItem(2,48)));
	tran.insert(make_pair("+", TableItem(2,48)));
	tran.insert(make_pair("-", TableItem(2,48)));
	tran.insert(make_pair("*", TableItem(2,48)));
	tran.insert(make_pair("/", TableItem(2,48)));
	tran.insert(make_pair("%", TableItem(2,48)));
	tran.insert(make_pair("(", TableItem(1,408)));
	tran.insert(make_pair(")", TableItem(2,48)));
	tran.insert(make_pair("[", TableItem(1,409)));
	_parseTable.insert(make_pair(363,tran));
	tran.clear();


	// state 364
	tran.insert(make_pair("||", TableItem(2,50)));
	tran.insert(make_pair("&&", TableItem(2,50)));
	tran.insert(make_pair("|", TableItem(2,50)));
	tran.insert(make_pair("^", TableItem(2,50)));
	tran.insert(make_pair("&", TableItem(2,50)));
	tran.insert(make_pair("<<", TableItem(2,50)));
	tran.insert(make_pair(">>", TableItem(2,50)));
	tran.insert(make_pair("+", TableItem(2,50)));
	tran.insert(make_pair("-", TableItem(2,50)));
	tran.insert(make_pair("*", TableItem(2,50)));
	tran.insert(make_pair("/", TableItem(2,50)));
	tran.insert(make_pair("%", TableItem(2,50)));
	tran.insert(make_pair(")", TableItem(2,50)));
	_parseTable.insert(make_pair(364,tran));
	tran.clear();


	// state 365
	tran.insert(make_pair("(", TableItem(1,410)));
	_parseTable.insert(make_pair(365,tran));
	tran.clear();


	// state 366
	tran.insert(make_pair("||", TableItem(2,47)));
	tran.insert(make_pair("&&", TableItem(2,47)));
	tran.insert(make_pair("|", TableItem(2,47)));
	tran.insert(make_pair("^", TableItem(2,47)));
	tran.insert(make_pair("&", TableItem(2,47)));
	tran.insert(make_pair("==", TableItem(2,47)));
	tran.insert(make_pair("!=", TableItem(2,47)));
	tran.insert(make_pair("<", TableItem(2,47)));
	tran.insert(make_pair(">", TableItem(2,47)));
	tran.insert(make_pair("<=", TableItem(2,47)));
	tran.insert(make_pair(">=", TableItem(2,47)));
	tran.insert(make_pair("<<", TableItem(2,47)));
	tran.insert(make_pair(">>", TableItem(2,47)));
	tran.insert(make_pair("+", TableItem(2,47)));
	tran.insert(make_pair("-", TableItem(2,47)));
	tran.insert(make_pair("*", TableItem(2,47)));
	tran.insert(make_pair("/", TableItem(2,47)));
	tran.insert(make_pair("%", TableItem(2,47)));
	tran.insert(make_pair(")", TableItem(2,47)));
	_parseTable.insert(make_pair(366,tran));
	tran.clear();


	// state 367
	tran.insert(make_pair("||", TableItem(2,64)));
	tran.insert(make_pair("&&", TableItem(2,64)));
	tran.insert(make_pair(")", TableItem(2,64)));
	_parseTable.insert(make_pair(367,tran));
	tran.clear();


	// state 368
	tran.insert(make_pair(",", TableItem(1,226)));
	tran.insert(make_pair(")", TableItem(1,411)));
	_parseTable.insert(make_pair(368,tran));
	tran.clear();


	// state 369
	tran.insert(make_pair("|", TableItem(1,230)));
	tran.insert(make_pair("^", TableItem(1,231)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(1,412)));
	_parseTable.insert(make_pair(369,tran));
	tran.clear();


	// state 370
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,413)));
	_parseTable.insert(make_pair(370,tran));
	tran.clear();


	// state 371
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,414)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(371,tran));
	tran.clear();


	// state 372
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,415)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(372,tran));
	tran.clear();


	// state 373
	tran.insert(make_pair("stmt", TableItem(3,416)));
	tran.insert(make_pair("includestmt", TableItem(3,417)));
	tran.insert(make_pair("{", TableItem(1,418)));
	tran.insert(make_pair("fun_define", TableItem(3,419)));
	tran.insert(make_pair("if_stmt", TableItem(3,420)));
	tran.insert(make_pair("while_stmt", TableItem(3,421)));
	tran.insert(make_pair("var_decl", TableItem(3,422)));
	tran.insert(make_pair(";", TableItem(1,423)));
	tran.insert(make_pair("static", TableItem(1,424)));
	tran.insert(make_pair("expr_stmt", TableItem(3,425)));
	tran.insert(make_pair("return", TableItem(1,426)));
	tran.insert(make_pair("call_stmt", TableItem(3,427)));
	tran.insert(make_pair("set_mem", TableItem(1,428)));
	tran.insert(make_pair("include", TableItem(1,429)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,430)));
	tran.insert(make_pair("type_spec", TableItem(3,431)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,432)));
	tran.insert(make_pair("while", TableItem(1,433)));
	_parseTable.insert(make_pair(373,tran));
	tran.clear();


	// state 374
	tran.insert(make_pair("M", TableItem(3,434)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(374,tran));
	tran.clear();


	// state 375
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,435)));
	_parseTable.insert(make_pair(375,tran));
	tran.clear();


	// state 376
	tran.insert(make_pair("{", TableItem(2,19)));
	tran.insert(make_pair("}", TableItem(2,19)));
	tran.insert(make_pair(";", TableItem(2,19)));
	tran.insert(make_pair("static", TableItem(2,19)));
	tran.insert(make_pair("return", TableItem(2,19)));
	tran.insert(make_pair("set_mem", TableItem(2,19)));
	tran.insert(make_pair("include", TableItem(2,19)));
	tran.insert(make_pair("id", TableItem(2,19)));
	tran.insert(make_pair("int", TableItem(2,19)));
	tran.insert(make_pair("double", TableItem(2,19)));
	tran.insert(make_pair("void", TableItem(2,19)));
	tran.insert(make_pair("char", TableItem(2,19)));
	tran.insert(make_pair("bool", TableItem(2,19)));
	tran.insert(make_pair("float", TableItem(2,19)));
	tran.insert(make_pair("if", TableItem(2,19)));
	tran.insert(make_pair("while", TableItem(2,19)));
	_parseTable.insert(make_pair(376,tran));
	tran.clear();


	// state 377
	tran.insert(make_pair("{", TableItem(2,21)));
	tran.insert(make_pair("}", TableItem(2,21)));
	tran.insert(make_pair(";", TableItem(2,21)));
	tran.insert(make_pair("static", TableItem(2,21)));
	tran.insert(make_pair("return", TableItem(2,21)));
	tran.insert(make_pair("set_mem", TableItem(2,21)));
	tran.insert(make_pair("include", TableItem(2,21)));
	tran.insert(make_pair("id", TableItem(2,21)));
	tran.insert(make_pair("int", TableItem(2,21)));
	tran.insert(make_pair("double", TableItem(2,21)));
	tran.insert(make_pair("void", TableItem(2,21)));
	tran.insert(make_pair("char", TableItem(2,21)));
	tran.insert(make_pair("bool", TableItem(2,21)));
	tran.insert(make_pair("float", TableItem(2,21)));
	tran.insert(make_pair("if", TableItem(2,21)));
	tran.insert(make_pair("while", TableItem(2,21)));
	_parseTable.insert(make_pair(377,tran));
	tran.clear();


	// state 378
	tran.insert(make_pair("stmt", TableItem(3,436)));
	tran.insert(make_pair("includestmt", TableItem(3,437)));
	tran.insert(make_pair("{", TableItem(1,438)));
	tran.insert(make_pair("fun_define", TableItem(3,439)));
	tran.insert(make_pair("if_stmt", TableItem(3,440)));
	tran.insert(make_pair("while_stmt", TableItem(3,441)));
	tran.insert(make_pair("var_decl", TableItem(3,442)));
	tran.insert(make_pair(";", TableItem(1,443)));
	tran.insert(make_pair("static", TableItem(1,444)));
	tran.insert(make_pair("expr_stmt", TableItem(3,445)));
	tran.insert(make_pair("return", TableItem(1,446)));
	tran.insert(make_pair("call_stmt", TableItem(3,447)));
	tran.insert(make_pair("set_mem", TableItem(1,448)));
	tran.insert(make_pair("include", TableItem(1,449)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,450)));
	tran.insert(make_pair("type_spec", TableItem(3,451)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,452)));
	tran.insert(make_pair("while", TableItem(1,453)));
	_parseTable.insert(make_pair(378,tran));
	tran.clear();


	// state 379
	tran.insert(make_pair("M", TableItem(3,454)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(379,tran));
	tran.clear();


	// state 380
	tran.insert(make_pair("|", TableItem(2,49)));
	tran.insert(make_pair("^", TableItem(2,49)));
	tran.insert(make_pair("&", TableItem(2,49)));
	tran.insert(make_pair("<<", TableItem(2,49)));
	tran.insert(make_pair(">>", TableItem(2,49)));
	tran.insert(make_pair("+", TableItem(2,49)));
	tran.insert(make_pair("-", TableItem(2,49)));
	tran.insert(make_pair("*", TableItem(2,49)));
	tran.insert(make_pair("/", TableItem(2,49)));
	tran.insert(make_pair("%", TableItem(2,49)));
	tran.insert(make_pair(")", TableItem(2,49)));
	_parseTable.insert(make_pair(380,tran));
	tran.clear();


	// state 381
	tran.insert(make_pair("|", TableItem(2,52)));
	tran.insert(make_pair("^", TableItem(2,52)));
	tran.insert(make_pair("&", TableItem(2,52)));
	tran.insert(make_pair("<<", TableItem(2,52)));
	tran.insert(make_pair(">>", TableItem(2,52)));
	tran.insert(make_pair("+", TableItem(2,52)));
	tran.insert(make_pair("-", TableItem(2,52)));
	tran.insert(make_pair("*", TableItem(2,52)));
	tran.insert(make_pair("/", TableItem(2,52)));
	tran.insert(make_pair("%", TableItem(2,52)));
	tran.insert(make_pair(")", TableItem(2,52)));
	_parseTable.insert(make_pair(381,tran));
	tran.clear();


	// state 382
	tran.insert(make_pair("|", TableItem(2,53)));
	tran.insert(make_pair("^", TableItem(2,53)));
	tran.insert(make_pair("&", TableItem(2,53)));
	tran.insert(make_pair("<<", TableItem(2,53)));
	tran.insert(make_pair(">>", TableItem(2,53)));
	tran.insert(make_pair("+", TableItem(2,53)));
	tran.insert(make_pair("-", TableItem(2,53)));
	tran.insert(make_pair("*", TableItem(2,53)));
	tran.insert(make_pair("/", TableItem(2,53)));
	tran.insert(make_pair("%", TableItem(2,53)));
	tran.insert(make_pair(")", TableItem(2,53)));
	_parseTable.insert(make_pair(382,tran));
	tran.clear();


	// state 383
	tran.insert(make_pair(";", TableItem(1,455)));
	_parseTable.insert(make_pair(383,tran));
	tran.clear();


	// state 384
	tran.insert(make_pair("|", TableItem(2,49)));
	tran.insert(make_pair("^", TableItem(2,49)));
	tran.insert(make_pair("&", TableItem(2,49)));
	tran.insert(make_pair("<<", TableItem(2,49)));
	tran.insert(make_pair(">>", TableItem(2,49)));
	tran.insert(make_pair("+", TableItem(2,49)));
	tran.insert(make_pair("-", TableItem(2,49)));
	tran.insert(make_pair("*", TableItem(2,49)));
	tran.insert(make_pair("/", TableItem(2,49)));
	tran.insert(make_pair("%", TableItem(2,49)));
	tran.insert(make_pair(",", TableItem(2,49)));
	_parseTable.insert(make_pair(384,tran));
	tran.clear();


	// state 385
	tran.insert(make_pair("|", TableItem(2,52)));
	tran.insert(make_pair("^", TableItem(2,52)));
	tran.insert(make_pair("&", TableItem(2,52)));
	tran.insert(make_pair("<<", TableItem(2,52)));
	tran.insert(make_pair(">>", TableItem(2,52)));
	tran.insert(make_pair("+", TableItem(2,52)));
	tran.insert(make_pair("-", TableItem(2,52)));
	tran.insert(make_pair("*", TableItem(2,52)));
	tran.insert(make_pair("/", TableItem(2,52)));
	tran.insert(make_pair("%", TableItem(2,52)));
	tran.insert(make_pair(",", TableItem(2,52)));
	_parseTable.insert(make_pair(385,tran));
	tran.clear();


	// state 386
	tran.insert(make_pair("|", TableItem(2,53)));
	tran.insert(make_pair("^", TableItem(2,53)));
	tran.insert(make_pair("&", TableItem(2,53)));
	tran.insert(make_pair("<<", TableItem(2,53)));
	tran.insert(make_pair(">>", TableItem(2,53)));
	tran.insert(make_pair("+", TableItem(2,53)));
	tran.insert(make_pair("-", TableItem(2,53)));
	tran.insert(make_pair("*", TableItem(2,53)));
	tran.insert(make_pair("/", TableItem(2,53)));
	tran.insert(make_pair("%", TableItem(2,53)));
	tran.insert(make_pair(",", TableItem(2,53)));
	_parseTable.insert(make_pair(386,tran));
	tran.clear();


	// state 387
	tran.insert(make_pair("num", TableItem(1,456)));
	_parseTable.insert(make_pair(387,tran));
	tran.clear();


	// state 388
	tran.insert(make_pair(",", TableItem(2,22)));
	tran.insert(make_pair(")", TableItem(2,22)));
	_parseTable.insert(make_pair(388,tran));
	tran.clear();


	// state 389
	tran.insert(make_pair("|", TableItem(2,49)));
	tran.insert(make_pair("^", TableItem(2,49)));
	tran.insert(make_pair("&", TableItem(2,49)));
	tran.insert(make_pair("<<", TableItem(2,49)));
	tran.insert(make_pair(">>", TableItem(2,49)));
	tran.insert(make_pair("+", TableItem(2,49)));
	tran.insert(make_pair("-", TableItem(2,49)));
	tran.insert(make_pair("*", TableItem(2,49)));
	tran.insert(make_pair("/", TableItem(2,49)));
	tran.insert(make_pair("%", TableItem(2,49)));
	tran.insert(make_pair(",", TableItem(2,49)));
	tran.insert(make_pair(")", TableItem(2,49)));
	_parseTable.insert(make_pair(389,tran));
	tran.clear();


	// state 390
	tran.insert(make_pair("|", TableItem(2,52)));
	tran.insert(make_pair("^", TableItem(2,52)));
	tran.insert(make_pair("&", TableItem(2,52)));
	tran.insert(make_pair("<<", TableItem(2,52)));
	tran.insert(make_pair(">>", TableItem(2,52)));
	tran.insert(make_pair("+", TableItem(2,52)));
	tran.insert(make_pair("-", TableItem(2,52)));
	tran.insert(make_pair("*", TableItem(2,52)));
	tran.insert(make_pair("/", TableItem(2,52)));
	tran.insert(make_pair("%", TableItem(2,52)));
	tran.insert(make_pair(",", TableItem(2,52)));
	tran.insert(make_pair(")", TableItem(2,52)));
	_parseTable.insert(make_pair(390,tran));
	tran.clear();


	// state 391
	tran.insert(make_pair("|", TableItem(2,53)));
	tran.insert(make_pair("^", TableItem(2,53)));
	tran.insert(make_pair("&", TableItem(2,53)));
	tran.insert(make_pair("<<", TableItem(2,53)));
	tran.insert(make_pair(">>", TableItem(2,53)));
	tran.insert(make_pair("+", TableItem(2,53)));
	tran.insert(make_pair("-", TableItem(2,53)));
	tran.insert(make_pair("*", TableItem(2,53)));
	tran.insert(make_pair("/", TableItem(2,53)));
	tran.insert(make_pair("%", TableItem(2,53)));
	tran.insert(make_pair(",", TableItem(2,53)));
	tran.insert(make_pair(")", TableItem(2,53)));
	_parseTable.insert(make_pair(391,tran));
	tran.clear();


	// state 392
	tran.insert(make_pair("|", TableItem(1,90)));
	tran.insert(make_pair("^", TableItem(1,91)));
	tran.insert(make_pair("&", TableItem(1,92)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(2,36)));
	_parseTable.insert(make_pair(392,tran));
	tran.clear();


	// state 393
	tran.insert(make_pair("|", TableItem(2,49)));
	tran.insert(make_pair("^", TableItem(2,49)));
	tran.insert(make_pair("&", TableItem(2,49)));
	tran.insert(make_pair("<<", TableItem(2,49)));
	tran.insert(make_pair(">>", TableItem(2,49)));
	tran.insert(make_pair("+", TableItem(2,49)));
	tran.insert(make_pair("-", TableItem(2,49)));
	tran.insert(make_pair("*", TableItem(2,49)));
	tran.insert(make_pair("/", TableItem(2,49)));
	tran.insert(make_pair("%", TableItem(2,49)));
	tran.insert(make_pair("]", TableItem(2,49)));
	_parseTable.insert(make_pair(393,tran));
	tran.clear();


	// state 394
	tran.insert(make_pair("|", TableItem(2,52)));
	tran.insert(make_pair("^", TableItem(2,52)));
	tran.insert(make_pair("&", TableItem(2,52)));
	tran.insert(make_pair("<<", TableItem(2,52)));
	tran.insert(make_pair(">>", TableItem(2,52)));
	tran.insert(make_pair("+", TableItem(2,52)));
	tran.insert(make_pair("-", TableItem(2,52)));
	tran.insert(make_pair("*", TableItem(2,52)));
	tran.insert(make_pair("/", TableItem(2,52)));
	tran.insert(make_pair("%", TableItem(2,52)));
	tran.insert(make_pair("]", TableItem(2,52)));
	_parseTable.insert(make_pair(394,tran));
	tran.clear();


	// state 395
	tran.insert(make_pair("|", TableItem(2,53)));
	tran.insert(make_pair("^", TableItem(2,53)));
	tran.insert(make_pair("&", TableItem(2,53)));
	tran.insert(make_pair("<<", TableItem(2,53)));
	tran.insert(make_pair(">>", TableItem(2,53)));
	tran.insert(make_pair("+", TableItem(2,53)));
	tran.insert(make_pair("-", TableItem(2,53)));
	tran.insert(make_pair("*", TableItem(2,53)));
	tran.insert(make_pair("/", TableItem(2,53)));
	tran.insert(make_pair("%", TableItem(2,53)));
	tran.insert(make_pair("]", TableItem(2,53)));
	_parseTable.insert(make_pair(395,tran));
	tran.clear();


	// state 396
	tran.insert(make_pair("||", TableItem(2,51)));
	tran.insert(make_pair("&&", TableItem(2,51)));
	tran.insert(make_pair("|", TableItem(2,51)));
	tran.insert(make_pair("^", TableItem(2,51)));
	tran.insert(make_pair("&", TableItem(2,51)));
	tran.insert(make_pair("<<", TableItem(2,51)));
	tran.insert(make_pair(">>", TableItem(2,51)));
	tran.insert(make_pair("+", TableItem(2,51)));
	tran.insert(make_pair("-", TableItem(2,51)));
	tran.insert(make_pair("*", TableItem(1,404)));
	tran.insert(make_pair("/", TableItem(1,405)));
	tran.insert(make_pair("%", TableItem(1,406)));
	tran.insert(make_pair(")", TableItem(2,51)));
	_parseTable.insert(make_pair(396,tran));
	tran.clear();


	// state 397
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,457)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(397,tran));
	tran.clear();


	// state 398
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,458)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(398,tran));
	tran.clear();


	// state 399
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,459)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(399,tran));
	tran.clear();


	// state 400
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,460)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(400,tran));
	tran.clear();


	// state 401
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,461)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(401,tran));
	tran.clear();


	// state 402
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,462)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(402,tran));
	tran.clear();


	// state 403
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,463)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(403,tran));
	tran.clear();


	// state 404
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,464)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(404,tran));
	tran.clear();


	// state 405
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,465)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(405,tran));
	tran.clear();


	// state 406
	tran.insert(make_pair("-", TableItem(1,360)));
	tran.insert(make_pair("expr", TableItem(3,466)));
	tran.insert(make_pair("(", TableItem(1,362)));
	tran.insert(make_pair("id", TableItem(1,363)));
	tran.insert(make_pair("num", TableItem(1,364)));
	tran.insert(make_pair("load_mem", TableItem(1,365)));
	_parseTable.insert(make_pair(406,tran));
	tran.clear();


	// state 407
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,467)));
	_parseTable.insert(make_pair(407,tran));
	tran.clear();


	// state 408
	tran.insert(make_pair("-", TableItem(1,123)));
	tran.insert(make_pair("expr", TableItem(3,124)));
	tran.insert(make_pair("(", TableItem(1,125)));
	tran.insert(make_pair(",", TableItem(2,56)));
	tran.insert(make_pair(")", TableItem(2,56)));
	tran.insert(make_pair("id", TableItem(1,126)));
	tran.insert(make_pair("num", TableItem(1,127)));
	tran.insert(make_pair("arg_list", TableItem(3,468)));
	tran.insert(make_pair("load_mem", TableItem(1,129)));
	_parseTable.insert(make_pair(408,tran));
	tran.clear();


	// state 409
	tran.insert(make_pair("-", TableItem(1,130)));
	tran.insert(make_pair("expr", TableItem(3,469)));
	tran.insert(make_pair("(", TableItem(1,132)));
	tran.insert(make_pair("id", TableItem(1,133)));
	tran.insert(make_pair("num", TableItem(1,134)));
	tran.insert(make_pair("load_mem", TableItem(1,135)));
	_parseTable.insert(make_pair(409,tran));
	tran.clear();


	// state 410
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,470)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(410,tran));
	tran.clear();


	// state 411
	tran.insert(make_pair("||", TableItem(2,49)));
	tran.insert(make_pair("&&", TableItem(2,49)));
	tran.insert(make_pair("|", TableItem(2,49)));
	tran.insert(make_pair("^", TableItem(2,49)));
	tran.insert(make_pair("&", TableItem(2,49)));
	tran.insert(make_pair("==", TableItem(2,49)));
	tran.insert(make_pair("!=", TableItem(2,49)));
	tran.insert(make_pair("<", TableItem(2,49)));
	tran.insert(make_pair(">", TableItem(2,49)));
	tran.insert(make_pair("<=", TableItem(2,49)));
	tran.insert(make_pair(">=", TableItem(2,49)));
	tran.insert(make_pair("<<", TableItem(2,49)));
	tran.insert(make_pair(">>", TableItem(2,49)));
	tran.insert(make_pair("+", TableItem(2,49)));
	tran.insert(make_pair("-", TableItem(2,49)));
	tran.insert(make_pair("*", TableItem(2,49)));
	tran.insert(make_pair("/", TableItem(2,49)));
	tran.insert(make_pair("%", TableItem(2,49)));
	tran.insert(make_pair(")", TableItem(2,49)));
	_parseTable.insert(make_pair(411,tran));
	tran.clear();


	// state 412
	tran.insert(make_pair("||", TableItem(2,52)));
	tran.insert(make_pair("&&", TableItem(2,52)));
	tran.insert(make_pair("|", TableItem(2,52)));
	tran.insert(make_pair("^", TableItem(2,52)));
	tran.insert(make_pair("&", TableItem(2,52)));
	tran.insert(make_pair("==", TableItem(2,52)));
	tran.insert(make_pair("!=", TableItem(2,52)));
	tran.insert(make_pair("<", TableItem(2,52)));
	tran.insert(make_pair(">", TableItem(2,52)));
	tran.insert(make_pair("<=", TableItem(2,52)));
	tran.insert(make_pair(">=", TableItem(2,52)));
	tran.insert(make_pair("<<", TableItem(2,52)));
	tran.insert(make_pair(">>", TableItem(2,52)));
	tran.insert(make_pair("+", TableItem(2,52)));
	tran.insert(make_pair("-", TableItem(2,52)));
	tran.insert(make_pair("*", TableItem(2,52)));
	tran.insert(make_pair("/", TableItem(2,52)));
	tran.insert(make_pair("%", TableItem(2,52)));
	tran.insert(make_pair(")", TableItem(2,52)));
	_parseTable.insert(make_pair(412,tran));
	tran.clear();


	// state 413
	tran.insert(make_pair("||", TableItem(2,53)));
	tran.insert(make_pair("&&", TableItem(2,53)));
	tran.insert(make_pair("|", TableItem(2,53)));
	tran.insert(make_pair("^", TableItem(2,53)));
	tran.insert(make_pair("&", TableItem(2,53)));
	tran.insert(make_pair("==", TableItem(2,53)));
	tran.insert(make_pair("!=", TableItem(2,53)));
	tran.insert(make_pair("<", TableItem(2,53)));
	tran.insert(make_pair(">", TableItem(2,53)));
	tran.insert(make_pair("<=", TableItem(2,53)));
	tran.insert(make_pair(">=", TableItem(2,53)));
	tran.insert(make_pair("<<", TableItem(2,53)));
	tran.insert(make_pair(">>", TableItem(2,53)));
	tran.insert(make_pair("+", TableItem(2,53)));
	tran.insert(make_pair("-", TableItem(2,53)));
	tran.insert(make_pair("*", TableItem(2,53)));
	tran.insert(make_pair("/", TableItem(2,53)));
	tran.insert(make_pair("%", TableItem(2,53)));
	tran.insert(make_pair(")", TableItem(2,53)));
	_parseTable.insert(make_pair(413,tran));
	tran.clear();


	// state 414
	tran.insert(make_pair("||", TableItem(2,62)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(2,62)));
	_parseTable.insert(make_pair(414,tran));
	tran.clear();


	// state 415
	tran.insert(make_pair("||", TableItem(2,61)));
	tran.insert(make_pair("&&", TableItem(2,61)));
	tran.insert(make_pair(")", TableItem(2,61)));
	_parseTable.insert(make_pair(415,tran));
	tran.clear();


	// state 416
	tran.insert(make_pair("else", TableItem(2,70)));
	tran.insert(make_pair("{", TableItem(2,58)));
	tran.insert(make_pair(";", TableItem(2,58)));
	tran.insert(make_pair("static", TableItem(2,58)));
	tran.insert(make_pair("return", TableItem(2,58)));
	tran.insert(make_pair("set_mem", TableItem(2,58)));
	tran.insert(make_pair("include", TableItem(2,58)));
	tran.insert(make_pair("id", TableItem(2,58)));
	tran.insert(make_pair("int", TableItem(2,58)));
	tran.insert(make_pair("double", TableItem(2,58)));
	tran.insert(make_pair("void", TableItem(2,58)));
	tran.insert(make_pair("char", TableItem(2,58)));
	tran.insert(make_pair("bool", TableItem(2,58)));
	tran.insert(make_pair("float", TableItem(2,58)));
	tran.insert(make_pair("if", TableItem(2,58)));
	tran.insert(make_pair("N", TableItem(3,471)));
	tran.insert(make_pair("while", TableItem(2,58)));
	tran.insert(make_pair("$", TableItem(2,58)));
	_parseTable.insert(make_pair(416,tran));
	tran.clear();


	// state 417
	tran.insert(make_pair("else", TableItem(2,4)));
	tran.insert(make_pair("{", TableItem(2,4)));
	tran.insert(make_pair(";", TableItem(2,4)));
	tran.insert(make_pair("static", TableItem(2,4)));
	tran.insert(make_pair("return", TableItem(2,4)));
	tran.insert(make_pair("set_mem", TableItem(2,4)));
	tran.insert(make_pair("include", TableItem(2,4)));
	tran.insert(make_pair("id", TableItem(2,4)));
	tran.insert(make_pair("int", TableItem(2,4)));
	tran.insert(make_pair("double", TableItem(2,4)));
	tran.insert(make_pair("void", TableItem(2,4)));
	tran.insert(make_pair("char", TableItem(2,4)));
	tran.insert(make_pair("bool", TableItem(2,4)));
	tran.insert(make_pair("float", TableItem(2,4)));
	tran.insert(make_pair("if", TableItem(2,4)));
	tran.insert(make_pair("while", TableItem(2,4)));
	tran.insert(make_pair("$", TableItem(2,4)));
	_parseTable.insert(make_pair(417,tran));
	tran.clear();


	// state 418
	tran.insert(make_pair("stmts", TableItem(3,472)));
	tran.insert(make_pair("stmt", TableItem(3,30)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(418,tran));
	tran.clear();


	// state 419
	tran.insert(make_pair("else", TableItem(2,6)));
	tran.insert(make_pair("{", TableItem(2,6)));
	tran.insert(make_pair(";", TableItem(2,6)));
	tran.insert(make_pair("static", TableItem(2,6)));
	tran.insert(make_pair("return", TableItem(2,6)));
	tran.insert(make_pair("set_mem", TableItem(2,6)));
	tran.insert(make_pair("include", TableItem(2,6)));
	tran.insert(make_pair("id", TableItem(2,6)));
	tran.insert(make_pair("int", TableItem(2,6)));
	tran.insert(make_pair("double", TableItem(2,6)));
	tran.insert(make_pair("void", TableItem(2,6)));
	tran.insert(make_pair("char", TableItem(2,6)));
	tran.insert(make_pair("bool", TableItem(2,6)));
	tran.insert(make_pair("float", TableItem(2,6)));
	tran.insert(make_pair("if", TableItem(2,6)));
	tran.insert(make_pair("while", TableItem(2,6)));
	tran.insert(make_pair("$", TableItem(2,6)));
	_parseTable.insert(make_pair(419,tran));
	tran.clear();


	// state 420
	tran.insert(make_pair("else", TableItem(2,7)));
	tran.insert(make_pair("{", TableItem(2,7)));
	tran.insert(make_pair(";", TableItem(2,7)));
	tran.insert(make_pair("static", TableItem(2,7)));
	tran.insert(make_pair("return", TableItem(2,7)));
	tran.insert(make_pair("set_mem", TableItem(2,7)));
	tran.insert(make_pair("include", TableItem(2,7)));
	tran.insert(make_pair("id", TableItem(2,7)));
	tran.insert(make_pair("int", TableItem(2,7)));
	tran.insert(make_pair("double", TableItem(2,7)));
	tran.insert(make_pair("void", TableItem(2,7)));
	tran.insert(make_pair("char", TableItem(2,7)));
	tran.insert(make_pair("bool", TableItem(2,7)));
	tran.insert(make_pair("float", TableItem(2,7)));
	tran.insert(make_pair("if", TableItem(2,7)));
	tran.insert(make_pair("while", TableItem(2,7)));
	tran.insert(make_pair("$", TableItem(2,7)));
	_parseTable.insert(make_pair(420,tran));
	tran.clear();


	// state 421
	tran.insert(make_pair("else", TableItem(2,8)));
	tran.insert(make_pair("{", TableItem(2,8)));
	tran.insert(make_pair(";", TableItem(2,8)));
	tran.insert(make_pair("static", TableItem(2,8)));
	tran.insert(make_pair("return", TableItem(2,8)));
	tran.insert(make_pair("set_mem", TableItem(2,8)));
	tran.insert(make_pair("include", TableItem(2,8)));
	tran.insert(make_pair("id", TableItem(2,8)));
	tran.insert(make_pair("int", TableItem(2,8)));
	tran.insert(make_pair("double", TableItem(2,8)));
	tran.insert(make_pair("void", TableItem(2,8)));
	tran.insert(make_pair("char", TableItem(2,8)));
	tran.insert(make_pair("bool", TableItem(2,8)));
	tran.insert(make_pair("float", TableItem(2,8)));
	tran.insert(make_pair("if", TableItem(2,8)));
	tran.insert(make_pair("while", TableItem(2,8)));
	tran.insert(make_pair("$", TableItem(2,8)));
	_parseTable.insert(make_pair(421,tran));
	tran.clear();


	// state 422
	tran.insert(make_pair(";", TableItem(1,473)));
	_parseTable.insert(make_pair(422,tran));
	tran.clear();


	// state 423
	tran.insert(make_pair("else", TableItem(2,16)));
	tran.insert(make_pair("{", TableItem(2,16)));
	tran.insert(make_pair(";", TableItem(2,16)));
	tran.insert(make_pair("static", TableItem(2,16)));
	tran.insert(make_pair("return", TableItem(2,16)));
	tran.insert(make_pair("set_mem", TableItem(2,16)));
	tran.insert(make_pair("include", TableItem(2,16)));
	tran.insert(make_pair("id", TableItem(2,16)));
	tran.insert(make_pair("int", TableItem(2,16)));
	tran.insert(make_pair("double", TableItem(2,16)));
	tran.insert(make_pair("void", TableItem(2,16)));
	tran.insert(make_pair("char", TableItem(2,16)));
	tran.insert(make_pair("bool", TableItem(2,16)));
	tran.insert(make_pair("float", TableItem(2,16)));
	tran.insert(make_pair("if", TableItem(2,16)));
	tran.insert(make_pair("while", TableItem(2,16)));
	tran.insert(make_pair("$", TableItem(2,16)));
	_parseTable.insert(make_pair(423,tran));
	tran.clear();


	// state 424
	tran.insert(make_pair("var_decl", TableItem(3,474)));
	tran.insert(make_pair("type_spec", TableItem(3,50)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	_parseTable.insert(make_pair(424,tran));
	tran.clear();


	// state 425
	tran.insert(make_pair(";", TableItem(1,475)));
	_parseTable.insert(make_pair(425,tran));
	tran.clear();


	// state 426
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair(";", TableItem(1,476)));
	tran.insert(make_pair("expr", TableItem(3,477)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(426,tran));
	tran.clear();


	// state 427
	tran.insert(make_pair(";", TableItem(1,478)));
	_parseTable.insert(make_pair(427,tran));
	tran.clear();


	// state 428
	tran.insert(make_pair("(", TableItem(1,479)));
	_parseTable.insert(make_pair(428,tran));
	tran.clear();


	// state 429
	tran.insert(make_pair("<", TableItem(1,480)));
	tran.insert(make_pair("\"", TableItem(1,481)));
	_parseTable.insert(make_pair(429,tran));
	tran.clear();


	// state 430
	tran.insert(make_pair("{", TableItem(2,71)));
	tran.insert(make_pair("BlockLeader", TableItem(3,482)));
	_parseTable.insert(make_pair(430,tran));
	tran.clear();


	// state 431
	tran.insert(make_pair("id", TableItem(1,483)));
	_parseTable.insert(make_pair(431,tran));
	tran.clear();


	// state 432
	tran.insert(make_pair("(", TableItem(1,484)));
	_parseTable.insert(make_pair(432,tran));
	tran.clear();


	// state 433
	tran.insert(make_pair("M", TableItem(3,485)));
	tran.insert(make_pair("(", TableItem(2,69)));
	_parseTable.insert(make_pair(433,tran));
	tran.clear();


	// state 434
	tran.insert(make_pair("stmt", TableItem(3,486)));
	tran.insert(make_pair("includestmt", TableItem(3,4)));
	tran.insert(make_pair("{", TableItem(1,5)));
	tran.insert(make_pair("fun_define", TableItem(3,6)));
	tran.insert(make_pair("if_stmt", TableItem(3,7)));
	tran.insert(make_pair("while_stmt", TableItem(3,8)));
	tran.insert(make_pair("var_decl", TableItem(3,9)));
	tran.insert(make_pair(";", TableItem(1,10)));
	tran.insert(make_pair("static", TableItem(1,11)));
	tran.insert(make_pair("expr_stmt", TableItem(3,12)));
	tran.insert(make_pair("return", TableItem(1,13)));
	tran.insert(make_pair("call_stmt", TableItem(3,14)));
	tran.insert(make_pair("set_mem", TableItem(1,15)));
	tran.insert(make_pair("include", TableItem(1,16)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,17)));
	tran.insert(make_pair("type_spec", TableItem(3,18)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,26)));
	tran.insert(make_pair("while", TableItem(1,27)));
	_parseTable.insert(make_pair(434,tran));
	tran.clear();


	// state 435
	tran.insert(make_pair(";", TableItem(1,487)));
	_parseTable.insert(make_pair(435,tran));
	tran.clear();


	// state 436
	tran.insert(make_pair("else", TableItem(2,70)));
	tran.insert(make_pair("{", TableItem(2,58)));
	tran.insert(make_pair("}", TableItem(2,58)));
	tran.insert(make_pair(";", TableItem(2,58)));
	tran.insert(make_pair("static", TableItem(2,58)));
	tran.insert(make_pair("return", TableItem(2,58)));
	tran.insert(make_pair("set_mem", TableItem(2,58)));
	tran.insert(make_pair("include", TableItem(2,58)));
	tran.insert(make_pair("id", TableItem(2,58)));
	tran.insert(make_pair("int", TableItem(2,58)));
	tran.insert(make_pair("double", TableItem(2,58)));
	tran.insert(make_pair("void", TableItem(2,58)));
	tran.insert(make_pair("char", TableItem(2,58)));
	tran.insert(make_pair("bool", TableItem(2,58)));
	tran.insert(make_pair("float", TableItem(2,58)));
	tran.insert(make_pair("if", TableItem(2,58)));
	tran.insert(make_pair("N", TableItem(3,488)));
	tran.insert(make_pair("while", TableItem(2,58)));
	_parseTable.insert(make_pair(436,tran));
	tran.clear();


	// state 437
	tran.insert(make_pair("else", TableItem(2,4)));
	tran.insert(make_pair("{", TableItem(2,4)));
	tran.insert(make_pair("}", TableItem(2,4)));
	tran.insert(make_pair(";", TableItem(2,4)));
	tran.insert(make_pair("static", TableItem(2,4)));
	tran.insert(make_pair("return", TableItem(2,4)));
	tran.insert(make_pair("set_mem", TableItem(2,4)));
	tran.insert(make_pair("include", TableItem(2,4)));
	tran.insert(make_pair("id", TableItem(2,4)));
	tran.insert(make_pair("int", TableItem(2,4)));
	tran.insert(make_pair("double", TableItem(2,4)));
	tran.insert(make_pair("void", TableItem(2,4)));
	tran.insert(make_pair("char", TableItem(2,4)));
	tran.insert(make_pair("bool", TableItem(2,4)));
	tran.insert(make_pair("float", TableItem(2,4)));
	tran.insert(make_pair("if", TableItem(2,4)));
	tran.insert(make_pair("while", TableItem(2,4)));
	_parseTable.insert(make_pair(437,tran));
	tran.clear();


	// state 438
	tran.insert(make_pair("stmts", TableItem(3,489)));
	tran.insert(make_pair("stmt", TableItem(3,30)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(438,tran));
	tran.clear();


	// state 439
	tran.insert(make_pair("else", TableItem(2,6)));
	tran.insert(make_pair("{", TableItem(2,6)));
	tran.insert(make_pair("}", TableItem(2,6)));
	tran.insert(make_pair(";", TableItem(2,6)));
	tran.insert(make_pair("static", TableItem(2,6)));
	tran.insert(make_pair("return", TableItem(2,6)));
	tran.insert(make_pair("set_mem", TableItem(2,6)));
	tran.insert(make_pair("include", TableItem(2,6)));
	tran.insert(make_pair("id", TableItem(2,6)));
	tran.insert(make_pair("int", TableItem(2,6)));
	tran.insert(make_pair("double", TableItem(2,6)));
	tran.insert(make_pair("void", TableItem(2,6)));
	tran.insert(make_pair("char", TableItem(2,6)));
	tran.insert(make_pair("bool", TableItem(2,6)));
	tran.insert(make_pair("float", TableItem(2,6)));
	tran.insert(make_pair("if", TableItem(2,6)));
	tran.insert(make_pair("while", TableItem(2,6)));
	_parseTable.insert(make_pair(439,tran));
	tran.clear();


	// state 440
	tran.insert(make_pair("else", TableItem(2,7)));
	tran.insert(make_pair("{", TableItem(2,7)));
	tran.insert(make_pair("}", TableItem(2,7)));
	tran.insert(make_pair(";", TableItem(2,7)));
	tran.insert(make_pair("static", TableItem(2,7)));
	tran.insert(make_pair("return", TableItem(2,7)));
	tran.insert(make_pair("set_mem", TableItem(2,7)));
	tran.insert(make_pair("include", TableItem(2,7)));
	tran.insert(make_pair("id", TableItem(2,7)));
	tran.insert(make_pair("int", TableItem(2,7)));
	tran.insert(make_pair("double", TableItem(2,7)));
	tran.insert(make_pair("void", TableItem(2,7)));
	tran.insert(make_pair("char", TableItem(2,7)));
	tran.insert(make_pair("bool", TableItem(2,7)));
	tran.insert(make_pair("float", TableItem(2,7)));
	tran.insert(make_pair("if", TableItem(2,7)));
	tran.insert(make_pair("while", TableItem(2,7)));
	_parseTable.insert(make_pair(440,tran));
	tran.clear();


	// state 441
	tran.insert(make_pair("else", TableItem(2,8)));
	tran.insert(make_pair("{", TableItem(2,8)));
	tran.insert(make_pair("}", TableItem(2,8)));
	tran.insert(make_pair(";", TableItem(2,8)));
	tran.insert(make_pair("static", TableItem(2,8)));
	tran.insert(make_pair("return", TableItem(2,8)));
	tran.insert(make_pair("set_mem", TableItem(2,8)));
	tran.insert(make_pair("include", TableItem(2,8)));
	tran.insert(make_pair("id", TableItem(2,8)));
	tran.insert(make_pair("int", TableItem(2,8)));
	tran.insert(make_pair("double", TableItem(2,8)));
	tran.insert(make_pair("void", TableItem(2,8)));
	tran.insert(make_pair("char", TableItem(2,8)));
	tran.insert(make_pair("bool", TableItem(2,8)));
	tran.insert(make_pair("float", TableItem(2,8)));
	tran.insert(make_pair("if", TableItem(2,8)));
	tran.insert(make_pair("while", TableItem(2,8)));
	_parseTable.insert(make_pair(441,tran));
	tran.clear();


	// state 442
	tran.insert(make_pair(";", TableItem(1,490)));
	_parseTable.insert(make_pair(442,tran));
	tran.clear();


	// state 443
	tran.insert(make_pair("else", TableItem(2,16)));
	tran.insert(make_pair("{", TableItem(2,16)));
	tran.insert(make_pair("}", TableItem(2,16)));
	tran.insert(make_pair(";", TableItem(2,16)));
	tran.insert(make_pair("static", TableItem(2,16)));
	tran.insert(make_pair("return", TableItem(2,16)));
	tran.insert(make_pair("set_mem", TableItem(2,16)));
	tran.insert(make_pair("include", TableItem(2,16)));
	tran.insert(make_pair("id", TableItem(2,16)));
	tran.insert(make_pair("int", TableItem(2,16)));
	tran.insert(make_pair("double", TableItem(2,16)));
	tran.insert(make_pair("void", TableItem(2,16)));
	tran.insert(make_pair("char", TableItem(2,16)));
	tran.insert(make_pair("bool", TableItem(2,16)));
	tran.insert(make_pair("float", TableItem(2,16)));
	tran.insert(make_pair("if", TableItem(2,16)));
	tran.insert(make_pair("while", TableItem(2,16)));
	_parseTable.insert(make_pair(443,tran));
	tran.clear();


	// state 444
	tran.insert(make_pair("var_decl", TableItem(3,491)));
	tran.insert(make_pair("type_spec", TableItem(3,50)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	_parseTable.insert(make_pair(444,tran));
	tran.clear();


	// state 445
	tran.insert(make_pair(";", TableItem(1,492)));
	_parseTable.insert(make_pair(445,tran));
	tran.clear();


	// state 446
	tran.insert(make_pair("-", TableItem(1,52)));
	tran.insert(make_pair(";", TableItem(1,493)));
	tran.insert(make_pair("expr", TableItem(3,494)));
	tran.insert(make_pair("(", TableItem(1,55)));
	tran.insert(make_pair("id", TableItem(1,56)));
	tran.insert(make_pair("num", TableItem(1,57)));
	tran.insert(make_pair("load_mem", TableItem(1,58)));
	_parseTable.insert(make_pair(446,tran));
	tran.clear();


	// state 447
	tran.insert(make_pair(";", TableItem(1,495)));
	_parseTable.insert(make_pair(447,tran));
	tran.clear();


	// state 448
	tran.insert(make_pair("(", TableItem(1,496)));
	_parseTable.insert(make_pair(448,tran));
	tran.clear();


	// state 449
	tran.insert(make_pair("<", TableItem(1,497)));
	tran.insert(make_pair("\"", TableItem(1,498)));
	_parseTable.insert(make_pair(449,tran));
	tran.clear();


	// state 450
	tran.insert(make_pair("{", TableItem(2,71)));
	tran.insert(make_pair("BlockLeader", TableItem(3,499)));
	_parseTable.insert(make_pair(450,tran));
	tran.clear();


	// state 451
	tran.insert(make_pair("id", TableItem(1,500)));
	_parseTable.insert(make_pair(451,tran));
	tran.clear();


	// state 452
	tran.insert(make_pair("(", TableItem(1,501)));
	_parseTable.insert(make_pair(452,tran));
	tran.clear();


	// state 453
	tran.insert(make_pair("M", TableItem(3,502)));
	tran.insert(make_pair("(", TableItem(2,69)));
	_parseTable.insert(make_pair(453,tran));
	tran.clear();


	// state 454
	tran.insert(make_pair("stmt", TableItem(3,503)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(454,tran));
	tran.clear();


	// state 455
	tran.insert(make_pair("{", TableItem(2,15)));
	tran.insert(make_pair(";", TableItem(2,15)));
	tran.insert(make_pair("static", TableItem(2,15)));
	tran.insert(make_pair("return", TableItem(2,15)));
	tran.insert(make_pair("set_mem", TableItem(2,15)));
	tran.insert(make_pair("include", TableItem(2,15)));
	tran.insert(make_pair("id", TableItem(2,15)));
	tran.insert(make_pair("int", TableItem(2,15)));
	tran.insert(make_pair("double", TableItem(2,15)));
	tran.insert(make_pair("void", TableItem(2,15)));
	tran.insert(make_pair("char", TableItem(2,15)));
	tran.insert(make_pair("bool", TableItem(2,15)));
	tran.insert(make_pair("float", TableItem(2,15)));
	tran.insert(make_pair("if", TableItem(2,15)));
	tran.insert(make_pair("while", TableItem(2,15)));
	tran.insert(make_pair("$", TableItem(2,15)));
	_parseTable.insert(make_pair(455,tran));
	tran.clear();


	// state 456
	tran.insert(make_pair("]", TableItem(1,504)));
	_parseTable.insert(make_pair(456,tran));
	tran.clear();


	// state 457
	tran.insert(make_pair("||", TableItem(2,43)));
	tran.insert(make_pair("&&", TableItem(2,43)));
	tran.insert(make_pair("|", TableItem(2,43)));
	tran.insert(make_pair("^", TableItem(1,398)));
	tran.insert(make_pair("&", TableItem(1,399)));
	tran.insert(make_pair("<<", TableItem(1,400)));
	tran.insert(make_pair(">>", TableItem(1,401)));
	tran.insert(make_pair("+", TableItem(1,402)));
	tran.insert(make_pair("-", TableItem(1,403)));
	tran.insert(make_pair("*", TableItem(1,404)));
	tran.insert(make_pair("/", TableItem(1,405)));
	tran.insert(make_pair("%", TableItem(1,406)));
	tran.insert(make_pair(")", TableItem(2,43)));
	_parseTable.insert(make_pair(457,tran));
	tran.clear();


	// state 458
	tran.insert(make_pair("||", TableItem(2,44)));
	tran.insert(make_pair("&&", TableItem(2,44)));
	tran.insert(make_pair("|", TableItem(2,44)));
	tran.insert(make_pair("^", TableItem(2,44)));
	tran.insert(make_pair("&", TableItem(1,399)));
	tran.insert(make_pair("<<", TableItem(1,400)));
	tran.insert(make_pair(">>", TableItem(1,401)));
	tran.insert(make_pair("+", TableItem(1,402)));
	tran.insert(make_pair("-", TableItem(1,403)));
	tran.insert(make_pair("*", TableItem(1,404)));
	tran.insert(make_pair("/", TableItem(1,405)));
	tran.insert(make_pair("%", TableItem(1,406)));
	tran.insert(make_pair(")", TableItem(2,44)));
	_parseTable.insert(make_pair(458,tran));
	tran.clear();


	// state 459
	tran.insert(make_pair("||", TableItem(2,42)));
	tran.insert(make_pair("&&", TableItem(2,42)));
	tran.insert(make_pair("|", TableItem(2,42)));
	tran.insert(make_pair("^", TableItem(2,42)));
	tran.insert(make_pair("&", TableItem(2,42)));
	tran.insert(make_pair("<<", TableItem(1,400)));
	tran.insert(make_pair(">>", TableItem(1,401)));
	tran.insert(make_pair("+", TableItem(1,402)));
	tran.insert(make_pair("-", TableItem(1,403)));
	tran.insert(make_pair("*", TableItem(1,404)));
	tran.insert(make_pair("/", TableItem(1,405)));
	tran.insert(make_pair("%", TableItem(1,406)));
	tran.insert(make_pair(")", TableItem(2,42)));
	_parseTable.insert(make_pair(459,tran));
	tran.clear();


	// state 460
	tran.insert(make_pair("||", TableItem(2,46)));
	tran.insert(make_pair("&&", TableItem(2,46)));
	tran.insert(make_pair("|", TableItem(2,46)));
	tran.insert(make_pair("^", TableItem(2,46)));
	tran.insert(make_pair("&", TableItem(2,46)));
	tran.insert(make_pair("<<", TableItem(2,46)));
	tran.insert(make_pair(">>", TableItem(2,46)));
	tran.insert(make_pair("+", TableItem(1,402)));
	tran.insert(make_pair("-", TableItem(1,403)));
	tran.insert(make_pair("*", TableItem(1,404)));
	tran.insert(make_pair("/", TableItem(1,405)));
	tran.insert(make_pair("%", TableItem(1,406)));
	tran.insert(make_pair(")", TableItem(2,46)));
	_parseTable.insert(make_pair(460,tran));
	tran.clear();


	// state 461
	tran.insert(make_pair("||", TableItem(2,45)));
	tran.insert(make_pair("&&", TableItem(2,45)));
	tran.insert(make_pair("|", TableItem(2,45)));
	tran.insert(make_pair("^", TableItem(2,45)));
	tran.insert(make_pair("&", TableItem(2,45)));
	tran.insert(make_pair("<<", TableItem(2,45)));
	tran.insert(make_pair(">>", TableItem(2,45)));
	tran.insert(make_pair("+", TableItem(1,402)));
	tran.insert(make_pair("-", TableItem(1,403)));
	tran.insert(make_pair("*", TableItem(1,404)));
	tran.insert(make_pair("/", TableItem(1,405)));
	tran.insert(make_pair("%", TableItem(1,406)));
	tran.insert(make_pair(")", TableItem(2,45)));
	_parseTable.insert(make_pair(461,tran));
	tran.clear();


	// state 462
	tran.insert(make_pair("||", TableItem(2,37)));
	tran.insert(make_pair("&&", TableItem(2,37)));
	tran.insert(make_pair("|", TableItem(2,37)));
	tran.insert(make_pair("^", TableItem(2,37)));
	tran.insert(make_pair("&", TableItem(2,37)));
	tran.insert(make_pair("<<", TableItem(2,37)));
	tran.insert(make_pair(">>", TableItem(2,37)));
	tran.insert(make_pair("+", TableItem(2,37)));
	tran.insert(make_pair("-", TableItem(2,37)));
	tran.insert(make_pair("*", TableItem(1,404)));
	tran.insert(make_pair("/", TableItem(1,405)));
	tran.insert(make_pair("%", TableItem(1,406)));
	tran.insert(make_pair(")", TableItem(2,37)));
	_parseTable.insert(make_pair(462,tran));
	tran.clear();


	// state 463
	tran.insert(make_pair("||", TableItem(2,38)));
	tran.insert(make_pair("&&", TableItem(2,38)));
	tran.insert(make_pair("|", TableItem(2,38)));
	tran.insert(make_pair("^", TableItem(2,38)));
	tran.insert(make_pair("&", TableItem(2,38)));
	tran.insert(make_pair("<<", TableItem(2,38)));
	tran.insert(make_pair(">>", TableItem(2,38)));
	tran.insert(make_pair("+", TableItem(2,38)));
	tran.insert(make_pair("-", TableItem(2,38)));
	tran.insert(make_pair("*", TableItem(1,404)));
	tran.insert(make_pair("/", TableItem(1,405)));
	tran.insert(make_pair("%", TableItem(1,406)));
	tran.insert(make_pair(")", TableItem(2,38)));
	_parseTable.insert(make_pair(463,tran));
	tran.clear();


	// state 464
	tran.insert(make_pair("||", TableItem(2,39)));
	tran.insert(make_pair("&&", TableItem(2,39)));
	tran.insert(make_pair("|", TableItem(2,39)));
	tran.insert(make_pair("^", TableItem(2,39)));
	tran.insert(make_pair("&", TableItem(2,39)));
	tran.insert(make_pair("<<", TableItem(2,39)));
	tran.insert(make_pair(">>", TableItem(2,39)));
	tran.insert(make_pair("+", TableItem(2,39)));
	tran.insert(make_pair("-", TableItem(2,39)));
	tran.insert(make_pair("*", TableItem(2,39)));
	tran.insert(make_pair("/", TableItem(2,39)));
	tran.insert(make_pair("%", TableItem(2,39)));
	tran.insert(make_pair(")", TableItem(2,39)));
	_parseTable.insert(make_pair(464,tran));
	tran.clear();


	// state 465
	tran.insert(make_pair("||", TableItem(2,40)));
	tran.insert(make_pair("&&", TableItem(2,40)));
	tran.insert(make_pair("|", TableItem(2,40)));
	tran.insert(make_pair("^", TableItem(2,40)));
	tran.insert(make_pair("&", TableItem(2,40)));
	tran.insert(make_pair("<<", TableItem(2,40)));
	tran.insert(make_pair(">>", TableItem(2,40)));
	tran.insert(make_pair("+", TableItem(2,40)));
	tran.insert(make_pair("-", TableItem(2,40)));
	tran.insert(make_pair("*", TableItem(2,40)));
	tran.insert(make_pair("/", TableItem(2,40)));
	tran.insert(make_pair("%", TableItem(2,40)));
	tran.insert(make_pair(")", TableItem(2,40)));
	_parseTable.insert(make_pair(465,tran));
	tran.clear();


	// state 466
	tran.insert(make_pair("||", TableItem(2,41)));
	tran.insert(make_pair("&&", TableItem(2,41)));
	tran.insert(make_pair("|", TableItem(2,41)));
	tran.insert(make_pair("^", TableItem(2,41)));
	tran.insert(make_pair("&", TableItem(2,41)));
	tran.insert(make_pair("<<", TableItem(2,41)));
	tran.insert(make_pair(">>", TableItem(2,41)));
	tran.insert(make_pair("+", TableItem(2,41)));
	tran.insert(make_pair("-", TableItem(2,41)));
	tran.insert(make_pair("*", TableItem(2,41)));
	tran.insert(make_pair("/", TableItem(2,41)));
	tran.insert(make_pair("%", TableItem(2,41)));
	tran.insert(make_pair(")", TableItem(2,41)));
	_parseTable.insert(make_pair(466,tran));
	tran.clear();


	// state 467
	tran.insert(make_pair("||", TableItem(2,47)));
	tran.insert(make_pair("&&", TableItem(2,47)));
	tran.insert(make_pair("|", TableItem(2,47)));
	tran.insert(make_pair("^", TableItem(2,47)));
	tran.insert(make_pair("&", TableItem(2,47)));
	tran.insert(make_pair("<<", TableItem(2,47)));
	tran.insert(make_pair(">>", TableItem(2,47)));
	tran.insert(make_pair("+", TableItem(2,47)));
	tran.insert(make_pair("-", TableItem(2,47)));
	tran.insert(make_pair("*", TableItem(2,47)));
	tran.insert(make_pair("/", TableItem(2,47)));
	tran.insert(make_pair("%", TableItem(2,47)));
	tran.insert(make_pair(")", TableItem(2,47)));
	_parseTable.insert(make_pair(467,tran));
	tran.clear();


	// state 468
	tran.insert(make_pair(",", TableItem(1,226)));
	tran.insert(make_pair(")", TableItem(1,505)));
	_parseTable.insert(make_pair(468,tran));
	tran.clear();


	// state 469
	tran.insert(make_pair("|", TableItem(1,230)));
	tran.insert(make_pair("^", TableItem(1,231)));
	tran.insert(make_pair("&", TableItem(1,232)));
	tran.insert(make_pair("<<", TableItem(1,233)));
	tran.insert(make_pair(">>", TableItem(1,234)));
	tran.insert(make_pair("+", TableItem(1,235)));
	tran.insert(make_pair("-", TableItem(1,236)));
	tran.insert(make_pair("*", TableItem(1,237)));
	tran.insert(make_pair("/", TableItem(1,238)));
	tran.insert(make_pair("%", TableItem(1,239)));
	tran.insert(make_pair("]", TableItem(1,506)));
	_parseTable.insert(make_pair(469,tran));
	tran.clear();


	// state 470
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,507)));
	_parseTable.insert(make_pair(470,tran));
	tran.clear();


	// state 471
	tran.insert(make_pair("else", TableItem(1,508)));
	_parseTable.insert(make_pair(471,tran));
	tran.clear();


	// state 472
	tran.insert(make_pair("M", TableItem(3,71)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair("}", TableItem(1,509)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(472,tran));
	tran.clear();


	// state 473
	tran.insert(make_pair("else", TableItem(2,9)));
	tran.insert(make_pair("{", TableItem(2,9)));
	tran.insert(make_pair(";", TableItem(2,9)));
	tran.insert(make_pair("static", TableItem(2,9)));
	tran.insert(make_pair("return", TableItem(2,9)));
	tran.insert(make_pair("set_mem", TableItem(2,9)));
	tran.insert(make_pair("include", TableItem(2,9)));
	tran.insert(make_pair("id", TableItem(2,9)));
	tran.insert(make_pair("int", TableItem(2,9)));
	tran.insert(make_pair("double", TableItem(2,9)));
	tran.insert(make_pair("void", TableItem(2,9)));
	tran.insert(make_pair("char", TableItem(2,9)));
	tran.insert(make_pair("bool", TableItem(2,9)));
	tran.insert(make_pair("float", TableItem(2,9)));
	tran.insert(make_pair("if", TableItem(2,9)));
	tran.insert(make_pair("while", TableItem(2,9)));
	tran.insert(make_pair("$", TableItem(2,9)));
	_parseTable.insert(make_pair(473,tran));
	tran.clear();


	// state 474
	tran.insert(make_pair(";", TableItem(1,510)));
	_parseTable.insert(make_pair(474,tran));
	tran.clear();


	// state 475
	tran.insert(make_pair("else", TableItem(2,11)));
	tran.insert(make_pair("{", TableItem(2,11)));
	tran.insert(make_pair(";", TableItem(2,11)));
	tran.insert(make_pair("static", TableItem(2,11)));
	tran.insert(make_pair("return", TableItem(2,11)));
	tran.insert(make_pair("set_mem", TableItem(2,11)));
	tran.insert(make_pair("include", TableItem(2,11)));
	tran.insert(make_pair("id", TableItem(2,11)));
	tran.insert(make_pair("int", TableItem(2,11)));
	tran.insert(make_pair("double", TableItem(2,11)));
	tran.insert(make_pair("void", TableItem(2,11)));
	tran.insert(make_pair("char", TableItem(2,11)));
	tran.insert(make_pair("bool", TableItem(2,11)));
	tran.insert(make_pair("float", TableItem(2,11)));
	tran.insert(make_pair("if", TableItem(2,11)));
	tran.insert(make_pair("while", TableItem(2,11)));
	tran.insert(make_pair("$", TableItem(2,11)));
	_parseTable.insert(make_pair(475,tran));
	tran.clear();


	// state 476
	tran.insert(make_pair("else", TableItem(2,13)));
	tran.insert(make_pair("{", TableItem(2,13)));
	tran.insert(make_pair(";", TableItem(2,13)));
	tran.insert(make_pair("static", TableItem(2,13)));
	tran.insert(make_pair("return", TableItem(2,13)));
	tran.insert(make_pair("set_mem", TableItem(2,13)));
	tran.insert(make_pair("include", TableItem(2,13)));
	tran.insert(make_pair("id", TableItem(2,13)));
	tran.insert(make_pair("int", TableItem(2,13)));
	tran.insert(make_pair("double", TableItem(2,13)));
	tran.insert(make_pair("void", TableItem(2,13)));
	tran.insert(make_pair("char", TableItem(2,13)));
	tran.insert(make_pair("bool", TableItem(2,13)));
	tran.insert(make_pair("float", TableItem(2,13)));
	tran.insert(make_pair("if", TableItem(2,13)));
	tran.insert(make_pair("while", TableItem(2,13)));
	tran.insert(make_pair("$", TableItem(2,13)));
	_parseTable.insert(make_pair(476,tran));
	tran.clear();


	// state 477
	tran.insert(make_pair("|", TableItem(1,90)));
	tran.insert(make_pair("^", TableItem(1,91)));
	tran.insert(make_pair("&", TableItem(1,92)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(1,511)));
	_parseTable.insert(make_pair(477,tran));
	tran.clear();


	// state 478
	tran.insert(make_pair("else", TableItem(2,14)));
	tran.insert(make_pair("{", TableItem(2,14)));
	tran.insert(make_pair(";", TableItem(2,14)));
	tran.insert(make_pair("static", TableItem(2,14)));
	tran.insert(make_pair("return", TableItem(2,14)));
	tran.insert(make_pair("set_mem", TableItem(2,14)));
	tran.insert(make_pair("include", TableItem(2,14)));
	tran.insert(make_pair("id", TableItem(2,14)));
	tran.insert(make_pair("int", TableItem(2,14)));
	tran.insert(make_pair("double", TableItem(2,14)));
	tran.insert(make_pair("void", TableItem(2,14)));
	tran.insert(make_pair("char", TableItem(2,14)));
	tran.insert(make_pair("bool", TableItem(2,14)));
	tran.insert(make_pair("float", TableItem(2,14)));
	tran.insert(make_pair("if", TableItem(2,14)));
	tran.insert(make_pair("while", TableItem(2,14)));
	tran.insert(make_pair("$", TableItem(2,14)));
	_parseTable.insert(make_pair(478,tran));
	tran.clear();


	// state 479
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,512)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(479,tran));
	tran.clear();


	// state 480
	tran.insert(make_pair("filename", TableItem(1,513)));
	_parseTable.insert(make_pair(480,tran));
	tran.clear();


	// state 481
	tran.insert(make_pair("filename", TableItem(1,514)));
	_parseTable.insert(make_pair(481,tran));
	tran.clear();


	// state 482
	tran.insert(make_pair("{", TableItem(1,515)));
	_parseTable.insert(make_pair(482,tran));
	tran.clear();


	// state 483
	tran.insert(make_pair("=", TableItem(1,119)));
	tran.insert(make_pair(";", TableItem(2,26)));
	tran.insert(make_pair("(", TableItem(1,516)));
	tran.insert(make_pair("[", TableItem(1,121)));
	_parseTable.insert(make_pair(483,tran));
	tran.clear();


	// state 484
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,517)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(484,tran));
	tran.clear();


	// state 485
	tran.insert(make_pair("(", TableItem(1,518)));
	_parseTable.insert(make_pair(485,tran));
	tran.clear();


	// state 486
	tran.insert(make_pair("{", TableItem(2,60)));
	tran.insert(make_pair(";", TableItem(2,60)));
	tran.insert(make_pair("static", TableItem(2,60)));
	tran.insert(make_pair("return", TableItem(2,60)));
	tran.insert(make_pair("set_mem", TableItem(2,60)));
	tran.insert(make_pair("include", TableItem(2,60)));
	tran.insert(make_pair("id", TableItem(2,60)));
	tran.insert(make_pair("int", TableItem(2,60)));
	tran.insert(make_pair("double", TableItem(2,60)));
	tran.insert(make_pair("void", TableItem(2,60)));
	tran.insert(make_pair("char", TableItem(2,60)));
	tran.insert(make_pair("bool", TableItem(2,60)));
	tran.insert(make_pair("float", TableItem(2,60)));
	tran.insert(make_pair("if", TableItem(2,60)));
	tran.insert(make_pair("while", TableItem(2,60)));
	tran.insert(make_pair("$", TableItem(2,60)));
	_parseTable.insert(make_pair(486,tran));
	tran.clear();


	// state 487
	tran.insert(make_pair("{", TableItem(2,15)));
	tran.insert(make_pair("}", TableItem(2,15)));
	tran.insert(make_pair(";", TableItem(2,15)));
	tran.insert(make_pair("static", TableItem(2,15)));
	tran.insert(make_pair("return", TableItem(2,15)));
	tran.insert(make_pair("set_mem", TableItem(2,15)));
	tran.insert(make_pair("include", TableItem(2,15)));
	tran.insert(make_pair("id", TableItem(2,15)));
	tran.insert(make_pair("int", TableItem(2,15)));
	tran.insert(make_pair("double", TableItem(2,15)));
	tran.insert(make_pair("void", TableItem(2,15)));
	tran.insert(make_pair("char", TableItem(2,15)));
	tran.insert(make_pair("bool", TableItem(2,15)));
	tran.insert(make_pair("float", TableItem(2,15)));
	tran.insert(make_pair("if", TableItem(2,15)));
	tran.insert(make_pair("while", TableItem(2,15)));
	_parseTable.insert(make_pair(487,tran));
	tran.clear();


	// state 488
	tran.insert(make_pair("else", TableItem(1,519)));
	_parseTable.insert(make_pair(488,tran));
	tran.clear();


	// state 489
	tran.insert(make_pair("M", TableItem(3,71)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair("}", TableItem(1,520)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(489,tran));
	tran.clear();


	// state 490
	tran.insert(make_pair("else", TableItem(2,9)));
	tran.insert(make_pair("{", TableItem(2,9)));
	tran.insert(make_pair("}", TableItem(2,9)));
	tran.insert(make_pair(";", TableItem(2,9)));
	tran.insert(make_pair("static", TableItem(2,9)));
	tran.insert(make_pair("return", TableItem(2,9)));
	tran.insert(make_pair("set_mem", TableItem(2,9)));
	tran.insert(make_pair("include", TableItem(2,9)));
	tran.insert(make_pair("id", TableItem(2,9)));
	tran.insert(make_pair("int", TableItem(2,9)));
	tran.insert(make_pair("double", TableItem(2,9)));
	tran.insert(make_pair("void", TableItem(2,9)));
	tran.insert(make_pair("char", TableItem(2,9)));
	tran.insert(make_pair("bool", TableItem(2,9)));
	tran.insert(make_pair("float", TableItem(2,9)));
	tran.insert(make_pair("if", TableItem(2,9)));
	tran.insert(make_pair("while", TableItem(2,9)));
	_parseTable.insert(make_pair(490,tran));
	tran.clear();


	// state 491
	tran.insert(make_pair(";", TableItem(1,521)));
	_parseTable.insert(make_pair(491,tran));
	tran.clear();


	// state 492
	tran.insert(make_pair("else", TableItem(2,11)));
	tran.insert(make_pair("{", TableItem(2,11)));
	tran.insert(make_pair("}", TableItem(2,11)));
	tran.insert(make_pair(";", TableItem(2,11)));
	tran.insert(make_pair("static", TableItem(2,11)));
	tran.insert(make_pair("return", TableItem(2,11)));
	tran.insert(make_pair("set_mem", TableItem(2,11)));
	tran.insert(make_pair("include", TableItem(2,11)));
	tran.insert(make_pair("id", TableItem(2,11)));
	tran.insert(make_pair("int", TableItem(2,11)));
	tran.insert(make_pair("double", TableItem(2,11)));
	tran.insert(make_pair("void", TableItem(2,11)));
	tran.insert(make_pair("char", TableItem(2,11)));
	tran.insert(make_pair("bool", TableItem(2,11)));
	tran.insert(make_pair("float", TableItem(2,11)));
	tran.insert(make_pair("if", TableItem(2,11)));
	tran.insert(make_pair("while", TableItem(2,11)));
	_parseTable.insert(make_pair(492,tran));
	tran.clear();


	// state 493
	tran.insert(make_pair("else", TableItem(2,13)));
	tran.insert(make_pair("{", TableItem(2,13)));
	tran.insert(make_pair("}", TableItem(2,13)));
	tran.insert(make_pair(";", TableItem(2,13)));
	tran.insert(make_pair("static", TableItem(2,13)));
	tran.insert(make_pair("return", TableItem(2,13)));
	tran.insert(make_pair("set_mem", TableItem(2,13)));
	tran.insert(make_pair("include", TableItem(2,13)));
	tran.insert(make_pair("id", TableItem(2,13)));
	tran.insert(make_pair("int", TableItem(2,13)));
	tran.insert(make_pair("double", TableItem(2,13)));
	tran.insert(make_pair("void", TableItem(2,13)));
	tran.insert(make_pair("char", TableItem(2,13)));
	tran.insert(make_pair("bool", TableItem(2,13)));
	tran.insert(make_pair("float", TableItem(2,13)));
	tran.insert(make_pair("if", TableItem(2,13)));
	tran.insert(make_pair("while", TableItem(2,13)));
	_parseTable.insert(make_pair(493,tran));
	tran.clear();


	// state 494
	tran.insert(make_pair("|", TableItem(1,90)));
	tran.insert(make_pair("^", TableItem(1,91)));
	tran.insert(make_pair("&", TableItem(1,92)));
	tran.insert(make_pair("<<", TableItem(1,93)));
	tran.insert(make_pair(">>", TableItem(1,94)));
	tran.insert(make_pair("+", TableItem(1,95)));
	tran.insert(make_pair("-", TableItem(1,96)));
	tran.insert(make_pair("*", TableItem(1,97)));
	tran.insert(make_pair("/", TableItem(1,98)));
	tran.insert(make_pair("%", TableItem(1,99)));
	tran.insert(make_pair(";", TableItem(1,522)));
	_parseTable.insert(make_pair(494,tran));
	tran.clear();


	// state 495
	tran.insert(make_pair("else", TableItem(2,14)));
	tran.insert(make_pair("{", TableItem(2,14)));
	tran.insert(make_pair("}", TableItem(2,14)));
	tran.insert(make_pair(";", TableItem(2,14)));
	tran.insert(make_pair("static", TableItem(2,14)));
	tran.insert(make_pair("return", TableItem(2,14)));
	tran.insert(make_pair("set_mem", TableItem(2,14)));
	tran.insert(make_pair("include", TableItem(2,14)));
	tran.insert(make_pair("id", TableItem(2,14)));
	tran.insert(make_pair("int", TableItem(2,14)));
	tran.insert(make_pair("double", TableItem(2,14)));
	tran.insert(make_pair("void", TableItem(2,14)));
	tran.insert(make_pair("char", TableItem(2,14)));
	tran.insert(make_pair("bool", TableItem(2,14)));
	tran.insert(make_pair("float", TableItem(2,14)));
	tran.insert(make_pair("if", TableItem(2,14)));
	tran.insert(make_pair("while", TableItem(2,14)));
	_parseTable.insert(make_pair(495,tran));
	tran.clear();


	// state 496
	tran.insert(make_pair("-", TableItem(1,110)));
	tran.insert(make_pair("expr", TableItem(3,523)));
	tran.insert(make_pair("(", TableItem(1,112)));
	tran.insert(make_pair("id", TableItem(1,113)));
	tran.insert(make_pair("num", TableItem(1,114)));
	tran.insert(make_pair("load_mem", TableItem(1,115)));
	_parseTable.insert(make_pair(496,tran));
	tran.clear();


	// state 497
	tran.insert(make_pair("filename", TableItem(1,524)));
	_parseTable.insert(make_pair(497,tran));
	tran.clear();


	// state 498
	tran.insert(make_pair("filename", TableItem(1,525)));
	_parseTable.insert(make_pair(498,tran));
	tran.clear();


	// state 499
	tran.insert(make_pair("{", TableItem(1,526)));
	_parseTable.insert(make_pair(499,tran));
	tran.clear();


	// state 500
	tran.insert(make_pair("=", TableItem(1,119)));
	tran.insert(make_pair(";", TableItem(2,26)));
	tran.insert(make_pair("(", TableItem(1,527)));
	tran.insert(make_pair("[", TableItem(1,121)));
	_parseTable.insert(make_pair(500,tran));
	tran.clear();


	// state 501
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,528)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(501,tran));
	tran.clear();


	// state 502
	tran.insert(make_pair("(", TableItem(1,529)));
	_parseTable.insert(make_pair(502,tran));
	tran.clear();


	// state 503
	tran.insert(make_pair("{", TableItem(2,60)));
	tran.insert(make_pair("}", TableItem(2,60)));
	tran.insert(make_pair(";", TableItem(2,60)));
	tran.insert(make_pair("static", TableItem(2,60)));
	tran.insert(make_pair("return", TableItem(2,60)));
	tran.insert(make_pair("set_mem", TableItem(2,60)));
	tran.insert(make_pair("include", TableItem(2,60)));
	tran.insert(make_pair("id", TableItem(2,60)));
	tran.insert(make_pair("int", TableItem(2,60)));
	tran.insert(make_pair("double", TableItem(2,60)));
	tran.insert(make_pair("void", TableItem(2,60)));
	tran.insert(make_pair("char", TableItem(2,60)));
	tran.insert(make_pair("bool", TableItem(2,60)));
	tran.insert(make_pair("float", TableItem(2,60)));
	tran.insert(make_pair("if", TableItem(2,60)));
	tran.insert(make_pair("while", TableItem(2,60)));
	_parseTable.insert(make_pair(503,tran));
	tran.clear();


	// state 504
	tran.insert(make_pair(",", TableItem(2,25)));
	tran.insert(make_pair(")", TableItem(2,25)));
	_parseTable.insert(make_pair(504,tran));
	tran.clear();


	// state 505
	tran.insert(make_pair("||", TableItem(2,49)));
	tran.insert(make_pair("&&", TableItem(2,49)));
	tran.insert(make_pair("|", TableItem(2,49)));
	tran.insert(make_pair("^", TableItem(2,49)));
	tran.insert(make_pair("&", TableItem(2,49)));
	tran.insert(make_pair("<<", TableItem(2,49)));
	tran.insert(make_pair(">>", TableItem(2,49)));
	tran.insert(make_pair("+", TableItem(2,49)));
	tran.insert(make_pair("-", TableItem(2,49)));
	tran.insert(make_pair("*", TableItem(2,49)));
	tran.insert(make_pair("/", TableItem(2,49)));
	tran.insert(make_pair("%", TableItem(2,49)));
	tran.insert(make_pair(")", TableItem(2,49)));
	_parseTable.insert(make_pair(505,tran));
	tran.clear();


	// state 506
	tran.insert(make_pair("||", TableItem(2,52)));
	tran.insert(make_pair("&&", TableItem(2,52)));
	tran.insert(make_pair("|", TableItem(2,52)));
	tran.insert(make_pair("^", TableItem(2,52)));
	tran.insert(make_pair("&", TableItem(2,52)));
	tran.insert(make_pair("<<", TableItem(2,52)));
	tran.insert(make_pair(">>", TableItem(2,52)));
	tran.insert(make_pair("+", TableItem(2,52)));
	tran.insert(make_pair("-", TableItem(2,52)));
	tran.insert(make_pair("*", TableItem(2,52)));
	tran.insert(make_pair("/", TableItem(2,52)));
	tran.insert(make_pair("%", TableItem(2,52)));
	tran.insert(make_pair(")", TableItem(2,52)));
	_parseTable.insert(make_pair(506,tran));
	tran.clear();


	// state 507
	tran.insert(make_pair("||", TableItem(2,53)));
	tran.insert(make_pair("&&", TableItem(2,53)));
	tran.insert(make_pair("|", TableItem(2,53)));
	tran.insert(make_pair("^", TableItem(2,53)));
	tran.insert(make_pair("&", TableItem(2,53)));
	tran.insert(make_pair("<<", TableItem(2,53)));
	tran.insert(make_pair(">>", TableItem(2,53)));
	tran.insert(make_pair("+", TableItem(2,53)));
	tran.insert(make_pair("-", TableItem(2,53)));
	tran.insert(make_pair("*", TableItem(2,53)));
	tran.insert(make_pair("/", TableItem(2,53)));
	tran.insert(make_pair("%", TableItem(2,53)));
	tran.insert(make_pair(")", TableItem(2,53)));
	_parseTable.insert(make_pair(507,tran));
	tran.clear();


	// state 508
	tran.insert(make_pair("M", TableItem(3,530)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(508,tran));
	tran.clear();


	// state 509
	tran.insert(make_pair("else", TableItem(2,5)));
	tran.insert(make_pair("{", TableItem(2,5)));
	tran.insert(make_pair(";", TableItem(2,5)));
	tran.insert(make_pair("static", TableItem(2,5)));
	tran.insert(make_pair("return", TableItem(2,5)));
	tran.insert(make_pair("set_mem", TableItem(2,5)));
	tran.insert(make_pair("include", TableItem(2,5)));
	tran.insert(make_pair("id", TableItem(2,5)));
	tran.insert(make_pair("int", TableItem(2,5)));
	tran.insert(make_pair("double", TableItem(2,5)));
	tran.insert(make_pair("void", TableItem(2,5)));
	tran.insert(make_pair("char", TableItem(2,5)));
	tran.insert(make_pair("bool", TableItem(2,5)));
	tran.insert(make_pair("float", TableItem(2,5)));
	tran.insert(make_pair("if", TableItem(2,5)));
	tran.insert(make_pair("while", TableItem(2,5)));
	tran.insert(make_pair("$", TableItem(2,5)));
	_parseTable.insert(make_pair(509,tran));
	tran.clear();


	// state 510
	tran.insert(make_pair("else", TableItem(2,10)));
	tran.insert(make_pair("{", TableItem(2,10)));
	tran.insert(make_pair(";", TableItem(2,10)));
	tran.insert(make_pair("static", TableItem(2,10)));
	tran.insert(make_pair("return", TableItem(2,10)));
	tran.insert(make_pair("set_mem", TableItem(2,10)));
	tran.insert(make_pair("include", TableItem(2,10)));
	tran.insert(make_pair("id", TableItem(2,10)));
	tran.insert(make_pair("int", TableItem(2,10)));
	tran.insert(make_pair("double", TableItem(2,10)));
	tran.insert(make_pair("void", TableItem(2,10)));
	tran.insert(make_pair("char", TableItem(2,10)));
	tran.insert(make_pair("bool", TableItem(2,10)));
	tran.insert(make_pair("float", TableItem(2,10)));
	tran.insert(make_pair("if", TableItem(2,10)));
	tran.insert(make_pair("while", TableItem(2,10)));
	tran.insert(make_pair("$", TableItem(2,10)));
	_parseTable.insert(make_pair(510,tran));
	tran.clear();


	// state 511
	tran.insert(make_pair("else", TableItem(2,12)));
	tran.insert(make_pair("{", TableItem(2,12)));
	tran.insert(make_pair(";", TableItem(2,12)));
	tran.insert(make_pair("static", TableItem(2,12)));
	tran.insert(make_pair("return", TableItem(2,12)));
	tran.insert(make_pair("set_mem", TableItem(2,12)));
	tran.insert(make_pair("include", TableItem(2,12)));
	tran.insert(make_pair("id", TableItem(2,12)));
	tran.insert(make_pair("int", TableItem(2,12)));
	tran.insert(make_pair("double", TableItem(2,12)));
	tran.insert(make_pair("void", TableItem(2,12)));
	tran.insert(make_pair("char", TableItem(2,12)));
	tran.insert(make_pair("bool", TableItem(2,12)));
	tran.insert(make_pair("float", TableItem(2,12)));
	tran.insert(make_pair("if", TableItem(2,12)));
	tran.insert(make_pair("while", TableItem(2,12)));
	tran.insert(make_pair("$", TableItem(2,12)));
	_parseTable.insert(make_pair(511,tran));
	tran.clear();


	// state 512
	tran.insert(make_pair("|", TableItem(1,188)));
	tran.insert(make_pair("^", TableItem(1,189)));
	tran.insert(make_pair("&", TableItem(1,190)));
	tran.insert(make_pair("<<", TableItem(1,191)));
	tran.insert(make_pair(">>", TableItem(1,192)));
	tran.insert(make_pair("+", TableItem(1,193)));
	tran.insert(make_pair("-", TableItem(1,194)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(1,531)));
	_parseTable.insert(make_pair(512,tran));
	tran.clear();


	// state 513
	tran.insert(make_pair(">", TableItem(1,532)));
	_parseTable.insert(make_pair(513,tran));
	tran.clear();


	// state 514
	tran.insert(make_pair("\"", TableItem(1,533)));
	_parseTable.insert(make_pair(514,tran));
	tran.clear();


	// state 515
	tran.insert(make_pair("stmts", TableItem(3,534)));
	tran.insert(make_pair("stmt", TableItem(3,30)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(515,tran));
	tran.clear();


	// state 516
	tran.insert(make_pair(")", TableItem(1,535)));
	tran.insert(make_pair("type_spec", TableItem(3,208)));
	tran.insert(make_pair("param_list", TableItem(3,536)));
	tran.insert(make_pair("param", TableItem(3,210)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	_parseTable.insert(make_pair(516,tran));
	tran.clear();


	// state 517
	tran.insert(make_pair("||", TableItem(1,270)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(1,537)));
	_parseTable.insert(make_pair(517,tran));
	tran.clear();


	// state 518
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,538)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(518,tran));
	tran.clear();


	// state 519
	tran.insert(make_pair("M", TableItem(3,539)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(519,tran));
	tran.clear();


	// state 520
	tran.insert(make_pair("else", TableItem(2,5)));
	tran.insert(make_pair("{", TableItem(2,5)));
	tran.insert(make_pair("}", TableItem(2,5)));
	tran.insert(make_pair(";", TableItem(2,5)));
	tran.insert(make_pair("static", TableItem(2,5)));
	tran.insert(make_pair("return", TableItem(2,5)));
	tran.insert(make_pair("set_mem", TableItem(2,5)));
	tran.insert(make_pair("include", TableItem(2,5)));
	tran.insert(make_pair("id", TableItem(2,5)));
	tran.insert(make_pair("int", TableItem(2,5)));
	tran.insert(make_pair("double", TableItem(2,5)));
	tran.insert(make_pair("void", TableItem(2,5)));
	tran.insert(make_pair("char", TableItem(2,5)));
	tran.insert(make_pair("bool", TableItem(2,5)));
	tran.insert(make_pair("float", TableItem(2,5)));
	tran.insert(make_pair("if", TableItem(2,5)));
	tran.insert(make_pair("while", TableItem(2,5)));
	_parseTable.insert(make_pair(520,tran));
	tran.clear();


	// state 521
	tran.insert(make_pair("else", TableItem(2,10)));
	tran.insert(make_pair("{", TableItem(2,10)));
	tran.insert(make_pair("}", TableItem(2,10)));
	tran.insert(make_pair(";", TableItem(2,10)));
	tran.insert(make_pair("static", TableItem(2,10)));
	tran.insert(make_pair("return", TableItem(2,10)));
	tran.insert(make_pair("set_mem", TableItem(2,10)));
	tran.insert(make_pair("include", TableItem(2,10)));
	tran.insert(make_pair("id", TableItem(2,10)));
	tran.insert(make_pair("int", TableItem(2,10)));
	tran.insert(make_pair("double", TableItem(2,10)));
	tran.insert(make_pair("void", TableItem(2,10)));
	tran.insert(make_pair("char", TableItem(2,10)));
	tran.insert(make_pair("bool", TableItem(2,10)));
	tran.insert(make_pair("float", TableItem(2,10)));
	tran.insert(make_pair("if", TableItem(2,10)));
	tran.insert(make_pair("while", TableItem(2,10)));
	_parseTable.insert(make_pair(521,tran));
	tran.clear();


	// state 522
	tran.insert(make_pair("else", TableItem(2,12)));
	tran.insert(make_pair("{", TableItem(2,12)));
	tran.insert(make_pair("}", TableItem(2,12)));
	tran.insert(make_pair(";", TableItem(2,12)));
	tran.insert(make_pair("static", TableItem(2,12)));
	tran.insert(make_pair("return", TableItem(2,12)));
	tran.insert(make_pair("set_mem", TableItem(2,12)));
	tran.insert(make_pair("include", TableItem(2,12)));
	tran.insert(make_pair("id", TableItem(2,12)));
	tran.insert(make_pair("int", TableItem(2,12)));
	tran.insert(make_pair("double", TableItem(2,12)));
	tran.insert(make_pair("void", TableItem(2,12)));
	tran.insert(make_pair("char", TableItem(2,12)));
	tran.insert(make_pair("bool", TableItem(2,12)));
	tran.insert(make_pair("float", TableItem(2,12)));
	tran.insert(make_pair("if", TableItem(2,12)));
	tran.insert(make_pair("while", TableItem(2,12)));
	_parseTable.insert(make_pair(522,tran));
	tran.clear();


	// state 523
	tran.insert(make_pair("|", TableItem(1,188)));
	tran.insert(make_pair("^", TableItem(1,189)));
	tran.insert(make_pair("&", TableItem(1,190)));
	tran.insert(make_pair("<<", TableItem(1,191)));
	tran.insert(make_pair(">>", TableItem(1,192)));
	tran.insert(make_pair("+", TableItem(1,193)));
	tran.insert(make_pair("-", TableItem(1,194)));
	tran.insert(make_pair("*", TableItem(1,195)));
	tran.insert(make_pair("/", TableItem(1,196)));
	tran.insert(make_pair("%", TableItem(1,197)));
	tran.insert(make_pair(",", TableItem(1,540)));
	_parseTable.insert(make_pair(523,tran));
	tran.clear();


	// state 524
	tran.insert(make_pair(">", TableItem(1,541)));
	_parseTable.insert(make_pair(524,tran));
	tran.clear();


	// state 525
	tran.insert(make_pair("\"", TableItem(1,542)));
	_parseTable.insert(make_pair(525,tran));
	tran.clear();


	// state 526
	tran.insert(make_pair("stmts", TableItem(3,543)));
	tran.insert(make_pair("stmt", TableItem(3,30)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(526,tran));
	tran.clear();


	// state 527
	tran.insert(make_pair(")", TableItem(1,544)));
	tran.insert(make_pair("type_spec", TableItem(3,208)));
	tran.insert(make_pair("param_list", TableItem(3,545)));
	tran.insert(make_pair("param", TableItem(3,210)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	_parseTable.insert(make_pair(527,tran));
	tran.clear();


	// state 528
	tran.insert(make_pair("||", TableItem(1,270)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(1,546)));
	_parseTable.insert(make_pair(528,tran));
	tran.clear();


	// state 529
	tran.insert(make_pair("-", TableItem(1,136)));
	tran.insert(make_pair("!", TableItem(1,137)));
	tran.insert(make_pair("expr", TableItem(3,138)));
	tran.insert(make_pair("(", TableItem(1,139)));
	tran.insert(make_pair("id", TableItem(1,140)));
	tran.insert(make_pair("num", TableItem(1,141)));
	tran.insert(make_pair("load_mem", TableItem(1,142)));
	tran.insert(make_pair("logic_expr", TableItem(3,547)));
	tran.insert(make_pair("true", TableItem(1,144)));
	tran.insert(make_pair("false", TableItem(1,145)));
	_parseTable.insert(make_pair(529,tran));
	tran.clear();


	// state 530
	tran.insert(make_pair("stmt", TableItem(3,548)));
	tran.insert(make_pair("includestmt", TableItem(3,4)));
	tran.insert(make_pair("{", TableItem(1,5)));
	tran.insert(make_pair("fun_define", TableItem(3,6)));
	tran.insert(make_pair("if_stmt", TableItem(3,7)));
	tran.insert(make_pair("while_stmt", TableItem(3,8)));
	tran.insert(make_pair("var_decl", TableItem(3,9)));
	tran.insert(make_pair(";", TableItem(1,10)));
	tran.insert(make_pair("static", TableItem(1,11)));
	tran.insert(make_pair("expr_stmt", TableItem(3,12)));
	tran.insert(make_pair("return", TableItem(1,13)));
	tran.insert(make_pair("call_stmt", TableItem(3,14)));
	tran.insert(make_pair("set_mem", TableItem(1,15)));
	tran.insert(make_pair("include", TableItem(1,16)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,17)));
	tran.insert(make_pair("type_spec", TableItem(3,18)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,26)));
	tran.insert(make_pair("while", TableItem(1,27)));
	_parseTable.insert(make_pair(530,tran));
	tran.clear();


	// state 531
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,549)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(531,tran));
	tran.clear();


	// state 532
	tran.insert(make_pair("else", TableItem(2,18)));
	tran.insert(make_pair("{", TableItem(2,18)));
	tran.insert(make_pair(";", TableItem(2,18)));
	tran.insert(make_pair("static", TableItem(2,18)));
	tran.insert(make_pair("return", TableItem(2,18)));
	tran.insert(make_pair("set_mem", TableItem(2,18)));
	tran.insert(make_pair("include", TableItem(2,18)));
	tran.insert(make_pair("id", TableItem(2,18)));
	tran.insert(make_pair("int", TableItem(2,18)));
	tran.insert(make_pair("double", TableItem(2,18)));
	tran.insert(make_pair("void", TableItem(2,18)));
	tran.insert(make_pair("char", TableItem(2,18)));
	tran.insert(make_pair("bool", TableItem(2,18)));
	tran.insert(make_pair("float", TableItem(2,18)));
	tran.insert(make_pair("if", TableItem(2,18)));
	tran.insert(make_pair("while", TableItem(2,18)));
	tran.insert(make_pair("$", TableItem(2,18)));
	_parseTable.insert(make_pair(532,tran));
	tran.clear();


	// state 533
	tran.insert(make_pair("else", TableItem(2,17)));
	tran.insert(make_pair("{", TableItem(2,17)));
	tran.insert(make_pair(";", TableItem(2,17)));
	tran.insert(make_pair("static", TableItem(2,17)));
	tran.insert(make_pair("return", TableItem(2,17)));
	tran.insert(make_pair("set_mem", TableItem(2,17)));
	tran.insert(make_pair("include", TableItem(2,17)));
	tran.insert(make_pair("id", TableItem(2,17)));
	tran.insert(make_pair("int", TableItem(2,17)));
	tran.insert(make_pair("double", TableItem(2,17)));
	tran.insert(make_pair("void", TableItem(2,17)));
	tran.insert(make_pair("char", TableItem(2,17)));
	tran.insert(make_pair("bool", TableItem(2,17)));
	tran.insert(make_pair("float", TableItem(2,17)));
	tran.insert(make_pair("if", TableItem(2,17)));
	tran.insert(make_pair("while", TableItem(2,17)));
	tran.insert(make_pair("$", TableItem(2,17)));
	_parseTable.insert(make_pair(533,tran));
	tran.clear();


	// state 534
	tran.insert(make_pair("M", TableItem(3,71)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair("}", TableItem(1,550)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(534,tran));
	tran.clear();


	// state 535
	tran.insert(make_pair("else", TableItem(2,20)));
	tran.insert(make_pair("{", TableItem(2,20)));
	tran.insert(make_pair(";", TableItem(2,20)));
	tran.insert(make_pair("static", TableItem(2,20)));
	tran.insert(make_pair("return", TableItem(2,20)));
	tran.insert(make_pair("set_mem", TableItem(2,20)));
	tran.insert(make_pair("include", TableItem(2,20)));
	tran.insert(make_pair("id", TableItem(2,20)));
	tran.insert(make_pair("int", TableItem(2,20)));
	tran.insert(make_pair("double", TableItem(2,20)));
	tran.insert(make_pair("void", TableItem(2,20)));
	tran.insert(make_pair("char", TableItem(2,20)));
	tran.insert(make_pair("bool", TableItem(2,20)));
	tran.insert(make_pair("float", TableItem(2,20)));
	tran.insert(make_pair("if", TableItem(2,20)));
	tran.insert(make_pair("while", TableItem(2,20)));
	tran.insert(make_pair("$", TableItem(2,20)));
	_parseTable.insert(make_pair(535,tran));
	tran.clear();


	// state 536
	tran.insert(make_pair(",", TableItem(1,316)));
	tran.insert(make_pair(")", TableItem(1,551)));
	_parseTable.insert(make_pair(536,tran));
	tran.clear();


	// state 537
	tran.insert(make_pair("M", TableItem(3,552)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(537,tran));
	tran.clear();


	// state 538
	tran.insert(make_pair("||", TableItem(1,270)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(1,553)));
	_parseTable.insert(make_pair(538,tran));
	tran.clear();


	// state 539
	tran.insert(make_pair("stmt", TableItem(3,554)));
	tran.insert(make_pair("includestmt", TableItem(3,31)));
	tran.insert(make_pair("{", TableItem(1,32)));
	tran.insert(make_pair("fun_define", TableItem(3,33)));
	tran.insert(make_pair("if_stmt", TableItem(3,34)));
	tran.insert(make_pair("while_stmt", TableItem(3,35)));
	tran.insert(make_pair("var_decl", TableItem(3,36)));
	tran.insert(make_pair(";", TableItem(1,37)));
	tran.insert(make_pair("static", TableItem(1,38)));
	tran.insert(make_pair("expr_stmt", TableItem(3,39)));
	tran.insert(make_pair("return", TableItem(1,40)));
	tran.insert(make_pair("call_stmt", TableItem(3,41)));
	tran.insert(make_pair("set_mem", TableItem(1,42)));
	tran.insert(make_pair("include", TableItem(1,43)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,44)));
	tran.insert(make_pair("type_spec", TableItem(3,45)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,46)));
	tran.insert(make_pair("while", TableItem(1,47)));
	_parseTable.insert(make_pair(539,tran));
	tran.clear();


	// state 540
	tran.insert(make_pair("-", TableItem(1,101)));
	tran.insert(make_pair("expr", TableItem(3,555)));
	tran.insert(make_pair("(", TableItem(1,103)));
	tran.insert(make_pair("id", TableItem(1,104)));
	tran.insert(make_pair("num", TableItem(1,105)));
	tran.insert(make_pair("load_mem", TableItem(1,106)));
	_parseTable.insert(make_pair(540,tran));
	tran.clear();


	// state 541
	tran.insert(make_pair("else", TableItem(2,18)));
	tran.insert(make_pair("{", TableItem(2,18)));
	tran.insert(make_pair("}", TableItem(2,18)));
	tran.insert(make_pair(";", TableItem(2,18)));
	tran.insert(make_pair("static", TableItem(2,18)));
	tran.insert(make_pair("return", TableItem(2,18)));
	tran.insert(make_pair("set_mem", TableItem(2,18)));
	tran.insert(make_pair("include", TableItem(2,18)));
	tran.insert(make_pair("id", TableItem(2,18)));
	tran.insert(make_pair("int", TableItem(2,18)));
	tran.insert(make_pair("double", TableItem(2,18)));
	tran.insert(make_pair("void", TableItem(2,18)));
	tran.insert(make_pair("char", TableItem(2,18)));
	tran.insert(make_pair("bool", TableItem(2,18)));
	tran.insert(make_pair("float", TableItem(2,18)));
	tran.insert(make_pair("if", TableItem(2,18)));
	tran.insert(make_pair("while", TableItem(2,18)));
	_parseTable.insert(make_pair(541,tran));
	tran.clear();


	// state 542
	tran.insert(make_pair("else", TableItem(2,17)));
	tran.insert(make_pair("{", TableItem(2,17)));
	tran.insert(make_pair("}", TableItem(2,17)));
	tran.insert(make_pair(";", TableItem(2,17)));
	tran.insert(make_pair("static", TableItem(2,17)));
	tran.insert(make_pair("return", TableItem(2,17)));
	tran.insert(make_pair("set_mem", TableItem(2,17)));
	tran.insert(make_pair("include", TableItem(2,17)));
	tran.insert(make_pair("id", TableItem(2,17)));
	tran.insert(make_pair("int", TableItem(2,17)));
	tran.insert(make_pair("double", TableItem(2,17)));
	tran.insert(make_pair("void", TableItem(2,17)));
	tran.insert(make_pair("char", TableItem(2,17)));
	tran.insert(make_pair("bool", TableItem(2,17)));
	tran.insert(make_pair("float", TableItem(2,17)));
	tran.insert(make_pair("if", TableItem(2,17)));
	tran.insert(make_pair("while", TableItem(2,17)));
	_parseTable.insert(make_pair(542,tran));
	tran.clear();


	// state 543
	tran.insert(make_pair("M", TableItem(3,71)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair("}", TableItem(1,556)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(543,tran));
	tran.clear();


	// state 544
	tran.insert(make_pair("else", TableItem(2,20)));
	tran.insert(make_pair("{", TableItem(2,20)));
	tran.insert(make_pair("}", TableItem(2,20)));
	tran.insert(make_pair(";", TableItem(2,20)));
	tran.insert(make_pair("static", TableItem(2,20)));
	tran.insert(make_pair("return", TableItem(2,20)));
	tran.insert(make_pair("set_mem", TableItem(2,20)));
	tran.insert(make_pair("include", TableItem(2,20)));
	tran.insert(make_pair("id", TableItem(2,20)));
	tran.insert(make_pair("int", TableItem(2,20)));
	tran.insert(make_pair("double", TableItem(2,20)));
	tran.insert(make_pair("void", TableItem(2,20)));
	tran.insert(make_pair("char", TableItem(2,20)));
	tran.insert(make_pair("bool", TableItem(2,20)));
	tran.insert(make_pair("float", TableItem(2,20)));
	tran.insert(make_pair("if", TableItem(2,20)));
	tran.insert(make_pair("while", TableItem(2,20)));
	_parseTable.insert(make_pair(544,tran));
	tran.clear();


	// state 545
	tran.insert(make_pair(",", TableItem(1,316)));
	tran.insert(make_pair(")", TableItem(1,557)));
	_parseTable.insert(make_pair(545,tran));
	tran.clear();


	// state 546
	tran.insert(make_pair("M", TableItem(3,558)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(546,tran));
	tran.clear();


	// state 547
	tran.insert(make_pair("||", TableItem(1,270)));
	tran.insert(make_pair("&&", TableItem(1,271)));
	tran.insert(make_pair(")", TableItem(1,559)));
	_parseTable.insert(make_pair(547,tran));
	tran.clear();


	// state 548
	tran.insert(make_pair("{", TableItem(2,59)));
	tran.insert(make_pair(";", TableItem(2,59)));
	tran.insert(make_pair("static", TableItem(2,59)));
	tran.insert(make_pair("return", TableItem(2,59)));
	tran.insert(make_pair("set_mem", TableItem(2,59)));
	tran.insert(make_pair("include", TableItem(2,59)));
	tran.insert(make_pair("id", TableItem(2,59)));
	tran.insert(make_pair("int", TableItem(2,59)));
	tran.insert(make_pair("double", TableItem(2,59)));
	tran.insert(make_pair("void", TableItem(2,59)));
	tran.insert(make_pair("char", TableItem(2,59)));
	tran.insert(make_pair("bool", TableItem(2,59)));
	tran.insert(make_pair("float", TableItem(2,59)));
	tran.insert(make_pair("if", TableItem(2,59)));
	tran.insert(make_pair("while", TableItem(2,59)));
	tran.insert(make_pair("$", TableItem(2,59)));
	_parseTable.insert(make_pair(548,tran));
	tran.clear();


	// state 549
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,560)));
	_parseTable.insert(make_pair(549,tran));
	tran.clear();


	// state 550
	tran.insert(make_pair("else", TableItem(2,19)));
	tran.insert(make_pair("{", TableItem(2,19)));
	tran.insert(make_pair(";", TableItem(2,19)));
	tran.insert(make_pair("static", TableItem(2,19)));
	tran.insert(make_pair("return", TableItem(2,19)));
	tran.insert(make_pair("set_mem", TableItem(2,19)));
	tran.insert(make_pair("include", TableItem(2,19)));
	tran.insert(make_pair("id", TableItem(2,19)));
	tran.insert(make_pair("int", TableItem(2,19)));
	tran.insert(make_pair("double", TableItem(2,19)));
	tran.insert(make_pair("void", TableItem(2,19)));
	tran.insert(make_pair("char", TableItem(2,19)));
	tran.insert(make_pair("bool", TableItem(2,19)));
	tran.insert(make_pair("float", TableItem(2,19)));
	tran.insert(make_pair("if", TableItem(2,19)));
	tran.insert(make_pair("while", TableItem(2,19)));
	tran.insert(make_pair("$", TableItem(2,19)));
	_parseTable.insert(make_pair(550,tran));
	tran.clear();


	// state 551
	tran.insert(make_pair("else", TableItem(2,21)));
	tran.insert(make_pair("{", TableItem(2,21)));
	tran.insert(make_pair(";", TableItem(2,21)));
	tran.insert(make_pair("static", TableItem(2,21)));
	tran.insert(make_pair("return", TableItem(2,21)));
	tran.insert(make_pair("set_mem", TableItem(2,21)));
	tran.insert(make_pair("include", TableItem(2,21)));
	tran.insert(make_pair("id", TableItem(2,21)));
	tran.insert(make_pair("int", TableItem(2,21)));
	tran.insert(make_pair("double", TableItem(2,21)));
	tran.insert(make_pair("void", TableItem(2,21)));
	tran.insert(make_pair("char", TableItem(2,21)));
	tran.insert(make_pair("bool", TableItem(2,21)));
	tran.insert(make_pair("float", TableItem(2,21)));
	tran.insert(make_pair("if", TableItem(2,21)));
	tran.insert(make_pair("while", TableItem(2,21)));
	tran.insert(make_pair("$", TableItem(2,21)));
	_parseTable.insert(make_pair(551,tran));
	tran.clear();


	// state 552
	tran.insert(make_pair("stmt", TableItem(3,561)));
	tran.insert(make_pair("includestmt", TableItem(3,417)));
	tran.insert(make_pair("{", TableItem(1,418)));
	tran.insert(make_pair("fun_define", TableItem(3,419)));
	tran.insert(make_pair("if_stmt", TableItem(3,420)));
	tran.insert(make_pair("while_stmt", TableItem(3,421)));
	tran.insert(make_pair("var_decl", TableItem(3,422)));
	tran.insert(make_pair(";", TableItem(1,423)));
	tran.insert(make_pair("static", TableItem(1,424)));
	tran.insert(make_pair("expr_stmt", TableItem(3,425)));
	tran.insert(make_pair("return", TableItem(1,426)));
	tran.insert(make_pair("call_stmt", TableItem(3,427)));
	tran.insert(make_pair("set_mem", TableItem(1,428)));
	tran.insert(make_pair("include", TableItem(1,429)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,430)));
	tran.insert(make_pair("type_spec", TableItem(3,431)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,432)));
	tran.insert(make_pair("while", TableItem(1,433)));
	_parseTable.insert(make_pair(552,tran));
	tran.clear();


	// state 553
	tran.insert(make_pair("M", TableItem(3,562)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(553,tran));
	tran.clear();


	// state 554
	tran.insert(make_pair("{", TableItem(2,59)));
	tran.insert(make_pair("}", TableItem(2,59)));
	tran.insert(make_pair(";", TableItem(2,59)));
	tran.insert(make_pair("static", TableItem(2,59)));
	tran.insert(make_pair("return", TableItem(2,59)));
	tran.insert(make_pair("set_mem", TableItem(2,59)));
	tran.insert(make_pair("include", TableItem(2,59)));
	tran.insert(make_pair("id", TableItem(2,59)));
	tran.insert(make_pair("int", TableItem(2,59)));
	tran.insert(make_pair("double", TableItem(2,59)));
	tran.insert(make_pair("void", TableItem(2,59)));
	tran.insert(make_pair("char", TableItem(2,59)));
	tran.insert(make_pair("bool", TableItem(2,59)));
	tran.insert(make_pair("float", TableItem(2,59)));
	tran.insert(make_pair("if", TableItem(2,59)));
	tran.insert(make_pair("while", TableItem(2,59)));
	_parseTable.insert(make_pair(554,tran));
	tran.clear();


	// state 555
	tran.insert(make_pair("|", TableItem(1,169)));
	tran.insert(make_pair("^", TableItem(1,170)));
	tran.insert(make_pair("&", TableItem(1,171)));
	tran.insert(make_pair("<<", TableItem(1,172)));
	tran.insert(make_pair(">>", TableItem(1,173)));
	tran.insert(make_pair("+", TableItem(1,174)));
	tran.insert(make_pair("-", TableItem(1,175)));
	tran.insert(make_pair("*", TableItem(1,176)));
	tran.insert(make_pair("/", TableItem(1,177)));
	tran.insert(make_pair("%", TableItem(1,178)));
	tran.insert(make_pair(")", TableItem(1,563)));
	_parseTable.insert(make_pair(555,tran));
	tran.clear();


	// state 556
	tran.insert(make_pair("else", TableItem(2,19)));
	tran.insert(make_pair("{", TableItem(2,19)));
	tran.insert(make_pair("}", TableItem(2,19)));
	tran.insert(make_pair(";", TableItem(2,19)));
	tran.insert(make_pair("static", TableItem(2,19)));
	tran.insert(make_pair("return", TableItem(2,19)));
	tran.insert(make_pair("set_mem", TableItem(2,19)));
	tran.insert(make_pair("include", TableItem(2,19)));
	tran.insert(make_pair("id", TableItem(2,19)));
	tran.insert(make_pair("int", TableItem(2,19)));
	tran.insert(make_pair("double", TableItem(2,19)));
	tran.insert(make_pair("void", TableItem(2,19)));
	tran.insert(make_pair("char", TableItem(2,19)));
	tran.insert(make_pair("bool", TableItem(2,19)));
	tran.insert(make_pair("float", TableItem(2,19)));
	tran.insert(make_pair("if", TableItem(2,19)));
	tran.insert(make_pair("while", TableItem(2,19)));
	_parseTable.insert(make_pair(556,tran));
	tran.clear();


	// state 557
	tran.insert(make_pair("else", TableItem(2,21)));
	tran.insert(make_pair("{", TableItem(2,21)));
	tran.insert(make_pair("}", TableItem(2,21)));
	tran.insert(make_pair(";", TableItem(2,21)));
	tran.insert(make_pair("static", TableItem(2,21)));
	tran.insert(make_pair("return", TableItem(2,21)));
	tran.insert(make_pair("set_mem", TableItem(2,21)));
	tran.insert(make_pair("include", TableItem(2,21)));
	tran.insert(make_pair("id", TableItem(2,21)));
	tran.insert(make_pair("int", TableItem(2,21)));
	tran.insert(make_pair("double", TableItem(2,21)));
	tran.insert(make_pair("void", TableItem(2,21)));
	tran.insert(make_pair("char", TableItem(2,21)));
	tran.insert(make_pair("bool", TableItem(2,21)));
	tran.insert(make_pair("float", TableItem(2,21)));
	tran.insert(make_pair("if", TableItem(2,21)));
	tran.insert(make_pair("while", TableItem(2,21)));
	_parseTable.insert(make_pair(557,tran));
	tran.clear();


	// state 558
	tran.insert(make_pair("stmt", TableItem(3,564)));
	tran.insert(make_pair("includestmt", TableItem(3,437)));
	tran.insert(make_pair("{", TableItem(1,438)));
	tran.insert(make_pair("fun_define", TableItem(3,439)));
	tran.insert(make_pair("if_stmt", TableItem(3,440)));
	tran.insert(make_pair("while_stmt", TableItem(3,441)));
	tran.insert(make_pair("var_decl", TableItem(3,442)));
	tran.insert(make_pair(";", TableItem(1,443)));
	tran.insert(make_pair("static", TableItem(1,444)));
	tran.insert(make_pair("expr_stmt", TableItem(3,445)));
	tran.insert(make_pair("return", TableItem(1,446)));
	tran.insert(make_pair("call_stmt", TableItem(3,447)));
	tran.insert(make_pair("set_mem", TableItem(1,448)));
	tran.insert(make_pair("include", TableItem(1,449)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,450)));
	tran.insert(make_pair("type_spec", TableItem(3,451)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,452)));
	tran.insert(make_pair("while", TableItem(1,453)));
	_parseTable.insert(make_pair(558,tran));
	tran.clear();


	// state 559
	tran.insert(make_pair("M", TableItem(3,565)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(559,tran));
	tran.clear();


	// state 560
	tran.insert(make_pair(";", TableItem(1,566)));
	_parseTable.insert(make_pair(560,tran));
	tran.clear();


	// state 561
	tran.insert(make_pair("else", TableItem(2,58)));
	tran.insert(make_pair("{", TableItem(2,58)));
	tran.insert(make_pair(";", TableItem(2,58)));
	tran.insert(make_pair("static", TableItem(2,58)));
	tran.insert(make_pair("return", TableItem(2,58)));
	tran.insert(make_pair("set_mem", TableItem(2,58)));
	tran.insert(make_pair("include", TableItem(2,58)));
	tran.insert(make_pair("id", TableItem(2,58)));
	tran.insert(make_pair("int", TableItem(2,58)));
	tran.insert(make_pair("double", TableItem(2,58)));
	tran.insert(make_pair("void", TableItem(2,58)));
	tran.insert(make_pair("char", TableItem(2,58)));
	tran.insert(make_pair("bool", TableItem(2,58)));
	tran.insert(make_pair("float", TableItem(2,58)));
	tran.insert(make_pair("if", TableItem(2,58)));
	tran.insert(make_pair("N", TableItem(3,567)));
	tran.insert(make_pair("while", TableItem(2,58)));
	tran.insert(make_pair("$", TableItem(2,58)));
	_parseTable.insert(make_pair(561,tran));
	tran.clear();


	// state 562
	tran.insert(make_pair("stmt", TableItem(3,568)));
	tran.insert(make_pair("includestmt", TableItem(3,417)));
	tran.insert(make_pair("{", TableItem(1,418)));
	tran.insert(make_pair("fun_define", TableItem(3,419)));
	tran.insert(make_pair("if_stmt", TableItem(3,420)));
	tran.insert(make_pair("while_stmt", TableItem(3,421)));
	tran.insert(make_pair("var_decl", TableItem(3,422)));
	tran.insert(make_pair(";", TableItem(1,423)));
	tran.insert(make_pair("static", TableItem(1,424)));
	tran.insert(make_pair("expr_stmt", TableItem(3,425)));
	tran.insert(make_pair("return", TableItem(1,426)));
	tran.insert(make_pair("call_stmt", TableItem(3,427)));
	tran.insert(make_pair("set_mem", TableItem(1,428)));
	tran.insert(make_pair("include", TableItem(1,429)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,430)));
	tran.insert(make_pair("type_spec", TableItem(3,431)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,432)));
	tran.insert(make_pair("while", TableItem(1,433)));
	_parseTable.insert(make_pair(562,tran));
	tran.clear();


	// state 563
	tran.insert(make_pair(";", TableItem(1,569)));
	_parseTable.insert(make_pair(563,tran));
	tran.clear();


	// state 564
	tran.insert(make_pair("else", TableItem(2,58)));
	tran.insert(make_pair("{", TableItem(2,58)));
	tran.insert(make_pair("}", TableItem(2,58)));
	tran.insert(make_pair(";", TableItem(2,58)));
	tran.insert(make_pair("static", TableItem(2,58)));
	tran.insert(make_pair("return", TableItem(2,58)));
	tran.insert(make_pair("set_mem", TableItem(2,58)));
	tran.insert(make_pair("include", TableItem(2,58)));
	tran.insert(make_pair("id", TableItem(2,58)));
	tran.insert(make_pair("int", TableItem(2,58)));
	tran.insert(make_pair("double", TableItem(2,58)));
	tran.insert(make_pair("void", TableItem(2,58)));
	tran.insert(make_pair("char", TableItem(2,58)));
	tran.insert(make_pair("bool", TableItem(2,58)));
	tran.insert(make_pair("float", TableItem(2,58)));
	tran.insert(make_pair("if", TableItem(2,58)));
	tran.insert(make_pair("N", TableItem(3,570)));
	tran.insert(make_pair("while", TableItem(2,58)));
	_parseTable.insert(make_pair(564,tran));
	tran.clear();


	// state 565
	tran.insert(make_pair("stmt", TableItem(3,571)));
	tran.insert(make_pair("includestmt", TableItem(3,437)));
	tran.insert(make_pair("{", TableItem(1,438)));
	tran.insert(make_pair("fun_define", TableItem(3,439)));
	tran.insert(make_pair("if_stmt", TableItem(3,440)));
	tran.insert(make_pair("while_stmt", TableItem(3,441)));
	tran.insert(make_pair("var_decl", TableItem(3,442)));
	tran.insert(make_pair(";", TableItem(1,443)));
	tran.insert(make_pair("static", TableItem(1,444)));
	tran.insert(make_pair("expr_stmt", TableItem(3,445)));
	tran.insert(make_pair("return", TableItem(1,446)));
	tran.insert(make_pair("call_stmt", TableItem(3,447)));
	tran.insert(make_pair("set_mem", TableItem(1,448)));
	tran.insert(make_pair("include", TableItem(1,449)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,450)));
	tran.insert(make_pair("type_spec", TableItem(3,451)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,452)));
	tran.insert(make_pair("while", TableItem(1,453)));
	_parseTable.insert(make_pair(565,tran));
	tran.clear();


	// state 566
	tran.insert(make_pair("else", TableItem(2,15)));
	tran.insert(make_pair("{", TableItem(2,15)));
	tran.insert(make_pair(";", TableItem(2,15)));
	tran.insert(make_pair("static", TableItem(2,15)));
	tran.insert(make_pair("return", TableItem(2,15)));
	tran.insert(make_pair("set_mem", TableItem(2,15)));
	tran.insert(make_pair("include", TableItem(2,15)));
	tran.insert(make_pair("id", TableItem(2,15)));
	tran.insert(make_pair("int", TableItem(2,15)));
	tran.insert(make_pair("double", TableItem(2,15)));
	tran.insert(make_pair("void", TableItem(2,15)));
	tran.insert(make_pair("char", TableItem(2,15)));
	tran.insert(make_pair("bool", TableItem(2,15)));
	tran.insert(make_pair("float", TableItem(2,15)));
	tran.insert(make_pair("if", TableItem(2,15)));
	tran.insert(make_pair("while", TableItem(2,15)));
	tran.insert(make_pair("$", TableItem(2,15)));
	_parseTable.insert(make_pair(566,tran));
	tran.clear();


	// state 567
	tran.insert(make_pair("else", TableItem(1,572)));
	_parseTable.insert(make_pair(567,tran));
	tran.clear();


	// state 568
	tran.insert(make_pair("else", TableItem(2,60)));
	tran.insert(make_pair("{", TableItem(2,60)));
	tran.insert(make_pair(";", TableItem(2,60)));
	tran.insert(make_pair("static", TableItem(2,60)));
	tran.insert(make_pair("return", TableItem(2,60)));
	tran.insert(make_pair("set_mem", TableItem(2,60)));
	tran.insert(make_pair("include", TableItem(2,60)));
	tran.insert(make_pair("id", TableItem(2,60)));
	tran.insert(make_pair("int", TableItem(2,60)));
	tran.insert(make_pair("double", TableItem(2,60)));
	tran.insert(make_pair("void", TableItem(2,60)));
	tran.insert(make_pair("char", TableItem(2,60)));
	tran.insert(make_pair("bool", TableItem(2,60)));
	tran.insert(make_pair("float", TableItem(2,60)));
	tran.insert(make_pair("if", TableItem(2,60)));
	tran.insert(make_pair("while", TableItem(2,60)));
	tran.insert(make_pair("$", TableItem(2,60)));
	_parseTable.insert(make_pair(568,tran));
	tran.clear();


	// state 569
	tran.insert(make_pair("else", TableItem(2,15)));
	tran.insert(make_pair("{", TableItem(2,15)));
	tran.insert(make_pair("}", TableItem(2,15)));
	tran.insert(make_pair(";", TableItem(2,15)));
	tran.insert(make_pair("static", TableItem(2,15)));
	tran.insert(make_pair("return", TableItem(2,15)));
	tran.insert(make_pair("set_mem", TableItem(2,15)));
	tran.insert(make_pair("include", TableItem(2,15)));
	tran.insert(make_pair("id", TableItem(2,15)));
	tran.insert(make_pair("int", TableItem(2,15)));
	tran.insert(make_pair("double", TableItem(2,15)));
	tran.insert(make_pair("void", TableItem(2,15)));
	tran.insert(make_pair("char", TableItem(2,15)));
	tran.insert(make_pair("bool", TableItem(2,15)));
	tran.insert(make_pair("float", TableItem(2,15)));
	tran.insert(make_pair("if", TableItem(2,15)));
	tran.insert(make_pair("while", TableItem(2,15)));
	_parseTable.insert(make_pair(569,tran));
	tran.clear();


	// state 570
	tran.insert(make_pair("else", TableItem(1,573)));
	_parseTable.insert(make_pair(570,tran));
	tran.clear();


	// state 571
	tran.insert(make_pair("else", TableItem(2,60)));
	tran.insert(make_pair("{", TableItem(2,60)));
	tran.insert(make_pair("}", TableItem(2,60)));
	tran.insert(make_pair(";", TableItem(2,60)));
	tran.insert(make_pair("static", TableItem(2,60)));
	tran.insert(make_pair("return", TableItem(2,60)));
	tran.insert(make_pair("set_mem", TableItem(2,60)));
	tran.insert(make_pair("include", TableItem(2,60)));
	tran.insert(make_pair("id", TableItem(2,60)));
	tran.insert(make_pair("int", TableItem(2,60)));
	tran.insert(make_pair("double", TableItem(2,60)));
	tran.insert(make_pair("void", TableItem(2,60)));
	tran.insert(make_pair("char", TableItem(2,60)));
	tran.insert(make_pair("bool", TableItem(2,60)));
	tran.insert(make_pair("float", TableItem(2,60)));
	tran.insert(make_pair("if", TableItem(2,60)));
	tran.insert(make_pair("while", TableItem(2,60)));
	_parseTable.insert(make_pair(571,tran));
	tran.clear();


	// state 572
	tran.insert(make_pair("M", TableItem(3,574)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(572,tran));
	tran.clear();


	// state 573
	tran.insert(make_pair("M", TableItem(3,575)));
	tran.insert(make_pair("{", TableItem(2,69)));
	tran.insert(make_pair(";", TableItem(2,69)));
	tran.insert(make_pair("static", TableItem(2,69)));
	tran.insert(make_pair("return", TableItem(2,69)));
	tran.insert(make_pair("set_mem", TableItem(2,69)));
	tran.insert(make_pair("include", TableItem(2,69)));
	tran.insert(make_pair("id", TableItem(2,69)));
	tran.insert(make_pair("int", TableItem(2,69)));
	tran.insert(make_pair("double", TableItem(2,69)));
	tran.insert(make_pair("void", TableItem(2,69)));
	tran.insert(make_pair("char", TableItem(2,69)));
	tran.insert(make_pair("bool", TableItem(2,69)));
	tran.insert(make_pair("float", TableItem(2,69)));
	tran.insert(make_pair("if", TableItem(2,69)));
	tran.insert(make_pair("while", TableItem(2,69)));
	_parseTable.insert(make_pair(573,tran));
	tran.clear();


	// state 574
	tran.insert(make_pair("stmt", TableItem(3,576)));
	tran.insert(make_pair("includestmt", TableItem(3,417)));
	tran.insert(make_pair("{", TableItem(1,418)));
	tran.insert(make_pair("fun_define", TableItem(3,419)));
	tran.insert(make_pair("if_stmt", TableItem(3,420)));
	tran.insert(make_pair("while_stmt", TableItem(3,421)));
	tran.insert(make_pair("var_decl", TableItem(3,422)));
	tran.insert(make_pair(";", TableItem(1,423)));
	tran.insert(make_pair("static", TableItem(1,424)));
	tran.insert(make_pair("expr_stmt", TableItem(3,425)));
	tran.insert(make_pair("return", TableItem(1,426)));
	tran.insert(make_pair("call_stmt", TableItem(3,427)));
	tran.insert(make_pair("set_mem", TableItem(1,428)));
	tran.insert(make_pair("include", TableItem(1,429)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,430)));
	tran.insert(make_pair("type_spec", TableItem(3,431)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,432)));
	tran.insert(make_pair("while", TableItem(1,433)));
	_parseTable.insert(make_pair(574,tran));
	tran.clear();


	// state 575
	tran.insert(make_pair("stmt", TableItem(3,577)));
	tran.insert(make_pair("includestmt", TableItem(3,437)));
	tran.insert(make_pair("{", TableItem(1,438)));
	tran.insert(make_pair("fun_define", TableItem(3,439)));
	tran.insert(make_pair("if_stmt", TableItem(3,440)));
	tran.insert(make_pair("while_stmt", TableItem(3,441)));
	tran.insert(make_pair("var_decl", TableItem(3,442)));
	tran.insert(make_pair(";", TableItem(1,443)));
	tran.insert(make_pair("static", TableItem(1,444)));
	tran.insert(make_pair("expr_stmt", TableItem(3,445)));
	tran.insert(make_pair("return", TableItem(1,446)));
	tran.insert(make_pair("call_stmt", TableItem(3,447)));
	tran.insert(make_pair("set_mem", TableItem(1,448)));
	tran.insert(make_pair("include", TableItem(1,449)));
	tran.insert(make_pair("fun_decl_head", TableItem(3,450)));
	tran.insert(make_pair("type_spec", TableItem(3,451)));
	tran.insert(make_pair("id", TableItem(1,19)));
	tran.insert(make_pair("int", TableItem(1,20)));
	tran.insert(make_pair("double", TableItem(1,21)));
	tran.insert(make_pair("void", TableItem(1,22)));
	tran.insert(make_pair("char", TableItem(1,23)));
	tran.insert(make_pair("bool", TableItem(1,24)));
	tran.insert(make_pair("float", TableItem(1,25)));
	tran.insert(make_pair("if", TableItem(1,452)));
	tran.insert(make_pair("while", TableItem(1,453)));
	_parseTable.insert(make_pair(575,tran));
	tran.clear();


	// state 576
	tran.insert(make_pair("else", TableItem(2,59)));
	tran.insert(make_pair("{", TableItem(2,59)));
	tran.insert(make_pair(";", TableItem(2,59)));
	tran.insert(make_pair("static", TableItem(2,59)));
	tran.insert(make_pair("return", TableItem(2,59)));
	tran.insert(make_pair("set_mem", TableItem(2,59)));
	tran.insert(make_pair("include", TableItem(2,59)));
	tran.insert(make_pair("id", TableItem(2,59)));
	tran.insert(make_pair("int", TableItem(2,59)));
	tran.insert(make_pair("double", TableItem(2,59)));
	tran.insert(make_pair("void", TableItem(2,59)));
	tran.insert(make_pair("char", TableItem(2,59)));
	tran.insert(make_pair("bool", TableItem(2,59)));
	tran.insert(make_pair("float", TableItem(2,59)));
	tran.insert(make_pair("if", TableItem(2,59)));
	tran.insert(make_pair("while", TableItem(2,59)));
	tran.insert(make_pair("$", TableItem(2,59)));
	_parseTable.insert(make_pair(576,tran));
	tran.clear();


	// state 577
	tran.insert(make_pair("else", TableItem(2,59)));
	tran.insert(make_pair("{", TableItem(2,59)));
	tran.insert(make_pair("}", TableItem(2,59)));
	tran.insert(make_pair(";", TableItem(2,59)));
	tran.insert(make_pair("static", TableItem(2,59)));
	tran.insert(make_pair("return", TableItem(2,59)));
	tran.insert(make_pair("set_mem", TableItem(2,59)));
	tran.insert(make_pair("include", TableItem(2,59)));
	tran.insert(make_pair("id", TableItem(2,59)));
	tran.insert(make_pair("int", TableItem(2,59)));
	tran.insert(make_pair("double", TableItem(2,59)));
	tran.insert(make_pair("void", TableItem(2,59)));
	tran.insert(make_pair("char", TableItem(2,59)));
	tran.insert(make_pair("bool", TableItem(2,59)));
	tran.insert(make_pair("float", TableItem(2,59)));
	tran.insert(make_pair("if", TableItem(2,59)));
	tran.insert(make_pair("while", TableItem(2,59)));
	_parseTable.insert(make_pair(577,tran));
	tran.clear();


}
#endif 
