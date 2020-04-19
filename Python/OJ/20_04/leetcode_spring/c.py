class Solution:
    def getTriggerTime(self, increase, requirements):
        l = len(increase)
        ll = len(requirements)
        cur = [increase[0]]
        temp=[0,0,0]
        for i in range(1, l):
            for _ in range(3):
                temp[_] = cur[i-1][_]
            for j in range(3):
                temp[j] += increase[i][j]
            cur.append(temp)

        for j in range(ll):
            for k in range(3):
                minDay = -1
                temp = requirements[j][k]  # min value of a task

                if temp > cur[l-1][k]:
                    requirements[k] = -1
                    continue

                left = 0
                right = l-1
                mid = (left + right)//2
                while(left < right):
                    if cur[mid][k] == temp:
                        minDay = k+1
                    elif cur[mid][k] < temp:
                        left = mid+1
                    else:
                        right = mid-1
                requirements[j][k] = minDay

        ans = [-1 for i in range(ll)]

        for i in range(ll):
            if -1 in requirements[i]:
                continue
            ans[i] = max(requirements[i][0], requirements[i]
                         [1], requirements[i][2])

        return ans


Solution.getTriggerTime([[2, 8, 4], [2, 5, 0], [10, 9, 8]], [[2, 8, 4], [2, 5, 0], [
                        10, 9, 8]], [[2, 11, 3], [15, 10, 7], [9, 17, 12], [8, 1, 14]])
