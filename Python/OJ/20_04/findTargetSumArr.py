#attempt dp...

class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        len_ = len(nums)
        dp = [0]*len_
        if nums[0] == S:
            dp[0] = 1
        else:
            dp[0] = 0

        for i in range(1, len_):
            dp[i] = dp[i-1]
            if dp :
                dp[i]+=1

        return dp[len_-1]


#dfs

class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        len_=len(S)
        stack = [nums[0]]
        while stack:
