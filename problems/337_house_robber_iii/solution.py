from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def rob(self, root: 'Optional[TreeNode]') -> int:
        def dfs(node):
            if not node:
                return 0, 0
            left = dfs(node.left)
            right = dfs(node.right)
            rob = node.val + left[1] + right[1]
            not_rob = max(left) + max(right)
            return rob, not_rob
        return max(dfs(root))
