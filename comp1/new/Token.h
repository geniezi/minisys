#ifndef _TOKEN_H
#define _TOKEN_H

#include <string>
using namespace std;

struct Token {
	Token(string word,string attr,unsigned int innercode,unsigned int line,unsigned int offset)
		: _lexecal(word), //token����
		_attribute(attr), //��ʶ������
		_innerCode(innercode),//��¼���ŵ��ڲ��룬0 for �ؼ���
		_line(line), //��ʾtoken��Դ�ļ���һ��
		_offset(offset) //��Դ�ļ�����ƫ���� ���������Ϣ
	{	}

	// data member
	string _lexecal;
	string _attribute;
	unsigned int _innerCode;
	unsigned int _line;
	unsigned int _offset;

}; // struct Token	

#endif
