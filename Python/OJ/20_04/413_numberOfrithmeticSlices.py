# https://leetcode-cn.com/problems/arithmetic-slices/solution/deng-chai-shu-lie-hua-fen-by-leetcode/
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        dp = [0 for _ in range(len(A))]
        sum_ = 0
        for i in range(2, len(A)):
            if A[i]-A[i-1] == A[i-1]-A[i-2]:
                dp[i] = dp[i-1]+1
                sum_ += dp[i]
        return sum_
