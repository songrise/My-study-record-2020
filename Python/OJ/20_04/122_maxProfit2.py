class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        len_ = len(prices)
        dp = [0 for _ in range(len_)]
        if len_ <1:
            return 0
        dp = [0 for _ in range(len_)]
        min_ = prices[0]

        for i in range(1,len_):
            if prices[i]-min_ >dp[i-1]: #sold
                dp[i] = prices[i]-min_
                min_ = prices[i+1]
            else:
                dp[i] = dp[i-1]
                
            if prices[i]< min_:
                min_ = prices[i]

        return dp[len_-1]

