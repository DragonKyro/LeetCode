from shared.python.data_structures import TreeNode


class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def dfs(node: TreeNode, mn: int, mx: int) -> int:
            if not node:
                return mx - mn
            mn = min(mn, node.val)
            mx = max(mx, node.val)
            return max(dfs(node.left, mn, mx), dfs(node.right, mn, mx))
        return dfs(root, root.val, root.val)
