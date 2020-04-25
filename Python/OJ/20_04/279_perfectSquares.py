# greedy is wrong.
class Solution:
    def numSquares(self, n: int) -> int:
        square = [num*num for num in range(1, 100)]
        len_ = len(square)
        count = 0
        while n > 0:

            left = 0
            right = len_-1
            while left <= right:
                mid = (left+right)//2
                if square[mid] == n:
                    return count+1
                elif square[mid] < n:
                    left = mid+1
                else:
                    right = mid-1
            n -= square[right]
            count += 1

        return count

# dp


class Solution:
    def numSquares(self, n: int) -> int:
        square = [num*num for num in range(1, 100)]
        dp = [0]*n
        dp[1] = 1
        for i in range(1, n):
            if i+1 in square:
                dp[i] = 1
            else:
                
        return dp[n-1]
