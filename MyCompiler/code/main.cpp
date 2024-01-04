#include "lex.h"
#include "yaccHelp.h"
#include <windows.h>
#include <filesystem>
using namespace std;
vector<string>asmfile;
int main(int argc, char *argv[]) {
	if (argc < 3) {
		cout << "please input the source file name" << endl;
		return 1;
	}
	list<Token> tokenlist;
	string filename = argv[1];;
	string _path = argv[2];
	filelist.push_back(filename);
	for (int i = 0; i < filelist.size(); i++) {
		tokenlist.clear();
		std::filesystem::path pathA(filelist[i]);
		//filename = filelist[i];
		//int p = filename.find('.');
		//int q = filename.find_last_of('/');
		//if (q == filename.npos) q = -1;
		cout << pathA.filename() << " begin\n";
		asmfile.push_back(pathA.filename() + ".asm");
		int ok = lexParse(filename, tokenlist);
		if (ok) ok = yaccReduce(tokenlist, asmfile[asmfile.size() - 1], i);
		if (ok) cout << "compile success" << endl;
		else cout << "error";
	}
	string am = "dist\\assembler\\assembler.exe ";
	for (int i = 0; i < filelist.size(); i++) am = am + asmfile[i] + " ";
	am += _path;
	system(am.c_str());
	return 0;
}
/*int main() {
	list<Token> tokenlist;
	string filename = "test.c";
	filelist.push_back(filename);
	for (int i = 0; i < filelist.size(); i++) {
		tokenlist.clear();
		filename = filelist[i];
		int p = filename.find('.');
		cout << filename << " begin\n";
		asmfile.push_back(filename.substr(0, p) + ".asm");
		int ok = lexParse(filename, tokenlist);
		if (ok) ok = yaccReduce(tokenlist, asmfile[asmfile.size()-1],i);
		if (ok) cout << "compile success" << endl;
		else cout << "error";
	}
	string am = "dist\\assembler\\assembler.exe ";
	for (int i = 0; i < filelist.size(); i++) am = am + asmfile[i] + " ";
	am = am + "./result";
	cout << am << endl;
	system(am.c_str());
	return 0;
}*/