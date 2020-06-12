# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findLeaf(self,root: TreeNode) -> bool:
        leaves = []
        if root:
            leaves = []
            stack = [root]
            while stack:
                node = stack.pop(-1)
                if node:
                    stack.append(node.left)
                    stack.append(node.right)
                    if not node.left and not node.right: # is a leaf
                        leaves.append(node.val)
        return leaves



    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
            return self.findLeaf(root1) == self.findLeaf(root2)
