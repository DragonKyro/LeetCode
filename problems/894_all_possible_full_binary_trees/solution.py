from typing import List, Optional
from shared.python.data_structures import TreeNode


class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []
        memo = {}
        def build(n: int) -> List[TreeNode]:
            if n in memo:
                return memo[n]
            if n == 1:
                return [TreeNode(0)]
            result = []
            for left in range(1, n, 2):
                right = n - 1 - left
                for l in build(left):
                    for r in build(right):
                        root = TreeNode(0, l, r)
                        result.append(root)
            memo[n] = result
            return result
        return build(n)
