# xxx
instructions_I = {
    "fence.i":  "0000 0000 0000 00000 001 00000 0001111",
    "ecall":    "000000000000 00000 000 00000 1110011",
    "ebreak":   "000000000001 00000 000 00000 1110011",

}

# xxx pred succ
instructions_I_a = {
    "fence":    "0000 pred succ 00000 000 00000 0001111",
}

# xxx rd csr rs1
instructions_I_b = {
    "csrrw":    "csr rs1 001 rd 1110011",
    "csrrs":    "csr rs1 010 rd 1110011",
    "csrrc":    "csr rs1 011 rd 1110011",
}

# xxx rd csr zimm
instructions_I_c = {
    "csrrwi":   "csr zimm 101 rd 1110011",
    "csrrsi":   "csr zimm 110 rd 1110011",
    "csrrci":   "csr zimm 111 rd 1110011",
}

# xxx rd imm
instructions_I_31 = {
    "lui":      "imm[31:12] rd 0110111",
    "auipc":    "imm[31:12] rd 0010111",
}

# xxx rd imm
instructions_I_20 = {
    "jal":      "imm[20|10:1|11|19:12] rd 1101111",
}

# xxx rs1 rs2 imm
instructions_I_12 = {
    "beq":      "imm[12|10:5] rs2 rs1 000 imm[4:1|11] 1100011",
    "bne":      "imm[12|10:5] rs2 rs1 001 imm[4:1|11] 1100011",
    "blt":      "imm[12|10:5] rs2 rs1 100 imm[4:1|11] 1100011",
    "bge":      "imm[12|10:5] rs2 rs1 101 imm[4:1|11] 1100011",
    "bltu":     "imm[12|10:5] rs2 rs1 110 imm[4:1|11] 1100011",
    "bgeu":     "imm[12|10:5] rs2 rs1 111 imm[4:1|11] 1100011",
}

# xxx rd rs1 imm[11:0]
instructions_I_11_a = {
    "addi":     "imm[11:0] rs1 000 rd 0010011",
    "slti":     "imm[11:0] rs1 010 rd 0010011",
    "sltiu":    "imm[11:0] rs1 011 rd 0010011",
    "xori":     "imm[11:0] rs1 100 rd 0010011",
    "ori":      "imm[11:0] rs1 110 rd 0010011",
    "andi":     "imm[11:0] rs1 111 rd 0010011",
}

# xx rd imm(rs1)
instructions_I_11_b = {
    "jalr":     "imm[11:0] rs1 000 rd 1100111",
    "lb":       "imm[11:0] rs1 000 rd 0000011",
    "lh":       "imm[11:0] rs1 001 rd 0000011",
    "lw":       "imm[11:0] rs1 010 rd 0000011",
    "lbu":      "imm[11:0] rs1 100 rd 0000011",
    "lhu":      "imm[11:0] rs1 101 rd 0000011",
}

# xxx rs2 imm(rs1)
instructions_I_11_4 = {
    "sb":       "imm[11:5] rs2 rs1 000 imm[4:0] 0100011",
    "sh":       "imm[11:5] rs2 rs1 001 imm[4:0] 0100011",
    "sw":       "imm[11:5] rs2 rs1 010 imm[4:0] 0100011",
}

# xxx rd rs1 imm
instructions_I_4 = {
    "slli":     "0000000 imm[4:0] rs1 001 rd 0010011",
    "srli":     "0000000 imm[4:0] rs1 101 rd 0010011",
    "srai":     "0100000 imm[4:0] rs1 101 rd 0010011",
}

# xxx rd rs1 rs2
instructions_I_0_M = {
    "add":      "0000000 rs2 rs1 000 rd 0110011",
    "sub":      "0100000 rs2 rs1 000 rd 0110011",
    "sll":      "0000000 rs2 rs1 001 rd 0110011",
    "slt":      "0000000 rs2 rs1 010 rd 0110011",
    "sltu":     "0000000 rs2 rs1 011 rd 0110011",
    "xor":      "0000000 rs2 rs1 100 rd 0110011",
    "srl":      "0000000 rs2 rs1 101 rd 0110011",
    "sra":      "0100000 rs2 rs1 101 rd 0110011",
    "or":       "0000000 rs2 rs1 110 rd 0110011",
    "and":      "0000000 rs2 rs1 111 rd 0110011",

    "mul":      "0000001 rs2 rs1 000 rd 0110011",
    "mulh":     "0000001 rs2 rs1 001 rd 0110011",
    "mulhsu":   "0000001 rs2 rs1 010 rd 0110011",
    "mulhu":    "0000001 rs2 rs1 011 rd 0110011",
    "div":      "0000001 rs2 rs1 100 rd 0110011",
    "divu":     "0000001 rs2 rs1 101 rd 0110011",
    "rem":      "0000001 rs2 rs1 110 rd 0110011",
    "remu":     "0000001 rs2 rs1 111 rd 0110011",
}

instructions_privilege = {
    "mret":     "0011000 00010 00000 000 00000 1110011",
    "wfi":      "0001000 00101 00000 000 00000 1110011"
}