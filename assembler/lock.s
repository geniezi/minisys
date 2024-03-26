addi x10,x0,8
lr x1,x10
addi x1,x1,3
sc x6,x1,x10
bne x6,x0,-12
jal x0,0
nop
nop
addi x10,x0,8
lr x1,x10
addi x1,x1,5
sc x6,x1,x10
bne x6,x0,-12
jal x0,0


