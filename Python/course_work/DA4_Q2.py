def genlegalStates():
    """ print legal states in MCGW problem."""
    state=["E","W"] #initialize
    for m in state:
        for c in state:
            for g in state:
                for w in state:
                    all_state = [m,c,g,w]
                    if (all_state[0] != all_state[1] == all_state[2] or
                         all_state[0] != all_state[2] == all_state[3]):
                    #if the state is illegal, omit it.
                        continue
                    print("".join(all_state))  #Print all legal states in the given format.
    return None
genlegalStates()
