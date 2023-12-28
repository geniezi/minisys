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
extern SymbolTable* globalTable; //ȫ�ֱ����ķ��ű�
SymbolTable* currentTable; //ÿ�������ֲ������ķ��ű�

extern vector<Quadruple> middleCode; //�м��������Ԫʽ��ʽ��ʾ
int nextInstr = 0;
map<int, string> labelMap; //labelMapΪ��¼�м�����ǩ�����ݽṹ��KeyΪ�м����ı�ţ�valueΪ��Ӧ�ñ�ŵı�ǩ��

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
	else { // ���뺯���ֲ������ķ��ű�
		if (currentTable->in(name)&& !isdigit(name))
		{
			error("redeclaration of " + name);
		}
		return currentTable->enter(name, type, offset, placeFlag);
	}
}

// Ϊһ�������ֲ�������ȫ�ֱ����������ű�
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
// ��������ʱ�Ѻ���ʵ�μ�����ű�
void addToSymbolTable(strType itemlist) {

	string sep = ",;"; // ���ֲ�ͬ��ʵ��
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
		// ����ʵ��
		currentTable->enterParam(strName, strType, atoi(strOffset.c_str()));
		pos_begin = itemlist.find_first_not_of(sep, pos_begin);
	}
}

void setOutLiveVar(strType name) {
	currentTable->at(name)._live = true;
}
// ������ű������������ش�С���������ŵ�����
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
// ��һ����ʱ����temp���뵽���ű���
string newtemp(string var) {
	string name = "T" + to_string(maxTemp++);
	return enter(name, currentTable->at(var)._type, currentTable->at(var)._space);
}

string addNum(string str) {
	enter(str,"num", 0, false);
	return str;
}

// look up variable name in symbol table
// ���ĳ���������Ƿ��ڷ��ű����Ѵ��ڣ��������򷵻�
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
// ���﷨�Ƶ�����Ĺ����У���Ӧ��ŵ��м���������δ���ɣ���˽���ǩ��Ϣ���б���
string newlabel() { 
	return "Label_" + to_string(maxLabel++);
}

// generator a array
string make_array(int a, strType type) {
	return "array<" + type + "," + to_string(a)  +  ">";
}
// intת�����ַ���
string gen(int a) {
	return to_string(a);
}
// ���뺯�������鿪ʼ��ڣ�leadersΪ�ú������л������������
void addLeader(int leaderIndex) {
	currentTable->_leaders.insert(leaderIndex);
}

void emit(strType op, strType arg1, strType arg2, strType des) {
	// ����������������1��������2������λ�ã�Ŀ��������������Ԫʽ��
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
	// ���һ����Ԫʽ��������Ϊ��ת
	if (middleCode.back()._type == 20) {
		addLeader(nextInstr);
		addLeader(nextInstr-1);
	}
	// j rop B C LABEL_xxx
	else if (20 < middleCode.back()._type && middleCode.back()._type < 27) {
		addLeader(nextInstr); //����-1
	}
	
}

// ���б�Ż��ݣ���ͬһ�����ڵ���תָ�����ַ�����ʽ�ϲ�����
// �ڸó����м��������ʱ�����Ž��л���
// create a new list containing only i, an index into the array of instrutions
string makelist(int i) {
	return to_string(i) + ";";
}

// concatenate the list p1,p2
string merge(const string& p1, const string& p2) {
	return p1 + p2;
}
// ��Ŀ���м���������ɺ���γɵ����е�Ŀ��λ�ñ�Ż���
// insert label as the target label for each of the instructions p
void backpatch(string p, string label) {
	if (p.empty()) return; // ��ת����Ϊ��

	// "LABEL_" + gen(nextInstr)
	int labelIndex = atoi(label.substr(6).c_str()); //��ȡ��ǰLABELֵ
	addLeader(labelIndex);

	string sep = ";";
	//������()��ָ�����ַ���������һ���ַ�����������ַ���λ�õ�ַ
	string::size_type pos_begin = p.find_first_not_of(sep);
	string::size_type comma_pos = 0;
	string strIndex;

	while (pos_begin != string::npos) {
		comma_pos = p.find_first_of(sep, pos_begin);
		if (comma_pos != string::npos) {
			strIndex = p.substr(pos_begin, comma_pos - pos_begin);
			pos_begin = comma_pos + 1;
		}
		middleCode.at(atoi(strIndex.c_str()))._des = label;  // �����е��м����_des����Ϊ��ǰlabel 
		pos_begin = p.find_first_not_of(sep, pos_begin);
	}
	// ��¼����Ԫʽ�ı��
	labelMap.insert(make_pair(labelIndex, label));
}

// output middle code
void outputMiddleCode() {	
	ofstream middleCodeOut("middle_code.txt");
	middleCodeOut << "                   " << setw(10) << "op" << setw(10) << "arg1" << setw(10) << "arg2" << setw(10) << "des" << endl;
	for (int i = 0; i < middleCode.size(); ++i) {
		auto& code = middleCode.at(i);
		// ���LABELû����Ϊ��
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