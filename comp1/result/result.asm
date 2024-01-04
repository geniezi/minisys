.data
    .word         b         0

.text
      main : addi x2,x2,-4
             sw x8,0(x2)
             add x8,x2,x0
             addi x2,x2,-4
             addi x5,x0,10
             add x5,x0,0
             lw x5,-4(x8)
