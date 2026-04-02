from shared.python.data_structures import TreeNode


class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        def dfs(node: TreeNode, current: int) -> TreeNode:
            if not node:
                return None
            current += node.val
            if not node.left and not node.right:
                return node if current >= limit else None
            node.left = dfs(node.left, current)
            node.right = dfs(node.right, current)
            if not node.left and not node.right:
                return None
            return node
        return dfs(root, 0)
