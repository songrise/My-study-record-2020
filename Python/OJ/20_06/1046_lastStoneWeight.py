from heapq import *


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        for i in range(len(stones)):
            stones[i] = -stones[i]

        heapify(stones)
        while len(stones) > 1:
            y = heappop(stones)
            x = heappop(stones)
            if (x == y):
                continue
            else:
                heappush(stones, y-x)
        if stones:
            return -stones[0]
        else:
            return 0
