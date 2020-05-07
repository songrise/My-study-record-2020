import random, copy

# directed graph
def genRandomDirectedGraph(n,m):
    #setOfNodes = set([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
    setOfNodes = set(i for i in range(n))
    graph = dict()
    for node in setOfNodes:
        setOfNodes.remove(node)
        graph[node] = random.sample(setOfNodes, m)
        setOfNodes.add(node)

    return graph

    
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


randomGraph = genRandomDirectedGraph(15,2)
print("The graph is:")
print(randomGraph)
print()
print("The shortest paths are:")
for node in range(1,15):
    print(findShortestPath(randomGraph, node, 0, path=[]))

print()
randomGraph = genRandomDirectedGraph(25,2)
print("The graph is:")
print(randomGraph)
print()
print("The shortest paths are:")
for node in range(1,25):
    print(findShortestPath(randomGraph, node, 0, path=[]))

print()
randomGraph = genRandomDirectedGraph(50,2)
print("The graph is:")
print(randomGraph)
print()
print("The shortest paths are:")
for node in range(1,50):
    print(findShortestPath(randomGraph, node, 0, path=[]))
    
"""
randomGraph = genRandomUndirectedGraph()
print(randomGraph)
print()
for node in range(9):
    print(findShortestPath(randomGraph, node, 9, path=[]))
"""


