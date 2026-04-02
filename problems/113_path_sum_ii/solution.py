from typing import List, Optional
from shared.python.data_structures import TreeNode


class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        result = []
        def dfs(node: Optional[TreeNode], remaining: int, path: List[int]) -> None:
            if not node:
                return
            path.append(node.val)
            if not node.left and not node.right and remaining == node.val:
                result.append(list(path))
            dfs(node.left, remaining - node.val, path)
            dfs(node.right, remaining - node.val, path)
            path.pop()
        dfs(root, targetSum, [])
        return result
