#ifndef  _LEX_HELP_H
#define _LEX_HELP_H

// define statement for use hash_map
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <windows.h>
#include "Token.h"
#include "actionLex.h"
#include "tableLex.h"
#include <hash_map>
#include <string>
#include <list>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;

struct string_less : public binary_function<const string, const string, bool> {
public:
	result_type operator()(const first_argument_type& _Left
		, const second_argument_type& _Right) const {
		return _Left.compare(_Right) < 0;
	}
};

// variable for reading
ifstream _reFile;
static char* _buffer;            // reading buffer
static char _peek;               // current char
static unsigned int _line;       // record the line of current _peek
static int _offset;              // record the offset of current _peek
static unsigned int _numSymbol = 0;

static hash_map<string, unsigned int, hash_compare<string, string_less> >* _symbolTable;
//static map<string, unsigned int>* _symbolTable;
void Lexerror(string er) {
	fstream write;
	write.open("compiler.log", ios::out);
	write << er << endl;
}
bool read() {
	if (_offset == strlen(_buffer)|| _offset==-2) {
		_offset = -1;
		if (!_reFile.eof()) {
			_reFile.getline(_buffer, 1000);
			++_line;
		}
		else
			return false;
	}
	++_offset;
	if (_offset == strlen(_buffer)) {
		_peek = '\n';
	}
	else {
		_peek = _buffer[_offset];
	//	if (_peek == '\t') _peek = ' ';
	}
	return true;
}

// content : retract the char back to stream
void retract() {
	_offset -= 1;
	//_peek = _buffer[_offset];
}

// return : innerCode in _symbolTable
// if it is not in, return _numSymbol
unsigned int lookup(const string& str) {
	auto found = _symbolTable->find(str);
	if (found != _symbolTable->end()) return found->second;
	else return _numSymbol;
}

void outputTokenList(list<Token>& tokenList, ofstream& result) {
	
	for (auto token : tokenList) {
		result << "< " << token._lexecal.c_str() << " , " << token._attribute.c_str() << " , " << token._innerCode << " >\n";
	}
}


bool parseToken(const string& file, list<Token>& tokenList,int file_t) {
	// ��С��DFA����״̬�ĳ�ʼ��
	vector<map<char, unsigned int> >* _minDFAStateTranfer;
	set<unsigned int> _minDFAfinalStateSet;
	_minDFAStateTranfer = new vector<map<char, unsigned int> >();
	initMinDFAStateTranfer(_minDFAStateTranfer);
	// ��С��DFA�ս�̬�ĳ�ʼ����������״̬�����ս�̬
	
	initFinalSet(_minDFAfinalStateSet);
	_numSymbol = 0;
	_symbolTable = new hash_map<string, unsigned int, hash_compare<string, string_less> >();

	//_symbolTable = new map<string, unsigned int>();
	_buffer = new char[1000];
	_line = 0;
	_offset = -2;
	
	unsigned int _state = 0;
	string _lexeme = "";

	_reFile.open(file, ios::in);
	if (_reFile.fail()) {
		cout << file.c_str() << " cannot be open\n";
		Lexerror(file + " cannot be open");
		return false;
	}
	int ok = 1;
	while (true) {
		if (!read()) break;
		map<char, unsigned int>& tran = _minDFAStateTranfer->at(_state);
		auto found = tran.find(_peek);// ��tran��һ��״̬�Ҷ����һ���ַ�
		if (found != tran.end()) {
			// state transition
			_state = found->second; // ״̬transiton
			_lexeme.operator+=(_peek);// ��¼ת��������ַ�

		}
		else  { //δ�ҵ�����ת��״̬���ַ�
			// check whether it is a final state
			if (!_lexeme.empty() && _minDFAfinalStateSet.find(_state) != _minDFAfinalStateSet.end()) {
				if (_lexeme == "//")
				{
					_state = 0;
					_lexeme = "";
					_offset = -2;
					continue;
				}
				//cout << _lexeme << endl;
				// judge the _lexeme is a keyword
				unsigned int _innerCode = lookup(_lexeme);
				if (_innerCode == _numSymbol) {
					// new identifier
					(*_symbolTable)[_lexeme] = _numSymbol++;
				}
				// ��¼һ��token
				if(performAction(_state)!="ws")
					tokenList.push_back(Token(_lexeme, performAction(_state), _innerCode, _line, _offset==-2?strlen(_buffer):_offset));
				// ���ôӳ�ʼ״̬����һ��token
				_state = 0;
				_lexeme = "";
				//if (_peek != ' ' && _peek != '\t' && _peek != '\n') retract();
				retract();
			}
			else {
				if (_peek == ' ' || _peek == '\t' || _peek == '\n')
				{
					cout << "omit error\n";
					_state = 0;
					_lexeme = "";
					continue;
				}
				else {
					Lexerror("lexical analysis error at line " + to_string(_line) + ",offset " + to_string(_offset == -2 ? strlen(_buffer) : _offset));
					ok = 0;
					break;
				}
			}
		}
	};
	ofstream result;
	result.open("token_list.txt", file_t == 0 ? ios::out : ios::app);
	result << file << "--------------------------------\n";
	outputTokenList(tokenList, result);
	result.close();

	delete _symbolTable; _symbolTable = nullptr;
	delete _minDFAStateTranfer; _minDFAStateTranfer = nullptr;
	delete[] _buffer; _buffer = nullptr;

	_reFile.close();
	if (ok) {
		cout << "Lexical parsing complete!\n";
	}
	else cout << "Lexical parsing wrong!\n";
	return ok;
}

#endif // ! _LEX_HELP_H
