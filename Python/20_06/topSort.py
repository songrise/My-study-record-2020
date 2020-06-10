# toplogical Sort a DAG

# DAG is in form of a adjacent list
DAG = [{0: [1]}, {1: [2]}, {2: [3, 4]}, {3: [6, 7]}, {
    4: [5]}, {5: [9]}, {6: [8]}, {7: [8]}, {8: [9]}, {9: []}]


def initInDegree(DAG: list) -> list:
    indegree = [0]*len(DAG)
    # initialize indegree
    for i in range(len(DAG)):
        dest = DAG[i][i]
        for d in dest:
            indegree[d] += 1
    # print(indegree)
    return indegree


def findIndgreeZero(indegree: list, route: list) -> int:
    for i, entry in enumerate(indegree):
        if entry == 0 and i not in route:
            return i
    return -1


def topSort(DAG: list) -> list:
    route = []
    indegree = initInDegree(DAG)

    for i in range(len(DAG)):
        v = findIndgreeZero(indegree, route)
        if (v == -1):
            print("Error! Graph has a cycle")
            return None
        dest = DAG[v][v]
        for d in dest:
            indegree[d] -= 1
        route.append(v)
        print("route", route)
        print("indegree", indegree)

    return route


print(topSort(DAG))
