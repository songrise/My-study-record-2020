# class Solution:
#     def solve(self, board: List[List[str]]) -> None:
#         """
#         Do not return anything, modify board in-place instead.
#         """
#         stack = []
#         visited = [[False for _ in range(board[0])] for __ in range(len(board))]
#         for i in range(len(board)):
#             for j in range((len(board[0]))):
#                 temp = []
#                 while stack:
#                     col, row  = stack.pop()
#                     if col < 0 or row < 0 or col == len(board) or row == len(board[0]) or board[col][row] == 'X':
#                         continue
#                     else: #board[col][row] == "O"
#                         visited[col][row] = True
#                         board[col][row] = 'X'




