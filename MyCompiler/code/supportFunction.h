#ifndef _SUPPORT_FUNCTION_H
#define _SUPPORT_FUNCTION_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "StructDefine.h"

using namespace std;

extern vector<SymbolTable*> symbolTables;
extern SymbolTable* globalTable; //全局变量的符号表
SymbolTable* currentTable; //每个函数局部变量的符号表

extern vector<Quadruple> middleCode; //中间代码以四元式形式表示
int nextInstr = 0;
map<int, string> labelMap; //labelMap为记录中间代码标签的数据结构。Key为中间代码的标号，value为对应该标号的标签。

typedef const string& strType;
bool isdigit(string x) {
	char* p1;
	strtol(x.c_str(), &p1, 10);
	return (*p1 == 0);
}
void error(string err) {
	fstream write;
	write.open("compiler.log", ios::app);
	write << "Syntax-directed translation error: " +err<< endl;
	exit(1);
}
// create newline in corresponding symbol table, and fill current variable's information
string enter(strType name, strType type, unsigned int offset, bool placeFlag = true, const string value="0") {
	if (name == "#") {
		return currentTable->enter(name, type, offset, false);
	}
	else if (currentTable->_funName == "global") {
		if (globalTable->in(name)&&!isdigit(name))
		{
			error("redeclaration of " + name);
		}
		return globalTable->enter(name, type, offset, false, value);
	}
	else { // 加入函数局部变量的符号表
		if (currentTable->in(name)&& !isdigit(name))
		{
			error("redeclaration of " + name);
		}
		return currentTable->enter(name, type, offset, placeFlag);
	}
}

// 为一个函数局部变量或全局变量建立符号表
void createSymbolTable(strType name, unsigned int returnSize) {
	if (globalTable->_endIndex < 0) globalTable->_endIndex = nextInstr;
	currentTable = new SymbolTable(name);
	currentTable->_returnSize = returnSize;
	currentTable->_beginIndex = nextInstr;
}

void returnToGlobalTable() {
	currentTable->_endIndex = nextInstr;
	symbolTables.push_back(currentTable);
	currentTable = globalTable;
}
string getType(string name)
{
	for (const auto& it : currentTable->_field) {
		if (it._name == name) return it._type;
	}
	for (const auto& it : globalTable->_field) {
		if (it._name == name) return it._type;
	}
}
void addFunLabel(int index, strType label) {
	labelMap.insert(make_pair(index, label));
}
// 声明函数时把函数实参加入符号表
void addToSymbolTable(strType itemlist) {

	string sep = ",;"; // 区分不同的实参
	string::size_type pos_begin = itemlist.find_first_not_of(sep);
	string::size_type comma_pos = 0;
	string strName, strType, strOffset;

	while (pos_begin != string::npos) {
		comma_pos = itemlist.find_first_of(sep, pos_begin);
		if (comma_pos != string::npos) {
			strName = itemlist.substr(pos_begin, comma_pos - pos_begin);
			pos_begin = comma_pos + 1;
		}
		comma_pos = itemlist.find_first_of(sep, pos_begin);
		if (comma_pos != string::npos) {
			strType = itemlist.substr(pos_begin, comma_pos - pos_begin);
			pos_begin = comma_pos + 1;
		}
		comma_pos = itemlist.find_first_of(sep, pos_begin);
		if (comma_pos != string::npos) {
			strOffset = itemlist.substr(pos_begin, comma_pos - pos_begin);
			pos_begin = comma_pos + 1;
		}
		// 加入实参
		currentTable->enterParam(strName, strType, atoi(strOffset.c_str()));
		pos_begin = itemlist.find_first_not_of(sep, pos_begin);
	}
}

void setOutLiveVar(strType name) {
	currentTable->at(name)._live = true;
}
// 输出符号表：函数名、返回大小、各个符号的属性
void outputSymbolTable(SymbolTable* table, ofstream& out) {
	out << endl << table->_funName << endl;
	out << "return size = " << table->_returnSize << endl;
	out << setw(6) << "name" << setw(8) << "place" << setw(6) << "type" << setw(6) << "offset" << setw(6) << "space" << endl;
	for (auto& _map : table->_field) {
		out << setw(6) << _map._name
			<< setw(8) << _map._place
			<< setw(6) << _map._type
			<< setw(6) << _map._offset
			<< setw(6) << _map._space
			<< endl;
	}
}

// form newline of parameter information into symbol table
string makeParam(strType name, strType type, unsigned int offset) {
	return name + "," + type + "," + to_string(offset) + ";";
}

static unsigned int maxTemp = 0;
// generate a new temp variable, return its place
// 把一个临时变量temp加入到符号表中
string newtemp(string var) {
	string name = "T" + to_string(maxTemp++);
	return enter(name, currentTable->at(var)._type, currentTable->at(var)._space);
}

string addNum(string str) {
	enter(str,"num", 0, false);
	return str;
}

// look up variable name in symbol table
// 检查某个变量名是否在符号表中已存在，若存在则返回
string lookupPlace(strType name) {
	if (name == "#") return name;
	for (auto& it : currentTable->_field) {
		if (it._name == name) {
			return it._place;
		}
	}
	for (auto& it : globalTable->_field) {
		if (it._name == name) {
			return name;
		}
	}
	cerr << name << " is not in symbol table " << endl;
	return name;
}

static unsigned int maxLabel = 0;
// generator a new label for object code
// 在语法制导翻译的过程中，对应标号的中间代码可能尚未生成，因此将标签信息进行保存
string newlabel() { 
	return "Label_" + to_string(maxLabel++);
}

// generator a array
string make_array(int a, strType type) {
	return "array<" + type + "," + to_string(a)  +  ">";
}
// int转换成字符串
string gen(int a) {
	return to_string(a);
}
// 加入函数基本块开始入口，leaders为该函数所有基本块的入口序号
void addLeader(int leaderIndex) {
	currentTable->_leaders.insert(leaderIndex);
}

void emit(strType op, strType arg1, strType arg2, strType des) {
	// 将操作符、操作数1、操作数2、返回位置（目的数）保存在四元式中
	if (currentTable == globalTable)
	{
		if (op == "MOV")
		{
			for (auto& it : globalTable->_field) {
				if (it._place == arg1) {
					it.init_value = des;
				}
			}
		}
		else
		{
			error(" should not write code other than definition outside function");
		}
		return;
	}
	middleCode.push_back(Quadruple(op, arg1, arg2, des));
	++nextInstr;
	// 最后一个四元式操作类型为跳转
	if (middleCode.back()._type == 20) {
		addLeader(nextInstr);
		addLeader(nextInstr-1);
	}
	// j rop B C LABEL_xxx
	else if (20 < middleCode.back()._type && middleCode.back()._type < 27) {
		addLeader(nextInstr); //不该-1
	}
	
}

// 进行标号回溯，对同一个出口的跳转指令以字符串形式合并成链
// 在该出口中间代码生成时将其标号进行回填
// create a new list containing only i, an index into the array of instrutions
string makelist(int i) {
	return to_string(i) + ";";
}

// concatenate the list p1,p2
string merge(const string& p1, const string& p2) {
	return p1 + p2;
}
// 当目标中间代码标号生成后对形成的链中的目标位置标号回填
// insert label as the target label for each of the instructions p
void backpatch(string p, string label) {
	if (p.empty()) return; // 跳转链串为空

	// "LABEL_" + gen(nextInstr)
	int labelIndex = atoi(label.substr(6).c_str()); //获取当前LABEL值
	addLeader(labelIndex);

	string sep = ";";
	//查找与()中指定的字符串中任意一个字符都不相符的字符的位置地址
	string::size_type pos_begin = p.find_first_not_of(sep);
	string::size_type comma_pos = 0;
	string strIndex;

	while (pos_begin != string::npos) {
		comma_pos = p.find_first_of(sep, pos_begin);
		if (comma_pos != string::npos) {
			strIndex = p.substr(pos_begin, comma_pos - pos_begin);
			pos_begin = comma_pos + 1;
		}
		middleCode.at(atoi(strIndex.c_str()))._des = label;  // 对已有的中间代码_des回填为当前label 
		pos_begin = p.find_first_not_of(sep, pos_begin);
	}
	// 记录该四元式的标号
	labelMap.insert(make_pair(labelIndex, label));
}

// output middle code
void outputMiddleCode() {	
	ofstream middleCodeOut("middle_code.txt");
	middleCodeOut << "                   " << setw(10) << "op" << setw(10) << "arg1" << setw(10) << "arg2" << setw(10) << "des" << endl;
	for (int i = 0; i < middleCode.size(); ++i) {
		auto& code = middleCode.at(i);
		// 输出LABEL没有则为空
		middleCodeOut << setw(13) << code._label + " : "; 
		middleCodeOut << setw(3) << i << ") ";
		middleCodeOut << setw(10) << code._op;
		middleCodeOut << setw(10) << code._arg1;
		middleCodeOut << setw(10) << code._arg2;
		middleCodeOut << setw(10) << code._des;
		middleCodeOut << endl;
	}
	middleCodeOut.close();
}
//void outputParseTree() {
//	ofstream TreeOut("prase_Tree.txt");
//}
#endif 