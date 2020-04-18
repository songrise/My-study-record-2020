class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        len_ = len(prices)
        if len_ <1:
            return 0
        dp = [0 for _ in range(len_)]
        min_ = prices[0]
        for i in range(1,len_):
            if prices[i]-min_ >dp[i-1]:
                dp[i] = prices[i]-min_
            else:
                dp[i] = dp[i-1]
                
            if prices[i]< min_:
                min_ = prices[i]

        return dp[len_-1]

