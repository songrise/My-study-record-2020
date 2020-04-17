# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans = []
        stack = []
        while (root):
            stack.append(root.left)
            root = root.left

        while len(stack):
            node = stack.pop()
            ans.append(node.val)
            #now stack top is parent of "node"
            if(stack[-1].right):
                root = stack[-1].right
            while (root):
                stack.append(root.left)
                root = root.left


        return ans


