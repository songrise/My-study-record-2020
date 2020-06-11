class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        l = len(T)
        day = [0]*l
        stack= []
        for i,temp in enumerate(T):
            if not stack or temp > T[stack[-1]]:
                stack.append(i)
            else:
                d = 0
                while(stack and T[stack[-1]] >= temp):
                    t = stack.pop()
                day[i] = d 


        return day
