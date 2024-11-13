
from mnemonics import AD, IS, DL, REG

SYMBOL={}
LITERAL={}


with open("input.txt") as f1:
    code = f1.readlines()
f1.close()

for i in range(len(code)):
    code[i] = code[i].replace("\n","").replace(",","").split()

f2 = open("IC_output.txt", "w")

def assemblerDirectives(line ,word):

    global lc

    if word == "START":
        try:
            lc = int(line[1])
        except:
            lc = 0

    elif word == "END":
        lc+=1
        for i in LITERAL:
            if LITERAL[i][1] == "notset":
                LITERAL[i][1] = str(lc)
                lc+=1

    elif word == "LTORG":
        for i in LITERAL:
            if LITERAL[i][1] == "notset":
                LITERAL[i][1] = str(lc)
                lc+=1

    elif word == "ORIGIN":
        symbol = int(SYMBOL[line[1]][1])
        value = int(line[3])
        if line[2] == "+":
            lc = symbol + value
        else:
            lc = symbol - value
    
    elif word == "EQU":
        SYMBOL[line[0]][1] = SYMBOL[line[2]][1]

def declareStatment(line, word):
    global lc

    if word == "DC":
        SYMBOL[line[0]][1] = str(lc)
        lc+=1
    else:
        SYMBOL[line[0]][1] = str(lc)
        lc+= int(line[2])




symIndex = 1
litIndex = 1

for line in code:
    for word in line:
        if word in AD:
            f2.write(AD[word] + " ")
            assemblerDirectives(line, word)

        elif word in IS:
            f2.write(IS[word] + " ")
            lc+=1

        elif word in DL:
            f2.write(DL[word] + " "+line[0]+" "+line[2])
            declareStatment(line, word)
        
        elif word in REG:
            f2.write(REG[word] + " ")
        
        elif "='" in word:
            if word not in LITERAL:
                LITERAL[word] = ["L" + str(litIndex), "notset"]
            else:
                word+="."
                LITERAL[word] = ["L" + str(litIndex), "notset"]
            litIndex+=1
            f2.write(LITERAL[word][0]+" ")

        elif not word.isdigit() and word not in SYMBOL and "+" not in word and "-" not in word:

            SYMBOL[word] = ["S" + str(symIndex), str(lc)]
            symIndex +=1

            if(word != line[0]):
                f2.write(SYMBOL[word][0] + " ")

    f2.write("\n")
f2.close()

print(SYMBOL)
print(LITERAL)


