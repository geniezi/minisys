#ifndef _TOKEN_H
#define _TOKEN_H

#include <string>
using namespace std;

struct Token {
	Token(string word,string attr,unsigned int innercode,unsigned int line,unsigned int offset)
		: _lexecal(word), //token单词
		_attribute(attr), //标识的属性
		_innerCode(innercode),//记录符号的内部码，0 for 关键字
		_line(line), //表示token在源文件哪一行
		_offset(offset) //在源文件行中偏移量 输出错误信息
	{	}

	// data member
	string _lexecal;
	string _attribute;
	unsigned int _innerCode;
	unsigned int _line;
	unsigned int _offset;

}; // struct Token	

#endif
