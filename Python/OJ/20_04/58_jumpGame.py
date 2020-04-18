#dp TLE

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        len_ = len(nums)
        dp = [False for _ in range(len_)]
        dp[0] = True
        for i in range(1, len_):
            for j in range(i):
                gap = i-j
                if dp[j] and nums[j]>=gap:
                    dp[i] = True
        return dp[len_-1]

#Greedy 

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n, rightmost = len(nums), 0
        for i in range(n):
            if i <= rightmost:
                rightmost = max(rightmost, i + nums[i])
                if rightmost >= n - 1:
                    return True
        return False
