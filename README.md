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
编译器说明：  
一次只能定义一个变量，例如 int a;/int a[10]; 不要 int a,b;  
函数名避开LABEL_开头的  
#include 中用到的库文件是相对于源文件的相对地址，统一用左斜杠分割，绝对地址暂不支持  
使用//注释的时候 记得要在 //后面空一格 例如“// int x;"  
目前不允许空while循环 空if,至少写一个分号;  
读写内存专用函数 load_mem(addr),set_mem(addr,val)，addr和val 支持表达式、变量、常量  
函数必须要有return语句，void也要写return;语句

## 软件
编写了一个可以循环测试所有外设的程序Minisys-TestApp\APP\peripheral_test.c
其中测试了BIOS初始化数码管显示为1，之后因中断显示为4.
测试了通过读取拨码开关实现控制LED的亮与灭.
并且通过按键输入1-7控制蜂鸣振动器实现小小电子琴的效果.1-7分别代表7个音符
以及通过输入1-7控制pwm为1的占空比，以实现调光台灯的效果，1最暗，7时led灯亮度最高.
编写了一个斐波那契数列应用程序，通过键盘输入值，在晶体管上显示相应的结果.
一个跑马灯程序，24位灯循环点亮，从低位到高位，每次点亮4个灯.
以及一个IDEtest程序，用来测试IDE的编译报错功能.