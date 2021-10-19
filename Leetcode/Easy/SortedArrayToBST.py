# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums) == 0: return None
        if len(nums) == 1:
            return TreeNode(nums[0])

        mid = len(nums) // 2
        root = TreeNode(nums[mid])
        leftSub = nums[0:mid]
        rightSub = nums[mid + 1:]

        root.left = self.sortedArrayToBST(leftSub)
        root.right = self.sortedArrayToBST(rightSub)

        return root

