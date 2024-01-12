import os

import instructions


def dec2binary(imm, width):
    mask = (1 << width) - 1
    imm = imm & mask
    imm_ = format(int(imm), '0' + str(width) + 'b')
    return imm_


def binary2hex(binary_string, width):
    # 确保二进制字符串的长度是width，以便正确转换为十六进制
    if len(binary_string) != width * 4:
        print("error, length not correct")  # 报错
        binary_string = binary_string.zfill(width * 4)  # 使用0补齐

    # 将二进制字符串转换为十六进制
    hex_value = hex(int(binary_string, 2))[2:].zfill(width)  # 使用int将二进制转换为十进制，然后用hex转换为十六进制字符串，并补0
    return hex_value.lower()  # 返回小写形式的十六进制字符串


def process_jal(functs, machine_code):
    # put main in the head
    main_start = functs['main']['start']
    main_end = functs['main']['end']
    for funct in functs:
        if (funct == 'bios') or (funct == 'main'):
            continue
        if functs[funct]['start'] < main_start:
            functs[funct]['start'] = functs[funct]['start'] + (main_end - main_start) + 1
            functs[funct]['end'] = functs[funct]['end'] + (main_end - main_start) + 1
    machine_code = machine_code[main_start - 1:main_end] + machine_code[0:main_start - 1] + machine_code[main_end:]
    functs['main']['start'] = 1
    functs['main']['end'] = main_end - main_start + 1

    for funct in functs:
        if funct == 'bios':
            result = machine_code[functs[funct]['start'] - 1: functs[funct]['end']]
            continue
        start = functs[funct]['start']
        end = functs[funct]['end']
        for i in range(start - 1, end):
            if '+' in machine_code[i]:
                rd_here = machine_code[i].split('+')[0]
                fuct_here = machine_code[i].split('+')[1]
                if fuct_here in functs:
                    imm = (functs[fuct_here]['start'] - (i + 1)) * 4
                    instr = dec2binary(imm, 20)

                    binary_instr = "imm[20|10:1|11|19:12] rd 1101111"
                    binary_instr = binary_instr.replace("rd", rd_here)
                    binary_instr = binary_instr.replace("imm[20|10:1|11|19:12]",
                                                        instr[0] + instr[10:20] + instr[9] + instr[1:9])
                    binary_instr = binary_instr.replace(" ", "")
                    machine_code[i] = binary2hex(binary_instr, 8)
    return result


def generate_ins_coe_file(functs, bios_code, machine_code, output_path):
    file_path = os.path.join(output_path, 'ins.coe')

    coe_file = open(file_path, "w")
    coe_file.write("memory_initialization_radix = 16;\n")
    coe_file.write("memory_initialization_vector =\n")

    # bios
    for i in range(0, bios_code.__len__()):
        bios_code[i] = bios_code[i][4:8] + "," + bios_code[i][0:4]

    # 1024-bios zeros
    for i in range(1024 - bios_code.__len__()):
        bios_code.append("0000,0000")

    for i in range(0, machine_code.__len__()):
        machine_code[i] = machine_code[i][4:8] + "," + machine_code[i][0:4]
    binary_code = (',\n'.join(bios_code)) + ",\n" + (',\n'.join(machine_code[0:functs['bios']['start']-1])) + ","
    # print(binary_code)

    coe_file.write(binary_code)
    coe_file.close()


def generate_data_coe_file(datas, output_path):
    file_path = os.path.join(output_path, 'data.coe')

    coe_file = open(file_path, "w")
    coe_file.write("memory_initialization_radix = 16;\n")
    coe_file.write("memory_initialization_vector =\n")

    for i in range(1024):
        coe_file.write("00000000,\n")

    for data in datas:
        bin = dec2binary(int(datas[data]), 32)
        coe_file.write(binary2hex(bin, 8) + ",\n")

    # coe_file.write(binary_code)
    coe_file.close()
