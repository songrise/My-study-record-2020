class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        len_ = len(nums)
        if len_ == 1:
            return nums[0]
        dp = [0 for _ in range(len_)]
        dp[0] = nums[0]
        for i in range(1, len_):
            if dp[i-1] < 0:
                dp[i] = nums[i]  # start new sub array
            else:
                dp[i] = dp[i-1]+nums[i]  # continue last subarray

        return max(dp)
