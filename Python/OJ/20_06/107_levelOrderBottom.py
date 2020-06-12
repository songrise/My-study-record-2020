# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        queue = [root]
        stack = []
        while queue:
            layer = []
            for _ in range(len(queue)):
                node = queue.pop(0)
                if node:
                    layer.append(node.val)
                    queue.append(node.left)
                    queue.append(node.right)
            if layer:
                stack.append(layer)

        ans = []
        for i in range(len(stack)):
            ans.append(stack.pop())
        return ans

