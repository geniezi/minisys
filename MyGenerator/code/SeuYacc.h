#ifndef _SEU_YACC_H
#define _SEU_YACC_H

#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <map>

#include "Token.h"
using namespace std;

class SeuYacc {
public:
	typedef unsigned int ElementType;
	typedef unsigned int IDType;
	// 产生式结构
	struct ProductionItem {
		ProductionItem(ElementType head,  list<ElementType> str, size_t length, IDType index)
			: _head(head), _bodyLength(length), _index(index)
		{
			_bodyList.assign(str.begin(), str.end());
			_op = 999999;  // init with no op
		};
		ProductionItem(ElementType head,  list<ElementType> str, size_t length, IDType index, ElementType opr)
			: _head(head), _bodyLength(length), _index(index)
		{
				_bodyList.assign(str.begin(), str.end());
				_op = opr;  // init with  op
		};
		void setOP(ElementType opr) {
			_op = opr;
		}
		bool equals(ProductionItem item) {
			return item._index == this->_index;
		}
		ElementType _head;  // nonterminal for production head  产生式头部非终结符
		 list<ElementType> _bodyList;// nonterminal and terminal for production body  箭头后产生式主体
		size_t _bodyLength;
		IDType _index; //表示第index条表达式
		ElementType _op;
	};
	// LR1产生式（加上预测符）
	struct LR1Item {
		LR1Item(ProductionItem* prod,  set<ElementType> predSet)
		{
			_prod = prod;
			_predSet = predSet;
			_dot = _prod->_bodyList.begin();
		}
		bool equals(LR1Item item) {
			return (item._prod == _prod && item._dot == _dot && item._predSet == _predSet);
		}
		// 有相同内核，可以合并预测符
		bool sameCoreEqual(LR1Item item) {
			return (item._prod == _prod && item._dot == _dot);
		}
		ProductionItem* _prod; //产生式
		 list<ElementType>::iterator _dot; // dot position pointer to the latter (non)terminal A->.B, dot points to B
		//当_dot== _prod->_bodyList.end()时·在最后，需要执行规约动作
		 set<ElementType> _predSet;	//预测符
	};
	// LR1状态（多个LR1产生式）
	struct LR1State {
		list<LR1Item> itemList;
		LR1State() {
			itemList.clear();
		}
		LR1State(const LR1State& st) {
			itemList.clear();
			for (auto it : st.itemList) {
				itemList.push_back(it);
			}
		}
		bool addItem(LR1Item item) {
			//对于itemList中的所有产生式遍历看是否已存在
			for (auto& it : itemList) {
				//已有该产生式（预测符也相同）
				if (it.equals(item)) {
					return false;
				}
				// 产生式核相同，预测符不同，合并预测符集合
				else if (it.sameCoreEqual(item)) {
					it._predSet.insert(item._predSet.begin(), item._predSet.end());
					return true;
				}
			}
			// 加入该LR1产生式
			itemList.push_back(item);
			return true;
		}
		// 判断该状态与其他LR1状态是否相同，两个状态互为对方子集说明相同
		bool equal(LR1State& other) {
			if (this->itemList.size() != other.itemList.size()) return false;
			for (auto it : other.itemList) {
				// 对于其他状态中的一条产生式在当前状态中查找有无equal
				auto it2 = itemList.begin(), it2End = itemList.end();
				for (; it2 != it2End; ++it2) {
					if (it2->equals(it)) {
						break;
					}
				}
				if (it2 == it2End)
					return false;
			}
			for (auto it : itemList) {
				// 对于当前状态中的一条产生式在其他状态中查找有无equal
				auto it2 = other.itemList.begin(), it2End = other.itemList.end();
				for (; it2 != it2End; ++it2) {
					if (it2->equals(it)) {
						break;
					}
				}
				if (it2 == it2End)
					return false;
			}
			return true;
		}
		// 判断两个状态核（产生式）是否相同，LALR进行合并
		bool equalSameCore(LR1State& other) {
			if (this->itemList.size() != other.itemList.size()) return false;
			for (auto it : other.itemList) {
				auto it2 = itemList.begin(), it2End = itemList.end();
				for (; it2 != it2End; ++it2) {
					if (it2->sameCoreEqual(it)) {
						break;
					}
				}
				if (it2 == it2End)
					return false;
			}
			for (auto it : itemList) {
				auto it2 = other.itemList.begin(), it2End = other.itemList.end();
				for (; it2 != it2End; ++it2) {
					if (it2->sameCoreEqual(it)) {
						break;
					}
				}
				if (it2 == it2End)
					return false;
			}
			return true;
		}
	};
	// LR1状态（加上转换MAP）构成goto Graph
	struct TransitionItem {
		// LR1状态和ID
		TransitionItem(LR1State state, IDType index)
		:LR1state(state), index(index){}
		// 读入的下一个符号和相应的转换状态ID，如读入S由s0进入状态s1
		void addEdge(ElementType edge, IDType next) {
			TransMap.insert( make_pair(edge, next));
		}
		bool operator==(TransitionItem& it) {
			return (it.LR1state.equal(this->LR1state) && it.TransMap == TransMap);
		}
		LR1State LR1state;
		 map<ElementType, IDType> TransMap; //保存边和移入的状态
		IDType index;
	};
	// 定义动作：移入、规约、goto状态（GOTO列）、ERROR和ACCEPT
	enum ACTION_TYPE { SHIFT = 1, REDUCTION, GOTO_STATE, ERROR, ACCEPT };
	// LR Parsing Table（定义分析表一格）
	struct TableItem {
		TableItem() : action(ERROR), index(0) {};  //未定义的分析表一格表示错误
		TableItem(ACTION_TYPE action, IDType index) : action(action), index(index) {};
		ACTION_TYPE action; //动作
		IDType index;   // index of production(通过第i个产生式规约) or goto state id(移入某个状态)
	};

	struct StackItem {
		StackItem(IDType state, ElementType symbol) : state(state), symbol(symbol) {};
		IDType state;
		ElementType symbol;
		 map< string,  string> definitionMap;  //制导翻译表
	};

public:
	SeuYacc(const  string grammerFile, const  string parsingFile);

	//bool reduce( list<Token>* _tokenList,  list<ProductionItem>* _reduceSequence);
	//void outputReduceSequence(const  string& filename,  list<ProductionItem>* _reduceSequence);
	
	// generate Lex code
	void generateParsingProgram();
	void outputLRStateSet();
	void outputLRParsingTable();
	void outputTable();
	void outputAction();
	void outputnonterminal();

protected:
	// read part
	bool readGrammer(const  string grammerFile);
	bool readPriority();
	bool read();
	void retract();
	bool isLetterOrDigit(char ch);
	bool isLegalLetter(char ch);

	// help function
	void nullableAnalyze();
	LR1State LRClosure(LR1State result);
	LR1State GOTO(LR1State h, ElementType edge);
	 set<ElementType> First(ElementType X);
	 set<ElementType> Follow(ElementType X);

	// transition graph
	void initTransition();

	// parsing table
	void initParseTable();
	ACTION_TYPE conflictSolve(ElementType shiftOP, ElementType reduceOP);

	bool transformIntoLALR();

	void translateAction();

private:

	 ifstream _sourcefile;
	 ofstream _outputFile;

	char* _buffer;
	char _peek;          // current char 当前读取到的字符
	unsigned int _line = 0;  // record the line of current _peek 记录读取到第i行
	int _offset = -1;// record the offset of current _peek 记录读取到第i行的第j个字符

	ElementType _indexSymbol = 0; // max value stands for empty，记录每个对象的index产生一个就++
	ElementType EPLISON = 100; //表示空串

	 vector< string> _word; // output word

	 map< string, ElementType> _nonterminalTable; //非终结符表，非终结符字符串和相应标号对应
	 map< string, ElementType> _terminalTable;	//终结符表，终结符字符串和相应标号对应
	 map<ElementType, bool> _nonterminalNullable; //非终结符是否会产生空串
	 map<ElementType, bool> _leftAssociative;
	 map<ElementType, unsigned int> _priority;
	 map<ElementType,  set<ElementType> > _firstMap;

	 deque<ProductionItem> _productionVector; //双端队列，保存多个产生式
	 map<unsigned int,  string> _productionAction; // 保存产生式号和相应的动作字符串

	// LR(1) data
	 vector< vector<TableItem> > _LR1parseTable;
	 vector<TransitionItem> _LR1stateTransition;

	// LALR(1) data
	 map<IDType,  vector<TableItem> > _LALR1parseTable;
	 map<IDType, TransitionItem> _LALR1stateTransition;

}; // class SeuYacc

#endif _SEU_YACC_H
