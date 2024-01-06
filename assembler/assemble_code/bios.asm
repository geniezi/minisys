.text
    main :  lui x2,0x10
            lui x8,0x10
            lui x3,0x1
            addi x31,x31,0x1
            addi x30,x30,0x100
            addi x29,x29,-0x400
            sw x31,0(x29)
            sw x30,4(x29)
            jal x0,4064
            addi x30,x0,0x100
            addi x29,x0,-0x400
            addi x7,x0,11
            addi x28,x0,3
            csrrs x6,t834,x0
            bne x6,x7,16
            addi x31,x0,2
            sw x31,0(x29)
            jal x0,28
            bne x6,x28,16
            addi x31,x0,3
            sw x31,0(x29)
            jal x0,12
            addi x31,x0,4
            sw x31,0(x29)
            mret

