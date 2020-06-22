class Solution:
    def checkIfPrerequisite(self, n: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        require =[[False for _ in range(n)] for _ in range(n)]
        for pre, cur in prerequisites:
            require[pre][cur] = True

        for k in range(n):
            for i in range(i):
                for j in range(j):
                    if require[i][j]:
                        continue
                    else:
                         require[i][j] = require[i][k] and require[k][j]
        ans = []
        for k,v in queries:
            ans.append(require[k][v])
        return ans