class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        len_=len(nums)
        for i in range(len_):
            if nums[i] == i:
                return i
        return -1