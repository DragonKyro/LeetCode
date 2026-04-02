from typing import List, Optional
from shared.python.data_structures import TreeNode


class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        from collections import deque
        res = []
        queue = deque([root])
        while queue:
            max_val = float('-inf')
            for _ in range(len(queue)):
                node = queue.popleft()
                max_val = max(max_val, node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(max_val)
        return res
