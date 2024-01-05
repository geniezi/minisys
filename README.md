# minisys

## 汇编器
可执行文件 `assembler/dist/assembler/assembler.exe`，使用方法：
```
assembler.exe input_file1 input_file2 ... output_path
input_file1 input_file2 ...: 输入文件（可多个）
output_path: 输出路径，输出两个文件，分别为指令文件ins.coe和数据文件data.coe
示例：assembler.exe ..\..\assemble_code\code1.asm ..\..\assemble_code\code2.asm ..\..\coe_result\
```

## 编译器
编译器一次仅能编译一个文件，当有多个文件时，需要多次调用编译器。

可执行文件 `MyCompiler/Release/MyCompiler.exe`，使用方法：
```
MyCompiler.exe input_file output_file
input_file: 输入文件（仅一个）
output_file: 输出文件路径 （注意是路径！）
示例：MyCompiler.exe ../source_code/source_code.c  ../result/ 建议文件路径都是相对于MyCompiler.exe的路径
输出的文件名是：输出文件路径/源文件和库文件文件名.asm
```
一次只能定义一个变量，例如 int a;/int a[10]; 不要 int a,b;  
函数名避开LABEL_开头的  
#include 中用到的库文件是相对于源文件的相对地址，统一用左斜杠分割，绝对地址暂不支持
使用//注释的时候 记得要在 //后面空一格 例如“// int x;"  
目前不允许空while循环 空if  

## 软件
