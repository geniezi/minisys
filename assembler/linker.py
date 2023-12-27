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
    for funct in functs:
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


def generate_ins_coe_file(machine_code):
    directory = 'coe_result'
    os.makedirs(directory, exist_ok=True)
    file_path = os.path.join(directory, 'ins.coe')

    coe_file = open(file_path, "w")
    coe_file.write("memory_initialization_radix = 16;\n")
    coe_file.write("memory_initialization_vector =\n")

    for i in range(0, machine_code.__len__()):
        machine_code[i] = machine_code[i][4:8] + "," + machine_code[i][0:4]
    binary_code = (',\n'.join(machine_code)) + ","
    # print(binary_code)

    coe_file.write(binary_code)
    coe_file.close()


def generate_data_coe_file(datas):
    directory = 'coe_result'
    os.makedirs(directory, exist_ok=True)
    file_path = os.path.join(directory, 'data.coe')

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
