class Solution:
    def translateNum(self, num: int) -> int:
        num = str(num)
        len_ = len(num)
        if len_ == 1:
            return 1

        dp = [0]*len_
        dp[0] = 1
        for i in range(1, len_):
            if i >= 2:
                if int(num[i-1]) <= 2 and int(num[i]) <= 5:

                    dp[i] = dp[i-2]+dp[i-1]
            else:
                dp[i] = dp[i-1]
        print(dp)

        return dp[-1]
