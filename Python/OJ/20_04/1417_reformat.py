class Solution:
    def reformat(self, s: str) -> str:
        char = []
        num = []
        for c in s:
            if c.isalpha():
                char.append(c)
            else:
                num.append(c)
        lenc = len(char)
        lenn = len(num)
        ans = ""
        if abs(lenc - lenn) > 1:
            return ans
        else:
            if lenc > lenn:
                while (len(num)):
                    ans += char.pop(0)
                    ans += num.pop(0)
                ans += char.pop(0)
                return ans
            else:
                while (len(char)):
                    ans += num.pop(0)
                    ans += char.pop(0)
                if len(num):
                    ans += num.pop(0)
                return ans
