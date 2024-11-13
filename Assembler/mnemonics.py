AD = {
    "START" : "(AD01)",
    "END" : "(AD02)",
    "LTORG" : "(AD03)",
    "ORIGIN" : "(AD04)",
    "EQU" : "(AD05)"
}

IS = {
    "STOP" : "(IS00)",
    "ADD" : "(IS01)",
    "SUB" : "(IS02)",
    "MULT" : "(IS03)",
    "MOVER" : "(IS04)",
    "MOVEM" : "(IS05)",
    "CMP" : "(IS06)",
    "BC" : "(IS07)",
    "DIV" : "(IS08)",
    "READ" : "(IS09)",
    "PRINT" : "(IS10)" 
}

DL = {
    "DC" : "(DL01)",
    "DS" : "(DL02)"
}

REG = { 'AREG':"(R,1)", 'BREG':"(R,2)", 'CREG':"(R,3)", 'DREG':"(R,4)"}

OPCODE = {
    "AREG" : "01",
    "BREG" : "02",
    "CREG" : "03",
    "DREG" : "04",
    "(IS00)" : "00 00 000",
    "(IS01)" : "01",
    "(IS02)" : "02",
    "(IS03)" : "03",
    "(IS04)" : "04",
    "(IS05)" : "05",
    "(IS06)" : "06",
    "(IS07)" : "07",
    "(IS08)" : "08",
    "(IS09)" : "09",
    "(IS10)" : "10"
}