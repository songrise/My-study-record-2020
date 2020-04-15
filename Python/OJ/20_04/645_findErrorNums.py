class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums.sort()
        l = len(nums)
        a = 0
        for i in range(l):
            if nums[i] < i+1:
                return[nums[i], i+1]
            elif nums[i] > i+1:
                if a:
                    return[nums[i], a]
                else:
                    a = i+1
