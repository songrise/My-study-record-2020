# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def height(self, root)->int:
        if not root:
            return -1
        else:
            h = 0
            queue = [root.left,root.right]
            while queue:
                for i in range(len(queue)):
                    node = queue.pop(0)
                    if node:
                        queue.append(node.left)
                        queue.append(node.right)
                h += 1
        return h


    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        elif abs(self.height(root.left) - self.height(root.right)) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)