class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # init indegree list
        indegree = [0 for _ in range(numCourses)]
        adjacency = [[] for _ in range(numCourses)]

        for pre in prerequisites:
            for cur in pre[1:]:
                indegree[pre[0]] += 1
                adjacency[cur].append(pre[0])

        queue = [v for v in range(numCourses) if indegree[v] == 0]
        while queue:
            pre = queue.pop(0)
            numCourses -= 1
            for cur in adjacency[pre]:
                indegree[cur] -= 1
                if indegree[cur] == 0:
                    queue.append(cur)
        for v in indegree:
            if v != 0:
                return False
        return True
        # return numCourses == 0
