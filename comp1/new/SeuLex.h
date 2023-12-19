//	  file : SeuLex.h
// content : lexical analyze tool class 
//	  date : 2020/5/23
//  author : Yuqifan
//  @COPYRIGHT  : School of Computer Science & Engineering Southeast University

#ifndef _SEU_LEX_H
#define _SEU_LEX_H

// define statement for use hash_map
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "Token.h"
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <hash_map>
using namespace std;

// compare function for string hash_map use
struct string_less : public binary_function<const string, const string, bool> {
public:
	result_type operator()(const first_argument_type& _Left
		, const second_argument_type& _Right) const {
		return _Left.compare(_Right) < 0;
	}
};

class SeuLex {

	typedef unsigned int ElementType;
	typedef unsigned int IDType;
	typedef string Action; 

	typedef struct State {
		State(IDType id) : _id(id) {}
		void addEdge(ElementType edge, State* next) {
			_transition.push_back(Edge(edge, next));
		}
		struct Edge {
			Edge(ElementType edge, State* next) : _edge(edge), _next(next) {}
			State* _next;
			ElementType _edge;
		};
		list<Edge> _transition;
		IDType _id;
	}; // struct State

	typedef typename deque<State*> FA;    //only the first and the last states are important
	typedef typename set<State*> DFAState;
	typedef typename map<ElementType, IDType> StatesTransfer;
	typedef hash_map<string, unsigned int, hash_compare<string, string_less> > StringHash;

public:

	SeuLex(const string& reFile, const string& parsingFile);
	~SeuLex();

	// generate Lex code
	void generateParsingProgram();
	void outputMinDFA();
	void outputAction();

	bool parseByminDFA(list<Token>* tokenList, const string& file);
	
protected:
	// read RE file functions
	bool read();
	void retract();
	void error(const string& errorStr);
	unsigned int lookup(const string& str);
	bool readHeadInformation();
	bool readRegularDefinition();
	bool readTranslationRule();
	bool readREFile(const string& reFile);
	list<ElementType> convertPost(list<ElementType>& list);

	// NFA create function
	void PUSH(ElementType chInput);
	bool CONCAT();
	bool STAR();
	bool UNION();
	bool QUESTION();
	bool PLUS();
	bool createNFA();

	// DFA create function
	DFAState Closure(DFAState T);
	DFAState Move(DFAState T, ElementType input);
	bool createDFA();

	// min DFA optimized function
	bool optimizeDFA();

private:
	StringHash* _symbolTable;

	ofstream outputFile;

	// variable for reading
	char* _buffer;            // reading buffer
	char _peek;               // current char
	unsigned int _line;       // record the line of current _peek
	size_t _offset;              // record the offset of current _peek
	ifstream _reFile;
	unsigned int _numSymbol;
	bool _selfDefinedProgramme;

	// regular expressions structure
	const ElementType EPSILON = 0;
	// priority define for RE parsing
	const ElementType RIGHT_BRACE_OP = 1;
	const ElementType LEFT_BRACE_OP = 2;
	const ElementType CONCAT_OP = 3;
	const ElementType UNION_OP = 4;
	const ElementType STAR_OP = 5;
	const ElementType QUESTION_OP = 6;
	const ElementType PLUS_OP = 7;
	unsigned int _reIndex = 7;
	ElementType _minREelement = 8;
	map<string, list<ElementType> > _REs;     // index REs map
	vector<list<ElementType> > _postREs;   // index is the order in translation rule (action id)
	vector<Action> _actionMap;                  // index is the action id
	map<char, ElementType> _inputRE;      // map characters to numbers 
	map<ElementType, char> _outputRE;     // inverse of _input
	
	// data to help transfer REs to NFA
	State* _NFA_start;
	IDType _nextStateID = 0;
	stack<FA> _operandStack;  //to construct NFA from post RE 
	set<IDType> _NFAfinalStateSet;
	map<IDType, IDType> _NFAAction;         // <NFA state id, action id>

	// DFA data
	map<DFAState, DFAState> _ClosureMap;
	map<DFAState, IDType> _DFAStateMap;      
	set<IDType>  _DFAfinalStateSet;
	vector<StatesTransfer> _DFAStateTranfer; // vector index is state id
	map<IDType, IDType> _DFAAction;          // <DFA state id, action id>

	// min DFA data
	set<IDType> _minDFAfinalStateSet;
	vector<StatesTransfer> _minDFAStateTranfer; // vector index is state id
	map<IDType, IDType> _minDFAAction;      // <minDFA state id, action id>

}; // class SeuLex

#endif _SEU_LEX_H