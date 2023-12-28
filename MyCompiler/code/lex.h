#include <string>
#include <map>
#include <iostream>
using namespace std;
int line = 0;
int numCount = 0;

void calLine() {
	cout << "number of lines : " << line << endl;
}

void getNumCount() {
	cout << "count of num : " << numCount << endl;
}

void main2() {
	calLine();
	getNumCount();
}

#include "lexHelp.h"
int lexParse(const string file, list<Token>& tokenList) {
	int ok = parseToken(file, tokenList);
	if (ok) {
		//getNumCount();
		cout << "Lexical parsing complete!\n";
	}
	else cout << "Lexical parsing wrong!\n";
	return ok;
}