from shared.python.data_structures import TreeNode


class Solution:
    def pseudoPalindromicPaths(self, root: TreeNode) -> int:
        def dfs(node: TreeNode, mask: int) -> int:
            if not node:
                return 0
            mask ^= 1 << node.val
            if not node.left and not node.right:
                return 1 if mask & (mask - 1) == 0 else 0
            return dfs(node.left, mask) + dfs(node.right, mask)
        return dfs(root, 0)
