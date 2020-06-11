# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        queue = [root]
        while queue:
            layer = []
            lenQ = len(queue)
            for _ in range(len(lenQ)):
                pre = queue.pop(0)
                if pre:
                    layer.append(pre.val)
                    queue.append(pre.left)
                    queue.append(pre.right)
                else:
                    layer.append(None)

            print(layer)
            if layer != layer[::-1]:
                return False

        return True


##############recursive method###########
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#buggy
# class Solution:
#     def isSymmetric(self, root: TreeNode) -> bool:
#         if not root:
#             return True
#         else:
#             if (not root.left and not root.right):
#                 return True
#             elif(root.left and root.right)
#                 return root.left.val == root.right.val
#             else:
#                 return False

#         return isSymmetric(root.left) and isSymmetric(root.right)
