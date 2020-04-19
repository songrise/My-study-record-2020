class Solution:
    def minJump(self, jump: List[int]) -> int:
        len_ = len(jump)
        dp = [10000000 for _ in range(len_)]
        dp[0] = 0
        for i in range(1, len_):
            right = 10000000
            for j in range(i):
                if jump[j] == i-j:
                    right=1
