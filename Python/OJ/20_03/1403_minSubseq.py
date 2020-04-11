

class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort()
        len_ = len(nums)
        i = len_-1
        sub = 0
        sum_ = sum(nums)
        ans = []
        while i >= 0:
            ans.append(nums[i])
            sub += nums[i]
            sum_ -= nums[i]
            if sub > sum_:
                break
            i -= 1
        return ans
