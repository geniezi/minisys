// ����asm���������
#ifndef MY_CODE_GENERATE_H
#define MY_CODE_GENERATE_H

#define REGISTER_NUM 17

#include "structDefine.h"
#include "supportFunction.h"
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

// reg descripter table
extern vector<SymbolTable*> symbolTables;
SymbolTable* table;
vector<set<string> >* RValue;	// ��дR�Ĵ����мĴ�����Щ����
vector<int>* RNextUse;						// RNextUse����дR�Ĵ����б����Ĵ�����Ϣ��Ϊ��������д�����Ԫʽ�����С��ֵ

vector<Assembly> assemblyCode;				// �洢���еĻ�����
map<size_t, string> AssemblyLabelMap;	// ��¼������ı�ǩ��Ϣ��keyΪ������ı�ţ�valueΪ��Ӧ�˱�ŵı�ǩ

typedef set<string> VarSetType;
varState& Getvar(string place)
{
	if (table->in(place)) return table->at(place);
	else if (constTable->in(place)) return constTable->at(place);
	else return globalTable->at(place);
}
// live_nextuse algorithm ������Ծ�������Ϣ����
void fillVarState(int beginIndex, int endIndex, const VarSetType& outLiveVar, VarSetType& inLiveVar) {
	// table init with outLiveVar

	// ���ڻ�Ծ����_live��������Ϊ��Ծtrue
	for (auto& var : outLiveVar) {
		Getvar(var)._live = true;
		Getvar(var)._nextUse = endIndex;
	}

	// �������ݿ�����������Ԫʽ
	for (int i = endIndex - 1; beginIndex <= i; --i) {
		auto& code = middleCode.at(i);
		if (code._type == 7) continue; // call N funName
		if (code._arg1 == "#") { //��ǰ��������
			code._liveDes = Getvar(code._des)._live;
			code._nextDes = Getvar(code._des)._nextUse;
			Getvar(code._des)._live = false;
			Getvar(code._des)._nextUse = -1;
			continue;
		}
		bool desExsitFlag = !(code._des.empty() || code._op[0] == 'j');
		bool arg1ExsitFlag = !code._arg1.empty();
		bool arg2ExsitFlag = !code._arg2.empty();

		// �����ű��б���A, B, C��Live��Next - Use�����A, B, C�ĸ�����Ϣ������

		// fill code var state live from symbol table
		if (desExsitFlag) code._liveDes = Getvar(code._des)._live;
		if (arg1ExsitFlag) code._liveArg1 = Getvar(code._arg1)._live;
		if (arg2ExsitFlag) code._liveArg2 = Getvar(code._arg2)._live;

		// fill code var state next use from symbol table
		if (desExsitFlag) code._nextDes = Getvar(code._des)._nextUse;
		if (arg1ExsitFlag) code._nextArg1 = Getvar(code._arg1)._nextUse;
		if (arg2ExsitFlag) code._nextArg2 = Getvar(code._arg2)._nextUse;

		// erase des state in symbol table
		// ������ű���A��Live��Next - Use��
		if (desExsitFlag) {
			Getvar(code._des)._live = false;
			Getvar(code._des)._nextUse = -1;
		}

		// set arg1,arg2 state in symbol table
		// �����ű���B, C��Live��Ϊtrue, Next - Use��Ϊi
		if (arg1ExsitFlag) {
			Getvar(code._arg1)._live = true;
			Getvar(code._arg1)._nextUse = i;
		}

		if (arg2ExsitFlag) {
			Getvar(code._arg2)._live = true;
			Getvar(code._arg2)._nextUse = i;
		}
	}

	// generate inLivaVar
	for (auto& var : table->_field) {
		if (var._live == true && var._space != 0) {
			inLiveVar.insert(var._place);
		}
		// clear table
		var._live = false;
		var._nextUse = -1;
	}
}

// ��ȡ�յļĴ������
int getEmptyReg() {
	auto availReg = find(RValue->begin(), RValue->end(), set<string>());	// auto& -> auto
	if (availReg != RValue->end()) {
		return availReg - RValue->begin();
	}
	else return -1;
}

// ����û�пռĴ�������ҼĴ��������滻�㷨
int storeToGetReg() {
	// find one available register
	int furthestUseCode = -1;
	int regReturn = -1;
	for (int Reg = 0; Reg < REGISTER_NUM; ++Reg) {
		// find one reg whose var has copy in memory and will be uesd furthest
		int varNotInM = 0;
		for (const auto& var : RValue->at(Reg)) {
			if (Getvar(var)._inM == false)
				++varNotInM;
		}
		// �ڳ��Ĵ���Ri
		if (0 < varNotInM && furthestUseCode < RNextUse->at(Reg)) {
			regReturn = Reg;
			furthestUseCode = RNextUse->at(Reg);
		}
	}
	if (regReturn < 0) {
		// when all var not in memoty
		// need optimize
		// do not optimize
		regReturn = 0;
	}

	// store var not in memory
	for (auto& var : RValue->at(regReturn)) {
		if (Getvar(var)._inM == false) {
			// ����Ri���������ڴ����޸���ʱ����
			assemblyCode.push_back(Assembly("sw", regReturn, var));	// MOV regReturn var -> ADDI regReturn var 0
		}
		Getvar(var)._inR = -1;	//�����κμĴ�����
		Getvar(var)._inM = true; //���ڴ����и���
	}
	return regReturn;
}
//imm -> reg
void imm2reg(int imm,int reg)
{
	int x_l = imm & ((1 << 13) - 1);
	int x_u = (imm - x_l)>>12;
	if (x_u == 0)
	{
		assemblyCode.push_back(Assembly("addi", reg, "x0", x_l));
	}
	else
	{
		assemblyCode.push_back(Assembly("lui", reg, x_u));
		assemblyCode.push_back(Assembly("addi", reg, reg, x_l));
	}
	set<string> set;
	set.insert(to_string(imm));
	RValue->at(reg) = set;
}
void imm2reg(int imm, string reg)
{
	int x_l = imm & ((1 << 13) - 1);
	int x_u = (imm - x_l) >> 12;
	if (x_u == 0)
	{
		assemblyCode.push_back(Assembly("addi", reg, "x0", x_l));
	}
	else
	{
		assemblyCode.push_back(Assembly("lui", reg, x_u));
		assemblyCode.push_back(Assembly("addi", reg, reg, x_l));
	}
}
// code : A = B op C
// _des, _arg1, _arg2
void Assembly_A_BopC(const Quadruple& code) {

	int RegForC = Getvar(code._arg2)._inR;
	int RegForB = Getvar(code._arg1)._inR;
	int RegForA = Getvar(code._des)._inR;
	if(RegForA<0)
	{
		RegForA = getEmptyReg(); // ����ռĴ���
		if (RegForA < 0) RegForA = storeToGetReg(); // ����滻�Ĵ���
		set<string> set;
		set.insert(code._des);
		RValue->at(RegForA) = set;
		RNextUse->at(RegForA) = code._nextDes;
		Getvar(code._des)._inR = RegForA;
		Getvar(code._des)._inM = false;
	}
	if (RegForB < 0) {
		if (code._typeArg1)
		{
			RegForB = getEmptyReg();
			if (RegForB < 0) RegForB = storeToGetReg();
			set<string> set;
			RValue->at(RegForB) = set;
			RNextUse->at(RegForB) = -1;
			int x=atoi(code._arg1.c_str());
			imm2reg(x, RegForB);
		}
		else
		{
			RegForB = getEmptyReg();
			if (RegForB < 0) RegForB = storeToGetReg();
			set<string> set; set.insert(code._arg1);
			RValue->at(RegForB) = set;
			RNextUse->at(RegForB) = -1;
			Getvar(code._arg1)._inR = RegForB;
			Getvar(code._arg1)._inM = true;
			assemblyCode.push_back(Assembly("lw", RegForB, code._arg1));
		}
	}
	if (RegForC < 0) {
		if (code._typeArg2)
		{
			RegForC = getEmptyReg();
			if (RegForC < 0) RegForC = storeToGetReg();
			set<string> set;
			RValue->at(RegForC) = set;
			RNextUse->at(RegForC) = -1;
			int x = atoi(code._arg2.c_str());
			imm2reg(x, RegForC);
		}
		else
		{
			RegForC = getEmptyReg();
			if (RegForC < 0) RegForC = storeToGetReg();
			set<string> set; set.insert(code._arg1);
			RValue->at(RegForC) = set;
			RNextUse->at(RegForC) = -1;
			Getvar(code._arg1)._inR = RegForC;
			Getvar(code._arg1)._inM = true;
			assemblyCode.push_back(Assembly("lw", RegForC, code._arg1));
		}
	}
	assemblyCode.push_back(Assembly(code._op, RegForA, RegForB, RegForC));
	/*if (code._typeArg1) {
		// B Ϊ����
		if (RegForC < 0) {
			// C����register��
			if (RegForA < 0) {
				// A����register��
				// A����register
				RegForA = getEmptyReg(); // ����ռĴ���
				if (RegForA < 0) RegForA = storeToGetReg(); // ����滻�Ĵ���
				set<string> set;
				set.insert(code._des);
				RValue->at(RegForA) = set;
				RNextUse->at(RegForA) = code._nextDes;
				Getvar(code._des)._inR = RegForA;
				Getvar(code._des)._inM = false;
			}
			assemblyCode.push_back(Assembly("lw", RegForA,   code._arg2  , ""));		// MOV RegForA code._arg2 -> LW regForA 0(aode.arg2)
			assemblyCode.push_back(Assembly(code._op, RegForA, code._arg1, ""));	// op RegForA B
		}
		else {
			// C��register��
			if (RegForA < 0) {
				// A in memory and C in reg
				assemblyCode.push_back(Assembly("sw", RegForC, code._des, 0));		// MOV code._des RegForC -> SW RegForC 0(code._des)
				assemblyCode.push_back(Assembly(code._op, code._des, code._arg1, ""));	// op A B
			}
			else {
				// A in reg and C in reg
				assemblyCode.push_back(Assembly("addi", RegForA, RegForC, 0));			// MOV RegForA RegForC -> ADDI RegForA RegForC 0
				assemblyCode.push_back(Assembly(code._op, RegForA, code._arg1, ""));	// op RegForA C
				set<string> set; set.insert(code._des);
				RValue->at(RegForA) = set;
				RNextUse->at(RegForA) = code._nextDes;
				Getvar(code._des)._inR = RegForA;
				Getvar(code._des)._inM = false;
			}
		}
	}
	else if (code._typeArg2) {
		// BΪ������CΪ����
		if (RegForB < 0) {
			// B����register��
			if (RegForA < 0) {
				// A����register��
				// A����register
				RegForA = getEmptyReg();
				if (RegForA < 0) RegForA = storeToGetReg();
				set<string> set; set.insert(code._des);
				RValue->at(RegForA) = set;
				RNextUse->at(RegForA) = code._nextDes;
				Getvar(code._des)._inR = RegForA;
				Getvar(code._des)._inM = false;
			}
			assemblyCode.push_back(Assembly("addi", RegForA, "x0", code._arg2));		// MOV RegForA code._arg2 -> ADDI RegForA $0 code._arg2
			assemblyCode.push_back(Assembly(code._op, RegForA, code._arg1, ""));	// op RegForA B
		}
		else {
			// B��register��
			if (RegForA < 0) {
				// A in memory and B in reg
				assemblyCode.push_back(Assembly("sw", RegForB,  code._des , ""));		// MOV code._des RegForB -> SW RegForB 0(code._des)
				assemblyCode.push_back(Assembly(code._op, code._des, code._arg2, ""));	// op A C
			}
			else {
				// A in reg and B in reg
				assemblyCode.push_back(Assembly("addi", RegForA, RegForB, 0));			// MOV RegForA RegForB -> ADDI RegForA RegForB 0
				assemblyCode.push_back(Assembly(code._op, RegForA, code._arg2, ""));	// op RegForA C
				set<string> set; set.insert(code._des);
				RValue->at(RegForA) = set;
				RNextUse->at(RegForA) = code._nextDes;
				Getvar(code._des)._inR = RegForA;
				Getvar(code._des)._inM = false;
			}
		}
	}
	else {
		// B and C is variable, not number
		if (RegForB < 0) {
			// B����register
			// IN_R[B] != Ri
			RegForB = getEmptyReg();
			if (RegForB < 0) RegForB = storeToGetReg();
			// generate targer code
			assemblyCode.push_back(Assembly("lw", RegForB,  code._arg1 , ""));			// MOV RegForB code._arg1 -> LW RegForB 0(code._arg1)
			// RValue[Ri] = {B}, RNextUse[Ri] = B.NextUse
			set<string> set; set.insert(code._arg1);
			RValue->at(RegForB) = set;
			RNextUse->at(RegForB) = code._nextArg1;
			Getvar(code._arg1)._inR = RegForB;
			Getvar(code._arg1)._inM = true;
		}

		// select reg for A
		RegForA = RegForB;
		if (*(RValue->at(RegForA).begin()) == code._arg1 && RValue->at(RegForA).size() == 1
			&& (code._liveArg1 == false || code._arg1 == code._des)) {
			// select reg of B to store A
			// [Ri] = {B} && (B.live == false || A = A op C)
			if (-1 < RegForC) {
				// C��register��
				assemblyCode.push_back(Assembly(code._op, RegForA, RegForC, ""));		// op RegForA RegForC
			}
			else {
				// C����register��
				assemblyCode.push_back(Assembly(code._op, RegForA, code._arg2, ""));	// op RegForA C
			}
			Getvar(code._arg1)._inR = -1;
		}
		else {
			// select another reg for A
			RegForA = getEmptyReg();
			if (-1 < RegForA) {
				assemblyCode.push_back(Assembly("addi", RegForA, RegForB, 0));				// MOV RegForA RegForB -> ADDI RegForA RegForB 0
				int regC = Getvar(code._arg2)._inR;	// ������C�Ƿ���register��
														// ����Aʱ�����ƻ���C
				if (-1 < regC)
					assemblyCode.push_back(Assembly(code._op, RegForA, regC, ""));			// op RegForA C
				else
					assemblyCode.push_back(Assembly(code._op, RegForA, code._arg2, ""));	// op RegForA C
			}
			else {
				RegForA = storeToGetReg();
				assemblyCode.push_back(Assembly("addi", RegForA, RegForB, 0));				// MOV RegForA RegForB -> ADDI RegForA RegForB 0
				assemblyCode.push_back(Assembly(code._op, RegForA, code._arg2, ""));		// op RegForA C
			}
		}
		// update reg descripter table RValue[RegA] = {A}, RNextUse[RegA] = A.next
		set<string> sset; sset.insert(code._des);
		RValue->at(RegForA) = sset;
		RNextUse->at(RegForA) = code._nextDes;
		Getvar(code._des)._inR = RegForA;
		Getvar(code._des)._inM = false;

		// variable in C deal
		if (code._liveArg2 == false && -1 < RegForC) {
			RValue->at(RegForC).erase(code._arg2);
			Getvar(code._arg2)._inR = -1;
			set<string> sset = RValue->at(RegForC);
			for (const auto& var : sset) {
				auto& it = Getvar(var);
				if (it._live == false) {
					it._inR = -1;
					RValue->at(RegForC).erase(var);
				}
			}
			int nextUse = INT_MAX;
			for (auto& var : RValue->at(RegForC)) {
				nextUse = min(nextUse, Getvar(var)._nextUse);
			}
		}
	}*/
}

// code : A = op B
void Assembly_A_opB(const Quadruple& code) {
	// BΪ����
	int RegForB = Getvar(code._arg1)._inR;
	if (code._typeArg1)
	{
		int RegForB = getEmptyReg();
		if (RegForB < 0) RegForB = storeToGetReg();
		int x = atoi(code._arg1.c_str());
		imm2reg(x, RegForB);
	}
	else
	{
		if (RegForB < 0) {
			RegForB = getEmptyReg();
			if (RegForB < 0) RegForB = storeToGetReg();
			assemblyCode.push_back(Assembly("lw", RegForB, code._arg1));
			set<string> set; set.insert(code._arg1);
			RValue->at(RegForB) = set;
			RNextUse->at(RegForB) = code._nextArg1;
			Getvar(code._arg1)._inR = RegForB;
			Getvar(code._arg1)._inM = true;
		}
	}
	int RegForA = Getvar(code._des)._inR;
	if (RegForA < 0)
	{
		RegForA = getEmptyReg();
		if (RegForA < 0) RegForA = storeToGetReg();
		assemblyCode.push_back(Assembly("lw", RegForA, code._des));
		set<string> set; set.insert(code._arg1);
		RValue->at(RegForA) = set;
		RNextUse->at(RegForA) = code._nextDes;
		Getvar(code._arg1)._inR = RegForA;
		Getvar(code._arg1)._inM = true;
	}
	assemblyCode.push_back(Assembly("sub", RegForA,"x0", RegForB));
	/*int RegForB = Getvar(code._arg1)._inR;
	if (RegForB < 0) {
		// B����register��
		// IN_R[B] != Ri
		// ����B
		RegForB = getEmptyReg();
		if (RegForB < 0) RegForB = storeToGetReg();
		// generate targer code
		assemblyCode.push_back(Assembly("lw", RegForB,  code._arg1, ""));	// MOV RegForB code._arg1 -> LW RegForB 0(code._arg1)
		// RValue[Ri] = {B}, RNextUse[Ri] = B.NextUse
		set<string> set; set.insert(code._arg1);
		RValue->at(RegForB) = set;
		RNextUse->at(RegForB) = code._nextArg1;
		Getvar(code._arg1)._inR = RegForB;
		Getvar(code._arg1)._inM = true;
	}
	// B��RegForB��

	// select reg for A
	int RegForA = Getvar(code._arg1)._inR;
	if (*(RValue->at(RegForA).begin()) == code._arg1 && RValue->at(RegForA).size() == 1
		&& (code._liveArg1 == false || code._arg1 == code._des)) {
		// select reg of B to store A
		// [Ri] = {B} && (B.live == false || A = op A)
		assemblyCode.push_back(Assembly(code._op, RegForA, "", ""));		// op RegForA _
		Getvar(code._arg1)._inR = -1;
	}
	else {
		// select another reg for A
		RegForA = getEmptyReg();
		if (-1 < RegForA) {
			assemblyCode.push_back(Assembly("addi", RegForA, RegForB, 0));	// MOV RegForA RegForB -> ADDI RegForA RegForB 0
			assemblyCode.push_back(Assembly(code._op, RegForA, "", ""));	// op RegForA
		}
		else {
			RegForA = storeToGetReg();
			assemblyCode.push_back(Assembly("addi", RegForA, RegForB, 0));			// MOV RegForA RegForB -> ADDI RegForA RegForB 0
			assemblyCode.push_back(Assembly(code._op, RegForA, code._arg2, ""));	// op RegForA _
		}
	}
	// update reg descripter table RValue[RegA] = {A}, RNextUse[RegA] = A.next
	set<string> set; set.insert(code._des);
	RValue->at(RegForA) = set;
	RNextUse->at(RegForA) = code._nextDes;
	Getvar(code._des)._inR = RegForA;
	Getvar(code._des)._inM = false;*/
}

// code : A = B
void Assembly_A_B(const Quadruple& code) {

	if (code._typeArg1) {
		// BΪ����
		int RegForA = Getvar(code._arg1)._inR;
		if (RegForA < 0) {
			// A����register��
			RegForA = getEmptyReg();
			if (RegForA < 0) RegForA = storeToGetReg();
			// generate targer code
			
		}
		imm2reg(atoi(code._arg1.c_str()), RegForA);
		set<string> set; set.insert(code._des);
		RValue->at(RegForA) = set;
		RNextUse->at(RegForA) = code._nextDes;
		Getvar(code._des)._inR = RegForA;
		Getvar(code._des)._inM = false;
		return;
	}

	if (code._arg1 == "#") {
		// BΪ��������ֵ
		int RegForA = Getvar(code._des)._inR;
		if (RegForA >=0) {
			// A��register��
			RegForA = getEmptyReg();
			if (RegForA < 0) RegForA = storeToGetReg();
			// generate targer code
			set<string> set; set.insert(code._des);
			RValue->at(RegForA) = set;
			RNextUse->at(RegForA) = code._nextDes;
			Getvar(code._des)._inR = RegForA;
			Getvar(code._des)._inM = false;
		}
		assemblyCode.push_back(Assembly("add", RegForA, "x10", "x0"));	// MOV code._des AX -> ADDI RegForA "$2" 0
		return;
	}

	int RegForB = Getvar(code._arg1)._inR;
	if (RegForB < 0) {
		RegForB = getEmptyReg();
		if (RegForB < 0) RegForB = storeToGetReg();
		assemblyCode.push_back(Assembly("lw", RegForB,  code._arg1));	// MOV RegForB code._arg1 -> LW RegForB 0(code._arg1)
	}
	//����B��ֵ�ڼĴ����е��������Ҫ���ɻ����룬ֱ�Ӳ���A������A._inR
	RValue->at(RegForB).insert(code._des);
	Getvar(code._des)._inR = RegForB;
	Getvar(code._des)._inM = false;
	if (code._liveArg1 == false) {
		RValue->at(RegForB).erase(code._arg1);
		Getvar(code._arg1)._inR = -1;
	}
	// Ϊ��ָֹ���ǩλ�ó������ɡ�nop��ָ���Խ��й���
	//assemblyCode.push_back(Assembly("addi", "x0", "x0", 0));
}

// code : j LABEL_xxx
void Assembly_j(const Quadruple& code) {
	assemblyCode.push_back(Assembly("jal","x9", code._des));	// JMP des -> J code._des
}

// code : j rop B C LABEL_xxx
void Assembly_jrop(const Quadruple& code) {
	int judgment = 0;
	int RegForResult = getEmptyReg();
	if (RegForResult < 0) RegForResult = storeToGetReg();
	if (code._op == "j<" || code._op == "j>=")  judgment = 1;
	if (code._op == "j>" || code._op == "j<=")  judgment = 2;

	int RegForB = Getvar(code._arg1)._inR;
	if (RegForB < 0) {
		// IN_R[B] != Ri
		RegForB = getEmptyReg();
		if (RegForB < 0) RegForB = storeToGetReg();
		if (!code._typeArg1) {
			assemblyCode.push_back(Assembly("lw", RegForB, code._arg1));	// lw RegForB code._arg1 -> LW RegForB 0(code._arg1)
			// RValue[Ri] = {B}, RNextUse[Ri] = B.NextUse
			set<string> set; set.insert(code._arg1);
			RValue->at(RegForB) = set;
			RNextUse->at(RegForB) = code._nextArg1;
			Getvar(code._arg1)._inR = RegForB;
			Getvar(code._arg1)._inM = true;
		}
		else {
			imm2reg(atoi(code._arg1.c_str()),RegForB);
		}
	}	

	int RegForC = Getvar(code._arg2)._inR;
	if (RegForC < 0) {
		// IN_R[C] != Ri
		RegForC = getEmptyReg();
		if (RegForC < 0) RegForC = storeToGetReg();
		if (!code._typeArg2) {
			assemblyCode.push_back(Assembly("lw", RegForC,code._arg2));	// lw RegForB code._arg1 -> LW RegForB 0(code._arg1)
			// RValue[Ri] = {B}, RNextUse[Ri] = B.NextUse
			set<string> set; set.insert(code._arg2);
			RValue->at(RegForC) = set;
			RNextUse->at(RegForC) = code._nextArg2;
			Getvar(code._arg2)._inR = RegForC;
			Getvar(code._arg2)._inM = true;
		}
		else {
			imm2reg(atoi(code._arg2.c_str()), RegForC);
		}
	}
	if (judgment == 1)
		assemblyCode.push_back(Assembly("slt", RegForResult, RegForB, RegForC));	// slt code._arg1 code._arg2
	else if (judgment == 2)
		assemblyCode.push_back(Assembly("slt", RegForResult, RegForC, RegForB));
	
	string jrop = "";
	if (code._op == "j==")
	{
		assemblyCode.push_back(Assembly("beq", code._des, RegForB, RegForC));
		return;
	}
	else if (code._op == "j!=")
	{
		assemblyCode.push_back(Assembly("bne", code._des, RegForB, RegForC));
		return;
	}
	else if (code._op == "j<") {
		jrop = "bne";
	}
	else if (code._op == "j<=") {
		jrop = "beq";
	}	
	else if (code._op == "j>") {
		jrop = "bne";
	}
	else if (code._op == "j>=") {
		jrop = "beq";
	}
	assemblyCode.push_back(Assembly(jrop, RegForResult, "x0", code._des ));
}
int param_num = 0;
// code : param p
void Assembly_param(const Quadruple& code) {
	/*int regP = Getvar(code._arg1)._inR;
	if (regP < 0) {
		regP = getEmptyReg();
		if (regP < 0) regP = storeToGetReg();
		assemblyCode.push_back(Assembly("lw", regP,  code._arg1 , ""));	// MOV regP code._arg1 -> LW regP 0(code._arg1)
		set<string> set; set.insert(code._arg1);
		RValue->at(regP) = set;
		RNextUse->at(regP) = code._nextArg1;
		Getvar(code._arg1)._inR = regP;
		Getvar(code._arg1)._inM = true;
	}
	// PUSH regP 
	assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
	assemblyCode.push_back(Assembly("sw", regP, "0(x2)", ""));*/
	if (code._typeArg1)
	{
		imm2reg(atoi(code._arg1.c_str()), "x12");
		assemblyCode.push_back(Assembly("sw", "x12", "0(x2)"));
	}
	else
	{
		int regP = Getvar(code._arg1)._inR;
		param_num++;
		if (regP < 0)
		{
			assemblyCode.push_back(Assembly("lw", "x12", code._arg1));
			assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", "x12", "0(x2)"));
		}
		else
		{
			assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", regP, "0(x2)"));
		}
	}
}
// code : call N funName
void Assembly_call(const Quadruple& code) {
	// clear all registers
	for (int reg = 0; reg < REGISTER_NUM; reg++) {
		for (auto it : RValue->at(reg)){
			if (table->in(it)) {
				if (table->at(it)._inM == false) {
					assemblyCode.push_back(Assembly("sw", reg, table->at(it)._place));
				}
			}
			else if (globalTable->in(it)) {
				if (globalTable->at(it)._inM == false) {
					assemblyCode.push_back(Assembly("sw", reg, globalTable->at(it)._place));
				}
			}
		}
		RValue->at(reg).clear();
		RNextUse->at(reg) = -1;
	}
	assemblyCode.push_back(Assembly("jal","x1" ,code._arg2));	// call
	param_num = 0;
}

// code : function begin
void Assembly_function_prework(const Quadruple& code) {
	// PUSH BP
	assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
	assemblyCode[assemblyCode.size()-1]._label = code._label;
	assemblyCode.push_back(Assembly("sw", "x8", "0(x2)"));		
	// PUSH reg
	if (code._label != "main") {
			//save ra
			assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", "x1", "0(x2)"));
			//save parameters
			/*assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", "x11", "0(x2)", ""));
			assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", "x12", "0(x2)", ""));
			assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", "x13", "0(x2)", ""));
			assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", "x14", "0(x2)", ""));
			assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", "x15", "0(x2)", ""));
			assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", "x16", "0(x2)", ""));
			assemblyCode.push_back(Assembly("addi", "x2", "x2", -4));
			assemblyCode.push_back(Assembly("sw", "x17", "0(x2)", ""));*/
	}
	
	assemblyCode.push_back(Assembly("add", "x8", "x2", "x0"));	// MOV BP SP
	for (const auto& table : symbolTables) {
		if (table->_funName == code._label) {
			assemblyCode.push_back(Assembly("addi", "x2","x2", "-"+to_string(table->_variableOffset)));	// SUB SP 'offset'
			break;
		}
	}
}

// code : return B
void Assembly_return(const Quadruple& code) {
	//int RegForB = Getvar(code._arg1)._inR;
	//if (RegForB < 0) RegForB = getEmptyReg();
	//if (RegForB < 0) RegForB = storeToGetReg();

	if (table->_returnSize > 0) {
		if (code._typeArg1)
		{
			int x = atoi(code._arg1.c_str());
			imm2reg(x, "x10");
		}
		else
		{
			int RegForB = Getvar(code._arg1)._inR;
			if (-1 < RegForB) {
					// Reg for B is not AX
					assemblyCode.push_back(Assembly("add", "x10", RegForB,"x0"));	// MOV AX RegForB
			}
			else {
				assemblyCode.push_back(Assembly("lw", "x10", code._arg1));	// MOV AX code._arg1
			}
		}
		
	}
	// MOV SP BP
	assemblyCode.push_back(Assembly("add", "x2", "x8","x0"));	
	// POP regs
	/*assemblyCode.push_back(Assembly("lw", "x17", "0(x2)", ""));	
	assemblyCode.push_back(Assembly("addi", "x2", "x2", 4));
	assemblyCode.push_back(Assembly("lw", "x16", "0(x2)", ""));
	assemblyCode.push_back(Assembly("addi", "x2", "x2", 4));
	assemblyCode.push_back(Assembly("lw", "x15", "0(x2)", ""));
	assemblyCode.push_back(Assembly("addi", "x2", "x2", 4));
	assemblyCode.push_back(Assembly("lw", "x14", "0(x2)", ""));
	assemblyCode.push_back(Assembly("addi", "x2", "x2", 4));
	assemblyCode.push_back(Assembly("lw", "x13", "0(x2)", ""));
	assemblyCode.push_back(Assembly("addi", "x2", "x2", 4));
	assemblyCode.push_back(Assembly("lw", "x12", "0(x2)", ""));
	assemblyCode.push_back(Assembly("addi", "x2", "x2", 4));
	assemblyCode.push_back(Assembly("lw", "x11", "0(x2)", ""));
	assemblyCode.push_back(Assembly("addi", "x2", "x2", 4));*/
	//POP ra
	assemblyCode.push_back(Assembly("lw", "x1", "0(x2)"));
	assemblyCode.push_back(Assembly("addi", "x2", "x2", 4));
	//POP BP
	assemblyCode.push_back(Assembly("lw", "x8", "0(x2)"));	
	assemblyCode.push_back(Assembly("addi", "x2", "x2", 4));
	for (int reg = 0; reg < REGISTER_NUM; reg++) {
		for (auto it : RValue->at(reg)) {
			if (globalTable->in(it)) {
				if (globalTable->at(it)._inM == false) {
					assemblyCode.push_back(Assembly("sw", reg, globalTable->at(it)._place));
				}
			}
		}
		RValue->at(reg).clear();
		RNextUse->at(reg) = -1;
	}
	//RET 
	assemblyCode.push_back(Assembly("jalr", "x9", "0(x1)"));	
}

//gen array base address + off
//A=B.addr + off
void Assembly_addr(const Quadruple& code) {
	int pos = code._arg1.find('(');
	int x = atoi(code._arg1.substr(0, pos).c_str());
	imm2reg(x, "x9");
	int reg;
	if (code._typeArg2)
	{
		reg = getEmptyReg();
		if (reg < 0) reg = storeToGetReg();
		imm2reg(atoi(code._arg2.c_str()), reg);
	}
	else
	{
		reg = Getvar(code._arg2)._inR;
		if (reg < 0)
		{
			reg = getEmptyReg();
			if (reg < 0) reg = storeToGetReg();
			set<string> set; set.insert(code._arg2);
			RValue->at(reg) = set;
			RNextUse->at(reg) = code._nextArg2;
			Getvar(code._arg2)._inR = reg;
			assemblyCode.push_back(Assembly("lw", reg, code._arg2));
		}
	}

	int sp = Getvar(code._arg1)._space;
	int p1 = Getvar(code._arg1)._type.find(',');
	int p2 = Getvar(code._arg1)._type.find(')');
	int len = atoi(Getvar(code._arg1)._type.substr(p1+1,p2-p1-1).c_str());
	int stp = sp / len;
	int tmpreg = getEmptyReg();
	if (tmpreg < 0) tmpreg = storeToGetReg();
	assemblyCode.push_back(Assembly("addi", tmpreg, tmpreg, stp));
	assemblyCode.push_back(Assembly("mul", reg, tmpreg, reg));
	assemblyCode.push_back(Assembly("add", "x9", reg,"x9"));
}

//x9=addr
//A=B.addr+off
//A.addr+off=B
void Assembly_addroff(const Quadruple& code) {
	string base;
	if (code._des.find("x8") != code._des.npos) base = "x8";
	else base = "x3";
	assemblyCode.push_back(Assembly("add", "x9", base, "x9"));
	if (code._arg1 == "")
	{
		// left value
		int reg = Getvar(code._arg2)._inR;
		if (reg < 0)
		{
			reg = getEmptyReg();
			if (reg < 0) reg = storeToGetReg();
			set<string> set; set.insert(code._arg2);
			RValue->at(reg) = set;
			RNextUse->at(reg) = code._nextArg2;
			Getvar(code._arg2)._inR = reg;
			assemblyCode.push_back(Assembly("lw", reg, code._arg2));
		}
		assemblyCode.push_back(Assembly("sw", reg, "0(x9)"));
	}
	else
	{
		//right value
		int reg = Getvar(code._arg1)._inR;
		if (reg < 0)
		{
			reg = getEmptyReg();
			if (reg < 0) reg = storeToGetReg();
			set<string> set; set.insert(code._arg1);
			RValue->at(reg) = set;
			RNextUse->at(reg) = code._nextArg1;
			Getvar(code._arg1)._inR = reg;
			Getvar(code._arg1)._inM= false;

		}
		assemblyCode.push_back(Assembly("lw", reg, "0(x9)"));

	}
}

//gen array base address + offset
//A.addr+off=B
void Assembly_nop() {
	assemblyCode.push_back(Assembly("add", "x0", "x0", "x0"));
}

//B=load_mem(A)
void Assembly_load(const Quadruple& code) {
	int regA = Getvar(code._arg1)._inR;
	if (code._typeArg1)
	{
		regA = getEmptyReg();
		if (regA < 0) regA = storeToGetReg();
		imm2reg(atoi(code._arg1.c_str()), regA);
	}
	else if (regA < 0)
	{
		regA = getEmptyReg();
		if (regA < 0) regA = storeToGetReg();
		assemblyCode.push_back(Assembly("lw", regA, code._arg1));
		set<string> set; set.insert(code._arg1);
		RValue->at(regA) = set;
		RNextUse->at(regA) = code._nextArg1;
		Getvar(code._arg1)._inR = regA;
		Getvar(code._arg1)._inM = true;
	}
	int regB = Getvar(code._des)._inR;
	if (regB < 0)
	{
		regB = getEmptyReg();
		if (regB < 0) regB = storeToGetReg();
	}
	assemblyCode.push_back(Assembly("lw", regB, "0("+ transformToRegName(regA)+")"));
	set<string> set; set.insert(code._des);
	RValue->at(regB) = set;
	RNextUse->at(regB) = code._nextDes;
	Getvar(code._des)._inR = regB;
	Getvar(code._des)._inM = false;
}

//set_mem(A,B);
void Assembly_set(const Quadruple& code) {
	int regA = Getvar(code._arg1)._inR;
	if (code._typeArg1)
	{
		regA = getEmptyReg();
		if (regA < 0) regA = storeToGetReg();
		imm2reg(atoi(code._arg1.c_str()), regA);
	}
	else if (regA < 0)
	{
		regA = getEmptyReg();
		if (regA < 0) regA = storeToGetReg();
		assemblyCode.push_back(Assembly("lw", regA, code._arg1));
		set<string> set; set.insert(code._arg1);
		RValue->at(regA) = set;
		RNextUse->at(regA) = code._nextArg1;
		Getvar(code._arg1)._inR = regA;
		Getvar(code._arg1)._inM = true;
	}
	int regB = Getvar(code._arg2)._inR;
	if (code._typeArg2)
	{
		regB = getEmptyReg();
		if (regB < 0) regB = storeToGetReg();
		imm2reg(atoi(code._arg2.c_str()), regB);
	}
	else if (regB < 0)
	{
		regB = getEmptyReg();
		if (regB < 0) regB = storeToGetReg();
		assemblyCode.push_back(Assembly("lw", regB, code._arg2));
		set<string> set; set.insert(code._arg2);
		RValue->at(regB) = set;
		RNextUse->at(regB) = code._nextArg2;
		Getvar(code._arg2)._inR = regB;
		Getvar(code._arg2)._inM = true;
	}
	assemblyCode.push_back(Assembly("sw", regB, "0(" + transformToRegName(regA) + ")"));
}

// generate condition choose
// �Բ�ͬ����Ԫʽ����caseѡ�����ɶ�Ӧ�����ɴ���
void GenerateAssembly(const Quadruple& code) {
	if (!code._label.empty()) {

		if (code._label.substr(0, 6) != "LABEL_") {
			//assemblyCode.push_back(Assembly(code._label, "", "", ""));
			Assembly_function_prework(code);
		}
		/*else if (code._label == "main") {
			// prework for function entrance
			//assemblyCode.push_back(Assembly(code._label, "", "", ""));
			assemblyCode.push_back(Assembly("add", "x8", "x2","x0"));	// MOV BP SP
			for (const auto& table : symbolTables) {
				if (table->_funName == code._label) {
					//int RegForResult = getEmptyReg();
					//if (RegForResult < 0) RegForResult = storeToGetReg();
					//assemblyCode.push_back(Assembly("addi", RegForResult, "x0", to_string(table->_variableOffset)));
					//assemblyCode.push_back(Assembly("sub", "x2", "x2", RegForResult));	
					assemblyCode.push_back(Assembly("addi", "x2", "x2", to_string(-table->_variableOffset)));// SUB SP 'offset'
					break;
				}
			}
		}*/
	}
	// different handle by type of code
	if (10 <= code._type && code._type <= 19) {
		Assembly_A_BopC(code);
	}
	else if (code._type == 2) {
		Assembly_A_opB(code);
	}
	else if (code._type == 3) {
		Assembly_A_B(code);
	}
	else if (code._type == 40) {
		Assembly_j(code);
	}
	else if (40 < code._type && code._type < 47) {
		Assembly_jrop(code);
	}
	else if (code._type == 6) {
		Assembly_param(code);
	}
	else if (code._type == 7) {
		Assembly_call(code);
	}
	else if (code._type == 8) {
		Assembly_return(code);
	}
	else if (code._type == 99) {
		Assembly_addr(code);
	}
	else if (code._type == 98) {
		Assembly_addroff(code);
	}
	else if (code._type == 100) {
		Assembly_nop();
	}
	else if (code._type == 97) {
		Assembly_load(code);
	}
	else if (code._type == 96) {
		Assembly_set(code);
	}
}

// output assembly codes
void outputAssemblyCode(string filename) {

	map<string, int>jlabel;
	jlabel.clear();
	int i = 0;
	for (const auto& code : assemblyCode) {
		if (code._label.substr(0, 6) == "LABEL_")
		{
			jlabel[code._label] = i;
		}
		i++;
	}
	ofstream out(filename);
	// output static data assemble code
	out << ".data" << endl;
	for (auto& var : globalTable->_field) {
		//out << setw(5) << var._name;
		// init value
		if (var._type == "int") {
			out << "    .word";
			out << setw(10) << var._name;
			out << setw(10) <<var.init_value;
		}
		/*else if (var._type == "float") {
			out << setw(5) << "    .float ";
			out << setw(5) << "0x00000000";
		}
		else if (var._type == "double") {
			out << setw(5) << "    .double ";
			out << setw(5) << "0x0";
		}*/
		out << endl;
	}

	// output code part
	out << endl<<".text" << endl;
	int index = 0;
	for (const auto& code : assemblyCode) {
		if (!code._label.empty()&& code._label.substr(0,6)!="LABEL_") {
			out << setw(13) << code._label + " : ";
		}
		else out << "             ";
		out << code._op << " ";
		if (jlabel.find(code._des) != jlabel.end()) {
			//cout << jlabel[code._des] << " " << index << endl;
			out << (jlabel[code._des] - index) * 4;
		}
		else out << code._des;
		if (!code._arg.empty()) {
			if (jlabel.find(code._arg) != jlabel.end())
			{
			//	cout << jlabel[code._arg] << " " << index << endl;
				out << "," << (jlabel[code._arg] - index) * 4;
			}
			else out << "," << code._arg;
		}
		if (!code._arg2.empty()) {
			if (jlabel.find(code._arg2) != jlabel.end())
			{
			//	cout << jlabel[code._immediate] << " " << index << endl;
				out << "," << (jlabel[code._arg2] - index) * 4 << endl;
			}
			else out << "," << code._arg2 <<endl;
		}
		else {
			out << endl;
		}
		index++;
	}
	out.close();
}

void tranlateIntoAssembly(string filename) {
	assemblyCode.clear();
	RValue = new vector<set<string>>(REGISTER_NUM);
	RNextUse = new vector<int>(REGISTER_NUM);
	AssemblyLabelMap.clear();

	for (auto& tab : symbolTables) {

		table = tab;
		if (table->_beginIndex == table->_endIndex) continue;
		//if (tab->_funName != "global" && tab->_funName != "main")
		//	assemblyCode.push_back(Assembly(tab->_funName + " :", "", "", ""));

		// set DS to DATA segment
		//if (tab->_funName == "main") {
			//AssemblyLabelMap.insert(make_pair(assemblyCode.size(), tab->_funName));
			// assemblyCode.push_back(Assembly("MOV", "AX", "@DATA"));
			// assemblyCode.push_back(Assembly("MOV", "DS", "AX"));
		//}

		map<int, BasicBlock> flowGragh;

		deque<int> leaders(table->_leaders.begin(), table->_leaders.end());
		leaders.push_back(table->_endIndex);

		for (auto& leader : leaders) {
			// use the beginIndex as block index
			flowGragh.insert(make_pair(leader, BasicBlock(leader)));
		}

		int beginIndex = leaders.front();
		auto cur = leaders.begin(); ++cur;	
		int endIndex = beginIndex;
		while (cur != leaders.end() ) {

			endIndex = *cur;

			auto& block = flowGragh.at(beginIndex);
			block._end = endIndex;
			auto& code = middleCode.at(endIndex - 1);

			if (code._type == 40) {
				// j LABEL_i
				int d = atoi(code._des.substr(6).c_str());
				block._successors.push_back(d);
				flowGragh.at(d)._predecessors.push_back(beginIndex);

			}
			else if (40 < code._type && code._type < 47) {
				// jop A B LABEL_i
				int d = atoi(code._des.substr(6).c_str());
				block._successors.push_back(d);
				flowGragh.at(d)._predecessors.push_back(beginIndex);

				// execute in order
				block._successors.push_back(endIndex);
				flowGragh.at(endIndex)._predecessors.push_back(beginIndex);
			}
			else {
				// execute in order
				block._successors.push_back(endIndex);
				flowGragh.at(endIndex)._predecessors.push_back(beginIndex);
			}

			beginIndex = endIndex;
			++cur;
		}

		// fill outLiveVar and inLiveVar info
		for (auto blockIndex = leaders.rbegin() + 1; blockIndex != leaders.rend(); ++blockIndex) {	// auto& -> auto

			auto& block = flowGragh.at(*blockIndex);
			VarSetType inLiveVar;
			fillVarState(block._begin, block._end, block._outLiveVar, inLiveVar);
			for (auto& predecessor : block._predecessors) {
				auto vars = flowGragh.at(predecessor)._outLiveVar;
				VarSetType newVars;
				set_union(inLiveVar.begin(), inLiveVar.end(), vars.begin(), vars.end(),
					inserter(newVars, newVars.begin()));
				flowGragh.at(predecessor)._outLiveVar = newVars;
			}
		}

		// generate assembly codes for each basic block
		for (auto blockIndex = leaders.begin(); blockIndex != leaders.end() - 1; ++blockIndex) {	// auto& -> auto

			auto& block = flowGragh.at(*blockIndex);

			fillVarState(block._begin, block._end, block._outLiveVar, block._inLiveVar);
			fill_n(RValue->begin(), REGISTER_NUM, set<string>());
			fill_n(RNextUse->begin(), REGISTER_NUM, -1);

			string label = middleCode.at(block._begin)._label;
			//if (!label.empty() && label != "main") {
			if (!label.empty()){
				AssemblyLabelMap.insert(make_pair(assemblyCode.size(), label));
			}

			for (int i = block._begin; i < block._end; ++i)
				GenerateAssembly(middleCode.at(i));

			// save live variables
			for (int reg = 0; reg < REGISTER_NUM; ++reg) {
				for (auto& var : RValue->at(reg)) {
					if (block._outLiveVar.find(var) != block._outLiveVar.end()
						&& Getvar(var)._inM == false) {
						assemblyCode.push_back(Assembly("sw", reg, var));	// MOV var reg -> SW reg 0(var)
						Getvar(var)._inM = true;
					}
					Getvar(var)._inR = -1;
				}
			}
			
		}
	}
	// reserve label
	AssemblyLabelMap.insert(make_pair(assemblyCode.size(), middleCode[nextInstr-1]._label));
	assemblyCode.push_back(Assembly("add", "x0", "x0", "x0")); 
	// add label
	for (const auto& map : AssemblyLabelMap) {
		assemblyCode.at(map.first)._label = map.second;
	}
	outputAssemblyCode(filename);


	if (RValue != nullptr) delete RValue;
	if (RNextUse != nullptr) delete RNextUse;
}

#endif

//x8 bp
//x2 sp
//x1 ra
//x10 return value
//x3 bss
//x9 �ո�ʽ��/array
//x11 array
//x12 ������������