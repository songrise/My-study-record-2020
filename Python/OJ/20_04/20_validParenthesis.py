class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        left = ["(", "{", "["]
        d = {")": "(", "}": "{", "]": "["}
        for char in s:
            if char in left:
                stack.append(char)
            else:
                if len(stack) == 0:
                    return False
                if stack[-1] != d[char]:
                    return False
                else:
                    stack.pop()
        if len(stack) == 0:
            return True
        else:
            return False
