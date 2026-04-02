from typing import Optional
from shared.python.data_structures import TreeNode


class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        from collections import deque
        queue = deque([root])
        found_null = False
        while queue:
            node = queue.popleft()
            if not node:
                found_null = True
            else:
                if found_null:
                    return False
                queue.append(node.left)
                queue.append(node.right)
        return True
