# This program solves the problem by finding a shortest path

def solver():
    """
    The main program prints out a human-readable solution to the problem.
    # Input: None
    # Output: None
    """
    setAllStates = genStates()                  # Generate a set of all possible states
                                                # Each state consists of 7 characters, each of which could be
                                                # E(ast)/W(est):
                                                # 1st: the current position of the boat
                                                # 2nd: green husband
                                                # 3rd: green wife
                                                # 4th: red husband
                                                # 5th: red wife
                                                # 6th: blue husband
                                                # 7th: blue wife
    
    G = genGraph(setAllStates)                  # Generate a graph G from the set of states (nodes)
    
    src = "EEEEEEE"                             # The beginning state where all are on the east side.
    des = "WWWWWWW"                             # The terminating state when the problem is solved

    path = findShortestPath(G,src,des,path=[])  # Generate the path by finding a shortest path from
                                                # a source node src to a destination node.

    printPath(path)                             # Print the path in a reading-friendly format

    #allPaths = findAllPaths(G,src,des,path=[])
    #print(allPaths)
    
    return
    
    
def genStates():
    """
    This functions generates a set of all possible states (E/W,E/W,E/W,E/W,E/W,E/W,E/W).
    Input: None
    Output: Return a set of all possible states (E/W,E/W,E/W,E/W,E/W,E/W,E/W).
    """

    states = ["".join((i,j,k,l,m,n,o)) for i in ["E","W"] for j in ["E","W"] for k in ["E","W"] for l in ["E","W"] \
                                       for m in ["E","W"] for n in ["E","W"] for o in ["E","W"]]
    return tuple(states)


def genGraph(S):
    """
    This function generates a graph from S, a set of all possible states.
    Input: A set of all possible states
    Output: Return a graph based on a set of all possible states and given constraints.
    """
    
    # Create a set of all legal states from all possible states
    setLegalStates = []
    # Create an empty dictionary for the final graph
    graph = {}

    # For each node n in S, find the set of other nodes that node n can connect to
    for n in range(len(S)):
        if isAStateLegal(S[n]) == True:     # check whether a node (state) is legal
            setLegalStates.append(S[n])     # If legal, add n to the set of all legal states

    # For each legal state n,
    #   First: find the set of other legal nodes that n can connect to
    #   Second: add n and the links to other legal nodes to the graph            
    for n in range(len(setLegalStates)):
        setNextNodes = nextStates(setLegalStates[n],setLegalStates)
        graph.update({setLegalStates[n]:setNextNodes})

    for key in list(graph.keys()):  #remove disconncted nodes
        if graph[key] == []:
            del graph[key]   

    # For debugging
    #for i in graph:
    #    print(i, graph[i])

    return graph
    
            
def isAStateLegal(state):
    """
    This function determines whether a state is legal or not.
    Input: A state
    Output: If a state is legal, return true; else, false
    """

    # The if() statement expresses the condition for illegal state
    if ((state[1] != state[2] and (state[2] == state[3] or state[2] == state[5])) or \
        (state[3] != state[4] and (state[4] == state[1] or state[4] == state[5])) or \
        (state[5] != state[6] and (state[6] == state[1] or state[6] == state[3])) or \
        # The boat is on the side where there is no one.
        (state[0] != state[1] and state[1] == state[2] == state[3] == state[4] == state[5] == state[6])):
        return False
    else:
        return True
    

def nextStates(aState,allStates):
    """
    This function returns a set of states that a given state can go to.
    Input: A state (aState) and a set of a states (allStates)
    Output: A set of states from allStates that aState can go to (i.e., neighboring states
    """
    
    neighborStates = []
            
    # Determine which states could be reached by the given states
    for m in allStates:
        # A neighbor node if the two states differ by one or two elements
        # in their states
        if neighborNode(aState,m) == True:
            neighborStates.append(m)

    return neighborStates


def neighborNode(n1, n2):
    """
    This function determines whether the states n1 and n2 are neighboring states
    (i.e., the boats are on different sides and there are no more than two changes in
    their positions).
    Input: Two states n1 and n2
    Output: Return true if they are neighboring states; else false
    """
    diff = 0
    if n1[0] != n2[0]:
        for i in range(1,7):
            if n1[i] == n1[0]:
                if n1[i] != n2[i]:
                    diff = diff + 1
            else:
                if n1[i] != n2[i]:
                    return False
    else:
        return False
        
    if diff > 0 and diff < 3:
        return True
    else:
        return False


# You are not expected to implement this function.
# You should have the skill of finding a suitable implementation
# to help solve the program.
def findShortestPath(graph, start, end, path=[]):
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
#    if not graph.has_key(start):
    if not (start in graph):
        return None
    shortestPath = None
    for node in graph[start]:
        if node not in path:
            newpath = findShortestPath(graph, node, end, path)
            if newpath:
                if not shortestPath or len(newpath) < len(shortestPath):
                    shortestPath = newpath

    #print(shortestPath)
    return shortestPath


def printPath(path):
    """
    This function prints out the solution in a reading friendly format.
    Input: A path
    Output: A print out of the exact order of what is/are transported from one side to the other each time.
    """

    listPersons = ["","green husband", "green wife", "red husband", "red wife", "blue husband", "blue wife"]
    
    for nodeOnPath in range(len(path)-1):
        # For each node on the path, except the last one, determine
        # the direction of crossing the river.
        if path[nodeOnPath][0] == "E":
            fromDirection = "east"
            toDirection = "west"
        else:
            fromDirection = "west"
            toDirection = "east"

        whichPersonCrossing = ""
        # Determine who went to the other side
        for j in range(1,len(path[nodeOnPath])):
            if path[nodeOnPath][j] != path[nodeOnPath+1][j]:
                whichPersonCrossing = whichPersonCrossing + str(j)

        # print out the objects being shipped each time by the man in order
        # to bring all three objects from the east to the west.
        printLine = "The "
        if len(whichPersonCrossing) == 1:    
            printLine = printLine + listPersons[int(whichPersonCrossing[0])] + " goes"
        else:
            printLine = printLine + listPersons[int(whichPersonCrossing[0])] + " and " + listPersons[int(whichPersonCrossing[1])] + " go"

        printLine = printLine + " from the " + fromDirection + " to the " + toDirection + "."
        print(str(nodeOnPath+1),printLine)

solver()
graph = genGraph(genStates())
for key in graph.keys():
    value = "{" + ", ".join(graph[key]) + "}"
    print("{}: {}".format(key,value))
