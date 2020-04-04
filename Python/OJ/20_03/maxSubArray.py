class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 0:
            return 0
        maxSum = crtSum = nums[0]

        for i in range(1, length):
            if crtSum < 0:
                # if current sum is neg, discard it. Since the sum begin at i will be larger.
                crtSum = nums[i]
            else:
                crtSum += nums[i]

            maxSum = max(crtSum, maxSum)

        return maxSum
