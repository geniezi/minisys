#include "lex.h"
#include "yaccHelp.h"
#include <windows.h>
#include <sys/stat.h>
#include <stdio.h>
#include <direct.h>
using namespace std;
vector<string>asmfile;
int main(int argc, char *argv[]) {
	if (argc < 3) {
		cout << "please input the source file name" << endl;
		return 1;
	}
	list<Token> tokenlist;
	string filename = argv[1];
	string base = "";
	int pos = filename.find_last_of('/');
	if(pos!=filename.npos) base = filename.substr(0, pos+1);
	string out_path = argv[2];
	struct stat st;
	if (stat(out_path.c_str(), &st) != 0) {
		cout<<"create new folder "<<out_path<<" "<<_mkdir(out_path.c_str())<<endl;
	}
	filelist.push_back(filename);
	for (int i = 0; i < filelist.size(); i++) {
		tokenlist.clear();
		filename = filelist[i];
		int p = filename.find_last_of('.');
		int q = filename.find_last_of('/');
		if (q == filename.npos) q = -1;
		string nname = filename.substr(q + 1, p - q - 1) + ".asm";
		cout << nname << " begin\n";
		asmfile.push_back(out_path+"/"+nname);
		if (i != 0) nname = base + "./" + filename;
		else nname = filename;
		int ok = lexParse(nname, tokenlist);
		if (ok) ok = yaccReduce(tokenlist, asmfile[asmfile.size() - 1], i);
		if (ok) cout << "compile success" << endl;
		else cout << "error\n";
	}
	string am = "..\\..\\assembler\\dist\\assembler\\assembler.exe ";
	for (int i = 0; i < filelist.size(); i++) am = am +asmfile[i] + " ";
	am += out_path;
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
		else cout << "error\n";
	}
	string am = "..\\..\\assembler\\dist\\assembler\\assembler.exe ";
	for (int i = 0; i < filelist.size(); i++) am = am + "./result" + "/" + asmfile[i] + " ";
	am = am + "./result";
	cout << am << endl;
	system(am.c_str());
	return 0;
}*/