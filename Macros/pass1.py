
mnttab=[]
pntab=[]
kpdtab=[]
mdttab=[]

def macroProcessor(macroLines, start_index):

    mntInfo=[]
    mntLines = macroLines[start_index].replace("\n","").replace("="," ").split()
    mntInfo.append(mntLines[0])

    pntInfo={}
    for i in range(len(mntLines)):
        if "&" in mntLines[i]:
            pntInfo[mntLines[i]] = "P" + str(i)
    
    pntab.append(pntInfo)
    mntInfo.append(len(pntInfo))

    kpDict={}
    temp = macroLines[start_index].split()
    for i in range(len(temp)):
        if "=" in temp[i]:
            temp2 = temp[i].split("=")
            try:
                kpDict[temp2[0]] = temp2[1]
            except:
                kpDict[temp2[0]] = "notset"
    
    kpdtab.append(kpDict)
    mntInfo.append(len(kpdtab))

    mnttab.append(mntInfo)

    mdtInfo=[]
    for i in range(start_index+1 , len(macroLines)):
        mdtLines=""

        if "MEND" in macroLines[i]:
            mdtLines="MEND"
            mdtInfo.append(mdtLines)
            mdttab.append(mdtInfo)
            
        else:
            macroArray = macroLines[i].replace(",","").split()

            for j in range(len(macroArray)):
                if macroArray[j] in pntInfo:
                    mdtLines += pntInfo[macroArray[j]] + " "
                else:
                    mdtLines += macroArray[j] + " "
            mdtInfo.append(mdtLines)
    return len(macroLines)


with open("input1.txt") as f1:
    macroLines = f1.readlines()
f1.close()

index=0
while index < len(macroLines):
    line = macroLines[index]
    if "MACRO" in line:
        index = macroProcessor(macroLines, index+1)
    else:
        index += 1

print(mnttab)
print(pntab)
print(kpdtab)
print(mdttab)

with open("output.txt", "w") as f2:

    for i in mnttab:
        f2.write(str(i) + "\n")
    

    f2.write("\n======== MDT TABLE ========\n")
    for i in mdttab:
        for j in i:
            f2.write(str(j) + "\n")
        f2.write("\n")

print("Output written to output.txt")
