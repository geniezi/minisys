addi x1,x1,-0x3F0
addi x4,x4,-0x3a0
lw x5,0(x1)
lw x6,2(x1)
beq x6,x0,-8
sw x5,0(x4)
sw x5,2(x4)
jal x7,-20
