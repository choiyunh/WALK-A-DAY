# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        return self.foo(root)

    def foo(self, root):
        if root is None:
            return 0

        left = self.foo(root.left)
        right = self.foo(root.right)

        if left and right:
            return min(left, right) + 1
        else:
            return left + right + 1