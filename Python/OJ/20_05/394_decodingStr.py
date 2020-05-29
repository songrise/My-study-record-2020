class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        len_ = len(s)
        ans = []
        for c in s:
            if c == "]":
                substr = ""
                while stack[-1] != "[":
                    substr = stack.pop()+substr
                stack.pop()  # pop [
                repTime = ""
                while stack and stack[-1].isdigit():
                    repTime = stack.pop()+repTime
                substr *= int(repTime)
                stack.append(substr)
            else:
                stack.append(c)
        return "".join(stack)
