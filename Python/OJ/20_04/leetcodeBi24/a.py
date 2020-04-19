class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        len_ = len(nums)
        i = 1
        while True:
            sum_ = i
            for j in range(len_):
                sum_+=nums[j]
                if sum_ < 1:
                    break
                if j == len_-1:
                    return i
            i+=1
