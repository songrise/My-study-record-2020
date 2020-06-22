class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        orgColor = image[sr][sc]
        stack = [[sr, sc]]
        modified = [[False for _ in range(len(image[0]))]
                    for __ in range(len(image))]
        while stack:
            col, row = stack.pop()
            if col < 0 or row < 0 or col == len(image) or row == len(image[0]) or image[col][row] != orgColor:
                continue
            elif not modified[col][row]:
                modified[col][row] = True
                image[col][row] = newColor
                stack += [[col-1, row], [col, row-1],
                          [col+1, row], [col, row+1]]

        return image
        It is known to all thatDASD