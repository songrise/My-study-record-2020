# Solution 1 (iterate first index, Binary search second index)


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        len_ = len(numbers)

        for i in range(len_):
            a = numbers[i]
            b = target - a
            start = i+1
            end = len_
            while start <= end:
                mid = (start + end)//2
                if numbers[mid] == b:  # found
                    return [i+1, mid+1]
                # binary search
                if numbers[mid] > b:
                    end = mid-1
                else:
                    start = mid+1

# Solutions (double pointer)


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        len_ = len(numbers)
        lastNum = numbers[len_-1]
        for i in range(len_):
            a = numbers[i]
            if a + lastNum < target:
                continue
            elif a + lastNum == target:
                return [i+1, len_]
            else:  # >
                for j in range(i+1, len_):
                    if a + numbers[j] == target:
                        return[i+1, j+1]
