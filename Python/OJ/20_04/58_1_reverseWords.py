class Solution:
    def reverseWords(self, s: str) -> str:
        stack = []

        word = ""
        for c in s:
            if c != " ":
                # if word != " ":  # ignore mutiple white spaces
                word += c
                continue
            else:
                if word != "":
                    stack.append(word)
                    word = ""
        stack.append(word)  # last word

        ans = stack.pop()[1:]
        while len(stack):
            ans += stack.pop()
            if len(stack):
                ans += " "

        return ans
