addi x1,x0,-0x10
addi x2,x0,1
addi x3,x0,0x100
addi x4,x0,120
sw x4,0(x3)
sw x2,4(x1)
jal x0,0
nop
nop
nop
nop
jal x0,0
nop
nop
nop
nop
nop
nop
nop
addi x1,x1,-0x10
addi x2,x0,0x100
lw x3,0(x2)
sw x0,4(x1)
csrrw x0,0x341,x3
mret
nop
nop
nop
nop
nop
addi x10,x0,10
jal x0,0