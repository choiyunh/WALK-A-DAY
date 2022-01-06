# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.getHeight(root) is not -1

    def getHeight(self, root):
        if root is None:
            return 0

        left = self.getHeight(root.left)
        right = self.getHeight(root.right)

        if left == -1 or right == -1 or abs(left - right) > 1:
            return -1

        return max(left, right) + 1