#ifndef _STRUCT_DEFINE_H
#define _STRUCT_DEFINE_H

#include <string>
#include <sstream>  
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <windows.h>

using namespace std;
#define SHIFT 1
#define REDUCTION 2
#define GOTO_STATE 3
#define ERROR 4
#define ACCEPT 5
extern int errorline;
const int REGISTER_NUM = 17;
void error(string err) {
	fstream write;
	write.open("compiler.log", ios::out);
	write << "Syntax-directed translation error: " + err + " at line:"<< errorline << endl;
	cout << "Syntax-directed translation error: " + err + " at line:" << errorline <<endl;
	exit(1);
}
//typedef unsigned int ACTION_TYPE;
struct TableItem {
	TableItem() : _action(ERROR), _index(0) {};
	TableItem(unsigned int action, unsigned int index) : _action(action), _index(index) {};
	unsigned int _action;
	unsigned int _index;   // index of production or goto state id
};

struct StackItem {
	StackItem(unsigned int state,  string symbol) : _state(state), _symbol(symbol) {};
	StackItem(unsigned int state,  string symbol,  map< string,  string> map)
		: _state(state), _symbol(symbol), _map(map) {};
	unsigned int _state;
	string _symbol;
	map< string,  string> _map;
};
struct varState {
	bool _live;	// 暂存活跃与待用信息，用于生成四元式中活跃Live和待用Next-Use
	int _nextUse;
	bool _inM;	// 是否在memory中
	int _inR;	// 在哪个register中，-1则为不在
	bool _unsigned;  //is unsigned value or not
	int _offset; //offset to base
	unsigned int _space; //used bytes
	string _name;
	string _type;
	string _place;	// 对应的动态栈区分配模型的变量访问地址
	string init_value;
	varState(const  string& name, const  string& type, unsigned int offset, unsigned int space, const string v = "")
		: _name(name), _type(type), _live(false), _nextUse(-1), _inM(false), _inR(-1), _offset(offset), _space(space), init_value(v)
	{
		string::size_type pos = _type.find("unsigned", 0);
		if (pos != string::npos) {
			_unsigned = true;
		}
	};

};

struct SymbolTable {
	// data
	 string _funName;
	unsigned int _returnSize = 0;		// 该函数返回值所占的字节数
	unsigned int _variableOffset = 0;	// 局部变量所占的全部字节数
	unsigned int _paramOffset = 4;		// 函数实参所占的全部字节数
	int param_num = 0; //参数个数
	int _beginIndex = -1;   //Intermediate code entry index
	int _endIndex = -1;  //Intermediate code exit index(exclusive)
	
	 vector<varState> _field; // field for all vars
	 set<int> _leaders;  //basic blocks entry indices 

	// function
	SymbolTable(const  string& name) : _funName(name) {
		//RValue.resize(REGISTER_NUM);
		//RNextUse.resize(REGISTER_NUM);
		// fill_n(RNextUse.begin(), REGISTER_NUM, -1);
	}
	// add local variable into symbol table
	 string enter(const  string& name, const string& type, unsigned int space, bool placeFlag = true, const string value="") {
		// 检索该符号表中是否已有该单词（变量）信息
		for (const auto& it : _field) {
			if (it._name == name) return it._place;
		}
		if (_funName == "global") {
			varState state(name, type, _variableOffset, space, value);
			state._place = to_string(_variableOffset) + "(x3)";
			_variableOffset += space; // 分配空间
			_field.push_back(state);
			//cout << state._name << " " << state._type << " " << state.init_value << " " << state._place << endl;
			return state._place;
		}
		else if (_funName == "const") {
			string ty;
			if (name.find("0x") != name.npos) ty = "hex";
			else ty = "dec";
			varState state(name, ty, _variableOffset, space,name);
			if (ty == "dec") state._place = name;
			else state._place = to_string(stoi(name.c_str(), NULL, 16));
			_field.push_back(state);
			return state._place;
		}
		else
		{
			_variableOffset += space; // 分配空间
			varState state(name, type, _variableOffset, space, value);
			//局部变量用【BP-OFFSET】基址寻址存储访问
			state._place = "-" + to_string(_variableOffset) + "(x8)";
			_field.push_back(state);
			return state._place;
		}
	}

	// add param into symbol table
	 string enterParam(const  string& name, const  string& type, unsigned int space) {
		for (const auto& it : _field) {
			if (it._name == name) return "";
		}
		param_num++;
		_paramOffset += space;
		varState state(name, type, _paramOffset, space);
		// 访问实参时，采用[BP+offset]的基址寻址方式
		//state._place =  to_string((REGISTER_NUM - 1 + 2 - 1) * 2 + _paramOffset) + "(x8)";
		state._place = to_string(_paramOffset) + "(x8)";
		_field.push_back(state);
		return state._place;
	}

	// 检测某个空间位置是否在符号表中
	varState& at(const  string& place) {
		for (auto& it : _field) {
			if (it._place == place) {
				return it;
			}
		}
		error("can not find address " +place );
	}
	// 检测某个变量是否在符号表中，不直接exit
	bool in(const  string& place) {
		for (auto& it : _field) {
			if (it._place == place) {
				return true;
			}
		}
		return false;
	}
	bool namein(const  string& name) {
		for (auto& it : _field) {
			if (it._name == name) {
				return true;
			}
		}
		return false;
	}
	varState& nameat(const  string& name) {
		for (auto& it : _field) {
			if (it._name == name) {
				return it;
			}
		}
		error("can not find name" + name);
	}
};

struct BasicBlock {
	int _begin;  //入口语句的四元式标号
	int _end;  //出口语句的四元式标号
	vector<int> _predecessors; //该基本块的前继（基本块标号的集合）
	vector<int> _successors; //该基本块的后继（基本块标号的集合）
	set< string> _inLiveVar;
	set< string> _outLiveVar;
	BasicBlock(int index = -1) {
		_begin = index;  //入口语句标号为该基本块标号
	}
};

bool isNum( string str) {
	stringstream sin(str);
	int d;
	char c;
	if (!(sin >> d))
		return false;
	if (sin >> c)
		return false;
	return true;
}

struct  Quadruple {
	int _type; // 类型码
	 string _label;  //optional (e.g. loop:)
	 string _op;
	 string _des, _arg1, _arg2;

	bool _typeDes = false, _typeArg1 = false, _typeArg2 = false;	// 表示它们对应的变量或是常量，默认为false即为变量
																	// false : 变量 true : 常量
	bool _liveDes, _liveArg1, _liveArg2; // 该变量是否还会在基本块内被引用，false表示不会被引用
	int _nextDes, _nextArg1, _nextArg2;  // 表示会在哪个四元式被引用，数值为四元式标号，无引用则为-1

	Quadruple(const  string& op, const  string& arg1, const  string& arg2, const  string& des)
		: _op(op), _des(des), _arg1(arg1), _arg2(arg2) {

		if (isNum(arg1)) _typeArg1 = true;
		if (isNum(arg2)) _typeArg2 = true;
		_typeDes = _typeArg1 & _typeArg2;
		// 对不同四元式进行翻译时根据类型码区分
		if (_op == "add") {
			_type = 10;
		}
		else if (_op == "sub") {
			_type = 11;
		}
		else if (_op == "mul") {
			_type = 12;
		}
		else if (_op == "div") {
			_type = 13;
		}
		else if (_op == "srl") {
			_type = 14; // A >> B
		}
		else if (_op == "sll") {
			_type = 15; // A << B
		}
		else if (_op == "rem") {
			_type = 16; // A % B
		}
		else if (_op == "and") {
			_type = 17; // A & B
		}
		else if (_op == "or") {
			_type = 18; // A | B
		}
		else if (_op == "xor") {
			_type = 19; // A ^ B
		}
		else if (_op == "neg") {
			_type = 2; // A = op B
		}
		else if (_op == "MOV") {
			_type = 3; // A = B
		}
		else if (_op == "MOVaddr") {
			_type = 99; // A = B.addr
		}
		else if (_op == "MOVoff") {
			_type = 98; // A = B.addr+(off)
		}
		else if (_op == "load") {
			_type = 97; // load_mem(x)
		}
		else if (_op == "set") {
			_type = 96; // set_mem(x,y)
		}
		else if (_op == "nop") {
			_type = 100;
		}
		else if (_op[0] == 'j') {
			if (_op.size() == 1) {
				_type = 40; // j LABEL_xxx
			}
			else {
				// j rop B C LABEL_xxx
				if (_op == "j<") {
					_type = 41;
				}
				else if (_op == "j<=") {
					_type = 42;
				}
				else if (_op == "j>") {
					_type = 43;
				}
				else if (_op == "j>=") {
					_type = 44;
				}
				else if (_op == "j==") {
					_type = 45;
				}
				else if (_op == "j!=") {
					_type = 46;
				}
			}
		}
		else if (_op == "param") {
			_type = 6; // param p
		}
		else if (_op == "call") {
			_type = 7;// call N funName
		}
		else if (_op == "return") {
			_type = 8; // return a
		}
	}
};
string transformToRegName(int reg) {
	if (reg == 0) return "x5";
	else if (reg == 1) return "x6";
	else if (reg == 2) return "x7";
	else if (reg == 3) return "x28";
	else if (reg == 4) return "x29";
	else if (reg == 5) return "x30";
	else if (reg == 6) return "x31";
	else if (reg == 7) return "x18";
	else if (reg == 8) return "x19";
	else if (reg == 9) return "x20";
	else if (reg == 10) return "x21";
	else if (reg == 11) return "x22";
	else if (reg == 12) return "x23";
	else if (reg == 13) return "x24";
	else if (reg == 14) return "x25";
	else if (reg == 15) return "x26";
	else if (reg == 16) return "x27";
	else return "x18";
}

// 汇编代码，表示一条汇编语句 _label : _op _des _arg _immediate
struct Assembly {
	 string _op;	// 操作符
	 string _des;	// 目的操作数
	 string _arg;	// 源操作数1
	 string _label;	// 标签，对应中间代码中的标号
	 string _arg2;	// 源操作数2
	 Assembly(const  string& op, const string des, const string arg) : _op(op)
	 {
		 _des = des;
		 _arg = arg;
	 }
	 Assembly(const  string& op, const int des, const string arg) : _op(op)
	 {
		 _des = transformToRegName(des);
		 _arg = arg;
	 }
	 Assembly(const  string& op, const int des, const int arg) : _op(op)
	 {
		 _des = transformToRegName(des);
		 _arg = to_string(arg);
	 }
	 Assembly(const  string& op, const string des, const int arg) : _op(op),_des(des)
	 {
		 _arg = to_string(arg);
	 }
	 Assembly(const  string& op, const int des, const int arg, const int arg2)
		 : _op(op) {
		 _des = transformToRegName(des);
		 _arg = transformToRegName(arg);
		 if (op == "addi" || op == "slti" || op == "sltiu" || op == "xori" || op == "ori" || op == "andi"
			 || op == "slli" || op == "srli" || op == "srai")
			 _arg2 = to_string(arg2);
		 else _arg2 = transformToRegName(arg2);
	 }
	 Assembly(const  string& op, const int des, const string arg, const int arg2)
		 : _op(op),_arg(arg) {
		 _des = transformToRegName(des);
		 if (op == "addi" || op == "slti" || op == "sltiu" || op == "xori" || op == "ori" || op == "andi"
			 || op == "slli" || op == "srli" || op == "srai")
			 _arg2 = to_string(arg2);
		 else _arg2 = transformToRegName(arg2);
	 }
	 Assembly(const  string& op, const string des, const int arg, const int arg2)
		 : _op(op), _des(des) {
		 _arg = transformToRegName(arg);
		 if (op == "addi" || op == "slti" || op == "sltiu" || op == "xori" || op == "ori" || op == "andi"
			 || op == "slli" || op == "srli" || op == "srai")
			 _arg2 = to_string(arg2);
		 else _arg2 = transformToRegName(arg2);
	 }
	 Assembly(const  string& op, const string des, const string arg, const int arg2)
		 : _op(op) ,_arg(arg) , _des(des){
		 if (op == "addi" || op == "slti" || op == "sltiu" || op == "xori" || op == "ori" || op == "andi"
			 || op == "slli" || op == "srli" || op == "srai")
			 _arg2 = to_string(arg2);
		 else _arg2 = transformToRegName(arg2);
	 }
	 Assembly(const  string& op, const int des, const int arg, const string arg2)
		 : _op(op), _arg2(arg2) {
		 _des = transformToRegName(des);
		 _arg = transformToRegName(arg);
	 }
	 Assembly(const  string& op, const int des, const string arg, const string arg2)
		 : _op(op), _arg(arg), _arg2(arg2) {
		 _des = transformToRegName(des);
	 }
	 Assembly(const  string& op, const string des, const int arg, const string arg2)
		 : _op(op), _des(des), _arg2(arg2) {
		 _arg = transformToRegName(arg);
	 }
	 Assembly(const  string& op, const string des, const string arg, const string arg2)
		 : _op(op), _arg(arg), _des(des) ,_arg2(arg2){
	 }
	// 寄存器寻址，根据序号选择不同的寄存器
};

#endif //_STRUCT_DEFINE_H