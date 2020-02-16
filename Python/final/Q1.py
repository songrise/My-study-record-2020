# (a)
def genStates() -> tuple:
    """
    A function to generate all possible states for this problem
    Input: None
    Output: Return a tuple of all possible states.
    """
    allStates = []  # using a mutable data type first
    for boat in 'EW':
        for police in range(4):
            for robber in range(4):
                state = boat+str(police)+str(robber)
                allStates.append(state)

    return tuple(allStates)

# (b)


def genLegalStates(setStates: tuple) -> tuple:
    """
    A function to generate all legal states
    Input: setStates is a tuple of all possible states.
    Output: A tuple of all legal states
    """
    legal = []
    for s in setStates:
        if s[1] == '3' or s[1] == '0':  # no police at one side
            legal.append(s)
        elif s[1] == s[2]:
            legal.append(s)

        # handle incorrect place of boat
        if s[1] == '0' and s[2] == '0':
            if s[0] in'EW':
                # violate the constraint of boat must be operated by man
                legal.remove(s)

    return tuple(legal)

# (c)


def isNeighbor(aState: str, bState: str) -> bool:
    """
    A function to determine whether two legal states are direct neighbors (i.e., there is a
    link between them in the graph.)
    Input: aState and bState are two legal states.
    Output: Return True if they are direct neighbors; False, otherwise
    """

    # judge the boat
    if aState[0] == bState[0]:
        return False
    # convert into uniform format(express the absolute number of people in East)
    # (i.e.) [police in east, robber in east]
    if aState[0] == 'W':
        aState = [3-int(aState[1]), 3-int(aState[2])]
    else:
        aState = [int(aState[1]), int(aState[2])]
    if bState[0] == 'W':
        bState = [3-int(bState[1]), 3-int(bState[2])]
    else:
        bState = [int(bState[1]), int(bState[2])]

    neighbor = True
    diff = 0
    diff += abs(aState[0] - bState[0])
    diff += abs(aState[1] - bState[1])
    if diff > 2:
        neighbor = False

    return neighbor

# (d)


def genGraph(S: tuple) -> dict:
    """
    A function to generate a graph from all legal states
    Input: S is a tuple of all legal states.
    Output: Return a graph based on S and the constraints given in the problem.
    """
    # The graph ADT in implemented by python dict
    G = {state: [] for state in S}

    for aState in S:
        for bState in S:
            if isNeighbor(aState, bState):
                # if convert into uniform format(express the absolute number of people in East)
                # then the people in bState should decrease, otherwise the move is invalid
                if (int(aState[1]) - (3-int(bState[1])) >= 0) and (int(aState[2]) - (3-int(bState[2])) >= 0):
                    if not ((int(aState[1]) - (3-int(bState[1])) == 0) and (int(aState[2]) - (3-int(bState[2])) == 0)):
                        G[aState].append(bState)

    return G


# Testing
setAllStates = genStates()
print("(a) All possible states:")
count = 0
for s in setAllStates:
    print(s, end=" ")
    count += 1
    if count % 4 == 0:
        print()
print()

print("(b) All legal states:")
setLegalStates = genLegalStates(setAllStates)
count = 0
for s in setLegalStates:
    print(s, end=" ")
    count += 1
    if count % 6 == 0:
        print()
print()

print("(c) Checking whether direct neighbors:")
print("E33", "and", "W02"+":", end=" ")
print(isNeighbor("E33", "W02"))
print("E33", "and", "W01"+":", end=" ")
print(isNeighbor("E33", "W01"))
print("E33", "and", "W11"+":", end=" ")
print(isNeighbor("E33", "W11"))
print("E33", "and", "E32"+":", end=" ")
print(isNeighbor("E33", "E32"))
print("E32", "and", "W03"+":", end=" ")
print(isNeighbor("E32", "W03"))
print("W11", "and", "E32"+":", end=" ")
print(isNeighbor("W11", "E32"))
print("W22", "and", "E32"+":", end=" ")
print(isNeighbor("W22", "E32"))
print()

print("(d) The graph:")
G = genGraph(setLegalStates)
for n in G.keys():
    print(n+":", G[n])
print()


# (e)

print("The legal states that not belong to any shortest path are:", end='')
print(" E01 E30 W01 W30")
print("Reseaon : if a state can lead to no other state (in other word, not connected to other legal state),\n\
    then it not belong to any shortest path ")
print("    if a state is only connected to one State then it not belong to any shortest path. becase if we view\n\
    the graph as directed, then the move should be unidirectional, thus the only State it connected to must be the\n\
    father node of this State. So a loop will occur if we go this State in an undirected graph.\n\
    if a loop is occurred, then it can not be shortest.")

# (f)
print("The length of shortest path is:")
print("The path is ")
