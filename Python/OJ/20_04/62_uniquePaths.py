#dynamic programming


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1]*m] + [[1]+[0]*(m-1) for _ in range(n-1)]
        for i in range(1,n):
            for j in range(1,m):
                dp[i][j]= dp[i][j-1]+dp[i-1][j]
        return dp[n-1][m-1]
