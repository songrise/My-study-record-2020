class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        dp = [False]*len(s)
        a = 0
        for i in range(len(t)):
            if t[i] == s[0]:
                a = i
                dp[0] = True
        if dp[0] == False:
            return False
        for i in range(1, len(dp)):
            for j in range(a, len(t)):
                if t[j] == s[i]:
                    a = j
                    dp[i] = dp[i-1]
        return dp[-1]
