%{
#include <string>
#include <map>
#include <iostream>
#include <vector>
int line = 0;
int numCount = 0;
%}
blank \n|\r| |\t;
ws {blank}+;
digit [0~9];
letter [A~Za~z];
id {letter}({letter}|{digit})*;
number {digit}+(.{digit}+)?(E[+-]?{digit}+)?|0x({digit}|a|b|c|d|e|f)+;
%%
char {return "char";}
int {return "int";}
float {return "float";}
bool {return "bool";}
void {return "void";}
if  {return "if";}
else  {return "else";}
while {return "while";}
return {return "return";}
static {return "static";}
break {return "break";}
continue {return "continue";}
{id} {return "id";}
{number} {++numCount; return "num";}
{ws} {;}
"+" {return "+";}
"-" {return "-";}
"*" {return "*";}
"/" {return "/";}
"%" {return "%";}
"+=" {return "+=";}
"-=" {return "-=";}
"*=" {return "*=";}
"/=" {return "/=";}
"%=" {return "%=";}
"&&" {return "&&";}
"||" {return "||";}
"!" {return "!";}
"<=" {return "<=";}
">=" {return ">=";}
"=" {return "=";}
"!=" {return "!=";}
"==" {return "==";}
"|" {return "|";}
"&" {return "&";}
"^" {return "^";}
"<<" {return "<<";}
">>" {return ">>";}
"<" {return "<";}
">" {return ">";}
"(" {return "(";}
")" {return ")";}
"{" {return "{";}
"}" {return "}";}
"[" {return "[";}
"]" {return "]";}
";" {++line;return ";";}
"," {return ",";}
%%
void calLine() {
	std::cout << "number of semicolon : " << line << std::endl;
}
void getNumCount() {
    std::cout << "count of num : " << numCount << std::endl;
}
void main() {
	calLine();
	getNumCount();
}