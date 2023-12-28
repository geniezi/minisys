#ifndef _STRUCT_DEFINE_H
#define _STRUCT_DEFINE_H

#include <string>
#include <sstream>  
#include <map>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
#define SHIFT 1
#define REDUCTION 2
#define GOTO_STATE 3
#define ERROR 4
#define ACCEPT 5

const int REGISTER_NUM = 7;

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

struct SymbolTable {
	// data
	 string _funName;
	unsigned int _returnSize = 0;		// �ú�������ֵ��ռ���ֽ���
	unsigned int _variableOffset = 0;	// �ֲ�������ռ��ȫ���ֽ���
	unsigned int _paramOffset = 4;		// ����ʵ����ռ��ȫ���ֽ���
	int param_num = 0; //��������
	int _beginIndex = -1;   //Intermediate code entry index
	int _endIndex = -1;  //Intermediate code exit index(exclusive)
	struct varState {
		bool _live;	// �ݴ��Ծ�������Ϣ������������Ԫʽ�л�ԾLive�ʹ���Next-Use
		int _nextUse;
		bool _inM;	// �Ƿ���memory��
		int _inR;	// ���ĸ�register�У�-1��Ϊ����
		bool _unsigned;  //is unsigned value or not
		unsigned int _offset; //offset to base
		unsigned int _space; //used bytes
		string _name;
		string _type;
		string _place;	// ��Ӧ�Ķ�̬ջ������ģ�͵ı������ʵ�ַ
		string init_value;
		varState(const  string& name, const  string& type, unsigned int offset, unsigned int space, const string v="")
			: _name(name), _type(type), _live(false), _nextUse(-1),_inM(false), _inR(-1), _offset(offset), _space(space),init_value(v)
		{
			string::size_type pos = _type.find("unsigned", 0);
			if (pos !=  string::npos) {
				_unsigned = true;
			}
		};

	};
	 vector<varState> _field; // field for all vars
	 set<int> _leaders;  //basic blocks entry indices 

	// function
	SymbolTable(const  string& name) : _funName(name) {
		//RValue.resize(REGISTER_NUM);
		//RNextUse.resize(REGISTER_NUM);
		// fill_n(RNextUse.begin(), REGISTER_NUM, -1);
	}

	// add local variable into symbol table
	 string enter(const  string& name, const  string& type, unsigned int space, bool placeFlag = true, const string value="") {
		// �����÷��ű����Ƿ����иõ��ʣ���������Ϣ
		for (const auto& it : _field) {
			if (it._name == name) return it._place;
		}
		if (_funName != "global") {
			_variableOffset += space; // ����ռ�
			varState state(name, type, _variableOffset, space, value);
			if (placeFlag) { //�ֲ������á�BP-OFFSET����ַѰַ�洢����
				state._place = "-" + to_string(_variableOffset) + "(x8)";
			}
			else { //global var is searched by name
				state._place = name;
			}
			_field.push_back(state);
			return state._place;
		}
		else
		{
			varState state(name, type, _variableOffset, space, value);
			if (placeFlag) { //�ֲ������á�BP-OFFSET����ַѰַ�洢����
				state._place = to_string(_variableOffset) + "(x3)";
			}
			else { //global var is searched by name
				state._place = name;
			}
			_variableOffset += space; // ����ռ�
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
		// ����ʵ��ʱ������[BP+offset]�Ļ�ַѰַ��ʽ
		//state._place =  to_string((REGISTER_NUM - 1 + 2 - 1) * 2 + _paramOffset) + "(x8)";
		state._place = to_string(_paramOffset) + "(x8)";
		_field.push_back(state);
		return state._place;
	}

	// ���ĳ���ռ�λ���Ƿ��ڷ��ű���
	varState& at(const  string& place) {
		for (auto& it : _field) {
			if (it._place == place) {
				return it;
			}
		}
		 cerr << place << " is not in symbol table " << _funName <<  endl;
		// error handle
		exit(1);
	}
	// ���ĳ�������Ƿ��ڷ��ű��У���ֱ��exit
	bool in(const  string& place) {
		for (auto& it : _field) {
			if (it._place == place) {
				return true;
			}
		}
		return false;
	}
};

struct BasicBlock {
	int _begin;  //���������Ԫʽ���
	int _end;  //����������Ԫʽ���
	vector<int> _predecessors; //�û������ǰ�̣��������ŵļ��ϣ�
	vector<int> _successors; //�û�����ĺ�̣��������ŵļ��ϣ�
	set< string> _inLiveVar;
	set< string> _outLiveVar;
	BasicBlock(int index = -1) {
		_begin = index;  //��������Ϊ�û�������
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
	int _type; // ������
	 string _label;  //optional (e.g. loop:)
	 string _op;
	 string _des, _arg1, _arg2;

	bool _typeDes = false, _typeArg1 = false, _typeArg2 = false;	// ��ʾ���Ƕ�Ӧ�ı������ǳ�����Ĭ��Ϊfalse��Ϊ����
																	// false : ���� true : ����
	bool _liveDes, _liveArg1, _liveArg2; // �ñ����Ƿ񻹻��ڻ������ڱ����ã�false��ʾ���ᱻ����
	int _nextDes, _nextArg1, _nextArg2;  // ��ʾ�����ĸ���Ԫʽ�����ã���ֵΪ��Ԫʽ��ţ���������Ϊ-1

	Quadruple(const  string& op, const  string& arg1, const  string& arg2, const  string& des)
		: _op(op), _des(des), _arg1(arg1), _arg2(arg2) {

		if (isNum(arg1)) _typeArg1 = true;
		if (isNum(arg2)) _typeArg2 = true;
		_typeDes = _typeArg1 & _typeArg2;
		// �Բ�ͬ��Ԫʽ���з���ʱ��������������
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
			_type = 99; // A = B
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

// �����룬��ʾһ�������� _label : _op _des _arg _immediate
struct Assembly {
	 string _op;	// ������
	 string _des;	// Ŀ�Ĳ�����
	 string _arg;	// Դ������
	 string _label;	// ��ǩ����Ӧ�м�����еı��
	 string _immediate;	//������
	// Դ��Ŀ�Ĳ��ܶ�Ϊ�洢��ֱ��Ѱַ
	Assembly(const  string op, const  string des, const  string arg, const  string immediate)
		: _op(op), _des(des), _arg(arg), _immediate(immediate) {}
	Assembly(const  string& op, const int des, const  string& arg, const  string& immediate)
		: _op(op), _arg(arg) {
		_des = transformToRegName(des);
		_immediate = immediate;
	}
	Assembly(const  string& op, const int des, const int arg, const  string& immediate)
		: _op(op) {
		_des = transformToRegName(des);
		_arg = transformToRegName(arg);
		_immediate = immediate;
	}
	Assembly(const  string& op, const  string& des, const int arg, const  string& immediate)
		: _op(op) {
		_des = des;
		_arg = transformToRegName(arg);
		_immediate = immediate;
	}

	Assembly(const  string& op, const  string& des, const  string& arg, int immediate)
		: _op(op), _des(des), _arg(arg) {
		_immediate =  to_string(immediate);
	}
	Assembly(const  string& op, const int des, const  string& arg, int immediate)
		: _op(op), _arg(arg) {
		_des = transformToRegName(des);
		_immediate =  to_string(immediate);
	}
	Assembly(const  string& op, const int des, const int arg, const int immediate)
		: _op(op) {
		_des = transformToRegName(des);
		_arg = transformToRegName(arg);
		if (op=="addi"|| op == "slti" || op == "sltiu" || op == "xori" || op == "ori" || op == "andi"
			|| op == "slli" || op == "srli" || op == "srai")
			_immediate = to_string(immediate);
		else _immediate = transformToRegName(immediate);
	}
	Assembly(const string& op, const int& des, const int immediate)
		: _op(op) {
		_des = transformToRegName(des);
		_immediate =  to_string(immediate);
	}
	Assembly(const string& op, const string& des, const int immediate)
		: _op(op) {
		_des = des;
		_immediate = to_string(immediate);
	}
	Assembly(const string& op, const int& des, const string immediate)
		: _op(op) {
		_des = _des = transformToRegName(des);
		_immediate = immediate;
	}
	Assembly(const string& op, const string& des, const string immediate)
		: _op(op) {
		_des = des;
		_immediate = immediate;
	}
	// �Ĵ���Ѱַ���������ѡ��ͬ�ļĴ���
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
};

#endif //_STRUCT_DEFINE_H