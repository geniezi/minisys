.text
     minus : addi x2,x2,-4
             sw x8,0(x2)
             addi x2,x2,-4
             sw x1,0(x2)
             add x8,x2,x0
             addi x2,x2,-8
             lw x6,8(x8)
             lw x7,8(x8)
             sub x5,x6,x7
             lw x10,-8(x8)
             add x2,x8,x0
             lw x1,0(x2)
             addi x2,x2,4
             lw x8,0(x2)
             addi x2,x2,4
             jalr x9,0(x1)