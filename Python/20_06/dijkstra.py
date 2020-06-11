Inf = 0x7fffffff
adjacency = [[0, 3, 10, Inf, Inf, Inf],
             [Inf, 0, 7, 8, Inf, Inf],
             [Inf, Inf, 0, 2, 4, Inf],
             [Inf, Inf, Inf, 0, Inf, Inf],
             [Inf, 2, Inf, Inf, 0, 7],
             [Inf, Inf, Inf, Inf, Inf, 0],
             ]
A2 = [[0, 1, 12, Inf, Inf, Inf],
      [Inf, 0, 9, 3, Inf, Inf],
      [Inf, Inf, 0, Inf, 5, Inf],
      [Inf, Inf, 4, 0, 13, 15],
      [Inf, Inf, Inf, Inf, 0, 4],
      [Inf, Inf, Inf, Inf, Inf, 0]]


def dijkstra(adjacency: list) -> list:
    """
    Input: a adjacency matrix
    Return shortest distance from first vertex to other vertices.
    """

    # initialize, assume start from first vertex
    len_ = len(adjacency)
    known = [1]+[0]*(len_-1)
    dist = [0]+[Inf]*(len_-1)
    src = 0

    while 1:
        # update dest
        for i in range(len_):
            dist[i] = min(dist[i], dist[src]+adjacency[src][i])

        # update known
        UnknownDest = [dist[j] for j in range(len_) if known[j] == 0]
        known[dist.index(min(UnknownDest))] = 1
        src = dist.index(min(UnknownDest))

        # check end condition
        if known == [1]*len_:
            return dist


print(dijkstra(A2))


def dijkstra2(adjacency: list, destination: int) -> list:
    """
    Input: a adjacency matrix
    Return shortest path from first vertex to dest .
    """

    # initialize, assume start from first vertex
    len_ = len(adjacency)
    known = [1]+[0]*(len_-1)
    dist = [0]+[Inf]*(len_-1)
    parent = [0]*len_
    src = 0

    while 1:
        # update dest
        for i in range(len_):
            if dist[src]+adjacency[src][i] < dist[i]:
                dist[i] = dist[src]+adjacency[src][i]
                parent[i] = src

        # update known
        UnknownDest = [dist[j] for j in range(len_) if known[j] == 0]
        known[dist.index(min(UnknownDest))] = 1
        src = dist.index(min(UnknownDest))

        # check end condition
        if known == [1]*len_:
            return parent


print(dijkstra2(adjacency, 5))
