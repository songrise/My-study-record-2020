class Solution:
    def getTriggerTime(self, increase, requirements):
        l = len(increase)
        ll = len(requirements)
        a = [0 for i in range(l)]
        b = [0 for i in range(l)]
        c = [0 for i in range(l)]
        a[0] = increase[0][0]
        b[0] = increase[0][1]
        c[0] = increase[0][2]

        for i in range(1, l):
            a[i] = a[i-1]+increase[i][0]
            b[i] = b[i-1]+increase[i][1]
            c[i] = c[i-1]+increase[i][2]

        for j in range(ll):
            if requirements[j][0] > a[l-1]:
                requirements[j][0] = -1
            elif requirements[j][0] == 0:
                requirements[j][0] = 0
            else:
                left = 0
                right = l-1
                mid = (left + right)//2
                while(left < right):
                    if a[mid] == requirements[j][0]:
                        requirements[j][0] = mid+1
                        break
                    elif a[mid] < requirements[j][0]:
                        left = mid+1
                    else:
                        right = mid-1
                if requirements[j][0] > a[right]:
                    requirements[j][0] = right + 2
                else:
                    requirements[j][0] = right+1

            if requirements[j][1] > b[l-1]:
                requirements[j][1] = -1
            elif requirements[j][1] == 0:
                requirements[j][1] = 0
            else:
                left = 0
                right = l-1
                mid = (left + right)//2
                while(left < right):
                    if b[mid] == requirements[j][1]:
                        requirements[j][1] = mid+1
                        break
                    elif b[mid] < requirements[j][1]:
                        left = mid+1
                    else:
                        right = mid-1
                if requirements[j][1] > b[right]:
                    requirements[j][1] = right + 2
                else:
                    requirements[j][1] = right+1

            if requirements[j][2] > c[l-1]:
                requirements[j][2] = -1
            elif requirements[j][2] == 0:
                requirements[j][2] = 0
            else:
                left = 0
                right = l-1
                mid = (left + right)//2
                while(left < right):
                    if c[mid] == requirements[j][2]:
                        requirements[j][2] = mid+1
                        break
                    elif c[mid] < requirements[j][2]:
                        left = mid+1
                    else:
                        right = mid-1
                if requirements[j][2] > c[right]:
                    requirements[j][2] = right + 2
                else:
                    requirements[j][2] = right+1

        ans = [-1 for i in range(ll)]

        for i in range(ll):
            if -1 in requirements[i]:
                continue
            ans[i] = max(requirements[i][0], requirements[i]
                         [1], requirements[i][2])

        print(a)
        print(b)
        print(c)

        print(requirements)

        return ans


a = Solution()
a.getTriggerTime([[2, 8, 4], [2, 5, 0], [10, 9, 8]], [
                 [2, 11, 3], [15, 10, 7], [9, 17, 12], [8, 1, 14]])
