#include "SeuLex.h"
#include "SeuYacc.h"
#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
	//SeuLex lex("lexC.l" ,"lex.h");
	cout << "lex construction complete\n";
	SeuYacc yacc("miniC.y", "yacc.c");
	cout << "grammar construction complete\n";
	return 0;
}