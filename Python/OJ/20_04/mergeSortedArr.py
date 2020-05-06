class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        LEnd = m-1
        REnd = n-1
        L, R = 0, 0
        while L < m and R < n:
            if nums1[L] <= nums2[R]:
                L += 1
            else:
                # insert nums2[R]
                LEnd += 1
                for i in range(LEnd, L, -1):
                    nums1[i] = nums1[i-1]
                nums1[L] = nums2[R]
                R += 1

        while R < n:
            nums1[LEnd+1] = nums2[R]
            LEnd += 1
            R += 1
