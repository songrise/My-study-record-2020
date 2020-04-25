class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        len_ = len(cost)
        dp = [0]*len_
        for i in range(2, len_):
            dp[i] = min((dp[i-2]+cost[i-2]), (dp[i-1]+cost[i-1]))
        return min(dp[-1]+cost[-1], dp[-2]+cost[-2])


# O(1) space complexity

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        pre, cur = cost[0], cost[1]
        for c in cost[2:]:
            cur, pre = min(pre, cur)+c, cur
        return min(pre, cur)
