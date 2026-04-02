from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        from collections import deque
        sums = []
        q = deque([root])
        while q:
            level_sum = 0
            for _ in range(len(q)):
                node = q.popleft()
                level_sum += node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            sums.append(level_sum)
        if k > len(sums): return -1
        sums.sort(reverse=True)
        return sums[k - 1]
