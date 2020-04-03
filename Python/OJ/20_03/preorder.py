# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    arr = []

    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root.val:
            arr.append(root.val)
        preorderTraversal(root.left)
        preorderTraversal(root.right)
        return arr
