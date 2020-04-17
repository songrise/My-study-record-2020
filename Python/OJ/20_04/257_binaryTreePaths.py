# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        temp = []
        if not (root.left or root.right):
            return (str(root.val))
        else:
            self.binaryTreePaths(root.left)
            self.binaryTreePaths(root.right)

            return reversed(self.binaryTreePaths(root.left)).join("->") + reversed(self.binaryTreePaths(root.right)).join("->")
