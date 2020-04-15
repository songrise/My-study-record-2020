class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack, n, tmp_k = [], len(num), k
        for index, val in enumerate(num):
            while stack and int(stack[-1]) > int(val):
                stack.pop()
                k -= 1
                if not k:
                    return (''.join(stack) + num[index:]).lstrip('0') or '0'
            stack.append(val)
        return ''.join(stack[:n-tmp_k]).lstrip('0') or '0'


k = Solution()
k.removeKdigits("1432219", 3)
