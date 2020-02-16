def genLegalStates():
    state=["E","W"] #initialize  
    all = [[m,c,g,w] for m in state for c in state for g in state for w in state ]  #list comprehension
    sequ=("".join(str(obj) for States in all for obj in States if not (States[0] != States[1] == States[2] or States[0] != States[2] == States[3])))
    sequ = 1
genLegalStates()