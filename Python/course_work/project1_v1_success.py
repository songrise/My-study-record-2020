def main():
    """
    This is the main function to call other functions to print the expected output.
    Input:None
    Output:Return None
    """

    def genAllStates():
        """
        This function generates all possible states.
        Input:None.
        Output:Return a list containing all possible states.
        """
        allStates = ["".join((B, M, P, H1, W1, S1, H2, W2, S2)) for B in "EW" for M in "EW" for P in "EW" for H1 in "EW"
                     for W1 in "EW" for S1 in "EW" for H2 in "EW" for W2 in "EW" for S2 in "EW"]
        # B for boat, M for Mose, H for husband , S for servant, etc.
        return allStates

    def illegalC1(all_states: list):
        """
        This function find the states that violates the constraint of having the boat with at least a man(C1).
        Input: A list containing all possible states.        
        Output: Return a list containing all illegal states that violates C1
        """
        C1 = []
        for s in all_states:
            if (s[0] != s[1] and s[0] != s[2] and s[0] != s[3] and s[0] != s[6]):
                C1.append(s)
        return C1

    def illegalC2(all_states: list):
        """
        This function find the states that violates the constraint of preventing Pharaoh from beating others(C2).
        Input: A list containing all possible states.        
        Output: Return a list containing all illegal states that violates C2.
        """

        C2 = []
        for s in all_states:
            if s[1] != s[2]:
                if not (s[2] != s[3] and s[2] != s[4] and s[2] != s[5] and s[2] != s[6] and s[2] != s[7] and s[2] != s[8]):
                    C2.append(s)
        return C2

    def illegalC3(all_states: list):
        """
        This function find the states that violates the constraint of preventing Ananias from beating Ahab's household(C3).
        Input: A list containing all possible states.        
        Output: Return a list containing all illegal states that violates C3.
        """
        C3 = []
        for s in all_states:
            if (s[6] == s[4] or s[6] == s[5]) and (s[3] != s[6]):
                C3.append(s)
        return C3

    def illegalC4(all_states: list):
        """
        This function find the states that violates the constraint of preventing Ahab from beating Ananias's household (C4).
        Input: A list containing all possible states.        
        Output: Return a list containing all illegal states that violates C4.
        """
        C4 = []
        for s in all_states:
            if (s[3] == s[7] or s[3] == s[8]) and (s[6] != s[3]):
                C4.append(s)
        return C4

    def genLegalStates(all_states: list):
        """
        This function find the legal states according to all constraints.
        Input: A list containing all possible states.        
        Output: Return a list containing all llegal states.
        """
        legal_states = [s for s in all_states if not s in illegalC1(all_states) +
                        illegalC2(all_states) + illegalC3(all_states) + illegalC4(all_states)]
        # if a state is not illegal, then it is legal
        return legal_states

    def adjacentNode(n1: str, n2: str):
        """
        This function determine whether two nodes connect to each other
        Input: two strings which stand for two states        
        Output: Return True if they are adjacent according to constraints, else False.
        """
        diff = 0
        if n1[0] != n2[0]:
            for i in range(1, 9):
                if n1[i] == n1[0]:
                    if n1[i] != n2[i]:
                        diff += 1
                else:
                    if n1[i] != n2[i]:
                        return False
        else:
            return False
        return (diff > 0 and diff < 3)

    def shortestNode(n1: str, n2: str):
        """
        This function determain whether the given nodes satisfy the necessary 
        condition for being part of shortest paths. (i.e., Not sufficient and neccessary)
        Input: two strings which stand for two states        
        Output: Return True if they satisfy the necessary condition for being part of shortest paths.
        """
        diff = 0
        if adjacentNode(n1, n2):
            for i in range(1, 9):
                if n1[i] != n2[i]:
                    diff += 1
            if n1[1] == n2[1] and n1[2] == n2[2]and n1[3] == n2[3] and n1[6] == n2[6]:
                # if the boat moves without at least one man moves. then this link is invalid.
                return False
            else:
                return True
        else:
            return False

    def nextState(a_state: str, legal_states: list):
        """
        This fuction returns a set of states that a given state can go to.
        (Obtained from 3couple.py)
        Input: a str for a certain states and a list fo all legalstates
        Output: Return a list containing the neighbor states of the given state
        """
        neighborStates = []

        for s in legal_states:
            if shortestNode(a_state, s):
                neighborStates.append(s)

        return neighborStates

    def genShortestGraph(legal_states: list):
        """
        Generate a graph containing only nodes belong to shortest path based on all legal states.
        Input: a list containing all legal states
        Output: a dict 
        """
        graph = {}
        possible_graphs = []
        #The graph may not contain noly shortest path nodes, so we just call it possible.       
        
        for n in range(len(legal_states)):
            setNextNodes = nextState(legal_states[n], legal_states)
            if setNextNodes == []:
                continue
            graph.update({legal_states[n]: setNextNodes})
        
        while True:
            # Loop until the shortest nodes are found.
            key_to_del = []  # a list to store the key that to be deleted.
            for key in graph.keys():
                if not key == "EEEEEEEEE" and not key == "WWWWWWWWW":
                    # Start and end are just connected to one direction, thus their next node can be only one
                    # (I.e., The "start" node have no "in" nodes since it is the first step)
                    # While other nodes must have both the "in" and "out", that is to say another node to come and another node to go.
                    if len(graph[key]) == 1:
                        # if a node(exclude first and end) have only the "in" node, (i.e. can only move back)
                        graph[graph[key][0]].remove(key)
                        key_to_del.append(key)
                for key in graph.keys():
                    if len(graph[key]) == 0:
                        key_to_del.append(key)
            for k in key_to_del:
                try:
                    del graph[k]
                    # delete key:value if value is a list with only one item or no item.
                except KeyError:
                    pass
            possible_graphs.append(graph)
            if len(possible_graphs) > 1:
                if possible_graphs[-1] == possible_graphs[-2]:
                    # When the graph no longer updates.(Last two graph are identical)
                    break
        return graph

    def findShortestPath(graph: dict, start: str, end: str, path=[]):
        """
        This function finds a shortest path from 'start' to 'end' on a graph
        This function is obtained from https://www.python.org/doc/essays/graphs/
        with one change due to the deprecation of the method has_key().

        Input: A graph ('graph'), a starting node ('start'), an end node ('end') and an empty path ('path')
        Output: Returns a shortest path from 'start' and 'end'.
        """
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

    def fprint(container: list):
        """
        This function print a list in a specific format.
        Input: a list to print
        Output: Return None
        """
        for i in range(len(container)):
            print(container[i], end=" ")
            if (i+1) % 6 == 0:
                print("")

    def translate(n1: str, n2: str, num: int):
        """
        This function convert data abstraction into human-readable words.
        Input: Two str n1, n2 for two states. An int num for the steps
        Output:Return None
        """
        codebook = {'W': 'west', 'E': 'east', 1: 'Moses', 2: 'Pharaoh', 3: 'Ahab', 4: 'Jezebel',
                    5: 'servant of Ahab', 6: 'Ananias', 7: 'Sapphira', 8: 'servant of Ananias'}
        # for decoding abstractions. The ints is index of states abstration.
        E = sorted([codebook[i] for i in range(1, len(n1)) if n1[i] == "E"])
        W = sorted([codebook[i] for i in range(1, len(n1)) if n1[i] == "W"])
        diff = []

        print("East: {}".format(E))
        print("West: {}".format(W))
        for i in range(1, 9):
            if n1[i] != n2[i]:
                diff.append(i)
        if len(diff) == 1:
            i = diff[0]
            print("({}) {} goes from {} to {}.".format(num,
                                                       (codebook[i]), codebook[n1[i]], codebook[n2[i]]))
        if len(diff) == 2:
            i, j = diff[0], diff[1]
            print("({}) {} and {} go from {} to {}.".format(num,
                                                            (codebook[i]), (codebook[j]), codebook[n1[i]], codebook[n2[i]]))
        return None
    #Initialize
    all_states = genAllStates()
    legal_states = genLegalStates(all_states)
    graph = genShortestGraph(legal_states)
    shortestPath = findShortestPath(graph, "EEEEEEEEE", "WWWWWWWWW", path=[])
    # Section A
    print("SECTION A: THE STATE SPACE\n")
    print("The set of legal states: ({})".format(len(legal_states)))
    fprint(legal_states)

    print("\n(C1) The set of illegal states that violates the constraint of\nhaving the boat with at least a man: ({})".format(
        len(illegalC1(all_states))))
    fprint(illegalC1(all_states))
    
    print("\n\n(C2) The set of illegal states that violates the constraint of\npreventing Pharaoh from beating others: ({})".format(
        len(illegalC2(all_states))))
    fprint(illegalC2(all_states))

    print("\n(C3): The set of illegal states that violates the constraint of\npreventing Ananias from beating Ahab's household:({})".format(
        len(illegalC3(all_states))))
    fprint(illegalC3(all_states))

    print("\n(C4): The set of illegal states that violates the constraint of\npreventing  Ahab from beating Ananias's household:({})".format(
        len(illegalC4(all_states))))
    fprint(illegalC4(all_states))

    print("\nThe set of illegal states that violate both C2 and C3: ({})".format(
        len([s for s in all_states if (s in illegalC2(
            all_states) and s in illegalC3(all_states))])))
    fprint([s for s in all_states if (s in illegalC2(
        all_states) and s in illegalC3(all_states))])

    print("\nThe set of illegal states that violate both C2 and C4: ({})".format(
        len([s for s in all_states if (s in illegalC2(
            all_states) and s in illegalC4(all_states))])))
    fprint([s for s in all_states if (s in illegalC2(
        all_states) and s in illegalC4(all_states))])

    print("\nThe set of illegal states that violate both C3 and C4: ({})".format(
        len([s for s in all_states if (s in illegalC3(
            all_states) and s in illegalC4(all_states))])))
    fprint([s for s in all_states if (s in illegalC3(
        all_states) and s in illegalC4(all_states))])

    print("\nThe set of illegal states that violate C2, C3 and C4:({})".format(
        len([s for s in all_states if (s in illegalC2(all_states)
                                       and s in illegalC3(all_states) and s in illegalC4(all_states))])))
    fprint([s for s in all_states if (s in illegalC2(all_states)
                                      and s in illegalC3(all_states) and s in illegalC4(all_states))])

    print("\nThe set of illegal states that violate only C2:({})".format(
        len([s for s in all_states if (s in illegalC2(all_states)and s not in illegalC3(all_states)
                                       and s not in illegalC4(all_states) and s not in illegalC1(all_states))])))
    fprint([s for s in all_states if (s in illegalC2(all_states)and s not in illegalC3(all_states)
                                      and s not in illegalC4(all_states) and s not in illegalC1(all_states))])

    print("\nThe set of illegal states that violate only C3:({})".format(
        len([s for s in all_states if (s in illegalC3(all_states)and s not in illegalC2(all_states)
                                       and s not in illegalC4(all_states) and s not in illegalC1(all_states))])))
    fprint([s for s in all_states if (s in illegalC3(all_states)and s not in illegalC2(all_states)
                                      and s not in illegalC4(all_states) and s not in illegalC1(all_states))])

    print("\nThe set of illegal states that violate only C4:({})".format(
        len([s for s in all_states if (s in illegalC4(all_states)and s not in illegalC3(all_states)
                                       and s not in illegalC2(all_states) and s not in illegalC1(all_states))])))
    fprint([s for s in all_states if (s in illegalC4(all_states)and s not in illegalC3(all_states)
                                      and s not in illegalC2(all_states) and s not in illegalC1(all_states))])
    # Section B
    print("\nSECTION B: FORMING A GRAPH\n")
    print("There are 38 legal states that are part of at least one shortest path.")
    for key in graph.keys():
        print(key, graph[key])

    print("\nThere are 70 legal states that are NOT part of any shortest path.")
    notShortest = []
    for all in all_states:
        if all not in graph.keys():
            notShortest.append(all)
    fprint(notShortest)
    # Section C
    print("\nSECTION C: SHORTEST PATHS\n")
    
    for i in range(len(shortestPath)):
        if i == 17:
            break
        translate(shortestPath[i], shortestPath[i+1], i+1)
    return None


main()
