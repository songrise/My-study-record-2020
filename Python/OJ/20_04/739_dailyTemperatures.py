class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        len_ = len(T)
        if(len_ == 1):
            return [0]

        stack = []
        ans = [0]*len_

        for k, v in enumerate(T): 
            while stack and T[stack[-1]]<=v:
                ans[stack[-1]] = k - stack[-1]
                stack.pop()
            stack.append(k)
        return ans
