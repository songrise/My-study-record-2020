class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 1:
            return x
        else:
            return x * self.mypow(x, n//2)
