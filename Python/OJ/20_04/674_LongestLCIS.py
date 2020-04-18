class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        len_ = len(nums)
        if len_ <= 1:
            return len_
            
        dp = [0 for i in range(len_)]
        dp[0] = 1
        len__ = dp[0]
        for i in range(1,len_):
            if nums[i]>nums[i-1]:
                len__ +=1
            else:
                len__ = 0

            if len__>dp[i-1]:
                dp[i]=dp[i-1]+1
        return dp[len_-1]

# space complexity O(1)

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        len_ = len(nums)
        if len_ <= 1:
            return len_

        len__ = 1
        longest = len_
        for i in range(1,len_):
            if nums[i]>nums[i-1]:
                len__ +=1
            else:
                len__ = 1

            if len__>longest:
                longest=len__

        return longest