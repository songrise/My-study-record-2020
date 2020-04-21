class Solution:


class Solution:
    def countBits(self, num: int) -> List[int]:
        dp = [0]*(num+1)
        for i in range(1, num+1):
            dp[i] = dp[i & (i-1)]+1
        return dp

# sol2


class Solution:
    def countBits(self, num: int) -> List[int]:
        dp = [0]*(num+1)
        for i in range(1, num+1):
            if i & 1:
                dp[i] = dp[i//2]
            else:
                dp[i] = dp[i-1]+1
        return dp
