#ifndef _YACC_HELP_H
#define _YACC_HELP_H

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
stack< string> paramStack;

vector<Quadruple> middleCode;

void errorReduce( list<Token>::iterator token) {
	fstream write;
	write.open("compiler.log",  ios::app);
	write <<"parsing analysis error at "<< "line " << token->_line << ",offset " << token->_offset << " is wrong for grammar\n";
	exit(1);
}

bool yaccReduce(list<Token> _tokenList,string filename) {

	ofstream sequence("reduce_sequence.txt");
	// 根据tableYacc建立分析表（当前状态读取字符采取怎样的动作）
	initTable(_parseTable);
	globalTable = new SymbolTable("global");
	globalTable->_beginIndex = nextInstr;
	currentTable = globalTable;
	// 把终结符送入token末和压入栈当匹配到$时表示结束
	_tokenList.push_back(Token("$", "$", 0, 0, 0));
	st.push_back(StackItem(0, "$")); // init stack
	auto token = _tokenList.begin(), tokenEnd = _tokenList.end();
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
			if (found == tableitem.end()) errorReduce(token);
			unsigned int goto_state = found->second._index;
			// push GOTO[t, A] onto stack
			st.push_back(StackItem(goto_state, item.second, reduceHead));
			// output the production A->beta
			sequence << getProduction(tableItem._index) <<  endl;
		}
		else if (tableItem._action == ACCEPT) {
			// parsing is done
			sequence << getProduction(tableItem._index) <<  endl;
			break;
		}
		else if (tableItem._action == ERROR) {
			// M[state,a] is an error entry
			errorReduce(token);	
			return false;
			break;
		}
		else {
			errorReduce(token);
			return false;
			break;
		}
	}
	sequence.close();

	// put global symbol table into structure
	symbolTables.push_back(globalTable);

	for (const auto& map : labelMap) {
		middleCode.at(map.first)._label = map.second;
	}
	outputMiddleCode();

	tranlateIntoAssembly(filename);

	// release table pointers
	ofstream symbolFile("symbol_table_file.txt");
	for (auto& table : symbolTables) {
		outputSymbolTable(table, symbolFile);
		if (table != nullptr) delete table;
		table = nullptr;
	}
	symbolFile.close();
	//system("pause");
	return true;
}

#endif // !_YACC_HELP_H