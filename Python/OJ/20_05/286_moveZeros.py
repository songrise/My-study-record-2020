class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        len_ = len(nums)
        j = 0
        for i in range(len_):
            if nums[i] != 0:
                nums[j] = nums[i]
                j+=1

        while (j<len_):
            nums[j] = 0
            j+=1



