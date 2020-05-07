def main():
    def genAllStates():
        """Return a list containing all states in this problem"""
        allStates = ["".join((B, M, P, H1, W1, S1, H2, W2, S2)) for B in "EW" for M in "EW" for P in "EW" for H1 in "EW"
                     for W1 in "EW" for S1 in "EW" for H2 in "EW" for W2 in "EW" for S2 in "EW"]
        return allStates

    def illegalC1(all_states: list):
        """Return a list containing all illegal states that violates the constraint of having the boat with at least a man"""
        C1 = []
        for s in all_states:
            if (s[0] != s[1] and s[0] != s[2] and s[0] != s[3] and s[0] != s[6]):
                C1.append(s)
        return C1

    def illegalC2(all_states: list):
        """Return a list containing all illegal states that violates the constraint of
         preventing Pharaoh from beating others
         """
        C2 = []
        for s in all_states:
            if s[1] != s[2]:
                if not (s[2] != s[3] and s[2] != s[4] and s[2] != s[5] and s[2] != s[6] and s[2] != s[7] and s[2] != s[8]):
                    C2.append(s)
        return C2

    def illegalC3(all_states: list):
        """Return a list containing all illegal states that violates the constraint of
        preventing Ananias from beating Ahab's household
        """
        C3 = []
        for s in all_states:
            if (s[6] == s[4] or s[6] == s[5]) and (s[3] != s[6]):
                C3.append(s)
        return C3

    def illegalC4(all_states: list):
        """Return a list containing all illegal states that violates the constraint of
        preventing Ahab from beating Ananias's household
        """
        C4 = []
        for s in all_states:
            if (s[3] == s[7] or s[3] == s[8]) and (s[6] != s[3]):
                C4.append(s)
        return C4

    def genLegalStates(all_states: list):
        """Return a list containing all legal states"""
        legal_states = [s for s in all_states if not s in illegalC1(all_states) +
                        illegalC2(all_states) + illegalC3(all_states) + illegalC4(all_states)]
        return legal_states

    def adjacentNode(n1: str, n2: str):
        """This function determine whether two nodes connect to each other"""
        diff = 0
        if n1[0] == n2[0]:
            return False
        else:
            for i in range(1, 9):
                if n1[i] != n2[i]:
                    diff += 1
        return (diff > 0 and diff < 3)

    def nextState(a_state: str, all_states: list):
        """This fuction returns a set of states that a given state can go to."""
        neighborStates = []

        for s in all_states:
            if adjacentNode(a_state, s):
                neighborStates.append(s)

        return neighborStates

    def genGraph(legal_states: list):
        """
        Generate a graph based on all legal states
        """
        graph = {}

        for n in range(len(legal_states)):
            setNextNodes = nextState(legal_states[n], legal_states)
            graph.update({legal_states[n]: setNextNodes})

        return graph

    def findShortestPath(graph: dict, start: str, end: str, path=[]):
        nonlocal i
        i = 0
        if i == 0:  # initialze
            thisNode = start
            allPath = {}
        else:
            while end not in path:
                for nextNode in graph[thisNode]:
                    path += [Nextnode]
                    allPath.update{i:path}
            i += 1
        

        return

    print(genAllStates())
    print(len((genLegalStates(genAllStates()))))
    print(len(illegalC1(genAllStates())))
    print(len(illegalC2(genAllStates())))
    print(len(illegalC3(genAllStates())))
    print(len(illegalC4(genAllStates())))
    print(len([s for s in genAllStates() if (s in illegalC2(
        genAllStates()) and s in illegalC3(genAllStates()))]))
    print(len([s for s in genAllStates() if (s in illegalC2(
        genAllStates()) and s in illegalC4(genAllStates()))]))
    print(len([s for s in genAllStates() if (s in illegalC3(
        genAllStates()) and s in illegalC4(genAllStates()))]))
    print(len([s for s in genAllStates() if (s in illegalC2(genAllStates())
                                             and s in illegalC3(genAllStates()) and s in illegalC4(genAllStates()))]))

    graph = genGraph(genLegalStates(genAllStates()))
    print("########")
    print(graph)
    print("########")
    print(findShortestPath(graph, "EEEEEEEEE", "WWWWWWWWW", path=[]))


main()
