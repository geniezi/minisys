//	  file : SeuYacc.h
// content : syntax analyze tool class
//	  date : 2020/5/23
//  author : Yuqifan
//  @COPYRIGHT  : School of Computer Science & Engineering Southeast University


#ifndef _SEU_YACC_CPP
#define _SEU_YACC_CPP

#include "SeuYacc.h"
#include <functional>
#include <iomanip>
#include <iostream>
using namespace std;
// content : construct function
// input   : grammerFile -> xxx.y
//           parsingFile -> parsing file xxx.c generated
SeuYacc::SeuYacc(const string grammerFile, const string parsingFile) {
	_outputFile.open(parsingFile);
	if (readGrammer(grammerFile)) {
		initTransition();
		initParseTable();
		//transformIntoLALR();
		if (!transformIntoLALR()) {
			// it can not be transform into LALR, clear corresbonding data
			cout << "it can not be transform into LALR!" << endl;
			//_LALR1parseTable.swap(map<ElementType, vector<TableItem>>());
			_LALR1parseTable.clear();
			//_LALR1stateTransition.swap(map<ElementType, TransitionItem>());
			_LALR1stateTransition.clear();
		}
		generateParsingProgram();
	}
	_outputFile.close();
}

// content : read grammer file xx.y
bool SeuYacc::readGrammer(const string grammerFile) {

	_sourcefile.open(grammerFile, ios::in);
	// �ļ�������
	if (_sourcefile.fail()) {
		cout<<grammerFile + " cannot be open";
		return false;
	}

	_buffer = new char[100];

	IDType state = 0;
	string lexeme = ""; //����lex�ʷ�����һ�����ʣ�һ�����ս�����ս����
	IDType procHead = 9999; // �������ʽͷ��
	bool endFlag = false;
	unsigned int braceMatch = 0; //����ƥ������

	_indexSymbol = 0;
	list<ElementType> list; // ����list�������ʽ�Ҳ���ElementType���ս������ս����
	unsigned int numOfProd = 0;  // ��¼����ʽ������

	// read Priority infomation first
	if (!readPriority()) {
		//error("illegal addition condition declaration", 0);
		return false;
	}

	// ��ʼ��ȡ����ʽֱ��endFlagΪtrue
	// read production
	while (!endFlag) {
		switch (state) {
		case 0:
			// read prodction head
			if (!read()) endFlag = true;
			else if (isLegalLetter(_peek)) {
				lexeme.operator+=(_peek);  // ��ȡ������һ�����ս�����ս��
				state = 0;
			}
			else if (_peek == ':') { //����ʽͷ������
				auto found = _nonterminalTable.find(lexeme); //�ڷ��ս�������Ƿ����
				if (found != _nonterminalTable.end()) {
					procHead = found->second;  //procHead�������еķ��ս��ElementType
				}
				else {
					// new nontermianl production head �±���һ�����ս��
					_nonterminalTable.insert(make_pair(lexeme, _indexSymbol));
					_nonterminalNullable.insert(make_pair(_indexSymbol, false));// Ĭ���±���ķ��ս���������մ�
					_word.push_back(lexeme);
					procHead = _indexSymbol;
					++_indexSymbol;
				}
				lexeme = "";
				state = 1;
			} // ignore illegal char
			break;
		case 1:
			read();
			// read production list
			if (isLegalLetter(_peek)) {
				lexeme.operator+=(_peek);
				state = 1;
			}
			else if (_peek == ' ' || _peek == '\t' || _peek == '\n') {
				if (!lexeme.empty()) {
					auto found = _nonterminalTable.find(lexeme);
					if (found != _nonterminalTable.end()) {
						list.push_back(found->second);
					}
					else {
						_nonterminalTable.insert(make_pair(lexeme, _indexSymbol));
						_nonterminalNullable.insert(make_pair(_indexSymbol, false)); //Ĭ�ϲ��ǿմ�
						_word.push_back(lexeme);
						list.push_back(_indexSymbol);
						++_indexSymbol;
					}
				}
				lexeme = "";
				state = 1;
			}
			else if (_peek == '|') {
				// same production head with different body list
				// �ȱ������е�һ������ʽ
				_productionVector.push_back(ProductionItem(procHead, list, list.size(), numOfProd++));
				if (list.empty()) {
					// empty production������ʽΪ�մ�����¼�÷��ս��Ϊ�մ�
					_nonterminalNullable.find(procHead)->second = true;
				}
				//list.swap(list<ElementType>());// ���list�б�
				list.clear();
				lexeme = "";
			}
			else if (_peek == '\'' || _peek == ';' || _peek == '{') {
				if (!lexeme.empty()) {
					auto found = _nonterminalTable.find(lexeme);
					if (found != _nonterminalTable.end()) {
						list.push_back(found->second);
					}
					else {
						_nonterminalTable.insert(make_pair(lexeme, _indexSymbol));
						_nonterminalNullable.insert(make_pair(_indexSymbol, false));
						_word.push_back(lexeme);
						list.push_back(_indexSymbol);
						++_indexSymbol;
					}
				}
				lexeme = "";
				if (_peek == '\'') state = 2; //�������ű�ʾ֮�������Ϊ�ս��
				else if (_peek == ';') state = 3; //��������ʾһ������ʽ����׼������һ��
				else if (_peek == '{') { state = 4; ++braceMatch; }
			}
			break;
		case 2:
			// read terminal 'xxx'
			read();
			if (_peek == '\'') { //һ���ս������
				auto found = _terminalTable.find(lexeme);
				if (found != _terminalTable.end()) {
					list.push_back(found->second);
				}
				else {
					_terminalTable.insert(make_pair(lexeme, _indexSymbol));
					_word.push_back(lexeme);
					list.push_back(_indexSymbol);
					++_indexSymbol;
				}
				lexeme = "";
				state = 1;
			}
			else lexeme.operator+=(_peek);
			break;
		case 3:
			// add production�����ƶ���|����֮ǰ����Ĳ���ʽ���浽_productionVector
			_productionVector.push_back(ProductionItem(procHead, list, list.size(), numOfProd++));
			if (list.empty()) {
				// empty production
				_nonterminalNullable.find(procHead)->second = true;
			}
			//list.swap(list<ElementType>());
			list.clear();
			lexeme = "";
			state = 0;
			break;
		case 4:
			// action part ���嶯���������﷨�Ƶ����������м����
			// yacc.y�ļ���{}�еĲ���
			read();
			if (_peek == '}' && braceMatch == 1) {
				
				--braceMatch;
				// numOfProd��ʾ��n������ʽ��lexeme��ʾҪִ�еĶ�����map���ݲ���ʽ��Ų��Ӧ�Ĳ���
				_productionAction.insert(make_pair(numOfProd, lexeme));
				lexeme = "";
				state = 1;
			}
			else {
				lexeme.operator+=(_peek);
				if (_peek == '{') ++braceMatch;
				else if (_peek == '}') --braceMatch;
			}
			break;
		default:
			cout<<"unreachable state error\n";
			return false;
			break;
		}
	}
	//�����﷨��ȡ���
	translateAction(); //�Ѷ�ȡ��������stringת���ɿ�ִ�ж���
	nullableAnalyze(); //��¼���ս���Ƿ�����մ�
	_terminalTable.insert(make_pair("$", _indexSymbol)); //$��Ϊ������ս��
	_word.push_back("$");
	++_indexSymbol;

	if (_buffer != nullptr) delete[] _buffer;
	_sourcefile.close();
	cout << "reading yacc ok\n";
	return true;
}

// read addition conditions from file
// ��ȡ�������������ҵݹ�����ȼ���
bool SeuYacc::readPriority() {
	string lexeme = "";
	unsigned int curPriority = 0;
	read();
	while (true) {
		if (_peek != '%') { retract(); return true; }
		++curPriority; //����һ�����ȼ�����
		read();
		// ��ʼ��ȡһ��%����ַ�
		if (_peek == 'l') {
			read(); if (_peek != 'e') return false;
			read(); if (_peek != 'f') return false;
			read(); if (_peek != 't') return false;
			// ���쳣��������
			read();
			while (_peek != '%') {
				if (_peek == ' ' || _peek == '\t') {}
				else if (_peek == '\'') { //������
					lexeme = "";
					read();
					while (_peek != '\'') //��δ����������ʾ�÷���δ����
					{ lexeme.operator+=(_peek); read(); } //��ǰ������������lexeme��
					_terminalTable.insert(make_pair(lexeme, _indexSymbol)); //�ս�������������index����������ţ�
					_priority.insert(make_pair(_indexSymbol, curPriority)); //���ȼ����������index�����ȼ�
					_leftAssociative.insert(make_pair(_indexSymbol, true));	//���ϱ��������index����������
					_word.push_back(lexeme); //word����һ���ʣ���������
					++_indexSymbol;
				}
				read();
			}
		}
		else if (_peek == 'r') {
			read(); if (_peek != 'i') return false;
			read(); if (_peek != 'g') return false;
			read(); if (_peek != 'h') return false;
			read(); if (_peek != 't') return false;
			read();
			while (_peek != '%') {
				if (_peek == ' ' || _peek == '\t') {}
				else if (_peek == '\'') {
					lexeme = "";
					read();
					while (_peek != '\'') { lexeme.operator+=(_peek); read(); }
					_terminalTable.insert(make_pair(lexeme, _indexSymbol));
					_priority.insert(make_pair(_indexSymbol, curPriority));
					_leftAssociative.insert(make_pair(_indexSymbol, false));
					_word.push_back(lexeme);
					++_indexSymbol;
				}
				read();
			}
		}
		else if (_peek == '%') {  //����������ȡ��
			return true;   
		}
	}
}

// read a char from sourse file����ȡһ���ַ�����ȡ��֮����
bool SeuYacc::read() {
	if (_offset == -1) {
		if (!_sourcefile.eof()) {
			_sourcefile.getline(_buffer, 100);
			++_line;
		}
		else
			return false;
	}
	++_offset;
	if (_offset == strlen(_buffer)) {
		_offset = -1;
		read();
	}
	else {
		_peek = _buffer[_offset];
		//if (_peek == ' ' || _peek == '\t' || _peek == '\n') read();
		if (_peek == '\n') read();
	}
	return true;
}

// retract the char back to stream
void SeuYacc::retract() {
	//_sourcefile.putback(_peek);
	if (_offset == -1) _offset = strlen(_buffer);
	_offset -= 1;
}

bool SeuYacc::isLetterOrDigit(char ch) { 
	return ('A' <= ch && ch <= 'Z')
		|| ('a' <= ch && ch <= 'z')
		|| ('0' <= ch && ch <= '9');
}
// �Ƿ�Ϸ��ַ�
bool SeuYacc::isLegalLetter(char ch) {
	return (isLetterOrDigit(ch) || ch == '_');
}

// content : _nonterminalTable construct
// effect  : alter _nonterminalNullable value
void SeuYacc::nullableAnalyze() {
	auto termEnd = _nonterminalNullable.end();
	bool continueFlag = true;
	while (continueFlag) {
		continueFlag = false;
		for (auto& X : _nonterminalNullable) {
			if (X.second == true) continue;
			else {
				// check all production X->...
				for (auto& prod : _productionVector) {
					if (prod._head == X.first) {
						// check X->ABC..., where A,B,C,.. are all nullable
						auto bodyIT = prod._bodyList.begin(), bodyEnd = prod._bodyList.end();
						for (; bodyIT != bodyEnd; ++bodyIT) {
							auto found = _nonterminalNullable.find(*bodyIT);
							if (found == termEnd || found->second == false) break; //û���ҵ��ܲ����մ��ķ��ս��
						}
						// X is nullable, new one
						if (bodyIT == bodyEnd) {
							X.second = true;
							continueFlag = true;
						}
					}
				} // end for each in _productionVector
			}
		} // end for each in _nonterminalNullable
	} // end wh	ile
}

// content : auto construct state transition
// ��ʼ��LR1�����Զ���������I0״̬����������չ״̬�õ����յ������Զ���
void SeuYacc::initTransition() {
	// add the first state H
	LR1State H;
	set<ElementType> predSet;
	predSet.insert(_terminalTable.find("$")->second);
	H.addItem(LR1Item(&_productionVector.front(), predSet));  // S'->S��$
	_LR1stateTransition.push_back(TransitionItem(LRClosure(H), 0)); // ������Ӧ�ıհ�
	// ״̬�ߵ���չ
	// inner-state-extension and between-state-extension
	IDType maxState = 1;
	for (IDType k = 0; k < maxState; ++k) { //��0״̬�����״̬��ʼ����
		// check all symbols whether current state has a out-edge
		for (IDType edge = 0; edge < _indexSymbol; ++edge) {
			LR1State newState = GOTO(_LR1stateTransition.at(k).LR1state, edge); //Ѱ������������Ų�������״̬
			// transition construct
			if (!newState.itemList.empty()) {
				bool newStateFlag = true;
				for (auto& m : _LR1stateTransition) {
					if (m.LR1state.equal(newState)) {
						// the state has existed, insert out-edge
						_LR1stateTransition.at(k).TransMap.insert(make_pair(edge, m.index));
						newStateFlag = false;
						break;
					}
				}
				if (newStateFlag) {
					// create a new state in transition table
					_LR1stateTransition.push_back(TransitionItem(newState, maxState)); //��״̬�������
					_LR1stateTransition.at(k).TransMap.insert(make_pair(edge, maxState));
					++maxState;
				}
			}
		}
	}
}

// auto construct _LR1parseTable
void SeuYacc::initParseTable() {
	for (IDType state = 0, maxState = _LR1stateTransition.size(); state < maxState; ++state) {
		vector<TableItem> temp(_indexSymbol);
		// for end state, make reduction action
		for (auto& p : _LR1stateTransition.at(state).LR1state.itemList) { //����ĳ��״̬��ĳ������ʽ
			if (p._dot == p._prod->_bodyList.end()) { //���Ƶ��������Ҫ���й�Լ
				for (auto& pred : p._predSet) { //����Ԥ����Ĺ�Լ��
					TableItem &curItem = temp.at(pred);
					switch (curItem.action) {
					case ERROR: //TableItem��ʼ���ո��Ӷ�ΪERROR
						// no table item now
						// ��p._prod->_index�������ʽ���й�Լ
						curItem = TableItem(REDUCTION, p._prod->_index);// terminal, action reduction
						if (p._prod->_index == 0) //��0�����ʽ����ʼ����S'
							curItem = TableItem(ACCEPT, p._prod->_index);// terminal, action reduction
						break;
					default:
						// ��Լ-��Լ��ͻ
						//error("warning : state " + to_string(state) + " occurs reduce-reduce conflict");
						//error("state transition table should be initialed by error state");
						break;
					}
				}
			}
		}
		// shift action
		for (auto& tran : _LR1stateTransition.at(state).TransMap) {
			TableItem &curItem = temp.at(tran.first);
			if (curItem.action == ERROR) {
				// no table item now
				if (_nonterminalNullable.find(tran.first) == _nonterminalNullable.end())
					curItem = TableItem(SHIFT, tran.second);// terminal, action
				else
					curItem = TableItem(GOTO_STATE, tran.second);// nonterminal, goto
			}
			else if (curItem.action == REDUCTION) {
				// ��������-��Լ��ͻ���ø�������������ͻ
				// solving shift-reduce conflixt
				// reduce action is done before
				unsigned int reduceOP = _indexSymbol;
				// find the last terminial as reduceOP
				auto list = _productionVector.at(curItem.index)._bodyList;
				for (auto it = list.rbegin(); it != list.rend(); ++it) {
					if (_nonterminalNullable.find(*it) == _nonterminalNullable.end()) {
						reduceOP = *it;
						break;
					}
				}
				// ���ݳ�ͻ��������Ӧ����SHIFT����
				// tran.first��ʾת��ʱ����Ĳ����������Լ���Ž���conflictSolve
				if (reduceOP != _indexSymbol && conflictSolve(tran.first, reduceOP) == SHIFT) {
					curItem = TableItem(SHIFT, tran.second);
				}
			}
			else if (curItem.action == SHIFT) {
				//error("no possible for shift occur before");
			}
			else {
				//error("illegal state transition table item action");
			}
		}
		_LR1parseTable.push_back(temp);
	}
}

// content : transfer LR(1) TO LALR(1)
// return  : true if succeed; false if fail
bool SeuYacc::transformIntoLALR() {
	map<IDType, IDType> mergeMap;
	// find same core state from last to one
	for (IDType checkState = _LR1parseTable.size() - 1; 0 < checkState; --checkState) {
		for (IDType it2State = 0; it2State < checkState; ++it2State) {
			auto& finalState = _LR1stateTransition.at(it2State).LR1state
				, tomergeState = _LR1stateTransition.at(checkState).LR1state;
			// �ҵ���������ʽ���ˣ�����ͬ��״̬
			if (finalState.equalSameCore(tomergeState)) {
				mergeMap.insert(make_pair(checkState, it2State));
				break;
			}
		}
	}
	// make LALR_state_transition
	for (IDType index = 0; index < _LR1stateTransition.size(); ++index) {
		if (mergeMap.find(index) == mergeMap.end())
			// it is not a merge_need state,preserve it
			// û����Ҫ�ϲ��Ĳ���ʽ��ֱ�ӱ���LR1��state
			_LALR1stateTransition.insert(make_pair(index, _LR1stateTransition[index]));
	}
	// add the merged item list to the merge final one
	for (auto it : mergeMap) {
		// ȡ��mergeMap��ͬ��״̬�ĵ�һ��state��LR1state
		auto& mergeFinalState = _LALR1stateTransition.find(it.second)->second.LR1state;
		for (auto& itemListIt : _LR1stateTransition.at(it.first).LR1state.itemList) {
			mergeFinalState.addItem(itemListIt);
		}
	}

	// construct LALR_parsing table
	for (IDType curstate = 0; curstate != _LR1parseTable.size(); ++curstate) {
		vector<TableItem> newLine(_LR1parseTable [curstate]);
		// update _index to after-merge state id
		// ����LR1parseTableÿһ��״̬�е�ÿһ���޸�SHIFT��GOTO_STATE������״̬
		for (auto& it4 : newLine) {
			if (it4.action == SHIFT || it4.action == GOTO_STATE) {
				auto found = mergeMap.find(it4.index);
				if (found != mergeMap.end()) {
					it4.index = found->second;
				}
			}
		}
		// ���LR1parseTable�в�ͬ״̬��ͬ�˵�״̬�ϲ�
		auto found = mergeMap.find(curstate);
		if (found == mergeMap.end()) {
			// it is not a merge-need state
			_LALR1parseTable.insert(make_pair(curstate, newLine));
		}
		else {
			// merge same core states
			// �������״̬��ͬ�����н��кϲ�
			auto mergeFinalTranItr = _LALR1parseTable.at(found->second).begin();  // ȡ�����ձ�����LALR1parseTable��һ��
			for (auto& toMergeTran : newLine) {
				if (toMergeTran.action == REDUCTION || toMergeTran.action == SHIFT || toMergeTran.action == GOTO_STATE) {
					if (toMergeTran.action == mergeFinalTranItr->action && toMergeTran.index != mergeFinalTranItr->index) {
						return false;
					}
					*mergeFinalTranItr = toMergeTran;
				}
				++mergeFinalTranItr;
			}
		}
	}
	cout << "success to construct LALRparseTable!" << endl;
	return true;
}

// content : LRClosure(T) is T with extended layer FAs
// return  : LRClosure(T)
// ��LR1״̬�ıհ�
SeuYacc::LR1State SeuYacc::LRClosure(LR1State T) {
	for (auto& A : T.itemList) {
		// dot at the end
		if (A._dot == A._prod->_bodyList.end()) {
			continue;
		}
		for (auto &it2 : _productionVector) {
			if (it2._head == *(A._dot)) {
				// A->��B������BΪ��ͷ�Ĳ���ʽ
				auto next = A._dot; ++next;
				// A->B, add B->xxx to T
				// A->B֮��û���������ţ���B->xxx��Ԥ�����A->B��ͬ
				// A->a��Bb��B->xxx��Ԥ���ΪFIRST���¦���
				if (next == A._prod->_bodyList.end()) {
					T.addItem(LR1Item(&it2, A._predSet));
				}
				else {
					auto found = _nonterminalNullable.find(*next);
					if (found == _nonterminalNullable.end()) {
						// A->a.Bb b, b is terminal
						set<ElementType> set; set.insert(*next);
						T.addItem(LR1Item(&it2, set));
					}
					else if (found->second) {
						// A->a.BCDE.., C can be empty
						set<ElementType> firstC = First(*next); //�õ�C��FIRST����
						firstC.erase(find(firstC.begin(), firstC.end(), EPLISON)); // erase empty
						firstC.insert(A._predSet.begin(), A._predSet.end()); // copy preSet to first(C)

						// add first(symbol DE...) to firstC
						auto next2 = next; ++next2;
						while (next2 != A._prod->_bodyList.end()) {
							auto found2 = _nonterminalNullable.find(*next2);
							if (found2 == _nonterminalNullable.end()) {
								// A->a.BCDE..., next2 D is terminal
								set<ElementType> set; set.insert(*next);
								firstC.insert(*next2);
								break;
							}
							// A->a.BCDE..., next2 D can be empty
							else if (found2->second) {
								set<ElementType> firstD = First(*next2);
								firstD.erase(find(firstD.begin(), firstD.end(), EPLISON)); // erase empty
								firstC.insert(firstD.begin(), firstD.end());
								++next2;
							}
							// A->a.BCDE..., next2 D can not be empty
							else {
								set<ElementType> firstD = First(*next2);
								firstC.insert(firstD.begin(), firstD.end());
								break;
							}
						}
						T.addItem(LR1Item(&it2, firstC));
					}
					else {
						// A->a.BCD, C can not be empty
						T.addItem(LR1Item(&it2, First(*next)));
					}

				}
			}
		} // end for each in _productionVector
	} // end for each in T._itemList
	return T;
}

// content : h with edge X to GOTO(T)
// return  : GOTO(T)
// LR1State h��������edgeת������״̬
SeuYacc::LR1State SeuYacc::GOTO(LR1State h, ElementType edge) {
	LR1State result;
	for (auto& it : h.itemList) {
		if (it._dot != it._prod->_bodyList.end() && *(it._dot) == edge) {
			// shift, reserve same predictive symbol
			LR1Item item(it);
			++(item._dot);
			result.addItem(item);
		}
	}
	if (!result.itemList.empty())
		return LRClosure(result);
	else
		return result; // no such transition edge
}

// content : First(X) is all terminials X begins with
// �ɴ��ķ������Ƶ����Ĵ����׷��ŵļ���
// return  : First(X)
set<SeuYacc::ElementType> SeuYacc::First(ElementType X) {
	// check whether First(X) has done
	auto foundFirstSet = _firstMap.find(X);
	if (foundFirstSet != _firstMap.end()) return foundFirstSet->second;
	// calculate First(X)
	set<ElementType> result;
	auto foundX = _nonterminalNullable.find(X);
	if (foundX == _nonterminalNullable.end()) {
		// X is terminal, First(X) = {X}
		result.insert(X);
	}
	else {
		if (foundX->second == true) {
			result.insert(EPLISON); // X can be empty
		}
		// find all productions with X as head
		for (auto& it : _productionVector) {
			if (it._head == X) {
				if (it._bodyList.empty()) continue; // X->empty
				if (*it._bodyList.begin() == X) continue; // X->X...
				for (auto it2 : it._bodyList) {
					//X->AYB
					auto foundA = _nonterminalNullable.find(it2);
					if (foundA == _nonterminalNullable.end()) {
						// A is terminal, add A to First(X)
						result.insert(it2);
						break;
					}
					else if (foundA->second == false) {
						// A is nonterminal and A is not nullable, add First(A) to First(X)
						if(foundA == foundX)break;
						set<ElementType> firstIT2 = First(it2);
						result.insert(firstIT2.begin(), firstIT2.end());
						break;
					}
					else {
						// A is nonterminal and A is nullable, add {First(A)-EPLISON} to First(X) 
						if(foundA == foundX)continue;
						set<ElementType> firstIT2 = First(it2);
						firstIT2.erase(find(firstIT2.begin(), firstIT2.end(), EPLISON)); // erase empty
						result.insert(firstIT2.begin(), firstIT2.end());
					}
				}
			}
		}
	}
	_firstMap.insert(make_pair(X, result));
	return result;
}

// content : Follow(X) is all terminials X being front of
// �����ڷ��ս��X֮���ս���ŵļ���
// return  : Follow(X)

//incorrect and needless
set<SeuYacc::ElementType> SeuYacc::Follow(ElementType X) {
	set<ElementType> result;
	if (_productionVector.begin()->_head == X)  // X is start symbol
		result.insert(_terminalTable.find("$")->second);
	for (auto& it :_productionVector) {
		for (auto it2 = it._bodyList.begin(), it2End = it._bodyList.end(); it2 != it2End; ++it2) {
			if (*it2 == X) {
				// A->abcdXBCD..., next is B 
				auto next = it2; ++next;
				if (next == it2End) {
					if (it._head == X) break; // X->XB
					// A->abcdX, add first(A) to Follow(X)
					set<ElementType> firstIT2 = First(it._head);
					result.insert(firstIT2.begin(), firstIT2.end());
					break;
				}
				else {
					if (_nonterminalNullable.find(*next)->second == false) {
						// A->abcdXB..., B is not nullable, add first(B) to Follow(X)
						set<ElementType> firstIT2 = First(*next);
						result.insert(firstIT2.begin(), firstIT2.end());
						break;
					}
					else {
						// A->abcdXB..., B is nullable, add {first(B)-EPLISON} to Follow(X)
						set<ElementType> firstIT2 = First(*next);
						firstIT2.erase(find(firstIT2.begin(), firstIT2.end(), EPLISON)); // erase EPLISON

						// A->abcdXBCDE..., add first(symbol DE...) to firstC
						auto next2 = next; ++next2;
						while (next2 != it2End) {
							auto found2 = _nonterminalNullable.find(*next2);
							if (found2 == _nonterminalNullable.end()) {
								//A->aXBCDE..., next2 is terminal, add it to First(it2)
								firstIT2.insert(*next2);
								break;
							}
							else if (found2->second) {
								//A->aXBCDE..., next2 can be empty, add {First(D)-EPLISON} to First(C)
								set<ElementType> firstD = First(*next2);
								firstD.erase(find(firstD.begin(), firstD.end(), EPLISON)); // erase empty
								firstIT2.insert(firstD.begin(), firstD.end());
							}
							else {
								//A->aXBCDE..., next2 can not be empty, add First(D) to First(C)
								set<ElementType> firstD = First(*next2);
								firstIT2.insert(firstD.begin(), firstD.end());
								break;
							}
							++next2;
						}
						// add first(C) to Follow(X)
						result.insert(firstIT2.begin(), firstIT2.end());
						break;
					}
				}
			}
		}
	} // end for each in _productionVector
	return result;
}

// content : Follow(X) is all terminials X being front of
// return SHIFT or REDUCTION based on the adddtional condition
SeuYacc::ACTION_TYPE SeuYacc::conflictSolve(ElementType shiftOP, ElementType reduceOP) {
	auto sOp = _priority.find(shiftOP), rOp = _priority.find(reduceOP);

	if (sOp == _priority.end()) return REDUCTION;
	else if (rOp == _priority.end()) return SHIFT;
	else {
		// both priority is declared in file
		if (sOp->second < rOp->second) return REDUCTION;
		else if (rOp->second < sOp->second) return SHIFT;
		else {
			// equal priority, then judge left associatity
			return _leftAssociative.at(shiftOP) ? REDUCTION : SHIFT;
		}
	}
}

//generate parsing main function
void SeuYacc::generateParsingProgram() {
	_outputFile << "#include \"lex.h\"\n";
	_outputFile << "#include \"yaccHelp.h\"\n";

	outputTable();
	outputAction();
	outputLRParsingTable();
	outputLRStateSet();
	outputnonterminal();

	_outputFile << "int main(int argc, char *argv[]) {\n";
	_outputFile << "	if (argc < 2) {\n";
	_outputFile << "		cout << \"please input the target source file name\" << endl;\n";
	_outputFile << "		return 1;\n";
	_outputFile << "	}\n";
	_outputFile << "	list<Token> tokenlist;\n";
	_outputFile << "	lexParse(argv[1], tokenlist);\n";
	_outputFile << "	yaccReduce(tokenlist);\n";
	_outputFile << "	cout << \"compile success\" << endl;\n";
	_outputFile << "	return 0;\n";
	_outputFile << "}";
}

void SeuYacc::outputLRStateSet() {
	ofstream file;
	file.open("LR(1)_state_sets.txt", ios::out);

	if (!_LALR1stateTransition.empty()) {
		file << "number of states :" << _LALR1stateTransition.size() << endl;
		for (auto& stateIt : _LALR1stateTransition) {
			file << stateIt.first << ":" << endl;
			for (auto& lr1Item : stateIt.second.LR1state.itemList) {
				// output production with shift dot
				ProductionItem* prod = lr1Item._prod;
				auto it3 = prod->_bodyList.begin(), it3End = prod->_bodyList.end();
				file << "(" << _word.at(prod->_head).c_str() << "->";
				while (it3 != lr1Item._dot) {
					file << _word.at(*it3).c_str();
					++it3;
				}
				file << ".";
				while (it3 != it3End) {
					file << _word.at(*it3).c_str();
					++it3;
				}
				file << ",";
				// output predictives
				auto it4 = lr1Item._predSet.begin(), it4End = lr1Item._predSet.end();
				if (it4 != it4End) {
					file << _word.at(*it4).c_str(); ++it4;
					for (; it4 != it4End; ++it4) {
						file << '|' << _word.at(*it4).c_str();
					}
				}
				file << ')' << endl;
			}
			file << endl;
		}
	}
	else {
		file << "number of states :" << _LR1stateTransition.size() << endl;
		int stateIndex = 0;
		for (auto& stateIt : _LR1stateTransition) {
			file << stateIndex++ << ":" << endl;
			for (auto& lr1Item : stateIt.LR1state.itemList) {
				// output production with shift dot
				ProductionItem* prod = lr1Item._prod;
				auto it3 = prod->_bodyList.begin(), it3End = prod->_bodyList.end();
				file << "(" << _word.at(prod->_head).c_str() << "->";
				while (it3 != lr1Item._dot) {
					file << _word.at(*it3).c_str();
					++it3;
				}
				file << ".";
				while (it3 != it3End) {
					file << _word.at(*it3).c_str();
					++it3;
				}
				file << ",";
				// output predictives
				auto it4 = lr1Item._predSet.begin(), it4End = lr1Item._predSet.end();
				if (it4 != it4End) {
					file << _word.at(*it4).c_str(); ++it4;
					for (; it4 != it4End; ++it4) {
						file << '|' << _word.at(*it4).c_str();
					}
				}
				file << ')' << endl;
			}
			file << endl;
		}
	}

	file.close();
}


void SeuYacc::outputLRParsingTable() {
	ofstream file;
	file.open("LR(1)_parsing_table.txt", ios::out);

	if (!_LALR1parseTable.empty()) {
		for (auto& item : _LALR1parseTable) {
			file << "state " << item.first << endl;
			for (ElementType edge = 0; edge < _indexSymbol; ++edge) {
				switch (item.second[edge].action) {
				case SHIFT:
					file << _word.at(edge) << " S " << item.second[edge].index << endl; break;
				case REDUCTION:
					file << _word.at(edge) << " R " << item.second[edge].index << endl; break;
				case ACCEPT:
					file << _word.at(edge) << " accept" << endl; break;
				case GOTO_STATE:
					file << _word.at(edge) << " G " << item.second[edge].index << endl; break;
				}
			}
			file << endl;
		}
	}
	else {
		int stateIndex = 0;
		for (auto& item : _LR1parseTable) {
			file << "state " << stateIndex++ << endl;
			for (ElementType edge = 0; edge < _indexSymbol; ++edge) {
				switch (item[edge].action) {
				case SHIFT:
					file << _word.at(edge) << " S " << item[edge].index << endl; break;
				case REDUCTION:
					file << _word.at(edge) << " R " << item[edge].index << endl; break;
				case ACCEPT:
					file << _word.at(edge) << " accept" << endl; break;
				case GOTO_STATE:
					file << _word.at(edge) << " G " << item[edge].index << endl; break;
				}
			}
			file << endl;
		}
	}
	
	file.close();
}
// ������ս���������﷨������
void SeuYacc::outputnonterminal() {
	ofstream file;
	file.open("LR(1)_nonterminal.txt", ios::out);
	for (auto& item : _nonterminalTable) {
		file << item.first << " " << item.second << endl;
	}
}
// ��LALR��������case��ʽ�����h�ļ����﷨����ʱ����
void SeuYacc::outputTable() {
	ofstream out("tableYacc.h");
	out << "#ifndef _TABLE_YACC_H\n";
	out << "#define _TABLE_YACC_H\n";
	out << "#include \"StructDefine.h\"\n";
	out << "#include <vector>\n";
	out << "#include <map>\n";
	out << "void initTable(map<unsigned int, map<string, TableItem> >& _parseTable) {\n";
	out << "\tmap<string, TableItem> tran;\n";
	if (!_LALR1parseTable.empty()) {
		// TableItem��һ���ʾ�������ڶ����ʾ����ʽ��Ż���ת��״̬
		for (auto& item : _LALR1parseTable) {
			out << "\t// state " << item.first << endl;
			for (ElementType edge = 0; edge < _indexSymbol; ++edge) {
				if (item.second[edge].action != ERROR) {
					// _word.at(edge)��ʾ��һ����ȡ�ı�
					out << "\ttran.insert(make_pair(\"" << _word.at(edge) << "\", TableItem("
						<< item.second[edge].action << "," << item.second[edge].index << ")));\n";
				}
			}
			out << "\t_parseTable.insert(make_pair(" << item.first << ",tran));\n";
			//out << "tran.swap(map<string, TableItem>());\n\n";
			out << "\ttran.clear();\n\n";
			out << endl;
		}
	}
	else {
		for (int i = 0; i < _LR1parseTable.size(); ++i) {
			// ״̬i��LALR�������i�У�
			out << "\t// state " << i << endl;
			auto& item = _LR1parseTable.at(i);
			// ���һ��״̬�Ķ�����ߣ�ִ�ж���������������tableYacc�ļ���
			for (ElementType edge = 0; edge < _indexSymbol; ++edge) {
				// 
				if (item.at(edge).action != ERROR) {
					out << "\ttran.insert(make_pair(\"" << _word.at(edge) << "\", TableItem("
						<< item.at(edge).action << "," << item.at(edge).index << ")));\n";
				}
			}
			out << "\t_parseTable.insert(make_pair(" << i << ",tran));\n";
			//out << "tran.swap(map<string, TableItem>());\n\n";
			out << "\ttran.clear();\n\n";
			out << endl;
		}
	}

	out << "}\n";
	out << "#endif \n";
	out.close();
}

// translate action string to runnable one
/*   
	 �����м�������ɣ���Ԫʽ��
	 �����﷨��ÿһ������ʽ��һ�������洢��_productionAction��,���ݶ������з���
	 �������ض�����ʽʱ������д��һЩ״̬�ͻ���
	 �﷨�Ƶ�����������ķ��м������Ժ͸��ֶ�������Щ��������Ҳ��������ġ����롱��
	 ���������������������������Ҫ���е�һЩ��������صķ��������������ͼ�飩
	 ��Ӧ�����м��������ݽṹ�����StructDefine.h������
*/
void SeuYacc::translateAction() {
	for (auto& mapAction : _productionAction) {
		string action = mapAction.second;
		string actionTranslate;
		size_t index = 0, indexEnd = action.length();
		// �ӵ�һ���ַ���ʼ���η���
		while (index != indexEnd) {
			if (action[index] == '$') {
				++index;
				if (action[index] == '$') {
					++index; ++index;// skip dot  $$.����.֮����ַ�
					string strAttr;
					while (isalpha(action[index])) {
						strAttr += action[index];
						++index;
					}
					actionTranslate += "reduceHead[\"" + strAttr + "\"]";
				}
				else if (isdigit(action[index])) {
					int pos = action[index] - '0';
					++index;
					while (isdigit(action[index])) {
						pos = pos * 10 + (action[index] - '0');
						++index;  // �õ���pos���ַ�
					}
					++index; // skip dot
					string strAttr;
					while (isalpha(action[index])) {
						strAttr += action[index];
						++index;
					}
					// ����int���Ե�ֵҪת����int���ϴ���
					if (strAttr == "width" || strAttr == "lexval") {
						actionTranslate += "atoi(st[stackSize - " + to_string(_productionVector[mapAction.first]._bodyLength) 
							+ " + " + to_string(pos) + "]._map[\"" + strAttr + "\"].c_str())";
					}
					else {
						// �Ӳ���ʽ��ͷ����λ������($$),����ʽ�ұߵ�pos��������ֵ��Լʱ���ϴ������
						// �����_map��¼���ս��ÿ�����Ե�ֵ������Ϊ������
						actionTranslate += "st[stackSize - " + to_string(_productionVector[mapAction.first]._bodyLength) + " + " + to_string(pos) + "]._map[\"" + strAttr + "\"]";
					}
					
				}
				continue;
			}
			else if (action[index] == ';') {
				actionTranslate += ";\n";
				++index;
			}
			else if (action[index] == '|' && action[index+1] == '|') { // concat || to + 
				actionTranslate += " + ";
				++index;
				++index;
			}
			else {
				actionTranslate += action[index];
				++index;
			}
		}
		mapAction.second = actionTranslate;
	}
}

// output productions and their actions
void SeuYacc::outputAction() {
	ofstream out("actionYacc.h");
	out << "#ifndef _ACTION_YACC_H\n";
	out << "#define _ACTION_YACC_H\n";
	out << "#include \"structDefine.h\"\n";
	out << "#include \"supportFunction.h\"\n";
	out << "#include <string>\n";
	out << "#include <stack>\n";
	out << "#include <vector>\n";
	out << "#include <stdlib.h>\n";

	out << "extern unsigned int offset;\n";
	out << "string p;\n";
	// ���ÿ������ʽ����
	out << "extern deque<StackItem> st;\n";
	// ��ű�����ջ
	out << "extern stack<string> paramStack;\n";
	// ������ȡ�ַ�ִ�ж������Զ�����performAction
	out << "pair<unsigned int, string> performAction(unsigned int index, map<string, string>& reduceHead) {\n";
	out << "\tsize_t stackSize = st.size() - 1;\n";
	out << "\tswitch(index) {\n";
	for (unsigned int index = 0; index < _productionAction.size(); ++index) {

		out << "\tcase " << index << " :";
		// output production for view
		// ����ʽ��ʽ��ʾ
		out << "//" << _word.at(_productionVector[index]._head).c_str() << "->";
		for (auto& it3 : _productionVector[index]._bodyList) {
			out << _word.at(it3).c_str() << " ";
		}
		// ִ�иò���ʽ�Ķ���
		out << endl << _productionAction[index] << endl;
		out << "\treturn pair<unsigned int, string>(" 
			<< _productionVector[index]._bodyLength << ",\"" //����ʽ�Ҳ�����
			<< _word[_productionVector[index]._head] << "\");\n\n";
	}
	out << "\tdefault: return pair<unsigned int, string>(0,\"\");\n";
	out << "\t}\n";
	out << "}// end function\n";
	// ��ȡ����ʽ�������reduce_sequence
	out << "string getProduction(unsigned int index) {\n";
	out << "\tswitch(index) {\n";
	for (unsigned int index = 0; index < _productionAction.size(); ++index) {
		out << "\t\tcase " << index << " :";
		out << "return \"" << _word.at(_productionVector[index]._head).c_str() << "->";
		for (auto& it3 : _productionVector[index]._bodyList) {
			out << _word.at(it3).c_str() << " ";
		}
		out << "\";\n";
	}
	out << "\t\tdefault: return \"\";\n";
	out << "\t}\n";
	out << "}\n";
	out << "#endif\n";
	out.close();// code below is cut
	// ��¼����ʽ�������̵��﷨��
	out << "struct node {\n";
	out << "string name;\n";
	out << "vector<string> son;\n";
	out << "node(string s):name(s){}\n";
	out << "};\n";
	out << "string getTree(unsigned int index) {\n";
	out << "vector<node> tree;\n";
	out << "switch(index) {\n";
	for (unsigned int index = 0; index < _productionAction.size(); ++index) {
		out << "case " << index << " :";
		out << "node n(" << _word.at(_productionVector[index]._head).c_str() << ")";
		for (auto& it3 : _productionVector[index]._bodyList) {
			out << _word.at(it3).c_str() << " ";
		}
		out << "\";\n";
	}
	out << "default: return \"\";\n";
	out << "}\n";
	out << "}\n";
	out << "#endif //_ACTION_YACC_H\n";
	out.close();
}

#endif //_SEU_YACC_CPP
