class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        l = len(nums)
        nums.sort()
        dp = [[1] for _ in range(nums[l-1])]

        for i in range(l):
            for j in range(2, i+1):
                if (nums[i] % j == 0):
                    dp[j] = [j] + dp[]
