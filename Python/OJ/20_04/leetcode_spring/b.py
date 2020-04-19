class Solution:
    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        ans = 0
        len_ = len(relation)
        queue = []

        for j in range(len_):
            if relation[j][0] == 0:
                queue.append(relation[j])

        for i in range(k-1):
            level = len(queue)
            for k in range(level):
                node = queue.pop(0)
                next_ = node[1]
                for j in range(len_):
                    if relation[j][0] == next_:
                        queue.append(relation[j])

        for nodes in queue:
            if nodes[1] == n-1:
                ans += 1

        return ans
