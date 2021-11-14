# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        rst, queue = [], [root]

        while queue:
            child, nodeVal = [], []

            for node in queue:
                nodeVal.append(node.val)

                if node.left:
                    child.append(node.left)
                if node.right:
                    child.append(node.right)

            rst.append(nodeVal)
            queue = child

        return rst