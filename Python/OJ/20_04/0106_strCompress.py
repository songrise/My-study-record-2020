class Solution:
    def compressString(self, S: str) -> str:
        stack = []
        ans = ""
        for char in S:
            if char.isalpha():
                stack.append(char)
            elif char.isdigit():
                temp = stack.pop*(int(char))
                ans+=temp
        return ans
