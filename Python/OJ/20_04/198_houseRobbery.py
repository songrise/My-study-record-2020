class Solution:
    def rob(self, nums: List[int]) -> int:
        len_ = len(nums)
        if len_ == 0:
            return 0
        if len_ == 1:
            return nums[0]

        dp = [0 for _ in range(len_)]
        dp[0], dp[1] = nums[0], max(nums[0], nums[1])

        if (len_ == 2):
            return max(dp[0], dp[1])

        for i in range(2, len_):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])

        return max(dp[len_-1], dp[len_-2])
