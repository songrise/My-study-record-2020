class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows <= 0:
            return []
        if numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1, 1]]

        ans = [[1], [1, 1]]
        for i in range(2, numRows):
            line = [0 for _ in range(i+1)]
            for j in range(i+1):
                if j == 0 or j == i:
                    line[j] = 1
                else:
                    line[j] = ans[i-1][j-1]+ans[i-1][j]
            ans.append(line)
        return ans
