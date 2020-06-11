class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxArea = 0
        row = len(grid)
        col = len(grid[0])
        for i, l in enumerate(grid):
            for j, r in enumerate(l):
                stack = [[i, j]]  # 将grid看成图,每个节点四向相连接,(边界特殊处理),利用栈实现DFS.
                cur = 0
                while stack:
                    cur_i, cur_j = stack.pop()
                    if (cur_i < 0 or cur_j < 0 or cur_i >= row or cur_j >= col or grid[cur_i][cur_j] == 0):
                        continue
                    else:
                        cur += 1
                        grid[cur_i][cur_j] = 0  # ! dfs四个方向都入栈，不置零会重复计算同一格
                        stack += ([cur_i-1, cur_j], [cur_i, cur_j-1],
                                  [cur_i+1, cur_j], [cur_i, cur_j+1])
                maxArea = max(maxArea, cur)
        return maxArea
