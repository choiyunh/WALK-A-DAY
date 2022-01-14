# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        depth = 0

        Q = deque([root])
        while Q:
            depth += 1
            for _ in range(len(Q)):
                cur_node = Q.popleft()
                if cur_node.left:
                    Q.append(cur_node.left)
                if cur_node.right:
                    Q.append(cur_node.right)

        return depth