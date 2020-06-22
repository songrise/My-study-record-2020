class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        l = len(arr)
        mid = sorted(arr)[(l-1)//2]
        ans = []
        
        for _ in range(k):
            max_ = arr[0]
            for i in range(1, len(arr)):
                cur = arr[i]
                if abs(cur-mid) > abs(max_-mid):
                    max_ = cur
                elif abs(cur-mid) == abs(max_-mid) and cur > max_:
                    max_ = cur
            arr.pop(arr.index(max_))
            ans.append(max_)
        return ans
