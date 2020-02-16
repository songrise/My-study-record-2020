
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BSTIterator:

    def __init__(self, root: TreeNode):
        io = self.inorder(root)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        it = iter(io)
        next(it)
.  
    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """

    def inorder(self, root: TreeNode):
        """
        return an inorder traversed array of the BST
        """
        if not root:
            return []
        return self.inorder(root.left)+[root.val]+self.inorder(root.right)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
