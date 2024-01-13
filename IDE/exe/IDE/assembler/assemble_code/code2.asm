.data
    .word     p    0

.text
      main : addi x2,x2,-4
             sw x8,0(x2)
             add x8,x2,x0
             addi x2,x2,-16
             lw x11,-8(x8)
             addi x2,x2,-4
             sw x11,0(x2)
             lw x11,-4(x8)
             addi x2,x2,-4
             sw x11,0(x2)
             jal x1,minus
             lw x5,-16(x8)
             add x5,x10,x0
             addi x0,x0,0
             add x2,x8,x0
             lw x1,0(x2)
             addi x2,x2,4
             lw x8,0(x2)
             addi x2,x2,4
             jalr x9,0(x1)
