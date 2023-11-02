import instructions
import re


def reg2int(reg):
    reg_ = re.findall(r'\d+', reg)[0]
    reg_ = format(int(reg_), '05b')
    # print(reg_)
    return reg_


def imm2binary(imm, width):
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
    parts[3] = parts[2].split('(')[1].split(')')[0]
    parts[2] = parts[2].split('(')[0]
    binary_instr = instructions.instructions_I_11_4.get(parts[0])

    binary_instr = binary_instr.replace("rs2", reg2int(parts[1]))
    binary_instr = binary_instr.replace("rs1", reg2int(parts[3]))
    binary_instr = binary_instr.replace("imm[11:5]", imm2binary(parts[2] >> 5, 7))
    binary_instr = binary_instr.replace("imm[4:0]", imm2binary(parts[2], 5))

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
    parts[3] = parts[2].split('(')[1].split(')')[0]
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
    binary_instr = binary_instr.replace("imm[12|10:5]",
                                        imm2binary(parts[3] >> 12, 1) + imm2binary(parts[3] >> 5, 6))
    binary_instr = binary_instr.replace("imm[4:1|11]",
                                        imm2binary(parts[3] >> 1, 4) + imm2binary(parts[3] >> 11, 1))

    return binary_instr


def assemble_i_20(parts):
    # xxx rd imm
    binary_instr = instructions.instructions_I_20.get(parts[0])

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    binary_instr = binary_instr.replace("imm[20|10:1|11|19:12]",
                                        imm2binary(parts[2] >> 20, 1) + imm2binary(parts[2] >> 1,
                                                                                   10) + imm2binary(
                                            parts[2] >> 11, 1) + imm2binary(parts[2] >> 12, 8))

    return binary_instr


def assemble_i_31(parts):
    # xxx rd imm
    binary_instr = instructions.instructions_I_31.get(parts[0])

    binary_instr = binary_instr.replace("rd", reg2int(parts[1]))
    binary_instr = binary_instr.replace("imm[31:12]", imm2binary(parts[2]>>12, 20))

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
    return '\n'.join(machine_code)


print(imm2binary(7, 2))

# # 测试汇编器
# assembly_code = """slli x1, x2, 2
# jalr x1, x2, 100
# srli x3, x4, 8
# add x1, x2, x3
# mulh x4, x5, x6"""
#
# machine_code = assemble_risc_v(assembly_code)
# print(machine_code)
