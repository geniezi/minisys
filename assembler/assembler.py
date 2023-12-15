import instructions
import re


def binary2hex(binary_string, width):
    # 确保二进制字符串的长度是width，以便正确转换为十六进制
    if len(binary_string) != width*4:
        print("error, length not correct")  # 报错
        binary_string = binary_string.zfill(width*4)  # 使用0补齐

    # 将二进制字符串转换为十六进制
    hex_value = hex(int(binary_string, 2))[2:].zfill(width)  # 使用int将二进制转换为十进制，然后用hex转换为十六进制字符串，并补0
    return hex_value.lower()  # 返回小写形式的十六进制字符串


def reg2int(reg):
    reg_ = re.findall(r'\d+', reg)[0]
    reg_ = dec2binary(int(reg_), 5)
    # print(reg_)
    return reg_


def csr2int(csr):
    csr_ = re.findall(r'\d+', csr)[0]
    csr_ = dec2binary(int(csr_), 12)
    # print(csr_)
    return csr_


def imm2binary(imm, width):
    if imm[0:2] == "0x" or imm[0:3] == "-0x":
        return dec2binary(int(imm,16), width)
    else:
        return dec2binary(int(imm), width)


def dec2binary(imm, width):
    mask = (1 << width) - 1
    imm = imm & mask
    imm_ = format(int(imm), '0' + str(width) + 'b')
    return imm_


def assemble_i_0_m(parts):
    # xxx rd rs1 rs2
    binary_instr = instructions.instructions_I_0_M.get(parts[0])
    # print(binary_instr)

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    binary_instr = binary_instr.replace("rs1", reg2int(parts[2]))
    binary_instr = binary_instr.replace("rs2", reg2int(parts[3]))
    return binary_instr


def assemble_i_4(parts):
    # xxx rd rs1 imm
    binary_instr = instructions.instructions_I_4.get(parts[0])

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    binary_instr = binary_instr.replace("rs1", reg2int(parts[2]))
    binary_instr = binary_instr.replace("imm[4:0]", imm2binary(parts[3], 5))

    return binary_instr


def assemble_i_11_4(parts):
    # xxx rs2 imm(rs1)
    parts.append(parts[2].split('(')[1].split(')')[0])
    parts[2] = parts[2].split('(')[0]
    binary_instr = instructions.instructions_I_11_4.get(parts[0])
    binary_instr = binary_instr.replace("rs2", reg2int(parts[1]))
    binary_instr = binary_instr.replace("rs1", reg2int(parts[3]))
    imm = imm2binary(parts[2],12)
    binary_instr = binary_instr.replace("imm[11:5]", imm[0:7])
    binary_instr = binary_instr.replace("imm[4:0]", imm[7:12])
    return binary_instr


def assemble_i_11_a(parts):
    # xxx rd rs1 imm[11:0]
    binary_instr = instructions.instructions_I_11_a.get(parts[0])

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    binary_instr = binary_instr.replace("rs1", reg2int(parts[2]))
    binary_instr = binary_instr.replace("imm[11:0]", imm2binary(parts[3], 12))

    return binary_instr


def assemble_i_11_b(parts):
    # xx rd imm(rs1)
    parts.append(parts[2].split('(')[1].split(')')[0])
    parts[2] = parts[2].split('(')[0]
    binary_instr = instructions.instructions_I_11_b.get(parts[0])

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    binary_instr = binary_instr.replace("rs1", reg2int(parts[3]))
    binary_instr = binary_instr.replace("imm[11:0]", imm2binary(parts[2], 12))

    return binary_instr


def assemble_i_12(parts):
    # xxx rs1 rs2 imm
    binary_instr = instructions.instructions_I_12.get(parts[0])

    binary_instr = binary_instr.replace("rs1", reg2int(parts[1]))
    binary_instr = binary_instr.replace("rs2", reg2int(parts[2]))
    instr = imm2binary(parts[3],12)[0] + imm2binary(parts[3],12)
    binary_instr = binary_instr.replace("imm[12|10:5]",
                                        instr[0] + instr[2:8])
    binary_instr = binary_instr.replace("imm[4:1|11]",
                                        instr[8:12] + instr[1])
    return binary_instr


def assemble_i_20(parts):
    # xxx rd imm
    binary_instr = instructions.instructions_I_20.get(parts[0])

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    instr = imm2binary(parts[2],20)[0] + imm2binary(parts[2],20)
    binary_instr = binary_instr.replace("imm[20|10:1|11|19:12]",instr[0]+instr[10:20]+instr[9]+instr[1:9])
                                        # imm2binary(int(parts[2]) >> 20, 1) + imm2binary(int(parts[2]) >> 1,
                                        #                                            10) + imm2binary(
                                        #     int(parts[2]) >> 11, 1) + imm2binary(int(parts[2]) >> 12, 8))

    return binary_instr


def assemble_i_31(parts):
    # xxx rd imm
    binary_instr = instructions.instructions_I_31.get(parts[0])

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    binary_instr = binary_instr.replace("imm[31:12]", imm2binary(parts[2],20))

    return binary_instr


def assemble_I(parts):
    # xxx
    binary_instr = instructions.instructions_I.get(parts[0])

    return binary_instr


def assemble_i_a(parts):
    # xxx pred succ
    binary_instr = instructions.instructions_I_a.get(parts[0])

    binary_instr = binary_instr.replace("pred", imm2binary(parts[1], 4))
    binary_instr = binary_instr.replace("succ", imm2binary(parts[2], 4))

    return binary_instr


def assemble_i_b(parts):
    # xxx rd csr rs1
    binary_instr = instructions.instructions_I_b.get(parts[0])

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    binary_instr = binary_instr.replace("csr", csr2int(parts[2]))
    binary_instr = binary_instr.replace("rs1", reg2int(parts[3]))

    return binary_instr


def assemble_i_c(parts):
    # xxx rd csr zimm
    binary_instr = instructions.instructions_I_c.get(parts[0])

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    binary_instr = binary_instr.replace("csr", csr2int(parts[2]))
    binary_instr = binary_instr.replace("zimm", imm2binary(parts[3], 5))

    return binary_instr


def assemble_risc_v(assembly_code):
    machine_code = []
    lines = assembly_code.split('\n')

    for line in lines:
        parts = line.replace(",", "").split()
        if parts[0] in instructions.instructions_I_0_M:
            machine_code.append(assemble_i_0_m(parts))
        if parts[0] in instructions.instructions_I_4:
            machine_code.append(assemble_i_4(parts))
        if parts[0] in instructions.instructions_I_11_4:
            machine_code.append(assemble_i_11_4(parts))
        if parts[0] in instructions.instructions_I_11_a:
            machine_code.append(assemble_i_11_a(parts))
        if parts[0] in instructions.instructions_I_11_b:
            machine_code.append(assemble_i_11_b(parts))
        if parts[0] in instructions.instructions_I_12:
            machine_code.append(assemble_i_12(parts))
        if parts[0] in instructions.instructions_I_20:
            machine_code.append(assemble_i_20(parts))
        if parts[0] in instructions.instructions_I_31:
            machine_code.append(assemble_i_31(parts))
        if parts[0] in instructions.instructions_I:
            machine_code.append(assemble_I(parts))
        if parts[0] in instructions.instructions_I_a:
            machine_code.append(assemble_i_a(parts))
        if parts[0] in instructions.instructions_I_b:
            machine_code.append(assemble_i_b(parts))
        if parts[0] in instructions.instructions_I_c:
            machine_code.append(assemble_i_c(parts))
    for i in range(len(machine_code)):
        machine_code[i] = machine_code[i].replace(" ", "")
        machine_code[i] = binary2hex(machine_code[i], 8)
    # result = (',\n'.join(machine_code))
    return machine_code


if __name__ == '__main__':
    print()

    # 测试汇编器
    assembly_code = """addi x1, x1, -0x3F0
    addi x4, x4, -0x3C0
    lui x7, 2
    addi x7, x7, -0x22F
    addi x8, x8, 1
    lw x5, 0(x1)
    lw x6, 2(x1)
    beq x6, x0, -8
    sw x7, 0(x4)
    sw x8, 2(x4)
    jal x9, -20"""
    machine_code = assemble_risc_v(assembly_code)
    print(machine_code)
    for i in range(0,machine_code.__len__()):
        machine_code[i] = machine_code[i][4:8] + "," + machine_code[i][0:4]
    binary_code = (',\n'.join(machine_code)) + ","
    print(binary_code)

