def inorderTraversal(self, root: TreeNode) -> List[int]:
    if root is None: return []

    def dfs(root, res):
        if root is None: return
        dfs(root.left, res)
        res.append(root.val)
        dfs(root.right, res)
        return res

    return dfs(root, [])