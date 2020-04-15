class Solution:
    def addDigits(self, num: int) -> int:
        while num >= 10:
            numS = str(num)
            num = 0
            for i, k in enumerate(numS):
                num += int(k)
        return num
