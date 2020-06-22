class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        l = len(arr)
        mid = sorted(arr)[(l-1)//2]
        print(mid)
        for _ in range(l):
            for i in range(1,l):
                pre = arr[i-1]
                cur = arr[i]
                if abs(cur-mid) > abs(pre-mid):
                    arr[i-1], arr[i] = cur, pre
                elif abs(cur-mid) == abs(pre-mid) and cur > pre:
                    arr[i-1], arr[i] = cur, pre
        print(arr)
        return arr[:k]
