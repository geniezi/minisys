#include "lex.h"
#include "yaccHelp.h"
using namespace std;
/*int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "please input the target source file name" << endl;
		return 1;
	}
	list<Token> tokenlist;
	tokenlist.clear();
	int ok = lexParse(argv[1], tokenlist);
	if (ok) ok = yaccReduce(tokenlist, argv[2]);
	if (ok) cout << "compile success" << endl;
	else cout << "error";
	return 0;
}*/
int main() {
	
	list<Token> tokenlist;
	tokenlist.clear();
	string filename = "test.c";
	int p = filename.find('.');
	int ok=lexParse(filename,tokenlist);
	if(ok) ok=yaccReduce(tokenlist, filename.substr(0,p)+".asm");
	if (ok) cout << "compile success" << endl;
	else cout << "error";
	return 0;
}