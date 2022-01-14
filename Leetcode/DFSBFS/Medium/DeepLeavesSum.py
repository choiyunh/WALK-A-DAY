# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        stack = [(root, 0)]
        leaf = {}

        while stack:
            node = stack.pop()

            if node[0].left:
                stack.append((node[0].left, node[1] + 1))
            if node[0].right:
                stack.append((node[0].right, node[1] + 1))
            if not (node[0].left or node[0].right):
                if node[1] in leaf:
                    leaf[node[1]] += node[0].val
                else:
                    leaf[node[1]] = node[0].val

        return sorted(leaf.items(), reverse=True)[0][1]



