class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        l = len(A)
        ll = len(A[0])
        for i in range(1,l):
            for j in range(ll):
                if j == 0:
                    A[i][j] += min(A[i-1][j], A[i-1][j+1])
                elif j == ll-1: 
                    A[i][j] += min(A[i-1][j-1], A[i-1][j])

                else:
                    A[i][j] += min(A[i-1][j-1], A[i-1][j], A[i-1][j+1])
        return min(A[ll-1])