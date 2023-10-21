import instructions
import re


def assemble_m_0(parts):
    binary_instr = instructions.instructions_M[parts[0]]

    binary_instr = binary_instr.replace("rd", format(int(re.sub(r'\D','',parts[1]), '05b')))
    binary_instr = binary_instr.replace("rs1", format(int(parts[2]), '05b'))
    binary_instr = binary_instr.replace("rs2", format(int(parts[3]), '05b'))
    return binary_instr


def assemble_i_ins(parts):
    pass


def assemble_risc_v(assembly_code):
    machine_code = []
    lines = assembly_code.split('\n')

    for line in lines:
        parts = line.replace(",", "").split()
        if parts[0] in [instructions.instructions_M, instructions.instructions_I_0]:
            machine_code.append(assemble_m_0(parts))
        if parts[0] in instructions.instructions_I:
            machine_code.append(assemble_i_ins(parts))
    return '\n'.join(machine_code)


# 测试汇编器
assembly_code = """mul x1, x2, x3
mulh x4, x5, x6"""

machine_code = assemble_risc_v(assembly_code)
print(machine_code)
