# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res = TreeNode()

    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        low = 0
        high = len(nums) - 1

        self.make(nums, low, high, self.res)
        print(self.res)

    def make(self, nums, low, high, node):
        mid = (low + high) // 2
        node.val = nums[mid]

        if mid == low:
            print(high)
            return

        self.make(nums, low, mid - 1, node.left)
        self.make(nums, mid + 1, high, node.right)