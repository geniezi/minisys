lui x2,0xffff0
lui x3,0xffff1
lw x1,0(x3)
sw x1,0(x2)
jal x0,-8
nop
nop
nop
addi x31,x0,1
lui x1,0xffff2
lui x2,0xffff3
lw x3,4(x1)
lw x4,0(x1)
beq x3,x31,8
jal x0,-12
slli x4,x4,2
lw x5,0(x4)
sw x5,0(x2)
sw x31,4(x2)
jal x0,-32
