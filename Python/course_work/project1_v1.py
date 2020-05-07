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
        if n1[0] != n2[0]:
            for i in range(1, 9):
                if n1[i] == n1[0]:
                    if n1[i] != n2[i]:
                        diff = diff + 1
                else:
                    if n1[i] != n2[i]:
                        return False
        else:
            return False
        return (diff > 0 and diff < 3)

    def shortestNode(n1: str, n2: str):
        diff = 0
        if adjacentNode(n1, n2):
            for i in range(1, 9):
                if n1[i] != n2[i]:
                    diff += 1
            if n1[1] == n2[1] and n1[2] == n2[2]and n1[3] == n2[3] and n1[6] == n2[6]:
                return False
            else:
                return True
        else:
            return False

    def nextState(a_state: str, legal_states: list):
        """This fuction returns a set of states that a given state can go to."""
        neighborStates = []

        for s in legal_states:
            if shortestNode(a_state, s):
                neighborStates.append(s)

        return neighborStates

    def genGraph(legal_states: list):
        """
        Generate a graph based on all legal states
        """
        graph = {}

        for n in range(len(legal_states)):
            setNextNodes = nextState(legal_states[n], legal_states)
            if setNextNodes == []:
                continue                
            graph.update({legal_states[n]: setNextNodes})
        
        key_to_del=[]
        for key in graph.keys():
            if len(graph[key]) == 1: #graph[key] refer to nextnode(s) where key is current node
                try:
                    if key in graph[graph[key][0]]: #graph[key][0] refer to the only connected node
                        print(key)
                        print(graph[key])
                        graph[graph[key][0]].remove(key)
                        key_to_del.append(key)
                except KeyError:
                    key_to_del.append(key)
         
            if len(graph[key]) == 0:
                key_to_del.append(key)   
        print(key_to_del)    
        for k in key_to_del:
            graph.pop(k)

        return graph

    def findShortestPath(graph: dict, start: str, end: str, path=[]):
        path = path + [start]
        if start == end:
            return path
        # if not graph.has_key(start):
        if not (start in graph):
            return None
        shortestPath = None
        # "node" are those which connected to "start".
        for node in graph[start]:
            if node not in path:
                newpath = findShortestPath(graph, node, end, path)
                if newpath:
                    if not shortestPath or len(newpath) < len(shortestPath):
                        shortestPath = newpath
            # print(shortestPath)
        return shortestPath

    all_states = genAllStates()
    legal_states = genLegalStates(all_states)

    print(all_states)
    print(len((legal_states)))
    print(len(illegalC1(all_states)))
    print(len(illegalC2(all_states)))
    print(len(illegalC3(all_states)))
    print(len(illegalC4(all_states)))
    print(len([s for s in all_states if (s in illegalC2(
              all_states) and s in illegalC3(all_states))]))
    print(len([s for s in all_states if (s in illegalC2(
        all_states) and s in illegalC4(all_states))]))
    print(len([s for s in all_states if (s in illegalC3(
        all_states) and s in illegalC4(all_states))]))
    print(len([s for s in all_states if (s in illegalC2(all_states)
                                         and s in illegalC3(all_states) and s in illegalC4(all_states))]))
    print(len([s for s in all_states if (s in illegalC2(all_states)and s not in illegalC3(all_states)
                                         and s not in illegalC4(all_states) and s not in illegalC1(all_states))]))
    print(len([s for s in all_states if (s in illegalC3(all_states)and s not in illegalC2(all_states)
                                         and s not in illegalC4(all_states) and s not in illegalC1(all_states))]))
    print(len([s for s in all_states if (s in illegalC4(all_states)and s not in illegalC3(all_states)
                                         and s not in illegalC2(all_states) and s not in illegalC1(all_states))]))

    graph = genGraph(legal_states)
    genGraph(legal_states)
    print("########")
    for key in graph.keys():
        print(key, graph[key])
    print(len(graph))
    print("########")
    shortestPath = findShortestPath(graph, "EEEEEEEEE", "WWWWWWWWW", path=[])
    print("########")
    print(shortestPath)


main()
