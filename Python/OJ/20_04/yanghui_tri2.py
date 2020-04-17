class Solution:
    def getRow(self, rowIndex: int) -> List[int]:

        if rowIndex == 0:
            return [1]
        elif rowIndex == 1:
            return [1, 1]

        ans = [[1], [1, 1]]
        for i in range(2, rowIndex+1):
            line = [0 for _ in range(i+1)]
            for j in range(i+1):
                if j == 0 or j == i:
                    line[j] = 1
                else:
                    line[j] = ans[i-1][j-1]+ans[i-1][j]
            ans.append(line)

        return ans[rowIndex]
