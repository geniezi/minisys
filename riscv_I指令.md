## fence

```
fence
伪指令,内存和IO屏障.

 - 内存和IO屏障，保证fence之前的指令执行完后才执行fence之后的指令:
   fence

 - 实例:
   fence
```

## ecall

```
ecall
环境调用.

 - 通过引发环境调用异常来请求执行:
   ecall
```

## ebreak

```
ebreak
环境断点.

 - 通过抛出断点异常的方式请求调试器:
   ebreak
```

## csrrw

```
csrrw[i]
读后写控制状态寄存器 .

 - t = CSRs[csr]; CSRs[csr] = x[rs1]; x[rd] = t:
   csrrw rd, csr, rs1

 - x[rd] = CSRs[csr]; CSRs[csr] = zimm(只写五位的零扩展立即数）:
   csrrwi rd, csr, zimm[4:0]

 - 实例:
   csrrs t0, mie, t1
   csrrs t0, mie, 0b11010
```

## csrrs

```
csrrs[i]
读后置位控制状态寄存器 .

 - t = CSRs[csr]; CSRs[csr] = t | x[rs1]; x[rd] = t:
   csrrs rd, csr, rs1

 - t = CSRs[csr]; CSRs[csr] = t | zimm; x[rd] = t(csr寄存器的第5位及更高不变）:
   csrrsi rd, csr, zimm[4:0]

 - 实例:
   csrrs t0, mie, t1
   csrrs t0, mie, 0b11010
```

## csrrc

```
csrrc[i]
读后清除控制状态寄存器 .

 - t = CSRs[csr]; CSRs[csr] = t &~x[rs1]; x[rd] = t:
   csrrc rd, csr, rs1

 - t = CSRs[csr]; CSRs[csr] = t &~zimm; x[rd] = t (csr寄存器的第5位及更高不变）:
   csrrci rd, csr, zimm[4:0]

 - 实例:
   csrrci t0, mie, t1
   csrrci t0, mie, 0b11010
```

## lui

```
lui
高位立即数加载.

 - 将符号位扩展的20位立即数immediate左移12位，并将低12位置零，写入 x[rd]中。x[rd] = sext(immediate[31:12] << 12):
   lui rd, immediate
```

## auipc

```
auipc
PC加立即数.

 - 把符号位扩展的20 位（左移 12 位）立即数加到 pc上，结果写入 x[rd]。x[rd] = pc + sext(immediate[31:12] << 12):
   auipc rd, immediate

 - 实例:
   auipc t0,0
```

## jal

```
jal
伪指令,跳转并链接.

 - 跳转到offset执行，并将跳转指令的下一条指令地址放入ra寄存器:
   jal offset

 - 实例:
   jal lable
```

## beq

```
beq
相等时分支.

 - 若寄存器x[rs1]和寄存器x[rs2]的值相等，把pc的值设为当前值加上符号位扩展的偏移offset。if (rs1 == rs2) pc += sext(offset):
   beq rs1, rs2, offset

 - 实例:
   beq t0,t1,lable
```

## bne

```
bne
不相等时分支.

 - 若寄存器 x[rs1]和寄存器 x[rs2]的值不相等，把 pc的值设为当前值加上符号位扩展偏移offset。if (rs1 ≠ rs2) pc += sext(offset)：
   bne rs1, rs2, offset

 - 实例:
   bne t0, t1, lable
```

## blt

```
blt
小于时分支.

 - 若寄存器 x[rs1]的值小于寄存器x[rs2]的值（均视为二进制补码），把 pc的值设为当前值加上符号位扩展的偏移 offset。if (rs1 <s rs2) pc += sext(offset):
   blt rs1, rs2, offset

 - 若寄存器x[rs1]的值小于寄存器 x[rs2]的值（均视为无符号数），把 pc的值设为当前值加上符号位扩展的偏移offset。if (rs1 <u rs2) pc += sext(offset):
   bltu rs1, rs2, offset

 - 实例:
   blt t0, t1, lable
   bltu t0, t1, lable
```

## bge

```
bge[u]
大于等时分支.

 - 若寄存器 x[rs1]的值大于等于寄存器x[rs2]的值（均视为二进制补码），把 pc的值设为当前值加上符号位扩展的偏移 offset。if (rs1 ≥s rs2) pc += sext(offset):
   bge rs1, rs2, offset

 - 若寄存器x[rs1]的值大于等于寄存器 x[rs2]的值（均视为无符号数），把 pc的值设为当前值加上符号位扩展的偏移offset。if (rs1 ≥u rs2) pc += sext(offset):
   bgeu rs1, rs2, offset

 - 实例:
   bge t0, t1, lable
   bgeu t0, t1, lable
```

## jalr(似乎有误)

```
jalr
伪指令,跳转并链接寄存器.

 - 跳转到寄存器rs所存储的地址处执行，并将跳转指令的下一条指令地址放入ra寄存器:
   jalr rs

 - 实例:
   jalr s0
```

## lb

```
lb[u]
字节加载.

 - 从地址x[rs1] + sign-extend(offset)读取一个字节，经符号位扩展后写入 x[rd]。x[rd] = sext(M[x[rs1] + sext(offset)][7:0]):
   lb rd, offset(rs1)

 - 从地址x[rs1] + sign-extend(offset)读取一个字节，经零扩展后写入 x[rd]。x[rd] = M[x[rs1] + sext(offset)][7:0]:
   lbu rd, offset(rs1)

 - 实例:
   lb t0, 3(a0)
   lbu t0, 3(a0)
```

## lh

```
lh[u]
半字加载.

 - 从地址x[rs1] + sign-extend(offset)读取两个字节，经符号位扩展后写入 x[rd]。x[rd] = sext(M[x[rs1] + sext(offset)][15:0]):
   lh rd, offset(rs1)

 - 从地址x[rs1] + sign-extend(offset)读取两个字节，经零扩展后写入 x[rd]。x[rd] = M[x[rs1] + sext(offset)][15:0]:
   lhu rd, offset(rs1)

 - 实例:
   lh t0, 2(a0)
   lhu t0, 2(a0)
```

## lw

```
lw[u]
字加载.

 - 从地址x[rs1] + sign-extend(offset)读取四个字节，写入 x[rd](RV64I 经符号位扩展)。x[rd] = sext(M[x[rs1] + sext(offset)][31:0]):
   lw rd, offset(rs1)

 - 从地址x[rs1] + sign-extend(offset)读取四个字节，写入 x[rd](RV64I 经零扩展后)。x[rd] = M[x[rs1] + sext(offset)][31:0]:
   lwu rd, offset(rs1)

 - 实例:
   lw t0, 4(a0)
   lwu t0, 4(a0)
```

## sb

```
sb
存字节.

 - 将 x[rs2]的低位字节存入内地址x[rs1]+sign-extend(offset)。M[x[rs1]+sext(offset)=x[rs2][7:0]:
   sb rs2, offset(rs1)

 - 实例:
   sb t0, 3(a0)
```

## sh

```
lh
存半字.

 - 将 x[rs2]的低位2字节存入内地址x[rs1]+sign-extend(offset)。M[x[rs1]+sext(offset)=x[rs2][15:0]:
   sh rs2, offset(rs1)

 - 实例:
   sh t0, 3(a0)
```

## sw

```
lw
存字.

 - 将 x[rs2]的低位4字节存入内地址x[rs1]+sign-extend(offset)。M[x[rs1]+sext(offset)=x[rs2][31:0]:
   sw rs2, offset(rs1)

 - 实例:
   sw t0, 4(a0)
```

## add

```
add[i]
加法.

 - 把寄存器 x[rs2]加到寄存器x[rs1]上，结果写入 x[rd]。 忽略算术溢出。 x[rd] = x[rs1] + x[rs2]:
   add rd, rs1, rs2

 - 把符号位扩展的立即数加到寄存器 x[rs1]上，结果写入 x[rd]。 忽略算术溢出。 x[rd] = x[rs1] + sext(immediate):
   addi rd, rs1, immediate

 - 实例:
   add t0,t1,t2
   add t0,t1,100
```

## sub

```
sub
减法.

 - 忽略算术溢出。x[rd]=x[rs1] - x[rs2]:
   sub rd, rs1, rs2

 - 实例:
   sub t0,t1,t2
```

## sll

```
sll
逻辑左移.

 - rs2低5位为左移位数，高位忽略。左移后空出位数补0。x[rd]=x[rs1] << x[rs2]:
   sll rd, rs1, rs2

 - 立即数shamt低5位为左移位数，第6位必须为0，左移后空出位数补0。x[rd]=x[rs1] << shamt
   slli rd, rs1, shamt

 - 实例:
   sll t0, t0, t1
   slli t0, t0, 3
```

## slt

```
slt[i][u]
小于则置位.

 - 比较 x[rs1]和 x[rs2]中的数，如果 x[rs1]更小，向 x[rd]写入 1，否则写入 0。x[rd]=(x[rs1]<s x[rs2]):
   slt rd, rs1, rs2

 - 比较 x[rs1]和有符号扩展的 immediate(只有12位)，如果 x[rs1]更小，向 x[rd]写入 1，否则写入 0，x[rd]=(x[rs1]<s sext(immediate))：
   slti rd, rs1, immediate

 - 比较 x[rs1]和有符号扩展的 immediate(只有12位)，以无符号比较。如果 x[rs1]更小，向 x[rd]写入 1，否则写入 0，x[rd]=(x[rs1]<u sext(immediate))：
   sltiu rd, rs1, immediate

 - 比较 x[rs1]和 x[rs2]中的数，以无符号比较.如果 x[rs1]更小，向 x[rd]写入 1，否则写入 0。x[rd]=(x[rs1]<u x[rs2]):
   sltu rd, rs1, rs2

 - 实例:
   slt a0, t0, t1
   slti a0, t0, 35
   sltiu a0, t0, 55
   sltu a0, t0, t1
```

## xor

```
xor
取或.

 - 把寄存器 x[rs1]和寄存器x[rs2]按位取异或，结果写入x[rd], x[rd]=x[rs1] ^ x[rs2]:
   xor rd, rs1, rs2

 - 把寄存器 x[rs1]和有符号扩展的立即数immediate(只有低12bit有效)按位取异或，结果写 入 x[rd]。x[rd]=x[rs1] …… sext(immediate):
   xori rd, rs1, immediate

 - 实例:
   xor a0, t1, t2
   xori a0, t1, 0b11011
```

## srl

```
srl
逻辑右移.

 - rs2低5位为右移位数，高位忽略。右移后空出位数补0。x[rd]=x[rs1] >>u x[rs2]:
   sll rd, rs1, rs2

 - 立即数shamt低5位为右移位数，第6位必须为0，右移后空出位数补0。x[rd]=x[rs1] >>u shamt
   srli rd, rs1, shamt

 - 实例:
   sll t0, t0, t1
   slli t0, t0, 3
```

## sra

```
sra
算数右移.

 - rs2低5位为右移位数，高位忽略。右移后空出位数用x[rs1]的最高位填充。x[rd]=(x[rs1]>>s x[rs2]):
   sra rd, rs1, rs2

 - 立即数shamt低5位为→移位数，第6位必须为0，右移后空出位数用x[rs1]的最高位填充。x[rd]=x[rs1] >>s shamt
   srai rd, rs1, shamt

 - 实例:
   sll t0, t0, t1
   slli t0, t0, 3
```

## or

```
or
取或.

 - 把寄存器 x[rs1]和寄存器x[rs2]按位取或，结果写入x[rd], x[rd]=x[rs1] | x[rs2]:
   or rd, rs1, rs2

 - 把寄存器 x[rs1]和有符号扩展的立即数immediate(只有低12bit有效)按位取或，结果写 入 x[rd]。x[rd]=x[rs1] | sext(immediate):
   ori rd, rs1, immediate

 - 实例:
   or a0, t1, t2
   ori a0, t1, 0b11011
```

## and

```
rdcycle[h]
与.

 - 将寄存器 x[rs1]和寄存器x[rs2]位与的结果写入 x[rd]。 x[rd] = x[rs1] & x[rs2]:
   and rd, rs1, rs2

 - 把符号位扩展的立即数和寄存器x[rs1]上的值进行位与，结果写入 x[rd]。x[rd] = x[rs1] & sext(immediate):
   andi rd, rs1, immediate

 - 实例:
   and t0,t1,t2
   and t0,t1,0b100
```

