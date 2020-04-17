class Solution:
    def calPoints(self, ops) -> int:
        stack = []
        sum_ = 0
        for op in ops:
            if op == "C":
                temp = stack.pop()
                sum_ -= temp
            elif op == "D":
                temp = stack[-1] * 2
                sum_ += temp
                stack.append(temp)
            elif op == "+":
                temp = stack[-1] + stack[-2]
                sum_ += temp
                stack.append(temp)
            else:
                sum_ += (int(op))
                stack.append(int(op))
        return sum_


a = Solution()
a.calPoints(["5", "-2", "4", "C", "D", "9", "+", "+"])
