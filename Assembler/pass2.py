# # importing the opcodes from mnemonics
from mnemonics import OPCODE
from pass1 import SYMBOL, LITERAL

# opening intermediate code file
with open("IC_output.txt") as f3:
    codelines = f3.readlines()

# formatting the codelines
for i in range (len(codelines)):
    codelines[i] = codelines[i].replace('\n','').split()

# opening the machine code file
f4 = open("machineCode.txt",'w')

# functions
def handleDLS(line, word):
    if word == '(DL01)':
        f4.write("00 00 " + line[2].zfill(3))
    else:
        for i in range(int(line[2])):
            f4.write("-- -- --- \n")    
# # pass 2 of Assembler
for line in codelines:
    f4.write("+")
    for word in line:
        if word in OPCODE:
            f4.write(OPCODE[word] + ' ')
        elif word in LITERAL:
            f4.write(LITERAL[word].zfill(3))
        elif word in SYMBOL:
            f4.write(SYMBOL[word].zfill(3))
        elif "(DL" in word:
            handleDLS(line,word)
            break    
    f4.write('\n')  