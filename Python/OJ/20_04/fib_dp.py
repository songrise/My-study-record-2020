class Solution:

    def fib(self, N: int) -> int:
        dp = [0, 1]+[0 for i in range(30)]
        if N <= 1:
            return 1
        else:
            for i in range(2,N):
                dp[i]+= dp[i-1]+dp[i-2]
        return dp[N-1]
