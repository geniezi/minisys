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
	// ����ʽ�ṹ
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
		ElementType _head;  // nonterminal for production head  ����ʽͷ�����ս��
		 list<ElementType> _bodyList;// nonterminal and terminal for production body  ��ͷ�����ʽ����
		size_t _bodyLength;
		IDType _index; //��ʾ��index�����ʽ
		ElementType _op;
	};
	// LR1����ʽ������Ԥ�����
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
		// ����ͬ�ںˣ����Ժϲ�Ԥ���
		bool sameCoreEqual(LR1Item item) {
			return (item._prod == _prod && item._dot == _dot);
		}
		ProductionItem* _prod; //����ʽ
		 list<ElementType>::iterator _dot; // dot position pointer to the latter (non)terminal A->.B, dot points to B
		//��_dot== _prod->_bodyList.end()ʱ���������Ҫִ�й�Լ����
		 set<ElementType> _predSet;	//Ԥ���
	};
	// LR1״̬�����LR1����ʽ��
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
			//����itemList�е����в���ʽ�������Ƿ��Ѵ���
			for (auto& it : itemList) {
				//���иò���ʽ��Ԥ���Ҳ��ͬ��
				if (it.equals(item)) {
					return false;
				}
				// ����ʽ����ͬ��Ԥ�����ͬ���ϲ�Ԥ�������
				else if (it.sameCoreEqual(item)) {
					it._predSet.insert(item._predSet.begin(), item._predSet.end());
					return true;
				}
			}
			// �����LR1����ʽ
			itemList.push_back(item);
			return true;
		}
		// �жϸ�״̬������LR1״̬�Ƿ���ͬ������״̬��Ϊ�Է��Ӽ�˵����ͬ
		bool equal(LR1State& other) {
			if (this->itemList.size() != other.itemList.size()) return false;
			for (auto it : other.itemList) {
				// ��������״̬�е�һ������ʽ�ڵ�ǰ״̬�в�������equal
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
				// ���ڵ�ǰ״̬�е�һ������ʽ������״̬�в�������equal
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
		// �ж�����״̬�ˣ�����ʽ���Ƿ���ͬ��LALR���кϲ�
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
	// LR1״̬������ת��MAP������goto Graph
	struct TransitionItem {
		// LR1״̬��ID
		TransitionItem(LR1State state, IDType index)
		:LR1state(state), index(index){}
		// �������һ�����ź���Ӧ��ת��״̬ID�������S��s0����״̬s1
		void addEdge(ElementType edge, IDType next) {
			TransMap.insert( make_pair(edge, next));
		}
		bool operator==(TransitionItem& it) {
			return (it.LR1state.equal(this->LR1state) && it.TransMap == TransMap);
		}
		LR1State LR1state;
		 map<ElementType, IDType> TransMap; //����ߺ������״̬
		IDType index;
	};
	// ���嶯�������롢��Լ��goto״̬��GOTO�У���ERROR��ACCEPT
	enum ACTION_TYPE { SHIFT = 1, REDUCTION, GOTO_STATE, ERROR, ACCEPT };
	// LR Parsing Table�����������һ��
	struct TableItem {
		TableItem() : action(ERROR), index(0) {};  //δ����ķ�����һ���ʾ����
		TableItem(ACTION_TYPE action, IDType index) : action(action), index(index) {};
		ACTION_TYPE action; //����
		IDType index;   // index of production(ͨ����i������ʽ��Լ) or goto state id(����ĳ��״̬)
	};

	struct StackItem {
		StackItem(IDType state, ElementType symbol) : state(state), symbol(symbol) {};
		IDType state;
		ElementType symbol;
		 map< string,  string> definitionMap;  //�Ƶ������
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
	char _peek;          // current char ��ǰ��ȡ�����ַ�
	unsigned int _line = 0;  // record the line of current _peek ��¼��ȡ����i��
	int _offset = -1;// record the offset of current _peek ��¼��ȡ����i�еĵ�j���ַ�

	ElementType _indexSymbol = 0; // max value stands for empty����¼ÿ�������index����һ����++
	ElementType EPLISON = 100; //��ʾ�մ�

	 vector< string> _word; // output word

	 map< string, ElementType> _nonterminalTable; //���ս�������ս���ַ�������Ӧ��Ŷ�Ӧ
	 map< string, ElementType> _terminalTable;	//�ս�����ս���ַ�������Ӧ��Ŷ�Ӧ
	 map<ElementType, bool> _nonterminalNullable; //���ս���Ƿ������մ�
	 map<ElementType, bool> _leftAssociative;
	 map<ElementType, unsigned int> _priority;
	 map<ElementType,  set<ElementType> > _firstMap;

	 deque<ProductionItem> _productionVector; //˫�˶��У�����������ʽ
	 map<unsigned int,  string> _productionAction; // �������ʽ�ź���Ӧ�Ķ����ַ���

	// LR(1) data
	 vector< vector<TableItem> > _LR1parseTable;
	 vector<TransitionItem> _LR1stateTransition;

	// LALR(1) data
	 map<IDType,  vector<TableItem> > _LALR1parseTable;
	 map<IDType, TransitionItem> _LALR1stateTransition;

}; // class SeuYacc

#endif _SEU_YACC_H
