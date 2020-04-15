class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid)
        m = len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1 or obstacleGrid[n-1][m-1] == 1:
            return 0

        dp = [[0]*m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = -1
        dp[0][0]=1
        for i in range(n):
            for j in range(m):
                if dp[i][j] == -1:
                    dp[i][j] = 0
                elif i == 0:
                    dp[i][j] = dp[i][j-1]
                elif j == 0:
                    dp[i][j] = dp[i-1][j]

                else:
                    dp[i][j] = dp[i][j-1]+dp[i-1][j]
        return dp[n-1][m-1]
