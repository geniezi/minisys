#ifndef _YACC_HELP_H
#define _YACC_HELP_H

#include <windows.h>
#include "Token.h"
#include "actionYacc.h"
#include "tableYacc.h"
#include "structDefine.h"
#include "MyCodeGenerate.h"
#include <string>
#include <list>
#include <deque>
#include <map>
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

// use deque to simulate stack (for action convenience)
deque<StackItem> st;
map<unsigned int,  map< string, TableItem> > _parseTable;

vector<SymbolTable*> symbolTables;
SymbolTable* globalTable;
SymbolTable* constTable;
stack< string> paramStack;
vector<string> filelist;
vector<Quadruple> middleCode;
int errorline;
void errorReduce( list<Token>::iterator token) {
	fstream write;
	write.open("compiler.log",  ios::out);
	write <<"parsing analysis error at "<< "line " << token->_line << ",offset " << token->_offset << " is wrong for grammar\n";
	cout << "parsing analysis error at " << "line " << token->_line << ",offset " << token->_offset << " is wrong for grammar\n";

}

bool yaccReduce(list<Token> _tokenList,string filename,int file_t) {
	middleCode.clear();
	symbolTables.clear();
	globalTable = nullptr;
	constTable = nullptr;
	nextInstr = 0;
	labelMap.clear();
	while (!st.empty()) st.pop_back();
	ofstream sequence("reduce_sequence.txt",file_t==0?ios::out:ios::app);
	sequence << filename << "--------------------------------\n";
	// 根据tableYacc建立分析表（当前状态读取字符采取怎样的动作）
	initTable(_parseTable);
	globalTable = new SymbolTable("global");
	constTable = new SymbolTable("const");
	globalTable->_beginIndex = nextInstr;
	currentTable = globalTable;
	// 把终结符送入token末和压入栈当匹配到$时表示结束
	_tokenList.push_back(Token("$", "$", 0, 0, 0));
	st.push_back(StackItem(0, "$")); // init stack
	auto token = _tokenList.begin(), tokenEnd = _tokenList.end();
	bool ok = 1;
	// 依次读取token序列
	while (token != tokenEnd) {
		
		TableItem tableItem = _parseTable.find(st.back()._state)->second.find(token->_attribute)->second;
		//cout << token->_lexecal << " " << token->_line<< " "<<token->_offset << endl;
		if (tableItem._action == SHIFT) {
			// push t onto the stack
			map< string,  string> map;
			map["lexeme"] = token->_lexecal;
			st.push_back(StackItem(tableItem._index, token->_attribute, map));
			// let a be the next input symbol
			errorline = token->_line;
			++token;
		}
		else if (tableItem._action == REDUCTION) {
			// ACTION[s, a] = reduce A->beta
			map< string,  string> reduceHead;
			// pair <length of production, production head>
			pair<unsigned int,  string> item = performAction(tableItem._index, reduceHead);
			// pop |beta| symbols off the stack
			for (size_t i = 0; i < item.first; ++i) st.pop_back();
			// let state t now be on top of stack
			const auto& tableitem = _parseTable.find(st.back()._state)->second;
			auto found = tableitem.find(item.second);
			if (found == tableitem.end())
			{
				errorReduce(token);
				ok = 0;
				return false;
			}
			unsigned int goto_state = found->second._index;
			// push GOTO[t, A] onto stack
			st.push_back(StackItem(goto_state, item.second, reduceHead));
			// output the production A->beta
			sequence << getProduction(tableItem._index) <<  endl;
		}
		else if (tableItem._action == ACCEPT) {
			// parsing is done
			map< string, string> reduceHead;
			pair<unsigned int, string> item = performAction(tableItem._index, reduceHead);
			for (size_t i = 0; i < item.first; ++i) st.pop_back();
			sequence << getProduction(tableItem._index) <<  endl;
			break;
		}
		else if (tableItem._action == ERROR) {
			// M[state,a] is an error entry
			errorReduce(token);
			ok = 0;
			return false;
			break;
		}
		else {
			errorReduce(token);
			ok = 0;
			return false;
			break;
		}
	}
	sequence.close();
	if (!ok) return false;
	// put global symbol table into structure
	symbolTables.push_back(constTable);
	symbolTables.push_back(globalTable);

	for (const auto& it : labelMap) {
		if(middleCode.size()>it.first) middleCode.at(it.first)._label = it.second;
	}
	for (const auto& it : funLabel) {
		if (middleCode.size() > it.first) middleCode.at(it.first)._fun = it.second;
	}

	ofstream middleCodeOut("middle_code.txt", file_t == 0 ? ios::out : ios::app);
	middleCodeOut << filename << "-------------------------------------------------\n";
	outputMiddleCode(middleCodeOut);
	// release table pointers
	ofstream symbolFile("symbol_table_file.txt", file_t==0?ios::out:ios::app);
	symbolFile << filename << "--------------------------------------------------\n";
	for (auto& table : symbolTables) {
		outputSymbolTable(table, symbolFile);
		//if (table != nullptr) delete table;
		//table = nullptr;
	}
	symbolFile.close();
	tranlateIntoAssembly(filename);
	for (auto& table : symbolTables) if (table != nullptr) delete table;
	//system("pause");
	return true;
}

#endif // !_YACC_HELP_H