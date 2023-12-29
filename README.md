# minisys

#### 汇编器
可执行文件 `assembler/dist/assembler/assembler.exe`，使用方法：
```
assembler.exe input_file1 input_file2 ... output_path
input_file1 input_file2 ...: 输入文件（可多个）
output_path: 输出路径，输出两个文件，分别为指令文件ins.coe和数据文件data.coe
示例：assembler.exe ..\..\assemble_code\code1.asm ..\..\assemble_code\code2.asm ..\..\coe_result\
```

#### 编译器
可执行文件 `comp1/exe/MyCompiler.exe`，使用方法：
```
MyCompiler.exe input_file output_file
input_file: 输入文件（仅一个）
output_file: 输出文件（与上面不同，指定到文件名而非路径）
示例：MyCompiler.exe ../source_code/source_code.c  ../result/result.asm
```

#### 软件
