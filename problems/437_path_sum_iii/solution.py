from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def dfs(node: Optional[TreeNode], curr_sum: int) -> int:
            if not node:
                return 0
            curr_sum += node.val
            count = prefix.get(curr_sum - targetSum, 0)
            prefix[curr_sum] = prefix.get(curr_sum, 0) + 1
            count += dfs(node.left, curr_sum)
            count += dfs(node.right, curr_sum)
            prefix[curr_sum] -= 1
            return count

        prefix = {0: 1}
        return dfs(root, 0)
