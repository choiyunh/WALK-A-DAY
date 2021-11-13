# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        rst, queue = [], [root]
        while root and queue:
            node_val, node_queue = [], []
            for node in queue:
                node_val.append(node.val)
                if node.left:
                    node_queue.append(node.left)
                if node.right:
                    node_queue.append(node.right)
            rst.append(node_val)
            queue = node_queue
        return rst