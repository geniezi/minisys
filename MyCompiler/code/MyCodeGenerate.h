// 生成asm汇编语句代码
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
vector<set<string> >* RValue;	// 填写R寄存器中寄存了哪些变量
vector<int>* RNextUse;						// RNextUse中填写R寄存器中变量的待用信息，为所存变量中待用四元式序号最小的值

vector<Assembly> assemblyCode;				// 存储所有的汇编代码
map<size_t, string> AssemblyLabelMap;	// 记录汇编代码的标签信息，key为汇编代码的标号，value为对应此标号的标签
map<size_t, string> AssemblyFunMap;
typedef set<string> VarSetType;
varState& Getvar(string place)
{
	if (table->in(place)) return table->at(place);
	else if (constTable->in(place)) return constTable->at(place);
	else return globalTable->at(place);
}
// live_nextuse algorithm 变量活跃与待用信息计算
void fillVarState(int beginIndex, int endIndex, const VarSetType& outLiveVar, VarSetType& inLiveVar) {
	// table init with outLiveVar

	// 出口活跃变量_live属性设置为活跃true
	for (auto& var : outLiveVar) {
		Getvar(var)._live = true;
		Getvar(var)._nextUse = endIndex;
	}

	// 遍历数据块中其他的四元式
	for (int i = endIndex - 1; beginIndex <= i; --i) {
		auto& code = middleCode.at(i);
		if (code._type == 47) continue; // call N funName
		if (code._arg1 == "#") { //当前函数结束
			code._liveDes = Getvar(code._des)._live;
			code._nextDes = Getvar(code._des)._nextUse;
			Getvar(code._des)._live = false;
			Getvar(code._des)._nextUse = -1;
			continue;
		}
		bool desExsitFlag = !(code._des.empty() || code._op[0] == 'j');
		bool arg1ExsitFlag = !code._arg1.empty();
		bool arg2ExsitFlag = !code._arg2.empty();

		// 将符号表中变量A, B, C的Live与Next - Use填到变量A, B, C的附加信息两栏内

		// fill code var state live from symbol table
		if (desExsitFlag) code._liveDes = Getvar(code._des)._live;
		if (arg1ExsitFlag) code._liveArg1 = Getvar(code._arg1)._live;
		if (arg2ExsitFlag) code._liveArg2 = Getvar(code._arg2)._live;

		// fill code var state next use from symbol table
		if (desExsitFlag) code._nextDes = Getvar(code._des)._nextUse;
		if (arg1ExsitFlag) code._nextArg1 = Getvar(code._arg1)._nextUse;
		if (arg2ExsitFlag) code._nextArg2 = Getvar(code._arg2)._nextUse;

		// erase des state in symbol table
		// 清除符号表中A的Live和Next - Use项
		if (desExsitFlag) {
			Getvar(code._des)._live = false;
			Getvar(code._des)._nextUse = -1;
		}

		// set arg1,arg2 state in symbol table
		// 将符号表中B, C的Live置为true, Next - Use置为i
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

// 获取空的寄存器标号
int getEmptyReg() {
	for (int i = 0; i < REGISTER_NUM; i++) {
		if (RValue->at(i).empty()) return i;
	}
	return -1;
}

// 对于没有空寄存器情况找寄存器进行替换算法
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
		// 腾出寄存器Ri
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
			// 仅当Ri的内容在内存中无副本时生成
			assemblyCode.push_back(Assembly("sw", regReturn, var));	// MOV regReturn var -> ADDI regReturn var 0
		}
		Getvar(var)._inR = -1;	//不在任何寄存器中
		Getvar(var)._inM = true; //在内存中有副本
	}
	return regReturn;
}
//imm -> reg
void imm2reg(int imm,int reg)
{
	int x_l = imm & ((1 << 13) - 1);
	int x_u = imm>>12;
	if (imm >> 12 & 1) x_u++;
	if (x_u==0)
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
	int x_u = imm>>12;
	if (imm >> 12 & 1) x_u++;
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
	if (RegForB < 0) {
		if (code._typeArg1)
		{
			RegForB = getEmptyReg();
			if (RegForB < 0) RegForB = storeToGetReg();
			int x=atoi(code._arg1.c_str());
			imm2reg(x, RegForB);
			set<string> set; set.insert(code._arg1);
			RValue->at(RegForB) = set;
			RNextUse->at(RegForB) = -1;
			Getvar(code._arg1)._inR = RegForB;
			Getvar(code._arg1)._inM = true;
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
			int x = atoi(code._arg2.c_str());
			imm2reg(x, RegForC);
			set<string> set; set.insert(code._arg2);
			RValue->at(RegForC) = set;
			RNextUse->at(RegForC) = -1;
			Getvar(code._arg2)._inR = RegForC;
			Getvar(code._arg2)._inM = true;
		}
		else
		{
			RegForC = getEmptyReg();
			if (RegForC < 0) RegForC = storeToGetReg();
			set<string> set; set.insert(code._arg2);
			RValue->at(RegForC) = set;
			RNextUse->at(RegForC) = -1;
			Getvar(code._arg2)._inR = RegForC;
			Getvar(code._arg2)._inM = true;
			assemblyCode.push_back(Assembly("lw", RegForC, code._arg2));
		}
	}
	if (RegForA < 0)
	{
		RegForA = getEmptyReg(); // 分配空寄存器
		if (RegForA < 0) RegForA = storeToGetReg(); // 获得替换寄存器
		set<string> set;
		set.insert(code._des);
		RValue->at(RegForA) = set;
		RNextUse->at(RegForA) = code._nextDes;
		Getvar(code._des)._inR = RegForA;
		Getvar(code._des)._inM = false;
	}
	assemblyCode.push_back(Assembly(code._op, RegForA, RegForB, RegForC));
	Getvar(code._des)._inM = false;
	/*if (code._typeArg1) {
		// B 为常量
		if (RegForC < 0) {
			// C不在register中
			if (RegForA < 0) {
				// A不在register中
				// A载入register
				RegForA = getEmptyReg(); // 分配空寄存器
				if (RegForA < 0) RegForA = storeToGetReg(); // 获得替换寄存器
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
			// C在register中
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
		// B为变量，C为常量
		if (RegForB < 0) {
			// B不在register中
			if (RegForA < 0) {
				// A不在register中
				// A载入register
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
			// B在register中
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
			// B不在register
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
				// C在register中
				assemblyCode.push_back(Assembly(code._op, RegForA, RegForC, ""));		// op RegForA RegForC
			}
			else {
				// C不在register中
				assemblyCode.push_back(Assembly(code._op, RegForA, code._arg2, ""));	// op RegForA C
			}
			Getvar(code._arg1)._inR = -1;
		}
		else {
			// select another reg for A
			RegForA = getEmptyReg();
			if (-1 < RegForA) {
				assemblyCode.push_back(Assembly("addi", RegForA, RegForB, 0));				// MOV RegForA RegForB -> ADDI RegForA RegForB 0
				int regC = Getvar(code._arg2)._inR;	// 重新找C是否在register中
														// 载入A时可能破坏了C
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
	// B为常量
	int RegForB = Getvar(code._arg1)._inR;
	if (code._typeArg1)
	{
		int RegForB = getEmptyReg();
		if (RegForB < 0) RegForB = storeToGetReg();
		int x = atoi(code._arg1.c_str());
		imm2reg(x, RegForB);
		set<string> set; set.insert(code._arg1);
		RValue->at(RegForB) = set;
		RNextUse->at(RegForB) = code._nextArg1;
		Getvar(code._arg1)._inR = RegForB;
		Getvar(code._arg1)._inM = true;
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
		set<string> set; set.insert(code._des);
		RValue->at(RegForA) = set;
		RNextUse->at(RegForA) = code._nextDes;
		Getvar(code._des)._inR = RegForA;
		Getvar(code._des)._inM = true;
	}
	assemblyCode.push_back(Assembly("sub", RegForA,"x0", RegForB));
	Getvar(code._des)._inM = false;
	/*int RegForB = Getvar(code._arg1)._inR;
	if (RegForB < 0) {
		// B不在register中
		// IN_R[B] != Ri
		// 载入B
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
	// B在RegForB中

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

// code : B = A
void Assembly_A_B(const Quadruple& code) {

	if (code._typeArg1) {
		// B为常量
		int RegForA = Getvar(code._arg1)._inR;
		if (RegForA < 0) {
			// A不在register中
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
		// B为函数返回值
		int RegForA = Getvar(code._des)._inR;
		if (RegForA >=0) {
			// A在register中
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
		set<string> set; set.insert(code._arg1);
		RValue->at(RegForB) = set;
		RNextUse->at(RegForB) = code._nextArg1;
		Getvar(code._arg1)._inR = RegForB;
		Getvar(code._arg1)._inM = true;
	}
	//对于B的值在寄存器中的情况不需要生成汇编代码，直接插入A并更新A._inR
	RValue->at(RegForB).insert(code._des);
	Getvar(code._des)._inR = RegForB;
	Getvar(code._des)._inM = false;
	if (code._liveArg1 == false) {
		RValue->at(RegForB).erase(code._arg1);
		Getvar(code._arg1)._inR = -1;
	}
	// 为防止指令标签位置出错，生成“nop”指令以进行过渡
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
	addNum("1");
	set<string> sset; sset.insert("1");
	RValue->at(RegForResult) = sset;
	RNextUse->at(RegForResult) = -1;

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
			set<string> set; set.insert(code._arg1);
			RValue->at(RegForB) = set;
			RNextUse->at(RegForB) = code._nextArg1;
			Getvar(code._arg1)._inR = RegForB;
			Getvar(code._arg1)._inM = true;
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
			set<string> set; set.insert(code._arg2);
			RValue->at(RegForC) = set;
			RNextUse->at(RegForC) = code._nextArg2;
			Getvar(code._arg2)._inR = RegForC;
			Getvar(code._arg2)._inM = true;
		}
	}
	if (judgment == 1)
		assemblyCode.push_back(Assembly("slt", RegForResult, RegForB, RegForC));	// slt code._arg1 code._arg2
	else if (judgment == 2)
		assemblyCode.push_back(Assembly("slt", RegForResult, RegForC, RegForB));

	
	string jrop = "";
	if (code._op == "j==")
	{
		assemblyCode.push_back(Assembly("beq", RegForB, RegForC, code._des));
		return;
	}
	else if (code._op == "j!=")
	{
		assemblyCode.push_back(Assembly("bne", RegForB, RegForC, code._des));
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
					table->at(it)._inM == true;
				}
			}
			else if (globalTable->in(it)) {
				if (globalTable->at(it)._inM == false) {
					assemblyCode.push_back(Assembly("sw", reg, globalTable->at(it)._place));
					globalTable->at(it)._inM == true;
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
	//assemblyCode[assemblyCode.size()-1]._label = code._label;
	assemblyCode.push_back(Assembly("sw", "x8", "0(x2)"));		
	// PUSH reg
	if (code._fun != "main") {
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
		if (table->_funName == code._fun) {
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
					globalTable->at(it)._inM == true;
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
		set<string> set; set.insert(code._arg2);
		RValue->at(reg) = set;
		RNextUse->at(reg) = code._nextArg2;
		Getvar(code._arg2)._inR = reg;
		Getvar(code._arg2)._inM = true;
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
			Getvar(code._arg2)._inM = true;
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
			Getvar(code._arg2)._inM = true;
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
		set<string> set; set.insert(code._arg1);
		RValue->at(regA) = set;
		RNextUse->at(regA) = code._nextArg1;
		Getvar(code._arg1)._inR = regA;
		Getvar(code._arg1)._inM = true;
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
	Getvar(code._des)._inM = true;
}

//set_mem(A,B);
void Assembly_set(const Quadruple& code) {
	int regA = Getvar(code._arg1)._inR;
	if (code._typeArg1)
	{
		regA = getEmptyReg();
		if (regA < 0) regA = storeToGetReg();
		imm2reg(atoi(code._arg1.c_str()), regA);
		set<string> set; set.insert(code._arg1);
		RValue->at(regA) = set;
		RNextUse->at(regA) = code._nextArg1;
		Getvar(code._arg1)._inR = regA;
		Getvar(code._arg1)._inM = true;
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
		set<string> set; set.insert(code._arg2);
		RValue->at(regB) = set;
		RNextUse->at(regB) = code._nextArg2;
		Getvar(code._arg2)._inR = regB;
		Getvar(code._arg2)._inM = true;
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
// 对不同的四元式进行case选择生成对应的生成代码
void GenerateAssembly(const Quadruple& code) {
	/*
		if (code._fun!= "") {
			Assembly_function_prework(code);
		}
	*/
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
	else if (code._type == 47) {
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
		if (code._label != "")
		{
			jlabel[code._label] = i;
		}
		i++;
	}
	ofstream out(filename);
	// output static data assemble code
	out << ".data" << endl;
	for (auto& var : globalTable->_field) {
		// init value
		out << "    .word";
		out << setw(20) << var._name;
		out << setw(11) << var.init_value;
		out << endl;
	}

	// output code part
	out << endl<<".text" << endl;
	int index = 0;
	for (const auto& code : assemblyCode) {
		if (!code._fun.empty()) {
			out << setw(13) << code._fun + " : ";
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
	AssemblyFunMap.clear();
	for (auto& tab : symbolTables) {

		table = tab;
		if (table->_beginIndex == table->_endIndex) continue;
		map<int, BasicBlock> flowGragh;

		deque<int> leaders(table->_leaders.begin(), table->_leaders.end());
		if(table->_leaders.count(table->_endIndex)==0) leaders.push_back(table->_endIndex);

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
			string fun = middleCode.at(block._begin)._fun;
			//if (!label.empty() && label != "main") {
			if (!fun.empty())
			{
				AssemblyFunMap.insert(make_pair(assemblyCode.size(), fun));
				Assembly_function_prework(middleCode.at(block._begin));
			}
			if (!label.empty()) {
				AssemblyLabelMap.insert(make_pair(assemblyCode.size(), label));
			}
			//cout << block._begin << " " << block._end << endl;
			for (int i = block._begin; i < block._end-1; ++i)
				GenerateAssembly(middleCode.at(i));
			if (middleCode.at(block._end - 1)._type >= 40 && middleCode.at(block._end - 1)._type <= 46)
			{
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
				GenerateAssembly(middleCode.at(block._end - 1));
			}
			else
			{
				GenerateAssembly(middleCode.at(block._end - 1));
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
	}
	// reserve label
	AssemblyLabelMap.insert(make_pair(assemblyCode.size(), middleCode[nextInstr-1]._label));
	assemblyCode.push_back(Assembly("add", "x0", "x0", "x0")); 
	// add label
	for (const auto& map : AssemblyLabelMap) {
		assemblyCode.at(map.first)._label = map.second;
	}for (const auto& map : AssemblyFunMap) {
		assemblyCode.at(map.first)._fun = map.second;
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
//x9 凑格式的/array
//x11 array
//x12 函数参数传递