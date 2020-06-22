class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        l = len(T)
        day = [0]*l
        stack= []
        for i,temp in enumerate(T):
            interval = 0
            while(stack and T[stack[-1]] < temp):
                t = stack.pop()
                interval = i-t
            day[i] = interval

            stack.append(i)

        return day
