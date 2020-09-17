from itertools import permutations
from math import factorial


class determinant():
    def __init__(self, val: list):
        lenRow = len(val)
        for i in range(lenRow):
            if len(val[i]) != lenRow:
                raise ValueError("The Matrix Should be a Square!")

        self.order = lenRow
        self.val = [[0 for _ in range(self.order)] for __ in range(self.order)]
        self.setVal(val)
        self.result = 0
        self.FindResult()

    def setVal(self, val: list):
        """val is a 2-D list
        set value of the self accordingly, assume order is n
        """
        for c in range(self.order):
            for r in range(self.order):
                self.val[c][r] = val[c][r]

    def numInversions(self, number: str) -> int:
        # return the number of inversions of a given number, O(n^2)
        dp = [0]*len(number)
        if len(number) <= 1:
            return dp[-1]

        for i in range(1, len(dp)):
            number_of_larger = 0
            for j in range(i):
                if int(number[j]) > int(number[i]):
                    number_of_larger += 1
            dp[i] = dp[i-1] + number_of_larger
        return dp[-1]

    @staticmethod
    def sigOfInversions(inversions: int) -> int:
        # return the signal of the inversion
        return 1 if inversions % 2 == 0 else -1

    def FindResult(self):
        result = 0
        sequential = "".join([str(i) for i in range(1, self.order+1)])
        for cur in permutations(sequential, self.order):
            curStr = "".join(cur)
            sigma = self.sigOfInversions(
                self.numInversions(curStr))  # 1 or -1
            for j in range(self.order):
                sigma *= self.val[j][int(curStr[j])-1]
            result += sigma
        self.result = result

    def ShowInfo(self):

        for i in range(self.order):
            print(self.val[i])
        print("The determinant is:" + str(self.result))


if __name__ == if __name__ == "__main__":
    zero1 = determinant([[1, -2, -3], [2, -4, -6], [-4, 1, -2]])
    zero1.ShowInfo()
    test = determinant([[1, 2, 1, 1], [0, 1, 1, 4], [
                       0, 0, -1, 3], [0, 0, 1, -2]])
    test.ShowInfo()
