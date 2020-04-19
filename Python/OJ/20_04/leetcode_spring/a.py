class Solution:
    def minCount(self, coins: List[int]) -> int:
        sum_ = 0
        len_ = len(coins)
        for i in range(len_):
            sum_ += coins[i]//2 + coins % 2
        return sum_
