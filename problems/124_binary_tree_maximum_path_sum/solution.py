from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans = float('-inf')
        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            left = max(dfs(node.left), 0)
            right = max(dfs(node.right), 0)
            self.ans = max(self.ans, node.val + left + right)
            return node.val + max(left, right)
        dfs(root)
        return self.ans
