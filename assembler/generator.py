with open("test.s", 'a') as f:
    for i in range(0,32):
        inst = "addi x{0},x{0},{0}\n".format(i)
        f.write(inst)
