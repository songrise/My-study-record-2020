class Solution:
    def canCross(self, stones: List[int]) -> bool:
        len_ = len(stones)
        dp= [False for _ in range(len_)]
        dp[0] = True
        lastJmp = 0
        for i in range(1, len_):
            for j in range(i):
                for k in range(lastJmp-1,lastJmp+2):
                    if stone[j] and k+stones[j] == stones[i]:
                        dp[i] =True
                        lastJmp = k
                        break
        return dp[len_-1]
            
