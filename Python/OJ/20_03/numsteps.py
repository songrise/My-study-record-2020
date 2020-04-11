class Solution:
    def numSteps(self, s: str) -> int:

        s = eval('0b'+s)
        n = 0
        while s != 1:
            if (s & 1):
                s += 1
            else:
                s >>= 1
            n += 1
        return n
