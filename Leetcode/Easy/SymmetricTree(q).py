# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        else:
            d = deque([(root.left,root.right)])
            while d:
                l,r = d.popleft()
                if not(l) and not(r):
                    continue
                elif not(l) or not(r):
                    return False
                elif l.val != r.val:
                    return False
                else:
                    d.append((l.left,r.right))
                    d.append((l.right,r.left))

            return True